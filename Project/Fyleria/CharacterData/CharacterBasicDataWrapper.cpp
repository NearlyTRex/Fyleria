// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "CharacterData/CharacterBasicDataWrapper.h"
#include "Application/Application.h"
#include "Utility/Types.h"

namespace Gecko
{

// Start wrapper
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_START(CharacterData, CharacterBasicData);

// String stats
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(CharacterID);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(PartyID);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(FirstName);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(LastName);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(Gender);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(Hair);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(Eyes);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(Handedness);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(BaseRace);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(TransformedRace);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(PowerSet);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(WeaponSet);

// Int stats
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(Age);

// Finish wrapper
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_END();

};
