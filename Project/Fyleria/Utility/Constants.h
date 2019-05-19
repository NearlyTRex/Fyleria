// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_UTILITY_CONSTANTS_H_
#define _GECKO_UTILITY_CONSTANTS_H_

#include "Utility/Types.h"

namespace Gecko
{

// Binary file markers
const FixedUnsigned8Array BINARY_MARKER_CBR = {'C', 'B', 'R'};
const FixedUnsigned8Array BINARY_MARKER_MSG = {'M', 'S', 'G'};

// Save limits
const UByte MAX_SAVE_SLOT = 5;

// Tree limits
const UInt MAX_SKILL_RANK = 20;

// Character limits
const UInt MAX_TEAM_CHARACTER_AMOUNT = 6;

// Character index for team size of 6
const UInt CHARACTER_INDEX_1 = 0;
const UInt CHARACTER_INDEX_2 = 1;
const UInt CHARACTER_INDEX_3 = 2;
const UInt CHARACTER_INDEX_4 = 3;
const UInt CHARACTER_INDEX_5 = 4;
const UInt CHARACTER_INDEX_6 = 5;

// Limits on equipped items
const UInt HAND_SIZE_LIMIT = 4;
const UInt BODY_SIZE_LIMIT = 1;

// Skill attacks
const UInt BASE_NUMBER_OF_SKILL_ATTACKS = 1;

// Skill damage boundary
const Float SKILL_DAMAGE_BOUNDARY_PERCENT = 0.1f;
const Float SKILL_DAMAGE_BOUNDARY_DEFAULT_VALUE = 1.0f;

// Skill rank upgrade amount
const UInt SKILL_RANK_UPGRADE_AMOUNT = 10;

};

#endif
