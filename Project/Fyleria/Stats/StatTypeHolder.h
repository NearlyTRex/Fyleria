// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_STAT_TYPE_HOLDER_H_
#define _GECKO_STAT_TYPE_HOLDER_H_

#include "Stats/StatType.h"
#include "Stats/StatNames.h"
#include "Utility/Types.h"
#include "Utility/IndexedString.h"
#include "Utility/Macros.h"
#include "Utility/Enum.h"
#include "Utility/Json.h"

namespace Gecko
{

// Stat type holder
class StatTypeHolder
{
public:

    // Constructor
    StatTypeHolder();

    // Get stat values
    Bool GetBoolStatValue(const IndexedString& sStat, Bool& bValue) const;
    Bool GetByteStatValue(const IndexedString& sStat, Byte& iValue) const;
    Bool GetShortStatValue(const IndexedString& sStat, Short& iValue) const;
    Bool GetIntStatValue(const IndexedString& sStat, Int& iValue) const;
    Bool GetFloatStatValue(const IndexedString& sStat, Float& fValue) const;
    Bool GetDoubleStatValue(const IndexedString& sStat, Double& fValue) const;
    Bool GetIndexedStringStatValue(const IndexedString& sStat, IndexedString& sValue) const;
    Bool GetIndexedStringArrayStatValue(const IndexedString& sStat, IndexedStringArray& vValues) const;

    // Set stat values
    Bool SetBoolStatValue(const IndexedString& sStat, const Bool& bValue);
    Bool SetByteStatValue(const IndexedString& sStat, const Byte& iValue);
    Bool SetShortStatValue(const IndexedString& sStat, const Short& iValue);
    Bool SetIntStatValue(const IndexedString& sStat, const Int& iValue);
    Bool SetFloatStatValue(const IndexedString& sStat, const Float& fValue);
    Bool SetDoubleStatValue(const IndexedString& sStat, const Double& fValue);
    Bool SetIndexedStringStatValue(const IndexedString& sStat, const IndexedString& sValue);
    Bool SetIndexedStringArrayStatValue(const IndexedString& sStat, const IndexedStringArray& vValues);

    // Stat types
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(Stats, StatTypeMap);
};

};

#endif
