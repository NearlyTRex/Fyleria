// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_STAT_TYPE_HOLDER_H_
#define _GECKO_STAT_TYPE_HOLDER_H_

// Internal includes
#include "Stats/StatType.h"
#include "Stats/StatNames.h"
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

    // Get stat values
    Bool GetBoolStatValue(const String& sStat, Bool& bValue) const;
    Bool GetByteStatValue(const String& sStat, Byte& iValue) const;
    Bool GetShortStatValue(const String& sStat, Short& iValue) const;
    Bool GetIntStatValue(const String& sStat, Int& iValue) const;
    Bool GetFloatStatValue(const String& sStat, Float& fValue) const;
    Bool GetDoubleStatValue(const String& sStat, Double& fValue) const;
    Bool GetStringStatValue(const String& sStat, String& sValue) const;
    Bool GetStringArrayStatValue(const String& sStat, StringArray& vValues) const;

    // Set stat values
    Bool SetBoolStatValue(const String& sStat, const Bool& bValue);
    Bool SetByteStatValue(const String& sStat, const Byte& iValue);
    Bool SetShortStatValue(const String& sStat, const Short& iValue);
    Bool SetIntStatValue(const String& sStat, const Int& iValue);
    Bool SetFloatStatValue(const String& sStat, const Float& fValue);
    Bool SetDoubleStatValue(const String& sStat, const Double& fValue);
    Bool SetStringStatValue(const String& sStat, const String& sValue);
    Bool SetStringArrayStatValue(const String& sStat, const StringArray& vValues);

    // Stat types
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(BoolStats, BoolStatTypeMap);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ByteStats, ByteStatTypeMap);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ShortStats, ShortStatTypeMap);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(IntStats, IntStatTypeMap);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(FloatStats, FloatStatTypeMap);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(DoubleStats, DoubleStatTypeMap);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(StringStats, StringStatTypeMap);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(StringArrayStats, StringArrayStatTypeMap);
};

};

#endif
