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
    SET_JAVASCRIPT_POST_CALLBACK(SceneShop, OnMessageReceived);
}

void SceneShop::Finish()
{
    // Clear callbacks
    CLEAR_JAVASCRIPT_POST_CALLBACK();
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
