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

void SceneMainMenu::Start(ManagerSet* pManagerSet)
{
    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneMainMenu::OnMessageReceived, this, STDPlaceholder1));

    // Load page content
    LoadHtmlFromFile(PAGE_FILE_MAIN_MENU);
}

void SceneMainMenu::Finish(ManagerSet* pManagerSet)
{
    // Clear callbacks
    ClearPostCallback();
}

void SceneMainMenu::Update(ManagerSet* pManagerSet)
{
}

void SceneMainMenu::Input(ManagerSet* pManagerSet)
{
}

void SceneMainMenu::OnMessageReceived(ManagerSet* pManagerSet, const String& sMessage)
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
