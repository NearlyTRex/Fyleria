// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Stats/StatNames.h"
#include "CharacterData/CharacterBasicData.h"
#include "CharacterData/CharacterProgressData.h"
#include "CharacterData/CharacterBattleData.h"

namespace Gecko
{

static SafeStatNameSetType s_pBoolStatNames = {};
static SafeStatNameSetType s_pByteStatNames = {};
static SafeStatNameSetType s_pShortStatNames = {};
static SafeStatNameSetType s_pIntStatNames = {};
static SafeStatNameSetType s_pLongStatNames = {};
static SafeStatNameSetType s_pLongLongStatNames = {};
static SafeStatNameSetType s_pUByteStatNames = {};
static SafeStatNameSetType s_pUShortStatNames = {};
static SafeStatNameSetType s_pUIntStatNames = {};
static SafeStatNameSetType s_pULongStatNames = {};
static SafeStatNameSetType s_pULongLongStatNames = {};
static SafeStatNameSetType s_pFloatStatNames = {};
static SafeStatNameSetType s_pDoubleStatNames = {};
static SafeStatNameSetType s_pLongDoubleStatNames = {};
static SafeStatNameSetType s_pIndexedStringStatNames = {};
static SafeStatNameSetType s_pIndexedStringArrayStatNames = {};

SafeStatNameSetType& GetBoolStatNames() { return s_pBoolStatNames; }
SafeStatNameSetType& GetByteStatNames() { return s_pByteStatNames; }
SafeStatNameSetType& GetShortStatNames() { return s_pShortStatNames; }
SafeStatNameSetType& GetIntStatNames() { return s_pIntStatNames; }
SafeStatNameSetType& GetLongStatNames() { return s_pLongStatNames; }
SafeStatNameSetType& GetLongLongStatNames() { return s_pLongLongStatNames; }
SafeStatNameSetType& GetUByteStatNames() { return s_pUByteStatNames; }
SafeStatNameSetType& GetUShortStatNames() { return s_pUShortStatNames; }
SafeStatNameSetType& GetUIntStatNames() { return s_pUIntStatNames; }
SafeStatNameSetType& GetULongStatNames() { return s_pULongStatNames; }
SafeStatNameSetType& GetULongLongStatNames() { return s_pULongLongStatNames; }
SafeStatNameSetType& GetFloatStatNames() { return s_pFloatStatNames; }
SafeStatNameSetType& GetDoubleStatNames() { return s_pDoubleStatNames; }
SafeStatNameSetType& GetLongDoubleStatNames() { return s_pLongDoubleStatNames; }
SafeStatNameSetType& GetIndexedStringStatNames() { return s_pIndexedStringStatNames; }
SafeStatNameSetType& GetIndexedStringArrayStatNames() { return s_pIndexedStringArrayStatNames; }

Bool IsStatBool(const IndexedString& sStat) { return (GetBoolStatNames()->find(sStat) != GetBoolStatNames()->end()); }
Bool IsStatByte(const IndexedString& sStat) { return (GetByteStatNames()->find(sStat) != GetByteStatNames()->end()); }
Bool IsStatShort(const IndexedString& sStat) { return (GetShortStatNames()->find(sStat) != GetShortStatNames()->end()); }
Bool IsStatInt(const IndexedString& sStat) { return (GetIntStatNames()->find(sStat) != GetIntStatNames()->end()); }
Bool IsStatLong(const IndexedString& sStat) { return (GetLongStatNames()->find(sStat) != GetLongStatNames()->end()); }
Bool IsStatLongLong(const IndexedString& sStat) { return (GetLongLongStatNames()->find(sStat) != GetLongLongStatNames()->end()); }
Bool IsStatUByte(const IndexedString& sStat) { return (GetUByteStatNames()->find(sStat) != GetUByteStatNames()->end()); }
Bool IsStatUShort(const IndexedString& sStat) { return (GetUShortStatNames()->find(sStat) != GetUShortStatNames()->end()); }
Bool IsStatUInt(const IndexedString& sStat) { return (GetUIntStatNames()->find(sStat) != GetUIntStatNames()->end()); }
Bool IsStatULong(const IndexedString& sStat) { return (GetULongStatNames()->find(sStat) != GetULongStatNames()->end()); }
Bool IsStatULongLong(const IndexedString& sStat) { return (GetULongLongStatNames()->find(sStat) != GetULongLongStatNames()->end()); }
Bool IsStatFloat(const IndexedString& sStat) { return (GetFloatStatNames()->find(sStat) != GetFloatStatNames()->end()); }
Bool IsStatDouble(const IndexedString& sStat) { return (GetDoubleStatNames()->find(sStat) != GetDoubleStatNames()->end()); }
Bool IsStatLongDouble(const IndexedString& sStat) { return (GetLongDoubleStatNames()->find(sStat) != GetLongDoubleStatNames()->end()); }
Bool IsStatIndexedString(const IndexedString& sStat) { return (GetIndexedStringStatNames()->find(sStat) != GetIndexedStringStatNames()->end()); }
Bool IsStatIndexedStringArray(const IndexedString& sStat) { return (GetIndexedStringArrayStatNames()->find(sStat) != GetIndexedStringArrayStatNames()->end()); }

void InitializeAllStatNames()
{
    CharacterBasicData::InitAllStatNames();
    CharacterProgressData::InitAllStatNames();
    CharacterBattleData::InitAllStatNames();
}

};
