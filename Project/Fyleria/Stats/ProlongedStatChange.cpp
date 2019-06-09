// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Stats/ProlongedStatChange.h"

namespace Gecko
{

ProlongedStatChange::ProlongedStatChange()
    : SerializableToJson()
{
}

ProlongedStatChange::ProlongedStatChange(const Json& jsonData)
    : SerializableToJson(jsonData)
{
}

MAKE_JSON_OBJ_TYPE_CONVERTERS_IMPL(ProlongedStatChange);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(ProlongedStatChange, ProlongedStatChange);

};
