// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_SKILLDATA_WEAPON_H_
#define _GECKO_SKILLDATA_WEAPON_H_

#include "Skills/SkillData.h"
#include "Skills/SkillTypes.h"

namespace Gecko
{

class SkillDataWeapon : public SkillData
{
public:

    // Constructors
    SkillDataWeapon();
    SkillDataWeapon(const Json& jsonData);

    // Clear all data
    virtual void Clear();

    // Skill tree type
    static String GetTreeType()
    {
        return String(SkillTreeType(SkillTreeType::Weapon)._to_string());
    }

    // Create weapon actions
    CharacterActionArray CreateWeaponActions(const String& sCharacterID, const String& sWeaponSet) const;

    // Weapon base type
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(WeaponBaseType, String);

    // Amount of action points available
    MAKE_RAW_BASIC_TYPE_ACCESSORS(ActionPoints, UByte);
};

// Typedef
MAKE_TYPE_TYPEDEFS(SkillDataWeapon);

// JSON Converters
void to_json(Json& jsonData, const SkillDataWeapon& obj);
void from_json(const Json& jsonData, SkillDataWeapon& obj);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_DECL(SkillDataWeapon, SkillDataWeapon);

};

#endif
