// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Utility/Wrapper.h"
#include "CharacterData/CharacterActionDataWrapper.h"
#include "CharacterData/CharacterBasicDataWrapper.h"
#include "CharacterData/CharacterBattleDataWrapper.h"
#include "CharacterData/CharacterMediaDataWrapper.h"
#include "CharacterData/CharacterProgressDataWrapper.h"
#include "CharacterData/CharacterSkillDataWrapper.h"
#include "CharacterData/CharacterStatChangeDataWrapper.h"

namespace Gecko
{

BoostProgramOptionsDescription GetWrapperOptions()
{
    BoostProgramOptionsDescription options("Wrapper options");
    options.add_options()
        ("generate_wrappers,g", "Generate wrapper files")
    ;
    return options;
}

void HandleWrapperOptions(const BoostProgramOptionsDescription& options, const BoostProgramOptionsVariablesMap& vm)
{
    // Generate wrappers
    if(vm.count("generate_wrappers"))
    {
        WriteWrapperFiles();
        STDExit(EXIT_SUCCESS);
    }
}

void WriteWrapperFiles()
{
    // CharacterData
    WriteCharacterActionDataWrapper();
    WriteCharacterBasicDataWrapper();
    WriteCharacterBattleDataWrapper();
    WriteCharacterMediaDataWrapper();
    WriteCharacterProgressDataWrapper();
    WriteCharacterSkillDataWrapper();
    WriteCharacterStatChangeDataWrapper();
}

};
