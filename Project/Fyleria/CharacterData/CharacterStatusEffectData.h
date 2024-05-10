// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_CHARACTER_CHARACTER_STATUS_EFFECT_DATA_H_
#define _GECKO_CHARACTER_CHARACTER_STATUS_EFFECT_DATA_H_

// Internal includes
#include "Character/CharacterTypes.h"
#include "CharacterData/CharacterDataMacros.h"
#include "Stat/StatTypeHolder.h"

namespace Gecko
{

// Character status effect data
class CharacterStatusEffectData : public StatTypeHolder
{
public:

    // Constructors
    CharacterStatusEffectData();
    CharacterStatusEffectData(const Json& jsonData);

    // Destructor
    virtual ~CharacterStatusEffectData();

    // Update status
    void UpdateStatus(const String& sCharacterID);

    // Check if has status
    Bool HasStatus(const String& sStatusType) const;

    // Stat names
    static void InitAllStatNames();

    // Bool stats
    MAKE_STAT_TYPE_ACCESSORS(IsAcidified, Bool);
    MAKE_STAT_TYPE_ACCESSORS(IsBerserk, Bool);
    MAKE_STAT_TYPE_ACCESSORS(IsBound, Bool);
    MAKE_STAT_TYPE_ACCESSORS(IsBleeding, Bool);
    MAKE_STAT_TYPE_ACCESSORS(IsBlinded, Bool);
    MAKE_STAT_TYPE_ACCESSORS(IsBurned, Bool);
    MAKE_STAT_TYPE_ACCESSORS(IsCalmed, Bool);
    MAKE_STAT_TYPE_ACCESSORS(IsDead, Bool);
    MAKE_STAT_TYPE_ACCESSORS(IsDelirious, Bool);
    MAKE_STAT_TYPE_ACCESSORS(IsFrozen, Bool);
    MAKE_STAT_TYPE_ACCESSORS(IsHorrified, Bool);
    MAKE_STAT_TYPE_ACCESSORS(IsKnockdown, Bool);
    MAKE_STAT_TYPE_ACCESSORS(IsMossified, Bool);
    MAKE_STAT_TYPE_ACCESSORS(IsSleeping, Bool);
    MAKE_STAT_TYPE_ACCESSORS(IsSwallowed, Bool);
    MAKE_STAT_TYPE_ACCESSORS(IsUnconscious, Bool);

    // Comparisons
    Bool operator==(const CharacterStatusEffectData& other) const;
    Bool operator!=(const CharacterStatusEffectData& other) const;

};

// Typedef
MAKE_COMMON_TYPEDEFS(CharacterStatusEffectData);

// JSON Converters
void to_json(Json& jsonData, const CharacterStatusEffectData& obj);
void from_json(const Json& jsonData, CharacterStatusEffectData& obj);

};

#endif
