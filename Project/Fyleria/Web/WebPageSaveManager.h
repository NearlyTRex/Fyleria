// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_WEB_PAGE_SAVE_MANAGER_H_
#define _GECKO_WEB_PAGE_SAVE_MANAGER_H_

#include "Web/WebPage.h"

namespace Gecko
{

class WebPageSaveManager : public WebPage
{
public:

    // Constructors
    WebPageSaveManager();

    // Destructor
    virtual ~WebPageSaveManager();

    // Update page content
    virtual void UpdatePageContent(const ParameterMapType& tParams);
};

// Typedefs
MAKE_TYPE_TYPEDEFS(WebPageSaveManager);

};

#endif
