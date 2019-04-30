// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "Stats/StatNames.h"

namespace Gecko
{

STDUnorderedSet<IndexedString, IndexedStringHasher> s_tBoolStatNames = {};
STDUnorderedSet<IndexedString, IndexedStringHasher> s_tByteStatNames = {};
STDUnorderedSet<IndexedString, IndexedStringHasher> s_tShortStatNames = {};
STDUnorderedSet<IndexedString, IndexedStringHasher> s_tIntStatNames = {};
STDUnorderedSet<IndexedString, IndexedStringHasher> s_tLongStatNames = {};
STDUnorderedSet<IndexedString, IndexedStringHasher> s_tLongLongStatNames = {};
STDUnorderedSet<IndexedString, IndexedStringHasher> s_tUByteStatNames = {};
STDUnorderedSet<IndexedString, IndexedStringHasher> s_tUShortStatNames = {};
STDUnorderedSet<IndexedString, IndexedStringHasher> s_tUIntStatNames = {};
STDUnorderedSet<IndexedString, IndexedStringHasher> s_tULongStatNames = {};
STDUnorderedSet<IndexedString, IndexedStringHasher> s_tULongLongStatNames = {};
STDUnorderedSet<IndexedString, IndexedStringHasher> s_tFloatStatNames = {};
STDUnorderedSet<IndexedString, IndexedStringHasher> s_tDoubleStatNames = {};
STDUnorderedSet<IndexedString, IndexedStringHasher> s_tLongDoubleStatNames = {};
STDUnorderedSet<IndexedString, IndexedStringHasher> s_tIndexedStringStatNames = {};
STDUnorderedSet<IndexedString, IndexedStringHasher> s_tIndexedStringArrayStatNames = {};

STDUnorderedSet<IndexedString, IndexedStringHasher>& GetBoolStatNames() { return s_tBoolStatNames; }
STDUnorderedSet<IndexedString, IndexedStringHasher>& GetByteStatNames() { return s_tByteStatNames; }
STDUnorderedSet<IndexedString, IndexedStringHasher>& GetShortStatNames() { return s_tShortStatNames; }
STDUnorderedSet<IndexedString, IndexedStringHasher>& GetIntStatNames() { return s_tIntStatNames; }
STDUnorderedSet<IndexedString, IndexedStringHasher>& GetLongStatNames() { return s_tLongStatNames; }
STDUnorderedSet<IndexedString, IndexedStringHasher>& GetLongLongStatNames() { return s_tLongLongStatNames; }
STDUnorderedSet<IndexedString, IndexedStringHasher>& GetUByteStatNames() { return s_tUByteStatNames; }
STDUnorderedSet<IndexedString, IndexedStringHasher>& GetUShortStatNames() { return s_tUShortStatNames; }
STDUnorderedSet<IndexedString, IndexedStringHasher>& GetUIntStatNames() { return s_tUIntStatNames; }
STDUnorderedSet<IndexedString, IndexedStringHasher>& GetULongStatNames() { return s_tULongStatNames; }
STDUnorderedSet<IndexedString, IndexedStringHasher>& GetULongLongStatNames() { return s_tULongLongStatNames; }
STDUnorderedSet<IndexedString, IndexedStringHasher>& GetFloatStatNames() { return s_tFloatStatNames; }
STDUnorderedSet<IndexedString, IndexedStringHasher>& GetDoubleStatNames() { return s_tDoubleStatNames; }
STDUnorderedSet<IndexedString, IndexedStringHasher>& GetLongDoubleStatNames() { return s_tLongDoubleStatNames; }
STDUnorderedSet<IndexedString, IndexedStringHasher>& GetIndexedStringStatNames() { return s_tIndexedStringStatNames; }
STDUnorderedSet<IndexedString, IndexedStringHasher>& GetIndexedStringArrayStatNames() { return s_tIndexedStringArrayStatNames; }

Bool IsStatBool(const IndexedString& sStat) { return (GetBoolStatNames().find(sStat) != GetBoolStatNames().end()); }
Bool IsStatByte(const IndexedString& sStat) { return (GetByteStatNames().find(sStat) != GetByteStatNames().end()); }
Bool IsStatShort(const IndexedString& sStat) { return (GetShortStatNames().find(sStat) != GetShortStatNames().end()); }
Bool IsStatInt(const IndexedString& sStat) { return (GetIntStatNames().find(sStat) != GetIntStatNames().end()); }
Bool IsStatLong(const IndexedString& sStat) { return (GetLongStatNames().find(sStat) != GetLongStatNames().end()); }
Bool IsStatLongLong(const IndexedString& sStat) { return (GetLongLongStatNames().find(sStat) != GetLongLongStatNames().end()); }
Bool IsStatUByte(const IndexedString& sStat) { return (GetUByteStatNames().find(sStat) != GetUByteStatNames().end()); }
Bool IsStatUShort(const IndexedString& sStat) { return (GetUShortStatNames().find(sStat) != GetUShortStatNames().end()); }
Bool IsStatUInt(const IndexedString& sStat) { return (GetUIntStatNames().find(sStat) != GetUIntStatNames().end()); }
Bool IsStatULong(const IndexedString& sStat) { return (GetULongStatNames().find(sStat) != GetULongStatNames().end()); }
Bool IsStatULongLong(const IndexedString& sStat) { return (GetULongLongStatNames().find(sStat) != GetULongLongStatNames().end()); }
Bool IsStatFloat(const IndexedString& sStat) { return (GetFloatStatNames().find(sStat) != GetFloatStatNames().end()); }
Bool IsStatDouble(const IndexedString& sStat) { return (GetDoubleStatNames().find(sStat) != GetDoubleStatNames().end()); }
Bool IsStatLongDouble(const IndexedString& sStat) { return (GetLongDoubleStatNames().find(sStat) != GetLongDoubleStatNames().end()); }
Bool IsStatIndexedString(const IndexedString& sStat) { return (GetIndexedStringStatNames().find(sStat) != GetIndexedStringStatNames().end()); }
Bool IsStatIndexedStringArray(const IndexedString& sStat) { return (GetIndexedStringArrayStatNames().find(sStat) != GetIndexedStringArrayStatNames().end()); }

};
