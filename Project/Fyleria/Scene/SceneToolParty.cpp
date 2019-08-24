// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneToolParty.h"
#include "Web/WebPageHandlerPartyTool.h"
#include "Utility/Constants.h"
#include "Utility/ManagerSet.h"

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
    // Check manager set
    CHECK_MANAGER_SET_PTR(pManagerSet);

    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneToolParty::OnMessageReceived, this, pManagerSet, STDPlaceholder1));

    // Page location
    String sLocation = pManagerSet->GetFileManager()->GetDataPagesDirectory();

    // Load page content
    InjectCommonData(pManagerSet);
    InjectStylesheetFile(PAGE_FILE_TOOL_PARTY_CSS, sLocation);
    InjectJavascriptFile(PAGE_FILE_TOOL_PARTY_JS, sLocation);
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
