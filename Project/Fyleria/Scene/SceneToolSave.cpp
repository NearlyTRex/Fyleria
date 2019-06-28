// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneToolSave.h"
#include "Window/MainWindow.h"

namespace Gecko
{

SceneToolSave::SceneToolSave()
    : Scene()
{
}

SceneToolSave::~SceneToolSave()
{
}

void SceneToolSave::Start()
{
    // Register callbacks
    SET_JAVASCRIPT_POST_CALLBACK(SceneToolSave, OnMessageReceived);
}

void SceneToolSave::Finish()
{
    // Clear callbacks
    CLEAR_JAVASCRIPT_POST_CALLBACK();
}

void SceneToolSave::Update()
{
}

void SceneToolSave::Input()
{
}

void SceneToolSave::OnMessageReceived(const String& sMessage)
{
}

};
