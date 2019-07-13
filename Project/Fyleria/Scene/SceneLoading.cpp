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

void SceneLoading::Start()
{
    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneLoading::OnMessageReceived, this, STDPlaceholder1));

    // Load page content
    LoadHtmlFromFile(WEB_FILE_SYSTEM_LOADING);
}

void SceneLoading::Finish()
{
    // Clear callbacks
    ClearPostCallback();
}

void SceneLoading::Update()
{
}

void SceneLoading::Input()
{
}

void SceneLoading::OnMessageReceived(const String& sMessage)
{
    // Handle common messages
    if(Scene::HandleMessage(sMessage))
    {
        return;
    }
}

};
