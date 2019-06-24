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
    Gecko::String sPythonLibraryFile;
    Gecko::String sWebDir;
    Gecko::String sWebHostname;
    Gecko::String sWebGuiStartUrl;
    Gecko::Int iScreenWidth = 0;
    Gecko::Int iScreenHeight = 0;
    Gecko::Int iWebPort = 0;
    Gecko::Int iServerThreads = 0;

    // Setup allowed options
    BoostProgramOptionsDescription desc(Gecko::String(APPLICATION_NAME_LONG) + " " + Gecko::String(APPLICATION_VERSION));
    desc.add_options()
        ("help,h", "Print usage information")
        ("script-file,a", BoostProgramOptionsValue(&sScriptToRun), "Initial script file name")
        ("config-file,f", BoostProgramOptionsValue(&sConfigFile)->default_value("config.json"), "Config file name")
        ("config-dir,c", BoostProgramOptionsValue(&sConfigDir)->default_value("Config"), "Config directory")
        ("data-dir,d", BoostProgramOptionsValue(&sDataDir)->default_value("Data"), "Data directory")
        ("cache-dir,e", BoostProgramOptionsValue(&sCacheDir)->default_value("Cache"), "Cache directory")
        ("python-lib,l", BoostProgramOptionsValue(&sPythonLibraryFile)->default_value("PythonLib.zip"), "Python library")
        ("web-dir,b", BoostProgramOptionsValue(&sWebDir)->default_value("Web"), "Web directory")
        ("web-port,r", BoostProgramOptionsValue(&iWebPort)->default_value(8080), "Web server port")
        ("web-hostname,n", BoostProgramOptionsValue(&sWebHostname)->default_value("localhost"), "Web host name")
        ("screen-width,x", BoostProgramOptionsValue(&iScreenWidth)->default_value(1024), "Screen width")
        ("screen-height,y", BoostProgramOptionsValue(&iScreenHeight)->default_value(768), "Screen height")
        ("server-threads,t", BoostProgramOptionsValue(&iServerThreads)->default_value(1), "Number of server threads")
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

    // Set web gui url
    sWebGuiStartUrl = (BoostFormatString("http://%1%:%2%") % sWebHostname % iWebPort).str();

    // Set config data
    Gecko::ConfigManager::GetInstance()->SetUserConfigFile(sConfigFile);
    Gecko::ConfigManager::GetInstance()->SetUserConfigFolder(sConfigDir);
    Gecko::ConfigManager::GetInstance()->SetUserDataFolder(sDataDir);
    Gecko::ConfigManager::GetInstance()->SetUserCacheFolder(sCacheDir);
    Gecko::ConfigManager::GetInstance()->SetPythonLibraryFile(sPythonLibraryFile);
    Gecko::ConfigManager::GetInstance()->SetWebFolder(sWebDir);
    Gecko::ConfigManager::GetInstance()->SetWebHostname(sWebHostname);
    Gecko::ConfigManager::GetInstance()->SetWebUrl(sWebGuiStartUrl);
    Gecko::ConfigManager::GetInstance()->SetWebPort(iWebPort);
    Gecko::ConfigManager::GetInstance()->SetScreenWidth(iScreenWidth);
    Gecko::ConfigManager::GetInstance()->SetScreenHeight(iScreenHeight);
    Gecko::ConfigManager::GetInstance()->SetServerThreads(iServerThreads);

    // Run application
    Gecko::Application app;
    app.Run();
    return EXIT_SUCCESS;
}
