// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_MAIN_WINDOW_H_
#define _GECKO_MAIN_WINDOW_H_

// Internal includes
#include "Window/BrowserEngine.h"
#include "Utility/Types.h"
#include "Utility/Singleton.h"

namespace Gecko
{

// Main window class
class MainWindow : public Singleton<MainWindow>
{
public:

    // Constructor
    MainWindow();

    // Destructor
    virtual ~MainWindow();

    // Initializes the window
    Bool Init(const String& sTitle, Int iWidth, Int iHeight, Bool bResizable);

    // Shutdown the window
    void Shutdown();

    // Determine if shutting down
    Bool IsShuttingDown() const;

    // Navigate to url
    void Navigate(const String& sUrl);

    // Inject javascript
    void InjectJavascript(const String& sScript);

    // Run javascript
    void RunJavascript(const String& sScript);

    // Run main loop iteration
    void RunMainLoopIteration(Bool bBlocking);
    
    // Set post callback
    void SetPostCallback(const BrowserEngine::JavascriptCallback& fnCallback);

    // Set run result callback
    void SetRunResultCallback(const BrowserEngine::JavascriptCallback& fnCallback);

    // Browser engine
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(BrowserEngine, STDSharedPtr<BrowserEngine>);
};

};

#endif
