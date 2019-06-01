// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Items/ItemDataPotion.h"

namespace Gecko
{

ItemDataPotion::ItemDataPotion()
    : ItemData()
{
}

ItemDataPotion::ItemDataPotion(const Json& jsonData)
    : ItemData(jsonData)
{
    from_json(jsonData, *this);
}

void ItemDataPotion::Clear()
{
    // Base clear
    ItemData::Clear();

    // Stat changes
    SetStatChanges({});
}

CharacterActionArray ItemDataPotion::CreatePotionActions(const IndexedString& sCharacterID, const IndexedString& sWeaponSet) const
{
    CharacterActionArray vNewActions;
    return vNewActions;
}

void to_json(Json& jsonData, const ItemDataPotion& obj)
{
    // Stat changes
    SET_JSON_DATA_IF_NOT_EMPTY(StatChanges);
}

void from_json(const Json& jsonData, ItemDataPotion& obj)
{
    // Stat changes
    obj.SetStatChanges(GET_JSON_DATA_OR_DEFAULT(StatChanges, StatChangeArray, StatChangeArray()));
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(ItemDataPotion, ItemDataPotion);

};
