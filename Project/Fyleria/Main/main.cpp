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
    Gecko::Bool bEnableScrollbars = false;
    Gecko::Bool bEnableContextMenu = false;
    Gecko::Bool bStartFullscreen = false;
    Gecko::Bool bStartMaximized = false;
    Gecko::Bool bLaunchRestServer = false;
    Gecko::Bool bLaunchWebsocketServer = false;
    Gecko::Bool bLaunchWebGUI = false;

    // Setup allowed options
    BoostProgramOptionsDescription desc("Allowed options");
    desc.add_options()
        ("help,h", "Print usage information")
        ("config-file,f", BoostProgramOptionsValue(&sConfigFile)->default_value("config.json"), "Config file name")
        ("config-dir,c", BoostProgramOptionsValue(&sConfigDir)->default_value("Config"), "Config directory")
        ("data-dir,d", BoostProgramOptionsValue(&sDataDir)->default_value("Data"), "Data directory")
        ("cache-dir,e", BoostProgramOptionsValue(&sCacheDir)->default_value("Cache"), "Cache directory")
        ("web-dir,b", BoostProgramOptionsValue(&sWebDir)->default_value("Web"), "Web directory")
        ("hostname,n", BoostProgramOptionsValue(&sWebHostname)->default_value("localhost"), "Host name")
        ("screen-width,x", BoostProgramOptionsValue(&iScreenWidth)->default_value(1024), "Screen width")
        ("screen-height,y", BoostProgramOptionsValue(&iScreenHeight)->default_value(768), "Screen height")
        ("rest-port,r", BoostProgramOptionsValue(&iRestPort)->default_value(8080), "Rest server port")
        ("websocket-port,w", BoostProgramOptionsValue(&iWebsocketPort)->default_value(8090), "Websocket server port")
        ("server-threads,t", BoostProgramOptionsValue(&iServerThreads)->default_value(1), "Number of server threads")
        ("enable-scrollbars,s", BoostProgramOptionsValue(&bEnableScrollbars)->default_value(true), "Enable scrollbars")
        ("enable-context-menu,m", BoostProgramOptionsValue(&bEnableContextMenu)->default_value(true), "Enable context menu")
        ("start-fullscreen,u", BoostProgramOptionsBoolSwitch(&bStartFullscreen), "Start fullscreen")
        ("start-maximized,i", BoostProgramOptionsBoolSwitch(&bStartMaximized), "Start maximized")
        ("launch-rest-server,j", BoostProgramOptionsBoolSwitch(&bLaunchRestServer), "Launch rest server")
        ("launch-websocket-server,k", BoostProgramOptionsBoolSwitch(&bLaunchWebsocketServer), "Launch websocket server")
        ("launch-web-gui,g", BoostProgramOptionsBoolSwitch(&bLaunchWebGUI), "Launch web gui")
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
    Gecko::ConfigManager::GetInstance()->SetEnableScrollbars(bEnableScrollbars);
    Gecko::ConfigManager::GetInstance()->SetEnableContextMenu(bEnableContextMenu);
    Gecko::ConfigManager::GetInstance()->SetStartFullscreen(bStartFullscreen);
    Gecko::ConfigManager::GetInstance()->SetStartMaximized(bStartMaximized);
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
