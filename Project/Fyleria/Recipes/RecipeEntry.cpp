// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Recipes/RecipeEntry.h"

namespace Gecko
{

RecipeEntry::RecipeEntry()
{
}

RecipeEntry::RecipeEntry(const Json& jsonData)
{
    from_json(jsonData, *this);
}

void RecipeEntry::Clear()
{
    // Chance to success
    SetChanceToSucceed(0);

    // Input type
    SetInputPotionName("");
    SetInputIngredientName("");
    SetInputWeaponName("");
    SetInputArmorName("");

    // Output type
    SetOutputPotionName("");
    SetOutputIngredientName("");
    SetOutputWeaponName("");
    SetOutputArmorName("");

    // Input amount
    SetInputAmount(0);

    // Output amount
    SetOutputAmount(0);
}

void to_json(Json& jsonData, const RecipeEntry& obj)
{
    // Chance to success
    SET_JSON_DATA_IF_NOT_DEFAULT(ChanceToSucceed, 0);

    // Input type
    SET_JSON_DATA_IF_NOT_DEFAULT(InputPotionName, "");
    SET_JSON_DATA_IF_NOT_DEFAULT(InputIngredientName, "");
    SET_JSON_DATA_IF_NOT_DEFAULT(InputWeaponName, "");
    SET_JSON_DATA_IF_NOT_DEFAULT(InputArmorName, "");

    // Output type
    SET_JSON_DATA_IF_NOT_DEFAULT(OutputPotionName, "");
    SET_JSON_DATA_IF_NOT_DEFAULT(OutputIngredientName, "");
    SET_JSON_DATA_IF_NOT_DEFAULT(OutputWeaponName, "");
    SET_JSON_DATA_IF_NOT_DEFAULT(OutputArmorName, "");

    // Input amount
    SET_JSON_DATA_IF_NOT_DEFAULT(InputAmount, 0);

    // Output amount
    SET_JSON_DATA_IF_NOT_DEFAULT(OutputAmount, 0);
}

void from_json(const Json& jsonData, RecipeEntry& obj)
{
    // Chance to success
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(ChanceToSucceed, Float, 0);

    // Input type
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(InputPotionName, String, "");
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(InputIngredientName, String, "");
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(InputWeaponName, String, "");
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(InputArmorName, String, "");

    // Output type
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(OutputPotionName, String, "");
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(OutputIngredientName, String, "");
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(OutputWeaponName, String, "");
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(OutputArmorName, String, "");

    // Input amount
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(InputAmount, Int, 0);

    // Output amount
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(OutputAmount, Int, 0);
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(RecipeEntry, RecipeEntry);

};
