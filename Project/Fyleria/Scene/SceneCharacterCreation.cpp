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

void SceneCharacterCreation::Start(SafeObject<ManagerSet>& pManagerSet)
{
    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneCharacterCreation::OnMessageReceived, this, pManagerSet, STDPlaceholder1));

    // Page location
    String sLocation = pManagerSet->GetFileManager()->GetDataPagesDirectory();

    // Load page content
    InjectCommonData(pManagerSet);
    InjectStylesheetFile(pManagerSet, PAGE_FILE_CHARACTER_CREATION_CSS, sLocation);
    InjectJavascriptFile(pManagerSet, PAGE_FILE_CHARACTER_CREATION_JS, sLocation);
    LoadHtmlContentFile(pManagerSet, PAGE_FILE_CHARACTER_CREATION_HTML, sLocation);
}

void SceneCharacterCreation::Finish(SafeObject<ManagerSet>& pManagerSet)
{
    // Clear callbacks
    ClearPostCallback();

    // Clear page content
    RemoveAllInjectedData();
}

void SceneCharacterCreation::Update(SafeObject<ManagerSet>& pManagerSet)
{
}

void SceneCharacterCreation::Input(SafeObject<ManagerSet>& pManagerSet)
{
}

void SceneCharacterCreation::OnMessageReceived(SafeObject<ManagerSet>& pManagerSet, const String& sMessage)
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
