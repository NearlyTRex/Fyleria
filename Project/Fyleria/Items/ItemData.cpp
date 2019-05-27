// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "Items/ItemData.h"
#include "CharacterAction/CharacterAction.h"
#include "Character/CharacterManager.h"

namespace Gecko
{

ItemData::ItemData()
{
}

ItemData::ItemData(const Json& jsonData)
{
    from_json(jsonData, *this);
}

void ItemData::Clear()
{
    // Run types
    SetRunTypes({});

    // Data class
    SetDataClass(IndexedString(""));

    // Item name
    SetItemName(IndexedString(""));

    // Item description
    SetItemDescription(IndexedString(""));

    // Item type
    SetItemType(IndexedString("None"));

    // Action types
    SetActionTypes({});

    // Item index
    SetItemTreeIndex({});

    // Stat changes
    SetStatChanges({});
}

Bool ItemData::IsActionable() const
{
    // First check that all the necessary information is filled out
    if(GetRunTypes().empty() ||
       GetDataClass().empty() ||
       GetItemName().empty() ||
       GetItemDescription().empty() ||
       GetItemType().empty())
    {
        return false;
    }

    // Check if action types is empty
    if(GetActionTypes().empty())
    {
        return false;
    }
    return true;
}

Bool ItemData::DoesMeetActionRequirements(const IndexedString& sCharacterID, const IndexedString& sWeaponSet) const
{
    // Check character
    if(!CharacterManager::GetInstance()->DoesCharacterExist(sCharacterID))
    {
        return false;
    }

    // Check each of the stat changes against the equipped items and their action types
    for(const StatChange& change : GetStatChanges())
    {
        if(change.DoesHaveItemUsedRequirements())
        {
            return change.DoesMeetItemUsedRequirements(GetActionTypes());
        }
        else if(change.DoesHaveItemEquippedRequirements())
        {
            return change.DoesMeetItemEquippedRequirements(sCharacterID, sWeaponSet);
        }
    }
    return false;
}

CharacterActionArray ItemData::CreateBaseActions(const IndexedString& sCharacterID, const IndexedString& sWeaponSet) const
{
    // Check character
    CharacterActionArray vNewActions;
    if(!CharacterManager::GetInstance()->DoesCharacterExist(sCharacterID))
    {
        return vNewActions;
    }

    // Get character
    const Character& character = CharacterManager::GetInstance()->GetCharacter(sCharacterID);

    // Create actions
    for(auto& sType : GetRunTypes())
    {
        CharacterAction newAction;
        newAction.SetRunType(sType);
        newAction.SetWeaponSet(sWeaponSet);
        newAction.SetItemTreeIndex(GetItemTreeIndex());
        newAction.SetSourceTargetType(character.GetCharacterTargetType());
        newAction.SetSourceCharacterID(sCharacterID);
        vNewActions.push_back(newAction);
    }
    return vNewActions;
}

void to_json(Json& jsonData, const ItemData& obj)
{
    // Run types
    SET_JSON_DATA_IF_NOT_EMPTY(RunTypes);

    // Data class
    SET_JSON_DATA_IF_NOT_DEFAULT(DataClass, IndexedString(""));

    // Item name
    SET_JSON_DATA_IF_NOT_DEFAULT(ItemName, IndexedString(""));

    // Item description
    SET_JSON_DATA_IF_NOT_DEFAULT(ItemDescription, IndexedString(""));

    // Item type
    SET_JSON_DATA_IF_NOT_DEFAULT(ItemType, IndexedString("None"));

    // Item index
    SET_JSON_DATA_IF_NOT_DEFAULT(ItemTreeIndex, TreeIndex());

    // Action types
    SET_JSON_DATA_IF_NOT_EMPTY(ActionTypes);

    // Stat changes
    SET_JSON_DATA_IF_NOT_EMPTY(StatChanges);
}

void from_json(const Json& jsonData, ItemData& obj)
{
    // Run types
    obj.SetRunTypes(GET_JSON_DATA_OR_DEFAULT(RunTypes, IndexedStringArray, IndexedStringArray()));

    // Data class
    obj.SetDataClass(GET_JSON_DATA_OR_DEFAULT(DataClass, IndexedString, IndexedString("")));

    // Item name
    obj.SetItemName(GET_JSON_DATA_OR_DEFAULT(ItemName, IndexedString, IndexedString("")));

    // Item description
    obj.SetItemDescription(GET_JSON_DATA_OR_DEFAULT(ItemDescription, IndexedString, IndexedString("")));

    // Item type
    obj.SetItemType(GET_JSON_DATA_OR_DEFAULT(ItemType, IndexedString, IndexedString("None")));

    // Item index
    obj.SetItemTreeIndex(GET_JSON_DATA_OR_DEFAULT(ItemTreeIndex, TreeIndex, TreeIndex()));

    // Action types
    obj.SetActionTypes(GET_JSON_DATA_OR_DEFAULT(ActionTypes, IndexedStringArray, IndexedStringArray()));

    // Stat changes
    obj.SetStatChanges(GET_JSON_DATA_OR_DEFAULT(StatChanges, StatChangeArray, StatChangeArray()));
}

};
