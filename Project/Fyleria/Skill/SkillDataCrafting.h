// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_SKILL_SKILLDATA_CRAFTING_H_
#define _GECKO_SKILL_SKILLDATA_CRAFTING_H_

// Internal includes
#include "Skill/SkillData.h"
#include "Skill/SkillTypes.h"
#include "Recipe/Recipe.h"

namespace Gecko
{

// Skill data crafting
class SkillDataCrafting : public SkillData
{
public:

    // Constructors
    SkillDataCrafting();
    SkillDataCrafting(const Json& jsonData);

    // Destructor
    virtual ~SkillDataCrafting();

    // Clear all data
    virtual void Clear() override;

    // Skill tree type
    static String GetTreeType()
    {
        return GetEnumString(SkillTreeType::Crafting);
    }

    // Recipes
    MAKE_RAW_TYPE_ACCESSORS(Recipes, RecipeArray);
};

// Typedef
MAKE_COMMON_TYPEDEFS(SkillDataCrafting);

// JSON Converters
void to_json(Json& jsonData, const SkillDataCrafting& obj);
void from_json(const Json& jsonData, SkillDataCrafting& obj);

};

#endif
