// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_WINDOW_BROWSER_ENGINE_H_
#define _GECKO_WINDOW_BROWSER_ENGINE_H_

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

    // Binding types
    typedef STDFunction<String(String)> SynchronousFunction;
    typedef STDFunction<void(String, String, void*)> AsynchronousFunction;

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

    // Preload javascript
    virtual void PreloadJavascript(const String& sScript) = 0;

    // Run javascript
    virtual void RunJavascript(const String& sScript) = 0;

    // Load html content
    virtual void LoadHtmlContent(const String& sHtml) = 0;

    // Run main loop iteration
    virtual void RunMainLoopIteration(Bool bBlocking) = 0;

    // Bind synchronous function
    virtual void BindSynchronousFunction(const String& sName, SynchronousFunction fnFunc) = 0;

    // Bind asynchronous function
    virtual void BindAsynchronousFunction(const String& sName, AsynchronousFunction fnFunc, void* pArg) = 0;

    // Unbind function
    virtual void UnbindFunction(const String& sName) = 0;

    // Unbind all functions
    virtual void UnbindAllFunctions() = 0;

    // Shutting down
    MAKE_RAW_TYPE_ACCESSORS_GET_ONLY(IsShuttingDown, AtomicBool);

    // Bound functions
    MAKE_RAW_TYPE_ACCESSORS_GET_ONLY(BoundFunctions, SafeStringSet);
};

// Typedefs
MAKE_COMMON_TYPEDEFS(BrowserEngine);

};

#endif
