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
    SET_JAVASCRIPT_POST_CALLBACK(SceneToolMain, OnMessageReceived);
}

void SceneToolMain::Finish()
{
    // Clear callbacks
    CLEAR_JAVASCRIPT_POST_CALLBACK();
}

void SceneToolMain::Update()
{
}

void SceneToolMain::Input()
{
}

void SceneToolMain::OnMessageReceived(const String& sMessage)
{
}

};
