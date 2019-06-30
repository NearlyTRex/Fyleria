// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneToolCharacter.h"
#include "Window/MainWindow.h"

namespace Gecko
{

SceneToolCharacter::SceneToolCharacter()
    : Scene()
{
}

SceneToolCharacter::~SceneToolCharacter()
{
}

void SceneToolCharacter::Start()
{
    // Register callbacks
    SetPostCallback(CREATE_JAVASCRIPT_CLASS_CALLBACK(SceneToolCharacter, OnMessageReceived));
}

void SceneToolCharacter::Finish()
{
    // Clear callbacks
    ClearPostCallback();
}

void SceneToolCharacter::Update()
{
}

void SceneToolCharacter::Input()
{
}

void SceneToolCharacter::OnMessageReceived(const String& sMessage)
{
    // Handle common messages
    if(Scene::HandleMessage(sMessage))
    {
        return;
    }
}

};
