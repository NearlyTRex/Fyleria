// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Config/Config.h"
#include "Config/ConfigConstants.h"
#include "Utility/JsonMacros.h"

namespace Gecko
{

Config::Config()
{
    // Set defaults
    SetScreenWidth(DEFAULT_SCREEN_WIDTH);
    SetScreenHeight(DEFAULT_SCREEN_HEIGHT);
}

Config::Config(const Json& jsonData)
{
    from_json(jsonData, *this);
}

Config::Config(const String& jsonString)
{
    from_json(JsonParse(jsonString), *this);
}

Config::~Config()
{
}

void to_json(Json& jsonData, const Config& obj)
{
    // Screen dimensions
    SET_JSON_DATA(ScreenWidth);
    SET_JSON_DATA(ScreenHeight);
}

void from_json(const Json& jsonData, Config& obj)
{
    // Screen dimensions
    SET_OBJ_DATA(ScreenWidth, Int);
    SET_OBJ_DATA(ScreenHeight, Int);
}

};
