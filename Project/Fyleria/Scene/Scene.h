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
    virtual void Start() = 0;

    // Finish scene
    virtual void Finish() = 0;

    // Update scene
    virtual void Update() = 0;

    // Handle scene input
    virtual void Input() = 0;

    // Handle message received
    virtual void OnMessageReceived(const String& sMessage) = 0;
};

// Typedef
MAKE_TYPE_TYPEDEFS(Scene);

};

#endif
