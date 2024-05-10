// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_CHARACTER_CHARACTER_H_
#define _GECKO_CHARACTER_CHARACTER_H_

// Internal includes
#include "Character/CharacterTypes.h"
#include "CharacterAction/CharacterAction.h"
#include "CharacterData/CharacterActionData.h"
#include "CharacterData/CharacterBasicData.h"
#include "CharacterData/CharacterBattleData.h"
#include "CharacterData/CharacterProgressData.h"
#include "CharacterData/CharacterMediaData.h"
#include "CharacterData/CharacterSkillData.h"
#include "CharacterData/CharacterStatChangeData.h"
#include "CharacterData/CharacterStatusEffectData.h"
#include "CharacterParty/CharacterPartyEquippedItem.h"

namespace Gecko
{

// Character class
class Character
{
public:

    // Constructors
    Character();
    Character(const Json& jsonData);
    Character(const String& jsonString);

    // Clear all data
    void Clear();

    // Regenerate character data
    void RegenerateAllCharacterData();
    void RegenerateSpecificCharacterData(const StringUnorderedSet& tOptions);
    void RegenerateSpecificCharacterData(const IntUnorderedSet& tOptions);

    // Get character ID
    String GetCharacterID() const;

    // Get party ID
    String GetPartyID() const;

    // Get character target type
    String GetCharacterTargetType() const;

    // Get weapon set
    String GetWeaponSet() const;

    // Get equipped items
    CharacterPartyEquippedItemArray GetEquippedItems() const;

    // Get individual equipped items by type
    TreeIndex GetEquippedItemByType(const String& sEquipmentType) const;

    // Get available actions
    const CharacterActionArray& GetAvailableActions() const;

    // Get passive changes
    const TreeIndexArray& GetPassiveChanges(const String& sTreeIndexType) const;

    // Get active changes
    const TreeIndexArray& GetActiveChanges(const String& sTreeIndexType) const;

    // Get actionable changes
    const TreeIndexArray& GetActionableChanges(const String& sTreeIndexType) const;

    // Get stat values
    template <class T>
    Bool GetStatValue(const String& sStat, T& varValue) const
    {
        const CharacterBasicData& basicData = GetBasicData();
        const CharacterSkillData& skillData = GetSkillData();
        const CharacterMediaData& mediaData = GetMediaData();
        const CharacterProgressData& progressData = GetProgressData();
        const CharacterBattleData& battleData = GetBattleData();
        return (basicData.GetStatValue(sStat, varValue) ||
                progressData.GetStatValue(sStat, varValue) ||
                battleData.GetStatValue(sStat, varValue) ||
                skillData.GetStatValue(sStat, varValue) ||
                mediaData.GetStatValue(sStat, varValue));
    }

    // Set stat values
    template <class T>
    Bool SetStatValue(const String& sStat, const T& varValue)
    {
        CharacterBasicData& basicData = GetBasicData();
        CharacterSkillData& skillData = GetSkillData();
        CharacterMediaData& mediaData = GetMediaData();
        CharacterProgressData& progressData = GetProgressData();
        CharacterBattleData& battleData = GetBattleData();
        return (basicData.SetStatValue(sStat, varValue) ||
                progressData.SetStatValue(sStat, varValue) ||
                battleData.SetStatValue(sStat, varValue) ||
                skillData.SetStatValue(sStat, varValue) ||
                mediaData.SetStatValue(sStat, varValue));
    }

    // Increment stat values
    template <class T>
    Bool IncrementStatValue(const String& sStat, const T& varValue)
    {
        CharacterBasicData& basicData = GetBasicData();
        CharacterSkillData& skillData = GetSkillData();
        CharacterMediaData& mediaData = GetMediaData();
        CharacterProgressData& progressData = GetProgressData();
        CharacterBattleData& battleData = GetBattleData();
        return (basicData.IncrementStatValue(sStat, varValue) ||
                progressData.IncrementStatValue(sStat, varValue) ||
                battleData.IncrementStatValue(sStat, varValue) ||
                skillData.IncrementStatValue(sStat, varValue) ||
                mediaData.IncrementStatValue(sStat, varValue));
    }

    // Decrement stat values
    template <class T>
    Bool DecrementStatValue(const String& sStat, const T& varValue)
    {
        CharacterBasicData& basicData = GetBasicData();
        CharacterSkillData& skillData = GetSkillData();
        CharacterMediaData& mediaData = GetMediaData();
        CharacterProgressData& progressData = GetProgressData();
        CharacterBattleData& battleData = GetBattleData();
        return (basicData.DecrementStatValue(sStat, varValue) ||
                progressData.DecrementStatValue(sStat, varValue) ||
                battleData.DecrementStatValue(sStat, varValue) ||
                skillData.DecrementStatValue(sStat, varValue) ||
                mediaData.DecrementStatValue(sStat, varValue));
    }

    // Update current stats
    // This pulls the base stats and applies them to the current stats
    void UpdateCurrentStats();

    // Update equipment ratings
    // This pulls equipment and current attack/defense percents and fills
    // ratings for all equipment
    void UpdateEquipmentRatings();

    // Update available passive and active changes
    // This pulls all earned skills and equipped items and generates a list
    // of active and passive changes that can be applied
    void UpdateAvailableChanges();

    // Update available actions
    // This polls the list of active changes and creates a list of
    // character actions that can be used as the basis for selectable actions
    void UpdateAvailableActions();

    // Update available AP
    // This searches the skills for ones that give AP and updates each type
    void UpdateAvailableAP();

    // Apply passive changes
    void ApplyPassiveChanges();

    // Apply active changes
    void ApplyActiveChanges(const CharacterAction& action);

    // Progress data
    MAKE_RAW_TYPE_ACCESSORS(ProgressData, CharacterProgressData);

    // Battle data
    MAKE_RAW_TYPE_ACCESSORS(BattleData, CharacterBattleData);

    // Basic data
    MAKE_RAW_TYPE_ACCESSORS(BasicData, CharacterBasicData);

    // Action data
    MAKE_RAW_TYPE_ACCESSORS(ActionData, CharacterActionData);

    // Skill data
    MAKE_RAW_TYPE_ACCESSORS(SkillData, CharacterSkillData);

    // Stat change data
    MAKE_RAW_TYPE_ACCESSORS(StatChangeData, CharacterStatChangeData);

    // Status effect data
    MAKE_RAW_TYPE_ACCESSORS(StatusEffectData, CharacterStatusEffectData);

    // Media data
    MAKE_RAW_TYPE_ACCESSORS(MediaData, CharacterMediaData);

    // Comparisons
    Bool operator==(const Character& other) const;
    Bool operator!=(const Character& other) const;
};

// Typedef
MAKE_COMMON_TYPEDEFS(Character);

// JSON Converters
void to_json(Json& jsonData, const Character& obj);
void from_json(const Json& jsonData, Character& obj);

// Get saveable data
Json GetSaveableData(const Character& obj);

// Comparisons
Bool operator==(const Character& a, const Character& b);

};

#endif
