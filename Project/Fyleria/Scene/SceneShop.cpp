// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Scene/SceneShop.h"
#include "Scene/SceneTypes.h"
#include "Window/MainWindow.h"
#include "Application/Application.h"

namespace Gecko
{

SceneShop::SceneShop()
    : Scene(GetEnumString(SceneType::Shop))
{
}

SceneShop::~SceneShop()
{
}

void SceneShop::Start()
{
    // Call parent
    Scene::Start();

    // Set main page content
    SetMainPageContent();
}

void SceneShop::Finish()
{
    // Call parent
    Scene::Finish();
}

void SceneShop::Update()
{
}

void SceneShop::Input()
{
}

};
