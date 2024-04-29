// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Scene/SceneToolParty.h"
#include "Scene/SceneTypes.h"
#include "Application/Application.h"

namespace Gecko
{

SceneToolParty::SceneToolParty()
    : Scene(GetEnumString(SceneType::ToolParty))
{
}

SceneToolParty::~SceneToolParty()
{
}

void SceneToolParty::Start()
{
    // Call parent
    Scene::Start();

    // Set main page content
    SetMainPageContent();
}

void SceneToolParty::Finish()
{
    // Call parent
    Scene::Finish();
}

void SceneToolParty::Update()
{
}

void SceneToolParty::Input()
{
}

};
