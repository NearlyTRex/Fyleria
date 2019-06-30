// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneToolMain.h"
#include "Window/MainWindow.h"

namespace Gecko
{

SceneToolMain::SceneToolMain()
    : Scene()
{
}

SceneToolMain::~SceneToolMain()
{
}

void SceneToolMain::Start()
{
    // Register callbacks
    SetPostCallback(CREATE_JAVASCRIPT_CLASS_CALLBACK(SceneToolMain, OnMessageReceived));
}

void SceneToolMain::Finish()
{
    // Clear callbacks
    ClearPostCallback();
}

void SceneToolMain::Update()
{
}

void SceneToolMain::Input()
{
}

void SceneToolMain::OnMessageReceived(const String& sMessage)
{
    // Handle common messages
    if(Scene::HandleMessage(sMessage))
    {
        return;
    }
}

};
