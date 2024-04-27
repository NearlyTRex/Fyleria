// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Item/ItemDataIngredient.h"
#include "Utility/JsonMacros.h"

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

ItemDataIngredient::~ItemDataIngredient()
{
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
    SET_JSON_DATA(StatChanges);
}

void from_json(const Json& jsonData, ItemDataIngredient& obj)
{
    // Stat changes
    SET_OBJ_DATA(StatChanges, StatChangeArray);
}

};
