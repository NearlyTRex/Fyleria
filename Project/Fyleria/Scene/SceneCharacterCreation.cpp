// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneCharacterCreation.h"
#include "Window/MainWindow.h"

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
    SET_JAVASCRIPT_POST_CALLBACK(SceneCharacterCreation, OnMessageReceived);
}

void SceneCharacterCreation::Finish()
{
    // Clear callbacks
    CLEAR_JAVASCRIPT_POST_CALLBACK();
}

void SceneCharacterCreation::Update()
{
}

void SceneCharacterCreation::Input()
{
}

void SceneCharacterCreation::OnMessageReceived(const String& sMessage)
{
}

};
