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

    // Inject global javascript
    virtual void InjectGlobalJavascript(const String& sScript);

    // Inject local stylesheet
    virtual void InjectLocalStylesheet(const String& sStyle);

    // Inject local stylesheet file
    virtual void InjectLocalStylesheetFile(SafeObject<ManagerSet>& pManagerSet, const String& sFile, const String& sFileRoot);

    // Inject local javascript
    virtual void InjectLocalJavascript(const String& sScript);

    // Inject local javascript file
    virtual void InjectLocalJavascriptFile(SafeObject<ManagerSet>& pManagerSet, const String& sFile, const String& sFileRoot);

    // Inject local html
    virtual void InjectLocalHtml(const String& sHtml);

    // Inject local html file
    virtual void InjectLocalHtmlFile(SafeObject<ManagerSet>& pManagerSet, const String& sFile, const String& sFileRoot);

    // Remove all global injected data
    virtual void RemoveAllGlobalInjectedData();

    // Remove all local injected data
    virtual void RemoveAllLocalInjectedData();

    // Run javascript
    virtual void RunJavascript(const String& sScript) = 0;

    // Load html content
    virtual void LoadHtmlContent(const String& sHtml) = 0;

    // Load html content file
    virtual void LoadHtmlContentFile(SafeObject<ManagerSet>& pManagerSet, const String& sFile, const String& sFileRoot);

    // Run main loop iteration
    virtual void RunMainLoopIteration(Bool bBlocking) = 0;

    // Create inline javascript tag
    virtual String CreateInlineJavascriptTag(const String& sScript);

    // Create file javascript tag
    virtual String CreateFileJavascriptTag(SafeObject<ManagerSet>& pManagerSet, const String& sFile, const String& sFileRoot);

    // Create inline stylesheet tag
    virtual String CreateInlineStylesheetTag(const String& sStyle);

    // Create file stylesheet tag
    virtual String CreateFileStylesheetTag(SafeObject<ManagerSet>& pManagerSet, const String& sFile, const String& sFileRoot);

    // Create loadable html page
    virtual String CreateLoadableHtmlPage(const String& sHtml);

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

    // Global scripts
    MAKE_RAW_TYPE_ACCESSORS_GET_ONLY(GlobalScripts, SafeString);

    // Local styles
    MAKE_RAW_TYPE_ACCESSORS_GET_ONLY(LocalStyles, SafeString);

    // Local scripts
    MAKE_RAW_TYPE_ACCESSORS_GET_ONLY(LocalScripts, SafeString);

    // Local markup
    MAKE_RAW_TYPE_ACCESSORS_GET_ONLY(LocalMarkup, SafeString);

    // Preferences
    MAKE_RAW_TYPE_ACCESSORS_GET_ONLY(Preferences, BrowserEnginePreferences);
};

// Typedefs
MAKE_COMMON_TYPEDEFS(BrowserEngine);

};

#endif
