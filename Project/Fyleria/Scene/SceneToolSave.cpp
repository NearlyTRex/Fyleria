// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneToolSave.h"
#include "Web/WebPageHandlerSaveTool.h"
#include "Utility/Constants.h"

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
    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneToolSave::OnMessageReceived, this, pManagerSet, STDPlaceholder1));

    // Load page content
    InjectStylesheetFile(LIB_FILE_BOOTSTRAP_CSS);
    InjectJavascriptFile(LIB_FILE_BOOTSTRAP_JS);
    InjectJavascriptFile(LIB_FILE_JQUERY_JS);
    InjectJavascriptFile(LIB_FILE_COMMON_JS);
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
