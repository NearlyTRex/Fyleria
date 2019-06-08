// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "CharacterAction/CharacterAction.h"
#include "Character/CharacterManager.h"
#include "CharacterParty/CharacterPartyManager.h"
#include "Utility/Constants.h"

namespace Gecko
{

CharacterAction::CharacterAction()
    : SerializableToJson()
{
}

CharacterAction::CharacterAction(const Json& jsonData)
    : SerializableToJson(jsonData)
{
}

CharacterAction::CharacterAction(const String& jsonString)
    : SerializableToJson(JsonParse(jsonString))
{
}

IndexedStringArray CharacterAction::GetAllCharacterIDs() const
{
    IndexedStringArray vAllCharacterIDs;
    if(!GetSourceCharacterID().empty())
    {
        vAllCharacterIDs.push_back(GetSourceCharacterID());
    }
    for(const CharacterActionEntry& entry : GetActionEntries())
    {
        vAllCharacterIDs.insert(
            vAllCharacterIDs.end(),
            entry.GetDestinationCharacterIDs().begin(),
            entry.GetDestinationCharacterIDs().end());
    }
    return vAllCharacterIDs;
}

IndexedStringArray CharacterAction::GetAllActionTypes() const
{
    IndexedStringArray vAllActionTypes;
    for(const CharacterActionEntry& entry : GetActionEntries())
    {
        vAllActionTypes.insert(vAllActionTypes.end(), entry.GetActionTypes().begin(), entry.GetActionTypes().end());
    }
    return vAllActionTypes;
}

IndexedStringArray CharacterAction::GetAllDestinationTargetTypes() const
{
    IndexedStringArray vAllDestinationTargetTypes;
    for(const CharacterActionEntry& entry : GetActionEntries())
    {
        vAllDestinationTargetTypes.push_back(entry.GetDestinationTargetType());
    }
    return vAllDestinationTargetTypes;
}

Bool CharacterAction::AreAllCharacterIDsValid() const
{
    IndexedStringArray vAllCharacterIDs = GetAllCharacterIDs();
    if(vAllCharacterIDs.empty())
    {
        return false;
    }
    for(const IndexedString& sCharacterID : vAllCharacterIDs)
    {
        if(!CharacterManager::GetInstance()->DoesCharacterExist(sCharacterID))
        {
            return false;
        }
    }
    return true;
}

Bool CharacterAction::PrepareCharacterIDs()
{
    // Get source character info if it's not already set
    if(GetSourceCharacterID().empty())
    {
        // Get source character info
        IndexedStringArray vSourceCharIDs;
        IndexedString sSourceTargetType = GetSourceTargetType();
        IndexedString sSourcePartyType = ConvertCharacterTargetTypeToCharacterPartyType(sSourceTargetType);
        CharacterPartyManager::GetInstance()->GetPartyByType(sSourcePartyType).GetCharacterIDsFromTargetType(sSourceTargetType, vSourceCharIDs);
        if(vSourceCharIDs.empty())
        {
            return false;
        }

        // Store source character ID
        SetSourceCharacterID(vSourceCharIDs.front());
    }

    // Do the same for each destination
    for(CharacterActionEntry& entry : GetActionEntries())
    {
        // Get destination character info
        IndexedStringArray vDestCharIDs;
        IndexedString sDestTargetType = entry.GetDestinationTargetType();
        IndexedString sDestPartyType = ConvertCharacterTargetTypeToCharacterPartyType(sDestTargetType);
        CharacterPartyManager::GetInstance()->GetPartyByType(sDestPartyType).GetCharacterIDsFromTargetType(sDestTargetType, vDestCharIDs);
        if(vDestCharIDs.empty())
        {
            return false;
        }

        // Store destination character IDs
        entry.SetDestinationCharacterIDs(vDestCharIDs);
    }
    return true;
}

void to_json(Json& jsonData, const CharacterAction& obj)
{
    // Run type
    SET_JSON_DATA_IF_NOT_DEFAULT(RunType, IndexedString("None"));

    // Order
    SET_JSON_DATA_IF_NOT_DEFAULT(Order, 0);

    // Cost
    SET_JSON_DATA_IF_NOT_DEFAULT(CostAP, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(CostHP, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(CostMP, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(CostEP, 0);

    // Applicable weapon set
    SET_JSON_DATA_IF_NOT_DEFAULT(WeaponSet, IndexedString("None"));

    // Action entries
    SET_JSON_DATA_IF_NOT_EMPTY(ActionEntries);

    // Previous action types
    SET_JSON_DATA_IF_NOT_EMPTY(PreviousActionTypes);

    // Skill
    SET_JSON_DATA_IF_NOT_EMPTY(SkillTreeIndex);

    // Item
    SET_JSON_DATA_IF_NOT_EMPTY(ItemTreeIndex);
    SET_JSON_DATA_IF_NOT_DEFAULT(ItemAmount, 0);

    // Targets
    SET_JSON_DATA_IF_NOT_DEFAULT(SourceTargetType, IndexedString("None"));

    // Characters
    SET_JSON_DATA_IF_NOT_DEFAULT(SourceCharacterID, IndexedString(""));
}

void from_json(const Json& jsonData, CharacterAction& obj)
{
    // Run type
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(RunType, IndexedString, IndexedString("None"));

    // Order
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(Order, Int, 0);

    // Cost
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(CostAP, Int, 0);
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(CostHP, Int, 0);
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(CostMP, Int, 0);
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(CostEP, Int, 0);

    // Applicable weapon set
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(WeaponSet, IndexedString, IndexedString("None"));

    // Action entries
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(ActionEntries, CharacterActionEntryArray, CharacterActionEntryArray());

    // Previous action types
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(PreviousActionTypes, IndexedStringArray, IndexedStringArray());

    // Skill
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(SkillTreeIndex, TreeIndex, TreeIndex());

    // Item
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(ItemTreeIndex, TreeIndex, TreeIndex());
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(ItemAmount, Int, 0);

    // Targets
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(SourceTargetType, IndexedString, IndexedString("None"));

    // Characters
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(SourceCharacterID, IndexedString, IndexedString(""));
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(CharacterAction, CharacterAction);

};
