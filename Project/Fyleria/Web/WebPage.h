// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_WEB_PAGE_H_
#define _GECKO_WEB_PAGE_H_

#include "Utility/Macros.h"
#include "Utility/Tree.h"
#include "Utility/Enum.h"
#include "Utility/Json.h"
#include "Utility/Types.h"
#include "Utility/Serializable.h"

namespace Gecko
{

class WebPage
{
public:

    // Types
    typedef STDUnorderedMap<String, String> ParameterMapType;

    // Constructors
    WebPage();

    // Destructor
    virtual ~WebPage();

    // Update page content
    virtual void UpdatePageContent(const ParameterMapType& tParams) = 0;

    // Page content
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(PageContent, String);

    // Page template
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(PageTemplate, String);
};

// Typedefs
MAKE_TYPE_TYPEDEFS(WebPage);

};

#endif
