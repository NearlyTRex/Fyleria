// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneMainMenu.h"
#include "Window/MainWindow.h"
#include "Utility/Constants.h"

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
    SetPostCallback(CREATE_JAVASCRIPT_CLASS_CALLBACK(SceneMainMenu, OnMessageReceived));

    // Load page content
    LoadHtmlFromFile(WEB_PAGE_SYSTEM_MAIN_MENU);
}

void SceneMainMenu::Finish()
{
    // Clear callbacks
    ClearPostCallback();
}

void SceneMainMenu::Update()
{
}

void SceneMainMenu::Input()
{
}

void SceneMainMenu::OnMessageReceived(const String& sMessage)
{
    // Handle common messages
    if(Scene::HandleMessage(sMessage))
    {
        return;
    }
}

};
