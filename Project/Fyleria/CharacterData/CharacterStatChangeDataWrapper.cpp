// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "CharacterData/CharacterStatChangeDataWrapper.h"
#include "Application/Application.h"
#include "Utility/Types.h"

namespace Gecko
{

// Start wrapper
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_START(CharacterData, CharacterStatChangeData);

// Passive data
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(PassiveSkillDataArray);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(PassiveItemDataArray);

// Active data
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(ActiveSkillDataArray);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(ActiveItemDataArray);

// Actionable data
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(ActionableSkillDataArray);
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(ActionableItemDataArray);

// Prolonged stat changes
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(ProlongedStatChanges);

// Finish wrapper
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_END();

};
