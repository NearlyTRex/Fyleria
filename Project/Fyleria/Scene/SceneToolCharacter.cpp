// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneToolCharacter.h"
#include "Web/WebPageHandlerCharacterTool.h"

namespace Gecko
{

SceneToolCharacter::SceneToolCharacter()
    : Scene()
{
    // Create handler
    SetPageHandler(STDMakeSharedPtr<WebPageHandlerCharacterTool>());
}

SceneToolCharacter::~SceneToolCharacter()
{
}

void SceneToolCharacter::Start(ManagerSet* pManagerSet)
{
    // Register callbacks
    SetPostCallback(STDBindFunc(&SceneToolCharacter::OnMessageReceived, this, STDPlaceholder1));

    // Load page content
    LoadHtmlFromHandler(GetPageHandler());
}

void SceneToolCharacter::Finish(ManagerSet* pManagerSet)
{
    // Clear callbacks
    ClearPostCallback();
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
    if(Scene::HandleMessage(sMessage, sFunction, vArgs))
    {
        return;
    }
}

};
