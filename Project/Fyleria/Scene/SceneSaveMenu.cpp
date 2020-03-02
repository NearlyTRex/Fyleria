// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneSaveMenu.h"
#include "Window/MainWindow.h"
#include "Utility/Constants.h"
#include "Utility/ManagerSet.h"

namespace Gecko
{

SceneSaveMenu::SceneSaveMenu()
    : Scene()
{
}

SceneSaveMenu::~SceneSaveMenu()
{
}

void SceneSaveMenu::Start(SafeObject<ManagerSet>& pManagerSet)
{
    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneSaveMenu::OnMessageReceived, this, pManagerSet, STDPlaceholder1));

    // Page location
    String sLocation = pManagerSet->GetFileManager()->GetDataPagesDirectory();

    // Load page content
    InjectCommonData(pManagerSet);
    InjectStylesheetFile(pManagerSet, PAGE_FILE_SAVE_MENU_CSS, sLocation);
    InjectJavascriptFile(pManagerSet, PAGE_FILE_SAVE_MENU_JS, sLocation);
    LoadHtmlContentFile(pManagerSet, PAGE_FILE_SAVE_MENU_HTML, sLocation);
}

void SceneSaveMenu::Finish(SafeObject<ManagerSet>& pManagerSet)
{
    // Clear callbacks
    ClearPostCallback();

    // Clear page content
    RemoveAllInjectedData();
}

void SceneSaveMenu::Update(SafeObject<ManagerSet>& pManagerSet)
{
}

void SceneSaveMenu::Input(SafeObject<ManagerSet>& pManagerSet)
{
}

void SceneSaveMenu::OnMessageReceived(SafeObject<ManagerSet>& pManagerSet, const String& sMessage)
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
