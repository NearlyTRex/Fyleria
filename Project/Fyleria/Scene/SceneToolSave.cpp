// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Scene/SceneToolSave.h"
#include "Scene/SceneTypes.h"
#include "Application/Application.h"

namespace Gecko
{

SceneToolSave::SceneToolSave()
    : Scene(GetEnumString(SceneType::ToolSave))
{
}

SceneToolSave::~SceneToolSave()
{
}

void SceneToolSave::Start()
{
    // Call parent
    Scene::Start();

    // Set main page content
    SetMainPageContent();
}

void SceneToolSave::Finish()
{
    // Call parent
    Scene::Finish();
}

void SceneToolSave::Update()
{
}

void SceneToolSave::Input()
{
}

};
