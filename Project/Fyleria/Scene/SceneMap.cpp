// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneMap.h"
#include "Window/MainWindow.h"
#include "Utility/Constants.h"

namespace Gecko
{

SceneMap::SceneMap()
    : Scene()
{
}

SceneMap::~SceneMap()
{
}

void SceneMap::Start()
{
    // Register callbacks
    SetPostCallback(CREATE_JAVASCRIPT_CLASS_CALLBACK(SceneMap, OnMessageReceived));

    // Load page content
    LoadHtmlFromFile(WEB_PAGE_SYSTEM_MAP);
}

void SceneMap::Finish()
{
    // Clear callbacks
    ClearPostCallback();
}

void SceneMap::Update()
{
}

void SceneMap::Input()
{
}

void SceneMap::OnMessageReceived(const String& sMessage)
{
    // Handle common messages
    if(Scene::HandleMessage(sMessage))
    {
        return;
    }
}

};
