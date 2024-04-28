// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_SIMULATOR_SIMULATOR_H_
#define _GECKO_SIMULATOR_SIMULATOR_H_

// Internal includes
#include "Utility/Macros.h"
#include "Utility/Enum.h"
#include "Utility/Json.h"
#include "Utility/Types.h"

namespace Gecko
{

// Simulator
class Simulator
{
public:

    // Constructors
    Simulator();
    Simulator(const Json& jsonData);

    // Prepare
    virtual void Prepare() = 0;

    // Run
    virtual void Run() = 0;
};

// Typedef
MAKE_COMMON_TYPEDEFS(Simulator);

// JSON Converters
void to_json(Json& jsonData, const Simulator& obj);
void from_json(const Json& jsonData, Simulator& obj);

};

#endif
