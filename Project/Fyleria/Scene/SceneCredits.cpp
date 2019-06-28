// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneCredits.h"
#include "Window/MainWindow.h"

namespace Gecko
{

SceneCredits::SceneCredits()
    : Scene()
{
}

SceneCredits::~SceneCredits()
{
}

void SceneCredits::Start()
{
    // Register callbacks
    SET_JAVASCRIPT_POST_CALLBACK(SceneCredits, OnMessageReceived);
}

void SceneCredits::Finish()
{
    // Clear callbacks
    CLEAR_JAVASCRIPT_POST_CALLBACK();
}

void SceneCredits::Update()
{
}

void SceneCredits::Input()
{
}

void SceneCredits::OnMessageReceived(const String& sMessage)
{
}

};
