// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneToolMain.h"
#include "Window/MainWindow.h"
#include "Utility/Constants.h"

namespace Gecko
{

SceneToolMain::SceneToolMain()
    : Scene()
{
}

SceneToolMain::~SceneToolMain()
{
}

void SceneToolMain::Start(ManagerSet* pManagerSet)
{
    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneToolMain::OnMessageReceived, this, pManagerSet, STDPlaceholder1));

    // Load page content
    InjectCommonData();
    LoadHtmlFromFile(PAGE_FILE_TOOL_MAIN);
}

void SceneToolMain::Finish(ManagerSet* pManagerSet)
{
    // Clear callbacks
    ClearPostCallback();

    // Clear page content
    RemoveAllInjectedData();
}

void SceneToolMain::Update(ManagerSet* pManagerSet)
{
}

void SceneToolMain::Input(ManagerSet* pManagerSet)
{
}

void SceneToolMain::OnMessageReceived(ManagerSet* pManagerSet, const String& sMessage)
{
    // Function / arguments
    String sFunction;
    StringArray vArgs;

    // Handle common messages
    if(Scene::HandleMessage(pManagerSet, sMessage, sFunction, vArgs))
    {
        return;
    }
}

};
