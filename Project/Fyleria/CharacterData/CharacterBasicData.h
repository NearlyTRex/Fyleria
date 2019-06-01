// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_CHARACTER_BASIC_DATA_H_
#define _GECKO_CHARACTER_BASIC_DATA_H_

#include "Character/CharacterTypes.h"
#include "Stats/StatTypeHolder.h"

namespace Gecko
{

// Character basic data
class CharacterBasicData : public StatTypeHolder
{
public:

    // Constructors
    CharacterBasicData();
    CharacterBasicData(const Json& jsonData);

    // Clear all data
    void Clear();

    // Stat names
    static void InitAllStatNames();

    // Character ID
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(CharacterID, IndexedString);

    // Party ID
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(PartyID, IndexedString);

    // IndexedString stats
    MAKE_STAT_TYPE_ACCESSORS(FirstName, IndexedString);
    MAKE_STAT_TYPE_ACCESSORS(LastName, IndexedString);
    MAKE_STAT_TYPE_ACCESSORS(Gender, IndexedString);
    MAKE_STAT_TYPE_ACCESSORS(Hair, IndexedString);
    MAKE_STAT_TYPE_ACCESSORS(Eyes, IndexedString);
    MAKE_STAT_TYPE_ACCESSORS(Handedness, IndexedString);
    MAKE_STAT_TYPE_ACCESSORS(BaseRace, IndexedString);
    MAKE_STAT_TYPE_ACCESSORS(TransformedRace, IndexedString);
    MAKE_STAT_TYPE_ACCESSORS(PowerSet, IndexedString);

    // Int stats
    MAKE_STAT_TYPE_ACCESSORS(Age, Int);

    // Comparisons
    Bool operator==(const CharacterBasicData& other) const;
    Bool operator!=(const CharacterBasicData& other) const;
};

// Typedef
MAKE_TYPE_TYPEDEFS(CharacterBasicData);

// JSON Converters
void to_json(Json& jsonData, const CharacterBasicData& obj);
void from_json(const Json& jsonData, CharacterBasicData& obj);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_DECL(CharacterBasicData, CharacterBasicData);

};

#endif
