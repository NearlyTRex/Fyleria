// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_WEB_MANAGER_H_
#define _GECKO_WEB_MANAGER_H_

#include "Web/WebPageHandlerCharacterTool.h"
#include "Web/WebPageHandlerPartyTool.h"
#include "Web/WebPageHandlerSaveTool.h"
#include "Utility/Types.h"
#include "Utility/Singleton.h"
#include "Utility/Macros.h"

namespace Gecko
{

class WebManager : public Singleton<WebManager>
{
public:

    // Constructors
    WebManager();

    // Character tool handler
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(CharacterToolHandler, WebPageHandlerCharacterTool);

    // Party tool handler
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(PartyToolHandler, WebPageHandlerPartyTool);

    // Save tool handler
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SaveToolHandler, WebPageHandlerSaveTool);
};

};

#endif
