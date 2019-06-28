// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneCraftingMenu.h"
#include "Window/MainWindow.h"

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
    SET_JAVASCRIPT_POST_CALLBACK(SceneCraftingMenu, OnMessageReceived);
}

void SceneCraftingMenu::Finish()
{
    // Clear callbacks
    CLEAR_JAVASCRIPT_POST_CALLBACK();
}

void SceneCraftingMenu::Update()
{
}

void SceneCraftingMenu::Input()
{
}

void SceneCraftingMenu::OnMessageReceived(const String& sMessage)
{
}

};
