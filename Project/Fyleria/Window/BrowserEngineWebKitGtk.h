// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_BROWSER_ENGINE_WEBKITGTK_H_
#define _GECKO_BROWSER_ENGINE_WEBKITGTK_H_

// Linux only
#include "Utility/Platform.h"
#if defined(PLATFORM_OS_LINUX)

// External includes
#include <JavaScriptCore/JavaScript.h>
#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

// Internal includes
#include "Window/BrowserEngine.h"
#include "Utility/Types.h"

namespace Gecko
{

// WebKitGtk browser engine
class BrowserEngineWebKitGtk : public BrowserEngine
{
public:

    // Constructor
    BrowserEngineWebKitGtk();

    // Destructor
    virtual ~BrowserEngineWebKitGtk();

    // Initialize
    virtual Bool Init(ManagerSet* pManagerSet, const String& sTitle, Int iWidth, Int iHeight, Bool bResizable) override;

    // Shutdown
    virtual void Shutdown() override;

    // Navigate to url
    virtual void Navigate(const String& sUrl) override;

    // Inject system javascript
    virtual void InjectSystemJavascript(const String& sScript) override;

    // Inject user stylesheet
    virtual void InjectUserStylesheet(const String& sStyle) override;

    // Inject user stylesheet file
    virtual void InjectUserStylesheetFile(const String& sFile, const String& sFileRoot) override;

    // Inject user javascript
    virtual void InjectUserJavascript(const String& sScript) override;

    // Inject user javascript file
    virtual void InjectUserJavascriptFile(const String& sFile, const String& sFileRoot) override;

    // Inject user html
    virtual void InjectUserHtml(const String& sHtml) override;

    // Inject user html file
    virtual void InjectUserHtmlFile(const String& sFile, const String& sFileRoot) override;

    // Remove all user injected data
    virtual void RemoveAllUserInjectedData() override;

    // Run javascript
    virtual void RunJavascript(const String& sScript) override;

    // Set html content
    virtual void SetHtmlContent(const String& sHtml) override;

    // Set html content file
    virtual void SetHtmlContentFile(const String& sFile, const String& sFileRoot) override;

    // Run main loop iteration
    virtual void RunMainLoopIteration(Bool bBlocking) override;

    // Get javascript result string
    String GetJavascriptResultString(WebKitJavascriptResult* pResult);

    // Main window
    MAKE_PRIMITIVE_TYPE_ACCESSORS(MainWindow, GtkWidget*);

    // Main window
    MAKE_PRIMITIVE_TYPE_ACCESSORS(WebView, GtkWidget*);
};

// Typedefs
MAKE_COMMON_TYPEDEFS(BrowserEngineWebKitGtk);

};

#endif /* PLATFORM_OS_LINUX */

#endif
