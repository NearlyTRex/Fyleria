// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_CHARACTER_CHARACTER_PROGRESS_DATA_H_
#define _GECKO_CHARACTER_CHARACTER_PROGRESS_DATA_H_

// Internal includes
#include "Character/CharacterTypes.h"
#include "CharacterData/CharacterDataMacros.h"
#include "Stat/StatTypeHolder.h"

namespace Gecko
{

// Character progress data
class CharacterProgressData : public StatTypeHolder
{
public:

    // Constructors
    CharacterProgressData();
    CharacterProgressData(const Json& jsonData);

    // Destructor
    virtual ~CharacterProgressData();

    // Apply segmented data
    void ApplyBaseToCurrent();
    void ApplyCurrentToBase();

    // Apply health change
    void ApplyHealthChange(Int iChange);

    // Apply magic change
    void ApplyMagicChange(Int iChange);

    // Apply energy change
    void ApplyEnergyChange(Int iChange);

    // Apply regeneration
    void ApplyRegeneration(Bool bCanRegenHP, Bool bCanRegenMP, Bool bCanRegenEP);

    // Can regenerate
    Bool CanRegenerate(const String& sCharacterID, const String& sRegenStatType) const;

    // Stat names
    static void InitAllStatNames();

    // Int stats
    MAKE_STAT_TYPE_ACCESSORS(HealthCostDelta, Int);
    MAKE_STAT_TYPE_ACCESSORS(MagicCostDelta, Int);
    MAKE_STAT_TYPE_ACCESSORS(EnergyCostDelta, Int);
    MAKE_STAT_TYPE_ACCESSORS(AmberValueDelta, Int);
    MAKE_STAT_TYPE_ACCESSORS(RubyValueDelta, Int);
    MAKE_STAT_TYPE_ACCESSORS(DiamondValueDelta, Int);
    MAKE_STAT_TYPE_ACCESSORS(CitrineValueDelta, Int);
    MAKE_STAT_TYPE_ACCESSORS(OnyxValueDelta, Int);
    MAKE_STAT_TYPE_ACCESSORS(QuartzValueDelta, Int);
    MAKE_STAT_TYPE_ACCESSORS(SapphireValueDelta, Int);
    MAKE_STAT_TYPE_ACCESSORS(AmethystValueDelta, Int);
    MAKE_STAT_TYPE_ACCESSORS(EmeraldValueDelta, Int);
    MAKE_STAT_TYPE_ACCESSORS(GarnetValueDelta, Int);
    MAKE_STAT_TYPE_ACCESSORS(IvoryValueDelta, Int);
    MAKE_STAT_TYPE_ACCESSORS(OpalValueDelta, Int);

    // Segmented int stats
    MAKE_STAT_TYPE_SEGMENTED_ACCESSORS(HealthPoints, Int);
    MAKE_STAT_TYPE_SEGMENTED_ACCESSORS(MagicPoints, Int);
    MAKE_STAT_TYPE_SEGMENTED_ACCESSORS(EnergyPoints, Int);
    MAKE_STAT_TYPE_SEGMENTED_ACCESSORS(HealthPointsMax, Int);
    MAKE_STAT_TYPE_SEGMENTED_ACCESSORS(MagicPointsMax, Int);
    MAKE_STAT_TYPE_SEGMENTED_ACCESSORS(EnergyPointsMax, Int);
    MAKE_STAT_TYPE_SEGMENTED_ACCESSORS(HealthRegen, Int);
    MAKE_STAT_TYPE_SEGMENTED_ACCESSORS(MagicRegen, Int);
    MAKE_STAT_TYPE_SEGMENTED_ACCESSORS(EnergyRegen, Int);
    MAKE_STAT_TYPE_SEGMENTED_ACCESSORS(Speed, Int);
    MAKE_STAT_TYPE_SEGMENTED_ACCESSORS(BluntAttack, Int);
    MAKE_STAT_TYPE_SEGMENTED_ACCESSORS(BluntDefense, Int);
    MAKE_STAT_TYPE_SEGMENTED_ACCESSORS(PierceAttack, Int);
    MAKE_STAT_TYPE_SEGMENTED_ACCESSORS(PierceDefense, Int);
    MAKE_STAT_TYPE_SEGMENTED_ACCESSORS(SlashAttack, Int);
    MAKE_STAT_TYPE_SEGMENTED_ACCESSORS(SlashDefense, Int);
    MAKE_STAT_TYPE_SEGMENTED_ACCESSORS(MagicAttack, Int);
    MAKE_STAT_TYPE_SEGMENTED_ACCESSORS(MagicDefense, Int);
    MAKE_STAT_TYPE_SEGMENTED_ACCESSORS(EnergyAttack, Int);
    MAKE_STAT_TYPE_SEGMENTED_ACCESSORS(EnergyDefense, Int);

    // Comparisons
    Bool operator==(const CharacterProgressData& other) const;
    Bool operator!=(const CharacterProgressData& other) const;
};

// Typedef
MAKE_COMMON_TYPEDEFS(CharacterProgressData);

// JSON Converters
void to_json(Json& jsonData, const CharacterProgressData& obj);
void from_json(const Json& jsonData, CharacterProgressData& obj);

};

#endif
