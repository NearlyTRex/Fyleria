// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_ITEM_ITEMDATA_INGREDIENT_H_
#define _GECKO_ITEM_ITEMDATA_INGREDIENT_H_

// Internal includes
#include "Item/ItemData.h"
#include "Item/ItemTypes.h"
#include "Stat/StatChange.h"

namespace Gecko
{

class ItemDataIngredient : public ItemData
{
public:

    // Constructors
    ItemDataIngredient();
    ItemDataIngredient(const Json& jsonData);

    // Destructor
    virtual ~ItemDataIngredient();

    // Clear all data
    virtual void Clear() override;

    // Item tree type
    static String GetTreeType()
    {
        return GetEnumString(ItemTreeType::Ingredient);
    }

    // Stat changes
    MAKE_RAW_TYPE_ACCESSORS(StatChanges, StatChangeArray);
};

// Typedef
MAKE_COMMON_TYPEDEFS(ItemDataIngredient);

// JSON Converters
void to_json(Json& jsonData, const ItemDataIngredient& obj);
void from_json(const Json& jsonData, ItemDataIngredient& obj);

};

#endif
