// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_CHARACTER_ACTION_DATA_H_
#define _GECKO_CHARACTER_ACTION_DATA_H_

#include "Character/CharacterTypes.h"
#include "CharacterAction/CharacterAction.h"

namespace Gecko
{

class CharacterActionData
{
public:

    // Constructors
    CharacterActionData();
    CharacterActionData(const Json& jsonData);

    // Clear all data
    void Clear();

    // List of character actions
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(AvailableActions, CharacterActionArray);

    // Comparisons
    Bool operator==(const CharacterActionData& other) const;
    Bool operator!=(const CharacterActionData& other) const;

private:

};

// Typedef
MAKE_TYPE_TYPEDEFS(CharacterActionData);

// JSON Converters
void to_json(Json& jsonData, const CharacterActionData& obj);
void from_json(const Json& jsonData, CharacterActionData& obj);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_DECL(CharacterActionData, CharacterActionData);

};

#endif
