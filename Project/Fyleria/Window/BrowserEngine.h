// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_BROWSER_ENGINE_H_
#define _GECKO_BROWSER_ENGINE_H_

// Internal includes
#include "Utility/Types.h"
#include "Utility/Macros.h"
#include "Utility/Logging.h"

namespace Gecko
{

// Browser engine interface
class BrowserEngine
{
public:

    // Types
    typedef STDFunction<void(const String&)> JavascriptCallback;

    // Constructor
    BrowserEngine();

    // Destructor
    virtual ~BrowserEngine();

    // Initialize
    virtual Bool Init(const String& sTitle, Int iWidth, Int iHeight, Bool bResizable) = 0;

    // Shutdown
    virtual void Shutdown() = 0;

    // Navigate to url
    virtual void Navigate(const String& sUrl) = 0;

    // Inject stylesheet
    virtual void InjectStylesheet(const String& sStyle) = 0;

    // Inject stylesheet file
    virtual void InjectStylesheetFile(const String& sFile) = 0;

    // Remove all injected stylesheets
    virtual void RemoveAllInjectedStylesheets() = 0;

    // Inject javascript
    virtual void InjectJavascript(const String& sScript) = 0;

    // Inject javascript file
    virtual void InjectJavascriptFile(const String& sFile) = 0;

    // Remove all injected javascript
    virtual void RemoveAllInjectedJavascript() = 0;

    // Run javascript
    virtual void RunJavascript(const String& sScript) = 0;

    // Set html content
    virtual void SetHtmlContent(const String& sHtml) = 0;

    // Run main loop iteration
    virtual void RunMainLoopIteration(Bool bBlocking) = 0;

    // Get common javascript shortcuts
    String GetCommonJavascriptShortcuts();

    // Shutting down
    MAKE_RAW_BASIC_TYPE_ACCESSORS(IsShuttingDown, Bool);

    // Post (Javascript -> C++) callback
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(PostJavascriptCallback, JavascriptCallback);

    // Run result (C++ -> Javascript) callback
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(RunResultJavascriptCallback, JavascriptCallback);
};

};

#endif
