// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_STAT_NAMES_H_
#define _GECKO_STAT_NAMES_H_

#include "Utility/Types.h"
#include "Utility/IndexedString.h"

namespace Gecko
{

// Stat names
STDUnorderedSet<IndexedString, IndexedStringHasher>& GetBoolStatNames();
STDUnorderedSet<IndexedString, IndexedStringHasher>& GetByteStatNames();
STDUnorderedSet<IndexedString, IndexedStringHasher>& GetShortStatNames();
STDUnorderedSet<IndexedString, IndexedStringHasher>& GetIntStatNames();
STDUnorderedSet<IndexedString, IndexedStringHasher>& GetLongStatNames();
STDUnorderedSet<IndexedString, IndexedStringHasher>& GetLongLongStatNames();
STDUnorderedSet<IndexedString, IndexedStringHasher>& GetUByteStatNames();
STDUnorderedSet<IndexedString, IndexedStringHasher>& GetUShortStatNames();
STDUnorderedSet<IndexedString, IndexedStringHasher>& GetUIntStatNames();
STDUnorderedSet<IndexedString, IndexedStringHasher>& GetULongStatNames();
STDUnorderedSet<IndexedString, IndexedStringHasher>& GetULongLongStatNames();
STDUnorderedSet<IndexedString, IndexedStringHasher>& GetFloatStatNames();
STDUnorderedSet<IndexedString, IndexedStringHasher>& GetDoubleStatNames();
STDUnorderedSet<IndexedString, IndexedStringHasher>& GetLongDoubleStatNames();
STDUnorderedSet<IndexedString, IndexedStringHasher>& GetIndexedStringStatNames();
STDUnorderedSet<IndexedString, IndexedStringHasher>& GetIndexedStringArrayStatNames();

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
