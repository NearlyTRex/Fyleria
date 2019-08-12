// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneMap.h"
#include "Window/MainWindow.h"
#include "Utility/Constants.h"

namespace Gecko
{

SceneMap::SceneMap()
    : Scene()
{
}

SceneMap::~SceneMap()
{
}

void SceneMap::Start(ManagerSet* pManagerSet)
{
    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneMap::OnMessageReceived, this, pManagerSet, STDPlaceholder1));

    // Load page content
    InjectStylesheetFile(LIB_FILE_BOOTSTRAP_CSS);
    InjectJavascriptFile(LIB_FILE_BOOTSTRAP_JS);
    InjectJavascriptFile(LIB_FILE_JQUERY_JS);
    InjectStylesheetFile(LIB_FILE_JQUERY_TERMINAL_CSS);
    InjectJavascriptFile(LIB_FILE_JQUERY_TERMINAL_JS);
    InjectJavascriptFile(LIB_FILE_JQUERY_MOUSEWHEEL_JS);
    InjectJavascriptFile(LIB_FILE_POLYFILL_KEYBOARD_JS);
    InjectJavascriptFile(LIB_FILE_COMMON_JS);
    LoadHtmlFromFile(PAGE_FILE_MAP);

    // Clear page content
    RemoveAllInjectedData();
}

void SceneMap::Finish(ManagerSet* pManagerSet)
{
    // Clear callbacks
    ClearPostCallback();
}

void SceneMap::Update(ManagerSet* pManagerSet)
{
}

void SceneMap::Input(ManagerSet* pManagerSet)
{
}

void SceneMap::OnMessageReceived(ManagerSet* pManagerSet, const String& sMessage)
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
