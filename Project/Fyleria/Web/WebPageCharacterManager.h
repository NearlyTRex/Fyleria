// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_WEB_PAGE_CHARACTER_MANAGER_H_
#define _GECKO_WEB_PAGE_CHARACTER_MANAGER_H_

#include "Web/WebPage.h"

namespace Gecko
{

class WebPageCharacterManager : public WebPage
{
public:

    // Constructors
    WebPageCharacterManager();

    // Destructor
    virtual ~WebPageCharacterManager();

    // Update page content
    virtual void UpdatePageContent(const ParameterMapType& tParams) override;
};

// Typedefs
MAKE_TYPE_TYPEDEFS(WebPageCharacterManager);

};

#endif
