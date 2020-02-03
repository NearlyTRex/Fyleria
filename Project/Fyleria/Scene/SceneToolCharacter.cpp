// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneToolCharacter.h"
#include "Web/WebPageHandlerCharacterTool.h"
#include "Utility/Constants.h"
#include "Utility/ManagerSet.h"

namespace Gecko
{

SceneToolCharacter::SceneToolCharacter(SafeObject<ManagerSet>& pManagerSet)
    : Scene()
{
    // Create handler
    SetPageHandler(STDMakeSharedPtr<WebPageHandlerCharacterTool>(pManagerSet));
}

SceneToolCharacter::~SceneToolCharacter()
{
}

void SceneToolCharacter::Start(SafeObject<ManagerSet>& pManagerSet)
{
    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneToolCharacter::OnMessageReceived, this, pManagerSet, STDPlaceholder1));

    // Page location
    String sLocation = pManagerSet->GetFileManager()->GetDataPagesDirectory();

    // Load page content
    InjectCommonData(pManagerSet);
    InjectStylesheetFile(pManagerSet, PAGE_FILE_TOOL_CHARACTER_CSS, sLocation);
    InjectJavascriptFile(pManagerSet, PAGE_FILE_TOOL_CHARACTER_JS, sLocation);
    LoadHtmlFromHandler(GetPageHandler());
}

void SceneToolCharacter::Finish(SafeObject<ManagerSet>& pManagerSet)
{
    // Clear callbacks
    ClearPostCallback();

    // Clear page content
    RemoveAllInjectedData();
}

void SceneToolCharacter::Update(SafeObject<ManagerSet>& pManagerSet)
{
}

void SceneToolCharacter::Input(SafeObject<ManagerSet>& pManagerSet)
{
}

void SceneToolCharacter::OnMessageReceived(SafeObject<ManagerSet>& pManagerSet, const String& sMessage)
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
