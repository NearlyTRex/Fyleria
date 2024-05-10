// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_CHARACTER_CHARACTER_TYPES_H_
#define _GECKO_CHARACTER_CHARACTER_TYPES_H_

// Internal includes
#include "Utility/Macros.h"
#include "Utility/Enum.h"

namespace Gecko
{

MAKE_ENUM(CharacterTreeIndexType, Int,
    None,
    Skill,
    Item
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterTreeIndexType);

MAKE_ENUM(CharacterStatusType, Int,
    None,
    Acidified,
    Berserk,
    Bound,
    Bleeding,
    Blinded,
    Burned,
    Calmed,
    Dead,
    Delirious,
    Frozen,
    Horrified,
    Knockdown,
    Mossified,
    Sleeping,
    Swallowed,
    Unconscious
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterStatusType);

MAKE_ENUM(CharacterBaseRaceType, Int,
    None,
    Human,
    Dwarf,
    Drow,
    Elf,
    Halfling,
    Caetian,
    Geikan,
    Faerie,
    Goblin
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterBaseRaceType);

MAKE_ENUM(CharacterTransformedRaceType, Int,
    None,
    Untransformed,
    Skeleton,
    Zombie,
    Vampire,
    Ghost,
    Wraith,
    Revenant,
    Ghoul
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterTransformedRaceType);

MAKE_ENUM(CharacterPowerSetType, Int,
    None,
    Oracle,
    Reaper,
    Dragon,
    Trickster,
    Sidhe,
    Vampire
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterPowerSetType);

MAKE_ENUM(CharacterWeaponSetType, Int,
    None,
    WeaponSet1,
    WeaponSet2
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterWeaponSetType);

MAKE_ENUM(CharacterGenderType, Int,
    None,
    Male,
    Female
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterGenderType);

MAKE_ENUM(CharacterHairType, Int,
    None,
    Hair1,
    Hair2
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterHairType);

MAKE_ENUM(CharacterEyeType, Int,
    None,
    Eyes1,
    Eyes2
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterEyeType);

MAKE_ENUM(CharacterHandednessType, Int,
    None,
    LeftHanded,
    RightHanded
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterHandednessType);

MAKE_ENUM(CharacterHandType, Int,
    None,
    Primary,
    Secondary
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterHandType);

MAKE_ENUM(CharacterEquipmentType, Int,
    None,
    Weapon1Left,
    Weapon1Right,
    Weapon2Left,
    Weapon2Right,
    LeftFingers,
    RightFingers,
    Neck,
    Head,
    Hands,
    Feet,
    Legs,
    Chest
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterEquipmentType);

MAKE_ENUM(CharacterTargetType, Int,
    None,
    Self,
    ActionTargetsThisAction,
    ActionSourceThisAction,
    ActionTargetsThisRound,
    ActionSourcesThisRound,
    ActionTargetsLastRound,
    ActionSourcesLastRound,
    MostRecentActionTargets,
    MostRecentActionSource,
    AllEnemies,
    AllAllies,
    Enemy1,
    Enemy2,
    Enemy3,
    Enemy4,
    Enemy5,
    Enemy6,
    Ally1,
    Ally2,
    Ally3,
    Ally4,
    Ally5,
    Ally6
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterTargetType);

MAKE_ENUM(CharacterResolvedTargetType, Int,
    None,
    Enemy1,
    Enemy2,
    Enemy3,
    Enemy4,
    Enemy5,
    Enemy6,
    Ally1,
    Ally2,
    Ally3,
    Ally4,
    Ally5,
    Ally6
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterResolvedTargetType);

MAKE_ENUM(CharacterPartyType, Int,
    None,
    Ally,
    Enemy
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterPartyType);

MAKE_ENUM(CharacterActionType, Int,
    None,
    ItemPotionEnergy,
    ItemPotionHeal,
    ItemPotionMagic,
    ItemPotionSpeed,
    WeaponBasePierce,
    WeaponBaseBlunt,
    WeaponBaseSlash,
    WeaponSlash,
    WeaponSever,
    WeaponSlice,
    WeaponSlit,
    WeaponCleave,
    WeaponDecapitate,
    WeaponParry,
    WeaponRiposte,
    WeaponBash,
    WeaponSmash,
    WeaponImpact,
    WeaponCrush,
    WeaponBreak,
    WeaponCrack,
    WeaponBlock,
    WeaponRush,
    WeaponPierce,
    WeaponDrill,
    WeaponShoot,
    WeaponImpale,
    WeaponStealthStrike,
    WeaponCriticalShot,
    WeaponDodge,
    WeaponCounter,
    SpellHoly,
    SpellFire,
    SpellIce,
    SpellShock,
    SpellDark,
    SpellLight,
    SpellForce,
    SpellMind,
    SpellEarth,
    SpellBlood,
    SpellFlesh,
    SpellWind,
    PowerHoly,
    PowerFire,
    PowerIce,
    PowerShock,
    PowerDark,
    PowerLight,
    PowerForce,
    PowerMind,
    PowerEarth,
    PowerBlood,
    PowerFlesh,
    PowerWind
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterActionType);

MAKE_ENUM(CharacterActionRunType, Int,
    None,
    Battle,
    Field
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterActionRunType);

MAKE_ENUM(CharacterRegenerationType, Int,
    None,
    CurrentStats,
    EquipmentRatings,
    AvailableChanges,
    AvailableActions,
    AvailableAP
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterRegenerationType);


};

#endif
