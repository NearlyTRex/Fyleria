// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_CHARACTER_CHARACTER_ACTION_DATA_H_
#define _GECKO_CHARACTER_CHARACTER_ACTION_DATA_H_

// Internal includes
#include "Character/CharacterTypes.h"
#include "CharacterAction/CharacterAction.h"
#include "CharacterData/CharacterDataMacros.h"
#include "Stat/StatTypeHolder.h"

namespace Gecko
{

// Character action data
class CharacterActionData : public StatTypeHolder
{
public:

    // Constructors
    CharacterActionData();
    CharacterActionData(const Json& jsonData);

    // Destructor
    virtual ~CharacterActionData();

    // Clear all data
    virtual void Clear();

    // Update available actions
    void UpdateAvailableActions(const String& sCharacterID);

    // Apply cost of action
    void ApplyActionCost(
        const String& sCharacterID,
        const CharacterAction& action);

    // Update available AP
    void UpdateAvailableAP(const String& sCharacterID);

    // Stat names
    static void InitAllStatNames();

    // Int stats
    MAKE_STAT_TYPE_ACCESSORS(SlashPoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(SeverPoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(SlicePoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(SlitPoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(CleavePoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(DecapitatePoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(ParryPoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(RipostePoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(BashPoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(SmashPoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(ImpactPoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(CrushPoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(BreakPoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(CrackPoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(BlockPoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(RushPoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(PiercePoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(DrillPoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(ShootPoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(ImpalePoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(StealthStrikePoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(CriticalShotPoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(DodgePoints, Int);
    MAKE_STAT_TYPE_ACCESSORS(CounterPoints, Int);

    // List of character actions
    MAKE_RAW_TYPE_ACCESSORS(AvailableActions, CharacterActionArray);

    // Comparisons
    Bool operator==(const CharacterActionData& other) const;
    Bool operator!=(const CharacterActionData& other) const;

private:

};

// Typedef
MAKE_COMMON_TYPEDEFS(CharacterActionData);

// JSON Converters
void to_json(Json& jsonData, const CharacterActionData& obj);
void from_json(const Json& jsonData, CharacterActionData& obj);

};

#endif
