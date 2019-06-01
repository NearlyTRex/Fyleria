// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_WEB_PAGE_PARTY_MANAGER_H_
#define _GECKO_WEB_PAGE_PARTY_MANAGER_H_

#include "Web/WebPage.h"

namespace Gecko
{

class WebPagePartyManager : public WebPage
{
public:

    // Constructors
    WebPagePartyManager();

    // Destructor
    virtual ~WebPagePartyManager();

    // Update page content
    virtual void UpdatePageContent(const ParameterMapType& tParams);
};

// Typedefs
MAKE_TYPE_TYPEDEFS(WebPagePartyManager);

};

#endif
