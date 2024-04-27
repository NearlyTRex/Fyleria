// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_WINDOW_BROWSER_ENGINE_WEBVIEW_H_
#define _GECKO_WINDOW_BROWSER_ENGINE_WEBVIEW_H_

// Internal includes
#include "Window/BrowserEngine.h"
#include "Utility/Types.h"

namespace Gecko
{

// WebView browser engine
class BrowserEngineWebView : public BrowserEngine
{
public:

    // Constructor
    BrowserEngineWebView();

    // Destructor
    virtual ~BrowserEngineWebView();

    // Initialize
    virtual Bool Init(const String& sTitle, Int iWidth, Int iHeight, Bool bResizable) override;

    // Shutdown
    virtual void Shutdown() override;

    // Navigate to url
    virtual void Navigate(const String& sUrl) override;

    // Preload javascript
    virtual void PreloadJavascript(const String& sScript) override;

    // Run javascript
    virtual void RunJavascript(const String& sScript) override;

    // Load html content
    virtual void LoadHtmlContent(const String& sHtml) override;

    // Run main loop iteration
    virtual void RunMainLoopIteration(Bool bBlocking) override;

    // Bind synchronous function
    virtual void BindSynchronousFunction(const String& sName, SynchronousFunction fnFunc) override;

    // Bind asynchronous function
    virtual void BindAsynchronousFunction(const String& sName, AsynchronousFunction fnFunc, void* pArg) override;

    // Unbind function
    virtual void UnbindFunction(const String& sName) override;

    // Unbind all functions
    virtual void UnbindAllFunctions() override;

    // Web view
    MAKE_PRIMITIVE_TYPE_ACCESSORS(WebView, STDSharedPtr<void>);
};

// Typedefs
MAKE_COMMON_TYPEDEFS(BrowserEngineWebView);

};

#endif
