// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneToolCharacter.h"
#include "Web/WebPageHandlerCharacterTool.h"
#include "Utility/Constants.h"

namespace Gecko
{

SceneToolCharacter::SceneToolCharacter(ManagerSet* pManagerSet)
    : Scene()
{
    // Create handler
    SetPageHandler(STDMakeSharedPtr<WebPageHandlerCharacterTool>(pManagerSet));
}

SceneToolCharacter::~SceneToolCharacter()
{
}

void SceneToolCharacter::Start(ManagerSet* pManagerSet)
{
    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneToolCharacter::OnMessageReceived, this, pManagerSet, STDPlaceholder1));

    // Load page content
    InjectCommonData();
    LoadHtmlFromHandler(GetPageHandler());
}

void SceneToolCharacter::Finish(ManagerSet* pManagerSet)
{
    // Clear callbacks
    ClearPostCallback();

    // Clear page content
    RemoveAllInjectedData();
}

void SceneToolCharacter::Update(ManagerSet* pManagerSet)
{
}

void SceneToolCharacter::Input(ManagerSet* pManagerSet)
{
}

void SceneToolCharacter::OnMessageReceived(ManagerSet* pManagerSet, const String& sMessage)
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
