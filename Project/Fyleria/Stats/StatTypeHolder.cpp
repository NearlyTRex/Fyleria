// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Stats/StatTypeHolder.h"

namespace Gecko
{

StatTypeHolder::StatTypeHolder()
{
}

StatTypeHolder::~StatTypeHolder()
{
}

Bool StatTypeHolder::GetBoolStatValue(const String& sStat, Bool& bValue) const
{
    return GetStatValue<Bool>(GetBoolStats(), sStat, bValue);
}

Bool StatTypeHolder::GetByteStatValue(const String& sStat, Byte& iValue) const
{
    return GetStatValue<Byte>(GetByteStats(), sStat, iValue);
}

Bool StatTypeHolder::GetShortStatValue(const String& sStat, Short& iValue) const
{
    return GetStatValue<Short>(GetShortStats(), sStat, iValue);
}

Bool StatTypeHolder::GetIntStatValue(const String& sStat, Int& iValue) const
{
    return GetStatValue<Int>(GetIntStats(), sStat, iValue);
}

Bool StatTypeHolder::GetFloatStatValue(const String& sStat, Float& fValue) const
{
    return GetStatValue<Float>(GetFloatStats(), sStat, fValue);
}

Bool StatTypeHolder::GetDoubleStatValue(const String& sStat, Double& fValue) const
{
    return GetStatValue<Double>(GetDoubleStats(), sStat, fValue);
}

Bool StatTypeHolder::GetStringStatValue(const String& sStat, String& sValue) const
{
    return GetStatValue<String>(GetStringStats(), sStat, sValue);
}

Bool StatTypeHolder::GetStringArrayStatValue(const String& sStat, StringArray& vValues) const
{
    return GetStatValue<StringArray>(GetStringArrayStats(), sStat, vValues);
}

Bool StatTypeHolder::SetBoolStatValue(const String& sStat, const Bool& bValue)
{
    return SetStatValue<Bool>(GetBoolStats(), sStat, bValue);
}

Bool StatTypeHolder::SetByteStatValue(const String& sStat, const Byte& iValue)
{
    return SetStatValue<Byte>(GetByteStats(), sStat, iValue);
}

Bool StatTypeHolder::SetShortStatValue(const String& sStat, const Short& iValue)
{
    return SetStatValue<Short>(GetShortStats(), sStat, iValue);
}

Bool StatTypeHolder::SetIntStatValue(const String& sStat, const Int& iValue)
{
    return SetStatValue<Int>(GetIntStats(), sStat, iValue);
}

Bool StatTypeHolder::SetFloatStatValue(const String& sStat, const Float& fValue)
{
    return SetStatValue<Float>(GetFloatStats(), sStat, fValue);
}

Bool StatTypeHolder::SetDoubleStatValue(const String& sStat, const Double& fValue)
{
    return SetStatValue<Double>(GetDoubleStats(), sStat, fValue);
}

Bool StatTypeHolder::SetStringStatValue(const String& sStat, const String& sValue)
{
    return SetStatValue<String>(GetStringStats(), sStat, sValue);
}

Bool StatTypeHolder::SetStringArrayStatValue(const String& sStat, const StringArray& vValues)
{
    return SetStatValue<StringArray>(GetStringArrayStats(), sStat, vValues);
}

};
