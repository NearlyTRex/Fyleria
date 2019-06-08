// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Items/ItemDataArmor.h"

namespace Gecko
{

ItemDataArmor::ItemDataArmor()
    : ItemData()
{
}

ItemDataArmor::ItemDataArmor(const Json& jsonData)
    : ItemData(jsonData)
{
    from_json(jsonData, *this);
}

void ItemDataArmor::Clear()
{
    // Base clear
    ItemData::Clear();

    // Stat percents
    SetBluntDefendPercent(0);
    SetPierceDefendPercent(0);
    SetSlashDefendPercent(0);
    SetMagicDefendPercent(0);

    // Stat changes
    SetStatChanges({});
}

CharacterActionArray ItemDataArmor::CreateArmorActions(const IndexedString& sCharacterID, const IndexedString& sWeaponSet) const
{
    CharacterActionArray vNewActions;
    return vNewActions;
}

void to_json(Json& jsonData, const ItemDataArmor& obj)
{
    // Stat percents
    SET_JSON_DATA_IF_NOT_DEFAULT(BluntDefendPercent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(PierceDefendPercent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(SlashDefendPercent, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(MagicDefendPercent, 0);

    // Stat changes
    SET_JSON_DATA_IF_NOT_EMPTY(StatChanges);
}

void from_json(const Json& jsonData, ItemDataArmor& obj)
{
    // Stat percents
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(BluntDefendPercent, Float, 0);
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(PierceDefendPercent, Float, 0);
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(SlashDefendPercent, Float, 0);
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(MagicDefendPercent, Float, 0);

    // Stat changes
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(StatChanges, StatChangeArray, StatChangeArray());
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(ItemDataArmor, ItemDataArmor);

};
