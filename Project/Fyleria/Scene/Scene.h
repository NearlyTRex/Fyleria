// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_SCENE_SCENE_H_
#define _GECKO_SCENE_SCENE_H_

// Internal includes
#include "Window/BrowserEngine.h"
#include "Utility/Types.h"
#include "Utility/Macros.h"
#include "Utility/DebugConsole.h"

namespace Gecko
{

// Scene
class Scene
{
public:

    // Constructor
    Scene(const String& sSceneID);

    // Destructor
    virtual ~Scene();

    // Bind scene functions
    virtual void Bind();

    // Unbind scene functions
    virtual void Unbind();

    // Start scene
    virtual void Start() = 0;

    // Finish scene
    virtual void Finish() = 0;

    // Update scene
    virtual void Update() = 0;

    // Handle scene input
    virtual void Input() = 0;

    // Display scene
    virtual void Display();

protected:

    // Switch to scene
    virtual void SwitchToScene(const String& sSceneID);

    // Shutdown
    virtual void Shutdown();

    // Navigate to url
    virtual void Navigate(const String& sUrl);

    // Preload javascript
    virtual void PreloadJavascript(const String& sScript);

    // Run javascript
    virtual void RunJavascript(const String& sScript);

    // Load html content
    virtual void LoadHtmlContent(const String& sHtml);

    // Bind synchronous function
    virtual void BindSynchronousFunction(const String& sName, const StringArray& vArgs, BrowserEngine::SynchronousFunction fnFunc);

    // Bind asynchronous function
    virtual void BindAsynchronousFunction(const String& sName, const StringArray& vArgs, BrowserEngine::AsynchronousFunction fnFunc, void* pArg);

    // Unbind function
    virtual void UnbindFunction(const String& sName);

    // Unbind all functions
    virtual void UnbindAllFunctions();

protected:

    // Add styles
    void AddStyle(const String& sStyle);
    void AddStyleFile(const String& sFile);

    // Add scripts
    void AddScript(const String& sScript);
    void AddScriptFile(const String& sFile);

    // Add markups
    void AddMarkup(const String& sMarkup);
    void AddMarkupFile(const String& sFile);

    // Set main page content
    void SetMainPageContent();

    // Scene ID
    MAKE_RAW_TYPE_ACCESSORS(SceneID, String);

    // Injectable lists
    MAKE_RAW_TYPE_ACCESSORS(InjectableStyles, String);
    MAKE_RAW_TYPE_ACCESSORS(InjectableScripts, String);
    MAKE_RAW_TYPE_ACCESSORS(InjectableMarkups, String);

    // Main page contents
    MAKE_RAW_TYPE_ACCESSORS(MainPageContents, String);

    // Debug console
#if DEBUG
    MAKE_RAW_TYPE_ACCESSORS(DebugConsole, DebugConsole);
#endif
};

// Typedef
MAKE_COMMON_TYPEDEFS(Scene);

};

#endif
