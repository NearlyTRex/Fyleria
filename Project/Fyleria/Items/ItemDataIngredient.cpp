// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Items/ItemDataIngredient.h"

namespace Gecko
{

ItemDataIngredient::ItemDataIngredient()
    : ItemData()
{
}

ItemDataIngredient::ItemDataIngredient(const Json& jsonData)
    : ItemData(jsonData)
{
    from_json(jsonData, *this);
}

void ItemDataIngredient::Clear()
{
    // Base clear
    ItemData::Clear();

    // Stat changes
    SetStatChanges({});
}

void to_json(Json& jsonData, const ItemDataIngredient& obj)
{
    // Stat changes
    SET_JSON_DATA_IF_NOT_EMPTY(StatChanges);
}

void from_json(const Json& jsonData, ItemDataIngredient& obj)
{
    // Stat changes
    obj.SetStatChanges(GET_JSON_DATA_OR_DEFAULT(StatChanges, StatChangeArray, StatChangeArray()));
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(ItemDataIngredient, ItemDataIngredient);

};
