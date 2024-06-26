// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "CharacterData/CharacterProgressDataWrapper.h"
#include "Application/Application.h"
#include "Utility/Types.h"

namespace Gecko
{

// Start wrapper
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_START(CharacterData, CharacterProgressData);

// Int stats
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(HealthPointsCurrent);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(MagicPointsCurrent);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(EnergyPointsCurrent);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(HealthPointsMax);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(MagicPointsMax);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(EnergyPointsMax);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(HealthRegen);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(MagicRegen);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(EnergyRegen);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(HealthCostDelta);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(MagicCostDelta);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(EnergyCostDelta);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(SpeedCurrent);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(SpeedBase);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(AmberValueDelta);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(RubyValueDelta);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(DiamondValueDelta);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(CitrineValueDelta);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(OnyxValueDelta);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(QuartzValueDelta);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(SapphireValueDelta);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(AmethystValueDelta);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(EmeraldValueDelta);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(GarnetValueDelta);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(IvoryValueDelta);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(OpalValueDelta);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(BluntAttack);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(BluntDefense);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(MagicAttack);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(MagicDefense);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(PierceAttack);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(PierceDefense);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(SlashAttack);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(SlashDefense);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(EnergyAttack);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(EnergyDefense);

// Finish wrapper
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_END();

};
