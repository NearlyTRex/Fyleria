// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Main/Application.h"
#include "Window/MainWindow.h"
#include "Scene/SceneTypes.h"
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
    // Create managers
    SetManagers(STDMakeSharedPtr<ManagerSet>());

    // Initialize
    if(!Initialize())
    {
        return;
    }

    // Main loop
    do
    {
        // Handle scene
        if(!GetManagers()->GetSceneManager().GetCurrentSceneID().empty())
        {
            GetManagers()->GetSceneManager().GetCurrentScene()->Input(GetManagers().get());
            GetManagers()->GetSceneManager().GetCurrentScene()->Update(GetManagers().get());
        }

        // Handle browser main loop
        MainWindow::GetInstance()->GetBrowserEngine()->RunMainLoopIteration(true);
    }
    while(MainWindow::GetInstance()->GetBrowserEngine()->GetIsShuttingDown() == false);

    // Finalize
    Finalize();
}

Bool Application::Initialize()
{
    // Load config data
    String sConfigFile = JoinPathsCanonical(GetDataDirectory(), CONFIG_FILE);
    LOG_FORMAT_STATEMENT("Loading config file '{}'", sConfigFile.c_str());
    GetManagers()->GetConfigManager().SetCurrentConfigName("Default");
    if(!GetManagers()->GetConfigManager().LoadConfig("Default", sConfigFile))
    {
        ERROR_FORMAT_STATEMENT("Could not load configuration file '{}'",
            sConfigFile.c_str());
        return false;
    }

    // Initialize stat names
    LOG_STATEMENT("Initializing stat names...");
    InitializeAllStatNames();
    LOG_STATEMENT("Finished initializing stat names");

    // Load trees into memory
    LOG_STATEMENT("Loading trees into memory...");
    GetManagers()->GetSkillManager().LoadSkillTreesIntoMemory();
    GetManagers()->GetItemManager().LoadItemTreesIntoMemory();
    LOG_STATEMENT("Finished loading trees into memory");

    // Initialize window
    LOG_STATEMENT("Initializing window");
    Int iScreenWidth = GetManagers()->GetConfigManager().GetCurrentConfig().GetScreenWidth();
    Int iScreenHeight = GetManagers()->GetConfigManager().GetCurrentConfig().GetScreenHeight();
    if(!MainWindow::GetInstance()->GetBrowserEngine()->Init(GetManagers().get(), APPLICATION_NAME_SHORT, iScreenWidth, iScreenHeight, true))
    {
        ERROR_STATEMENT("Unable to initialize window");
        return false;
    }
    LOG_STATEMENT("Finished initializing window");
    return true;
}

Bool Application::Finalize()
{
    // Unload trees from memory
    LOG_STATEMENT("Unloading trees from memory...");
    GetManagers()->GetSkillManager().UnloadSkillTreesFromMemory();
    GetManagers()->GetItemManager().UnloadItemTreesFromMemory();
    LOG_STATEMENT("Finished unloading trees from memory");
    return true;
}

};
