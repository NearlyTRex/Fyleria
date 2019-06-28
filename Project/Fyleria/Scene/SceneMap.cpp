// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneMap.h"
#include "Window/MainWindow.h"

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
    SET_JAVASCRIPT_POST_CALLBACK(SceneMap, OnMessageReceived);
}

void SceneMap::Finish()
{
    // Clear callbacks
    CLEAR_JAVASCRIPT_POST_CALLBACK();
}

void SceneMap::Update()
{
}

void SceneMap::Input()
{
}

void SceneMap::OnMessageReceived(const String& sMessage)
{
}

};
