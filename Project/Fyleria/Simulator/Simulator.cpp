// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Simulator/Simulator.h"

namespace Gecko
{

Simulator::Simulator()
{
}

Simulator::Simulator(const Json& jsonData)
{
}

void Simulator::Prepare()
{
    // Initialize app
    GetApplication().InitializeForSimulator();
}

void Simulator::Shutdown()
{
    // Finalize app
    GetApplication().Finalize();
}

void Simulator::Run()
{
}

void to_json(Json& jsonData, const Simulator& obj)
{
}

void from_json(const Json& jsonData, Simulator& obj)
{
}

};
