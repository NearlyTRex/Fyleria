// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_STAT_STAT_TYPE_H_
#define _GECKO_STAT_STAT_TYPE_H_

// Internal includes
#include "Utility/Types.h"
#include "Utility/Enum.h"

namespace Gecko
{

MAKE_ENUM(StatOperationType, Int,
    None,
    Add,
    Subtract,
    Multiply,
    Divide,
    Modulus
);
MAKE_ENUM_CONVERTERS_PROTO(StatOperationType);

MAKE_ENUM(StatAssignmentType, Int,
    None,
    Set,
    Increment,
    Decrement
);
MAKE_ENUM_CONVERTERS_PROTO(StatAssignmentType);

};

#endif
