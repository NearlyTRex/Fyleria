// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "CharacterData/CharacterBattleData.h"
#include "Character/CharacterTypes.h"
#include "Config/ConfigManager.h"
#include "Items/ItemTree.h"
#include "Items/ItemTypes.h"

namespace Gecko
{

CharacterBattleData::CharacterBattleData()
{
}

CharacterBattleData::CharacterBattleData(const Json& jsonData)
{
    from_json(jsonData, *this);
}

void CharacterBattleData::Clear()
{
    // Clear stat values
    RESET_STAT_TYPE_VALUES(CharacterBattleStatType, IndexedString);
    RESET_STAT_TYPE_VALUES(CharacterBattleStatType, IndexedStringArray);
    RESET_STAT_TYPE_VALUES(CharacterBattleStatType, Bool);
    RESET_STAT_TYPE_VALUES(CharacterBattleStatType, Int);
    RESET_STAT_TYPE_VALUES(CharacterBattleStatType, Float);
}

void CharacterBattleData::ApplyNewStatus(const CharacterProgressData& progressData)
{
    SetIsDead(progressData.GetHealthPointsCurrent() <= 0);
    SetIsUnconscious(progressData.GetMagicPointsCurrent() <= 0 || progressData.GetEnergyPointsCurrent() <= 0);
}

void CharacterBattleData::ApplyGivenDamage(Int iDamage)
{
    SetDamageGivenThisRound(GetDamageGivenThisRound() + abs(iDamage));
    SetDamageGivenThisBattle(GetDamageGivenThisBattle() + abs(iDamage));
}

void CharacterBattleData::ApplyTakenDamage(Int iDamage)
{
    SetDamageTakenThisRound(GetDamageTakenThisRound() + abs(iDamage));
    SetDamageTakenThisBattle(GetDamageTakenThisBattle() + abs(iDamage));
}

void CharacterBattleData::AdvanceRound(CharacterProgressData& progressData)
{
    // Apply regeneration
    Bool bCanRegenHP = CanRegenerateFromStat(IndexedString("HealthRegen"));
    Bool bCanRegenMP = CanRegenerateFromStat(IndexedString("MagicRegen"));
    Bool bCanRegenEP = CanRegenerateFromStat(IndexedString("EnergyRegen"));
    if(bCanRegenHP || bCanRegenMP || bCanRegenEP)
    {
        progressData.ApplyRegeneration(bCanRegenHP, bCanRegenMP, bCanRegenEP);
    }

    // Apply new status
    ApplyNewStatus(progressData);

    // Clear this round's damage
    SetDamageGivenThisRound(0);
    SetDamageTakenThisRound(0);

    // Move this round's targets to last round
    SetActionTargetsLastRound(GetActionTargetsThisRound());
    SetActionSourcesLastRound(GetActionSourcesThisRound());
    SetActionTargetsThisRound({});
    SetActionSourcesThisRound({});
}

void CharacterBattleData::FinishBattle(CharacterProgressData& progressData)
{
    // Update character health if they are "dead"
    if(GetIsDead())
    {
        progressData.SetHealthPointsCurrent(1);
    }

    // Apply new status
    ApplyNewStatus(progressData);

    // Apply regeneration
    Bool bCanRegenHP = CanRegenerateFromStat(IndexedString("HealthRegen"));
    Bool bCanRegenMP = CanRegenerateFromStat(IndexedString("MagicRegen"));
    Bool bCanRegenEP = CanRegenerateFromStat(IndexedString("EnergyRegen"));
    if(bCanRegenHP || bCanRegenMP || bCanRegenEP)
    {
        progressData.ApplyRegeneration(bCanRegenHP, bCanRegenMP, bCanRegenEP);
    }

    // Clear this battle's damage
    SetDamageGivenThisBattle(0);
    SetDamageTakenThisBattle(0);
}

Bool CharacterBattleData::CanRegenerateFromStat(const IndexedString& sRegenStat) const
{
    const CharacterProgressStatType_Int eProgressType = StringToCharacterProgressStatType_Int(sRegenStat);
    switch(eProgressType)
    {
        case CharacterProgressStatType_Int::HealthRegen:
            return (!GetIsDead());
        case CharacterProgressStatType_Int::MagicRegen:
            return (!GetIsDead());
        case CharacterProgressStatType_Int::EnergyRegen:
            return true;
        default:
            break;
    }
    return false;
}

void CharacterBattleData::UpdateEquipmentRatings(const IndexedString& sWeaponSet,
    const CharacterPartyEquippedItemArray& vEquippedItems,
    const CharacterProgressData& progressData)
{
    // Get weapon set
    const CharacterWeaponSetType eWeaponSetType = StringToCharacterWeaponSetType(sWeaponSet);
    const Bool bIsWeaponSetSelected1 = (eWeaponSetType == +CharacterWeaponSetType::WeaponSet1);
    const Bool bIsWeaponSetSelected2 = (eWeaponSetType == +CharacterWeaponSetType::WeaponSet2);

    // Look through equipped items and gather information
    Float fArmor_BluntDefendPercent = 0;
    Float fArmor_PierceDefendPercent = 0;
    Float fArmor_SlashDefendPercent = 0;
    Float fArmor_MagicDefendPercent = 0;
    Float fShieldLeft_BluntDefendPercent = 0;
    Float fShieldLeft_PierceDefendPercent = 0;
    Float fShieldLeft_SlashDefendPercent = 0;
    Float fShieldLeft_MagicDefendPercent = 0;
    Float fShieldRight_BluntDefendPercent = 0;
    Float fShieldRight_PierceDefendPercent = 0;
    Float fShieldRight_SlashDefendPercent = 0;
    Float fShieldRight_MagicDefendPercent = 0;
    Float fWeaponLeft_BluntAttackPercent = 0;
    Float fWeaponLeft_PierceAttackPercent = 0;
    Float fWeaponLeft_SlashAttackPercent = 0;
    Float fWeaponRight_BluntAttackPercent = 0;
    Float fWeaponRight_PierceAttackPercent = 0;
    Float fWeaponRight_SlashAttackPercent = 0;
    for(auto&& equippedItem : vEquippedItems)
    {
        const ItemTreeType eItemTreeType = StringToItemTreeType(equippedItem.GetTreeIndex().GetTree());
        const CharacterEquipmentType eEquipType = StringToCharacterEquipmentType(equippedItem.GetItemSlot());
        const Bool bValidEquipLeft =
            (bIsWeaponSetSelected1 && (eEquipType == +CharacterEquipmentType::Weapon1Left)) ||
            (bIsWeaponSetSelected2 && (eEquipType == +CharacterEquipmentType::Weapon2Left));
        const Bool bValidEquipRight =
            (bIsWeaponSetSelected1 && (eEquipType == +CharacterEquipmentType::Weapon1Right)) ||
            (bIsWeaponSetSelected2 && (eEquipType == +CharacterEquipmentType::Weapon2Right));
        switch(eItemTreeType)
        {
            case ItemTreeType::Armor:
            {
                const Bool bIsShield = IsItemShield(equippedItem.GetTreeIndex());
                const ItemDataArmor& itemArmor = RetrieveItemDataArmor(equippedItem.GetTreeIndex());
                if(bIsShield && bValidEquipLeft)
                {
                    fShieldLeft_BluntDefendPercent = itemArmor.GetBluntDefendPercent();
                    fShieldLeft_PierceDefendPercent = itemArmor.GetPierceDefendPercent();
                    fShieldLeft_SlashDefendPercent = itemArmor.GetSlashDefendPercent();
                    fShieldLeft_MagicDefendPercent = itemArmor.GetMagicDefendPercent();
                }
                else if(bIsShield && bValidEquipRight)
                {
                    fShieldRight_BluntDefendPercent = itemArmor.GetBluntDefendPercent();
                    fShieldRight_PierceDefendPercent = itemArmor.GetPierceDefendPercent();
                    fShieldRight_SlashDefendPercent = itemArmor.GetSlashDefendPercent();
                    fShieldRight_MagicDefendPercent = itemArmor.GetMagicDefendPercent();
                }
                else
                {
                    fArmor_BluntDefendPercent += itemArmor.GetBluntDefendPercent();
                    fArmor_PierceDefendPercent += itemArmor.GetPierceDefendPercent();
                    fArmor_SlashDefendPercent += itemArmor.GetSlashDefendPercent();
                    fArmor_MagicDefendPercent += itemArmor.GetMagicDefendPercent();
                }
                break;
            }
            case ItemTreeType::Weapon:
            {
                const ItemDataWeapon& itemWeapon = RetrieveItemDataWeapon(equippedItem.GetTreeIndex());
                if(bValidEquipLeft)
                {
                    fWeaponLeft_BluntAttackPercent = itemWeapon.GetBluntAttackPercent();
                    fWeaponLeft_PierceAttackPercent = itemWeapon.GetPierceAttackPercent();
                    fWeaponLeft_SlashAttackPercent = itemWeapon.GetSlashAttackPercent();
                }
                else if(bValidEquipRight)
                {
                    fWeaponRight_BluntAttackPercent = itemWeapon.GetBluntAttackPercent();
                    fWeaponRight_PierceAttackPercent = itemWeapon.GetPierceAttackPercent();
                    fWeaponRight_SlashAttackPercent = itemWeapon.GetSlashAttackPercent();
                }
                break;
            }
            default:
                break;
        }
    }

    // Fill out equipment ratings
    SetEquippedWeaponLeftBluntRating(fWeaponLeft_BluntAttackPercent * progressData.GetBluntAttack());
    SetEquippedWeaponLeftPierceRating(fWeaponLeft_PierceAttackPercent * progressData.GetPierceAttack());
    SetEquippedWeaponLeftSlashRating(fWeaponLeft_SlashAttackPercent * progressData.GetSlashAttack());
    SetEquippedWeaponRightBluntRating(fWeaponRight_BluntAttackPercent * progressData.GetBluntAttack());
    SetEquippedWeaponRightPierceRating(fWeaponRight_PierceAttackPercent * progressData.GetPierceAttack());
    SetEquippedWeaponRightSlashRating(fWeaponRight_SlashAttackPercent * progressData.GetSlashAttack());
    SetEquippedShieldLeftBluntRating(fShieldLeft_BluntDefendPercent * progressData.GetBluntDefense());
    SetEquippedShieldLeftPierceRating(fShieldLeft_PierceDefendPercent * progressData.GetPierceDefense());
    SetEquippedShieldLeftSlashRating(fShieldLeft_SlashDefendPercent * progressData.GetSlashDefense());
    SetEquippedShieldLeftMagicRating(fShieldLeft_MagicDefendPercent * progressData.GetMagicDefense());
    SetEquippedShieldRightBluntRating(fShieldRight_BluntDefendPercent * progressData.GetBluntDefense());
    SetEquippedShieldRightPierceRating(fShieldRight_PierceDefendPercent * progressData.GetPierceDefense());
    SetEquippedShieldRightSlashRating(fShieldRight_SlashDefendPercent * progressData.GetSlashDefense());
    SetEquippedShieldRightMagicRating(fShieldRight_MagicDefendPercent * progressData.GetMagicDefense());
    SetEquippedArmorBluntRating(fArmor_BluntDefendPercent * progressData.GetBluntDefense());
    SetEquippedArmorPierceRating(fArmor_PierceDefendPercent * progressData.GetPierceDefense());
    SetEquippedArmorSlashRating(fArmor_SlashDefendPercent * progressData.GetSlashDefense());
    SetEquippedArmorMagicRating(fArmor_MagicDefendPercent * progressData.GetMagicDefense());
}

IndexedStringArray CharacterBattleData::ResolveTargetPlaceholder(const IndexedString& sSelfTargetType,
    const IndexedString& sPlaceholderTargetType) const
{
    IndexedStringArray vTargets;
    const CharacterTargetType eTargetType = StringToCharacterTargetType(sPlaceholderTargetType);
    switch(eTargetType)
    {
        case CharacterTargetType::Self:
            vTargets.push_back(sSelfTargetType);
            break;
        case CharacterTargetType::ActionTargetsThisAction:
            vTargets = GetActionTargetsThisAction();
            break;
        case CharacterTargetType::ActionSourceThisAction:
            vTargets.push_back(GetActionSourceThisAction());
            break;
        case CharacterTargetType::ActionTargetsThisRound:
            vTargets = GetActionTargetsThisRound();
            break;
        case CharacterTargetType::ActionSourcesThisRound:
            vTargets = GetActionSourcesThisRound();
            break;
        case CharacterTargetType::ActionTargetsLastRound:
            vTargets = GetActionTargetsLastRound();
            break;
        case CharacterTargetType::ActionSourcesLastRound:
            vTargets = GetActionSourcesLastRound();
            break;
        case CharacterTargetType::MostRecentActionTargets:
            vTargets = GetMostRecentActionTargets();
            break;
        case CharacterTargetType::MostRecentActionSource:
            vTargets.push_back(GetMostRecentActionSource());
            break;
        default:
            break;
    }
    return vTargets;
}

Bool CharacterBattleData::GetPrimaryWeaponRatings(const IndexedString& sHandedness,
    Float& fPrimaryBlunt,
    Float& fPrimaryPierce,
    Float& fPrimarySlash) const
{
    const CharacterHandednessType eType = StringToCharacterHandednessType(sHandedness);
    switch(eType)
    {
        case CharacterHandednessType::LeftHanded:
            fPrimaryBlunt = GetEquippedWeaponLeftBluntRating();
            fPrimaryPierce = GetEquippedWeaponLeftPierceRating();
            fPrimarySlash = GetEquippedWeaponLeftSlashRating();
            return true;
        case CharacterHandednessType::RightHanded:
            fPrimaryBlunt = GetEquippedWeaponRightBluntRating();
            fPrimaryPierce = GetEquippedWeaponRightPierceRating();
            fPrimarySlash = GetEquippedWeaponRightSlashRating();
            return true;
        default:
            break;
    }
    return false;
}

Bool CharacterBattleData::GetSecondaryWeaponRatings(const IndexedString& sHandedness,
    Float& fSecondaryBlunt,
    Float& fSecondaryPierce,
    Float& fSecondarySlash) const
{
    const CharacterHandednessType eType = StringToCharacterHandednessType(sHandedness);
    switch(eType)
    {
        case CharacterHandednessType::LeftHanded:
            fSecondaryBlunt = GetEquippedWeaponRightBluntRating();
            fSecondaryPierce = GetEquippedWeaponRightPierceRating();
            fSecondarySlash = GetEquippedWeaponRightSlashRating();
            return true;
        case CharacterHandednessType::RightHanded:
            fSecondaryBlunt = GetEquippedWeaponLeftBluntRating();
            fSecondaryPierce = GetEquippedWeaponLeftPierceRating();
            fSecondarySlash = GetEquippedWeaponLeftSlashRating();
            return true;
        default:
            break;
    }
    return false;
}

Bool CharacterBattleData::GetPrimaryShieldRatings(const IndexedString& sHandedness,
    Float& fPrimaryBlunt,
    Float& fPrimaryPierce,
    Float& fPrimarySlash) const
{
    const CharacterHandednessType eType = StringToCharacterHandednessType(sHandedness);
    switch(eType)
    {
        case CharacterHandednessType::LeftHanded:
            fPrimaryBlunt = GetEquippedShieldLeftBluntRating();
            fPrimaryPierce = GetEquippedShieldLeftPierceRating();
            fPrimarySlash = GetEquippedShieldLeftSlashRating();
            return true;
        case CharacterHandednessType::RightHanded:
            fPrimaryBlunt = GetEquippedShieldRightBluntRating();
            fPrimaryPierce = GetEquippedShieldRightPierceRating();
            fPrimarySlash = GetEquippedShieldRightSlashRating();
            return true;
        default:
            break;
    }
    return false;
}

Bool CharacterBattleData::GetSecondaryShieldRatings(const IndexedString& sHandedness,
    Float& fSecondaryBlunt,
    Float& fSecondaryPierce,
    Float& fSecondarySlash) const
{
    const CharacterHandednessType eType = StringToCharacterHandednessType(sHandedness);
    switch(eType)
    {
        case CharacterHandednessType::LeftHanded:
            fSecondaryBlunt = GetEquippedShieldRightBluntRating();
            fSecondaryPierce = GetEquippedShieldRightPierceRating();
            fSecondarySlash = GetEquippedShieldRightSlashRating();
            return true;
        case CharacterHandednessType::RightHanded:
            fSecondaryBlunt = GetEquippedShieldLeftBluntRating();
            fSecondaryPierce = GetEquippedShieldLeftPierceRating();
            fSecondarySlash = GetEquippedShieldLeftSlashRating();
            return true;
        default:
            break;
    }
    return false;
}

static Bool s_bCharacterBattleData_StatNamesInitialized = false;
void CharacterBattleData::InitAllStatNames()
{
    // Check initialization
    if(s_bCharacterBattleData_StatNamesInitialized)
    {
        return;
    }

    // Initialize stat type names
    INITIALIZE_STAT_TYPE_NAMES(CharacterBattleStatType, IndexedString);
    INITIALIZE_STAT_TYPE_NAMES(CharacterBattleStatType, IndexedStringArray);
    INITIALIZE_STAT_TYPE_NAMES(CharacterBattleStatType, Bool);
    INITIALIZE_STAT_TYPE_NAMES(CharacterBattleStatType, Int);
    INITIALIZE_STAT_TYPE_NAMES(CharacterBattleStatType, Float);

    // Finished
    s_bCharacterBattleData_StatNamesInitialized = true;
}

Bool CharacterBattleData::operator==(const CharacterBattleData& other) const
{
    return (Json(*this) == Json(other));
}

Bool CharacterBattleData::operator!=(const CharacterBattleData& other) const
{
    return not operator==(other);
}

void to_json(Json& jsonData, const CharacterBattleData& obj)
{
    // Stat values
    SET_JSON_VALUES_FROM_STAT_TYPE_VALUES(CharacterBattleStatType, IndexedString);
    SET_JSON_VALUES_FROM_STAT_TYPE_VALUES(CharacterBattleStatType, IndexedStringArray);
    SET_JSON_VALUES_FROM_STAT_TYPE_VALUES(CharacterBattleStatType, Bool);
    SET_JSON_VALUES_FROM_STAT_TYPE_VALUES(CharacterBattleStatType, Int);
    SET_JSON_VALUES_FROM_STAT_TYPE_VALUES(CharacterBattleStatType, Float);
}

void from_json(const Json& jsonData, CharacterBattleData& obj)
{
    // Stat values
    SET_STAT_TYPE_VALUES_FROM_JSON_VALUES(CharacterBattleStatType, IndexedString);
    SET_STAT_TYPE_VALUES_FROM_JSON_VALUES(CharacterBattleStatType, IndexedStringArray);
    SET_STAT_TYPE_VALUES_FROM_JSON_VALUES(CharacterBattleStatType, Bool);
    SET_STAT_TYPE_VALUES_FROM_JSON_VALUES(CharacterBattleStatType, Int);
    SET_STAT_TYPE_VALUES_FROM_JSON_VALUES(CharacterBattleStatType, Float);
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(CharacterBattleData, CharacterBattleData);

};
