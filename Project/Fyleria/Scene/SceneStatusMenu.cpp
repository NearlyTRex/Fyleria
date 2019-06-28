// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneStatusMenu.h"
#include "Window/MainWindow.h"

namespace Gecko
{

SceneStatusMenu::SceneStatusMenu()
    : Scene()
{
}

SceneStatusMenu::~SceneStatusMenu()
{
}

void SceneStatusMenu::Start()
{
    // Register callbacks
    SET_JAVASCRIPT_POST_CALLBACK(SceneStatusMenu, OnMessageReceived);
}

void SceneStatusMenu::Finish()
{
    // Clear callbacks
    CLEAR_JAVASCRIPT_POST_CALLBACK();
}

void SceneStatusMenu::Update()
{
}

void SceneStatusMenu::Input()
{
}

void SceneStatusMenu::OnMessageReceived(const String& sMessage)
{
}

};
