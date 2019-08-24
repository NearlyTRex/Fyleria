// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneCharacterCreation.h"
#include "Window/MainWindow.h"
#include "Utility/Constants.h"
#include "Utility/ManagerSet.h"

namespace Gecko
{

SceneCharacterCreation::SceneCharacterCreation()
    : Scene()
{
}

SceneCharacterCreation::~SceneCharacterCreation()
{
}

void SceneCharacterCreation::Start(ManagerSet* pManagerSet)
{
    // Check manager set
    CHECK_MANAGER_SET_PTR(pManagerSet);

    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneCharacterCreation::OnMessageReceived, this, pManagerSet, STDPlaceholder1));

    // Page location
    String sLocation = pManagerSet->GetFileManager().GetDataPagesDirectory();

    // Load page content
    InjectCommonData(pManagerSet);
    InjectStylesheetFile(PAGE_FILE_CHARACTER_CREATION_CSS, sLocation);
    InjectJavascriptFile(PAGE_FILE_CHARACTER_CREATION_JS, sLocation);
    SetHtmlContentFile(PAGE_FILE_CHARACTER_CREATION_HTML, sLocation);
}

void SceneCharacterCreation::Finish(ManagerSet* pManagerSet)
{
    // Clear callbacks
    ClearPostCallback();

    // Clear page content
    RemoveAllInjectedData();
}

void SceneCharacterCreation::Update(ManagerSet* pManagerSet)
{
}

void SceneCharacterCreation::Input(ManagerSet* pManagerSet)
{
}

void SceneCharacterCreation::OnMessageReceived(ManagerSet* pManagerSet, const String& sMessage)
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
