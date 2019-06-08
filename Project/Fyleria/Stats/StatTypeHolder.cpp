// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Stats/StatTypeHolder.h"

namespace Gecko
{

StatTypeHolder::StatTypeHolder()
{
}

Bool StatTypeHolder::GetBoolStatValue(const String& sStat, Bool& bValue) const
{
    return GetStatValue<Bool>(GetStats(), sStat, bValue);
}

Bool StatTypeHolder::GetByteStatValue(const String& sStat, Byte& iValue) const
{
    return GetStatValue<Byte>(GetStats(), sStat, iValue);
}

Bool StatTypeHolder::GetShortStatValue(const String& sStat, Short& iValue) const
{
    return GetStatValue<Short>(GetStats(), sStat, iValue);
}

Bool StatTypeHolder::GetIntStatValue(const String& sStat, Int& iValue) const
{
    return GetStatValue<Int>(GetStats(), sStat, iValue);
}

Bool StatTypeHolder::GetFloatStatValue(const String& sStat, Float& fValue) const
{
    return GetStatValue<Float>(GetStats(), sStat, fValue);
}

Bool StatTypeHolder::GetDoubleStatValue(const String& sStat, Double& fValue) const
{
    return GetStatValue<Double>(GetStats(), sStat, fValue);
}

Bool StatTypeHolder::GetStringStatValue(const String& sStat, String& sValue) const
{
    return GetStatValue<String>(GetStats(), sStat, sValue);
}

Bool StatTypeHolder::GetStringArrayStatValue(const String& sStat, StringArray& vValues) const
{
    return GetStatValue<StringArray>(GetStats(), sStat, vValues);
}

Bool StatTypeHolder::SetBoolStatValue(const String& sStat, const Bool& bValue)
{
    return SetStatValue<Bool>(GetStats(), sStat, bValue);
}

Bool StatTypeHolder::SetByteStatValue(const String& sStat, const Byte& iValue)
{
    return SetStatValue<Byte>(GetStats(), sStat, iValue);
}

Bool StatTypeHolder::SetShortStatValue(const String& sStat, const Short& iValue)
{
    return SetStatValue<Short>(GetStats(), sStat, iValue);
}

Bool StatTypeHolder::SetIntStatValue(const String& sStat, const Int& iValue)
{
    return SetStatValue<Int>(GetStats(), sStat, iValue);
}

Bool StatTypeHolder::SetFloatStatValue(const String& sStat, const Float& fValue)
{
    return SetStatValue<Float>(GetStats(), sStat, fValue);
}

Bool StatTypeHolder::SetDoubleStatValue(const String& sStat, const Double& fValue)
{
    return SetStatValue<Double>(GetStats(), sStat, fValue);
}

Bool StatTypeHolder::SetStringStatValue(const String& sStat, const String& sValue)
{
    return SetStatValue<String>(GetStats(), sStat, sValue);
}

Bool StatTypeHolder::SetStringArrayStatValue(const String& sStat, const StringArray& vValues)
{
    return SetStatValue<StringArray>(GetStats(), sStat, vValues);
}

};
