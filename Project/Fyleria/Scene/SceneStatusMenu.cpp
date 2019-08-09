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

void SceneStatusMenu::Start(ManagerSet* pManagerSet)
{
    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneStatusMenu::OnMessageReceived, this, STDPlaceholder1));

    // Load page content
    LoadHtmlFromFile(PAGE_FILE_STATUS_MENU);
}

void SceneStatusMenu::Finish(ManagerSet* pManagerSet)
{
    // Clear callbacks
    ClearPostCallback();
}

void SceneStatusMenu::Update(ManagerSet* pManagerSet)
{
}

void SceneStatusMenu::Input(ManagerSet* pManagerSet)
{
}

void SceneStatusMenu::OnMessageReceived(ManagerSet* pManagerSet, const String& sMessage)
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
