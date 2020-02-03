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

void SceneMap::Start(SafeObject<ManagerSet>& pManagerSet)
{
    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneMap::OnMessageReceived, this, pManagerSet, STDPlaceholder1));

    // Page location
    String sLocation = pManagerSet->GetFileManager()->GetDataPagesDirectory();

    // Load page content
    InjectCommonData(pManagerSet);
    InjectStylesheetFile(pManagerSet, PAGE_FILE_MAP_CSS, sLocation);
    InjectJavascriptFile(pManagerSet, PAGE_FILE_MAP_JS, sLocation);
    SetHtmlContentFile(pManagerSet, PAGE_FILE_MAP_HTML, sLocation);

    // Clear page content
    RemoveAllInjectedData();
}

void SceneMap::Finish(SafeObject<ManagerSet>& pManagerSet)
{
    // Clear callbacks
    ClearPostCallback();
}

void SceneMap::Update(SafeObject<ManagerSet>& pManagerSet)
{
}

void SceneMap::Input(SafeObject<ManagerSet>& pManagerSet)
{
}

void SceneMap::OnMessageReceived(SafeObject<ManagerSet>& pManagerSet, const String& sMessage)
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
