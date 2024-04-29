// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Scene/SceneLoading.h"
#include "Scene/SceneTypes.h"
#include "Window/MainWindow.h"
#include "Application/Application.h"

namespace Gecko
{

SceneLoading::SceneLoading()
    : Scene(GetEnumString(SceneType::Loading))
{
}

SceneLoading::~SceneLoading()
{
}

void SceneLoading::Start()
{
    // Call parent
    Scene::Start();

    // Set main page content
    SetMainPageContent();
}

void SceneLoading::Finish()
{
    // Call parent
    Scene::Finish();
}

void SceneLoading::Update()
{
}

void SceneLoading::Input()
{
}

};
