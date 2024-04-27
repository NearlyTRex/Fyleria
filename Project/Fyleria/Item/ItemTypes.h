// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_ITEM_ITEM_TYPES_H_
#define _GECKO_ITEM_ITEM_TYPES_H_

// Internal includes
#include "Utility/Macros.h"
#include "Utility/Enum.h"

namespace Gecko
{

BETTER_ENUM(ItemTreeType, Int,
    None,
    Armor,
    Ingredient,
    Potion,
    Weapon
);

BETTER_ENUM(ItemType, Int,
    None,
    PotionHeal,
    PotionMagic,
    PotionEnergy,
    PotionSpeed,
    IngredientCrystal,
    IngredientGem,
    IngredientThread,
    IngredientLeather,
    IngredientBar,
    IngredientPlate,
    IngredientSheet,
    IngredientStud,
    IngredientScale,
    IngredientScrew,
    IngredientCloth,
    IngredientMail,
    WeaponPierce,
    WeaponBlunt,
    WeaponSlash,
    WeaponMage,
    ArmorChest,
    ArmorFeet,
    ArmorFinger,
    ArmorHands,
    ArmorHead,
    ArmorLegs,
    ArmorNeck,
    ArmorShieldPierce,
    ArmorShieldBlunt,
    ArmorShieldSlash
);

};

#endif
