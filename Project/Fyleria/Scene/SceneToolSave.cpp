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

void SceneToolSave::Start()
{
    // Register callbacks
    SetPostCallback(CREATE_JAVASCRIPT_CLASS_CALLBACK(SceneToolSave, OnMessageReceived));

    // Load page content
    LoadHtmlFromHandler(GetPageHandler());
}

void SceneToolSave::Finish()
{
    // Clear callbacks
    ClearPostCallback();
}

void SceneToolSave::Update()
{
}

void SceneToolSave::Input()
{
}

void SceneToolSave::OnMessageReceived(const String& sMessage)
{
    // Handle common messages
    if(Scene::HandleMessage(sMessage))
    {
        return;
    }
}

};
