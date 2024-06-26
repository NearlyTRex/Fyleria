// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "CharacterData/CharacterMediaDataWrapper.h"
#include "Application/Application.h"
#include "Utility/Types.h"

namespace Gecko
{

// Start wrapper
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_START(CharacterData, CharacterMediaData);

// String stats
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(PortraitImage);

// Finish wrapper
MAKE_JSONDATA_WRAPPER_CLASS_IMPL_END();

};
