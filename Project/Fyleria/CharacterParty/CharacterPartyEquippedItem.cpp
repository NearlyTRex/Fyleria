// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "Character/CharacterPartyEquippedItem.h"

namespace Gecko
{

CharacterPartyEquippedItem::CharacterPartyEquippedItem()
{
}

CharacterPartyEquippedItem::CharacterPartyEquippedItem(const Json& jsonData)
{
    from_json(jsonData, *this);
}

void to_json(Json& jsonData, const CharacterPartyEquippedItem& obj)
{
    // Item tree index
    SET_JSON_DATA_IF_NOT_EMPTY(TreeIndex);

    // Item slot
    SET_JSON_DATA_IF_NOT_DEFAULT(ItemSlot, IndexedString("None"));
}

void from_json(const Json& jsonData, CharacterPartyEquippedItem& obj)
{
    // Item tree index
    obj.SetTreeIndex(GET_JSON_DATA_OR_DEFAULT(TreeIndex, TreeIndex, TreeIndex()));

    // Item slot
    obj.SetItemSlot(GET_JSON_DATA_OR_DEFAULT(ItemSlot, IndexedString, IndexedString("None")));
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(CharacterPartyEquippedItem, CharacterPartyEquippedItem);

Bool operator==(const CharacterPartyEquippedItem& a, const CharacterPartyEquippedItem& b)
{
    return (
        (a.GetTreeIndex() == b.GetTreeIndex()) &&
        (a.GetItemSlot() == b.GetItemSlot())
    );
}

};
