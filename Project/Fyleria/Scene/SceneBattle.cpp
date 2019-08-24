// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneBattle.h"
#include "Window/MainWindow.h"
#include "Utility/Constants.h"
#include "Utility/ManagerSet.h"

namespace Gecko
{

SceneBattle::SceneBattle()
    : Scene()
{
}

SceneBattle::~SceneBattle()
{
}

void SceneBattle::Start(ManagerSet* pManagerSet)
{
    // Check manager set
    CHECK_MANAGER_SET_PTR(pManagerSet);

    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneBattle::OnMessageReceived, this, pManagerSet, STDPlaceholder1));

    // Page location
    String sLocation = pManagerSet->GetFileManager()->GetDataPagesDirectory();

    // Load page content
    InjectCommonData(pManagerSet);
    InjectStylesheetFile(PAGE_FILE_BATTLE_CSS, sLocation);
    InjectJavascriptFile(PAGE_FILE_BATTLE_JS, sLocation);
    SetHtmlContentFile(PAGE_FILE_BATTLE_HTML, sLocation);
}

void SceneBattle::Finish(ManagerSet* pManagerSet)
{
    // Clear callbacks
    ClearPostCallback();

    // Clear page content
    RemoveAllInjectedData();
}

void SceneBattle::Update(ManagerSet* pManagerSet)
{
}

void SceneBattle::Input(ManagerSet* pManagerSet)
{
}

void SceneBattle::OnMessageReceived(ManagerSet* pManagerSet, const String& sMessage)
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
