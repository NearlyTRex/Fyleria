// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneCredits.h"
#include "Window/MainWindow.h"
#include "Utility/Constants.h"
#include "Utility/ManagerSet.h"

namespace Gecko
{

SceneCredits::SceneCredits()
    : Scene()
{
}

SceneCredits::~SceneCredits()
{
}

void SceneCredits::Start(ManagerSet* pManagerSet)
{
    // Check manager set
    CHECK_MANAGER_SET_PTR(pManagerSet);

    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneCredits::OnMessageReceived, this, pManagerSet, STDPlaceholder1));

    // Page location
    String sLocation = pManagerSet->GetFileManager()->GetDataPagesDirectory();

    // Load page content
    InjectCommonData(pManagerSet);
    InjectStylesheetFile(PAGE_FILE_CREDITS_CSS, sLocation);
    InjectJavascriptFile(PAGE_FILE_CREDITS_JS, sLocation);
    SetHtmlContentFile(PAGE_FILE_CREDITS_HTML, sLocation);
}

void SceneCredits::Finish(ManagerSet* pManagerSet)
{
    // Clear callbacks
    ClearPostCallback();

    // Clear page content
    RemoveAllInjectedData();
}

void SceneCredits::Update(ManagerSet* pManagerSet)
{
}

void SceneCredits::Input(ManagerSet* pManagerSet)
{
}

void SceneCredits::OnMessageReceived(ManagerSet* pManagerSet, const String& sMessage)
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
