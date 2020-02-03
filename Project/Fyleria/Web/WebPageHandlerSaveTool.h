// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_WEB_PAGE_HANDLER_SAVE_TOOL_H_
#define _GECKO_WEB_PAGE_HANDLER_SAVE_TOOL_H_

// Internal includes
#include "Web/WebPageHandler.h"

namespace Gecko
{

// Save tool
class WebPageHandlerSaveTool : public WebPageHandler
{
public:

    // Constructors
    WebPageHandlerSaveTool(SafeObject<ManagerSet>& pManagerSet);

    // Destructor
    virtual ~WebPageHandlerSaveTool();

    // Update page content
    virtual void UpdatePageContent(SafeObject<ManagerSet>& pManagerSet, const StringMap& tParams) override;
};

// Typedefs
MAKE_COMMON_TYPEDEFS(WebPageHandlerSaveTool);

};

#endif
