// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_CHARACTER_SKILL_USE_DATA_H_
#define _GECKO_CHARACTER_SKILL_USE_DATA_H_

#include "Character/CharacterTypes.h"

namespace Gecko
{

class CharacterSkillUseData
{
public:

    // Types
    typedef STDUnorderedMap<IndexedString, UInt, IndexedStringHasher> SkillUseTrackingMapType;

    // Constructors
    CharacterSkillUseData();
    CharacterSkillUseData(const Json& jsonData);

    // Clear all data
    void Clear();

    // Add skill use
    void AddSkillUse(const IndexedString& sSkillType, UInt uNum);

    // Get number of skill uses
    UInt GetSkillUseCount(const IndexedString& sSkillType) const;

    // Skill use tracking
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(SkillUseTrackingMap, SkillUseTrackingMapType);

    // Comparisons
    Bool operator==(const CharacterSkillUseData& other) const;
    Bool operator!=(const CharacterSkillUseData& other) const;

private:

};

// Typedef
MAKE_TYPE_TYPEDEFS(CharacterSkillUseData);

// JSON Converters
void to_json(Json& jsonData, const CharacterSkillUseData& obj);
void from_json(const Json& jsonData, CharacterSkillUseData& obj);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_DECL(CharacterSkillUseData, CharacterSkillUseData);

};

#endif
