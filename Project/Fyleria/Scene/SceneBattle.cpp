// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneBattle.h"
#include "Window/MainWindow.h"

namespace Gecko
{

SceneBattle::SceneBattle()
    : Scene()
{
}

SceneBattle::~SceneBattle()
{
}

void SceneBattle::Start()
{
    // Register callbacks
    SetPostCallback(CREATE_JAVASCRIPT_CLASS_CALLBACK(SceneBattle, OnMessageReceived));
}

void SceneBattle::Finish()
{
    // Clear callbacks
    ClearPostCallback();
}

void SceneBattle::Update()
{
}

void SceneBattle::Input()
{
}

void SceneBattle::OnMessageReceived(const String& sMessage)
{
}

};
