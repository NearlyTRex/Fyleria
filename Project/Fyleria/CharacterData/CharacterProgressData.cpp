// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "CharacterData/CharacterProgressData.h"
#include "CharacterData/CharacterDataTypes.h"
#include "Application/Application.h"
#include "Character/CharacterTypes.h"
#include "Stat/StatTypeTemplates.h"
#include "Utility/Templates.h"

namespace Gecko
{

CharacterProgressData::CharacterProgressData()
{
}

CharacterProgressData::CharacterProgressData(const Json& jsonData)
{
    from_json(jsonData, *this);
}

CharacterProgressData::~CharacterProgressData()
{
}

void CharacterProgressData::ApplyBaseToCurrent()
{
    // Segmented int stats
    APPLY_SEGMENTED_STAT_BASE_TO_CURRENT(HealthPoints);
    APPLY_SEGMENTED_STAT_BASE_TO_CURRENT(MagicPoints);
    APPLY_SEGMENTED_STAT_BASE_TO_CURRENT(EnergyPoints);
    APPLY_SEGMENTED_STAT_BASE_TO_CURRENT(HealthPointsMax);
    APPLY_SEGMENTED_STAT_BASE_TO_CURRENT(MagicPointsMax);
    APPLY_SEGMENTED_STAT_BASE_TO_CURRENT(EnergyPointsMax);
    APPLY_SEGMENTED_STAT_BASE_TO_CURRENT(HealthRegen);
    APPLY_SEGMENTED_STAT_BASE_TO_CURRENT(MagicRegen);
    APPLY_SEGMENTED_STAT_BASE_TO_CURRENT(EnergyRegen);
    APPLY_SEGMENTED_STAT_BASE_TO_CURRENT(Speed);
    APPLY_SEGMENTED_STAT_BASE_TO_CURRENT(BluntAttack);
    APPLY_SEGMENTED_STAT_BASE_TO_CURRENT(BluntDefense);
    APPLY_SEGMENTED_STAT_BASE_TO_CURRENT(PierceAttack);
    APPLY_SEGMENTED_STAT_BASE_TO_CURRENT(PierceDefense);
    APPLY_SEGMENTED_STAT_BASE_TO_CURRENT(SlashAttack);
    APPLY_SEGMENTED_STAT_BASE_TO_CURRENT(SlashDefense);
    APPLY_SEGMENTED_STAT_BASE_TO_CURRENT(MagicAttack);
    APPLY_SEGMENTED_STAT_BASE_TO_CURRENT(MagicDefense);
    APPLY_SEGMENTED_STAT_BASE_TO_CURRENT(EnergyAttack);
    APPLY_SEGMENTED_STAT_BASE_TO_CURRENT(EnergyDefense);
}

void CharacterProgressData::ApplyCurrentToBase()
{
    // Segmented int stats
    APPLY_SEGMENTED_STAT_CURRENT_TO_BASE(HealthPoints);
    APPLY_SEGMENTED_STAT_CURRENT_TO_BASE(MagicPoints);
    APPLY_SEGMENTED_STAT_CURRENT_TO_BASE(EnergyPoints);
    APPLY_SEGMENTED_STAT_CURRENT_TO_BASE(HealthPointsMax);
    APPLY_SEGMENTED_STAT_CURRENT_TO_BASE(MagicPointsMax);
    APPLY_SEGMENTED_STAT_CURRENT_TO_BASE(EnergyPointsMax);
    APPLY_SEGMENTED_STAT_CURRENT_TO_BASE(HealthRegen);
    APPLY_SEGMENTED_STAT_CURRENT_TO_BASE(MagicRegen);
    APPLY_SEGMENTED_STAT_CURRENT_TO_BASE(EnergyRegen);
    APPLY_SEGMENTED_STAT_CURRENT_TO_BASE(Speed);
    APPLY_SEGMENTED_STAT_CURRENT_TO_BASE(BluntAttack);
    APPLY_SEGMENTED_STAT_CURRENT_TO_BASE(BluntDefense);
    APPLY_SEGMENTED_STAT_CURRENT_TO_BASE(PierceAttack);
    APPLY_SEGMENTED_STAT_CURRENT_TO_BASE(PierceDefense);
    APPLY_SEGMENTED_STAT_CURRENT_TO_BASE(SlashAttack);
    APPLY_SEGMENTED_STAT_CURRENT_TO_BASE(SlashDefense);
    APPLY_SEGMENTED_STAT_CURRENT_TO_BASE(MagicAttack);
    APPLY_SEGMENTED_STAT_CURRENT_TO_BASE(MagicDefense);
    APPLY_SEGMENTED_STAT_CURRENT_TO_BASE(EnergyAttack);
    APPLY_SEGMENTED_STAT_CURRENT_TO_BASE(EnergyDefense);
}

void CharacterProgressData::ApplyHealthChange(Int iChange)
{
    // Apply health change
    Int iNewHP = ClipValue<Int>(GetHealthPointsCurrent() + iChange, 0, GetHealthPointsMaxCurrent());
    SetHealthPointsCurrent(iNewHP);
    SetHealthPointsBase(iNewHP);
}

void CharacterProgressData::ApplyMagicChange(Int iChange)
{
    // Apply magic change
    Int iNewMP = ClipValue<Int>(GetMagicPointsCurrent() + iChange, 0, GetMagicPointsMaxCurrent());
    SetMagicPointsCurrent(iNewMP);
    SetMagicPointsBase(iNewMP);
}

void CharacterProgressData::ApplyEnergyChange(Int iChange)
{
    // Apply energy change
    Int iNewEP = ClipValue<Int>(GetEnergyPointsCurrent() + iChange, 0, GetEnergyPointsMaxCurrent());
    SetEnergyPointsCurrent(iNewEP);
    SetEnergyPointsBase(iNewEP);
}

void CharacterProgressData::ApplyRegeneration(Bool bCanRegenHP, Bool bCanRegenMP, Bool bCanRegenEP)
{
    // Apply health change
    if(bCanRegenHP)
    {
        ApplyHealthChange(GetHealthRegenCurrent());
    }

    // Apply magic change
    if(bCanRegenMP)
    {
        ApplyMagicChange(GetMagicRegenCurrent());
    }

    // Apply energy change
    if(bCanRegenEP)
    {
        ApplyEnergyChange(GetEnergyRegenCurrent());
    }
}

Bool CharacterProgressData::CanRegenerate(const String& sCharacterID, const String& sRegenStatType) const
{
    // Get character
    const Character& character = GetManagers()->GetCharacterManager()->GetCharacter(sCharacterID);

    // Get character data
    const CharacterStatusEffectData& statusEffectData = character.GetStatusEffectData();

    // Check stat type
    const CharacterProgressDataType_Int eRegenStatType = GetEnumFromString<CharacterProgressDataType_Int>(sRegenStatType);
    switch(eRegenStatType)
    {
        case CharacterProgressDataType_Int::HealthRegenCurrent:
            return (!statusEffectData.GetIsDead());
        case CharacterProgressDataType_Int::MagicRegenCurrent:
            return (!statusEffectData.GetIsDead());
        case CharacterProgressDataType_Int::EnergyRegenCurrent:
            return true;
        default:
            break;
    }
    return false;
}

void CharacterProgressData::InitAllStatNames()
{
    // Initialize stat type names
    InitializeStatTypeNames<CharacterProgressDataType_Int>(GetIntStatNames());
}

Bool CharacterProgressData::operator==(const CharacterProgressData& other) const
{
    return (Json(*this) == Json(other));
}

Bool CharacterProgressData::operator!=(const CharacterProgressData& other) const
{
    return !operator==(other);
}

void to_json(Json& jsonData, const CharacterProgressData& obj)
{
    // Stat values
    SetJsonValuesFromStatTypeValues<CharacterProgressDataType_Int, Int>(jsonData, obj.GetIntStats());
}

void from_json(const Json& jsonData, CharacterProgressData& obj)
{
    // Stat values
    SetStatTypeValuesFromJsonValues<CharacterProgressDataType_Int, Int>(jsonData, obj.GetIntStats());
}

};
