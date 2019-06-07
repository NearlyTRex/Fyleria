// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "CharacterParty/CharacterPartyEquippedItem.h"

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
    SET_JSON_DATA_IF_NOT_EMPTY(ItemTreeIndex);

    // Item slot
    SET_JSON_DATA_IF_NOT_DEFAULT(ItemSlot, IndexedString("None"));
}

void from_json(const Json& jsonData, CharacterPartyEquippedItem& obj)
{
    // Item tree index
    obj.SetItemTreeIndex(GET_JSON_DATA_OR_DEFAULT(ItemTreeIndex, TreeIndex, TreeIndex()));

    // Item slot
    obj.SetItemSlot(GET_JSON_DATA_OR_DEFAULT(ItemSlot, IndexedString, IndexedString("None")));
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(CharacterPartyEquippedItem, CharacterPartyEquippedItem);

Bool operator==(const CharacterPartyEquippedItem& a, const CharacterPartyEquippedItem& b)
{
    return (
        (a.GetItemTreeIndex() == b.GetItemTreeIndex()) &&
        (a.GetItemSlot() == b.GetItemSlot())
    );
}

};
