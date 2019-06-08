// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "CharacterParty/CharacterPartyItem.h"
#include "Character/CharacterTypes.h"
#include "Items/ItemTypes.h"
#include "Items/ItemTree.h"
#include "Utility/Templates.h"

namespace Gecko
{

CharacterPartyItem::CharacterPartyItem()
{
}

CharacterPartyItem::CharacterPartyItem(const Json& jsonData)
{
    from_json(jsonData, *this);
}

Bool CharacterPartyItem::DoesMatchSlot(const IndexedString& sSlot) const
{
    return DoesVectorIntersectElement<IndexedString>(GetApplicableEquipmentSlots(), sSlot);
}

Bool CharacterPartyItem::CanAddAmount(UInt uAmount) const
{
    return true;
}

Bool CharacterPartyItem::CanRemoveAmount(UInt uAmount) const
{
    return (uAmount <= GetItemAmount()) && (GetItemAmount() - uAmount > GetEquipCount());
}

Bool CharacterPartyItem::CanEquipAmount(UInt uAmount) const
{
    return (uAmount <= GetItemAmount()) && (GetEquipCount() + uAmount <= GetItemAmount());
}

Bool CharacterPartyItem::CanUnequipAmount(UInt uAmount) const
{
    return (uAmount <= GetItemAmount()) && (uAmount <= GetEquipCount());
}

Bool CharacterPartyItem::AddAmount(UInt uAmount)
{
    if(CanAddAmount(uAmount))
    {
        const UInt kuMaxUInt = STDNumericLimits<UInt>::max();
        UInt uNewAmount = ClipValue<UInt>(GetItemAmount() + uAmount, 0, kuMaxUInt);
        SetItemAmount(uNewAmount);
        return true;
    }
    return false;
}

Bool CharacterPartyItem::RemoveAmount(UInt uAmount)
{
    if(CanRemoveAmount(uAmount))
    {
        const UInt kuMaxInt = STDNumericLimits<Int>::max();
        Int iNewAmount = ClipValue<Int>((Int)GetItemAmount() - (Int)uAmount, 0, kuMaxInt);
        SetItemAmount((UInt)iNewAmount);
        return true;
    }
    return false;
}

Bool CharacterPartyItem::EquipAmount(UInt uAmount)
{
    if(CanEquipAmount(uAmount))
    {
        SetEquipCount(GetEquipCount() + uAmount);
        return true;
    }
    return false;
}

Bool CharacterPartyItem::UnequipAmount(UInt uAmount)
{
    if(CanUnequipAmount(uAmount))
    {
        SetEquipCount(GetEquipCount() - uAmount);
        return true;
    }
    return false;
}

void to_json(Json& jsonData, const CharacterPartyItem& obj)
{
    // Item tree index
    SET_JSON_DATA_IF_NOT_EMPTY(ItemTreeIndex);

    // Item amount
    SET_JSON_DATA_IF_NOT_DEFAULT(ItemAmount, 0);

    // Number of equips (must be less than or equal to the amount of the item)
    SET_JSON_DATA_IF_NOT_DEFAULT(EquipCount, 0);

    // Applicable equipment slots
    SET_JSON_DATA_IF_NOT_EMPTY(ApplicableEquipmentSlots);
}

void from_json(const Json& jsonData, CharacterPartyItem& obj)
{
    // Item tree index
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(ItemTreeIndex, TreeIndex, TreeIndex());

    // Item amount
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(ItemAmount, UByte, 0);

    // Number of equips (must be less than or equal to the amount of the item)
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(EquipCount, UByte, 0);

    // Applicable equipment slots
    SET_OBJ_DATA_FROM_JSON_OR_DEFAULT(ApplicableEquipmentSlots, IndexedStringArray, IndexedStringArray());
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(CharacterPartyItem, CharacterPartyItem);

};
