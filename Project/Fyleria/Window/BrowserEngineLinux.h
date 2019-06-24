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

// Linux browser engine
class BrowserEngineLinux : public BrowserEngine
{
public:

    // Constructor
    BrowserEngineLinux();

    // Destructor
    virtual ~BrowserEngineLinux();

    // Initialize
    virtual Bool Init(const String& sTitle, Int iWidth, Int iHeight, Bool bResizable) override;

    // Shutdown
    virtual void Shutdown() override;

    // Navigate to url
    virtual void Navigate(const String& sUrl) override;

    // Inject javascript
    virtual void InjectJavascript(const String& sScript) override;

    // Run javascript
    virtual void RunJavascript(const String& sScript) override;

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
