// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneToolSave.h"
#include "Web/WebPageHandlerSaveTool.h"
#include "Utility/Constants.h"
#include "Utility/ManagerSet.h"

namespace Gecko
{

SceneToolSave::SceneToolSave(ManagerSet* pManagerSet)
    : Scene()
{
    // Create handler
    SetPageHandler(STDMakeSharedPtr<WebPageHandlerSaveTool>(pManagerSet));
}

SceneToolSave::~SceneToolSave()
{
}

void SceneToolSave::Start(ManagerSet* pManagerSet)
{
    // Check manager set
    CHECK_MANAGER_SET_PTR(pManagerSet);

    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneToolSave::OnMessageReceived, this, pManagerSet, STDPlaceholder1));

    // Page location
    String sLocation = pManagerSet->GetFileManager().GetDataPagesDirectory();

    // Load page content
    InjectCommonData(pManagerSet);
    InjectStylesheetFile(PAGE_FILE_TOOL_SAVE_CSS, sLocation);
    InjectJavascriptFile(PAGE_FILE_TOOL_SAVE_JS, sLocation);
    LoadHtmlFromHandler(GetPageHandler());
}

void SceneToolSave::Finish(ManagerSet* pManagerSet)
{
    // Clear callbacks
    ClearPostCallback();

    // Clear page content
    RemoveAllInjectedData();
}

void SceneToolSave::Update(ManagerSet* pManagerSet)
{
}

void SceneToolSave::Input(ManagerSet* pManagerSet)
{
}

void SceneToolSave::OnMessageReceived(ManagerSet* pManagerSet, const String& sMessage)
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
