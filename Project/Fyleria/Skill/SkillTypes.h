// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_SKILL_SKILL_TYPES_H_
#define _GECKO_SKILL_SKILL_TYPES_H_

// Internal includes
#include "Utility/Macros.h"
#include "Utility/Enum.h"

namespace Gecko
{

MAKE_ENUM(SkillTreeType, Int,
    None,
    Affinity,
    Alchemy,
    Crafting,
    Breakdown,
    Combat,
    Weapon
);
MAKE_ENUM_CONVERTERS_PROTO(SkillTreeType);

MAKE_ENUM(SkillWeaponBaseType, Int,
    None,
    Slash,
    Blunt,
    Pierce
);
MAKE_ENUM_CONVERTERS_PROTO(SkillWeaponBaseType);

MAKE_ENUM(SkillWeaponType, Int,
    None,

    // -- Slash --
    Slash,
    Sever,
    Slice,
    Slit,
    Cleave,
    Decapitate,
    Parry,
    Riposte,

    // -- Blunt --
    Bash,
    Smash,
    Impact,
    Crush,
    Break,
    Crack,
    Block,
    Rush,

    // -- Pierce --
    Pierce,
    Drill,
    Shoot,
    Impale,
    StealthStrike,
    CriticalShot,
    Dodge,
    Counter
);
MAKE_ENUM_CONVERTERS_PROTO(SkillWeaponType);

MAKE_ENUM(SkillAlchemyType, Int,
    None,
    Healer,
    Alchemist,
    Energist,
    Chemist
);
MAKE_ENUM_CONVERTERS_PROTO(SkillAlchemyType);

MAKE_ENUM(SkillBreakdownType, Int,
    None,
    Hammerbane,
    Spellbane,
    Bowbane,
    Swordbane,
    Threadbare,
    StudRemover,
    Scalebane,
    Platebane,
    Goldbane,
    Shieldbane
);
MAKE_ENUM_CONVERTERS_PROTO(SkillBreakdownType);

MAKE_ENUM(SkillCombatType, Int,
    None,
    Barbarian,
    Mage,
    Rogue,
    Blademaster,
    Avatar,
    Ambidextrous,
    Focused,
    Stalwart
);
MAKE_ENUM_CONVERTERS_PROTO(SkillCombatType);

MAKE_ENUM(SkillCraftingType, Int,
    None,
    Hammersmith,
    Spellsmith,
    Bowsmith,
    Swordsmith,
    Weaver,
    Tanner,
    Scalesmith,
    Platesmith,
    Goldsmith,
    Shieldsmith
);
MAKE_ENUM_CONVERTERS_PROTO(SkillCraftingType);

MAKE_ENUM(SkillAffinityType, Int,
    None,
    Holy,
    Fire,
    Ice,
    Shock,
    Dark,
    Light,
    Force,
    Mind,
    Earth,
    Blood,
    Flesh,
    Wind
);
MAKE_ENUM_CONVERTERS_PROTO(SkillAffinityType);

};

#endif
