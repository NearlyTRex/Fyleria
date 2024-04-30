// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_SIMULATOR_SIMULATOR_MAIN_H_
#define _GECKO_SIMULATOR_SIMULATOR_MAIN_H_

// Internal includes
#include "Utility/Boost.h"
#include "Utility/Types.h"

namespace Gecko
{

// Get simulator options
BoostProgramOptionsDescription GetSimulatorOptions();

// Handle simulator options
void HandleSimulatorOptions(const BoostProgramOptionsDescription& options, const BoostProgramOptionsVariablesMap& vm);

// Run battle simulation
void RunBattleSimulation();

};

#endif
