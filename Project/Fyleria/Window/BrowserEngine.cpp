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
    String sSwitchToSceneShortcut = "(function(){window." + sSwitchToSceneFunction + "=function(s){";
    sSwitchToSceneShortcut += "var p={" + sFunctionKey + ":\"" + sSwitchToSceneFunction + "\",";
    sSwitchToSceneShortcut += sArgsKey + ":[s]};";
    sSwitchToSceneShortcut += "window.external.invoke(JSON.stringify(p));";
    sSwitchToSceneShortcut += "};})();";

    // Process form shortcut
    String sProcessFormShortcut = "(function(){window." + sProcessFormFunction + "=function(s){";
    sProcessFormShortcut += "var p={" + sFunctionKey + ":\"" + sProcessFormFunction + "\",";
    sProcessFormShortcut += sArgsKey + ":[s]};";
    sProcessFormShortcut += "window.external.invoke(JSON.stringify(p));";
    sProcessFormShortcut += "};})();";

    // Reload page shortcut
    String sReloadPageShortcut = "(function(){window." + sReloadPageFunction + "=function(){";
    sReloadPageShortcut += "var p={" + sFunctionKey + ":\"" + sReloadPageFunction + "\",";
    sReloadPageShortcut += sArgsKey + ":[]};";
    sReloadPageShortcut += "window.external.invoke(JSON.stringify(p));";
    sReloadPageShortcut += "};})();";

    // Combine shortcuts
    String sCombinedShortcuts;
    sCombinedShortcuts += sSwitchToSceneShortcut;
    sCombinedShortcuts += sProcessFormShortcut;
    sCombinedShortcuts += sReloadPageShortcut;
    return sCombinedShortcuts;
}

};
