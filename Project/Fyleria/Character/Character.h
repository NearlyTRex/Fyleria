// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_CHARACTER_H_
#define _GECKO_CHARACTER_H_

#include "Character/CharacterTypes.h"
#include "CharacterAction/CharacterAction.h"
#include "CharacterData/CharacterActionData.h"
#include "CharacterData/CharacterBasicData.h"
#include "CharacterData/CharacterBattleData.h"
#include "CharacterData/CharacterProgressData.h"
#include "CharacterData/CharacterSkillData.h"
#include "CharacterData/CharacterSkillUseData.h"
#include "CharacterData/CharacterStatChangeData.h"
#include "Module/ModuleResultManager.h"
#include "Items/ItemTree.h"
#include "Skills/SkillTree.h"

namespace Gecko
{

class Character
{
public:

    // Constructors
    Character();

    // Regenerate character data
    void RegenerateCharacterData(
        Bool bUpdateSkillRankings = true,
        Bool bUpdateEquipmentRatings = true,
        Bool bUpdateAvailableChanges = true,
        Bool bUpdateAvailableActions = true,
        Bool bUpdateAvailableAP = true
    );

    // Get character ID
    const IndexedString& GetCharacterID() const;
    MAKE_MODULE_RESULT_VARIANT(GetCharacterID);

    // Get party ID
    const IndexedString& GetPartyID() const;
    MAKE_MODULE_RESULT_VARIANT(GetPartyID);

    // Get character target type
    const IndexedString& GetCharacterTargetType() const;
    MAKE_MODULE_RESULT_VARIANT(GetCharacterTargetType);

    // Get progress data segment
    const CharacterProgressData& GetProgressDataSegment(const IndexedString& sSegment) const;
    CharacterProgressData& GetProgressDataSegment(const IndexedString& sSegment);
    MAKE_MODULE_RESULT_VARIANT_A1(GetProgressDataSegment, const IndexedString&, sSegment);

    // Get battle data segment
    const CharacterBattleData& GetBattleDataSegment(const IndexedString& sSegment) const;
    CharacterBattleData& GetBattleDataSegment(const IndexedString& sSegment);
    MAKE_MODULE_RESULT_VARIANT_A1(GetBattleDataSegment, const IndexedString&, sSegment);

    // Stat values
    MAKE_SEGMENTED_STAT_VALUE_ACCESSORS(Bool);
    MAKE_SEGMENTED_STAT_VALUE_ACCESSORS(Int);
    MAKE_SEGMENTED_STAT_VALUE_ACCESSORS(Float);
    MAKE_SEGMENTED_STAT_VALUE_ACCESSORS(IndexedString);
    MAKE_SEGMENTED_STAT_VALUE_ACCESSORS(IndexedStringArray);

    // Update equipment ratings
    // This pulls equipment and current attack/defense percents and fills
    // ratings for all equipment
    void UpdateEquipmentRatings(const IndexedString& sSegment);

    // Update available passive and active changes
    // This pulls all earned skills and equipped items and generates a list
    // of active and passive changes that can be applied
    void UpdateAvailableChanges(const IndexedString& sSegment);

    // Update available actions
    // This polls the list of active changes and creates a list of
    // character actions that can be used as the basis for selectable actions
    void UpdateAvailableActions(const IndexedString& sSegment);

    // Update available AP
    // This searches the skills for ones that give AP and updates each type
    void UpdateAvailableAP(const IndexedString& sSegment);

    // Update skill rankings
    // This searches through the skill uses and upgrades ranks if necessary
    void UpdateSkillRankings(const IndexedString& sSegment);

    // Apply passive changes
    // Copy base data into passive data and apply each passive stat change
    void ApplyPassiveChanges();

    // Apply active changes
    // Copy passive data into active data and apply each active stat change
    void ApplyActiveChanges(const CharacterAction& action);

    // Clear active changes
    void ClearActiveChanges();

    // Progress data
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ProgressDataBase, CharacterProgressData);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ProgressDataPassives, CharacterProgressData);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ProgressDataActives, CharacterProgressData);
    MAKE_MODULE_RESULT_VARIANT(GetProgressDataBase);
    MAKE_MODULE_RESULT_VARIANT(GetProgressDataPassives);
    MAKE_MODULE_RESULT_VARIANT(GetProgressDataActives);

    // Battle data
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(BattleDataBase, CharacterBattleData);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(BattleDataPassives, CharacterBattleData);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(BattleDataActives, CharacterBattleData);
    MAKE_MODULE_RESULT_VARIANT(GetBattleDataBase);
    MAKE_MODULE_RESULT_VARIANT(GetBattleDataPassives);
    MAKE_MODULE_RESULT_VARIANT(GetBattleDataActives);

    // Basic data
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(BasicData, CharacterBasicData);
    MAKE_MODULE_RESULT_VARIANT(GetBasicData);

    // Action data
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ActionData, CharacterActionData);
    MAKE_MODULE_RESULT_VARIANT(GetActionData);

    // Skill data
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillData, CharacterSkillData);
    MAKE_MODULE_RESULT_VARIANT(GetSkillData);

    // Skill use data
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillUseData, CharacterSkillUseData);
    MAKE_MODULE_RESULT_VARIANT(GetSkillUseData);

    // Stat change data
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(StatChangeData, CharacterStatChangeData);
    MAKE_MODULE_RESULT_VARIANT(GetStatChangeData);

    // Comparisons
    Bool operator==(const Character& other) const;
    Bool operator!=(const Character& other) const;
};

// Typedef
MAKE_TYPE_TYPEDEFS(Character);

// JSON Converters
void to_json(Json& jsonData, const Character& obj);
void from_json(const Json& jsonData, Character& obj);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_DECL(Character, Character);

// Comparisons
Bool operator==(const Character& a, const Character& b);

};

#endif
