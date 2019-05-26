// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "CharacterData/CharacterStatChangeData.h"
#include "Utility/Errors.h"

namespace Gecko
{

CharacterStatChangeData::CharacterStatChangeData()
{
}

CharacterStatChangeData::CharacterStatChangeData(const Json& jsonData)
{
    from_json(jsonData, *this);
}

void CharacterStatChangeData::Clear()
{
    // Passive data
    GetPassiveSkillDataArray().clear();
    GetPassiveItemDataArray().clear();

    // Active data
    GetActiveSkillDataArray().clear();
    GetActiveItemDataArray().clear();

    // Actionable data
    GetActionableSkillDataArray().clear();
    GetActionableItemDataArray().clear();

    // Prolonged stat changes
    SetProlongedStatChanges({});
}

const TreeIndexArray& CharacterStatChangeData::GetPassiveChanges(const IndexedString& sTreeIndexType) const
{
    const CharacterTreeIndexType eTreeIndexType = StringToCharacterTreeIndexType(sTreeIndexType);
    switch(eTreeIndexType)
    {
        case CharacterTreeIndexType::Skill:
            return GetPassiveSkillDataArray();
        case CharacterTreeIndexType::Item:
            return GetPassiveItemDataArray();
        default:
            break;
    }
    throw RuntimeError("Invalid or unknown tree index type requested: " + sTreeIndexType.Get());
}

const TreeIndexArray& CharacterStatChangeData::GetActiveChanges(const IndexedString& sTreeIndexType) const
{
    const CharacterTreeIndexType eTreeIndexType = StringToCharacterTreeIndexType(sTreeIndexType);
    switch(eTreeIndexType)
    {
        case CharacterTreeIndexType::Skill:
            return GetActiveSkillDataArray();
        case CharacterTreeIndexType::Item:
            return GetActiveItemDataArray();
        default:
            break;
    }
    throw RuntimeError("Invalid or unknown tree index type requested: " + sTreeIndexType.Get());
}

const TreeIndexArray& CharacterStatChangeData::GetActionableChanges(const IndexedString& sTreeIndexType) const
{
    const CharacterTreeIndexType eTreeIndexType = StringToCharacterTreeIndexType(sTreeIndexType);
    switch(eTreeIndexType)
    {
        case CharacterTreeIndexType::Skill:
            return GetActionableSkillDataArray();
        case CharacterTreeIndexType::Item:
            return GetActionableItemDataArray();
        default:
            break;
    }
    throw RuntimeError("Invalid or unknown tree index type requested: " + sTreeIndexType.Get());
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

StatChangeEntryArray CharacterStatChangeData::GetProlongedStatChangeEntries(Int iRound, Int iAttack, Int iDefend) const
{
    // Find all prolonged stat change entries that match current conditions
    StatChangeEntryArray vEntries;
    for(auto it = GetProlongedStatChanges().begin(); it != GetProlongedStatChanges().end(); it++)
    {
        // Ignore expired entries
        const IndexedString& sKey = IndexedString(it->first);
        if(HasProlongedStatChangeExpired(sKey, iRound, iAttack, iDefend))
        {
            continue;
        }

        // Find the only valid round/attack/defend and check if it matches
        const ProlongedStatChange& change = it->second;
        const StatChangeEntry& entry = change.GetStatChangeEntry();
        if(
            (change.IsValidRound() && change.GetRound() == iRound) ||
            (change.IsValidAttack() && change.GetAttack() == iAttack) ||
            (change.IsValidDefend() && change.GetDefend() == iDefend))
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

Bool CharacterStatChangeData::HasProlongedStatChangeExpired(const IndexedString& sKey, Int iRound, Int iAttack, Int iDefend) const
{
    const ProlongedStatChange& change = GetProlongedStatChange(sKey);
    return (
        (change.IsValidRound() && change.GetRound() < iRound) ||
        (change.IsValidAttack() && change.GetAttack() < iAttack) ||
        (change.IsValidDefend() && change.GetDefend() < iDefend)
    );
}

void CharacterStatChangeData::RemoveAllExpiredProlongedStatChanges(Int iRound, Int iAttack, Int iDefend)
{
    IndexedStringArray vKeys;
    for(auto it = GetProlongedStatChanges().begin(); it != GetProlongedStatChanges().end(); it++)
    {
        if(HasProlongedStatChangeExpired(IndexedString(it->first), iRound, iAttack, iDefend))
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
    // Passive data
    SET_JSON_DATA_IF_NOT_EMPTY(PassiveSkillDataArray);
    SET_JSON_DATA_IF_NOT_EMPTY(PassiveItemDataArray);

    // Active data
    SET_JSON_DATA_IF_NOT_EMPTY(ActiveSkillDataArray);
    SET_JSON_DATA_IF_NOT_EMPTY(ActiveItemDataArray);

    // Actionable data
    SET_JSON_DATA_IF_NOT_EMPTY(ActionableSkillDataArray);
    SET_JSON_DATA_IF_NOT_EMPTY(ActionableItemDataArray);
}

void from_json(const Json& jsonData, CharacterStatChangeData& obj)
{
    // Passive data
    obj.SetPassiveSkillDataArray(GET_JSON_DATA_OR_DEFAULT(PassiveSkillDataArray, TreeIndexArray, TreeIndexArray()));
    obj.SetPassiveItemDataArray(GET_JSON_DATA_OR_DEFAULT(PassiveItemDataArray, TreeIndexArray, TreeIndexArray()));

    // Active data
    obj.SetActiveSkillDataArray(GET_JSON_DATA_OR_DEFAULT(ActiveSkillDataArray, TreeIndexArray, TreeIndexArray()));
    obj.SetActiveItemDataArray(GET_JSON_DATA_OR_DEFAULT(ActiveItemDataArray, TreeIndexArray, TreeIndexArray()));

    // Actionable data
    obj.SetActionableSkillDataArray(GET_JSON_DATA_OR_DEFAULT(ActionableSkillDataArray, TreeIndexArray, TreeIndexArray()));
    obj.SetActionableItemDataArray(GET_JSON_DATA_OR_DEFAULT(ActionableItemDataArray, TreeIndexArray, TreeIndexArray()));
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(CharacterStatChangeData, CharacterStatChangeData);

};
