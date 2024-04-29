// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_SKILL_SKILLDATA_COMBAT_H_
#define _GECKO_SKILL_SKILLDATA_COMBAT_H_

// Internal includes
#include "Skill/SkillData.h"
#include "Skill/SkillTypes.h"

namespace Gecko
{

// Skill data combat
class SkillDataCombat : public SkillData
{
public:

    // Constructors
    SkillDataCombat();
    SkillDataCombat(const Json& jsonData);

    // Destructor
    virtual ~SkillDataCombat();

    // Clear all data
    virtual void Clear() override;

    // Skill tree type
    static String GetTreeType()
    {
        return GetEnumString(SkillTreeType::Combat);
    }

    // Create combat action
    CharacterActionArray CreateCombatActions(const String& sCharacterID, const String& sWeaponSet) const;
};

// Typedef
MAKE_COMMON_TYPEDEFS(SkillDataCombat);

// JSON Converters
void to_json(Json& jsonData, const SkillDataCombat& obj);
void from_json(const Json& jsonData, SkillDataCombat& obj);

};

#endif
