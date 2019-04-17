// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_STAT_TYPE_H_
#define _GECKO_STAT_TYPE_H_

#include "Utility/Types.h"
#include "Utility/IndexedString.h"

namespace Gecko
{

// Stat type
class StatType
{
public:

    // Constructor
    StatType(const BoostAny& oValue)
        : m_xDataValue(oValue)
    {}

    // Get data value
    const BoostAny& GetDataValue() const { return m_oDataValue; }
    BoostAny& GetDataValue() { return m_oDataValue; }

    // Set data value
    void SetDataValue(const BoostAny& val) { m_oDataValue = val; }

private:

    // Data value
    BoostAny m_oDataValue;
};

// Typedefs
typedef STDMap<IndexedString, StatType> StatTypeMap;

// Helper functions
template <class T>
Bool SetStatValue(StatTypeMap& tStatMap, const IndexedString& sStatName, const T& inValue)
{
    if (tStatMap.find(sStatName) == tStatMap.end())
    {
        return false;
    }
    tStatMap.at(sStatName).SetDataValue(inValue);
    return true;
}
template <class T>
Bool GetStatValue(const StatTypeMap& tStatMap, const IndexedString& sStatName, T& outValue)
{
    if (tStatMap.find(sStatName) == tStatMap.end())
    {
        return false;
    }
    outValue = BoostAnyCast<T>(tStatMap.at(sStatName).GetDataValue());
    return true;
}

};

#endif
