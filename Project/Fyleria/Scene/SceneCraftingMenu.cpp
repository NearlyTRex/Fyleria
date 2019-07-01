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

void SceneCraftingMenu::Start()
{
    // Register callbacks
    SetPostCallback(CREATE_JAVASCRIPT_CLASS_CALLBACK(SceneCraftingMenu, OnMessageReceived));

    // Load page content
    LoadHtmlFromFile(WEB_PAGE_SYSTEM_CRAFTING_MENU);
}

void SceneCraftingMenu::Finish()
{
    // Clear callbacks
    ClearPostCallback();
}

void SceneCraftingMenu::Update()
{
}

void SceneCraftingMenu::Input()
{
}

void SceneCraftingMenu::OnMessageReceived(const String& sMessage)
{
    // Handle common messages
    if(Scene::HandleMessage(sMessage))
    {
        return;
    }
}

};
