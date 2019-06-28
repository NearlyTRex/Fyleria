// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_SCENE_CHARACTER_CREATION_H_
#define _GECKO_SCENE_CHARACTER_CREATION_H_

// Internal includes
#include "Scene/Scene.h"

namespace Gecko
{

class SceneCharacterCreation : public Scene
{
public:

    // Constructor
    SceneCharacterCreation();

    // Destructor
    virtual ~SceneCharacterCreation();

    // Start scene
    virtual void Start() override;

    // Finish scene
    virtual void Finish() override;

    // Update scene
    virtual void Update() override;

    // Handle scene input
    virtual void Input() override;

    // Handle message received
    virtual void OnMessageReceived(const String& sMessage) override;
};

// Typedef
MAKE_TYPE_TYPEDEFS(SceneCharacterCreation);

};

#endif
