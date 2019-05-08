// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "CharacterParty/CharacterPartyMember.h"
#include "Character/CharacterManager.h"
#include "Character/CharacterTypes.h"
#include "Items/ItemTree.h"
#include "Utility/Constants.h"
#include "Utility/Templates.h"

namespace Gecko
{

CharacterPartyMember::CharacterPartyMember()
{
}

CharacterPartyMember::CharacterPartyMember(const Json& jsonData)
{
    from_json(jsonData, *this);
}

UInt CharacterPartyMember::GetEquippedItemTypeCount(const TreeIndex& index) const
{
    TreeIndexArray vEquippedItemIndices;
    for(auto&& progressItem : GetEquippedItems())
    {
        vEquippedItemIndices.push_back(progressItem.GetTreeIndex());
    }
    return STDCountData(vEquippedItemIndices.begin(), vEquippedItemIndices.end(), index);
}

UInt CharacterPartyMember::GetEquippedWeaponCount(const IndexedString& sWeaponSet) const
{
    UInt uWeapon1Count = 0;
    UInt uWeapon2Count = 0;
    for(auto&& progressItem : GetEquippedItems())
    {
        if(!IsItemWeapon(progressItem.GetTreeIndex()))
        {
            continue;
        }

        const CharacterEquipmentType eEquipType = StringToCharacterEquipmentType(progressItem.GetItemSlot());
        uWeapon1Count += (eEquipType == +CharacterEquipmentType::Weapon1Left) ? 1 : 0;
        uWeapon1Count += (eEquipType == +CharacterEquipmentType::Weapon1Right) ? 1 : 0;
        uWeapon2Count += (eEquipType == +CharacterEquipmentType::Weapon2Left) ? 1 : 0;
        uWeapon2Count += (eEquipType == +CharacterEquipmentType::Weapon2Right) ? 1 : 0;
    }

    const CharacterWeaponSetType eWeaponSetType = StringToCharacterWeaponSetType(sWeaponSet);
    if(eWeaponSetType == +CharacterWeaponSetType::WeaponSet1)
    {
        return uWeapon1Count;
    }
    else if(eWeaponSetType == +CharacterWeaponSetType::WeaponSet2)
    {
        return uWeapon2Count;
    }
    return 0;
}

UInt CharacterPartyMember::GetEquippedShieldCount(const IndexedString& sWeaponSet) const
{
    UInt uShield1Count = 0;
    UInt uShield2Count = 0;
    for(auto&& progressItem : GetEquippedItems())
    {
        if(!IsItemShield(progressItem.GetTreeIndex()))
        {
            continue;
        }

        const CharacterEquipmentType eEquipType = StringToCharacterEquipmentType(progressItem.GetItemSlot());
        uShield1Count += (eEquipType == +CharacterEquipmentType::Weapon1Left) ? 1 : 0;
        uShield1Count += (eEquipType == +CharacterEquipmentType::Weapon1Right) ? 1 : 0;
        uShield2Count += (eEquipType == +CharacterEquipmentType::Weapon2Left) ? 1 : 0;
        uShield2Count += (eEquipType == +CharacterEquipmentType::Weapon2Right) ? 1 : 0;
    }

    const CharacterWeaponSetType eWeaponSetType = StringToCharacterWeaponSetType(sWeaponSet);
    if(eWeaponSetType == +CharacterWeaponSetType::WeaponSet1)
    {
        return uShield1Count;
    }
    else if(eWeaponSetType == +CharacterWeaponSetType::WeaponSet2)
    {
        return uShield2Count;
    }
    return 0;
}

Bool CharacterPartyMember::CanAddEquippedItem(const TreeIndex& index) const
{
    const UInt uItemCount = GetEquippedItemTypeCount(index);
    const ItemType eItemType = StringToItemType(RetrieveItemType(index));
    switch(eItemType)
    {
        case ItemType::WeaponPierce:
        case ItemType::WeaponBlunt:
        case ItemType::WeaponSlash:
        case ItemType::WeaponMage:
        case ItemType::ArmorShieldPierce:
        case ItemType::ArmorShieldBlunt:
        case ItemType::ArmorShieldSlash:
            return (uItemCount < s_kuHandSizeLimit);
        case ItemType::ArmorChest:
        case ItemType::ArmorFeet:
        case ItemType::ArmorFinger:
        case ItemType::ArmorHands:
        case ItemType::ArmorHead:
        case ItemType::ArmorLegs:
        case ItemType::ArmorNeck:
            return (uItemCount < s_kuBodySizeLimit);
        default:
            return false;
    }
}

Bool CharacterPartyMember::CanRemoveEquippedItem(const TreeIndex& index) const
{
    const UInt uItemCount = GetEquippedItemTypeCount(index);
    const ItemType eItemType = StringToItemType(RetrieveItemType(index));
    switch(eItemType)
    {
        case ItemType::WeaponPierce:
        case ItemType::WeaponBlunt:
        case ItemType::WeaponSlash:
        case ItemType::WeaponMage:
        case ItemType::ArmorShieldPierce:
        case ItemType::ArmorShieldBlunt:
        case ItemType::ArmorShieldSlash:
        case ItemType::ArmorChest:
        case ItemType::ArmorFeet:
        case ItemType::ArmorFinger:
        case ItemType::ArmorHands:
        case ItemType::ArmorHead:
        case ItemType::ArmorLegs:
        case ItemType::ArmorNeck:
            return (uItemCount > 0);
        default:
            return false;
    }
}

Bool CharacterPartyMember::AddEquippedItem(const TreeIndex& index, const IndexedString& sEquipSlot)
{
    // Check if it can be added
    if(!CanAddEquippedItem(index))
    {
        return false;
    }

    // Add item
    CharacterPartyEquippedItem equipItem;
    equipItem.SetTreeIndex(index);
    equipItem.SetItemSlot(sEquipSlot);
    GetEquippedItems().push_back(equipItem);
    return true;
}

Bool CharacterPartyMember::RemoveEquippedItem(const TreeIndex& index, const IndexedString& sEquipSlot)
{
    // Check if it can be removed
    if(!CanRemoveEquippedItem(index))
    {
        return false;
    }

    // Remove item
    CharacterPartyEquippedItem equipItem;
    equipItem.SetTreeIndex(index);
    equipItem.SetItemSlot(sEquipSlot);
    RemoveVectorElement<CharacterPartyEquippedItem>(GetEquippedItems(), equipItem);
    return true;
}

Bool CharacterPartyMember::GetHandInfoByWeaponSet(const IndexedString& sWeaponSet,
    TreeIndex& primaryItemIndex,
    TreeIndex& secondaryItemIndex,
    IndexedStringArray& vPrimaryActionTypes,
    IndexedStringArray& vSecondaryActionTypes) const
{
    // Get weapon set
    const CharacterWeaponSetType eWeaponSetType = StringToCharacterWeaponSetType(sWeaponSet);
    const Bool bIsWeaponSetSelected1 = (eWeaponSetType == +CharacterWeaponSetType::WeaponSet1);
    const Bool bIsWeaponSetSelected2 = (eWeaponSetType == +CharacterWeaponSetType::WeaponSet2);

    // Get the left/right items
    TreeIndex itemIndexLeft;
    TreeIndex itemIndexRight;
    for(auto&& progressItem : GetEquippedItems())
    {
        const ItemTreeType eItemTreeType = StringToItemTreeType(progressItem.GetTreeIndex().GetTree());
        const CharacterEquipmentType eEquipType = StringToCharacterEquipmentType(progressItem.GetItemSlot());
        const Bool bValidEquipLeft =
            (bIsWeaponSetSelected1 && (eEquipType == +CharacterEquipmentType::Weapon1Left)) ||
            (bIsWeaponSetSelected2 && (eEquipType == +CharacterEquipmentType::Weapon2Left));
        const Bool bValidEquipRight =
            (bIsWeaponSetSelected1 && (eEquipType == +CharacterEquipmentType::Weapon1Right)) ||
            (bIsWeaponSetSelected2 && (eEquipType == +CharacterEquipmentType::Weapon2Right));
        switch(eItemTreeType)
        {
            case ItemTreeType::Armor:
            {
                const Bool bIsShield = IsItemShield(progressItem.GetTreeIndex());
                if(bIsShield && bValidEquipLeft)
                {
                    itemIndexLeft = progressItem.GetTreeIndex();
                }
                else if(bIsShield && bValidEquipRight)
                {
                    itemIndexRight = progressItem.GetTreeIndex();
                }
                break;
            }
            case ItemTreeType::Weapon:
            {
                if(bValidEquipLeft)
                {
                    itemIndexLeft = progressItem.GetTreeIndex();
                }
                else if(bValidEquipRight)
                {
                    itemIndexRight = progressItem.GetTreeIndex();
                }
                break;
            }
            default:
                break;
        }
    }

    // Translate left/right to primary/secondary
    const Character& character = CharacterManager::GetInstance()->GetCharacter(GetCharacterID());
    const CharacterHandednessType eHandedness = StringToCharacterHandednessType(character.GetBasicData().GetHandedness());
    switch(eHandedness)
    {
        case CharacterHandednessType::LeftHanded:
            primaryItemIndex = itemIndexLeft;
            secondaryItemIndex = itemIndexRight;
            break;
        case CharacterHandednessType::RightHanded:
            primaryItemIndex = itemIndexRight;
            secondaryItemIndex = itemIndexLeft;
            break;
        default:
            break;
    }

    // Fill action types
    vPrimaryActionTypes = GetActionTypes(primaryItemIndex);
    vSecondaryActionTypes = GetActionTypes(secondaryItemIndex);
    return (!primaryItemIndex.empty() || !secondaryItemIndex.empty());
}

void to_json(Json& jsonData, const CharacterPartyMember& obj)
{
    // Character ID
    SET_JSON_DATA_IF_NOT_DEFAULT(CharacterID, IndexedString(""));

    // Character target type
    SET_JSON_DATA_IF_NOT_DEFAULT(CharacterTargetType, IndexedString("None"));

    // Equipped items
    SET_JSON_DATA_IF_NOT_EMPTY(EquippedItems);
}

void from_json(const Json& jsonData, CharacterPartyMember& obj)
{
    // Character ID
    obj.SetCharacterID(GET_JSON_DATA_OR_DEFAULT(CharacterID, IndexedString, IndexedString("")));

    // Character target type
    obj.SetCharacterTargetType(GET_JSON_DATA_OR_DEFAULT(CharacterTargetType, IndexedString, IndexedString("None")));

    // Equipped items
    obj.SetEquippedItems(GET_JSON_DATA_OR_DEFAULT(EquippedItems, CharacterPartyEquippedItemArray, CharacterPartyEquippedItemArray()));
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(CharacterPartyMember, CharacterPartyMember);

};
