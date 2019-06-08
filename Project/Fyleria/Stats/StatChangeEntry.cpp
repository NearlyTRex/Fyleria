// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

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

void to_json(Json& jsonData, const StatChangeEntry& obj)
{
    // Applicable round or attack number
    SET_JSON_DATA_IF_NOT_DEFAULT(Round, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(Attack, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(Defend, 0);

    // Delta amounts
    SET_JSON_DATA_IF_NOT_DEFAULT(DeltaFloat, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(DeltaInt, 0);

    // Full amounts
    SET_JSON_DATA_IF_NOT_DEFAULT(FullPercent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(FullFloat, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(FullInt, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(FullBool, false);
    SET_JSON_DATA_IF_NOT_DEFAULT(FullString, "");
    SET_JSON_DATA_IF_NOT_EMPTY(FullFloatArray);
    SET_JSON_DATA_IF_NOT_EMPTY(FullIntArray);
    SET_JSON_DATA_IF_NOT_EMPTY(FullBoolArray);
    SET_JSON_DATA_IF_NOT_EMPTY(FullStringArray);

    // Operation type (Add, Multiply, etc)
    SET_JSON_DATA_IF_NOT_DEFAULT(OperationType, "");

    // Stats to serve as source and destination
    SET_JSON_DATA_IF_NOT_DEFAULT(SourceStatType, "");
    SET_JSON_DATA_IF_NOT_DEFAULT(DestinationStatType, "");

    // Character IDs for applying
    SET_JSON_DATA_IF_NOT_DEFAULT(SourceCharacterID, "");
    SET_JSON_DATA_IF_NOT_EMPTY(DestinationCharacterIDs);
}

void from_json(const Json& jsonData, StatChangeEntry& obj)
{
    // Applicable round or attack number
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(Round, Int, 0);
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(Attack, Int, 0);
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(Defend, Int, 0);

    // Delta amounts
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(DeltaFloat, Float, 0);
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(DeltaInt, Int, 0);

    // Full amounts
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(FullPercent, Float, 0);
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(FullFloat, Float, 0);
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(FullInt, Int, 0);
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(FullBool, Bool, false);
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(FullString, String, "");
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(FullFloatArray, FloatArray, FloatArray());
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(FullIntArray, IntArray, IntArray());
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(FullBoolArray, BoolArray, BoolArray());
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(FullStringArray, StringArray, StringArray());

    // Operation type (Add, Multiply, etc)
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(OperationType, String, "");

    // Stats to serve as source and destination
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(SourceStatType, String, "");
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(DestinationStatType, String, "");

    // Character IDs for applying
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(SourceCharacterID, String, "");
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(DestinationCharacterIDs, StringArray, StringArray());
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(StatChangeEntry, StatChangeEntry);

};
