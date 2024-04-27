// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_UTILITY_POLYMORPHIC_BASE_H_
#define _GECKO_UTILITY_POLYMORPHIC_BASE_H_

// Internal includes
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
    PolymorphicBase(const String& sName);
    PolymorphicBase(const Json& jsonData);
};

// JSON Converters
void to_json(Json& jsonData, const PolymorphicBase& obj);
void from_json(const Json& jsonData, PolymorphicBase& obj);

};

#endif
