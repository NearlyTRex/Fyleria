// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Window/BrowserEngineWebKitCairo.h"
#include "Scene/SceneTypes.h"
#include "Utility/Constants.h"
#include "Utility/ManagerSet.h"

// Windows only
#if defined(PLATFORM_OS_WINDOWS)

namespace Gecko
{

BrowserEngineWebKitCairo::BrowserEngineWebKitCairo()
{
}

BrowserEngineWebKitCairo::~BrowserEngineWebKitCairo()
{
}

Bool BrowserEngineWebKitCairo::Init(ManagerSet* pManagerSet, const String& sTitle, Int iWidth, Int iHeight, Bool bResizable)
{
    return true;
}

void BrowserEngineWebKitCairo::Shutdown()
{
}

void BrowserEngineWebKitCairo::Navigate(const String& sUrl)
{
}

void BrowserEngineWebKitCairo::InjectSystemJavascript(const String& sScript)
{
}

void BrowserEngineWebKitCairo::InjectUserStylesheet(const String& sStyle)
{
}

void BrowserEngineWebKitCairo::InjectUserStylesheetFile(const String& sFile, const String& sFileRoot)
{
}

void BrowserEngineWebKitCairo::InjectUserJavascript(const String& sScript)
{
}

void BrowserEngineWebKitCairo::InjectUserJavascriptFile(const String& sFile, const String& sFileRoot)
{
}

void BrowserEngineWebKitCairo::InjectUserHtml(const String& sHtml)
{
}

void BrowserEngineWebKitCairo::InjectUserHtmlFile(const String& sFile, const String& sFileRoot)
{
}

void BrowserEngineWebKitCairo::RemoveAllUserInjectedData()
{
}

void BrowserEngineWebKitCairo::RunJavascript(const String& sScript)
{
}

void BrowserEngineWebKitCairo::SetHtmlContent(const String& sHtml)
{
}

void BrowserEngineWebKitCairo::SetHtmlContentFile(const String& sFile, const String& sFileRoot)
{
}

void BrowserEngineWebKitCairo::RunMainLoopIteration(Bool bBlocking)
{
}

};

#endif /* PLATFORM_OS_WINDOWS */
