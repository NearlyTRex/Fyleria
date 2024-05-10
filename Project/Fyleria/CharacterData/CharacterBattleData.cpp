// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "CharacterData/CharacterBattleData.h"
#include "CharacterData/CharacterProgressData.h"
#include "CharacterData/CharacterStatusEffectData.h"
#include "CharacterData/CharacterDataTypes.h"
#include "Character/CharacterTypes.h"
#include "CharacterParty/CharacterPartyEquippedItem.h"
#include "Item/ItemTypes.h"
#include "Application/Application.h"

namespace Gecko
{

CharacterBattleData::CharacterBattleData()
{
}

CharacterBattleData::CharacterBattleData(const Json& jsonData)
{
    from_json(jsonData, *this);
}

CharacterBattleData::~CharacterBattleData()
{
}

void CharacterBattleData::ApplyGivenDamage(Int iDamage)
{
    // Apply given damage
    SetDamageGivenThisRound(GetDamageGivenThisRound() + abs(iDamage));
    SetDamageGivenThisBattle(GetDamageGivenThisBattle() + abs(iDamage));
}

void CharacterBattleData::ApplyTakenDamage(Int iDamage)
{
    // Apply taken damage
    SetDamageTakenThisRound(GetDamageTakenThisRound() + abs(iDamage));
    SetDamageTakenThisBattle(GetDamageTakenThisBattle() + abs(iDamage));
}

void CharacterBattleData::AdvanceRound(const String& sCharacterID)
{
    // Get character
    Character& character = GetManagers()->GetCharacterManager()->GetCharacter(sCharacterID);

    // Get character data
    CharacterProgressData& progressData = character.GetProgressData();
    CharacterStatusEffectData& statusEffectData = character.GetStatusEffectData();

    // Apply regeneration
    Bool bCanRegenHP = progressData.CanRegenerate(sCharacterID, GetEnumString(CharacterProgressDataType_Int::HealthRegenCurrent));
    Bool bCanRegenMP = progressData.CanRegenerate(sCharacterID, GetEnumString(CharacterProgressDataType_Int::MagicRegenCurrent));
    Bool bCanRegenEP = progressData.CanRegenerate(sCharacterID, GetEnumString(CharacterProgressDataType_Int::EnergyRegenCurrent));
    if(bCanRegenHP || bCanRegenMP || bCanRegenEP)
    {
        progressData.ApplyRegeneration(bCanRegenHP, bCanRegenMP, bCanRegenEP);
    }

    // Update status
    statusEffectData.UpdateStatus(sCharacterID);

    // Clear this round's damage
    SetDamageGivenThisRound(0);
    SetDamageTakenThisRound(0);

    // Move this round's targets to last round
    SetActionTargetsLastRound(GetActionTargetsThisRound());
    SetActionSourcesLastRound(GetActionSourcesThisRound());
    SetActionTargetsThisRound({});
    SetActionSourcesThisRound({});
}

void CharacterBattleData::FinishBattle(const String& sCharacterID)
{
    // Get character
    Character& character = GetManagers()->GetCharacterManager()->GetCharacter(sCharacterID);

    // Get character data
    CharacterProgressData& progressData = character.GetProgressData();
    CharacterStatusEffectData& statusEffectData = character.GetStatusEffectData();

    // Update character health if they are "dead"
    if(statusEffectData.GetIsDead())
    {
        progressData.SetHealthPointsCurrent(1);
    }

    // Update status
    statusEffectData.UpdateStatus(sCharacterID);

    // Apply regeneration
    Bool bCanRegenHP = progressData.CanRegenerate(sCharacterID, GetEnumString(CharacterProgressDataType_Int::HealthRegenCurrent));
    Bool bCanRegenMP = progressData.CanRegenerate(sCharacterID, GetEnumString(CharacterProgressDataType_Int::MagicRegenCurrent));
    Bool bCanRegenEP = progressData.CanRegenerate(sCharacterID, GetEnumString(CharacterProgressDataType_Int::EnergyRegenCurrent));
    if(bCanRegenHP || bCanRegenMP || bCanRegenEP)
    {
        progressData.ApplyRegeneration(bCanRegenHP, bCanRegenMP, bCanRegenEP);
    }

    // Clear this battle's damage
    SetDamageGivenThisBattle(0);
    SetDamageTakenThisBattle(0);
}

void CharacterBattleData::UpdateEquipmentRatings(const String& sCharacterID)
{
    // Get character
    const Character& character = GetManagers()->GetCharacterManager()->GetCharacter(sCharacterID);
    if(character.GetPartyID().empty())
    {
        return;
    }

    // Get equipped items
    const CharacterPartyEquippedItemArray vEquippedItems = character.GetEquippedItems();
    if(vEquippedItems.empty())
    {
        return;
    }

    // Get current weapon set
    const String& sWeaponSet = character.GetWeaponSet();
    if(sWeaponSet.empty())
    {
        return;
    }

    // Get weapon set info
    const CharacterWeaponSetType eWeaponSetType = GetEnumFromStringOrNone<CharacterWeaponSetType>(sWeaponSet);
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
        const ItemTreeType eItemTreeType = GetEnumFromString<ItemTreeType>(equippedItem.GetItemTreeIndex().GetTree());
        const CharacterEquipmentType eEquipType = GetEnumFromString<CharacterEquipmentType>(equippedItem.GetItemSlot());
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
                const Bool bIsShield = GetManagers()->GetItemManager()->IsItemShield(equippedItem.GetItemTreeIndex());
                const ItemDataArmor& itemArmor = GetManagers()->GetItemManager()->RetrieveItemDataArmor(equippedItem.GetItemTreeIndex());
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
                const ItemDataWeapon& itemWeapon = GetManagers()->GetItemManager()->RetrieveItemDataWeapon(equippedItem.GetItemTreeIndex());
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
    const CharacterProgressData& progressData = character.GetProgressData();
    SetEquippedWeaponLeftBluntRating(fWeaponLeft_BluntAttackPercent * progressData.GetBluntAttackCurrent());
    SetEquippedWeaponLeftPierceRating(fWeaponLeft_PierceAttackPercent * progressData.GetPierceAttackCurrent());
    SetEquippedWeaponLeftSlashRating(fWeaponLeft_SlashAttackPercent * progressData.GetSlashAttackCurrent());
    SetEquippedWeaponRightBluntRating(fWeaponRight_BluntAttackPercent * progressData.GetBluntAttackCurrent());
    SetEquippedWeaponRightPierceRating(fWeaponRight_PierceAttackPercent * progressData.GetPierceAttackCurrent());
    SetEquippedWeaponRightSlashRating(fWeaponRight_SlashAttackPercent * progressData.GetSlashAttackCurrent());
    SetEquippedShieldLeftBluntRating(fShieldLeft_BluntDefendPercent * progressData.GetBluntDefenseCurrent());
    SetEquippedShieldLeftPierceRating(fShieldLeft_PierceDefendPercent * progressData.GetPierceDefenseCurrent());
    SetEquippedShieldLeftSlashRating(fShieldLeft_SlashDefendPercent * progressData.GetSlashDefenseCurrent());
    SetEquippedShieldLeftMagicRating(fShieldLeft_MagicDefendPercent * progressData.GetMagicDefenseCurrent());
    SetEquippedShieldRightBluntRating(fShieldRight_BluntDefendPercent * progressData.GetBluntDefenseCurrent());
    SetEquippedShieldRightPierceRating(fShieldRight_PierceDefendPercent * progressData.GetPierceDefenseCurrent());
    SetEquippedShieldRightSlashRating(fShieldRight_SlashDefendPercent * progressData.GetSlashDefenseCurrent());
    SetEquippedShieldRightMagicRating(fShieldRight_MagicDefendPercent * progressData.GetMagicDefenseCurrent());
    SetEquippedArmorBluntRating(fArmor_BluntDefendPercent * progressData.GetBluntDefenseCurrent());
    SetEquippedArmorPierceRating(fArmor_PierceDefendPercent * progressData.GetPierceDefenseCurrent());
    SetEquippedArmorSlashRating(fArmor_SlashDefendPercent * progressData.GetSlashDefenseCurrent());
    SetEquippedArmorMagicRating(fArmor_MagicDefendPercent * progressData.GetMagicDefenseCurrent());
}

StringArray CharacterBattleData::ResolveTargetPlaceholder(const String& sSelfTargetType,
    const String& sPlaceholderTargetType) const
{
    StringArray vTargets;
    const CharacterTargetType eTargetType = GetEnumFromString<CharacterTargetType>(sPlaceholderTargetType);
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

Bool CharacterBattleData::GetPrimaryWeaponRatings(const String& sHandedness,
    Float& fPrimaryBlunt,
    Float& fPrimaryPierce,
    Float& fPrimarySlash) const
{
    const CharacterHandednessType eType = GetEnumFromString<CharacterHandednessType>(sHandedness);
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

Bool CharacterBattleData::GetSecondaryWeaponRatings(const String& sHandedness,
    Float& fSecondaryBlunt,
    Float& fSecondaryPierce,
    Float& fSecondarySlash) const
{
    const CharacterHandednessType eType = GetEnumFromString<CharacterHandednessType>(sHandedness);
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

Bool CharacterBattleData::GetPrimaryShieldRatings(const String& sHandedness,
    Float& fPrimaryBlunt,
    Float& fPrimaryPierce,
    Float& fPrimarySlash) const
{
    const CharacterHandednessType eType = GetEnumFromString<CharacterHandednessType>(sHandedness);
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

Bool CharacterBattleData::GetSecondaryShieldRatings(const String& sHandedness,
    Float& fSecondaryBlunt,
    Float& fSecondaryPierce,
    Float& fSecondarySlash) const
{
    const CharacterHandednessType eType = GetEnumFromString<CharacterHandednessType>(sHandedness);
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

void CharacterBattleData::InitAllStatNames()
{
    // Initialize stat type names
    InitializeStatTypeNames<CharacterBattleDataType_String>(GetStringStatNames());
    InitializeStatTypeNames<CharacterBattleDataType_StringArray>(GetStringArrayStatNames());
    InitializeStatTypeNames<CharacterBattleDataType_Bool>(GetBoolStatNames());
    InitializeStatTypeNames<CharacterBattleDataType_Int>(GetIntStatNames());
    InitializeStatTypeNames<CharacterBattleDataType_Float>(GetFloatStatNames());
}

Bool CharacterBattleData::operator==(const CharacterBattleData& other) const
{
    return (Json(*this) == Json(other));
}

Bool CharacterBattleData::operator!=(const CharacterBattleData& other) const
{
    return !operator==(other);
}

void to_json(Json& jsonData, const CharacterBattleData& obj)
{
    // Stat values
    SetJsonValuesFromStatTypeValues<CharacterBattleDataType_String, String>(jsonData, obj.GetStringStats());
    SetJsonValuesFromStatTypeValues<CharacterBattleDataType_StringArray, StringArray>(jsonData, obj.GetStringArrayStats());
    SetJsonValuesFromStatTypeValues<CharacterBattleDataType_Bool, Bool>(jsonData, obj.GetBoolStats());
    SetJsonValuesFromStatTypeValues<CharacterBattleDataType_Int, Int>(jsonData, obj.GetIntStats());
    SetJsonValuesFromStatTypeValues<CharacterBattleDataType_Float, Float>(jsonData, obj.GetFloatStats());
}

void from_json(const Json& jsonData, CharacterBattleData& obj)
{
    // Stat values
    SetStatTypeValuesFromJsonValues<CharacterBattleDataType_String, String>(jsonData, obj.GetStringStats());
    SetStatTypeValuesFromJsonValues<CharacterBattleDataType_StringArray, StringArray>(jsonData, obj.GetStringArrayStats());
    SetStatTypeValuesFromJsonValues<CharacterBattleDataType_Bool, Bool>(jsonData, obj.GetBoolStats());
    SetStatTypeValuesFromJsonValues<CharacterBattleDataType_Int, Int>(jsonData, obj.GetIntStats());
    SetStatTypeValuesFromJsonValues<CharacterBattleDataType_Float, Float>(jsonData, obj.GetFloatStats());
}

};
