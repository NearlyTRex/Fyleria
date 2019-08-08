// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Utility/PolymorphicBase.h"

namespace Gecko
{

PolymorphicBase::PolymorphicBase()
{
}

PolymorphicBase::PolymorphicBase(const String& sName)
{
}

PolymorphicBase::PolymorphicBase(const Json& jsonData)
{
    from_json(jsonData, *this);
}

void to_json(Json& jsonData, const PolymorphicBase& obj)
{
}

void from_json(const Json& jsonData, PolymorphicBase& obj)
{
}

};
