// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_CONFIG_CONFIG_H_
#define _GECKO_CONFIG_CONFIG_H_

// Internal includes
#include "Utility/Macros.h"
#include "Utility/Enum.h"
#include "Utility/Json.h"

namespace Gecko
{

// Config
class Config
{
public:

    // Constructors
    Config();
    Config(const Json& jsonData);
    Config(const String& jsonString);

    // Destructor
    virtual ~Config();

    // Screen dimensions
    MAKE_RAW_TYPE_ACCESSORS(ScreenWidth, Int);
    MAKE_RAW_TYPE_ACCESSORS(ScreenHeight, Int);
};

// Typedef
MAKE_COMMON_TYPEDEFS(Config);

// JSON Converters
void to_json(Json& jsonData, const Config& obj);
void from_json(const Json& jsonData, Config& obj);

};

#endif
