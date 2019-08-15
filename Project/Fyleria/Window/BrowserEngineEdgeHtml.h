// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_BROWSER_ENGINE_EDGEHTML_H_
#define _GECKO_BROWSER_ENGINE_EDGEHTML_H_

// EdgeHTML is available for Windows 10 only
#include "Utility/Platform.h"
#if defined(PLATFORM_OS_WINDOWS_10)

// External includes
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <objbase.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Web.UI.Interop.h>

// Internal includes
#include "Window/BrowserEngine.h"
#include "Utility/Types.h"

namespace Gecko
{

// EdgeHtml browser engine
class BrowserEngineEdgeHtml : public BrowserEngine
{
public:

    // Constructor
    BrowserEngineEdgeHtml();

    // Destructor
    virtual ~BrowserEngineEdgeHtml();

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

    // Main window
    MAKE_RAW_TYPE_ACCESSORS(MainWindow, HWND);

    // Web view control
    MAKE_RAW_TYPE_ACCESSORS_INITIAL_VALUE(WebViewControl, winrt::Windows::Web::UI::Interop::WebViewControl, nullptr);

    // Web view control process
    MAKE_RAW_TYPE_ACCESSORS_INITIAL_VALUE(WebViewControlProcess, winrt::Windows::Web::UI::Interop::WebViewControlProcess, nullptr);
};

// Typedefs
MAKE_COMMON_TYPEDEFS(BrowserEngineEdgeHtml);

};

#endif /* PLATFORM_OS_WINDOWS_10 */

#endif
