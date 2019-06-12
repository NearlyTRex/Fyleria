// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_RECIPE_H_
#define _GECKO_RECIPE_H_

#include "Recipes/RecipeEntry.h"
#include "Utility/Macros.h"
#include "Utility/Enum.h"
#include "Utility/Json.h"

namespace Gecko
{

// Class for recipes
class Recipe
{
public:

    // Constructors
    Recipe();
    Recipe(const Json& jsonData);

    // Clear all data
    void Clear();

    // Chance to success
    MAKE_RAW_BASIC_TYPE_ACCESSORS(ChanceToSucceed, Float);

    // Ingredients
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(Ingredients, RecipeEntryArray);

    // Results
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(Results, RecipeEntryArray);
};

// Typedefs
MAKE_TYPE_TYPEDEFS(Recipe);

// JSON Converters
void to_json(Json& jsonData, const Recipe& obj);
void from_json(const Json& jsonData, Recipe& obj);
MAKE_JSON_SEQUENCE_TYPE_CONVERTERS_DECL(RecipeArray);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_DECL(Recipe, Recipe);

};

#endif
