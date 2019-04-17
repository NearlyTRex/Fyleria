// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

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
    SetFullString(IndexedString(""));
    SetFullFloatArray({});
    SetFullIntArray({});
    SetFullBoolArray({});
    SetFullStringArray({});

    // Operation type (Add, Multiply, etc)
    SetOperationType(IndexedString("None"));

    // Stats to serve as source and destination
    SetSourceStatType(IndexedString("None"));
    SetDestinationStatType(IndexedString("None"));
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
    SET_JSON_DATA_IF_NOT_DEFAULT(FullString, IndexedString(""));
    SET_JSON_DATA_IF_NOT_EMPTY(FullFloatArray);
    SET_JSON_DATA_IF_NOT_EMPTY(FullIntArray);
    SET_JSON_DATA_IF_NOT_EMPTY(FullBoolArray);
    SET_JSON_DATA_IF_NOT_EMPTY(FullStringArray);

    // Operation type (Add, Multiply, etc)
    SET_JSON_DATA_IF_NOT_DEFAULT(OperationType, IndexedString("None"));

    // Stats to serve as source and destination
    SET_JSON_DATA_IF_NOT_DEFAULT(SourceStatType, IndexedString("None"));
    SET_JSON_DATA_IF_NOT_DEFAULT(DestinationStatType, IndexedString("None"));

    // Character IDs for applying
    SET_JSON_DATA_IF_NOT_DEFAULT(SourceCharacterID, IndexedString(""));
    SET_JSON_DATA_IF_NOT_EMPTY(DestinationCharacterIDs);
}

void from_json(const Json& jsonData, StatChangeEntry& obj)
{
    // Applicable round or attack number
    obj.SetRound(GET_JSON_DATA_OR_DEFAULT(Round, Int, 0));
    obj.SetAttack(GET_JSON_DATA_OR_DEFAULT(Attack, Int, 0));
    obj.SetDefend(GET_JSON_DATA_OR_DEFAULT(Defend, Int, 0));

    // Delta amounts
    obj.SetDeltaFloat(GET_JSON_DATA_OR_DEFAULT(DeltaFloat, Float, 0));
    obj.SetDeltaInt(GET_JSON_DATA_OR_DEFAULT(DeltaInt, Int, 0));

    // Full amounts
    obj.SetFullPercent(GET_JSON_DATA_OR_DEFAULT(FullPercent, Float, 0));
    obj.SetFullFloat(GET_JSON_DATA_OR_DEFAULT(FullFloat, Float, 0));
    obj.SetFullInt(GET_JSON_DATA_OR_DEFAULT(FullInt, Int, 0));
    obj.SetFullBool(GET_JSON_DATA_OR_DEFAULT(FullBool, Bool, false));
    obj.SetFullString(GET_JSON_DATA_OR_DEFAULT(FullString, IndexedString, IndexedString("")));
    obj.SetFullFloatArray(GET_JSON_DATA_OR_DEFAULT(FullFloatArray, FloatArray, FloatArray()));
    obj.SetFullIntArray(GET_JSON_DATA_OR_DEFAULT(FullIntArray, IntArray, IntArray()));
    obj.SetFullBoolArray(GET_JSON_DATA_OR_DEFAULT(FullBoolArray, BoolArray, BoolArray()));
    obj.SetFullStringArray(GET_JSON_DATA_OR_DEFAULT(FullStringArray, IndexedStringArray, IndexedStringArray()));

    // Operation type (Add, Multiply, etc)
    obj.SetOperationType(GET_JSON_DATA_OR_DEFAULT(OperationType, IndexedString, IndexedString("None")));

    // Stats to serve as source and destination
    obj.SetSourceStatType(GET_JSON_DATA_OR_DEFAULT(SourceStatType, IndexedString, IndexedString("None")));
    obj.SetDestinationStatType(GET_JSON_DATA_OR_DEFAULT(DestinationStatType, IndexedString, IndexedString("None")));

    // Character IDs for applying
    obj.SetSourceCharacterID(GET_JSON_DATA_OR_DEFAULT(SourceCharacterID, IndexedString, IndexedString("")));
    obj.SetDestinationCharacterIDs(GET_JSON_DATA_OR_DEFAULT(DestinationCharacterIDs, IndexedStringArray, IndexedStringArray()));
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(StatChangeEntry, StatChangeEntry);

};
