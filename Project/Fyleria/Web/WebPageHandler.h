// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_WEB_PAGE_HANDLER_H_
#define _GECKO_WEB_PAGE_HANDLER_H_

#include "Utility/Macros.h"
#include "Utility/Tree.h"
#include "Utility/Enum.h"
#include "Utility/Json.h"
#include "Utility/Types.h"
#include "Utility/Serializable.h"

namespace Gecko
{

class WebPageHandler
{
public:

    // Constructors
    WebPageHandler();

    // Destructor
    virtual ~WebPageHandler();

    // Update page content
    virtual void UpdatePageContent(const StringMap& tParams) = 0;

    // Page content
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(PageContent, String);

    // Page template
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(PageTemplate, String);
};

// Typedefs
MAKE_TYPE_TYPEDEFS(WebPageHandler);

};

#endif
