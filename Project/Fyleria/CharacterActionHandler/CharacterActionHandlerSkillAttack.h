// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_CHARACTER_CHARACTER_ACTION_HANDLER_SKILL_ATTACK_H_
#define _GECKO_CHARACTER_CHARACTER_ACTION_HANDLER_SKILL_ATTACK_H_

// Internal includes
#include "CharacterActionHandler/CharacterActionHandler.h"

namespace Gecko
{

// Skill attack character action handler
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
        const String& sDestCharID) const;

    // Stages for running the action
    virtual Bool Setup(CharacterAction& action) override;
    virtual Bool Finish(CharacterAction& action) override;
    virtual Bool GenerateResult(CharacterAction& action) override;
    virtual Bool ApplyResult(CharacterAction& action) override;
};

// Typedef
MAKE_COMMON_TYPEDEFS(CharacterActionHandlerSkillAttack);

};

#endif
