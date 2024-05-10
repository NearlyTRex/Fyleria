// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_CHARACTER_CHARACTER_TYPE_CONVERTERS_H_
#define _GECKO_CHARACTER_CHARACTER_TYPE_CONVERTERS_H_

// Internal includes
#include "Character/CharacterTypes.h"
#include "CharacterData/CharacterDataTypes.h"

namespace Gecko
{

// Converters
String ConvertCharacterEquipmentTypeToCharacterWeaponSetType(const String& sCharacterEquipmentType);
String ConvertCharacterTargetTypeToCharacterPartyType(const String& sCharacterTargetType);
String ConvertItemTypeToCharacterActionType(const String& sItemType);
StringArray ConvertItemTypeToCharacterEquipTypes(const String& sItemType);
String ConvertSkillWeaponBaseTypeToCharacterActionType(const String& sSkillWeaponBaseType);
String ConvertSkillWeaponTypeToCharacterActionType(const String& sSkillWeaponType);
String ConvertSkillWeaponTypeToCharacterActionStatType(const String& sSkillWeaponType);

};

#endif
