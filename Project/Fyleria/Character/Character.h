// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_CHARACTER_H_
#define _GECKO_CHARACTER_H_

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
#include "CharacterParty/CharacterPartyEquippedItem.h"

namespace Gecko
{

// Manager set
class ManagerSet;

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
    void RegenerateCharacterData(
        SafeObject<ManagerSet>& pManagerSet,
        Bool bUpdateEquipmentRatings = true,
        Bool bUpdateAvailableChanges = true,
        Bool bUpdateAvailableActions = true,
        Bool bUpdateAvailableAP = true
    );

    // Get character ID
    String GetCharacterID() const;

    // Get party ID
    String GetPartyID() const;

    // Get character target type
    String GetCharacterTargetType(SafeObject<ManagerSet>& pManagerSet) const;

    // Get weapon set
    String GetWeaponSet() const;

    // Get equipped items
    CharacterPartyEquippedItemArray GetEquippedItems(SafeObject<ManagerSet>& pManagerSet) const;

    // Get individual equipped items by type
    TreeIndex GetEquippedItemByType(SafeObject<ManagerSet>& pManagerSet, const String& sEquipmentType) const;

    // Get available actions
    const CharacterActionArray& GetAvailableActions() const;

    // Get passive changes
    const TreeIndexArray& GetPassiveChanges(const String& sTreeIndexType) const;

    // Get active changes
    const TreeIndexArray& GetActiveChanges(const String& sTreeIndexType) const;

    // Get actionable changes
    const TreeIndexArray& GetActionableChanges(const String& sTreeIndexType) const;

    // Get progress data segment
    const CharacterProgressData& GetProgressDataSegment(const String& sSegment) const;
    CharacterProgressData& GetProgressDataSegment(const String& sSegment);

    // Get battle data segment
    const CharacterBattleData& GetBattleDataSegment(const String& sSegment) const;
    CharacterBattleData& GetBattleDataSegment(const String& sSegment);

    // Get stat values
    template <class T>
    Bool GetStatValue(const String& sSegment, const String& sStat, T& varValue) const
    {
        const CharacterBasicData& basicData = GetBasicData();
        const CharacterSkillData& skillData = GetSkillData();
        const CharacterMediaData& mediaData = GetMediaData();
        const CharacterProgressData& progressData = GetProgressDataSegment(sSegment);
        const CharacterBattleData& battleData = GetBattleDataSegment(sSegment);
        return (basicData.GetStatValue(sStat, varValue) ||
                progressData.GetStatValue(sStat, varValue) ||
                battleData.GetStatValue(sStat, varValue) ||
                skillData.GetStatValue(sStat, varValue) ||
                mediaData.GetStatValue(sStat, varValue));
    }

    // Set stat values
    template <class T>
    Bool SetStatValue(const String& sSegment, const String& sStat, const T& varValue)
    {
        CharacterBasicData& basicData = GetBasicData();
        CharacterSkillData& skillData = GetSkillData();
        CharacterMediaData& mediaData = GetMediaData();
        CharacterProgressData& progressData = GetProgressDataSegment(sSegment);
        CharacterBattleData& battleData = GetBattleDataSegment(sSegment);
        return (basicData.SetStatValue(sStat, varValue) ||
                progressData.SetStatValue(sStat, varValue) ||
                battleData.SetStatValue(sStat, varValue) ||
                skillData.SetStatValue(sStat, varValue) ||
                mediaData.SetStatValue(sStat, varValue));
    }

    // Update equipment ratings
    // This pulls equipment and current attack/defense percents and fills
    // ratings for all equipment
    void UpdateEquipmentRatings(SafeObject<ManagerSet>& pManagerSet);

    // Update available passive and active changes
    // This pulls all earned skills and equipped items and generates a list
    // of active and passive changes that can be applied
    void UpdateAvailableChanges(SafeObject<ManagerSet>& pManagerSet);

    // Update available actions
    // This polls the list of active changes and creates a list of
    // character actions that can be used as the basis for selectable actions
    void UpdateAvailableActions(SafeObject<ManagerSet>& pManagerSet);

    // Update available AP
    // This searches the skills for ones that give AP and updates each type
    void UpdateAvailableAP(SafeObject<ManagerSet>& pManagerSet);

    // Apply passive changes
    // Copy base data into passive data and apply each passive stat change
    void ApplyPassiveChanges(SafeObject<ManagerSet>& pManagerSet);

    // Apply active changes
    // Copy passive data into active data and apply each active stat change
    void ApplyActiveChanges(SafeObject<ManagerSet>& pManagerSet, const CharacterAction& action);

    // Clear active changes
    void ClearActiveChanges();

    // Progress data
    MAKE_RAW_TYPE_ACCESSORS(ProgressData, CharacterProgressData);
    MAKE_RAW_TYPE_ACCESSORS(ProgressDataPassives, CharacterProgressData);
    MAKE_RAW_TYPE_ACCESSORS(ProgressDataActives, CharacterProgressData);

    // Battle data
    MAKE_RAW_TYPE_ACCESSORS(BattleData, CharacterBattleData);
    MAKE_RAW_TYPE_ACCESSORS(BattleDataPassives, CharacterBattleData);
    MAKE_RAW_TYPE_ACCESSORS(BattleDataActives, CharacterBattleData);

    // Basic data
    MAKE_RAW_TYPE_ACCESSORS(BasicData, CharacterBasicData);

    // Action data
    MAKE_RAW_TYPE_ACCESSORS(ActionData, CharacterActionData);

    // Skill data
    MAKE_RAW_TYPE_ACCESSORS(SkillData, CharacterSkillData);

    // Stat change data
    MAKE_RAW_TYPE_ACCESSORS(StatChangeData, CharacterStatChangeData);

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
