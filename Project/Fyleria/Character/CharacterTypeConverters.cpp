// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Character/CharacterTypeConverters.h"
#include "Item/ItemTypes.h"
#include "Skill/SkillTypes.h"

namespace Gecko
{

String ConvertCharacterEquipmentTypeToCharacterWeaponSetType(const String& sCharacterEquipmentType)
{
    if(sCharacterEquipmentType.empty())
    {
        return GetNoneTypeForEnum<CharacterEquipmentType>();
    }

    const CharacterEquipmentType eCharacterEquipmentType = GetEnumFromStringOrNone<CharacterEquipmentType>(sCharacterEquipmentType);
    switch(eCharacterEquipmentType)
    {
        case CharacterEquipmentType::Weapon1Left:
        case CharacterEquipmentType::Weapon1Right:
            return GetEnumString(CharacterWeaponSetType::WeaponSet1);
        case CharacterEquipmentType::Weapon2Left:
        case CharacterEquipmentType::Weapon2Right:
            return GetEnumString(CharacterWeaponSetType::WeaponSet2);
        default:
            return GetNoneTypeForEnum<CharacterWeaponSetType>();
    }
}

String ConvertCharacterTargetTypeToCharacterPartyType(const String& sCharacterTargetType)
{
    if(sCharacterTargetType.empty())
    {
        return GetNoneTypeForEnum<CharacterTargetType>();
    }

    const CharacterTargetType eCharacterTargetType = GetEnumFromStringOrNone<CharacterTargetType>(sCharacterTargetType);
    switch(eCharacterTargetType)
    {
        case CharacterTargetType::AllAllies:
        case CharacterTargetType::Ally1:
        case CharacterTargetType::Ally2:
        case CharacterTargetType::Ally3:
        case CharacterTargetType::Ally4:
        case CharacterTargetType::Ally5:
        case CharacterTargetType::Ally6:
            return GetEnumString(CharacterPartyType::Ally);
        case CharacterTargetType::AllEnemies:
        case CharacterTargetType::Enemy1:
        case CharacterTargetType::Enemy2:
        case CharacterTargetType::Enemy3:
        case CharacterTargetType::Enemy4:
        case CharacterTargetType::Enemy5:
        case CharacterTargetType::Enemy6:
            return GetEnumString(CharacterPartyType::Enemy);
        default:
            return GetNoneTypeForEnum<CharacterPartyType>();
    }
}

String ConvertItemTypeToCharacterActionType(const String& sItemType)
{
    if(sItemType.empty())
    {
        return GetNoneTypeForEnum<CharacterActionType>();
    }

    const ItemType eItemType = GetEnumFromStringOrNone<ItemType>(sItemType);
    switch(eItemType)
    {
        case ItemType::WeaponPierce:
        case ItemType::ArmorShieldPierce:
            return GetEnumString(CharacterActionType::WeaponBasePierce);
        case ItemType::WeaponBlunt:
        case ItemType::ArmorShieldBlunt:
            return GetEnumString(CharacterActionType::WeaponBaseBlunt);
        case ItemType::WeaponSlash:
        case ItemType::ArmorShieldSlash:
            return GetEnumString(CharacterActionType::WeaponBaseSlash);
        default:
            return GetNoneTypeForEnum<CharacterActionType>();
    }
}

StringArray ConvertItemTypeToCharacterEquipTypes(const String& sItemType)
{
    StringArray vEquipTypes;
    if(sItemType.empty())
    {
        return vEquipTypes;
    }

    const ItemType eItemType = GetEnumFromStringOrNone<ItemType>(sItemType);
    switch(eItemType)
    {
        case ItemType::WeaponPierce:
        case ItemType::WeaponBlunt:
        case ItemType::WeaponSlash:
        case ItemType::WeaponMage:
        case ItemType::ArmorShieldPierce:
        case ItemType::ArmorShieldBlunt:
        case ItemType::ArmorShieldSlash:
            vEquipTypes.push_back(GetEnumString(CharacterEquipmentType::Weapon1Left));
            vEquipTypes.push_back(GetEnumString(CharacterEquipmentType::Weapon1Right));
            vEquipTypes.push_back(GetEnumString(CharacterEquipmentType::Weapon2Left));
            vEquipTypes.push_back(GetEnumString(CharacterEquipmentType::Weapon2Right));
            break;
        case ItemType::ArmorChest:
            vEquipTypes.push_back(GetEnumString(CharacterEquipmentType::Chest));
            break;
        case ItemType::ArmorFeet:
            vEquipTypes.push_back(GetEnumString(CharacterEquipmentType::Feet));
            break;
        case ItemType::ArmorFinger:
            vEquipTypes.push_back(GetEnumString(CharacterEquipmentType::LeftFingers));
            vEquipTypes.push_back(GetEnumString(CharacterEquipmentType::RightFingers));
            break;
        case ItemType::ArmorHands:
            vEquipTypes.push_back(GetEnumString(CharacterEquipmentType::Hands));
            break;
        case ItemType::ArmorHead:
            vEquipTypes.push_back(GetEnumString(CharacterEquipmentType::Head));
            break;
        case ItemType::ArmorLegs:
            vEquipTypes.push_back(GetEnumString(CharacterEquipmentType::Legs));
            break;
        case ItemType::ArmorNeck:
            vEquipTypes.push_back(GetEnumString(CharacterEquipmentType::Neck));
            break;
        default:
            break;
    }
    return vEquipTypes;
}

String ConvertSkillWeaponBaseTypeToCharacterActionType(const String& sSkillWeaponBaseType)
{
    if(sSkillWeaponBaseType.empty())
    {
        return GetNoneTypeForEnum<CharacterActionType>();
    }

    const SkillWeaponBaseType eSkillWeaponBaseType = GetEnumFromStringOrNone<SkillWeaponBaseType>(sSkillWeaponBaseType);
    switch(eSkillWeaponBaseType)
    {
        case SkillWeaponBaseType::Slash:
            return GetEnumString(CharacterActionType::WeaponBaseSlash);
        case SkillWeaponBaseType::Blunt:
            return GetEnumString(CharacterActionType::WeaponBaseBlunt);
        case SkillWeaponBaseType::Pierce:
            return GetEnumString(CharacterActionType::WeaponBasePierce);
        default:
            return GetNoneTypeForEnum<CharacterActionType>();
    }
}

String ConvertSkillWeaponTypeToCharacterActionType(const String& sSkillWeaponType)
{
    if(sSkillWeaponType.empty())
    {
        return GetNoneTypeForEnum<CharacterActionType>();
    }

    const SkillWeaponType eSkillWeaponType = GetEnumFromStringOrNone<SkillWeaponType>(sSkillWeaponType);
    switch(eSkillWeaponType)
    {
        case SkillWeaponType::Slash:
            return GetEnumString(CharacterActionType::WeaponSlash);
        case SkillWeaponType::Sever:
            return GetEnumString(CharacterActionType::WeaponSever);
        case SkillWeaponType::Slice:
            return GetEnumString(CharacterActionType::WeaponSlice);
        case SkillWeaponType::Slit:
            return GetEnumString(CharacterActionType::WeaponSlit);
        case SkillWeaponType::Cleave:
            return GetEnumString(CharacterActionType::WeaponCleave);
        case SkillWeaponType::Decapitate:
            return GetEnumString(CharacterActionType::WeaponDecapitate);
        case SkillWeaponType::Parry:
            return GetEnumString(CharacterActionType::WeaponParry);
        case SkillWeaponType::Riposte:
            return GetEnumString(CharacterActionType::WeaponRiposte);
        case SkillWeaponType::Bash:
            return GetEnumString(CharacterActionType::WeaponBash);
        case SkillWeaponType::Smash:
            return GetEnumString(CharacterActionType::WeaponSmash);
        case SkillWeaponType::Impact:
            return GetEnumString(CharacterActionType::WeaponImpact);
        case SkillWeaponType::Crush:
            return GetEnumString(CharacterActionType::WeaponCrush);
        case SkillWeaponType::Break:
            return GetEnumString(CharacterActionType::WeaponBreak);
        case SkillWeaponType::Crack:
            return GetEnumString(CharacterActionType::WeaponCrack);
        case SkillWeaponType::Block:
            return GetEnumString(CharacterActionType::WeaponBlock);
        case SkillWeaponType::Rush:
            return GetEnumString(CharacterActionType::WeaponRush);
        case SkillWeaponType::Pierce:
            return GetEnumString(CharacterActionType::WeaponPierce);
        case SkillWeaponType::Drill:
            return GetEnumString(CharacterActionType::WeaponDrill);
        case SkillWeaponType::Shoot:
            return GetEnumString(CharacterActionType::WeaponShoot);
        case SkillWeaponType::Impale:
            return GetEnumString(CharacterActionType::WeaponImpale);
        case SkillWeaponType::StealthStrike:
            return GetEnumString(CharacterActionType::WeaponStealthStrike);
        case SkillWeaponType::CriticalShot:
            return GetEnumString(CharacterActionType::WeaponCriticalShot);
        case SkillWeaponType::Dodge:
            return GetEnumString(CharacterActionType::WeaponDodge);
        case SkillWeaponType::Counter:
            return GetEnumString(CharacterActionType::WeaponCounter);
        default:
            return GetNoneTypeForEnum<CharacterActionType>();
    }
}

String ConvertSkillWeaponTypeToCharacterActionStatType(const String& sSkillWeaponType)
{
    if(sSkillWeaponType.empty())
    {
        return GetNoneTypeForEnum<CharacterActionDataType_Int>();
    }

    const SkillWeaponType eSkillWeaponType = GetEnumFromStringOrNone<SkillWeaponType>(sSkillWeaponType);
    switch(eSkillWeaponType)
    {
        case SkillWeaponType::Slash:
            return GetEnumString(CharacterActionDataType_Int::SlashPoints);
        case SkillWeaponType::Sever:
            return GetEnumString(CharacterActionDataType_Int::SeverPoints);
        case SkillWeaponType::Slice:
            return GetEnumString(CharacterActionDataType_Int::SlicePoints);
        case SkillWeaponType::Slit:
            return GetEnumString(CharacterActionDataType_Int::SlitPoints);
        case SkillWeaponType::Cleave:
            return GetEnumString(CharacterActionDataType_Int::CleavePoints);
        case SkillWeaponType::Decapitate:
            return GetEnumString(CharacterActionDataType_Int::DecapitatePoints);
        case SkillWeaponType::Parry:
            return GetEnumString(CharacterActionDataType_Int::ParryPoints);
        case SkillWeaponType::Riposte:
            return GetEnumString(CharacterActionDataType_Int::RipostePoints);
        case SkillWeaponType::Bash:
            return GetEnumString(CharacterActionDataType_Int::BashPoints);
        case SkillWeaponType::Smash:
            return GetEnumString(CharacterActionDataType_Int::SmashPoints);
        case SkillWeaponType::Impact:
            return GetEnumString(CharacterActionDataType_Int::ImpactPoints);
        case SkillWeaponType::Crush:
            return GetEnumString(CharacterActionDataType_Int::CrushPoints);
        case SkillWeaponType::Break:
            return GetEnumString(CharacterActionDataType_Int::BreakPoints);
        case SkillWeaponType::Crack:
            return GetEnumString(CharacterActionDataType_Int::CrackPoints);
        case SkillWeaponType::Block:
            return GetEnumString(CharacterActionDataType_Int::BlockPoints);
        case SkillWeaponType::Rush:
            return GetEnumString(CharacterActionDataType_Int::RushPoints);
        case SkillWeaponType::Pierce:
            return GetEnumString(CharacterActionDataType_Int::PiercePoints);
        case SkillWeaponType::Drill:
            return GetEnumString(CharacterActionDataType_Int::DrillPoints);
        case SkillWeaponType::Shoot:
            return GetEnumString(CharacterActionDataType_Int::ShootPoints);
        case SkillWeaponType::Impale:
            return GetEnumString(CharacterActionDataType_Int::ImpalePoints);
        case SkillWeaponType::StealthStrike:
            return GetEnumString(CharacterActionDataType_Int::StealthStrikePoints);
        case SkillWeaponType::CriticalShot:
            return GetEnumString(CharacterActionDataType_Int::CriticalShotPoints);
        case SkillWeaponType::Dodge:
            return GetEnumString(CharacterActionDataType_Int::DodgePoints);
        case SkillWeaponType::Counter:
            return GetEnumString(CharacterActionDataType_Int::CounterPoints);
        default:
            return GetNoneTypeForEnum<CharacterActionDataType_Int>();
    }
}

};
