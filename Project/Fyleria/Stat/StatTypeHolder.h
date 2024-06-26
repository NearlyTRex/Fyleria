// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_STAT_STAT_TYPE_HOLDER_H_
#define _GECKO_STAT_STAT_TYPE_HOLDER_H_

// Internal includes
#include "Stat/StatType.h"
#include "Stat/StatNames.h"
#include "Utility/Types.h"
#include "Utility/Macros.h"
#include "Utility/Enum.h"
#include "Utility/Errors.h"
#include "Utility/Json.h"

namespace Gecko
{

// Stat type holder
class StatTypeHolder
{
public:

    // Constructor
    StatTypeHolder();

    // Destructor
    virtual ~StatTypeHolder();

    // Clear all data
    virtual void Clear();

    // Get stat values
    Bool GetStatValue(const String& sStat, Bool& bValue) const;
    Bool GetStatValue(const String& sStat, Byte& iValue) const;
    Bool GetStatValue(const String& sStat, Short& iValue) const;
    Bool GetStatValue(const String& sStat, Int& iValue) const;
    Bool GetStatValue(const String& sStat, Float& fValue) const;
    Bool GetStatValue(const String& sStat, Double& fValue) const;
    Bool GetStatValue(const String& sStat, String& sValue) const;
    Bool GetStatValue(const String& sStat, StringArray& vValues) const;

    // Get stat value
    template <class T>
    T GetStatValue(const String& sStat) const
    {
        T varStat {};
        GetStatValue(sStat, varStat);
        return varStat;
    }

    // Set stat values
    Bool SetStatValue(const String& sStat, const Bool& bValue);
    Bool SetStatValue(const String& sStat, const Byte& iValue);
    Bool SetStatValue(const String& sStat, const Short& iValue);
    Bool SetStatValue(const String& sStat, const Int& iValue);
    Bool SetStatValue(const String& sStat, const Float& fValue);
    Bool SetStatValue(const String& sStat, const Double& fValue);
    Bool SetStatValue(const String& sStat, const String& sValue);
    Bool SetStatValue(const String& sStat, const StringArray& vValues);

    // Increment stat values
    Bool IncrementStatValue(const String& sStat, const Byte& iValue);
    Bool IncrementStatValue(const String& sStat, const Short& iValue);
    Bool IncrementStatValue(const String& sStat, const Int& iValue);
    Bool IncrementStatValue(const String& sStat, const Float& iValue);
    Bool IncrementStatValue(const String& sStat, const Double& iValue);

    // Decrement stat values
    Bool DecrementStatValue(const String& sStat, const Byte& iValue);
    Bool DecrementStatValue(const String& sStat, const Short& iValue);
    Bool DecrementStatValue(const String& sStat, const Int& iValue);
    Bool DecrementStatValue(const String& sStat, const Float& iValue);
    Bool DecrementStatValue(const String& sStat, const Double& iValue);

    // Stat types
    MAKE_RAW_TYPE_ACCESSORS(BoolStats, StringBoolUnorderedMap);
    MAKE_RAW_TYPE_ACCESSORS(ByteStats, StringByteUnorderedMap);
    MAKE_RAW_TYPE_ACCESSORS(ShortStats, StringShortUnorderedMap);
    MAKE_RAW_TYPE_ACCESSORS(IntStats, StringIntUnorderedMap);
    MAKE_RAW_TYPE_ACCESSORS(FloatStats, StringFloatUnorderedMap);
    MAKE_RAW_TYPE_ACCESSORS(DoubleStats, StringDoubleUnorderedMap);
    MAKE_RAW_TYPE_ACCESSORS(StringStats, StringStringUnorderedMap);
    MAKE_RAW_TYPE_ACCESSORS(StringArrayStats, StringStringArrayUnorderedMap);
};

};

#endif
