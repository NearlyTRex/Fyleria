// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Scene/SceneCraftingMenu.h"
#include "Scene/SceneTypes.h"
#include "Window/MainWindow.h"
#include "Application/Application.h"

namespace Gecko
{

SceneCraftingMenu::SceneCraftingMenu()
    : Scene(GetEnumString(SceneType::CraftingMenu))
{
}

SceneCraftingMenu::~SceneCraftingMenu()
{
}

void SceneCraftingMenu::Start()
{
    // Call parent
    Scene::Start();

    // Set main page content
    SetMainPageContent();
}

void SceneCraftingMenu::Finish()
{
    // Call parent
    Scene::Finish();
}

void SceneCraftingMenu::Update()
{
}

void SceneCraftingMenu::Input()
{
}

};
