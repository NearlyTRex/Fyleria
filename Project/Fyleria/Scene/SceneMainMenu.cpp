// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneMainMenu.h"
#include "Window/MainWindow.h"

namespace Gecko
{

SceneMainMenu::SceneMainMenu()
    : Scene()
{
}

SceneMainMenu::~SceneMainMenu()
{
}

void SceneMainMenu::Start()
{
    // Register callbacks
    SET_JAVASCRIPT_POST_CALLBACK(SceneMainMenu, OnMessageReceived);
}

void SceneMainMenu::Finish()
{
    // Clear callbacks
    CLEAR_JAVASCRIPT_POST_CALLBACK();
}

void SceneMainMenu::Update()
{
}

void SceneMainMenu::Input()
{
}

void SceneMainMenu::OnMessageReceived(const String& sMessage)
{
}

};
