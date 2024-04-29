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

MAKE_ENUM(SceneType, Int,
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
MAKE_ENUM_CONVERTERS_PROTO(SceneType);

MAKE_ENUM(SceneMessageKeyType, Int,
    None,
    Function,
    Args
);
MAKE_ENUM_CONVERTERS_PROTO(SceneMessageKeyType);

MAKE_ENUM(SceneMessageFunctionType, Int,
    None,
    SwitchToScene,
    SubmitForm
);
MAKE_ENUM_CONVERTERS_PROTO(SceneMessageFunctionType);

};

#endif
