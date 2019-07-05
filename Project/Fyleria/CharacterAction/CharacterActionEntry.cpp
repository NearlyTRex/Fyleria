// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "CharacterAction/CharacterActionEntry.h"

namespace Gecko
{

CharacterActionEntry::CharacterActionEntry()
    : SerializableToJson()
{
}

CharacterActionEntry::CharacterActionEntry(const Json& jsonData)
    : SerializableToJson(jsonData)
{
}

CharacterActionEntry::CharacterActionEntry(const String& jsonString)
    : SerializableToJson(JsonParse(jsonString))
{
}

CharacterActionEntry::~CharacterActionEntry()
{
}

Bool CharacterActionEntry::DoesMatchActionType(const String& sType) const
{
    return STDFindData(GetActionTypes().begin(), GetActionTypes().end(), sType) != GetActionTypes().end();
}

Bool CharacterActionEntry::operator==(const CharacterActionEntry& other) const
{
    return (Json(*this) == Json(other));
}

Bool CharacterActionEntry::operator!=(const CharacterActionEntry& other) const
{
    return not operator==(other);
}

MAKE_JSON_OBJ_TYPE_CONVERTERS_IMPL(CharacterActionEntry);
MAKE_JSON_SEQUENCE_TYPE_CONVERTERS_IMPL(CharacterActionEntryArray);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(CharacterActionEntry, CharacterActionEntry);

};
