// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

// System includes
#include <string>
#include <iostream>
#include <cstdlib>

// Local includes
#include "Main/Application.h"
#include "Main/Game.h"
#include "Config/ConfigManager.h"
#include "Utility/Types.h"
#include "Utility/Standard.h"
#include "Utility/Boost.h"
#include "Utility/StackTrace.h"

// Main
int main(int argc, char** argv)
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
    Gecko::String sWebHostname;
    Gecko::Int iScreenWidth = 0;
    Gecko::Int iScreenHeight = 0;
    Gecko::Int iRestPort = 0;
    Gecko::Int iWebsocketPort = 0;
    Gecko::Int iServerThreads = 0;
    Gecko::Bool bStartFullscreen = false;
    Gecko::Bool bAllowScrollbars = false;
    Gecko::Bool bAllowContextMenu = false;
    Gecko::Bool bLaunchRestServer = false;
    Gecko::Bool bLaunchWebsocketServer = false;
    Gecko::Bool bLaunchWebGUI = false;

    // Setup allowed options
    BoostProgramOptionsDescription desc("Allowed options");
    desc.add_options()
        ("help,h", "Print usage information")
        ("config-file", BoostProgramOptionsValue(&sConfigFile)->default_value("config.json"), "Config file name")
        ("config-dir", BoostProgramOptionsValue(&sConfigDir)->default_value("Config"), "Config directory")
        ("data-dir", BoostProgramOptionsValue(&sDataDir)->default_value("Data"), "Data directory")
        ("cache-dir", BoostProgramOptionsValue(&sCacheDir)->default_value("Cache"), "Cache directory")
        ("web-dir", BoostProgramOptionsValue(&sWebDir)->default_value("Web"), "Web directory")
        ("hostname", BoostProgramOptionsValue(&sWebHostname)->default_value("localhost"), "Host name")
        ("screen-width", BoostProgramOptionsValue(&iScreenWidth)->default_value(1024), "Screen width")
        ("screen-height", BoostProgramOptionsValue(&iScreenHeight)->default_value(768), "Screen height")
        ("rest-port", BoostProgramOptionsValue(&iRestPort)->default_value(8080), "Rest server port")
        ("websocket-port", BoostProgramOptionsValue(&iWebsocketPort)->default_value(8090), "Websocket server port")
        ("server-threads", BoostProgramOptionsValue(&iServerThreads)->default_value(1), "Number of server threads")
        ("start-fullscreen", BoostProgramOptionsBoolSwitch(&bStartFullscreen)->default_value(false), "Start in fullscreen")
        ("allow-scrollbars", BoostProgramOptionsBoolSwitch(&bAllowScrollbars)->default_value(true), "Allow scrollbars")
        ("allow-context-menu", BoostProgramOptionsBoolSwitch(&bAllowContextMenu)->default_value(true), "Allow context menu")
        ("launch-rest-server", BoostProgramOptionsBoolSwitch(&bLaunchRestServer)->default_value(true), "Launch rest server")
        ("launch-websocket-server", BoostProgramOptionsBoolSwitch(&bLaunchWebsocketServer)->default_value(true), "Launch websocket server")
        ("launch-web-gui", BoostProgramOptionsBoolSwitch(&bLaunchWebGUI)->default_value(true), "Launch web gui")
    ;

    // Parse command line
    BoostProgramOptionsVariablesMap vm;
    BoostProgramOptionsStore(BoostProgramOptionsParseCommandLine(argc, argv, desc), vm);
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
    Gecko::ConfigManager::GetInstance()->SetWebFolder(sWebDir);
    Gecko::ConfigManager::GetInstance()->SetWebHostname(sWebHostname);
    Gecko::ConfigManager::GetInstance()->SetRestUrl((BoostFormatString("http://%1%:%2%") % sWebHostname % iRestPort).str());
    Gecko::ConfigManager::GetInstance()->SetWebsocketUrl((BoostFormatString("http://%1%:%2%") % sWebHostname % iWebsocketPort).str());
    Gecko::ConfigManager::GetInstance()->SetStartFullscreen(bStartFullscreen);
    Gecko::ConfigManager::GetInstance()->SetAllowScrollbars(bAllowScrollbars);
    Gecko::ConfigManager::GetInstance()->SetAllowContextMenu(bAllowContextMenu);
    Gecko::ConfigManager::GetInstance()->SetScreenWidth(iScreenWidth);
    Gecko::ConfigManager::GetInstance()->SetScreenHeight(iScreenHeight);
    Gecko::ConfigManager::GetInstance()->SetRestPort(iRestPort);
    Gecko::ConfigManager::GetInstance()->SetWebsocketPort(iWebsocketPort);
    Gecko::ConfigManager::GetInstance()->SetServerThreads(iServerThreads);

    // Launch server
    STDSharedPtr<BoostThread> pThreadRestServer;
    STDSharedPtr<BoostThread> pThreadWebsocketServer;
    if(bLaunchRestServer)
    {
        pThreadRestServer = STDMakeSharedPtr<BoostThread>(&Gecko::StartGameRestServer);
    }
    else if(bLaunchWebsocketServer)
    {
        pThreadWebsocketServer = STDMakeSharedPtr<BoostThread>(&Gecko::StartGameWebsocketServer);
    }

    // Launch web gui
    if(bLaunchWebGUI && bLaunchRestServer)
    {
        Gecko::StartApplication(argc, argv);
    }

    // Join threads
    if (pThreadRestServer.get())
    {
        pThreadRestServer->join();
    }
    if (pThreadWebsocketServer.get())
    {
        pThreadWebsocketServer->join();
    }
    return EXIT_SUCCESS;
}
