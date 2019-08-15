// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneMap.h"
#include "Window/MainWindow.h"
#include "Utility/Constants.h"

namespace Gecko
{

SceneMap::SceneMap()
    : Scene()
{
}

SceneMap::~SceneMap()
{
}

void SceneMap::Start(ManagerSet* pManagerSet)
{
    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneMap::OnMessageReceived, this, pManagerSet, STDPlaceholder1));

    // Load page content
    InjectCommonData();
    InjectStylesheetFile(PAGE_FILE_MAP_CSS, GetDataPagesDirectory());
    InjectJavascriptFile(PAGE_FILE_MAP_JS, GetDataPagesDirectory());
    SetHtmlContentFile(PAGE_FILE_MAP_HTML, GetDataPagesDirectory());

    // Clear page content
    RemoveAllInjectedData();
}

void SceneMap::Finish(ManagerSet* pManagerSet)
{
    // Clear callbacks
    ClearPostCallback();
}

void SceneMap::Update(ManagerSet* pManagerSet)
{
}

void SceneMap::Input(ManagerSet* pManagerSet)
{
}

void SceneMap::OnMessageReceived(ManagerSet* pManagerSet, const String& sMessage)
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
