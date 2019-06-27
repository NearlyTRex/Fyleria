// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Main/Application.h"
#include "Window/MainWindow.h"
#include "Config/ConfigManager.h"
#include "Scene/SceneManager.h"
#include "Scene/SceneMainMenu.h"
#include "Items/ItemTree.h"
#include "Skills/SkillTree.h"
#include "Stats/StatNames.h"
#include "Utility/Constants.h"
#include "Utility/Logging.h"
#include "Utility/Filesystem.h"
#include "Utility/Python.h"

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

    // Start first scene
    SceneManager::GetInstance()->SwitchToScene(FIRST_SCENE);

    // Main loop
    do
    {
        // Handle scene
        SceneManager::GetInstance()->GetCurrentScene()->Input();
        SceneManager::GetInstance()->GetCurrentScene()->Update();

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
    String sConfigFile = ConfigManager::GetInstance()->GetConstructedConfigFilename();
    LOG_FORMAT_STATEMENT("Loading config file '%s'\n", sConfigFile.c_str());
    ConfigManager::GetInstance()->SetCurrentConfigName("Default");
    if(!ConfigManager::GetInstance()->LoadConfig("Default", sConfigFile))
    {
        ERROR_FORMAT_STATEMENT("Could not load configuration file '%s'\n",
            sConfigFile.c_str());
        return false;
    }

    // Initialize python
    if(!InitPython())
    {
        ERROR_STATEMENT("Unable to initialize python");
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

    // Add starting scenes
    LOG_STATEMENT("Adding scenes");
    SceneManager::GetInstance()->AddScene(MAIN_MENU_SCENE, STDMakeSharedPtr<SceneMainMenu>());
    SceneManager::GetInstance()->SetCurrentSceneID(MAIN_MENU_SCENE);
    LOG_STATEMENT("Finished adding scenes");

    // Initialize window
    LOG_STATEMENT("Initializing window");
    Int iScreenWidth = ConfigManager::GetInstance()->GetScreenWidth();
    Int iScreenHeight = ConfigManager::GetInstance()->GetScreenHeight();
    if(!MainWindow::GetInstance()->GetBrowserEngine()->Init(APPLICATION_NAME_SHORT, iScreenWidth, iScreenHeight, true))
    {
        ERROR_STATEMENT("Unable to initialize window");
        return false;
    }
    LOG_STATEMENT("Finished initializing window");

    // Load web files
    LOG_STATEMENT("Loading web files");
    String sWebDir = ConfigManager::GetInstance()->GetUserWebFolder();
    String sBootstrapCss = JoinPathsCanonical(sWebDir, FILE_CSS_BOOTSTRAP);
    String sBootstrapJs = JoinPathsCanonical(sWebDir, FILE_JS_BOOTSTRAP);
    String sJqueryJs = JoinPathsCanonical(sWebDir, FILE_JS_JQUERY);
    String sPhaserJs = JoinPathsCanonical(sWebDir, FILE_JS_PHASER);
    MainWindow::GetInstance()->GetBrowserEngine()->InjectStylesheetFile(sBootstrapCss);
    MainWindow::GetInstance()->GetBrowserEngine()->InjectJavascriptFile(sBootstrapJs);
    MainWindow::GetInstance()->GetBrowserEngine()->InjectJavascriptFile(sJqueryJs);
    MainWindow::GetInstance()->GetBrowserEngine()->InjectJavascriptFile(sPhaserJs);
    LOG_STATEMENT("Finished loading web files");

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

    // Finalize python
    if(!FinalizePython())
    {
        ERROR_STATEMENT("Unable to finalize python");
        return false;
    }
    return true;
}

};
