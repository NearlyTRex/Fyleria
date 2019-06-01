// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_STAT_CHANGE_ENTRY_H_
#define _GECKO_STAT_CHANGE_ENTRY_H_

#include "Utility/IndexedString.h"
#include "Utility/Macros.h"
#include "Utility/Enum.h"
#include "Utility/Json.h"

namespace Gecko
{

// Class for stat change entries
class StatChangeEntry
{
public:

    // Constructors
    StatChangeEntry();
    StatChangeEntry(const Json& jsonData);

    // Applicable round or attack number
    MAKE_RAW_BASIC_TYPE_ACCESSORS(Round, Short);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(Attack, Short);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(Defend, Short);

    // Delta amounts
    MAKE_RAW_BASIC_TYPE_ACCESSORS(DeltaFloat, Float);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(DeltaInt, Int);

    // Full amounts
    MAKE_RAW_BASIC_TYPE_ACCESSORS(FullPercent, Float);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(FullFloat, Float);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(FullInt, Int);
    MAKE_RAW_BASIC_TYPE_ACCESSORS(FullBool, Bool);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(FullString, IndexedString);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(FullFloatArray, FloatArray);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(FullIntArray, IntArray);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(FullBoolArray, BoolArray);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(FullStringArray, IndexedStringArray);

    // Operation type (Add, Multiply, etc)
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(OperationType, IndexedString);

    // Stats to serve as source and destination
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SourceStatType, IndexedString);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(DestinationStatType, IndexedString);

    // Character IDs for applying
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SourceCharacterID, IndexedString);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(DestinationCharacterIDs, IndexedStringArray);
};

// Typedefs
MAKE_TYPE_TYPEDEFS(StatChangeEntry);

// JSON Converters
void to_json(Json& jsonData, const StatChangeEntry& obj);
void from_json(const Json& jsonData, StatChangeEntry& obj);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_DECL(StatChangeEntry, StatChangeEntry);

};

#endif
