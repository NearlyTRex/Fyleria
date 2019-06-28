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
    SET_JAVASCRIPT_POST_CALLBACK(SceneToolCharacter, OnMessageReceived);
}

void SceneToolCharacter::Finish()
{
    // Clear callbacks
    CLEAR_JAVASCRIPT_POST_CALLBACK();
}

void SceneToolCharacter::Update()
{
}

void SceneToolCharacter::Input()
{
}

void SceneToolCharacter::OnMessageReceived(const String& sMessage)
{
}

};
