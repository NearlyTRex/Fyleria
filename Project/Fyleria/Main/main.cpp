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
#include "Utility/Constants.h"
#include "Utility/Types.h"
#include "Utility/Standard.h"
#include "Utility/Boost.h"
#include "Utility/StackTrace.h"

// Control interrupt handlers
void ControlInterruptHandler()
{
    STDCout << STDEndl << "Handling Ctrl Event" << STDEndl << STDEndl;
    Gecko::StopGameRestServer();
    Gecko::StopGameWebsocketServer();
}
#ifdef WIN32
BOOL ControlInterruptHandler(DWORD fdwCtrlType)
{
    switch(fdwCtrlType)
    {
    case CTRL_C_EVENT:
    case CTRL_CLOSE_EVENT:
        ControlInterruptHandler();
        return TRUE;
    default:
        return FALSE;
    }
}
#else
static void ControlInterruptHandler(int signo)
{
    ControlInterruptHandler();
}
#endif

// Main
int main(int iArgCount, char** vArgList)
{
    // Register control interrupt handler
#ifdef WIN32
    SetConsoleCtrlHandler((PHANDLER_ROUTINE)ControlInterruptHandler, TRUE);
#else
    struct sigaction sigact;
    sigact.sa_handler = ControlInterruptHandler;
    sigemptyset(&sigact.sa_mask);
    sigact.sa_flags = 0;
    sigaction(SIGINT, &sigact, NULL);
    sigaction(SIGTERM, &sigact, NULL);
#endif

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
    BoostProgramOptionsDescription desc(Gecko::String(APPLICATION_NAME_LONG) + " " + Gecko::String(APPLICATION_VERSION));
    desc.add_options()
        ("help,h", "Print usage information")
        ("script-file,a", BoostProgramOptionsValue(&sScriptToRun), "Script file name")
        ("config-file,f", BoostProgramOptionsValue(&sConfigFile)->default_value("config.json"), "Config file name")
        ("config-dir,c", BoostProgramOptionsValue(&sConfigDir)->default_value("Config"), "Config directory")
        ("data-dir,d", BoostProgramOptionsValue(&sDataDir)->default_value("Data"), "Data directory")
        ("cache-dir,e", BoostProgramOptionsValue(&sCacheDir)->default_value("Cache"), "Cache directory")
        ("python-lib,l", BoostProgramOptionsValue(&sPythonLibraryFile)->default_value("PythonLib.zip"), "Python library")
        ("web-dir,b", BoostProgramOptionsValue(&sWebDir)->default_value("Web"), "Web directory")
        ("hostname,n", BoostProgramOptionsValue(&sWebHostname)->default_value("localhost"), "Host name")
        ("screen-width,x", BoostProgramOptionsValue(&iScreenWidth)->default_value(1024), "Screen width")
        ("screen-height,y", BoostProgramOptionsValue(&iScreenHeight)->default_value(768), "Screen height")
        ("rest-port,r", BoostProgramOptionsValue(&iRestPort)->default_value(8080), "Rest server port")
        ("websocket-port,w", BoostProgramOptionsValue(&iWebsocketPort)->default_value(8090), "Websocket server port")
        ("web-gui-url,q", BoostProgramOptionsValue(&sWebGuiStartUrl)->default_value("http://localhost:8080"), "Web gui start url")
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
    BoostProgramOptionsStore(BoostProgramOptionsParseCommandLine(iArgCount, vArgList, desc), vm);
    BoostProgramOptionsNotify(vm);
    Gecko::Bool bAtLeastOneMainOption = (
        !sScriptToRun.empty() ||
        bLaunchRestServer ||
        bLaunchWebsocketServer ||
        bLaunchWebGUI
    );
    if(vm.count("help") || !bAtLeastOneMainOption)
    {
        STDCout << desc << STDEndl;
        return EXIT_SUCCESS;
    }

    // Set config data
    Gecko::ConfigManager::GetInstance()->SetUserConfigFile(sConfigFile);
    Gecko::ConfigManager::GetInstance()->SetUserConfigFolder(sConfigDir);
    Gecko::ConfigManager::GetInstance()->SetUserDataFolder(sDataDir);
    Gecko::ConfigManager::GetInstance()->SetUserCacheFolder(sCacheDir);
    Gecko::ConfigManager::GetInstance()->SetPythonLibraryFile(sPythonLibraryFile);
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

    // Run main script if it was specified
    if(!sScriptToRun.empty())
    {
        Gecko::RunGameScript(sScriptToRun.c_str());
        return EXIT_SUCCESS;
    }

    // Launch server
    STDSharedPtr<STDThread> pThreadRestServer;
    STDSharedPtr<STDThread> pThreadWebsocketServer;
    if(bLaunchRestServer)
    {
        pThreadRestServer = STDMakeSharedPtr<STDThread>(&Gecko::StartGameRestServer);
    }
    else if(bLaunchWebsocketServer)
    {
        pThreadWebsocketServer = STDMakeSharedPtr<STDThread>(&Gecko::StartGameWebsocketServer);
    }

    // Launch web gui
    if(bLaunchWebGUI)
    {
        Gecko::StartApplication(iArgCount, vArgList, sWebGuiStartUrl.c_str());
    }

    // Stop servers
    Gecko::StopGameRestServer();
    Gecko::StopGameWebsocketServer();

    // Join threads
    if (pThreadRestServer.get() && pThreadRestServer->joinable())
    {
        pThreadRestServer->join();
    }
    if (pThreadWebsocketServer.get() && pThreadWebsocketServer->joinable())
    {
        pThreadWebsocketServer->join();
    }
    return EXIT_SUCCESS;
}
