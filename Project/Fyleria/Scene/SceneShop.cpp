// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneShop.h"
#include "Window/MainWindow.h"
#include "Utility/Constants.h"

namespace Gecko
{

SceneShop::SceneShop()
    : Scene()
{
}

SceneShop::~SceneShop()
{
}

void SceneShop::Start(ManagerSet* pManagerSet)
{
    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneShop::OnMessageReceived, this, STDPlaceholder1));

    // Load page content
    LoadHtmlFromFile(PAGE_FILE_SHOP);
}

void SceneShop::Finish(ManagerSet* pManagerSet)
{
    // Clear callbacks
    ClearPostCallback();
}

void SceneShop::Update(ManagerSet* pManagerSet)
{
}

void SceneShop::Input(ManagerSet* pManagerSet)
{
}

void SceneShop::OnMessageReceived(ManagerSet* pManagerSet, const String& sMessage)
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
