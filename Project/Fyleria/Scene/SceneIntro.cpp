// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneIntro.h"
#include "Window/MainWindow.h"

namespace Gecko
{

SceneIntro::SceneIntro()
    : Scene()
{
}

SceneIntro::~SceneIntro()
{
}

void SceneIntro::Start()
{
    // Register callbacks
    SET_JAVASCRIPT_POST_CALLBACK(SceneIntro, OnMessageReceived);
}

void SceneIntro::Finish()
{
    // Clear callbacks
    CLEAR_JAVASCRIPT_POST_CALLBACK();
}

void SceneIntro::Update()
{
}

void SceneIntro::Input()
{
}

void SceneIntro::OnMessageReceived(const String& sMessage)
{
}

};
