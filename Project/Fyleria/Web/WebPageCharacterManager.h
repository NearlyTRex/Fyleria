// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_WEB_PAGE_HANDLER_CHARACTER_TOOL_H_
#define _GECKO_WEB_PAGE_HANDLER_CHARACTER_TOOL_H_

#include "Web/WebPageHandler.h"

namespace Gecko
{

class WebPageHandlerCharacterTool : public WebPageHandler
{
public:

    // Constructors
    WebPageHandlerCharacterTool();

    // Destructor
    virtual ~WebPageHandlerCharacterTool();

    // Initialize
    virtual void Init() override;

    // Update page content
    virtual void UpdatePageContent(const ParameterMapType& tParams) override;
};

// Typedefs
MAKE_TYPE_TYPEDEFS(WebPageHandlerCharacterTool);

};

#endif
