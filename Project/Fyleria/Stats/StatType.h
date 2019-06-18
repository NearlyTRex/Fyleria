// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_STAT_TYPE_H_
#define _GECKO_STAT_TYPE_H_

#include "Utility/Types.h"

namespace Gecko
{

// Stat type
class StatType
{
public:

    // Constructor
    StatType(const BoostAny& value)
        : m_DataValue(value)
    {}

    // Get data value
    const BoostAny& GetDataValue() const { return m_DataValue; }
    BoostAny& GetDataValue() { return m_DataValue; }

    // Set data value
    void SetDataValue(const BoostAny& val) { m_DataValue = val; }

private:

    // Data value
    BoostAny m_DataValue;
};

// Typedefs
typedef STDUnorderedMap<String, StatType> StatTypeMap;

// Helper functions
template <class T>
Bool SetStatValue(StatTypeMap& tStatMap, const String& sStatName, const T& inValue)
{
    if(tStatMap.find(sStatName) == tStatMap.end())
    {
        auto result = tStatMap.insert({sStatName, StatType(inValue)});
        return (result.first != tStatMap.end());
    }
    else
    {
        tStatMap.at(sStatName).SetDataValue(StatType(inValue));
        return true;
    }
}
template <class T>
Bool GetStatValue(const StatTypeMap& tStatMap, const String& sStatName, T& outValue)
{
    if(tStatMap.find(sStatName) == tStatMap.end())
    {
        return false;
    }
    try
    {
        outValue = BoostAnyCast<T>(tStatMap.at(sStatName).GetDataValue());
        return true;
    }
    catch(BoostBadAnyCast&)
    {
        return false;
    }
    return false;
}

};

#endif
