// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_STAT_NAMES_H_
#define _GECKO_STAT_NAMES_H_

#include "Utility/Types.h"
#include "Utility/IndexedString.h"

namespace Gecko
{

// Stat names
STDUnorderedSet<String>& GetBoolStatNames();
STDUnorderedSet<String>& GetByteStatNames();
STDUnorderedSet<String>& GetShortStatNames();
STDUnorderedSet<String>& GetIntStatNames();
STDUnorderedSet<String>& GetLongStatNames();
STDUnorderedSet<String>& GetLongLongStatNames();
STDUnorderedSet<String>& GetUByteStatNames();
STDUnorderedSet<String>& GetUShortStatNames();
STDUnorderedSet<String>& GetUIntStatNames();
STDUnorderedSet<String>& GetULongStatNames();
STDUnorderedSet<String>& GetULongLongStatNames();
STDUnorderedSet<String>& GetFloatStatNames();
STDUnorderedSet<String>& GetDoubleStatNames();
STDUnorderedSet<String>& GetLongDoubleStatNames();
STDUnorderedSet<String>& GetIndexedStringStatNames();
STDUnorderedSet<String>& GetIndexedStringArrayStatNames();

// Determine stat value types
Bool IsStatBool(const IndexedString& sStat);
Bool IsStatByte(const IndexedString& sStat);
Bool IsStatShort(const IndexedString& sStat);
Bool IsStatInt(const IndexedString& sStat);
Bool IsStatLong(const IndexedString& sStat);
Bool IsStatLongLong(const IndexedString& sStat);
Bool IsStatUByte(const IndexedString& sStat);
Bool IsStatUShort(const IndexedString& sStat);
Bool IsStatUInt(const IndexedString& sStat);
Bool IsStatULong(const IndexedString& sStat);
Bool IsStatULongLong(const IndexedString& sStat);
Bool IsStatFloat(const IndexedString& sStat);
Bool IsStatDouble(const IndexedString& sStat);
Bool IsStatLongDouble(const IndexedString& sStat);
Bool IsStatIndexedString(const IndexedString& sStat);
Bool IsStatIndexedStringArray(const IndexedString& sStat);

};

#endif
