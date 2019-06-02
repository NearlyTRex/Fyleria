// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_WEB_PAGE_MANAGER_H_
#define _GECKO_WEB_PAGE_MANAGER_H_

#include "Web/WebPageCharacterManager.h"
#include "Web/WebPagePartyManager.h"
#include "Web/WebPageSaveManager.h"
#include "Utility/Types.h"
#include "Utility/Singleton.h"
#include "Utility/Macros.h"

namespace Gecko
{

class WebPageManager : public Singleton<WebPageManager>
{
public:

    // Constructors
    WebPageManager();

    // Character manager
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(CharacterManagerPage, WebPageCharacterManager);

    // Party manager
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(PartyManagerPage, WebPagePartyManager);

    // Save manager
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SaveManagerPage, WebPageSaveManager);
};

};

#endif
