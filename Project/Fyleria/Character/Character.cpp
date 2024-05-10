// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Character/Character.h"
#include "Character/CharacterTypes.h"
#include "Item/ItemTypes.h"
#include "Application/Application.h"
#include "Utility/Errors.h"
#include "Utility/Enum.h"
#include "Utility/JsonMacros.h"

namespace Gecko
{

Character::Character()
{
}

Character::Character(const Json& jsonData)
{
    from_json(jsonData, *this);
}

Character::Character(const String& jsonString)
{
    from_json(JsonParse(jsonString), *this);
}

void Character::Clear()
{
    // Progress data
    GetProgressData().Clear();

    // Battle data
    GetBattleData().Clear();

    // Basic data
    GetBasicData().Clear();

    // Action data
    GetActionData().Clear();

    // Skill data
    GetSkillData().Clear();

    // Stat change data
    GetStatChangeData().Clear();
}

void Character::RegenerateAllCharacterData()
{
    // Regenerate all character data
    RegenerateSpecificCharacterData({
        CharacterRegenerationType::CurrentStats,
        CharacterRegenerationType::EquipmentRatings,
        CharacterRegenerationType::AvailableChanges,
        CharacterRegenerationType::AvailableActions,
        CharacterRegenerationType::AvailableAP
    });
}

void Character::RegenerateSpecificCharacterData(const StringUnorderedSet& tOptions)
{
    // Create translated options
    IntUnorderedSet tTranslatedOptions;
    for(auto& sRegenerationType : GetUsableEnumNames<CharacterRegenerationType>())
    {
        if (tOptions.count(sRegenerationType))
        {
            tTranslatedOptions.insert(GetEnumFromString<CharacterRegenerationType>(sRegenerationType));
        }
    }

    // Regenerate character data
    RegenerateSpecificCharacterData(tTranslatedOptions);
}

void Character::RegenerateSpecificCharacterData(const IntUnorderedSet& tOptions)
{
    // Update character data
    if (tOptions.count(CharacterRegenerationType::CurrentStats)) { UpdateCurrentStats(); }
    if (tOptions.count(CharacterRegenerationType::EquipmentRatings)) { UpdateEquipmentRatings(); }
    if (tOptions.count(CharacterRegenerationType::AvailableChanges)) { UpdateAvailableChanges(); }
    if (tOptions.count(CharacterRegenerationType::AvailableActions)) { UpdateAvailableActions(); }
    if (tOptions.count(CharacterRegenerationType::AvailableAP)) { UpdateAvailableAP(); }

    // Apply passives
    ApplyPassiveChanges();

    // Display the new data
#ifdef DEBUG
    Json jsonData = *this;
    LOG_FORMAT_STATEMENT("Completed regenerating character data (CharacterID = '{}'):\n{}\n",
        GetBasicData().GetCharacterID().c_str(),
        jsonData.dump(4).c_str());
#endif
}

String Character::GetCharacterID() const
{
    return GetBasicData().GetCharacterID();
}

String Character::GetPartyID() const
{
    return GetBasicData().GetPartyID();
}

String Character::GetCharacterTargetType() const
{
    // Get character and party ID
    String sCharacterID = GetCharacterID();
    String sPartyID = GetPartyID();
    if(sPartyID.empty())
    {
        return GetNoneTypeForEnum<CharacterResolvedTargetType>();
    }

    // Get target type
    const CharacterParty& characterParty = GetManagers()->GetCharacterPartyManager()->GetPartyByID(sPartyID);
    const CharacterPartyMember& characterPartyMember = characterParty.GetMemberByID(sCharacterID);
    return characterPartyMember.GetCharacterTargetType();
}

String Character::GetWeaponSet() const
{
    return GetBasicData().GetWeaponSet();
}

CharacterPartyEquippedItemArray Character::GetEquippedItems() const
{
    // Get character and party ID
    String sCharacterID = GetCharacterID();
    String sPartyID = GetPartyID();
    if(sPartyID.empty())
    {
        return CharacterPartyEquippedItemArray();
    }

    // Get equipped items
    const CharacterParty& characterParty = GetManagers()->GetCharacterPartyManager()->GetPartyByID(sPartyID);
    const CharacterPartyMember& characterPartyMember = characterParty.GetMemberByID(sCharacterID);
    return characterPartyMember.GetEquippedItems();
}

TreeIndex Character::GetEquippedItemByType(const String& sEquipmentType) const
{
    auto vEquippedItems = GetEquippedItems();
    if(vEquippedItems.empty())
    {
        return TreeIndex();
    }
    for(auto it = vEquippedItems.begin(); it != vEquippedItems.end(); it++)
    {
        if(it->GetItemSlot() == sEquipmentType)
        {
            return it->GetItemTreeIndex();
        }
    }
    return TreeIndex();
}

const CharacterActionArray& Character::GetAvailableActions() const
{
    return GetActionData().GetAvailableActions();
}

const TreeIndexArray& Character::GetPassiveChanges(const String& sTreeIndexType) const
{
    return GetStatChangeData().GetPassiveChanges(sTreeIndexType);
}

const TreeIndexArray& Character::GetActiveChanges(const String& sTreeIndexType) const
{
    return GetStatChangeData().GetActiveChanges(sTreeIndexType);
}

const TreeIndexArray& Character::GetActionableChanges(const String& sTreeIndexType) const
{
    return GetStatChangeData().GetActionableChanges(sTreeIndexType);
}

void Character::UpdateCurrentStats()
{
    // Update current stats
    GetProgressData().ApplyBaseToCurrent();
}

void Character::UpdateEquipmentRatings()
{
    // Update equipment ratings
    GetBattleData().UpdateEquipmentRatings(GetCharacterID());
}

void Character::UpdateAvailableChanges()
{
    // Update available changes
    GetStatChangeData().UpdateAvailableChanges(GetCharacterID());
}

void Character::UpdateAvailableActions()
{
    // Update available actions
    GetActionData().UpdateAvailableActions(GetCharacterID());
}

void Character::UpdateAvailableAP()
{
    // Update available AP
    GetActionData().UpdateAvailableAP(GetCharacterID());
}

void Character::ApplyPassiveChanges()
{
    // Apply passives
    for(auto& sTreeIndexType : GetUsableEnumNames<CharacterTreeIndexType>())
    {
        for(const TreeIndex& treeIndex : GetStatChangeData().GetPassiveChanges(sTreeIndexType))
        {
            for(StatChange change : GetStatChangesFromTreeIndex(sTreeIndexType, treeIndex))
            {
                // Resolve target placeholders
                change.ResolveTargetPlaceholders(GetCharacterID());

                // Apply change
                Bool bAllChangesApplied = false;
                Bool bAtLeastOneChange = false;
                GetManagers()->GetCharacterManager()->ApplyStatChange(change, bAllChangesApplied, bAtLeastOneChange);
            }
        }
    }
}

void Character::ApplyActiveChanges(const CharacterAction& action)
{
    // Apply actives
    for(auto& sTreeIndexType : GetUsableEnumNames<CharacterTreeIndexType>())
    {
        for(const TreeIndex& treeIndex : GetStatChangeData().GetActiveChanges(sTreeIndexType))
        {
            for(const StatChange& change : GetStatChangesFromTreeIndex(sTreeIndexType, treeIndex))
            {
                // Ignore active changes that do not meet requirements
                if(!change.DoesMeetActiveRequirements(
                    GetCharacterID(), GetCharacterTargetType(), GetWeaponSet(), action))
                {
                    continue;
                }

                // Make a local copy now that we have passed the check
                StatChange localStatChange(change);

                // Resolve target placeholders
                localStatChange.ResolveTargetPlaceholders(GetCharacterID());

                // Apply change
                Bool bAllChangesApplied = false;
                Bool bAtLeastOneChange = false;
                GetManagers()->GetCharacterManager()->ApplyStatChange(localStatChange, bAllChangesApplied, bAtLeastOneChange);
            }
        }
    }

    // Apply prolonged stat changes
    GetStatChangeData().ApplyProlongedStatChanges(GetCharacterID());
}

Bool Character::operator==(const Character& other) const
{
    return (Json(*this) == Json(other));
}

Bool Character::operator!=(const Character& other) const
{
    return !operator==(other);
}

void to_json(Json& jsonData, const Character& obj)
{
    // Progress data
    SET_JSON_DATA(ProgressData);

    // Battle data
    SET_JSON_DATA(BattleData);

    // Basic data
    SET_JSON_DATA(BasicData);

    // Action data
    SET_JSON_DATA(ActionData);

    // Skill data
    SET_JSON_DATA(SkillData);

    // Stat change data
    SET_JSON_DATA(StatChangeData);

    // Status effect data
    SET_JSON_DATA(StatusEffectData);

    // Media data
    SET_JSON_DATA(MediaData);
}

void from_json(const Json& jsonData, Character& obj)
{
    // Progress data
    SET_OBJ_DATA(ProgressData, CharacterProgressData);

    // Battle data
    SET_OBJ_DATA(BattleData, CharacterBattleData);

    // Basic data
    SET_OBJ_DATA(BasicData, CharacterBasicData);

    // Action data
    SET_OBJ_DATA(ActionData, CharacterActionData);

    // Skill data
    SET_OBJ_DATA(SkillData, CharacterSkillData);

    // Stat change data
    SET_OBJ_DATA(StatChangeData, CharacterStatChangeData);

    // Status effect data
    SET_OBJ_DATA(StatusEffectData, CharacterStatusEffectData);

    // Media data
    SET_OBJ_DATA(MediaData, CharacterMediaData);
}

Json GetSaveableData(const Character& obj)
{
    // Ouput data
    Json jsonData;

    // Progress data
    SET_JSON_DATA(ProgressData);

    // Basic data
    SET_JSON_DATA(BasicData);

    // Skill data
    SET_JSON_DATA(SkillData);

    // Status effect data
    SET_JSON_DATA(StatusEffectData);

    // Media data
    SET_JSON_DATA(MediaData);

    // Return saveable data
    return jsonData;
}

Bool operator==(const Character& a, const Character& b)
{
    return (a.GetBasicData().GetCharacterID() == b.GetBasicData().GetCharacterID());
}

};
