// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_SKILL_SKILLDATA_AFFINITY_H_
#define _GECKO_SKILL_SKILLDATA_AFFINITY_H_

// Internal includes
#include "Skill/SkillData.h"
#include "Skill/SkillTypes.h"

namespace Gecko
{

// Skill data affinity
class SkillDataAffinity : public SkillData
{
public:

    // Constructors
    SkillDataAffinity();
    SkillDataAffinity(const Json& jsonData);

    // Destructor
    virtual ~SkillDataAffinity();

    // Clear all data
    virtual void Clear() override;

    // Skill tree type
    static String GetTreeType()
    {
        return GetEnumString(SkillTreeType::Affinity);
    }
};

// Typedef
MAKE_COMMON_TYPEDEFS(SkillDataAffinity);

// JSON Converters
void to_json(Json& jsonData, const SkillDataAffinity& obj);
void from_json(const Json& jsonData, SkillDataAffinity& obj);

};

#endif
