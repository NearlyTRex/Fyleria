// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

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
