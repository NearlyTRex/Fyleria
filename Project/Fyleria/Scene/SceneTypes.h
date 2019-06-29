// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_SCENE_TYPES_H_
#define _GECKO_SCENE_TYPES_H_

// Internal includes
#include "Utility/Assert.h"
#include "Utility/Macros.h"
#include "Utility/Enum.h"

namespace Gecko
{

BETTER_ENUM(SceneMessageFunctionType, Int,
    None,
    SwitchToScene,
    ProcessForm,
    ReloadPage
);

};

#endif
