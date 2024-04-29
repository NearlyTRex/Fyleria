// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Scene/SceneCredits.h"
#include "Scene/SceneTypes.h"
#include "Window/MainWindow.h"
#include "Application/Application.h"

namespace Gecko
{

SceneCredits::SceneCredits()
    : Scene(GetEnumString(SceneType::Credits))
{
}

SceneCredits::~SceneCredits()
{
}

void SceneCredits::Start()
{
    // Call parent
    Scene::Start();

    // Set main page content
    SetMainPageContent();
}

void SceneCredits::Finish()
{
    // Call parent
    Scene::Finish();
}

void SceneCredits::Update()
{
}

void SceneCredits::Input()
{
}

};
