// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_SKILL_SKILLDATA_WEAPON_H_
#define _GECKO_SKILL_SKILLDATA_WEAPON_H_

// Internal includes
#include "Skill/SkillData.h"
#include "Skill/SkillTypes.h"

namespace Gecko
{

// Skill data weapon
class SkillDataWeapon : public SkillData
{
public:

    // Constructors
    SkillDataWeapon();
    SkillDataWeapon(const Json& jsonData);

    // Destructor
    virtual ~SkillDataWeapon();

    // Clear all data
    virtual void Clear() override;

    // Skill tree type
    static String GetTreeType()
    {
        return GetEnumString(SkillTreeType::Weapon);
    }

    // Create weapon actions
    CharacterActionArray CreateWeaponActions(const String& sCharacterID, const String& sWeaponSet) const;

    // Weapon base type
    MAKE_RAW_TYPE_ACCESSORS(WeaponBaseType, String);

    // Amount of action points available
    MAKE_RAW_TYPE_ACCESSORS(ActionPoints, UByte);
};

// Typedef
MAKE_COMMON_TYPEDEFS(SkillDataWeapon);

// JSON Converters
void to_json(Json& jsonData, const SkillDataWeapon& obj);
void from_json(const Json& jsonData, SkillDataWeapon& obj);

};

#endif
