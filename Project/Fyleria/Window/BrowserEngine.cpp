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

void BrowserEngine::InjectGlobalJavascript(const String& sScript)
{
    // Inject script
    GetGlobalScripts()->append(CreateInlineJavascriptTag(sScript));
}

void BrowserEngine::InjectLocalStylesheet(const String& sStyle)
{
    // Inject style
    GetLocalStyles()->append(CreateInlineStylesheetTag(sStyle));
}

void BrowserEngine::InjectLocalStylesheetFile(SafeObject<ManagerSet>& pManagerSet, const String& sFile, const String& sFileRoot)
{
    // Inject style
    GetLocalStyles()->append(CreateFileStylesheetTag(pManagerSet, sFile, sFileRoot));
}

void BrowserEngine::InjectLocalJavascript(const String& sScript)
{
    // Inject script
    GetLocalScripts()->append(CreateInlineJavascriptTag(sScript));
}

void BrowserEngine::InjectLocalJavascriptFile(SafeObject<ManagerSet>& pManagerSet, const String& sFile, const String& sFileRoot)
{
    // Inject script
    GetLocalScripts()->append(CreateFileJavascriptTag(pManagerSet, sFile, sFileRoot));
}

void BrowserEngine::InjectLocalHtml(const String& sHtml)
{
    // Inject html
    GetLocalMarkup()->append(sHtml);
}

void BrowserEngine::InjectLocalHtmlFile(SafeObject<ManagerSet>& pManagerSet, const String& sFile, const String& sFileRoot)
{
    // Inject html
    String sFileContents;
    if (pManagerSet->GetFileManager()->ReadFileToString(sFile, sFileContents, sFileRoot))
    {
        InjectLocalHtml(sFileContents);
    }
}

void BrowserEngine::RemoveAllGlobalInjectedData()
{
    // Remove all injected data
    GetGlobalScripts()->clear();
}

void BrowserEngine::RemoveAllLocalInjectedData()
{
    // Remove all injected data
    GetLocalStyles()->clear();
    GetLocalScripts()->clear();
    GetLocalMarkup()->clear();
}

void BrowserEngine::LoadHtmlContentFile(SafeObject<ManagerSet>& pManagerSet, const String& sFile, const String& sFileRoot)
{
    // Load document html
    String sFileContents;
    if (pManagerSet->GetFileManager()->ReadFileToString(sFile, sFileContents, sFileRoot))
    {
        LoadHtmlContent(sFileContents);
    }
}

String BrowserEngine::CreateInlineJavascriptTag(const String& sScript)
{
    // Create tag
    String sTag = "<script type=\"text/javascript\">" + sScript + "</script>\n";
    return sTag;
}

String BrowserEngine::CreateFileJavascriptTag(SafeObject<ManagerSet>& pManagerSet, const String& sFile, const String& sFileRoot)
{
    // Create tag
    String sUri = pManagerSet->GetFileManager()->GetUriPath(sFile, sFileRoot);
    String sTag = "<script type=\"text/javascript\" src=\"" + sUri + "\"></script>\n";
    return sTag;
}

String BrowserEngine::CreateInlineStylesheetTag(const String& sStyle)
{
    // Create tag
    String sTag = "<style>" + sStyle + "</style>\n";
    return sTag;
}

String BrowserEngine::CreateFileStylesheetTag(SafeObject<ManagerSet>& pManagerSet, const String& sFile, const String& sFileRoot)
{
    // Create tag
    String sUri = pManagerSet->GetFileManager()->GetUriPath(sFile, sFileRoot);
    String sTag = "<link rel=\"stylesheet\" type=\"text/css\" href='" + sUri + "'>\n";
    return sTag;
}

String BrowserEngine::CreateLoadableHtmlPage(const String& sHtml)
{
    // Create page
    String sHtmlPage(sHtml);
    BoostReplaceAll(sHtmlPage, INJECTED_STYLES_TOKEN, String(GetLocalStyles()->c_str()));
    BoostReplaceAll(sHtmlPage, INJECTED_SCRIPTS_TOKEN, String(GetGlobalScripts()->c_str()) + String(GetLocalScripts()->c_str()));
    BoostReplaceAll(sHtmlPage, INJECTED_MARKUP_TOKEN, String(GetLocalMarkup()->c_str()));
    return sHtmlPage;
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
