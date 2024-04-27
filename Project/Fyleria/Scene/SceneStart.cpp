// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Scene/SceneIntro.h"
#include "Scene/SceneTypes.h"
#include "Window/MainWindow.h"
#include "Application/Application.h"

namespace Gecko
{

SceneStart::SceneStart()
    : Scene((+SceneType::Start)._to_string())
{
}

SceneStart::~SceneStart()
{
}

void SceneStart::Start()
{
    // Call parent
    Scene::Start();

    // Set main page content
    SetMainPageContent();
}

void SceneStart::Finish()
{
    // Call parent
    Scene::Finish();
}

void SceneStart::Update()
{
}

void SceneStart::Input()
{
}

};
