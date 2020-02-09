// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_BROWSER_ENGINE_H_
#define _GECKO_BROWSER_ENGINE_H_

// Internal includes
#include "Window/BrowserEnginePreferences.h"
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

    // Callback wrapper
    class JavascriptCallbackWrapper
    {
    public:

        // Callback
        JavascriptCallback GetCallback() { return m_Callback; }
        void SetCallback(JavascriptCallback callback) { m_Callback = callback; }

        // Get whether it was set
        Bool IsSet() const { return (m_Callback != nullptr); }

    private:

        // Callback
        JavascriptCallback m_Callback = nullptr;
    };

    // Constructor
    BrowserEngine();

    // Destructor
    virtual ~BrowserEngine();

    // Initialize
    virtual Bool Init(SafeObject<ManagerSet>& pManagerSet, const String& sTitle, Int iWidth, Int iHeight, Bool bResizable) = 0;

    // Shutdown
    virtual void Shutdown();

    // Navigate to url
    virtual void Navigate(const String& sUrl) = 0;

    // Inject system javascript
    virtual void InjectSystemJavascript(const String& sScript);

    // Inject user stylesheet
    virtual void InjectUserStylesheet(const String& sStyle);

    // Inject user stylesheet file
    virtual void InjectUserStylesheetFile(SafeObject<ManagerSet>& pManagerSet, const String& sFile, const String& sFileRoot);

    // Inject user javascript
    virtual void InjectUserJavascript(const String& sScript);

    // Inject user javascript file
    virtual void InjectUserJavascriptFile(SafeObject<ManagerSet>& pManagerSet, const String& sFile, const String& sFileRoot);

    // Inject user html
    virtual void InjectUserHtml(const String& sHtml);

    // Inject user html file
    virtual void InjectUserHtmlFile(SafeObject<ManagerSet>& pManagerSet, const String& sFile, const String& sFileRoot);

    // Remove all system injected data
    virtual void RemoveAllSystemInjectedData();

    // Remove all user injected data
    virtual void RemoveAllUserInjectedData();

    // Run javascript
    virtual void RunJavascript(const String& sScript) = 0;

    // Set html content
    virtual void SetHtmlContent(const String& sHtml) = 0;

    // Set html content file
    virtual void SetHtmlContentFile(SafeObject<ManagerSet>& pManagerSet, const String& sFile, const String& sFileRoot);

    // Run main loop iteration
    virtual void RunMainLoopIteration(Bool bBlocking) = 0;

    // Define javascript shortcut
    virtual void DefineJavascriptShortcut(const String& sFunction, const String& sArgs);

    // Clear javascript shortcut
    virtual void ClearJavascriptShortcut(const String& sFunction);

    // Shutting down
    MAKE_RAW_TYPE_ACCESSORS_GET_ONLY(IsShuttingDown, AtomicBool);

    // Post (Javascript -> C++) callback
    MAKE_RAW_TYPE_ACCESSORS_GET_ONLY(PostJavascriptCallback, SafeObject<JavascriptCallbackWrapper>);

    // Run result (C++ -> Javascript) callback
    MAKE_RAW_TYPE_ACCESSORS_GET_ONLY(RunResultJavascriptCallback, SafeObject<JavascriptCallbackWrapper>);

    // System scripts
    MAKE_RAW_TYPE_ACCESSORS_GET_ONLY(SystemScripts, SafeString);

    // User styles
    MAKE_RAW_TYPE_ACCESSORS_GET_ONLY(UserStyles, SafeString);

    // User scripts
    MAKE_RAW_TYPE_ACCESSORS_GET_ONLY(UserScripts, SafeString);

    // User markup
    MAKE_RAW_TYPE_ACCESSORS_GET_ONLY(UserMarkup, SafeString);

    // Preferences
    MAKE_RAW_TYPE_ACCESSORS_GET_ONLY(Preferences, BrowserEnginePreferences);
};

// Typedefs
MAKE_COMMON_TYPEDEFS(BrowserEngine);

};

#endif
