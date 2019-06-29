// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneLoading.h"
#include "Window/MainWindow.h"

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
    SetPostCallback(CREATE_JAVASCRIPT_CLASS_CALLBACK(SceneLoading, OnMessageReceived));
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
}

};
