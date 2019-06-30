// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Window/BrowserEngine.h"
#include "Scene/SceneTypes.h"

namespace Gecko
{

BrowserEngine::BrowserEngine()
{
}

BrowserEngine::~BrowserEngine()
{
}

String BrowserEngine::GetCommonJavascriptShortcuts()
{
    // Keys
    const String sFunctionKey = (+SceneMessageKeyType::Function)._to_string();
    const String sArgsKey = (+SceneMessageKeyType::Args)._to_string();

    // Functions
    const String sSwitchToSceneFunction = (+SceneMessageFunctionType::SwitchToScene)._to_string();
    const String sProcessFormFunction = (+SceneMessageFunctionType::ProcessForm)._to_string();
    const String sReloadPageFunction = (+SceneMessageFunctionType::ReloadPage)._to_string();

    // Switch to scene shortcut
    String sSwitchToSceneShortcut = "window.";
    sSwitchToSceneShortcut += sSwitchToSceneFunction;
    sSwitchToSceneShortcut += "=function(scene){";
    sSwitchToSceneShortcut += "var p = {";
    sSwitchToSceneShortcut += sFunctionKey;
    sSwitchToSceneShortcut += ":\"";
    sSwitchToSceneShortcut += sSwitchToSceneFunction;
    sSwitchToSceneShortcut += "\",";
    sSwitchToSceneShortcut += sArgsKey;
    sSwitchToSceneShortcut += ":[scene]};";
    sSwitchToSceneShortcut += "window.external.invoke(JSON.stringify(p));";
    sSwitchToSceneShortcut += "};";

    // Combine shortcuts
    String sCombinedShortcuts = sSwitchToSceneShortcut;
    return sCombinedShortcuts;
}

};
