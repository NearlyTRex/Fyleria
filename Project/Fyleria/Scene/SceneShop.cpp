// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneShop.h"
#include "Window/MainWindow.h"
#include "Utility/Constants.h"
#include "Utility/ManagerSet.h"

namespace Gecko
{

SceneShop::SceneShop()
    : Scene()
{
}

SceneShop::~SceneShop()
{
}

void SceneShop::Start(ManagerSet* pManagerSet)
{
    // Check manager set
    CHECK_MANAGER_SET_PTR(pManagerSet);

    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneShop::OnMessageReceived, this, pManagerSet, STDPlaceholder1));

    // Page location
    String sLocation = pManagerSet->GetFileManager()->GetDataPagesDirectory();

    // Load page content
    InjectCommonData(pManagerSet);
    InjectStylesheetFile(PAGE_FILE_SHOP_CSS, sLocation);
    InjectJavascriptFile(PAGE_FILE_SHOP_JS, sLocation);
    SetHtmlContentFile(PAGE_FILE_SHOP_HTML, sLocation);
}

void SceneShop::Finish(ManagerSet* pManagerSet)
{
    // Clear callbacks
    ClearPostCallback();

    // Clear page content
    RemoveAllInjectedData();
}

void SceneShop::Update(ManagerSet* pManagerSet)
{
}

void SceneShop::Input(ManagerSet* pManagerSet)
{
}

void SceneShop::OnMessageReceived(ManagerSet* pManagerSet, const String& sMessage)
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
