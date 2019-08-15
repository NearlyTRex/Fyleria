// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneIntro.h"
#include "Window/MainWindow.h"
#include "Utility/Constants.h"

namespace Gecko
{

SceneIntro::SceneIntro()
    : Scene()
{
}

SceneIntro::~SceneIntro()
{
}

void SceneIntro::Start(ManagerSet* pManagerSet)
{
    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneIntro::OnMessageReceived, this, pManagerSet, STDPlaceholder1));

    // Load page content
    InjectCommonData();
    InjectStylesheetFile(PAGE_FILE_INTRO_CSS, GetDataPagesDirectory());
    InjectJavascriptFile(PAGE_FILE_INTRO_JS, GetDataPagesDirectory());
    SetHtmlContentFile(PAGE_FILE_INTRO_HTML, GetDataPagesDirectory());
}

void SceneIntro::Finish(ManagerSet* pManagerSet)
{
    // Clear callbacks
    ClearPostCallback();

    // Clear page content
    RemoveAllInjectedData();
}

void SceneIntro::Update(ManagerSet* pManagerSet)
{
}

void SceneIntro::Input(ManagerSet* pManagerSet)
{
}

void SceneIntro::OnMessageReceived(ManagerSet* pManagerSet, const String& sMessage)
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
