// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Window/BrowserEngine.h"
#include "Scene/SceneTypes.h"
#include "Utility/ManagerSet.h"

namespace Gecko
{

BrowserEngine::BrowserEngine()
{
}

BrowserEngine::~BrowserEngine()
{
}

void BrowserEngine::Shutdown()
{
    // Mark as shutting down
    GetIsShuttingDown() = true;
}

void BrowserEngine::InjectSystemJavascript(const String& sScript)
{
    // Inject script
    String sTag = "<script type=\"text/javascript\">" + sScript + "</script>\n";
    GetSystemScripts()->append(sTag);
}

void BrowserEngine::InjectUserStylesheet(const String& sStyle)
{
    // Inject style
    String sTag = "<style>" + sStyle + "</style>\n";
    GetUserStyles()->append(sTag);
}

void BrowserEngine::InjectUserStylesheetFile(SafeManagerSet& pManagerSet, const String& sFile, const String& sFileRoot)
{
    // Inject style
    String sUri = pManagerSet->GetFileManager()->GetUriPath(sFile, sFileRoot);
    String sTag = "<link rel=\"stylesheet\" type=\"text/css\" href='" + sUri + "'>\n";
    GetUserStyles()->append(sTag);
}

void BrowserEngine::InjectUserJavascript(const String& sScript)
{
    // Inject script
    String sTag = "<script type=\"text/javascript\">" + sScript + "</script>\n";
    GetUserScripts()->append(sTag);
}

void BrowserEngine::InjectUserJavascriptFile(SafeObject<ManagerSet>& pManagerSet, const String& sFile, const String& sFileRoot)
{
    // Inject script
    String sUri = pManagerSet->GetFileManager()->GetUriPath(sFile, sFileRoot);
    String sTag = "<script type=\"text/javascript\" src=\"" + sUri + "\"></script>\n";
    GetUserScripts()->append(sTag);
}

void BrowserEngine::InjectUserHtml(const String& sHtml)
{
    // Inject html
    GetUserMarkup()->append(sHtml);
}

void BrowserEngine::InjectUserHtmlFile(SafeObject<ManagerSet>& pManagerSet, const String& sFile, const String& sFileRoot)
{
    // Inject html
    String sFileContents;
    if (pManagerSet->GetFileManager()->ReadFileToString(sFile, sFileContents, sFileRoot))
    {
        InjectUserHtml(sFileContents);
    }
}

void BrowserEngine::RemoveAllSystemInjectedData()
{
    // Remove all injected data
    GetSystemScripts()->clear();
}

void BrowserEngine::RemoveAllUserInjectedData()
{
    // Remove all injected data
    GetUserStyles()->clear();
    GetUserScripts()->clear();
    GetUserMarkup()->clear();
}

void BrowserEngine::SetHtmlContentFile(SafeObject<ManagerSet>& pManagerSet, const String& sFile, const String& sFileRoot)
{
    // Set document html
    String sFileContents;
    if (pManagerSet->GetFileManager()->ReadFileToString(sFile, sFileContents, sFileRoot))
    {
        SetHtmlContent(sFileContents);
    }
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
