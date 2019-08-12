// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneToolParty.h"
#include "Web/WebPageHandlerPartyTool.h"
#include "Utility/Constants.h"

namespace Gecko
{

SceneToolParty::SceneToolParty(ManagerSet* pManagerSet)
    : Scene()
{
    // Create handler
    SetPageHandler(STDMakeSharedPtr<WebPageHandlerPartyTool>(pManagerSet));
}

SceneToolParty::~SceneToolParty()
{
}

void SceneToolParty::Start(ManagerSet* pManagerSet)
{
    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneToolParty::OnMessageReceived, this, pManagerSet, STDPlaceholder1));

    // Load page content
    InjectStylesheetFile(LIB_FILE_BOOTSTRAP_CSS);
    InjectJavascriptFile(LIB_FILE_BOOTSTRAP_JS);
    InjectJavascriptFile(LIB_FILE_JQUERY_JS);
    InjectJavascriptFile(LIB_FILE_COMMON_JS);
    LoadHtmlFromHandler(GetPageHandler());
}

void SceneToolParty::Finish(ManagerSet* pManagerSet)
{
    // Clear callbacks
    ClearPostCallback();

    // Clear page content
    RemoveAllInjectedData();
}

void SceneToolParty::Update(ManagerSet* pManagerSet)
{
}

void SceneToolParty::Input(ManagerSet* pManagerSet)
{
}

void SceneToolParty::OnMessageReceived(ManagerSet* pManagerSet, const String& sMessage)
{
    // Function / arguments
    String sFunction;
    StringArray vArgs;

    // Handle common messages
    if(Scene::HandleMessage(pManagerSet, sMessage, sFunction, vArgs))
    {
        return;
    }
}

};
