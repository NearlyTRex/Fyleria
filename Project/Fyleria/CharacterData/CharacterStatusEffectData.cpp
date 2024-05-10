// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "CharacterData/CharacterStatusEffectData.h"
#include "CharacterData/CharacterDataTypes.h"
#include "Application/Application.h"
#include "Stat/StatTypeTemplates.h"
#include "Utility/Errors.h"
#include "Utility/JsonMacros.h"

namespace Gecko
{

CharacterStatusEffectData::CharacterStatusEffectData()
{
}

CharacterStatusEffectData::CharacterStatusEffectData(const Json& jsonData)
{
    from_json(jsonData, *this);
}

CharacterStatusEffectData::~CharacterStatusEffectData()
{
}

void CharacterStatusEffectData::UpdateStatus(const String& sCharacterID)
{
    // Get character
    const Character& character = GetManagers()->GetCharacterManager()->GetCharacter(sCharacterID);

    // Get character data
    const CharacterProgressData& progressData = character.GetProgressData();

    // Update status
    SetIsDead(progressData.GetHealthPointsCurrent() <= 0);
    SetIsUnconscious(progressData.GetMagicPointsCurrent() <= 0 || progressData.GetEnergyPointsCurrent() <= 0);
}

Bool CharacterStatusEffectData::HasStatus(const String& sStatusType) const
{
    const CharacterStatusType eStatusType = GetEnumFromStringOrNone<CharacterStatusType>(sStatusType);
    switch(eStatusType)
    {
        case CharacterStatusType::Acidified:
            return GetIsAcidified();
        case CharacterStatusType::Berserk:
            return GetIsBerserk();
        case CharacterStatusType::Bound:
            return GetIsBound();
        case CharacterStatusType::Bleeding:
            return GetIsBleeding();
        case CharacterStatusType::Blinded:
            return GetIsBlinded();
        case CharacterStatusType::Burned:
            return GetIsBurned();
        case CharacterStatusType::Calmed:
            return GetIsCalmed();
        case CharacterStatusType::Dead:
            return GetIsDead();
        case CharacterStatusType::Delirious:
            return GetIsDelirious();
        case CharacterStatusType::Frozen:
            return GetIsFrozen();
        case CharacterStatusType::Horrified:
            return GetIsHorrified();
        case CharacterStatusType::Knockdown:
            return GetIsKnockdown();
        case CharacterStatusType::Mossified:
            return GetIsMossified();
        case CharacterStatusType::Sleeping:
            return GetIsSleeping();
        case CharacterStatusType::Swallowed:
            return GetIsSwallowed();
        case CharacterStatusType::Unconscious:
            return GetIsUnconscious();
        default:
            break;
    }
    return false;
}

void CharacterStatusEffectData::InitAllStatNames()
{
    // Initialize stat type names
    InitializeStatTypeNames<CharacterStatusEffectDataType_Bool>(GetBoolStatNames());
}

Bool CharacterStatusEffectData::operator==(const CharacterStatusEffectData& other) const
{
    return (Json(*this) == Json(other));
}

Bool CharacterStatusEffectData::operator!=(const CharacterStatusEffectData& other) const
{
    return !operator==(other);
}

void to_json(Json& jsonData, const CharacterStatusEffectData& obj)
{
    // Bool stats
    SET_JSON_DATA(IsAcidified);
    SET_JSON_DATA(IsBerserk);
    SET_JSON_DATA(IsBound);
    SET_JSON_DATA(IsBleeding);
    SET_JSON_DATA(IsBlinded);
    SET_JSON_DATA(IsBurned);
    SET_JSON_DATA(IsCalmed);
    SET_JSON_DATA(IsDead);
    SET_JSON_DATA(IsDelirious);
    SET_JSON_DATA(IsFrozen);
    SET_JSON_DATA(IsHorrified);
    SET_JSON_DATA(IsKnockdown);
    SET_JSON_DATA(IsMossified);
    SET_JSON_DATA(IsSleeping);
    SET_JSON_DATA(IsSwallowed);
    SET_JSON_DATA(IsUnconscious);
}

void from_json(const Json& jsonData, CharacterStatusEffectData& obj)
{
    // Bool stats
    SET_OBJ_DATA(IsAcidified, Bool);
    SET_OBJ_DATA(IsBerserk, Bool);
    SET_OBJ_DATA(IsBound, Bool);
    SET_OBJ_DATA(IsBleeding, Bool);
    SET_OBJ_DATA(IsBlinded, Bool);
    SET_OBJ_DATA(IsBurned, Bool);
    SET_OBJ_DATA(IsCalmed, Bool);
    SET_OBJ_DATA(IsDead, Bool);
    SET_OBJ_DATA(IsDelirious, Bool);
    SET_OBJ_DATA(IsFrozen, Bool);
    SET_OBJ_DATA(IsHorrified, Bool);
    SET_OBJ_DATA(IsKnockdown, Bool);
    SET_OBJ_DATA(IsMossified, Bool);
    SET_OBJ_DATA(IsSleeping, Bool);
    SET_OBJ_DATA(IsSwallowed, Bool);
    SET_OBJ_DATA(IsUnconscious, Bool);
}

};
