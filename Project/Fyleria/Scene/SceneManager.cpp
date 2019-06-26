// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Scene/SceneManager.h"
#include "Utility/Errors.h"

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
}

void SceneManager::RemoveScene(const String& sSceneID)
{
}

void SceneManager::SwitchToScene(const String& sSceneID)
{
}

const Scene& SceneManager::GetCurrentScene() const
{
    // Get current scene
    auto iSearch = GetScenes().find(GetCurrentSceneID());
    if(iSearch != GetScenes().end())
    {
        return iSearch->second;
    }
    throw RuntimeError("Invalid or unknown scene ID requested: " + GetCurrentSceneID());
}

Scene& SceneManager::GetCurrentScene()
{
    // Get current scene
    return const_cast<Scene&>(static_cast<const SceneManager&>(*this).GetCurrentScene());
}

};
