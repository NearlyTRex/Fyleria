// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneMap.h"
#include "Window/MainWindow.h"
#include "Utility/Constants.h"
#include "Utility/ManagerSet.h"

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
    // Check manager set
    CHECK_MANAGER_SET_PTR(pManagerSet);

    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneMap::OnMessageReceived, this, pManagerSet, STDPlaceholder1));

    // Page location
    String sLocation = pManagerSet->GetFileManager()->GetDataPagesDirectory();

    // Load page content
    InjectCommonData(pManagerSet);
    InjectStylesheetFile(PAGE_FILE_MAP_CSS, sLocation);
    InjectJavascriptFile(PAGE_FILE_MAP_JS, sLocation);
    SetHtmlContentFile(PAGE_FILE_MAP_HTML, sLocation);

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
