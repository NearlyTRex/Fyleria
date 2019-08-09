// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneToolSave.h"
#include "Web/WebPageHandlerSaveTool.h"

namespace Gecko
{

SceneToolSave::SceneToolSave()
    : Scene()
{
    // Create handler
    SetPageHandler(STDMakeSharedPtr<WebPageHandlerSaveTool>());
}

SceneToolSave::~SceneToolSave()
{
}

void SceneToolSave::Start(ManagerSet* pManagerSet)
{
    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneToolSave::OnMessageReceived, this, STDPlaceholder1));

    // Load page content
    LoadHtmlFromHandler(GetPageHandler());
}

void SceneToolSave::Finish(ManagerSet* pManagerSet)
{
    // Clear callbacks
    ClearPostCallback();
}

void SceneToolSave::Update(ManagerSet* pManagerSet)
{
}

void SceneToolSave::Input(ManagerSet* pManagerSet)
{
}

void SceneToolSave::OnMessageReceived(ManagerSet* pManagerSet, const String& sMessage)
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
