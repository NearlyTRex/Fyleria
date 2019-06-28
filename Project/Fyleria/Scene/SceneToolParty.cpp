// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneToolParty.h"
#include "Window/MainWindow.h"

namespace Gecko
{

SceneToolParty::SceneToolParty()
    : Scene()
{
}

SceneToolParty::~SceneToolParty()
{
}

void SceneToolParty::Start()
{
    // Register callbacks
    SET_JAVASCRIPT_POST_CALLBACK(SceneToolParty, OnMessageReceived);
}

void SceneToolParty::Finish()
{
    // Clear callbacks
    CLEAR_JAVASCRIPT_POST_CALLBACK();
}

void SceneToolParty::Update()
{
}

void SceneToolParty::Input()
{
}

void SceneToolParty::OnMessageReceived(const String& sMessage)
{
}

};
