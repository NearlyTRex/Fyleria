// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneManager.h"
#include "Utility/Constants.h"
#include "Utility/Errors.h"
#include "Utility/Logging.h"

namespace Gecko
{

SceneManager::SceneManager()
{
    // Load scenes
    AddScene(SCENE_INTRO, STDMakeSharedPtr<SceneIntro>());
    AddScene(SCENE_LOADING, STDMakeSharedPtr<SceneLoading>());
    AddScene(SCENE_MAIN_MENU, STDMakeSharedPtr<SceneMainMenu>());
    AddScene(SCENE_STATUS_MENU, STDMakeSharedPtr<SceneStatusMenu>());
    AddScene(SCENE_SAVE_MENU, STDMakeSharedPtr<SceneSaveMenu>());
    AddScene(SCENE_CRAFTING_MENU, STDMakeSharedPtr<SceneCraftingMenu>());
    AddScene(SCENE_MAP, STDMakeSharedPtr<SceneMap>());
    AddScene(SCENE_SHOP, STDMakeSharedPtr<SceneShop>());
    AddScene(SCENE_BATTLE, STDMakeSharedPtr<SceneBattle>());
    AddScene(SCENE_CHARACTER_CREATION, STDMakeSharedPtr<SceneCharacterCreation>());
    AddScene(SCENE_CREDITS, STDMakeSharedPtr<SceneCredits>());
    AddScene(SCENE_TOOL_MAIN, STDMakeSharedPtr<SceneToolMain>());
    AddScene(SCENE_TOOL_CHARACTER, STDMakeSharedPtr<SceneToolCharacter>());
    AddScene(SCENE_TOOL_PARTY, STDMakeSharedPtr<SceneToolParty>());
    AddScene(SCENE_TOOL_SAVE, STDMakeSharedPtr<SceneToolSave>());
}

SceneManager::~SceneManager()
{
}

void SceneManager::AddScene(const String& sSceneID, const SceneSharedPtr& pScene)
{
    // Add scene
    LOG_FORMAT_STATEMENT("Adding scene '%s'\n", sSceneID.c_str());
    GetScenes().insert({sSceneID, pScene});
}

void SceneManager::RemoveScene(const String& sSceneID)
{
    // Remove scene
    LOG_FORMAT_STATEMENT("Removing scene '%s'\n", sSceneID.c_str());
    GetScenes().erase(sSceneID);
}

void SceneManager::SwitchToScene(const String& sSceneID)
{
    // Ensure that the new scene already exists
    if(!DoesSceneExist(sSceneID))
    {
        ERROR_FORMAT_STATEMENT("Scene '%s' does not exist, so cannot switch to it\n", sSceneID.c_str());
        return;
    }

    // Check if we already had a current scene and it's not the same scene
    String sCurrentSceneID = GetCurrentSceneID();
    if(DoesSceneExist(sCurrentSceneID) && (sCurrentSceneID != sSceneID))
    {
        // Finish it
        LOG_FORMAT_STATEMENT("Finishing scene '%s'\n", sCurrentSceneID.c_str());
        GetCurrentScene()->Finish();
    }

    // Start new scene
    LOG_FORMAT_STATEMENT("Starting scene '%s'\n", sSceneID.c_str());
    SetCurrentSceneID(sSceneID);
    GetCurrentScene()->Start();
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
    throw RuntimeError("Invalid or unknown scene ID requested: " + sSceneID);
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
        throw RuntimeError("No current scene ID was set");
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
