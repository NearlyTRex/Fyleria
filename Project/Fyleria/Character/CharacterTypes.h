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

MAKE_ENUM(CharacterSegmentType, Int,
    None,
    Base,
    Passive,
    Active
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterSegmentType);

MAKE_ENUM(CharacterActionStatType_Int, Int,
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
MAKE_ENUM_CONVERTERS_PROTO(CharacterActionStatType_Int);

MAKE_ENUM(CharacterBasicStatType_String, Int,
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
MAKE_ENUM_CONVERTERS_PROTO(CharacterBasicStatType_String);

MAKE_ENUM(CharacterBasicStatType_Int, Int,
    None,
    Age
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterBasicStatType_Int);

MAKE_ENUM(CharacterMediaStatType_String, Int,
    None,
    PortraitImage
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterMediaStatType_String);

MAKE_ENUM(CharacterProgressStatType_Int, Int,
    None,
    HealthPointsCurrent,
    MagicPointsCurrent,
    EnergyPointsCurrent,
    HealthPointsMax,
    MagicPointsMax,
    EnergyPointsMax,
    HealthRegen,
    MagicRegen,
    EnergyRegen,
    HealthCostDelta,
    MagicCostDelta,
    EnergyCostDelta,
    SpeedCurrent,
    SpeedBase,
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
    BluntAttack,
    BluntDefense,
    PierceAttack,
    PierceDefense,
    SlashAttack,
    SlashDefense,
    MagicAttack,
    MagicDefense,
    EnergyAttack,
    EnergyDefense
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterProgressStatType_Int);

MAKE_ENUM(CharacterBattleStatType_String, Int,
    None,
    ActionSourceThisAction,
    MostRecentActionSource
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterBattleStatType_String);

MAKE_ENUM(CharacterBattleStatType_StringArray, Int,
    None,
    PreviousActionTypes,
    ActionTargetsThisAction,
    ActionTargetsThisRound,
    ActionSourcesThisRound,
    ActionTargetsLastRound,
    ActionSourcesLastRound,
    MostRecentActionTargets
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterBattleStatType_StringArray);

MAKE_ENUM(CharacterBattleStatType_Bool, Int,
    None,
    TargetsMustBeIdentical,
    IsDead,
    IsUnconscious
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterBattleStatType_Bool);

MAKE_ENUM(CharacterBattleStatType_Int, Int,
    None,
    AttackCounter,
    DefendCounter,
    AllowedTargetAmount,
    DamageTakenThisRound,
    DamageTakenThisBattle,
    DamageGivenThisRound,
    DamageGivenThisBattle
);
MAKE_ENUM_CONVERTERS_PROTO(CharacterBattleStatType_Int);

MAKE_ENUM(CharacterBattleStatType_Float, Int,
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
MAKE_ENUM_CONVERTERS_PROTO(CharacterBattleStatType_Float);

MAKE_ENUM(CharacterSkillStatType_Short, Int,
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
MAKE_ENUM_CONVERTERS_PROTO(CharacterSkillStatType_Short);

MAKE_ENUM(CharacterStatusType, Int,
    None,
    Dead,
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

String ConvertCharacterEquipmentTypeToCharacterWeaponSetType(const String& sCharacterEquipmentType);
String ConvertCharacterTargetTypeToCharacterPartyType(const String& sCharacterTargetType);
String ConvertItemTypeToCharacterActionType(const String& sItemType);
StringArray ConvertItemTypeToCharacterEquipTypes(const String& sItemType);
String ConvertSkillWeaponBaseTypeToCharacterActionType(const String& sSkillWeaponBaseType);
String ConvertSkillWeaponTypeToCharacterActionType(const String& sSkillWeaponType);
String ConvertSkillWeaponTypeToCharacterActionStatType(const String& sSkillWeaponType);

};

#endif
