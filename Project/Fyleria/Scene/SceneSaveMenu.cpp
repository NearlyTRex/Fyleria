// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneSaveMenu.h"
#include "Window/MainWindow.h"

namespace Gecko
{

SceneSaveMenu::SceneSaveMenu()
    : Scene()
{
}

SceneSaveMenu::~SceneSaveMenu()
{
}

void SceneSaveMenu::Start()
{
    // Register callbacks
    SET_JAVASCRIPT_POST_CALLBACK(SceneSaveMenu, OnMessageReceived);
}

void SceneSaveMenu::Finish()
{
    // Clear callbacks
    CLEAR_JAVASCRIPT_POST_CALLBACK();
}

void SceneSaveMenu::Update()
{
}

void SceneSaveMenu::Input()
{
}

void SceneSaveMenu::OnMessageReceived(const String& sMessage)
{
}

};
