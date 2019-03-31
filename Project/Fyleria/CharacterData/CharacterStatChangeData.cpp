// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "CharacterData/CharacterStatChangeData.h"

namespace Gecko
{

const TreeIndexList CharacterStatChangeData::s_vEmptyChanges = {};

CharacterStatChangeData::CharacterStatChangeData()
{
    // List of passive/active/actionable data
    GetPassiveSkillDataList().clear();
    GetActiveSkillDataList().clear();
    GetActionableSkillDataList().clear();
    GetPassiveItemDataList().clear();
    GetActiveItemDataList().clear();
    GetActionableItemDataList().clear();

    // Prolonged stat changes
    SetProlongedStatChanges({});
}

CharacterStatChangeData::~CharacterStatChangeData()
{
}

const TreeIndexList& CharacterStatChangeData::GetPassiveChanges(const IndexedString& sTreeIndexType) const
{
    const CharacterTreeIndexType eTreeIndexType = StringToCharacterTreeIndexType(sTreeIndexType);
    switch(eTreeIndexType)
    {
        case CharacterTreeIndexType::Skill:
            return GetPassiveSkillDataList();
        case CharacterTreeIndexType::Item:
            return GetPassiveItemDataList();
        default:
            break;
    }
    return s_vEmptyChanges;
}

const TreeIndexList& CharacterStatChangeData::GetActiveChanges(const IndexedString& sTreeIndexType) const
{
    const CharacterTreeIndexType eTreeIndexType = StringToCharacterTreeIndexType(sTreeIndexType);
    switch(eTreeIndexType)
    {
        case CharacterTreeIndexType::Skill:
            return GetActiveSkillDataList();
        case CharacterTreeIndexType::Item:
            return GetActiveItemDataList();
        default:
            break;
    }
    return s_vEmptyChanges;
}

const TreeIndexList& CharacterStatChangeData::GetActionableChanges(const IndexedString& sTreeIndexType) const
{
    const CharacterTreeIndexType eTreeIndexType = StringToCharacterTreeIndexType(sTreeIndexType);
    switch(eTreeIndexType)
    {
        case CharacterTreeIndexType::Skill:
            return GetActionableSkillDataList();
        case CharacterTreeIndexType::Item:
            return GetActionableItemDataList();
        default:
            break;
    }
    return s_vEmptyChanges;
}

void CharacterStatChangeData::AddProlongedStatChange(const IndexedString& sKey, const ProlongedStatChange& change)
{
    GetProlongedStatChanges()[sKey] = change;
}

Bool CharacterStatChangeData::RemoveProlongedStatChange(const IndexedString& sKey)
{
    return (GetProlongedStatChanges().erase(sKey) > 0);
}

ProlongedStatChange& CharacterStatChangeData::GetProlongedStatChange(const IndexedString& sKey)
{
    return (GetProlongedStatChanges().at(sKey));
}

const ProlongedStatChange& CharacterStatChangeData::GetProlongedStatChange(const IndexedString& sKey) const
{
    return (GetProlongedStatChanges().at(sKey));
}

StatChangeEntryList CharacterStatChangeData::GetProlongedStatChangeEntries() const
{
    // Find all prolonged stat change entries that match current conditions
    StatChangeEntryList vEntries;
    for(auto it = GetProlongedStatChanges().begin(); it != GetProlongedStatChanges().end(); it++)
    {
        // Ignore expired entries
        const IndexedString& sKey = IndexedString(it->first);
        if(HasProlongedStatChangeExpired(sKey))
        {
            continue;
        }

        // Find the only valid round/attack/defend and check if it matches
        const ProlongedStatChange& change = it->second;
        const StatChangeEntry& entry = change.GetStatChangeEntry();
        if(
            (change.IsValidRound() && change.GetRound() == BattleManager::GetInstance()->GetCurrentBattle().GetCurrentRoundIndex()) ||
            (change.IsValidAttack() && change.GetAttack() == GetAttackCounter()) ||
            (change.IsValidDefend() && change.GetDefend() == GetDefendCounter()))
        {
            vEntries.push_back(entry);
        }
    }
    return vEntries;
}

Bool CharacterStatChangeData::DoesProlongedStatChangeExist(const IndexedString& sKey) const
{
    return (GetProlongedStatChanges().find(sKey) != GetProlongedStatChanges().end());
}

Bool CharacterStatChangeData::HasProlongedStatChangeExpired(const IndexedString& sKey) const
{
    const ProlongedStatChange& change = GetProlongedStatChange(sKey);
    return (
        (change.IsValidRound() && change.GetRound() < BattleManager::GetInstance()->GetCurrentBattle().GetCurrentRoundIndex()) ||
        (change.IsValidAttack() && change.GetAttack() < GetAttackCounter()) ||
        (change.IsValidDefend() && change.GetDefend() < GetDefendCounter())
    );
}

void CharacterStatChangeData::RemoveAllExpiredProlongedStatChanges()
{
    IndexedStringList vKeys;
    for(auto it = GetProlongedStatChanges().begin(); it != GetProlongedStatChanges().end(); it++)
    {
        if(HasProlongedStatChangeExpired(IndexedString(it->first)))
        {
            vKeys.push_back(IndexedString(it->first));
        }
    }

    for(const IndexedString& sKey : vKeys)
    {
        RemoveProlongedStatChange(sKey);
    }
}

Bool CharacterStatChangeData::operator==(const CharacterStatChangeData& other) const
{
    return false;
}

Bool CharacterStatChangeData::operator!=(const CharacterStatChangeData& other) const
{
    return false;
}

void to_json(Json& jsonData, const CharacterStatChangeData& obj)
{
    // List of passive/active/actionable data
    SET_JSON_DATA_IF_NOT_EMPTY(PassiveSkillDataList);
    SET_JSON_DATA_IF_NOT_EMPTY(ActiveSkillDataList);
    SET_JSON_DATA_IF_NOT_EMPTY(ActionableSkillDataList);
    SET_JSON_DATA_IF_NOT_EMPTY(PassiveItemDataList);
    SET_JSON_DATA_IF_NOT_EMPTY(ActiveItemDataList);
    SET_JSON_DATA_IF_NOT_EMPTY(ActionableItemDataList);
}

void from_json(const Json& jsonData, CharacterStatChangeData& obj)
{
    // List of passive/active/actionable data
    obj.SetPassiveSkillDataList(GET_JSON_DATA_OR_DEFAULT(PassiveSkillDataList, TreeIndexList, TreeIndexList()));
    obj.SetActiveSkillDataList(GET_JSON_DATA_OR_DEFAULT(ActiveSkillDataList, TreeIndexList, TreeIndexList()));
    obj.SetActionableSkillDataList(GET_JSON_DATA_OR_DEFAULT(ActionableSkillDataList, TreeIndexList, TreeIndexList()));
    obj.SetPassiveItemDataList(GET_JSON_DATA_OR_DEFAULT(PassiveItemDataList, TreeIndexList, TreeIndexList()));
    obj.SetActiveItemDataList(GET_JSON_DATA_OR_DEFAULT(ActiveItemDataList, TreeIndexList, TreeIndexList()));
    obj.SetActionableItemDataList(GET_JSON_DATA_OR_DEFAULT(ActionableItemDataList, TreeIndexList, TreeIndexList()));
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(CharacterStatChangeData, CharacterStatChangeData);

};
