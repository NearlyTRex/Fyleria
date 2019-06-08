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

StringArray CharacterAction::GetAllCharacterIDs() const
{
    StringArray vAllCharacterIDs;
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

StringArray CharacterAction::GetAllActionTypes() const
{
    StringArray vAllActionTypes;
    for(const CharacterActionEntry& entry : GetActionEntries())
    {
        vAllActionTypes.insert(vAllActionTypes.end(), entry.GetActionTypes().begin(), entry.GetActionTypes().end());
    }
    return vAllActionTypes;
}

StringArray CharacterAction::GetAllDestinationTargetTypes() const
{
    StringArray vAllDestinationTargetTypes;
    for(const CharacterActionEntry& entry : GetActionEntries())
    {
        vAllDestinationTargetTypes.push_back(entry.GetDestinationTargetType());
    }
    return vAllDestinationTargetTypes;
}

Bool CharacterAction::AreAllCharacterIDsValid() const
{
    StringArray vAllCharacterIDs = GetAllCharacterIDs();
    if(vAllCharacterIDs.empty())
    {
        return false;
    }
    for(const String& sCharacterID : vAllCharacterIDs)
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
        StringArray vSourceCharIDs;
        String sSourceTargetType = GetSourceTargetType();
        String sSourcePartyType = ConvertCharacterTargetTypeToCharacterPartyType(sSourceTargetType);
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
        StringArray vDestCharIDs;
        String sDestTargetType = entry.GetDestinationTargetType();
        String sDestPartyType = ConvertCharacterTargetTypeToCharacterPartyType(sDestTargetType);
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
    SET_JSON_DATA_IF_NOT_DEFAULT(RunType, "");

    // Order
    SET_JSON_DATA_IF_NOT_DEFAULT(Order, 0);

    // Cost
    SET_JSON_DATA_IF_NOT_DEFAULT(CostAP, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(CostHP, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(CostMP, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(CostEP, 0);

    // Applicable weapon set
    SET_JSON_DATA_IF_NOT_DEFAULT(WeaponSet, "");

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
    SET_JSON_DATA_IF_NOT_DEFAULT(SourceTargetType, "");

    // Characters
    SET_JSON_DATA_IF_NOT_DEFAULT(SourceCharacterID, "");
}

void from_json(const Json& jsonData, CharacterAction& obj)
{
    // Run type
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(RunType, String, "");

    // Order
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(Order, Int, 0);

    // Cost
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(CostAP, Int, 0);
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(CostHP, Int, 0);
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(CostMP, Int, 0);
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(CostEP, Int, 0);

    // Applicable weapon set
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(WeaponSet, String, "");

    // Action entries
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(ActionEntries, CharacterActionEntryArray, CharacterActionEntryArray());

    // Previous action types
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(PreviousActionTypes, StringArray, StringArray());

    // Skill
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(SkillTreeIndex, TreeIndex, TreeIndex());

    // Item
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(ItemTreeIndex, TreeIndex, TreeIndex());
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(ItemAmount, Int, 0);

    // Targets
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(SourceTargetType, String, "");

    // Characters
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(SourceCharacterID, String, "");
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(CharacterAction, CharacterAction);

};
