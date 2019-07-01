// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneStatusMenu.h"
#include "Window/MainWindow.h"
#include "Utility/Constants.h"

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
    SetPostCallback(CREATE_JAVASCRIPT_CLASS_CALLBACK(SceneStatusMenu, OnMessageReceived));

    // Load page content
    LoadHtmlFromFile(WEB_PAGE_SYSTEM_STATUS_MENU);
}

void SceneStatusMenu::Finish()
{
    // Clear callbacks
    ClearPostCallback();
}

void SceneStatusMenu::Update()
{
}

void SceneStatusMenu::Input()
{
}

void SceneStatusMenu::OnMessageReceived(const String& sMessage)
{
    // Handle common messages
    if(Scene::HandleMessage(sMessage))
    {
        return;
    }
}

};
