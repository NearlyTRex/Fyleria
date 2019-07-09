// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneCharacterCreation.h"
#include "Window/MainWindow.h"
#include "Utility/Constants.h"

namespace Gecko
{

SceneCharacterCreation::SceneCharacterCreation()
    : Scene()
{
}

SceneCharacterCreation::~SceneCharacterCreation()
{
}

void SceneCharacterCreation::Start()
{
    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneCharacterCreation::OnMessageReceived, this, STDPlaceholder1));

    // Load page content
    LoadHtmlFromFile(WEB_PAGE_SYSTEM_CHARACTER_CREATION);
}

void SceneCharacterCreation::Finish()
{
    // Clear callbacks
    ClearPostCallback();
}

void SceneCharacterCreation::Update()
{
}

void SceneCharacterCreation::Input()
{
}

void SceneCharacterCreation::OnMessageReceived(const String& sMessage)
{
    // Handle common messages
    if(Scene::HandleMessage(sMessage))
    {
        return;
    }
}

};
