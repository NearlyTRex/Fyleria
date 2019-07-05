// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Stats/StatChangeEntry.h"

namespace Gecko
{

StatChangeEntry::StatChangeEntry()
{
    // Applicable round or attack number
    SetRound(0);
    SetAttack(0);
    SetDefend(0);

    // Delta amounts
    SetDeltaFloat(0);
    SetDeltaInt(0);

    // Full amounts
    SetFullPercent(0);
    SetFullFloat(0);
    SetFullInt(0);
    SetFullBool(false);
    SetFullString("");
    SetFullFloatArray({});
    SetFullIntArray({});
    SetFullBoolArray({});
    SetFullStringArray({});

    // Operation type (Add, Multiply, etc)
    SetOperationType("");

    // Stats to serve as source and destination
    SetSourceStatType("");
    SetDestinationStatType("");
}

StatChangeEntry::StatChangeEntry(const Json& jsonData)
{
    from_json(jsonData, *this);
}

StatChangeEntry::~StatChangeEntry()
{
}

void to_json(Json& jsonData, const StatChangeEntry& obj)
{
    // Applicable round or attack number
    SET_JSON_DATA(Round);
    SET_JSON_DATA(Attack);
    SET_JSON_DATA(Defend);

    // Delta amounts
    SET_JSON_DATA(DeltaFloat);
    SET_JSON_DATA(DeltaInt);

    // Full amounts
    SET_JSON_DATA(FullPercent);
    SET_JSON_DATA(FullFloat);
    SET_JSON_DATA(FullInt);
    SET_JSON_DATA(FullBool);
    SET_JSON_DATA(FullString);
    SET_JSON_DATA(FullFloatArray);
    SET_JSON_DATA(FullIntArray);
    SET_JSON_DATA(FullBoolArray);
    SET_JSON_DATA(FullStringArray);

    // Operation type (Add, Multiply, etc)
    SET_JSON_DATA(OperationType);

    // Stats to serve as source and destination
    SET_JSON_DATA(SourceStatType);
    SET_JSON_DATA(DestinationStatType);

    // Character IDs for applying
    SET_JSON_DATA(SourceCharacterID);
    SET_JSON_DATA(DestinationCharacterIDs);
}

void from_json(const Json& jsonData, StatChangeEntry& obj)
{
    // Applicable round or attack number
    SET_OBJ_DATA(Round, Int, 0);
    SET_OBJ_DATA(Attack, Int, 0);
    SET_OBJ_DATA(Defend, Int, 0);

    // Delta amounts
    SET_OBJ_DATA(DeltaFloat, Float, 0);
    SET_OBJ_DATA(DeltaInt, Int, 0);

    // Full amounts
    SET_OBJ_DATA(FullPercent, Float, 0);
    SET_OBJ_DATA(FullFloat, Float, 0);
    SET_OBJ_DATA(FullInt, Int, 0);
    SET_OBJ_DATA(FullBool, Bool, false);
    SET_OBJ_DATA(FullString, String, "");
    SET_OBJ_DATA(FullFloatArray, FloatArray, FloatArray());
    SET_OBJ_DATA(FullIntArray, IntArray, IntArray());
    SET_OBJ_DATA(FullBoolArray, BoolArray, BoolArray());
    SET_OBJ_DATA(FullStringArray, StringArray, StringArray());

    // Operation type (Add, Multiply, etc)
    SET_OBJ_DATA(OperationType, String, "");

    // Stats to serve as source and destination
    SET_OBJ_DATA(SourceStatType, String, "");
    SET_OBJ_DATA(DestinationStatType, String, "");

    // Character IDs for applying
    SET_OBJ_DATA(SourceCharacterID, String, "");
    SET_OBJ_DATA(DestinationCharacterIDs, StringArray, StringArray());
}

MAKE_JSON_SEQUENCE_TYPE_CONVERTERS_IMPL(StatChangeEntryArray);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(StatChangeEntry, StatChangeEntry);

};
