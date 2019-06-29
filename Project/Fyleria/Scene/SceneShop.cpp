// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneShop.h"
#include "Window/MainWindow.h"

namespace Gecko
{

SceneShop::SceneShop()
    : Scene()
{
}

SceneShop::~SceneShop()
{
}

void SceneShop::Start()
{
    // Register callbacks
    SetPostCallback(CREATE_JAVASCRIPT_CLASS_CALLBACK(SceneShop, OnMessageReceived));
}

void SceneShop::Finish()
{
    // Clear callbacks
    ClearPostCallback();
}

void SceneShop::Update()
{
}

void SceneShop::Input()
{
}

void SceneShop::OnMessageReceived(const String& sMessage)
{
}

};
