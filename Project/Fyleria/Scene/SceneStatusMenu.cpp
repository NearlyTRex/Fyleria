// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneStatusMenu.h"
#include "Window/MainWindow.h"
#include "Utility/Constants.h"
#include "Utility/ManagerSet.h"

namespace Gecko
{

SceneStatusMenu::SceneStatusMenu()
    : Scene()
{
}

SceneStatusMenu::~SceneStatusMenu()
{
}

void SceneStatusMenu::Start(ManagerSet* pManagerSet)
{
    // Check manager set
    CHECK_MANAGER_SET_PTR(pManagerSet);

    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneStatusMenu::OnMessageReceived, this, pManagerSet, STDPlaceholder1));

    // Page location
    String sLocation = pManagerSet->GetFileManager().GetDataPagesDirectory();

    // Load page content
    InjectCommonData(pManagerSet);
    InjectStylesheetFile(PAGE_FILE_STATUS_MENU_CSS, sLocation);
    InjectJavascriptFile(PAGE_FILE_STATUS_MENU_JS, sLocation);
    SetHtmlContentFile(PAGE_FILE_STATUS_MENU_HTML, sLocation);
}

void SceneStatusMenu::Finish(ManagerSet* pManagerSet)
{
    // Clear callbacks
    ClearPostCallback();

    // Clear page content
    RemoveAllInjectedData();
}

void SceneStatusMenu::Update(ManagerSet* pManagerSet)
{
}

void SceneStatusMenu::Input(ManagerSet* pManagerSet)
{
}

void SceneStatusMenu::OnMessageReceived(ManagerSet* pManagerSet, const String& sMessage)
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
