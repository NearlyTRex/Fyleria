// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "CharacterData/CharacterBasicData.h"

namespace Gecko
{

CharacterBasicData::CharacterBasicData()
{
    // Get current configuration
    const Config& config = ConfigManager::GetInstance()->GetCurrentConfig();

    // Character ID
    SetCharacterID(IndexedString(""));

    // Character target type
    SetCharacterTargetType(IndexedString("None"));

    // Basic character data
    SetFirstName(IndexedString(config.GetDefaultFirstName()));
    SetLastName(IndexedString(config.GetDefaultLastName()));
    SetAge(config.GetDefaultAge());
    SetGender(IndexedString(config.GetDefaultGender()));
    SetHair(IndexedString(config.GetDefaultHair()));
    SetEyes(IndexedString(config.GetDefaultEyes()));
    SetHandedness(IndexedString(config.GetDefaultHandedness()));
    SetBaseRace(IndexedString(config.GetDefaultBaseRace()));
    SetTransformedRace(IndexedString(config.GetDefaultTransformedRace()));
    SetPowerSet(IndexedString(config.GetDefaultPowerSet()));
    SetCurrentWeaponSet(IndexedString(config.GetDefaultCurrentWeaponSet()));

    // Attack/defend counters
    SetAttackCounter(0);
    SetDefendCounter(0);


}

CharacterBasicData::~CharacterBasicData()
{
}

Bool CharacterBasicData::operator==(const CharacterBasicData& other) const
{
    return false;
}

Bool CharacterBasicData::operator!=(const CharacterBasicData& other) const
{
    return false;
}

void to_json(Json& jsonData, const CharacterBasicData& obj)
{
    // Get current configuration
    const Config& config = ConfigManager::GetInstance()->GetCurrentConfig();

    // Character ID
    SET_JSON_DATA_IF_NOT_DEFAULT(CharacterID, IndexedString(""));

    // Character target type
    SET_JSON_DATA_IF_NOT_DEFAULT(CharacterTargetType, IndexedString("None"));

    // Basic character data
    SET_JSON_DATA_IF_NOT_DEFAULT(FirstName, IndexedString(config.GetDefaultFirstName()));
    SET_JSON_DATA_IF_NOT_DEFAULT(LastName, IndexedString(config.GetDefaultLastName()));
    SET_JSON_DATA_IF_NOT_DEFAULT(Age, config.GetDefaultAge());
    SET_JSON_DATA_IF_NOT_DEFAULT(Gender, IndexedString(config.GetDefaultGender()));
    SET_JSON_DATA_IF_NOT_DEFAULT(Hair, IndexedString(config.GetDefaultHair()));
    SET_JSON_DATA_IF_NOT_DEFAULT(Eyes, IndexedString(config.GetDefaultEyes()));
    SET_JSON_DATA_IF_NOT_DEFAULT(Handedness, IndexedString(config.GetDefaultHandedness()));
    SET_JSON_DATA_IF_NOT_DEFAULT(BaseRace, IndexedString(config.GetDefaultBaseRace()));
    SET_JSON_DATA_IF_NOT_DEFAULT(TransformedRace, IndexedString(config.GetDefaultTransformedRace()));
    SET_JSON_DATA_IF_NOT_DEFAULT(PowerSet, IndexedString(config.GetDefaultPowerSet()));
    SET_JSON_DATA_IF_NOT_DEFAULT(CurrentWeaponSet, IndexedString(config.GetDefaultCurrentWeaponSet()));

    // Attack/defend counters
    SET_JSON_DATA_IF_NOT_DEFAULT(AttackCounter, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(DefendCounter, 0);

    // Previous action types
    SET_JSON_DATA_IF_NOT_EMPTY(PreviousActionTypes);
}

void from_json(const Json& jsonData, CharacterBasicData& obj)
{
    // Get current configuration
    const Config& config = ConfigManager::GetInstance()->GetCurrentConfig();

    // Character ID
    obj.SetCharacterID(GET_JSON_DATA_OR_DEFAULT(CharacterID, IndexedString, IndexedString("")));

    // Character target type
    obj.SetCharacterTargetType(GET_JSON_DATA_OR_DEFAULT(CharacterTargetType, IndexedString, IndexedString("None")));

    // Basic character data
    obj.SetFirstName(GET_JSON_DATA_OR_DEFAULT(FirstName, IndexedString, IndexedString(config.GetDefaultFirstName())));
    obj.SetLastName(GET_JSON_DATA_OR_DEFAULT(LastName, IndexedString, IndexedString(config.GetDefaultLastName())));
    obj.SetAge(GET_JSON_DATA_OR_DEFAULT(Age, Int, config.GetDefaultAge()));
    obj.SetGender(GET_JSON_DATA_OR_DEFAULT(Gender, IndexedString, IndexedString(config.GetDefaultGender())));
    obj.SetHair(GET_JSON_DATA_OR_DEFAULT(Hair, IndexedString, IndexedString(config.GetDefaultHair())));
    obj.SetEyes(GET_JSON_DATA_OR_DEFAULT(Eyes, IndexedString, IndexedString(config.GetDefaultEyes())));
    obj.SetHandedness(GET_JSON_DATA_OR_DEFAULT(Handedness, IndexedString, IndexedString(config.GetDefaultHandedness())));
    obj.SetBaseRace(GET_JSON_DATA_OR_DEFAULT(BaseRace, IndexedString, IndexedString(config.GetDefaultBaseRace())));
    obj.SetTransformedRace(GET_JSON_DATA_OR_DEFAULT(TransformedRace, IndexedString, IndexedString(config.GetDefaultTransformedRace())));
    obj.SetPowerSet(GET_JSON_DATA_OR_DEFAULT(PowerSet, IndexedString, IndexedString(config.GetDefaultPowerSet())));
    obj.SetCurrentWeaponSet(GET_JSON_DATA_OR_DEFAULT(CurrentWeaponSet, IndexedString, IndexedString(config.GetDefaultCurrentWeaponSet())));

    // Attack/defend counters
    obj.SetAttackCounter(GET_JSON_DATA_OR_DEFAULT(AttackCounter, Int, 0));
    obj.SetDefendCounter(GET_JSON_DATA_OR_DEFAULT(DefendCounter, Int, 0));

    // Previous action types
    obj.SetPreviousActionTypes(GET_JSON_DATA_OR_DEFAULT(PreviousActionTypes, IndexedStringArray, IndexedStringArray()));
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(CharacterBasicData, CharacterBasicData);

};
