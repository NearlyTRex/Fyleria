// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneBattle.h"
#include "Window/MainWindow.h"
#include "Utility/Constants.h"

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

    // Load page content
    LoadHtmlFromFile(WEB_PAGE_SYSTEM_BATTLE);
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
    // Handle common messages
    if(Scene::HandleMessage(sMessage))
    {
        return;
    }
}

};
