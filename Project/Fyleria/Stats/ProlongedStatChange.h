// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_PROLONGED_STAT_CHANGE_H_
#define _GECKO_PROLONGED_STAT_CHANGE_H_

#include "Stats/StatChangeEntry.h"
#include "Utility/Json.h"
#include "Utility/Serializable.h"

namespace Gecko
{

// JSON class for prolonged stat changes
class ProlongedStatChange : public SerializableToJson
{
public:
    // Constructors
    ProlongedStatChange();
    ProlongedStatChange(const Json& jsonData);

    // Relevant stat change
    MAKE_JSON_BASIC_TYPE_ACCESSORS(StatChangeEntry, StatChangeEntry);

    // Valid round
    MAKE_JSON_BASIC_TYPE_ACCESSORS(Round, Int);

    // Valid attack
    MAKE_JSON_BASIC_TYPE_ACCESSORS(Attack, Int);

    // Valid defend
    MAKE_JSON_BASIC_TYPE_ACCESSORS(Defend, Int);
};

// Typedefs
MAKE_TYPE_TYPEDEFS(ProlongedStatChange);

// JSON Converters
MAKE_JSON_OBJ_TYPE_CONVERTERS_DECL(ProlongedStatChange);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_DECL(ProlongedStatChange, ProlongedStatChange);

};

#endif
