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

// Manager set
class ManagerSet;

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
    virtual Bool Init(ManagerSet* pManagerSet, const String& sTitle, Int iWidth, Int iHeight, Bool bResizable) = 0;

    // Shutdown
    virtual void Shutdown() = 0;

    // Navigate to url
    virtual void Navigate(const String& sUrl) = 0;

    // Inject system javascript
    virtual void InjectSystemJavascript(const String& sScript);

    // Inject user stylesheet
    virtual void InjectUserStylesheet(const String& sStyle);

    // Inject user stylesheet file
    virtual void InjectUserStylesheetFile(const String& sFile);

    // Inject user javascript
    virtual void InjectUserJavascript(const String& sScript);

    // Inject user javascript file
    virtual void InjectUserJavascriptFile(const String& sFile);

    // Inject user html
    virtual void InjectUserHtml(const String& sHtml);

    // Inject user html file
    virtual void InjectUserHtmlFile(const String& sFile);

    // Remove all user injected data
    virtual void RemoveAllUserInjectedData();

    // Run javascript
    virtual void RunJavascript(const String& sScript) = 0;

    // Set html content
    virtual void SetHtmlContent(const String& sHtml) = 0;

    // Set html content file
    virtual void SetHtmlContentFile(const String& sFile) = 0;

    // Run main loop iteration
    virtual void RunMainLoopIteration(Bool bBlocking) = 0;

    // Define javascript shortcut
    virtual void DefineJavascriptShortcut(const String& sFunction, const String& sArgs);

    // Clear javascript shortcut
    virtual void ClearJavascriptShortcut(const String& sFunction);

    // Shutting down
    MAKE_RAW_TYPE_ACCESSORS(IsShuttingDown, Bool);

    // Post (Javascript -> C++) callback
    MAKE_RAW_TYPE_ACCESSORS(PostJavascriptCallback, JavascriptCallback);

    // Run result (C++ -> Javascript) callback
    MAKE_RAW_TYPE_ACCESSORS(RunResultJavascriptCallback, JavascriptCallback);

    // System scripts
    MAKE_RAW_TYPE_ACCESSORS(SystemScripts, String);

    // User styles
    MAKE_RAW_TYPE_ACCESSORS(UserStyles, String);

    // User scripts
    MAKE_RAW_TYPE_ACCESSORS(UserScripts, String);

    // User markup
    MAKE_RAW_TYPE_ACCESSORS(UserMarkup, String);
};

// Typedefs
MAKE_COMMON_TYPEDEFS(BrowserEngine);

};

#endif
