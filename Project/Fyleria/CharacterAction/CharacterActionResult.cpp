// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "CharacterAction/CharacterActionResult.h"

namespace Gecko
{

CharacterActionResult::CharacterActionResult()
    : SerializableToJson()
{
}

CharacterActionResult::CharacterActionResult(const Json& jsonData)
    : SerializableToJson(jsonData)
{
}

CharacterActionResult::CharacterActionResult(const String& jsonString)
    : SerializableToJson(JsonParse(jsonString))
{
}

CharacterActionResult::~CharacterActionResult()
{
}

Bool CharacterActionResult::operator==(const CharacterActionResult& other) const
{
    return (Json(*this) == Json(other));
}

Bool CharacterActionResult::operator!=(const CharacterActionResult& other) const
{
    return not operator==(other);
}

MAKE_JSON_OBJ_TYPE_CONVERTERS_IMPL(CharacterActionResult);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(CharacterActionResult, CharacterActionResult);

};
