// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneManager.h"
#include "Utility/Errors.h"
#include "Utility/Logging.h"

namespace Gecko
{

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::AddScene(const String& sSceneID, const Scene& scene)
{
    // Add scene
    LOG_FORMAT_STATEMENT("Adding scene '%s'\n", sSceneID.c_str());
    GetScenes().insert({sSceneID, scene});
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
        GetCurrentScene().Finish();
    }

    // Start new scene
    LOG_FORMAT_STATEMENT("Starting scene '%s'\n", sSceneID.c_str());
    SetCurrentSceneID(sSceneID);
    GetCurrentScene().Start();
}

Bool SceneManager::DoesSceneExist(const String& sSceneID) const
{
    // Check if scene exists
    auto iSearch = GetScenes().find(sSceneID);
    return (iSearch != GetScenes().end());
}

const Scene& SceneManager::GetScene(const String& sSceneID) const
{
    // Get scene
    auto iSearch = GetScenes().find(sSceneID);
    if(iSearch != GetScenes().end())
    {
        return iSearch->second;
    }
    throw RuntimeError("Invalid or unknown scene ID requested: " + sSceneID);
}

Scene& SceneManager::GetScene(const String& sSceneID)
{
    // Get scene
    return const_cast<Scene&>(static_cast<const SceneManager&>(*this).GetScene(sSceneID));
}

const Scene& SceneManager::GetCurrentScene() const
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

Scene& SceneManager::GetCurrentScene()
{
    // Get current scene
    return const_cast<Scene&>(static_cast<const SceneManager&>(*this).GetCurrentScene());
}

};
