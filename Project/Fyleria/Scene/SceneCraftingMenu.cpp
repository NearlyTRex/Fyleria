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
    SetPostCallback(STDBindFunc(&SceneCraftingMenu::OnMessageReceived, this, STDPlaceholder1));

    // Load page content
    LoadHtmlFromFile(PAGE_FILE_CRAFTING_MENU);
}

void SceneCraftingMenu::Finish(ManagerSet* pManagerSet)
{
    // Clear callbacks
    ClearPostCallback();
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
    if(Scene::HandleMessage(sMessage, sFunction, vArgs))
    {
        return;
    }
}

};
