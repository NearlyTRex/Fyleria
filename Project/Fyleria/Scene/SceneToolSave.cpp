// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneToolSave.h"
#include "Web/WebPageHandlerSaveTool.h"
#include "Utility/Constants.h"
#include "Utility/ManagerSet.h"

namespace Gecko
{

SceneToolSave::SceneToolSave(SafeObject<ManagerSet>& pManagerSet)
    : Scene()
{
    // Create handler
    SetPageHandler(STDMakeSharedPtr<WebPageHandlerSaveTool>(pManagerSet));
}

SceneToolSave::~SceneToolSave()
{
}

void SceneToolSave::Start(SafeObject<ManagerSet>& pManagerSet)
{
    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneToolSave::OnMessageReceived, this, pManagerSet, STDPlaceholder1));

    // Page location
    String sLocation = pManagerSet->GetFileManager()->GetDataPagesDirectory();

    // Load page content
    InjectCommonData(pManagerSet);
    InjectStylesheetFile(pManagerSet, PAGE_FILE_TOOL_SAVE_CSS, sLocation);
    InjectJavascriptFile(pManagerSet, PAGE_FILE_TOOL_SAVE_JS, sLocation);
    LoadHtmlFromHandler(GetPageHandler());
}

void SceneToolSave::Finish(SafeObject<ManagerSet>& pManagerSet)
{
    // Clear callbacks
    ClearPostCallback();

    // Clear page content
    RemoveAllInjectedData();
}

void SceneToolSave::Update(SafeObject<ManagerSet>& pManagerSet)
{
}

void SceneToolSave::Input(SafeObject<ManagerSet>& pManagerSet)
{
}

void SceneToolSave::OnMessageReceived(SafeObject<ManagerSet>& pManagerSet, const String& sMessage)
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
