// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_SCENE_START_H_
#define _GECKO_SCENE_START_H_

// Internal includes
#include "Scene/Scene.h"

namespace Gecko
{

class SceneStart : public Scene
{
public:

    // Constructor
    SceneStart();

    // Destructor
    virtual ~SceneStart();

    // Start scene
    virtual void Start(SafeObject<ManagerSet>& pManagerSet) override;

    // Finish scene
    virtual void Finish(SafeObject<ManagerSet>& pManagerSet) override;

    // Update scene
    virtual void Update(SafeObject<ManagerSet>& pManagerSet) override;

    // Handle scene input
    virtual void Input(SafeObject<ManagerSet>& pManagerSet) override;

protected:

    // Handle message received
    virtual void OnMessageReceived(SafeObject<ManagerSet>& pManagerSet, const String& sMessage) override;
};

// Typedef
MAKE_COMMON_TYPEDEFS(SceneStart);

};

#endif
