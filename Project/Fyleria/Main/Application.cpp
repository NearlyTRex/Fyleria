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
        MainWindow::GetInstance()->GetBrowserEngine()->RunMainLoopIteration(true);
    }
    while(MainWindow::GetInstance()->GetBrowserEngine()->GetIsShuttingDown() == false);

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
    Int iScreenWidth = ConfigManager::GetInstance()->GetScreenWidth();
    Int iScreenHeight = ConfigManager::GetInstance()->GetScreenHeight();

    // Initialize window
    LOG_STATEMENT("Initializing window");
    if(!MainWindow::GetInstance()->GetBrowserEngine()->Init(APPLICATION_NAME_SHORT, iScreenWidth, iScreenHeight, true))
    {
        ERROR_STATEMENT("Unable to initialize window");
        return false;
    }
    LOG_STATEMENT("Finished initializing window");

    // Setup window
    LOG_STATEMENT("Navigating to start page");
    MainWindow::GetInstance()->GetBrowserEngine()->Navigate("about:blank");
    LOG_STATEMENT("Finished navigating");
    return true;
}

Bool Application::Finalize()
{
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
