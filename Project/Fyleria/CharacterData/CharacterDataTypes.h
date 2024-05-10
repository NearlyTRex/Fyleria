// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_CHARACTER_CHARACTER_DATA_TYPES_H_
#define _GECKO_CHARACTER_CHARACTER_DATA_TYPES_H_

// Internal includes
#include "Utility/Macros.h"
#include "Utility/Enum.h"

namespace Gecko
{

MAKE_ENUM(CharacterActionDataType_Int, Int,
    None,
    SlashPoints,
    SeverPoints,
    SlicePoints,
    SlitPoints,
    CleavePoints,
    DecapitatePoints,
    ParryPoints,
    RipostePoints,
    BashPoints,
    SmashPoints,
    ImpactPoints,
    CrushPoints,
    BreakPoints,
    CrackPoints,
    BlockPoints,
    RushPoints,
    PiercePoints,
    DrillPoints,
    ShootPoints,
    ImpalePoints,
    StealthStrikePoints,
    CriticalShotPoints,
    DodgePoints,
    CounterPoints
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterActionDataType_Int);

MAKE_ENUM(CharacterBasicDataType_String, Int,
    None,
    CharacterID,
    PartyID,
    FirstName,
    LastName,
    Gender,
    Hair,
    Eyes,
    Handedness,
    BaseRace,
    TransformedRace,
    PowerSet,
    WeaponSet
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterBasicDataType_String);

MAKE_ENUM(CharacterBasicDataType_Int, Int,
    None,
    Age
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterBasicDataType_Int);

MAKE_ENUM(CharacterMediaDataType_String, Int,
    None,
    PortraitImage
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterMediaDataType_String);

MAKE_ENUM(CharacterProgressDataType_Int, Int,
    None,

    // Regular
    HealthCostDelta,
    MagicCostDelta,
    EnergyCostDelta,
    AmberValueDelta,
    RubyValueDelta,
    DiamondValueDelta,
    CitrineValueDelta,
    OnyxValueDelta,
    QuartzValueDelta,
    SapphireValueDelta,
    AmethystValueDelta,
    EmeraldValueDelta,
    GarnetValueDelta,
    IvoryValueDelta,
    OpalValueDelta,

    // Segmented
    HealthPointsBase,
    HealthPointsCurrent,
    MagicPointsBase,
    MagicPointsCurrent,
    EnergyPointsBase,
    EnergyPointsCurrent,
    HealthPointsMaxBase,
    HealthPointsMaxCurrent,
    MagicPointsMaxBase,
    MagicPointsMaxCurrent,
    EnergyPointsMaxBase,
    EnergyPointsMaxCurrent,
    HealthRegenBase,
    HealthRegenCurrent,
    MagicRegenBase,
    MagicRegenCurrent,
    EnergyRegenBase,
    EnergyRegenCurrent,
    SpeedBase,
    SpeedCurrent,
    BluntAttackBase,
    BluntAttackCurrent,
    BluntDefenseBase,
    BluntDefenseCurrent,
    PierceAttackBase,
    PierceAttackCurrent,
    PierceDefenseBase,
    PierceDefenseCurrent,
    SlashAttackBase,
    SlashAttackCurrent,
    SlashDefenseBase,
    SlashDefenseCurrent,
    MagicAttackBase,
    MagicAttackCurrent,
    MagicDefenseBase,
    MagicDefenseCurrent,
    EnergyAttackBase,
    EnergyAttackCurrent,
    EnergyDefenseBase,
    EnergyDefenseCurrent
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterProgressDataType_Int);

MAKE_ENUM(CharacterBattleDataType_String, Int,
    None,
    ActionSourceThisAction,
    MostRecentActionSource
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterBattleDataType_String);

MAKE_ENUM(CharacterBattleDataType_StringArray, Int,
    None,
    PreviousActionTypes,
    ActionTargetsThisAction,
    ActionTargetsThisRound,
    ActionSourcesThisRound,
    ActionTargetsLastRound,
    ActionSourcesLastRound,
    MostRecentActionTargets
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterBattleDataType_StringArray);

MAKE_ENUM(CharacterBattleDataType_Bool, Int,
    None,
    TargetsMustBeIdentical
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterBattleDataType_Bool);

MAKE_ENUM(CharacterBattleDataType_Int, Int,
    None,
    AttackCounter,
    DefendCounter,
    AllowedTargetAmount,
    DamageTakenThisRound,
    DamageTakenThisBattle,
    DamageGivenThisRound,
    DamageGivenThisBattle
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterBattleDataType_Int);

MAKE_ENUM(CharacterBattleDataType_Float, Int,
    None,
    EquippedWeaponLeftBluntRating,
    EquippedWeaponLeftPierceRating,
    EquippedWeaponLeftSlashRating,
    EquippedWeaponRightBluntRating,
    EquippedWeaponRightPierceRating,
    EquippedWeaponRightSlashRating,
    EquippedShieldLeftBluntRating,
    EquippedShieldLeftPierceRating,
    EquippedShieldLeftSlashRating,
    EquippedShieldLeftMagicRating,
    EquippedShieldRightBluntRating,
    EquippedShieldRightPierceRating,
    EquippedShieldRightSlashRating,
    EquippedShieldRightMagicRating,
    EquippedArmorBluntRating,
    EquippedArmorPierceRating,
    EquippedArmorSlashRating,
    EquippedArmorMagicRating,
    ChanceToCauseCriticalHit,
    ChanceToBlockCriticalHit,
    CriticalHitMultiplier,
    ChanceToApplyMultipleAttacks,
    AttacksMultiplier,
    WeaponPrimaryDamageBonusValue,
    WeaponPrimaryDamageBonusPercent,
    WeaponSecondaryDamageBonusValue,
    WeaponSecondaryDamageBonusPercent,
    GeneralDamageBonusPercent,
    GeneralDamageBonusValue,
    DefensivePowerEffectsBonusValue,
    DefensivePowerEffectsBonusPercent,
    OffensivePowerEffectsBonusValue,
    OffensivePowerEffectsBonusPercent
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterBattleDataType_Float);

MAKE_ENUM(CharacterSkillDataType_Short, Int,
    None,
    Healer,
    Alchemist,
    Energist,
    Chemist,
    Hammerbane,
    Spellbane,
    Bowbane,
    Swordbane,
    Threadbare,
    StudRemover,
    Scalebane,
    Platebane,
    Goldbane,
    Shieldbane,
    Barbarian,
    Mage,
    Rogue,
    Blademaster,
    Avatar,
    Ambidextrous,
    Focused,
    Stalwart,
    Hammersmith,
    Spellsmith,
    Bowsmith,
    Swordsmith,
    Weaver,
    Tanner,
    Scalesmith,
    Platesmith,
    Goldsmith,
    Shieldsmith,
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
MAKE_ENUM_CONVERTERS_PROTO(CharacterSkillDataType_Short);

MAKE_ENUM(CharacterStatusEffectDataType_Bool, Int,
    None,
    IsAcidified,
    IsBerserk,
    IsBound,
    IsBleeding,
    IsBlinded,
    IsBurned,
    IsCalmed,
    IsDead,
    IsDelirious,
    IsFrozen,
    IsHorrified,
    IsKnockdown,
    IsMossified,
    IsSleeping,
    IsSwallowed,
    IsUnconscious
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterStatusEffectDataType_Bool);

};

#endif
