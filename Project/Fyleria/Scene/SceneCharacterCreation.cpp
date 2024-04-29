// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Scene/SceneCharacterCreation.h"
#include "Scene/SceneTypes.h"
#include "Window/MainWindow.h"
#include "Application/Application.h"

namespace Gecko
{

SceneCharacterCreation::SceneCharacterCreation()
    : Scene(GetEnumString(SceneType::CharacterCreation))
{
}

SceneCharacterCreation::~SceneCharacterCreation()
{
}

void SceneCharacterCreation::Start()
{
    // Call parent
    Scene::Start();

    // Set main page content
    SetMainPageContent();
}

void SceneCharacterCreation::Finish()
{
    // Call parent
    Scene::Finish();
}

void SceneCharacterCreation::Update()
{
}

void SceneCharacterCreation::Input()
{
}

};
