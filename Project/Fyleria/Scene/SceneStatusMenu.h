// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_SCENE_SCENE_STATUS_MENU_H_
#define _GECKO_SCENE_SCENE_STATUS_MENU_H_

// Internal includes
#include "Scene/Scene.h"

namespace Gecko
{

class SceneStatusMenu : public Scene
{
public:

    // Constructor
    SceneStatusMenu();

    // Destructor
    virtual ~SceneStatusMenu();

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
MAKE_COMMON_TYPEDEFS(SceneStatusMenu);

};

#endif
