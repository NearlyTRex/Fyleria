// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneCredits.h"
#include "Window/MainWindow.h"
#include "Utility/Constants.h"

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
    SetPostCallback(CREATE_JAVASCRIPT_CLASS_CALLBACK(SceneCredits, OnMessageReceived));

    // Load page content
    LoadHtmlFromFile(WEB_PAGE_SYSTEM_CREDITS);
}

void SceneCredits::Finish()
{
    // Clear callbacks
    ClearPostCallback();
}

void SceneCredits::Update()
{
}

void SceneCredits::Input()
{
}

void SceneCredits::OnMessageReceived(const String& sMessage)
{
    // Handle common messages
    if(Scene::HandleMessage(sMessage))
    {
        return;
    }
}

};
