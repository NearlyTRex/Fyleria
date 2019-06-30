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
    const String sSubmitFormFunction = (+SceneMessageFunctionType::SubmitForm)._to_string();
    const String sReloadPageFunction = (+SceneMessageFunctionType::ReloadPage)._to_string();

    // Switch to scene shortcut
    String sSwitchToSceneShortcut = "(function(){window." + sSwitchToSceneFunction + "=function(s){";
    sSwitchToSceneShortcut += "var p={" + sFunctionKey + ":\"" + sSwitchToSceneFunction + "\",";
    sSwitchToSceneShortcut += sArgsKey + ":[s]};";
    sSwitchToSceneShortcut += "window.external.invoke(JSON.stringify(p));";
    sSwitchToSceneShortcut += "};})();";

    // Submit form shortcut
    String sSubmitFormShortcut = "(function(){window." + sSubmitFormFunction + "=function(s){";
    sSubmitFormShortcut += "var p={" + sFunctionKey + ":\"" + sSubmitFormFunction + "\",";
    sSubmitFormShortcut += sArgsKey + ":[s]};";
    sSubmitFormShortcut += "window.external.invoke(JSON.stringify(p));";
    sSubmitFormShortcut += "};})();";

    // Reload page shortcut
    String sReloadPageShortcut = "(function(){window." + sReloadPageFunction + "=function(){";
    sReloadPageShortcut += "var p={" + sFunctionKey + ":\"" + sReloadPageFunction + "\",";
    sReloadPageShortcut += sArgsKey + ":[]};";
    sReloadPageShortcut += "window.external.invoke(JSON.stringify(p));";
    sReloadPageShortcut += "};})();";

    // Combine shortcuts
    String sCombinedShortcuts;
    sCombinedShortcuts += sSwitchToSceneShortcut;
    sCombinedShortcuts += sSubmitFormShortcut;
    sCombinedShortcuts += sReloadPageShortcut;
    return sCombinedShortcuts;
}

};
