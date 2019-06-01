// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Stats/StatTypeHolder.h"

namespace Gecko
{

StatTypeHolder::StatTypeHolder()
{
}

Bool StatTypeHolder::GetBoolStatValue(const IndexedString& sStat, Bool& bValue) const
{
    return GetStatValue<Bool>(GetStats(), sStat, bValue);
}

Bool StatTypeHolder::GetByteStatValue(const IndexedString& sStat, Byte& iValue) const
{
    return GetStatValue<Byte>(GetStats(), sStat, iValue);
}

Bool StatTypeHolder::GetShortStatValue(const IndexedString& sStat, Short& iValue) const
{
    return GetStatValue<Short>(GetStats(), sStat, iValue);
}

Bool StatTypeHolder::GetIntStatValue(const IndexedString& sStat, Int& iValue) const
{
    return GetStatValue<Int>(GetStats(), sStat, iValue);
}

Bool StatTypeHolder::GetFloatStatValue(const IndexedString& sStat, Float& fValue) const
{
    return GetStatValue<Float>(GetStats(), sStat, fValue);
}

Bool StatTypeHolder::GetDoubleStatValue(const IndexedString& sStat, Double& fValue) const
{
    return GetStatValue<Double>(GetStats(), sStat, fValue);
}

Bool StatTypeHolder::GetIndexedStringStatValue(const IndexedString& sStat, IndexedString& sValue) const
{
    return GetStatValue<IndexedString>(GetStats(), sStat, sValue);
}

Bool StatTypeHolder::GetIndexedStringArrayStatValue(const IndexedString& sStat, IndexedStringArray& vValues) const
{
    return GetStatValue<IndexedStringArray>(GetStats(), sStat, vValues);
}

Bool StatTypeHolder::SetBoolStatValue(const IndexedString& sStat, const Bool& bValue)
{
    return SetStatValue<Bool>(GetStats(), sStat, bValue);
}

Bool StatTypeHolder::SetByteStatValue(const IndexedString& sStat, const Byte& iValue)
{
    return SetStatValue<Byte>(GetStats(), sStat, iValue);
}

Bool StatTypeHolder::SetShortStatValue(const IndexedString& sStat, const Short& iValue)
{
    return SetStatValue<Short>(GetStats(), sStat, iValue);
}

Bool StatTypeHolder::SetIntStatValue(const IndexedString& sStat, const Int& iValue)
{
    return SetStatValue<Int>(GetStats(), sStat, iValue);
}

Bool StatTypeHolder::SetFloatStatValue(const IndexedString& sStat, const Float& fValue)
{
    return SetStatValue<Float>(GetStats(), sStat, fValue);
}

Bool StatTypeHolder::SetDoubleStatValue(const IndexedString& sStat, const Double& fValue)
{
    return SetStatValue<Double>(GetStats(), sStat, fValue);
}

Bool StatTypeHolder::SetIndexedStringStatValue(const IndexedString& sStat, const IndexedString& sValue)
{
    return SetStatValue<IndexedString>(GetStats(), sStat, sValue);
}

Bool StatTypeHolder::SetIndexedStringArrayStatValue(const IndexedString& sStat, const IndexedStringArray& vValues)
{
    return SetStatValue<IndexedStringArray>(GetStats(), sStat, vValues);
}

};
