// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_UTILITY_ENUMS_H_
#define _GECKO_UTILITY_ENUMS_H_

// External includes
#include <enum.h>

// Internal includes
#include "Utility/Types.h"

// External defines
#define MAKE_ENUM BETTER_ENUM

// External macros
#define MAKE_ENUM_CONVERTERS_PROTO(type)    String GetEnumString(type arg)
#define MAKE_ENUM_CONVERTERS_IMPL(type)     String GetEnumString(type arg) { return arg._to_string(); }

namespace Gecko
{

template <typename T>
StringArray GetEnumNames()
{
    StringArray vTypeNames;
    for (const char* name : T::_names())
    {
        vTypeNames.push_back(name);
    }
    return vTypeNames;
}

template <typename T>
T GetEnumFromString(const String& sType)
{
    return T::_from_string(sType.c_str());
}

template <typename T>
T GetEnumFromStringOrNone(const String& sType)
{
    if(T::_is_valid(sType.c_str()))
    {
        return T::_from_string(sType.c_str());
    }
    return +T::None;
}

template <typename T>
Bool IsValidEnumString(const String& sType)
{
    return T::_is_valid(sType.c_str());
}

template <typename T>
Bool IsNoneTypeForEnum(const String& sType)
{
    return (sType == (+T::None)._to_string());
}

template <typename T>
String GetNoneTypeForEnum()
{
    return (+T::None)._to_string();
}

};

#endif
