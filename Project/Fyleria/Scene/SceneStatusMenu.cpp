// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Scene/SceneStatusMenu.h"
#include "Scene/SceneTypes.h"
#include "Window/MainWindow.h"
#include "Application/Application.h"

namespace Gecko
{

SceneStatusMenu::SceneStatusMenu()
    : Scene((+SceneType::StatusMenu)._to_string())
{
}

SceneStatusMenu::~SceneStatusMenu()
{
}

void SceneStatusMenu::Start()
{
    // Call parent
    Scene::Start();

    // Set main page content
    SetMainPageContent();
}

void SceneStatusMenu::Finish()
{
    // Call parent
    Scene::Finish();
}

void SceneStatusMenu::Update()
{
}

void SceneStatusMenu::Input()
{
}

};
