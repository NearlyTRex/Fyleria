// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneSaveMenu.h"
#include "Window/MainWindow.h"
#include "Utility/Constants.h"

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
    SetPostCallback(STDBindFunc(&SceneSaveMenu::OnMessageReceived, this, STDPlaceholder1));

    // Load page content
    LoadHtmlFromFile(WEB_FILE_SYSTEM_SAVE_MENU);
}

void SceneSaveMenu::Finish()
{
    // Clear callbacks
    ClearPostCallback();
}

void SceneSaveMenu::Update()
{
}

void SceneSaveMenu::Input()
{
}

void SceneSaveMenu::OnMessageReceived(const String& sMessage)
{
    // Handle common messages
    if(Scene::HandleMessage(sMessage))
    {
        return;
    }
}

};
