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
    SET_JAVASCRIPT_POST_CALLBACK(SceneLoading, OnMessageReceived);
}

void SceneLoading::Finish()
{
    // Clear callbacks
    CLEAR_JAVASCRIPT_POST_CALLBACK();
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
