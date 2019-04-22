// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_CHARACTER_BATTLE_DATA_H_
#define _GECKO_CHARACTER_BATTLE_DATA_H_

#include "CharacterData/CharacterProgressData.h"
#include "Stats/StatTypeHolder.h"

namespace Gecko
{

// Character battle data
class CharacterBattleData : public StatTypeHolder
{
public:

    // Constructors
    CharacterBattleData();
    CharacterBattleData(const Json& jsonData);

    // Clear all data
    void Clear();

    // Apply status
    void ApplyNewStatus(const CharacterProgressData& progressData);

    // Apply damage
    void ApplyGivenDamage(Int iDamage);
    void ApplyTakenDamage(Int iDamage);

    // Advance round
    void AdvanceRound(CharacterProgressData& progressData);

    // Finish battle
    void FinishBattle(CharacterProgressData& progressData);

    // Can regenerate from stat
    Bool CanRegenerateFromStat(const IndexedString& sRegenStat) const;

    // Update equipment ratings
    void UpdateEquipmentRatings(const IndexedString& sWeaponSet,
        const CharacterProgressItemArray& vEquippedItems,
        const CharacterProgressData& progressData);

    // Resolve target placeholders
    IndexedStringArray ResolveTargetPlaceholder(const IndexedString& sSelfTargetType,
        const IndexedString& sPlaceholderTargetType) const;

    // Weapon ratings based on handedness
    Bool GetPrimaryWeaponRatings(const IndexedString& sHandedness,
        Float& fPrimaryBlunt,
        Float& fPrimaryPierce,
        Float& fPrimarySlash) const;
    Bool GetSecondaryWeaponRatings(const IndexedString& sHandedness,
        Float& fSecondaryBlunt,
        Float& fSecondaryPierce,
        Float& fSecondarySlash) const;

    // Shield ratings based on handedness
    Bool GetPrimaryShieldRatings(const IndexedString& sHandedness,
        Float& fPrimaryBlunt,
        Float& fPrimaryPierce,
        Float& fPrimarySlash) const;
    Bool GetSecondaryShieldRatings(const IndexedString& sHandedness,
        Float& fSecondaryBlunt,
        Float& fSecondaryPierce,
        Float& fSecondarySlash) const;

    // Stat names
    static void InitAllStatNames();

    // Attack/defend counters
    MAKE_RAW_BASIC_TYPE_ACCESSORS(AttackCounter, Int);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(DefendCounter, Int);

    // Previous action types
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(PreviousActionTypes, IndexedStringArray);

    // IndexedString stats
    MAKE_STAT_TYPE_ACCESSORS(ActionSourceThisAction, IndexedString);
    MAKE_STAT_TYPE_ACCESSORS(MostRecentActionSource, IndexedString);

    // IndexedStringArray stats
    MAKE_STAT_TYPE_ACCESSORS(ActionTargetsThisAction, IndexedStringArray);
    MAKE_STAT_TYPE_ACCESSORS(ActionTargetsThisRound, IndexedStringArray);
    MAKE_STAT_TYPE_ACCESSORS(ActionTargetsLastRound, IndexedStringArray);
    MAKE_STAT_TYPE_ACCESSORS(ActionSourcesThisRound, IndexedStringArray);
    MAKE_STAT_TYPE_ACCESSORS(ActionSourcesLastRound, IndexedStringArray);
    MAKE_STAT_TYPE_ACCESSORS(MostRecentActionTargets, IndexedStringArray);

    // Bool stats
    MAKE_STAT_TYPE_ACCESSORS(IsDead, Bool);
    MAKE_STAT_TYPE_ACCESSORS(IsUnconscious, Bool);

    // Int stats
    MAKE_STAT_TYPE_ACCESSORS(AllowedTargetAmount, Int);
    MAKE_STAT_TYPE_ACCESSORS(DamageTakenThisRound, Int);
    MAKE_STAT_TYPE_ACCESSORS(DamageTakenThisBattle, Int);
    MAKE_STAT_TYPE_ACCESSORS(DamageGivenThisRound, Int);
    MAKE_STAT_TYPE_ACCESSORS(DamageGivenThisBattle, Int);

    // Float stats
    MAKE_STAT_TYPE_ACCESSORS(EquippedWeaponLeftBluntRating, Float);
    MAKE_STAT_TYPE_ACCESSORS(EquippedWeaponLeftPierceRating, Float);
    MAKE_STAT_TYPE_ACCESSORS(EquippedWeaponLeftSlashRating, Float);
    MAKE_STAT_TYPE_ACCESSORS(EquippedWeaponRightBluntRating, Float);
    MAKE_STAT_TYPE_ACCESSORS(EquippedWeaponRightPierceRating, Float);
    MAKE_STAT_TYPE_ACCESSORS(EquippedWeaponRightSlashRating, Float);
    MAKE_STAT_TYPE_ACCESSORS(EquippedShieldLeftBluntRating, Float);
    MAKE_STAT_TYPE_ACCESSORS(EquippedShieldLeftPierceRating, Float);
    MAKE_STAT_TYPE_ACCESSORS(EquippedShieldLeftSlashRating, Float);
    MAKE_STAT_TYPE_ACCESSORS(EquippedShieldLeftMagicRating, Float);
    MAKE_STAT_TYPE_ACCESSORS(EquippedShieldRightBluntRating, Float);
    MAKE_STAT_TYPE_ACCESSORS(EquippedShieldRightPierceRating, Float);
    MAKE_STAT_TYPE_ACCESSORS(EquippedShieldRightSlashRating, Float);
    MAKE_STAT_TYPE_ACCESSORS(EquippedShieldRightMagicRating, Float);
    MAKE_STAT_TYPE_ACCESSORS(EquippedArmorBluntRating, Float);
    MAKE_STAT_TYPE_ACCESSORS(EquippedArmorPierceRating, Float);
    MAKE_STAT_TYPE_ACCESSORS(EquippedArmorSlashRating, Float);
    MAKE_STAT_TYPE_ACCESSORS(EquippedArmorMagicRating, Float);
    MAKE_STAT_TYPE_ACCESSORS(ChanceToCauseCriticalHit, Float);
    MAKE_STAT_TYPE_ACCESSORS(ChanceToBlockCriticalHit, Float);
    MAKE_STAT_TYPE_ACCESSORS(CriticalHitMultiplier, Float);
    MAKE_STAT_TYPE_ACCESSORS(ChanceToApplyMultipleAttacks, Float);
    MAKE_STAT_TYPE_ACCESSORS(AttacksMultiplier, Float);
    MAKE_STAT_TYPE_ACCESSORS(WeaponPrimaryDamageBonusValue, Float);
    MAKE_STAT_TYPE_ACCESSORS(WeaponPrimaryDamageBonusPercent, Float);
    MAKE_STAT_TYPE_ACCESSORS(WeaponSecondaryDamageBonusValue, Float);
    MAKE_STAT_TYPE_ACCESSORS(WeaponSecondaryDamageBonusPercent, Float);
    MAKE_STAT_TYPE_ACCESSORS(GeneralDamageBonusValue, Float);
    MAKE_STAT_TYPE_ACCESSORS(GeneralDamageBonusPercent, Float);
    MAKE_STAT_TYPE_ACCESSORS(DefensivePowerEffectsBonusValue, Float);
    MAKE_STAT_TYPE_ACCESSORS(DefensivePowerEffectsBonusPercent, Float);
    MAKE_STAT_TYPE_ACCESSORS(OffensivePowerEffectsBonusValue, Float);
    MAKE_STAT_TYPE_ACCESSORS(OffensivePowerEffectsBonusPercent, Float);

    // Comparisons
    Bool operator==(const CharacterBattleData& other) const;
    Bool operator!=(const CharacterBattleData& other) const;
};

// Typedef
MAKE_TYPE_TYPEDEFS(CharacterBattleData);

// JSON Converters
void to_json(Json& jsonData, const CharacterBattleData& obj);
void from_json(const Json& jsonData, CharacterBattleData& obj);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_DECL(CharacterBattleData, CharacterBattleData);

};

#endif
