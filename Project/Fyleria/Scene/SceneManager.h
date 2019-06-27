// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_SCENE_MANAGER_H_
#define _GECKO_SCENE_MANAGER_H_

// Internal includes
#include "Scene/Scene.h"
#include "Utility/Types.h"
#include "Utility/Singleton.h"

namespace Gecko
{

// Scene manager
class SceneManager : public Singleton<SceneManager>
{
public:

    // Types
    typedef STDUnorderedMap<String, SceneSharedPtr> SceneMappingType;

    // Constructor
    SceneManager();

    // Destructor
    virtual ~SceneManager();

    // Add scene
    void AddScene(const String& sSceneID, const SceneSharedPtr& pScene);

    // Remove scene
    void RemoveScene(const String& sSceneID);

    // Switch to scene
    void SwitchToScene(const String& sSceneID);

    // Does scene exist
    Bool DoesSceneExist(const String& sSceneID) const;

    // Get scene
    const SceneSharedPtr& GetScene(const String& sSceneID) const;
    SceneSharedPtr& GetScene(const String& sSceneID);

    // Get current scene
    const SceneSharedPtr& GetCurrentScene() const;
    SceneSharedPtr& GetCurrentScene();

    // Current scene
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(CurrentSceneID, String);

    // Scenes
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(Scenes, SceneMappingType);
};

};

#endif
