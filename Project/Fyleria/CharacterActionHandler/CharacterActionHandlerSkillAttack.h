// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_CHARACTER_ACTION_HANDLER_SKILL_ATTACK_H_
#define _GECKO_CHARACTER_ACTION_HANDLER_SKILL_ATTACK_H_

#include "CharacterActionHandler/CharacterActionHandler.h"

namespace Gecko
{

class CharacterActionHandlerSkillAttack : public CharacterActionHandler
{
public:

    // Constructors
    CharacterActionHandlerSkillAttack();

    // Destructors
    virtual ~CharacterActionHandlerSkillAttack();

    // Get skill attack result
    CharacterActionResult GetSkillAttackResult(
        const CharacterAction& action,
        const CharacterActionEntry& entry,
        const IndexedString& sDestCharID) const;

    // Stages for running the action
    virtual Bool Setup(CharacterAction& action);
    virtual Bool Finish(CharacterAction& action);
    virtual Bool GenerateResult(CharacterAction& action);
    virtual Bool ApplyResult(CharacterAction& action);
};

// Typedef
MAKE_TYPE_TYPEDEFS(CharacterActionHandlerSkillAttack);

};

#endif
