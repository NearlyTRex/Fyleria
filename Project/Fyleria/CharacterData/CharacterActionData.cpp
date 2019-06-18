// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "CharacterData/CharacterActionData.h"
#include "Character/CharacterManager.h"

namespace Gecko
{

CharacterActionData::CharacterActionData()
{
}

CharacterActionData::CharacterActionData(const Json& jsonData)
{
    from_json(jsonData, *this);
}

CharacterActionData::~CharacterActionData()
{
}

void CharacterActionData::Clear()
{
    // List of character actions
    GetAvailableActions().clear();
}

void CharacterActionData::UpdateAvailableActions(const String& sCharacterID)
{
    // Get character
    const Character& character = CharacterManager::GetInstance()->GetCharacter(sCharacterID);

    // Clear stored actions
    CharacterActionArray& vAvailableActions = GetAvailableActions();
    vAvailableActions.clear();

    // Look at each type of tree index
    for(const String& sIndexTreeType : CharacterTreeIndexType::_names())
    {
        // Skip invalid tree types
        if(IsNoneTypeForEnum<CharacterTreeIndexType>(sIndexTreeType))
        {
            continue;
        }

        // Look at each active change index of that type
        for(const TreeIndex& treeIndex : character.GetActionableChanges(sIndexTreeType))
        {
            // Look at each weapon set
            for(const String& sWeaponSet : CharacterWeaponSetType::_names())
            {
                // Skip invalid weapon sets
                if(IsNoneTypeForEnum<CharacterWeaponSetType>(sWeaponSet))
                {
                    continue;
                }

                // Add skill actions
                CharacterActionArray vSkillActions;
                if(SkillTree::GenerateSkillCharacterActions(treeIndex, sCharacterID, sWeaponSet, vSkillActions))
                {
                   vAvailableActions.insert(vAvailableActions.end(), vSkillActions.begin(), vSkillActions.end());
                }

                // Add item actions
                CharacterActionArray vItemActions;
                if(ItemTree::GenerateItemCharacterActions(treeIndex, sCharacterID, sWeaponSet, vItemActions))
                {
                   vAvailableActions.insert(vAvailableActions.end(), vItemActions.begin(), vItemActions.end());
                }
            }
        }
    }
}

Bool CharacterActionData::operator==(const CharacterActionData& other) const
{
    return (Json(*this) == Json(other));
}

Bool CharacterActionData::operator!=(const CharacterActionData& other) const
{
    return not operator==(other);
}

void to_json(Json& jsonData, const CharacterActionData& obj)
{
    // List of character actions
    SET_JSON_DATA(AvailableActions);
}

void from_json(const Json& jsonData, CharacterActionData& obj)
{
    // List of character actions
    SET_OBJ_DATA(AvailableActions, CharacterActionArray, CharacterActionArray());
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(CharacterActionData, CharacterActionData);

};
