// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Main/Application.h"
#include "Window/MainWindow.h"
#include "Config/ConfigManager.h"
#include "Items/ItemTree.h"
#include "Skills/SkillTree.h"
#include "Interface/Interface.h"
#include "Web/WebServer.h"
#include "Stats/StatNames.h"
#include "Utility/Constants.h"
#include "Utility/Logging.h"
#include "Utility/Filesystem.h"

namespace Gecko
{

Application::Application()
{
}

Application::~Application()
{
}

void Application::Run()
{
    // Initialize
    if(!Initialize())
    {
        return;
    }

    // Main loop
    do
    {
        MainWindow::GetInstance()->RunMainLoopIteration(true);
    }
    while(MainWindow::GetInstance()->IsShuttingDown() == false);

    // Finalize
    Finalize();
}

Bool Application::Initialize()
{
    // Initialize module
    if(!DLL_InitModule())
    {
        ERROR_STATEMENT("Unable to initialize module");
        return false;
    }

    // Initialize stat names
    LOG_STATEMENT("Initializing stat names...");
    InitializeAllStatNames();
    LOG_STATEMENT("Finished initializing stat names");

    // Load trees into memory
    LOG_STATEMENT("Loading trees into memory...");
    SkillTree::LoadSkillTreesIntoMemory();
    ItemTree::LoadItemTreesIntoMemory();
    LOG_STATEMENT("Finished loading trees into memory");

    // Get configuration data
    String sStartUrl = ConfigManager::GetInstance()->GetWebUrl();
    String sWebHostname = ConfigManager::GetInstance()->GetWebHostname();
    String sWebFolder = ConfigManager::GetInstance()->GetWebFolder();
    Int iWebPort = ConfigManager::GetInstance()->GetWebPort();
    Int iServerThreads = ConfigManager::GetInstance()->GetServerThreads();
    Int iScreenWidth = ConfigManager::GetInstance()->GetScreenWidth();
    Int iScreenHeight = ConfigManager::GetInstance()->GetScreenHeight();

    // Start server
    LOG_STATEMENT("Starting server");
    WebServer::GetInstance()->SetHostname(sWebHostname);
    WebServer::GetInstance()->SetWebRoot(sWebFolder);
    WebServer::GetInstance()->SetPort(iWebPort);
    WebServer::GetInstance()->SetThreadCount(iServerThreads);
    WebServer::GetInstance()->Reset();
    WebServer::GetInstance()->Start();
    LOG_STATEMENT("Finished starting server");

    // Initialize window
    LOG_STATEMENT("Initializing window");
    if(!MainWindow::GetInstance()->Init(APPLICATION_NAME_SHORT, iScreenWidth, iScreenHeight, true))
    {
        ERROR_STATEMENT("Unable to initialize window");
        return false;
    }
    LOG_STATEMENT("Finished initializing window");

    // Setup window
    LOG_FORMAT_STATEMENT("Navigating to %s\n", sStartUrl.c_str());
    MainWindow::GetInstance()->Navigate(sStartUrl);
    LOG_STATEMENT("Finished navigating");
    return true;
}

Bool Application::Finalize()
{
    // Stop server
    LOG_STATEMENT("Stopping server");
    WebServer::GetInstance()->Stop();
    LOG_STATEMENT("Finished stopping server");

    // Unload trees from memory
    LOG_STATEMENT("Unloading trees from memory...");
    SkillTree::UnloadSkillTreesFromMemory();
    ItemTree::UnloadItemTreesFromMemory();
    LOG_STATEMENT("Finished unloading trees from memory");

    // Finalize module
    if(!DLL_FinalizeModule())
    {
        ERROR_STATEMENT("Unable to finalize module");
        return false;
    }
    return true;
}

};
