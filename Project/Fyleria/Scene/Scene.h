// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_SCENE_H_
#define _GECKO_SCENE_H_

// Internal includes
#include "Utility/Types.h"
#include "Utility/Macros.h"

namespace Gecko
{

class Scene
{
public:

    // Constructor
    Scene();

    // Destructor
    virtual ~Scene();

    // Start scene
    virtual void Start();

    // Finish scene
    virtual void Finish();

    // Update scene
    virtual void Update();

    // Handle scene input
    virtual void Input();
};

// Typedef
MAKE_TYPE_TYPEDEFS(Scene);

};

#endif
