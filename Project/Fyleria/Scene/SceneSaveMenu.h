// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_SCENE_SCENE_SAVE_MENU_H_
#define _GECKO_SCENE_SCENE_SAVE_MENU_H_

// Internal includes
#include "Scene/Scene.h"

namespace Gecko
{

class SceneSaveMenu : public Scene
{
public:

    // Constructor
    SceneSaveMenu();

    // Destructor
    virtual ~SceneSaveMenu();

    // Start scene
    virtual void Start() override;

    // Finish scene
    virtual void Finish() override;

    // Update scene
    virtual void Update() override;

    // Handle scene input
    virtual void Input() override;
};

// Typedef
MAKE_COMMON_TYPEDEFS(SceneSaveMenu);

};

#endif
