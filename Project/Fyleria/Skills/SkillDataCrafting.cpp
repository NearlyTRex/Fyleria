// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Skills/SkillDataCrafting.h"

namespace Gecko
{

SkillDataCrafting::SkillDataCrafting()
    : SkillData()
{
}

SkillDataCrafting::SkillDataCrafting(const Json& jsonData)
    : SkillData(jsonData)
{
    from_json(jsonData, *this);
}

void SkillDataCrafting::Clear()
{
    // Base clear
    SkillData::Clear();

    // Recipes
    SetRecipes({});
}

void to_json(Json& jsonData, const SkillDataCrafting& obj)
{
    // Recipes
    SET_JSON_DATA_IF_NOT_EMPTY(Recipes);
}

void from_json(const Json& jsonData, SkillDataCrafting& obj)
{
    // Recipes
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(Recipes, RecipeArray, RecipeArray());
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(SkillDataCrafting, SkillDataCrafting);

};
