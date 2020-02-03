// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneToolParty.h"
#include "Web/WebPageHandlerPartyTool.h"
#include "Utility/Constants.h"
#include "Utility/ManagerSet.h"

namespace Gecko
{

SceneToolParty::SceneToolParty(SafeObject<ManagerSet>& pManagerSet)
    : Scene()
{
    // Create handler
    SetPageHandler(STDMakeSharedPtr<WebPageHandlerPartyTool>(pManagerSet));
}

SceneToolParty::~SceneToolParty()
{
}

void SceneToolParty::Start(SafeObject<ManagerSet>& pManagerSet)
{
    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneToolParty::OnMessageReceived, this, pManagerSet, STDPlaceholder1));

    // Page location
    String sLocation = pManagerSet->GetFileManager()->GetDataPagesDirectory();

    // Load page content
    InjectCommonData(pManagerSet);
    InjectStylesheetFile(pManagerSet, PAGE_FILE_TOOL_PARTY_CSS, sLocation);
    InjectJavascriptFile(pManagerSet, PAGE_FILE_TOOL_PARTY_JS, sLocation);
    LoadHtmlFromHandler(GetPageHandler());
}

void SceneToolParty::Finish(SafeObject<ManagerSet>& pManagerSet)
{
    // Clear callbacks
    ClearPostCallback();

    // Clear page content
    RemoveAllInjectedData();
}

void SceneToolParty::Update(SafeObject<ManagerSet>& pManagerSet)
{
}

void SceneToolParty::Input(SafeObject<ManagerSet>& pManagerSet)
{
}

void SceneToolParty::OnMessageReceived(SafeObject<ManagerSet>& pManagerSet, const String& sMessage)
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
