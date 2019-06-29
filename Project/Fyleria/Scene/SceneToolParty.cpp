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
    SetPostCallback(CREATE_JAVASCRIPT_CLASS_CALLBACK(SceneToolParty, OnMessageReceived));
}

void SceneToolParty::Finish()
{
    // Clear callbacks
    ClearPostCallback();
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
