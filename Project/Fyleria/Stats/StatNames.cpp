// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "Stats/StatNames.h"

namespace Gecko
{

STDUnorderedSet<String> s_tBoolStatNames = {};
STDUnorderedSet<String> s_tByteStatNames = {};
STDUnorderedSet<String> s_tShortStatNames = {};
STDUnorderedSet<String> s_tIntStatNames = {};
STDUnorderedSet<String> s_tLongStatNames = {};
STDUnorderedSet<String> s_tLongLongStatNames = {};
STDUnorderedSet<String> s_tUByteStatNames = {};
STDUnorderedSet<String> s_tUShortStatNames = {};
STDUnorderedSet<String> s_tUIntStatNames = {};
STDUnorderedSet<String> s_tULongStatNames = {};
STDUnorderedSet<String> s_tULongLongStatNames = {};
STDUnorderedSet<String> s_tFloatStatNames = {};
STDUnorderedSet<String> s_tDoubleStatNames = {};
STDUnorderedSet<String> s_tLongDoubleStatNames = {};
STDUnorderedSet<String> s_tIndexedStringStatNames = {};
STDUnorderedSet<String> s_tIndexedStringArrayStatNames = {};

STDUnorderedSet<String>& GetBoolStatNames() { return s_tBoolStatNames; }
STDUnorderedSet<String>& GetByteStatNames() { return s_tByteStatNames; }
STDUnorderedSet<String>& GetShortStatNames() { return s_tShortStatNames; }
STDUnorderedSet<String>& GetIntStatNames() { return s_tIntStatNames; }
STDUnorderedSet<String>& GetLongStatNames() { return s_tLongStatNames; }
STDUnorderedSet<String>& GetLongLongStatNames() { return s_tLongLongStatNames; }
STDUnorderedSet<String>& GetUByteStatNames() { return s_tUByteStatNames; }
STDUnorderedSet<String>& GetUShortStatNames() { return s_tUShortStatNames; }
STDUnorderedSet<String>& GetUIntStatNames() { return s_tUIntStatNames; }
STDUnorderedSet<String>& GetULongStatNames() { return s_tULongStatNames; }
STDUnorderedSet<String>& GetULongLongStatNames() { return s_tULongLongStatNames; }
STDUnorderedSet<String>& GetFloatStatNames() { return s_tFloatStatNames; }
STDUnorderedSet<String>& GetDoubleStatNames() { return s_tDoubleStatNames; }
STDUnorderedSet<String>& GetLongDoubleStatNames() { return s_tLongDoubleStatNames; }
STDUnorderedSet<String>& GetIndexedStringStatNames() { return s_tIndexedStringStatNames; }
STDUnorderedSet<String>& GetIndexedStringArrayStatNames() { return s_tIndexedStringArrayStatNames; }

Bool IsStatBool(const IndexedString& sStat) { return (GetBoolStatNames().find(sStat.Get()) != GetBoolStatNames().end()); }
Bool IsStatByte(const IndexedString& sStat) { return (GetByteStatNames().find(sStat.Get()) != GetByteStatNames().end()); }
Bool IsStatShort(const IndexedString& sStat) { return (GetShortStatNames().find(sStat.Get()) != GetShortStatNames().end()); }
Bool IsStatInt(const IndexedString& sStat) { return (GetIntStatNames().find(sStat.Get()) != GetIntStatNames().end()); }
Bool IsStatLong(const IndexedString& sStat) { return (GetLongStatNames().find(sStat.Get()) != GetLongStatNames().end()); }
Bool IsStatLongLong(const IndexedString& sStat) { return (GetLongLongStatNames().find(sStat.Get()) != GetLongLongStatNames().end()); }
Bool IsStatUByte(const IndexedString& sStat) { return (GetUByteStatNames().find(sStat.Get()) != GetUByteStatNames().end()); }
Bool IsStatUShort(const IndexedString& sStat) { return (GetUShortStatNames().find(sStat.Get()) != GetUShortStatNames().end()); }
Bool IsStatUInt(const IndexedString& sStat) { return (GetUIntStatNames().find(sStat.Get()) != GetUIntStatNames().end()); }
Bool IsStatULong(const IndexedString& sStat) { return (GetULongStatNames().find(sStat.Get()) != GetULongStatNames().end()); }
Bool IsStatULongLong(const IndexedString& sStat) { return (GetULongLongStatNames().find(sStat.Get()) != GetULongLongStatNames().end()); }
Bool IsStatFloat(const IndexedString& sStat) { return (GetFloatStatNames().find(sStat.Get()) != GetFloatStatNames().end()); }
Bool IsStatDouble(const IndexedString& sStat) { return (GetDoubleStatNames().find(sStat.Get()) != GetDoubleStatNames().end()); }
Bool IsStatLongDouble(const IndexedString& sStat) { return (GetLongDoubleStatNames().find(sStat.Get()) != GetLongDoubleStatNames().end()); }
Bool IsStatIndexedString(const IndexedString& sStat) { return (GetIndexedStringStatNames().find(sStat.Get()) != GetIndexedStringStatNames().end()); }
Bool IsStatIndexedStringArray(const IndexedString& sStat) { return (GetIndexedStringArrayStatNames().find(sStat.Get()) != GetIndexedStringArrayStatNames().end()); }

};
