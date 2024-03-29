// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_SCENE_H_
#define _GECKO_SCENE_H_

// Internal includes
#include "Window/BrowserEngine.h"
#include "Web/WebPageHandler.h"
#include "Utility/Types.h"
#include "Utility/Macros.h"

namespace Gecko
{

// Manager set
class ManagerSet;

// Scene
class Scene
{
public:

    // Constructor
    Scene();

    // Destructor
    virtual ~Scene();

    // Start scene
    virtual void Start(SafeObject<ManagerSet>& pManagerSet) = 0;

    // Finish scene
    virtual void Finish(SafeObject<ManagerSet>& pManagerSet) = 0;

    // Update scene
    virtual void Update(SafeObject<ManagerSet>& pManagerSet) = 0;

    // Handle scene input
    virtual void Input(SafeObject<ManagerSet>& pManagerSet) = 0;

protected:

    // Handle message received
    virtual void OnMessageReceived(SafeObject<ManagerSet>& pManagerSet, const String& sMessage) = 0;

    // Parse message and get the function and arguments
    virtual Bool ParseMessage(SafeObject<ManagerSet>& pManagerSet, const String& sMessage, String& sFunction, StringArray& vArgs);

    // Handle message or return false if it could not be handled
    virtual Bool HandleMessage(SafeObject<ManagerSet>& pManagerSet, const String& sMessage, String& sFunction, StringArray& vArgs);

    // Process form
    virtual Bool ProcessForm(SafeObject<ManagerSet>& pManagerSet, const String& sAction, const String& sParameters, String& sProcessedPage);

    // Load html from handler
    virtual void LoadHtmlFromHandler(const WebPageHandlerSharedPtr& pHandler);

    // Inject stylesheet file
    virtual void InjectStylesheetFile(SafeObject<ManagerSet>& pManagerSet, const String& sFile, const String& sFileRoot);

    // Inject javascript file
    virtual void InjectJavascriptFile(SafeObject<ManagerSet>& pManagerSet, const String& sFile, const String& sFileRoot);

    // Inject html file
    virtual void InjectHtmlFile(SafeObject<ManagerSet>& pManagerSet, const String& sFile, const String& sFileRoot);

    // Inject common data
    virtual void InjectCommonData(SafeObject<ManagerSet>& pManagerSet);

    // Remove all injected data
    virtual void RemoveAllInjectedData();

    // Run javascript
    virtual void RunJavascript(const String& sScript);

    // Load html content
    virtual void LoadHtmlContent(const String& sHtml);

    // Load html content file
    virtual void LoadHtmlContentFile(SafeObject<ManagerSet>& pManagerSet, const String& sFile, const String& sFileRoot);

    // Define javascript shortcut
    virtual void DefineJavascriptShortcut(const String& sFunction, const String& sArgs);

    // Clear javascript shortcut
    virtual void ClearJavascriptShortcut(const String& sFunction);

    // Set callbacks
    virtual void SetPostCallback(const BrowserEngine::JavascriptCallback& fnCallback);
    virtual void SetRunResultCallback(const BrowserEngine::JavascriptCallback& fnCallback);

    // Clear callbacks
    virtual void ClearPostCallback();
    virtual void ClearRunResultCallback();

    // Page handler
    MAKE_RAW_TYPE_ACCESSORS(PageHandler, WebPageHandlerSharedPtr);
};

// Typedef
MAKE_COMMON_TYPEDEFS(Scene);

};

#endif
