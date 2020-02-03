// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_CHARACTER_ACTION_HANDLER_H_
#define _GECKO_CHARACTER_ACTION_HANDLER_H_

// Internal includes
#include "CharacterAction/CharacterAction.h"

namespace Gecko
{

// Manager set
class ManagerSet;

// Character action handler
class CharacterActionHandler
{
public:

    // Constructors
    CharacterActionHandler();

    // Destructor
    virtual ~CharacterActionHandler();

    // Stages for running the action
    virtual Bool Setup(SafeObject<ManagerSet>& pManagerSet, CharacterAction& action) = 0;
    virtual Bool Finish(SafeObject<ManagerSet>& pManagerSet, CharacterAction& action) = 0;
    virtual Bool GenerateResult(SafeObject<ManagerSet>& pManagerSet, CharacterAction& action) = 0;
    virtual Bool ApplyResult(SafeObject<ManagerSet>& pManagerSet, CharacterAction& action) = 0;
};

// Typedef
MAKE_COMMON_TYPEDEFS(CharacterActionHandler);

};

#endif
