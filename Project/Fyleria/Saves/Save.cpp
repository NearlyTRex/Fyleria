// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Saves/Save.h"

namespace Gecko
{

Save::Save()
    : SerializableToJson()
{
    Clear();
}

Save::Save(const Json& jsonData)
    : SerializableToJson(jsonData)
{
}

Save::Save(const String& jsonString)
    : SerializableToJson(JsonParse(jsonString))
{
}

void Save::Clear()
{
    // Slot
    SetSlot(0);

    // Time
    SetTime(0);

    // Description
    SetDescription("");

    // Parties
    SetParties({});

    // Characters
    SetCharacters({});
}

MAKE_JSON_BASIC_TYPE_CONVERTERS_IMPL(Save);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(Save, Save);

};
