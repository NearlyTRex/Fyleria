// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "CharacterData/CharacterSkillUseData.h"

namespace Gecko
{

CharacterSkillUseData::CharacterSkillUseData()
{
}

CharacterSkillUseData::CharacterSkillUseData(const Json& jsonData)
{
    from_json(jsonData, *this);
}

void CharacterSkillUseData::Clear()
{
    // Skill use tracking
    SetSkillUseTrackingMap({});
}

void CharacterSkillUseData::AddSkillUse(const IndexedString& sSkillType, UInt uNum)
{
    SkillUseTrackingMapType& tTrackingMap = GetSkillUseTrackingMap();
    if(tTrackingMap.count(sSkillType))
    {
        tTrackingMap[sSkillType] = tTrackingMap[sSkillType] + uNum;
    }
    else
    {
        tTrackingMap[sSkillType] = uNum;
    }
}

UInt CharacterSkillUseData::GetSkillUseCount(const IndexedString& sSkillType) const
{
    const SkillUseTrackingMapType& tTrackingMap = GetSkillUseTrackingMap();
    auto iSearch = tTrackingMap.find(sSkillType);
    if(iSearch != tTrackingMap.end())
    {
        return iSearch->second;
    }
    return 0;
}

Bool CharacterSkillUseData::operator==(const CharacterSkillUseData& other) const
{
    return false;
}

Bool CharacterSkillUseData::operator!=(const CharacterSkillUseData& other) const
{
    return false;
}

void to_json(Json& jsonData, const CharacterSkillUseData& obj)
{
}

void from_json(const Json& jsonData, CharacterSkillUseData& obj)
{
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(CharacterSkillUseData, CharacterSkillUseData);

};
