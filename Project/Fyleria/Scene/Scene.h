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

    // Init scene
    virtual void Init();

    // Destroy scene
    virtual void Destroy();

    // Update scene
    virtual void Update();
};

// Typedef
MAKE_TYPE_TYPEDEFS(Scene);

};

#endif
