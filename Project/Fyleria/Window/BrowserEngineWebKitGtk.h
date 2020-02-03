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
    virtual Bool Init(SafeObject<ManagerSet>& pManagerSet, const String& sTitle, Int iWidth, Int iHeight, Bool bResizable) override;

    // Navigate to url
    virtual void Navigate(const String& sUrl) override;

    // Run javascript
    virtual void RunJavascript(const String& sScript) override;

    // Set html content
    virtual void SetHtmlContent(const String& sHtml) override;

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
