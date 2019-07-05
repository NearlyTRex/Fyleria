// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_STAT_TYPE_H_
#define _GECKO_STAT_TYPE_H_

// Internal includes
#include "Utility/Types.h"

namespace Gecko
{

// Typedefs
typedef STDUnorderedMap<String, Bool> BoolStatTypeMap;
typedef STDUnorderedMap<String, Byte> ByteStatTypeMap;
typedef STDUnorderedMap<String, Short> ShortStatTypeMap;
typedef STDUnorderedMap<String, Int> IntStatTypeMap;
typedef STDUnorderedMap<String, Float> FloatStatTypeMap;
typedef STDUnorderedMap<String, Double> DoubleStatTypeMap;
typedef STDUnorderedMap<String, String> StringStatTypeMap;
typedef STDUnorderedMap<String, StringArray> StringArrayStatTypeMap;

// Helper functions
template <class T>
Bool SetStatValue(STDUnorderedMap<String, T>& tStatMap, const String& sStatName, const T& inValue)
{
    if(tStatMap.find(sStatName) == tStatMap.end())
    {
        auto result = tStatMap.insert({sStatName, inValue});
        return (result.first != tStatMap.end());
    }
    else
    {
        tStatMap.at(sStatName) = inValue;
        return true;
    }
}
template <class T>
Bool GetStatValue(const STDUnorderedMap<String, T>& tStatMap, const String& sStatName, T& outValue)
{
    if(tStatMap.find(sStatName) == tStatMap.end())
    {
        return false;
    }
    outValue = tStatMap.at(sStatName);
    return true;
}

};

#endif
