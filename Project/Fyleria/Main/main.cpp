// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// System includes
#include <string>
#include <iostream>
#include <cstdlib>

// Local includes
#include "Main/Application.h"
#include "Config/ConfigManager.h"
#include "Utility/Constants.h"
#include "Utility/Types.h"
#include "Utility/Standard.h"
#include "Utility/Boost.h"
#include "Utility/StackTrace.h"

// Main
int main(int iArgCount, char** vArgList)
{
    // Register signal handler
#ifdef DEBUG
    Gecko::SignalHandler signalHandler(Gecko::GetStackTraceSignals());
#endif

    // Program options
    Gecko::String sScriptToRun;
    Gecko::String sConfigFile;
    Gecko::String sConfigDir;
    Gecko::String sDataDir;
    Gecko::String sCacheDir;
    Gecko::String sWebDir;
    Gecko::String sPythonLibraryFile;
    Gecko::Int iScreenWidth = 0;
    Gecko::Int iScreenHeight = 0;

    // Setup allowed options
    BoostProgramOptionsDescription desc(Gecko::String(APPLICATION_NAME_LONG) + " " + Gecko::String(APPLICATION_VERSION));
    desc.add_options()
        ("help,h", "Print usage information")
        ("script-file,a", BoostProgramOptionsValue(&sScriptToRun), "Initial script file name")
        ("config-file,f", BoostProgramOptionsValue(&sConfigFile)->default_value("config.json"), "Config file name")
        ("config-dir,c", BoostProgramOptionsValue(&sConfigDir)->default_value("Config"), "Config directory")
        ("data-dir,d", BoostProgramOptionsValue(&sDataDir)->default_value("Data"), "Data directory")
        ("cache-dir,e", BoostProgramOptionsValue(&sCacheDir)->default_value("Cache"), "Cache directory")
        ("web-dir,b", BoostProgramOptionsValue(&sWebDir)->default_value("Web"), "Web directory")
        ("python-lib,l", BoostProgramOptionsValue(&sPythonLibraryFile)->default_value("PythonLib.zip"), "Python library")
        ("screen-width,x", BoostProgramOptionsValue(&iScreenWidth)->default_value(1024), "Screen width")
        ("screen-height,y", BoostProgramOptionsValue(&iScreenHeight)->default_value(768), "Screen height")
    ;

    // Parse command line
    BoostProgramOptionsVariablesMap vm;
    BoostProgramOptionsStore(BoostProgramOptionsParseCommandLine(iArgCount, vArgList, desc), vm);
    BoostProgramOptionsNotify(vm);
    if(vm.count("help"))
    {
        STDCout << desc << STDEndl;
        return EXIT_SUCCESS;
    }

    // Set config data
    Gecko::ConfigManager::GetInstance()->SetUserConfigFile(sConfigFile);
    Gecko::ConfigManager::GetInstance()->SetUserConfigFolder(sConfigDir);
    Gecko::ConfigManager::GetInstance()->SetUserDataFolder(sDataDir);
    Gecko::ConfigManager::GetInstance()->SetUserCacheFolder(sCacheDir);
    Gecko::ConfigManager::GetInstance()->SetUserWebFolder(sWebDir);
    Gecko::ConfigManager::GetInstance()->SetPythonLibraryFile(sPythonLibraryFile);
    Gecko::ConfigManager::GetInstance()->SetScreenWidth(iScreenWidth);
    Gecko::ConfigManager::GetInstance()->SetScreenHeight(iScreenHeight);

    // Run application
    Gecko::Application app;
    app.Run();
    return EXIT_SUCCESS;
}
