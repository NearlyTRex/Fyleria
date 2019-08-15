// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneCraftingMenu.h"
#include "Window/MainWindow.h"
#include "Utility/Constants.h"

namespace Gecko
{

SceneCraftingMenu::SceneCraftingMenu()
    : Scene()
{
}

SceneCraftingMenu::~SceneCraftingMenu()
{
}

void SceneCraftingMenu::Start(ManagerSet* pManagerSet)
{
    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneCraftingMenu::OnMessageReceived, this, pManagerSet, STDPlaceholder1));

    // Load page content
    InjectCommonData();
    InjectStylesheetFile(PAGE_FILE_CRAFTING_MENU_CSS, GetDataPagesDirectory());
    InjectJavascriptFile(PAGE_FILE_CRAFTING_MENU_JS, GetDataPagesDirectory());
    SetHtmlContentFile(PAGE_FILE_CRAFTING_MENU_HTML, GetDataPagesDirectory());
}

void SceneCraftingMenu::Finish(ManagerSet* pManagerSet)
{
    // Clear callbacks
    ClearPostCallback();

    // Clear page content
    RemoveAllInjectedData();
}

void SceneCraftingMenu::Update(ManagerSet* pManagerSet)
{
}

void SceneCraftingMenu::Input(ManagerSet* pManagerSet)
{
}

void SceneCraftingMenu::OnMessageReceived(ManagerSet* pManagerSet, const String& sMessage)
{
    // Function / arguments
    String sFunction;
    StringArray vArgs;

    // Handle common messages
    if(Scene::HandleMessage(pManagerSet, sMessage, sFunction, vArgs))
    {
        return;
    }
}

};
