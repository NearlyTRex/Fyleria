// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Items/ItemDataWeapon.h"

namespace Gecko
{

ItemDataWeapon::ItemDataWeapon()
    : ItemData()
{
}

ItemDataWeapon::ItemDataWeapon(const Json& jsonData)
    : ItemData(jsonData)
{
    from_json(jsonData, *this);
}

void ItemDataWeapon::Clear()
{
    // Base clear
    ItemData::Clear();

    // Stat percents
    SetBluntAttackPercent(0);
    SetPierceAttackPercent(0);
    SetSlashAttackPercent(0);

    // Stat changes
    SetStatChanges({});
}

CharacterActionArray ItemDataWeapon::CreateWeaponActions(const String& sCharacterID, const String& sWeaponSet) const
{
    CharacterActionArray vNewActions;
    return vNewActions;
}

void to_json(Json& jsonData, const ItemDataWeapon& obj)
{
    // Stat percents
    SET_JSON_DATA_IF_NOT_DEFAULT(BluntAttackPercent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(PierceAttackPercent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(SlashAttackPercent, 0);

    // Stat changes
    SET_JSON_DATA_IF_NOT_EMPTY(StatChanges);
}

void from_json(const Json& jsonData, ItemDataWeapon& obj)
{
    // Stat percents
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(BluntAttackPercent, Float, 0);
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(PierceAttackPercent, Float, 0);
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(SlashAttackPercent, Float, 0);

    // Stat changes
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(StatChanges, StatChangeArray, StatChangeArray());
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(ItemDataWeapon, ItemDataWeapon);

};
