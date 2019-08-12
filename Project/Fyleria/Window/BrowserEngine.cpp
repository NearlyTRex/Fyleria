// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Window/BrowserEngine.h"
#include "Scene/SceneTypes.h"
#include "Utility/Filesystem.h"

namespace Gecko
{

BrowserEngine::BrowserEngine()
{
}

BrowserEngine::~BrowserEngine()
{
}

void BrowserEngine::InjectSystemStylesheet(const String& sStyle)
{
    // Inject style
    String sTag = "<style>" + sStyle + "</style>\n";
    SetSystemStyles(GetSystemStyles() + sTag);
}

void BrowserEngine::InjectSystemJavascript(const String& sScript)
{
    // Inject script
    String sTag = "<script type=\"text/javascript\">" + sScript + "</script>\n";
    SetSystemScripts(GetSystemScripts() + sTag);
}

void BrowserEngine::InjectUserStylesheet(const String& sStyle)
{
    // Inject style
    String sTag = "<style>" + sStyle + "</style>\n";
    SetUserStyles(GetUserStyles() + sTag);
}

void BrowserEngine::InjectUserStylesheetFile(const String& sFile)
{
    // Inject style
    String sUri = GetUriPath(JoinPathsCanonical(GetDataDirectory(), sFile));
    String sTag = "<link rel=\"stylesheet\" type=\"text/css\" href='" + sUri + "'>\n";
    SetUserStyles(GetUserStyles() + sTag);
}

void BrowserEngine::InjectUserJavascript(const String& sScript)
{
    // Inject script
    String sTag = "<script type=\"text/javascript\">" + sScript + "</script>\n";
    SetUserScripts(GetUserScripts() + sTag);
}

void BrowserEngine::InjectUserJavascriptFile(const String& sFile)
{
    // Inject script
    String sUri = GetUriPath(JoinPathsCanonical(GetDataDirectory(), sFile));
    String sTag = "<script type=\"text/javascript\" src=\"" + sUri + "\"></script>\n";
    SetUserScripts(GetUserScripts() + sTag);
}

void BrowserEngine::RemoveAllUserInjectedData()
{
    // Clear injected styles and scripts
    GetUserStyles().clear();
    GetUserScripts().clear();
}

void BrowserEngine::DefineJavascriptShortcut(const String& sFunction, const String& sArgs)
{
    // Keys
    const String sFunctionKey = (+SceneMessageKeyType::Function)._to_string();
    const String sArgsKey = (+SceneMessageKeyType::Args)._to_string();

    // Define shortcut
    String sShortcut = sFunction + "=function(" + sArgs + "){";
    sShortcut += "var p={" + sFunctionKey + ":\"" + sFunction + "\",";
    sShortcut += sArgsKey + ":[" + sArgs + "]};";
    sShortcut += "window.external.invoke(JSON.stringify(p));";
    sShortcut += "};";

    // Register shortcut
    RunJavascript(sShortcut);
}

void BrowserEngine::ClearJavascriptShortcut(const String& sFunction)
{
    // Clear shortcut
    RunJavascript("delete " + sFunction + ";");
}

};
