// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneLoading.h"
#include "Window/MainWindow.h"
#include "Utility/Constants.h"

namespace Gecko
{

SceneLoading::SceneLoading()
    : Scene()
{
}

SceneLoading::~SceneLoading()
{
}

void SceneLoading::Start(ManagerSet* pManagerSet)
{
    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneLoading::OnMessageReceived, this, STDPlaceholder1));

    // Load page content
    LoadHtmlFromFile(PAGE_FILE_LOADING);
}

void SceneLoading::Finish(ManagerSet* pManagerSet)
{
    // Clear callbacks
    ClearPostCallback();
}

void SceneLoading::Update(ManagerSet* pManagerSet)
{
}

void SceneLoading::Input(ManagerSet* pManagerSet)
{
}

void SceneLoading::OnMessageReceived(ManagerSet* pManagerSet, const String& sMessage)
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
