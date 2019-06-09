// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Recipes/Recipe.h"

namespace Gecko
{

Recipe::Recipe()
{
}

Recipe::Recipe(const Json& jsonData)
{
    from_json(jsonData, *this);
}

void Recipe::Clear()
{
    // Chance to success
    SetChanceToSucceed(0);

    // Ingredients
    SetIngredients({});

    // Results
    SetResults({});
}

void to_json(Json& jsonData, const Recipe& obj)
{
    // Chance to success
    SET_JSON_DATA_VIA_ASSIGNMENT(ChanceToSucceed);

    // Ingredients
    SET_JSON_DATA_VIA_ASSIGNMENT(Ingredients);

    // Results
    SET_JSON_DATA_VIA_ASSIGNMENT(Results);
}

void from_json(const Json& jsonData, Recipe& obj)
{
    // Chance to success
    SET_OBJ_DATA(ChanceToSucceed, Float, 0);

    // Ingredients
    SET_OBJ_DATA(Ingredients, RecipeEntryArray, RecipeEntryArray());

    // Results
    SET_OBJ_DATA(Results, RecipeEntryArray, RecipeEntryArray());
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(Recipe, Recipe);

};
