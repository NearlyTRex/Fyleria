// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Skill/SkillDataBreakdown.h"
#include "Utility/JsonMacros.h"

namespace Gecko
{

SkillDataBreakdown::SkillDataBreakdown()
    : SkillData()
{
}

SkillDataBreakdown::SkillDataBreakdown(const Json& jsonData)
    : SkillData(jsonData)
{
    from_json(jsonData, *this);
}

SkillDataBreakdown::~SkillDataBreakdown()
{
}

void SkillDataBreakdown::Clear()
{
    // Base clear
    SkillData::Clear();

    // Recipes
    SetRecipes({});
}

void to_json(Json& jsonData, const SkillDataBreakdown& obj)
{
    // Recipes
    SET_JSON_DATA(Recipes);
}

void from_json(const Json& jsonData, SkillDataBreakdown& obj)
{
    // Recipes
    SET_OBJ_DATA(Recipes, RecipeArray);
}

};
