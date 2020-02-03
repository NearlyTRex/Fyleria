// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneManager.h"
#include "Scene/SceneTypes.h"
#include "Utility/Constants.h"
#include "Utility/Errors.h"
#include "Utility/Logging.h"
#include "Utility/ManagerSet.h"

namespace Gecko
{

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::AddScene(SafeObject<ManagerSet>& pManagerSet, const String& sSceneID)
{
    // Only add if it is not already added
    if (!DoesSceneExist(sSceneID))
    {
        SceneType eSceneType = GetEnumFromStringOrNone<SceneType>(sSceneID);
        switch (eSceneType)
        {
        case SceneType::Intro:
            AddScene(sSceneID, STDMakeSharedPtr<SceneIntro>());
            break;
        case SceneType::Loading:
            AddScene(sSceneID, STDMakeSharedPtr<SceneLoading>());
            break;
        case SceneType::MainMenu:
            AddScene(sSceneID, STDMakeSharedPtr<SceneMainMenu>());
            break;
        case SceneType::StatusMenu:
            AddScene(sSceneID, STDMakeSharedPtr<SceneStatusMenu>());
            break;
        case SceneType::SaveMenu:
            AddScene(sSceneID, STDMakeSharedPtr<SceneSaveMenu>());
            break;
        case SceneType::CraftingMenu:
            AddScene(sSceneID, STDMakeSharedPtr<SceneCraftingMenu>());
            break;
        case SceneType::Map:
            AddScene(sSceneID, STDMakeSharedPtr<SceneMap>());
            break;
        case SceneType::Shop:
            AddScene(sSceneID, STDMakeSharedPtr<SceneShop>());
            break;
        case SceneType::Battle:
            AddScene(sSceneID, STDMakeSharedPtr<SceneBattle>());
            break;
        case SceneType::CharacterCreation:
            AddScene(sSceneID, STDMakeSharedPtr<SceneCharacterCreation>());
            break;
        case SceneType::Credits:
            AddScene(sSceneID, STDMakeSharedPtr<SceneCredits>());
            break;
        case SceneType::ToolCharacter:
            AddScene(sSceneID, STDMakeSharedPtr<SceneToolCharacter>(pManagerSet));
            break;
        case SceneType::ToolParty:
            AddScene(sSceneID, STDMakeSharedPtr<SceneToolParty>(pManagerSet));
            break;
        case SceneType::ToolSave:
            AddScene(sSceneID, STDMakeSharedPtr<SceneToolSave>(pManagerSet));
            break;
        default:
            break;
        }
    }
}

void SceneManager::AddScene(const String& sSceneID, const SceneSharedPtr& pScene)
{
    // Add scene
    LOG_FORMAT_STATEMENT("Adding scene '{}'", sSceneID.c_str());
    GetScenes().insert({sSceneID, pScene});
}

void SceneManager::RemoveScene(const String& sSceneID)
{
    // Remove scene
    LOG_FORMAT_STATEMENT("Removing scene '{}'", sSceneID.c_str());
    GetScenes().erase(sSceneID);
}

void SceneManager::SwitchToScene(SafeObject<ManagerSet>& pManagerSet, const String& sSceneID)
{
    // Add scene if necessary
    AddScene(pManagerSet, sSceneID);

    // Skip if it still does not exist
    if(!DoesSceneExist(sSceneID))
    {
        ERROR_FORMAT_STATEMENT("Scene '{}' does not exist", sSceneID.c_str());
        return;
    }

    // Skip if we are already in this scene
    String sCurrentSceneID = GetCurrentSceneID();
    if(sCurrentSceneID == sSceneID)
    {
        ERROR_FORMAT_STATEMENT("Already in scene '{}'", sSceneID.c_str());
        return;
    }

    // Check if we already had a current scene and it's not the same scene
    if(DoesSceneExist(sCurrentSceneID) && (sCurrentSceneID != sSceneID))
    {
        // Finish it
        LOG_FORMAT_STATEMENT("Finishing scene '{}'", sCurrentSceneID.c_str());
        GetCurrentScene()->Finish(pManagerSet);
    }

    // Start new scene
    LOG_FORMAT_STATEMENT("Starting scene '{}'", sSceneID.c_str());
    SetCurrentSceneID(sSceneID);
    GetCurrentScene()->Start(pManagerSet);
}

Bool SceneManager::DoesSceneExist(const String& sSceneID) const
{
    // Check if scene exists
    auto iSearch = GetScenes().find(sSceneID);
    return (iSearch != GetScenes().end());
}

const SceneSharedPtr& SceneManager::GetScene(const String& sSceneID) const
{
    // Get scene
    auto iSearch = GetScenes().find(sSceneID);
    if(iSearch != GetScenes().end())
    {
        return iSearch->second;
    }
    THROW_RUNTIME_ERROR("Invalid or unknown scene ID requested: " + sSceneID);
}

SceneSharedPtr& SceneManager::GetScene(const String& sSceneID)
{
    // Get scene
    return const_cast<SceneSharedPtr&>(static_cast<const SceneManager&>(*this).GetScene(sSceneID));
}

const SceneSharedPtr& SceneManager::GetCurrentScene() const
{
    // Get current scene id
    String sCurrentSceneID = GetCurrentSceneID();
    if(sCurrentSceneID.empty())
    {
        THROW_RUNTIME_ERROR("No current scene ID was set");
    }

    // Get current scene
    return GetScene(sCurrentSceneID);
}

SceneSharedPtr& SceneManager::GetCurrentScene()
{
    // Get current scene
    return const_cast<SceneSharedPtr&>(static_cast<const SceneManager&>(*this).GetCurrentScene());
}

};
