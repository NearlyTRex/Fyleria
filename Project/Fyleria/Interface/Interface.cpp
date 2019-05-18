// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "Interface/Interface.h"
#include "Module/Module.h"
#include "Utility/Assert.h"
#include "Utility/Converters.h"
#include "Utility/Logging.h"
#include "Utility/Types.h"
#include "Utility/Python.h"
#include "Utility/StackTrace.h"
#include "Utility/FantasyName.h"
#include "Utility/Filesystem.h"
#include "Utility/Errors.h"

#include "Config/ConfigManager.h"

#include "Character/Character.h"
#include "CharacterParty/CharacterParty.h"
#include "CharacterAction/CharacterAction.h"
#include "Items/ItemTree.h"
#include "Skills/SkillTree.h"

#include "Battle/Battle_wrapper.h"
#include "Config/Config_wrapper.h"
#include "Character/Character_wrapper.h"
#include "CharacterAction/CharacterAction_wrapper.h"
#include "CharacterData/CharacterData_wrapper.h"
#include "CharacterParty/CharacterParty_wrapper.h"
#include "Items/Items_wrapper.h"
#include "Module/Module_wrapper.h"
#include "Recipes/Recipes_wrapper.h"
#include "Saves/Saves_wrapper.h"
#include "Skills/Skills_wrapper.h"
#include "Stats/Stats_wrapper.h"
#include "Utility/Utility_wrapper.h"

#include "Server/WebSockets.h"
#include "Server/Rest.h"

namespace Gecko
{

// Interface mutex
STDMutex g_ModuleMutex;

extern "C" DLL_PUBLIC bool DLL_InitModule()
{
    // Lock API call
    STDLockGuard<STDMutex> lock(g_ModuleMutex);

    // Start initialization
    LOG_STATEMENT("Starting initialization...");

    // Check supported platforms
    if(
        ConfigManager::GetInstance()->IsIOS() ||
        ConfigManager::GetInstance()->IsAndroid()
    )
    {
        ERROR_STATEMENT("Unsupported platform");
        return false;
    }

    // Get file names
    String sConfigFile = ConfigManager::GetInstance()->GetConstructedConfigFilename();
    String sPythonLibFile = ConfigManager::GetInstance()->GetConstructedPythonLibraryFilename();
    WString sPythonLibFileW = ConvertStringToWideString(sPythonLibFile);

    // Load config data
    LOG_FORMAT_STATEMENT("Loading config file '%s'\n", sConfigFile.c_str());
    ConfigManager::GetInstance()->SetCurrentConfigName("Default");
    if(!ConfigManager::GetInstance()->LoadConfig("Default", sConfigFile))
    {
        ERROR_FORMAT_STATEMENT("Could not load configuration file '%s'\n",
            sConfigFile.c_str());
        return false;
    }

    // Check python library
    LOG_FORMAT_STATEMENT("Loading python library '%s'\n", sPythonLibFile.c_str());
    if(!DoesPathExist(sPythonLibFile))
    {
        ERROR_FORMAT_STATEMENT("Python library '%s' could not be found, check configuration data\n",
            sPythonLibFile.c_str());
        return false;
    }

    // Skip site usage and ignore environment variables
    Py_NoSiteFlag++;
    Py_NoUserSiteDirectory++;
    Py_IgnoreEnvironmentFlag++;

    // Set python home
#ifdef Py_USING_UNICODE
    Py_SetPythonHome(const_cast<wchar_t*>(sPythonLibFileW.c_str()));
    Py_SetPath(sPythonLibFileW.c_str());
#else
    Py_SetPythonHome(const_cast<char*>(sPythonLibFile.c_str()));
    Py_SetPath(sPythonLibFile.c_str());
#endif

    // Initialize interpreter
    PyBindInitializeInterpreter(false);

    // Import basic modules
    PyRun_SimpleString("import os");
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('Scripts')");

    // Initialization finished!
    LOG_STATEMENT("Module successfully initialized");
    return true;
}

extern "C" DLL_PUBLIC bool DLL_FinalizeModule()
{
    // Lock API call
    STDLockGuard<STDMutex> lock(g_ModuleMutex);

    // Start finalization
    LOG_STATEMENT("Starting finalization...");

    // Finalize interpreter
    PyBindFinalizeInterpreter();

    // Finalization finished!
    LOG_STATEMENT("Module successfully finalized");
    return true;
}

bool DLL_Internal_RunModuleFile(const char* sFile, const char* sResultsID)
{
    // Lock API call
    STDLockGuard<STDMutex> lock(g_ModuleMutex);

    try
    {
        // Set run result ID
        if(sResultsID)
        {
            ModuleResult::SetRunResultID(sResultsID);
        }

        // Lock python state
        PyBindAcquireScopedGIL acquire;

        // Evaluate in scope of main module
        PyBindObject scope = PyBindModuleImport("__main__").attr("__dict__");

        // Evaluate the statements in an separate Python file on disk
        LOG_FORMAT_STATEMENT("Running file '%s'\n", sFile);
        PyBindEvalFile(sFile, scope);
    }
    catch (PyBindRuntimeException& error)
    {
        if(sResultsID)
        {
            ModuleResult::SetRunResultID("");
        }
        auto sMessage = error.what();
        error.restore();
        ERROR_FORMAT_STATEMENT("%s\n", sMessage);
        throw ModuleError(sMessage);
    }
    if(sResultsID)
    {
        ModuleResult::SetRunResultID("");
    }
    return true;
}

extern "C" DLL_PUBLIC bool DLL_RunModuleFile(const char* sFile)
{
    return DLL_Internal_RunModuleFile(sFile, nullptr);
}

extern "C" DLL_PUBLIC bool DLL_RunModuleFileResults(const char* sFile, const char* sResultsID)
{
    return DLL_Internal_RunModuleFile(sFile, sResultsID);
}

bool DLL_Internal_RunModuleCommand(const char* sCommand, const char* sResultsID)
{
    // Lock API call
    STDLockGuard<STDMutex> lock(g_ModuleMutex);

    try
    {
        // Set run result ID
        if(sResultsID)
        {
            ModuleResult::SetRunResultID(sResultsID);
        }

        // Lock python state
        PyBindAcquireScopedGIL acquire;

        // Evaluate in scope of main module
        PyBindObject scope = PyBindModuleImport("__main__").attr("__dict__");

        // Evaluate a string containing a sequence of statements
        LOG_FORMAT_STATEMENT("Running command '%s'\n", sCommand);
        PyBindExec(sCommand, scope);
    }
    catch (PyBindRuntimeException& error)
    {
        if(sResultsID)
        {
            ModuleResult::SetRunResultID("");
        }
        auto sMessage = error.what();
        error.restore();
        ERROR_FORMAT_STATEMENT("%s\n", sMessage);
        throw ModuleError(sMessage);
    }
    if(sResultsID)
    {
        ModuleResult::SetRunResultID("");
    }
    return true;
}

extern "C" DLL_PUBLIC bool DLL_RunModuleCommand(const char* sCommand)
{
    return DLL_Internal_RunModuleCommand(sCommand, nullptr);
}

extern "C" DLL_PUBLIC bool DLL_RunModuleCommandResults(const char* sCommand, const char* sResultsID)
{
    return DLL_Internal_RunModuleCommand(sCommand, sResultsID);
}

extern "C" DLL_PUBLIC void DLL_ClearModuleResult(const char* sResultsID)
{
    // Lock API call
    STDLockGuard<STDMutex> lock(g_ModuleMutex);

    // Clear the specific result
    ModuleResult::ClearResult(String(sResultsID));
}

extern "C" DLL_PUBLIC void DLL_ClearAllModuleResults()
{
    // Lock API call
    STDLockGuard<STDMutex> lock(g_ModuleMutex);

    // Clear all results
    ModuleResult::ClearAllResults();
}

extern "C" DLL_PUBLIC bool DLL_DoesModuleResultExist(const char* sResultsID)
{
    // Lock API call
    STDLockGuard<STDMutex> lock(g_ModuleMutex);

    // Determine if result exists
    return ModuleResult::DoesResultExist(String(sResultsID));
}

extern "C" DLL_PUBLIC unsigned int DLL_GetModuleResultSize(const char* sResultsID)
{
    // Lock API call
    STDLockGuard<STDMutex> lock(g_ModuleMutex);

    // Get the result size
    return ModuleResult::GetResult(String(sResultsID)).size();
}

extern "C" DLL_PUBLIC bool DLL_GetModuleResults(const char* sResultsID, char* sResultStr, unsigned int uResultLen)
{
    // Lock API call
    STDLockGuard<STDMutex> lock(g_ModuleMutex);

    // Search for the given result
    String sResult = ModuleResult::GetResult(String(sResultsID));
    if(sResult.empty())
    {
        ERROR_FORMAT_STATEMENT("Cannot get result for ID '%s'\n", sResultsID);
        return false;
    }

    // Copy the result to the given buffer
    strncpy(sResultStr, sResult.c_str(), uResultLen);
    return true;
}

extern "C" DLL_PUBLIC void DLL_VerifyModuleData()
{
    // Lock API call
    STDLockGuard<STDMutex> lock(g_ModuleMutex);

    // Verify trees
    VerifySkillTrees();
    VerifyItemTrees();
}

};
