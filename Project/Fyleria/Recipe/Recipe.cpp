// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Recipe/Recipe.h"
#include "Utility/JsonMacros.h"

namespace Gecko
{

Recipe::Recipe()
{
}

Recipe::Recipe(const Json& jsonData)
{
    from_json(jsonData, *this);
}

Recipe::~Recipe()
{
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
    SET_JSON_DATA(ChanceToSucceed);

    // Ingredients
    SET_JSON_DATA(Ingredients);

    // Results
    SET_JSON_DATA(Results);
}

void from_json(const Json& jsonData, Recipe& obj)
{
    // Chance to success
    SET_OBJ_DATA(ChanceToSucceed, Float);

    // Ingredients
    SET_OBJ_DATA(Ingredients, RecipeEntryArray);

    // Results
    SET_OBJ_DATA(Results, RecipeEntryArray);
}

};
