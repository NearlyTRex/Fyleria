// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Application/Application.h"
#include "Application/ApplicationConstants.h"
#include "Window/MainWindow.h"
#include "Scene/SceneTypes.h"
#include "Stat/StatNames.h"
#include "Utility/Logging.h"
#include "Utility/Version.h"

namespace Gecko
{

SafeObject<ManagerSet>& GetManagers()
{
    static SafeObject<ManagerSet> managers;
    return managers;
}

Application::Application()
{
}

Application::~Application()
{
}

String Application::GetName()
{
    // Get name
    return APPLICATION_NAME_LONG;
}

String GetVersion(const String& sVersion)
{
    // Check length
    if(sVersion.size() <= 2)
    {
        return sVersion;
    }

    // Get version
    String sNewVersion = sVersion;
    BoostReplaceAll(sNewVersion, "-dirty", "");
    if(BoostStartsWith(sNewVersion, "v"))
    {
        return "Version " + sNewVersion.substr(1, sNewVersion.size() - 1);
    }
    return "Version " + sNewVersion;
}

String Application::GetVersionShort()
{
    // Get version
    return GetVersion(GetVersionStringShort());
}

String Application::GetVersionLong()
{
    // Get version
    return GetVersion(GetVersionStringLong());
}

void Application::Run()
{
    do
    {
        // Handle scene
        if(!GetManagers()->GetSceneManager()->GetCurrentSceneID().empty())
        {
            GetManagers()->GetSceneManager()->GetCurrentScene()->Input();
            GetManagers()->GetSceneManager()->GetCurrentScene()->Update();
        }

        // Handle browser main loop
        MainWindow::GetInstance()->GetBrowserEngine()->RunMainLoopIteration(true);
    }
    while(MainWindow::GetInstance()->GetBrowserEngine()->GetIsShuttingDown() == false);
}

void Application::CheckDataDirectory()
{
    // Check data dir
    String sDataDir = GetManagers()->GetFileManager()->GetDataDirectory();
    if(!GetManagers()->GetFileManager()->DoesPathExist(sDataDir))
    {
        THROW_RUNTIME_ERROR("Unable to find data directory");
    }
}

void Application::InitializeLogging(const String& sLogName, LoggingLevelType eLogLevel)
{
    // Get logging location
    String sLogDir = GetManagers()->GetFileManager()->GetDataLogsDirectory();
    String sLogFile = GetManagers()->GetFileManager()->GetLogFile();

    // Create log folder
    if(!GetManagers()->GetFileManager()->DoesPathExist(sLogDir))
    {
        GetManagers()->GetFileManager()->CreateNewDirectory(sLogDir);
    }

    // Setup logging
    String sFullLogFile = GetManagers()->GetFileManager()->JoinPaths(sLogDir, sLogFile);
    SetupLogging(sLogName, sFullLogFile, eLogLevel);
}

void Application::InitializeConfig(const String& sConfigName, const String& sConfigFile)
{
    // Load config
    LOG_FORMAT_STATEMENT("Loading config file '{}'", sConfigFile);
    if(!GetManagers()->GetConfigManager()->LoadConfigFromFile(sConfigName, sConfigFile))
    {
        LOG_FORMAT_STATEMENT("Unable to load config file '{}', creating default", sConfigFile);
        if(!GetManagers()->GetConfigManager()->CreateConfig(sConfigName))
        {
            THROW_RUNTIME_ERROR("Unable to create default config");
        }
    }

    // Set current config name
    GetManagers()->GetConfigManager()->SetCurrentConfigName(sConfigName);
}

void Application::InitializeSaves()
{
    // Get save dir
    String sSaveDir = GetManagers()->GetFileManager()->GetDataSavesDirectory();

    // Create save dir
    LOG_STATEMENT("Checking save directory");
    if(!GetManagers()->GetFileManager()->DoesPathExist(sSaveDir))
    {
        LOG_STATEMENT("Creating save directory");
        GetManagers()->GetFileManager()->CreateNewDirectory(sSaveDir);
    }
}

void Application::InitializeTrees()
{
    // Initialize stat names
    LOG_STATEMENT("Initializing stat names");
    InitializeAllStatNames();
    LOG_STATEMENT("Finished initializing stat names");

    // Load skill trees
    LOG_STATEMENT("Loading skill trees");
    GetManagers()->GetSkillManager()->LoadSkillTreesIntoMemory();
    LOG_STATEMENT("Finished loading skill trees");

    // Load item trees
    LOG_STATEMENT("Loading item trees");
    GetManagers()->GetItemManager()->LoadItemTreesIntoMemory();
    LOG_STATEMENT("Finished loading item trees");
}

void Application::InitializeWindow()
{
    // Get screen dimensions
    Int iWidth = GetManagers()->GetConfigManager()->GetCurrentConfig().GetScreenWidth();
    Int iHeight = GetManagers()->GetConfigManager()->GetCurrentConfig().GetScreenHeight();

    // Initialize window
    LOG_STATEMENT("Initializing window");
    if(!MainWindow::GetInstance()->GetBrowserEngine()->Init(APPLICATION_NAME_SHORT, iWidth, iHeight, true))
    {
        THROW_RUNTIME_ERROR("Unable to initialize window");
    }
    LOG_STATEMENT("Finished initializing window");
}

void Application::Initialize()
{
    // Check data directory
    CheckDataDirectory();

    // Initialize
    InitializeLogging(APPLICATION_LOGGER_NAME, APPLICATION_LOGGER_LEVEL_MAIN);
    InitializeConfig(APPLICATION_CONFIG_NAME, APPLICATION_CONFIG_FILE);
    InitializeSaves();
    InitializeTrees();
    InitializeWindow();
}

void Application::FinalizeLogging()
{
    // Shutdown logging
    ShutdownLogging();
}

void Application::FinalizeCharacters()
{
    // Unload characters
    LOG_STATEMENT("Unloading characters");
    GetManagers()->GetCharacterManager()->UnloadAllCharacters();
    LOG_STATEMENT("Finished unloading characters");

    // Unload parties
    LOG_STATEMENT("Unloading parties");
    GetManagers()->GetCharacterPartyManager()->UnloadAllParties();
    LOG_STATEMENT("Finished unloading parties");
}

void Application::FinalizeTrees()
{
    // Unload skill trees
    LOG_STATEMENT("Unloading skill trees");
    GetManagers()->GetSkillManager()->UnloadSkillTreesFromMemory();
    LOG_STATEMENT("Finished unloading skill trees");

    // Unload item trees
    LOG_STATEMENT("Unloading item trees");
    GetManagers()->GetItemManager()->UnloadItemTreesFromMemory();
    LOG_STATEMENT("Finished unloading item trees");
}

void Application::Finalize()
{
    // Finalize
    FinalizeCharacters();
    FinalizeTrees();
    FinalizeLogging();
}

};
