// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_ITEM_ITEMDATA_WEAPON_H_
#define _GECKO_ITEM_ITEMDATA_WEAPON_H_

// Internal includes
#include "Item/ItemData.h"
#include "Item/ItemTypes.h"
#include "Stat/StatChange.h"

namespace Gecko
{

class ItemDataWeapon : public ItemData
{
public:

    // Constructors
    ItemDataWeapon();
    ItemDataWeapon(const Json& jsonData);

    // Destructor
    virtual ~ItemDataWeapon();

    // Clear all data
    virtual void Clear() override;

    // Item tree type
    static String GetTreeType()
    {
        return GetEnumString(ItemTreeType::Weapon);
    }

    // Create weapon action
    CharacterActionArray CreateWeaponActions(const String& sCharacterID, const String& sWeaponSet) const;

    // Stat percents
    MAKE_RAW_TYPE_ACCESSORS(BluntAttackPercent, Float);
    MAKE_RAW_TYPE_ACCESSORS(PierceAttackPercent, Float);
    MAKE_RAW_TYPE_ACCESSORS(SlashAttackPercent, Float);

    // Stat changes
    MAKE_RAW_TYPE_ACCESSORS(StatChanges, StatChangeArray);
};

// Typedef
MAKE_COMMON_TYPEDEFS(ItemDataWeapon);

// JSON Converters
void to_json(Json& jsonData, const ItemDataWeapon& obj);
void from_json(const Json& jsonData, ItemDataWeapon& obj);

};

#endif
