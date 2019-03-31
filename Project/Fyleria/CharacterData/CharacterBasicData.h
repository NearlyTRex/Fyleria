// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_CHARACTER_BASIC_DATA_H_
#define _GECKO_CHARACTER_BASIC_DATA_H_

#include "Character/CharacterTypes.h"

namespace Gecko
{

class CharacterBasicData
{
public:

    // Constructors
    CharacterBasicData();
    ~CharacterBasicData();

    // Character ID
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(CharacterID, IndexedString);

    // Character target type
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(CharacterTargetType, IndexedString);

    // Basic character data
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(FirstName, IndexedString);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(LastName, IndexedString);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(Age, Short);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(Gender, IndexedString);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(Hair, IndexedString);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(Eyes, IndexedString);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(Handedness, IndexedString);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(BaseRace, IndexedString);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(TransformedRace, IndexedString);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(PowerSet, IndexedString);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(CurrentWeaponSet, IndexedString);

    // Attack/defend counters
    MAKE_RAW_BASIC_TYPE_ACCESSORS(AttackCounter, Int);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(DefendCounter, Int);

    // Previous action types
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(PreviousActionTypes, IndexedStringArray);


    // Comparisons
    Bool operator==(const CharacterBasicData& other) const;
    Bool operator!=(const CharacterBasicData& other) const;

private:

};

// Typedef
MAKE_TYPE_TYPEDEFS(CharacterBasicData);

// JSON Converters
void to_json(Json& jsonData, const CharacterBasicData& obj);
void from_json(const Json& jsonData, CharacterBasicData& obj);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_DECL(CharacterBasicData, CharacterBasicData);

};

#endif
