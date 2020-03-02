// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneIntro.h"
#include "Window/MainWindow.h"
#include "Utility/Constants.h"
#include "Utility/ManagerSet.h"

namespace Gecko
{

SceneStart::SceneStart()
    : Scene()
{
}

SceneStart::~SceneStart()
{
}

void SceneStart::Start(SafeObject<ManagerSet>& pManagerSet)
{
    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneStart::OnMessageReceived, this, pManagerSet, STDPlaceholder1));

    // Page location
    String sLocation = pManagerSet->GetFileManager()->GetDataPagesDirectory();

    // Load page content
    InjectCommonData(pManagerSet);
    InjectStylesheetFile(pManagerSet, PAGE_FILE_START_CSS, sLocation);
    InjectJavascriptFile(pManagerSet, PAGE_FILE_START_JS, sLocation);
    LoadHtmlContentFile(pManagerSet, PAGE_FILE_START_HTML, sLocation);
}

void SceneStart::Finish(SafeObject<ManagerSet>& pManagerSet)
{
    // Clear callbacks
    ClearPostCallback();

    // Clear page content
    RemoveAllInjectedData();
}

void SceneStart::Update(SafeObject<ManagerSet>& pManagerSet)
{
}

void SceneStart::Input(SafeObject<ManagerSet>& pManagerSet)
{
}

void SceneStart::OnMessageReceived(SafeObject<ManagerSet>& pManagerSet, const String& sMessage)
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
