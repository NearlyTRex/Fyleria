// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Scene/SceneSaveMenu.h"
#include "Scene/SceneTypes.h"
#include "Window/MainWindow.h"
#include "Application/Application.h"

namespace Gecko
{

SceneSaveMenu::SceneSaveMenu()
    : Scene((+SceneType::SaveMenu)._to_string())
{
}

SceneSaveMenu::~SceneSaveMenu()
{
}

void SceneSaveMenu::Start()
{
    // Call parent
    Scene::Start();

    // Set main page content
    SetMainPageContent();
}

void SceneSaveMenu::Finish()
{
    // Call parent
    Scene::Finish();
}

void SceneSaveMenu::Update()
{
}

void SceneSaveMenu::Input()
{
}

};
