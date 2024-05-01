// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Simulator/SimulatorMain.h"
#include "Simulator/BattleSimulator.h"

namespace Gecko
{

void RunBattleSimulation()
{
    // Run battle simulation
    BattleSimulator sim;
    sim.Prepare();
    sim.Run();
}

BoostProgramOptionsDescription GetSimulatorOptions()
{
    // Get options
    BoostProgramOptionsDescription options("Simulator options");
    options.add_options()
        ("simulate_battle,b", "Simulate battle")
    ;
    return options;
}

void HandleSimulatorOptions(const BoostProgramOptionsDescription& options, const BoostProgramOptionsVariablesMap& vm)
{
    // Run battle simulation
    if(vm.count("simulate_battle"))
    {
        RunBattleSimulation();
        STDExit(EXIT_SUCCESS);
    }
}

};
