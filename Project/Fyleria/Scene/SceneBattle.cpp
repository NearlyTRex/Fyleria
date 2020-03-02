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

void SceneBattle::Start(SafeObject<ManagerSet>& pManagerSet)
{
    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneBattle::OnMessageReceived, this, pManagerSet, STDPlaceholder1));

    // Page location
    String sLocation = pManagerSet->GetFileManager()->GetDataPagesDirectory();

    // Load page content
    InjectCommonData(pManagerSet);
    InjectStylesheetFile(pManagerSet, PAGE_FILE_BATTLE_CSS, sLocation);
    InjectJavascriptFile(pManagerSet, PAGE_FILE_BATTLE_JS, sLocation);
    LoadHtmlContentFile(pManagerSet, PAGE_FILE_BATTLE_HTML, sLocation);
}

void SceneBattle::Finish(SafeObject<ManagerSet>& pManagerSet)
{
    // Clear callbacks
    ClearPostCallback();

    // Clear page content
    RemoveAllInjectedData();
}

void SceneBattle::Update(SafeObject<ManagerSet>& pManagerSet)
{
}

void SceneBattle::Input(SafeObject<ManagerSet>& pManagerSet)
{
}

void SceneBattle::OnMessageReceived(SafeObject<ManagerSet>& pManagerSet, const String& sMessage)
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
