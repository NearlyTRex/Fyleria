// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_BROWSER_ENGINE_WEBKITCAIRO_H_
#define _GECKO_BROWSER_ENGINE_WEBKITCAIRO_H_

// Windows only
#include "Utility/Platform.h"
#if defined(PLATFORM_OS_WINDOWS)

// External includes
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <WebKit/WKBase.h>
#include <WebKit/WKRetainPtr.h>
#include <WebKit/WebKit2_C.h>
#include <WebKit/WKRetainPtr.h>
#include <WebKit/WKSerializedScriptValue.h>
#include <WebKit/WKString.h>
#include <WebKit/WKURL.h>
#include <JavaScriptCore/JSContextRef.h>
#include <JavaScriptCore/JSStringRef.h>
#include <JavaScriptCore/JavaScript.h>
#include <wtf/Ref.h>
#include <wtf/StdLibExtras.h>
#include <wtf/UniqueArray.h>

// Internal includes
#include "Window/BrowserEngine.h"
#include "Utility/Types.h"

namespace Gecko
{

// WebKitCairo browser engine
class BrowserEngineWebKitCairo : public BrowserEngine
{
public:

    // Constructor
    BrowserEngineWebKitCairo();

    // Destructor
    virtual ~BrowserEngineWebKitCairo();

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
    String GetJavascriptResultString(WKSerializedScriptValueRef pResult);

    // Main window
    MAKE_RAW_TYPE_ACCESSORS(MainWindow, HWND);

    // WebKit view
    MAKE_RAW_TYPE_ACCESSORS(WebKitView, WKRetainPtr<WKViewRef>);

    // WebKit context
    MAKE_RAW_TYPE_ACCESSORS(WebKitContext, WKRetainPtr<WKContextRef>);

    // WebKit preferences
    MAKE_RAW_TYPE_ACCESSORS(WebKitPreferences, WKRetainPtr<WKPreferencesRef>);

    // WebKit page configuration
    MAKE_RAW_TYPE_ACCESSORS(WebKitPageConfiguration, WKRetainPtr<WKPageConfigurationRef>);

    // WebKit page group
    MAKE_RAW_TYPE_ACCESSORS(WebKitPageGroup, WKRetainPtr<WKPageGroupRef>);

    // WebKit page navigation client
    MAKE_RAW_TYPE_ACCESSORS_INITIAL_VALUE(WebKitPageNavigationClient, WKPageNavigationClientV0, {});

    // WebKit page UI client
    MAKE_RAW_TYPE_ACCESSORS_INITIAL_VALUE(WebKitPageUIClient, WKPageUIClientV13, {});

    // WebKit page state client
    MAKE_RAW_TYPE_ACCESSORS_INITIAL_VALUE(WebKitPageStateClient, WKPageStateClientV0, {});
};

// Typedefs
MAKE_COMMON_TYPEDEFS(BrowserEngineWebKitCairo);

};

#endif /* PLATFORM_OS_WINDOWS */

#endif
