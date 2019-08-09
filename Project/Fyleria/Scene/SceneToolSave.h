// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_SCENE_TOOL_SAVE_H_
#define _GECKO_SCENE_TOOL_SAVE_H_

// Internal includes
#include "Scene/Scene.h"
#include "Web/WebPageHandlerSaveTool.h"

namespace Gecko
{

class SceneToolSave : public Scene
{
public:

    // Constructor
    SceneToolSave(ManagerSet* pManagerSet);

    // Destructor
    virtual ~SceneToolSave();

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

    // Web page handler
    MAKE_RAW_TYPE_ACCESSORS(WebPageHandler, STDSharedPtr<WebPageHandlerSaveTool>);
};

// Typedef
MAKE_COMMON_TYPEDEFS(SceneToolSave);

};

#endif
