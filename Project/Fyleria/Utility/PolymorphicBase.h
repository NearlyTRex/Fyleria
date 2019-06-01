// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_UTILITY_POLYMORPHIC_BASE_H_
#define _GECKO_UTILITY_POLYMORPHIC_BASE_H_

#include "Utility/IndexedString.h"
#include "Utility/Macros.h"
#include "Utility/Json.h"

namespace Gecko
{

// Polymorphic base class
class PolymorphicBase
{
public:

    // Constructors
    PolymorphicBase();
    PolymorphicBase(const IndexedString& sName);
    PolymorphicBase(const Json& jsonData);

    // Type name
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(TypeName, IndexedString);
};

// JSON Converters
void to_json(Json& jsonData, const PolymorphicBase& obj);
void from_json(const Json& jsonData, PolymorphicBase& obj);

};

#endif
