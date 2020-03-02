// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_SCENE_TYPES_H_
#define _GECKO_SCENE_TYPES_H_

// Internal includes
#include "Utility/Macros.h"
#include "Utility/Enum.h"

namespace Gecko
{

BETTER_ENUM(SceneType, Int,
    None,
    Start,
    Intro,
    Loading,
    MainMenu,
    StatusMenu,
    SaveMenu,
    CraftingMenu,
    Map,
    Shop,
    Battle,
    CharacterCreation,
    Credits,
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
