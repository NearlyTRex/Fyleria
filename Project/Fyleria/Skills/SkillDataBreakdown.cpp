// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Skills/SkillDataBreakdown.h"

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
    SET_JSON_DATA_IF_NOT_EMPTY(Recipes);
}

void from_json(const Json& jsonData, SkillDataBreakdown& obj)
{
    // Recipes
    obj.SetRecipes(GET_JSON_DATA_OR_DEFAULT(Recipes, RecipeArray, RecipeArray()));
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(SkillDataBreakdown, SkillDataBreakdown);

};
