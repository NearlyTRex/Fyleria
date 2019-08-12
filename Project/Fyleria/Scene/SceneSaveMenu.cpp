// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneSaveMenu.h"
#include "Window/MainWindow.h"
#include "Utility/Constants.h"

namespace Gecko
{

SceneSaveMenu::SceneSaveMenu()
    : Scene()
{
}

SceneSaveMenu::~SceneSaveMenu()
{
}

void SceneSaveMenu::Start(ManagerSet* pManagerSet)
{
    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneSaveMenu::OnMessageReceived, this, pManagerSet, STDPlaceholder1));

    // Load page content
    InjectCommonData();
    InjectStylesheetFile(PAGE_FILE_SAVE_MENU_CSS);
    InjectJavascriptFile(PAGE_FILE_SAVE_MENU_JS);
    LoadHtmlFromFile(PAGE_FILE_SAVE_MENU_HTML);
}

void SceneSaveMenu::Finish(ManagerSet* pManagerSet)
{
    // Clear callbacks
    ClearPostCallback();

    // Clear page content
    RemoveAllInjectedData();
}

void SceneSaveMenu::Update(ManagerSet* pManagerSet)
{
}

void SceneSaveMenu::Input(ManagerSet* pManagerSet)
{
}

void SceneSaveMenu::OnMessageReceived(ManagerSet* pManagerSet, const String& sMessage)
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
