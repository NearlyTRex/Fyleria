// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_SCENE_TOOL_CHARACTER_H_
#define _GECKO_SCENE_TOOL_CHARACTER_H_

// Internal includes
#include "Scene/Scene.h"

namespace Gecko
{

class SceneToolCharacter : public Scene
{
public:

    // Constructor
    SceneToolCharacter(ManagerSet* pManagerSet);

    // Destructor
    virtual ~SceneToolCharacter();

    // Start scene
    virtual void Start(ManagerSet* pManagerSet) override;

    // Finish scene
    virtual void Finish(ManagerSet* pManagerSet) override;

    // Update scene
    virtual void Update(ManagerSet* pManagerSet) override;

    // Handle scene input
    virtual void Input(ManagerSet* pManagerSet) override;

protected:

    // Handle message received
    virtual void OnMessageReceived(ManagerSet* pManagerSet, const String& sMessage) override;
};

// Typedef
MAKE_COMMON_TYPEDEFS(SceneToolCharacter);

};

#endif
