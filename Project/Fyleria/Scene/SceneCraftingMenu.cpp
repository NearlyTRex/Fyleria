// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneCraftingMenu.h"
#include "Window/MainWindow.h"
#include "Utility/Constants.h"
#include "Utility/ManagerSet.h"

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
    // Check manager set
    CHECK_MANAGER_SET_PTR(pManagerSet);

    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneCraftingMenu::OnMessageReceived, this, pManagerSet, STDPlaceholder1));

    // Page location
    String sLocation = pManagerSet->GetFileManager().GetDataPagesDirectory();

    // Load page content
    InjectCommonData(pManagerSet);
    InjectStylesheetFile(PAGE_FILE_CRAFTING_MENU_CSS, sLocation);
    InjectJavascriptFile(PAGE_FILE_CRAFTING_MENU_JS, sLocation);
    SetHtmlContentFile(PAGE_FILE_CRAFTING_MENU_HTML, sLocation);
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
