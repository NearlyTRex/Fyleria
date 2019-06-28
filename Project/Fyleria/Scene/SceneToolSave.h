// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_SCENE_TOOL_SAVE_H_
#define _GECKO_SCENE_TOOL_SAVE_H_

// Internal includes
#include "Scene/Scene.h"

namespace Gecko
{

class SceneToolSave : public Scene
{
public:

    // Constructor
    SceneToolSave();

    // Destructor
    virtual ~SceneToolSave();

    // Start scene
    virtual void Start() override;

    // Finish scene
    virtual void Finish() override;

    // Update scene
    virtual void Update() override;

    // Handle scene input
    virtual void Input() override;
};

// Typedef
MAKE_TYPE_TYPEDEFS(SceneToolSave);

};

#endif
