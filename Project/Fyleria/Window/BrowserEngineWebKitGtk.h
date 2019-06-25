// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_BROWSER_LINUX_H_
#define _GECKO_BROWSER_LINUX_H_

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
    virtual Bool Init(const String& sTitle, Int iWidth, Int iHeight, Bool bResizable) override;

    // Shutdown
    virtual void Shutdown() override;

    // Navigate to url
    virtual void Navigate(const String& sUrl) override;

    // Inject stylesheet
    virtual void InjectStylesheet(const String& sStyle) override;

    // Inject stylesheet file
    virtual void InjectStylesheetFile(const String& sFile) override;

    // Remove all injected stylesheets
    virtual void RemoveAllInjectedStylesheets() override;

    // Inject javascript
    virtual void InjectJavascript(const String& sScript) override;

    // Inject javascript file
    virtual void InjectJavascriptFile(const String& sFile) override;

    // Remove all injected javascript
    virtual void RemoveAllInjectedJavascript() override;

    // Run javascript
    virtual void RunJavascript(const String& sScript) override;

    // Set html content
    virtual void SetHtmlContent(const String& sHtml) override;

    // Run main loop iteration
    virtual void RunMainLoopIteration(Bool bBlocking) override;

    // Get javascript result string
    String GetJavascriptResultString(WebKitJavascriptResult* pResult);

private:

    // Window
    GtkWidget* m_pWindow;

    // Web view
    GtkWidget* m_pWebview;
};

};

#endif
