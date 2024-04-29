// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Scene/SceneMap.h"
#include "Scene/SceneTypes.h"
#include "Window/MainWindow.h"
#include "Application/Application.h"

namespace Gecko
{

SceneMap::SceneMap()
    : Scene(GetEnumString(SceneType::Map))
{
}

SceneMap::~SceneMap()
{
}

void SceneMap::Start()
{
    // Call parent
    Scene::Start();

    // Set main page content
    SetMainPageContent();
}

void SceneMap::Finish()
{
    // Call parent
    Scene::Finish();
}

void SceneMap::Update()
{
}

void SceneMap::Input()
{
}

};
