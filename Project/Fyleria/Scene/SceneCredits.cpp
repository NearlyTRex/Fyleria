// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneCredits.h"
#include "Window/MainWindow.h"
#include "Utility/Constants.h"

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
    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneCredits::OnMessageReceived, this, pManagerSet, STDPlaceholder1));

    // Load page content
    InjectStylesheetFile(LIB_FILE_BOOTSTRAP_CSS);
    InjectJavascriptFile(LIB_FILE_BOOTSTRAP_JS);
    InjectJavascriptFile(LIB_FILE_JQUERY_JS);
    InjectStylesheetFile(LIB_FILE_JQUERY_TERMINAL_CSS);
    InjectJavascriptFile(LIB_FILE_JQUERY_TERMINAL_JS);
    InjectJavascriptFile(LIB_FILE_JQUERY_MOUSEWHEEL_JS);
    InjectJavascriptFile(LIB_FILE_POLYFILL_KEYBOARD_JS);
    InjectJavascriptFile(LIB_FILE_COMMON_JS);
    LoadHtmlFromFile(PAGE_FILE_CREDITS);
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
