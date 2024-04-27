// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_SCENE_SCENE_TYPES_H_
#define _GECKO_SCENE_SCENE_TYPES_H_

// Internal includes
#include "Utility/Macros.h"
#include "Utility/Enum.h"

namespace Gecko
{

BETTER_ENUM(SceneType, Int,
    None,
    Battle,
    CharacterCreation,
    CraftingMenu,
    Credits,
    Intro,
    Loading,
    MainMenu,
    Map,
    SaveMenu,
    Shop,
    Start,
    StatusMenu,
    ToolCharacter,
    ToolParty,
    ToolSave
);

BETTER_ENUM(SceneMessageKeyType, Int,
    None,
    Function,
    Args
);

BETTER_ENUM(SceneMessageFunctionType, Int,
    None,
    SwitchToScene,
    SubmitForm
);

};

#endif
