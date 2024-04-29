// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Scene/SceneBattle.h"
#include "Scene/SceneTypes.h"
#include "Window/MainWindow.h"
#include "Application/Application.h"

namespace Gecko
{

SceneBattle::SceneBattle()
    : Scene(GetEnumString(SceneType::Battle))
{
}

SceneBattle::~SceneBattle()
{
}

void SceneBattle::Start()
{
    // Call parent
    Scene::Start();

    // Set main page content
    SetMainPageContent();
}

void SceneBattle::Finish()
{
    // Call parent
    Scene::Finish();
}

void SceneBattle::Update()
{
}

void SceneBattle::Input()
{
}

};
