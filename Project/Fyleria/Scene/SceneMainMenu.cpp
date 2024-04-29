// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Scene/SceneMainMenu.h"
#include "Scene/SceneTypes.h"
#include "Window/MainWindow.h"
#include "Application/Application.h"

namespace Gecko
{

SceneMainMenu::SceneMainMenu()
    : Scene(GetEnumString(SceneType::MainMenu))
{
}

SceneMainMenu::~SceneMainMenu()
{
}

void SceneMainMenu::Start()
{
    // Call parent
    Scene::Start();

    // Set main page content
    SetMainPageContent();
}

void SceneMainMenu::Finish()
{
    // Call parent
    Scene::Finish();
}

void SceneMainMenu::Update()
{
}

void SceneMainMenu::Input()
{
}

};
