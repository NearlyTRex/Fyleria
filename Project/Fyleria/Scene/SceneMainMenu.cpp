// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneMainMenu.h"
#include "Window/MainWindow.h"
#include "Utility/Constants.h"
#include "Utility/ManagerSet.h"

namespace Gecko
{

SceneMainMenu::SceneMainMenu()
    : Scene()
{
}

SceneMainMenu::~SceneMainMenu()
{
}

void SceneMainMenu::Start(ManagerSet* pManagerSet)
{
    // Check manager set
    CHECK_MANAGER_SET_PTR(pManagerSet);

    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneMainMenu::OnMessageReceived, this, pManagerSet, STDPlaceholder1));

    // Page location
    String sLocation = pManagerSet->GetFileManager()->GetDataPagesDirectory();

    // Load page content
    InjectCommonData(pManagerSet);
    InjectStylesheetFile(PAGE_FILE_MAIN_MENU_CSS, sLocation);
    InjectJavascriptFile(PAGE_FILE_MAIN_MENU_JS, sLocation);
    SetHtmlContentFile(PAGE_FILE_MAIN_MENU_HTML, sLocation);
}

void SceneMainMenu::Finish(ManagerSet* pManagerSet)
{
    // Clear callbacks
    ClearPostCallback();

    // Clear page content
    RemoveAllInjectedData();
}

void SceneMainMenu::Update(ManagerSet* pManagerSet)
{
}

void SceneMainMenu::Input(ManagerSet* pManagerSet)
{
}

void SceneMainMenu::OnMessageReceived(ManagerSet* pManagerSet, const String& sMessage)
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
