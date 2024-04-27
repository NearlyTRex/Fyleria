// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "TestSample/TestSamples.h"

namespace Gecko
{

// Empty character
const String EMPTY_CHARACTER_JSON = R"(
{
    "BasicData": {
        "CharacterID": "EmptyCharacter"
    },
    "MediaData": null,
    "ProgressData": null,
    "SkillData": null
}
)";

// Invalid character
const String INVALID_CHARACTER_JSON = R"(
{
    "BasicData": {
        "CharacterID": "TestCharacter"
    },
    "MediaData": null,
    "ProgressData": null
    "SkillData": nul
}
)";

// Random character 1
extern const String RANDOM_CHARACTER_1_JSON = R"(
{
    "BasicData": {
        "Age": 91,
        "BaseRace": "Faerie",
        "CharacterID": "RandomCharacter1",
        "Eyes": "Eyes2",
        "FirstName": "Shianwuo",
        "Gender": "Female",
        "Hair": "Hair2",
        "Handedness": "RightHanded",
        "LastName": "Shiacian",
        "PowerSet": "Vampire",
        "TransformedRace": "Vampire",
        "WeaponSet": "WeaponSet2"
    },
    "MediaData": null,
    "ProgressData": {
        "BluntAttack": 165,
        "BluntDefense": 57,
        "EnergyAttack": 133,
        "EnergyDefense": 154,
        "EnergyPointsCurrent": 133,
        "EnergyPointsMax": 133,
        "EnergyRegen": 63,
        "HealthPointsCurrent": 10,
        "HealthPointsMax": 10,
        "HealthRegen": 63,
        "MagicAttack": 112,
        "MagicDefense": 74,
        "MagicPointsCurrent": 176,
        "MagicPointsMax": 176,
        "MagicRegen": 114,
        "PierceAttack": 84,
        "PierceDefense": 194,
        "SlashAttack": 169,
        "SlashDefense": 188,
        "Speed": 143
    },
    "SkillData": {
        "Alchemist": 198,
        "Ambidextrous": 8,
        "Avatar": 5,
        "Barbarian": 173,
        "Blademaster": 193,
        "Blood": 71,
        "Bowbane": 197,
        "Bowsmith": 157,
        "Chemist": 23,
        "Dark": 99,
        "Earth": 182,
        "Energist": 108,
        "Fire": 130,
        "Flesh": 138,
        "Focused": 100,
        "Force": 196,
        "Goldbane": 199,
        "Goldsmith": 192,
        "Hammerbane": 180,
        "Hammersmith": 201,
        "Healer": 137,
        "Holy": 176,
        "Ice": 139,
        "Light": 32,
        "Mage": 29,
        "Mind": 94,
        "Platebane": 103,
        "Platesmith": 124,
        "Rogue": 118,
        "Scalebane": 107,
        "Scalesmith": 97,
        "Shieldbane": 176,
        "Shieldsmith": 182,
        "Shock": 186,
        "Spellbane": 163,
        "Spellsmith": 67,
        "Stalwart": 154,
        "StudRemover": 95,
        "Swordbane": 138,
        "Swordsmith": 181,
        "Tanner": 190,
        "Threadbare": 182,
        "Weaver": 189,
        "Wind": 159
    }
}
)";

// Random character 2
extern const String RANDOM_CHARACTER_2_JSON = R"(
{
    "BasicData": {
        "Age": 87,
        "BaseRace": "Caetian",
        "CharacterID": "RandomCharacter2",
        "Eyes": "Eyes2",
        "FirstName": "Li'ona",
        "Gender": "Female",
        "Hair": "Hair2",
        "Handedness": "LeftHanded",
        "LastName": "Aoake",
        "PowerSet": "Sidhe",
        "TransformedRace": "Zombie",
        "WeaponSet": "WeaponSet2"
    },
    "MediaData": null,
    "ProgressData": {
        "BluntAttack": 150,
        "BluntDefense": 162,
        "EnergyAttack": 193,
        "EnergyDefense": 67,
        "EnergyPointsCurrent": 91,
        "EnergyPointsMax": 91,
        "EnergyRegen": 158,
        "HealthPointsCurrent": 82,
        "HealthPointsMax": 82,
        "HealthRegen": 175,
        "MagicAttack": 92,
        "MagicDefense": 177,
        "MagicPointsCurrent": 173,
        "MagicPointsMax": 173,
        "MagicRegen": 114,
        "PierceAttack": 112,
        "PierceDefense": 164,
        "SlashAttack": 90,
        "SlashDefense": 114,
        "Speed": 128
    },
    "SkillData": {
        "Alchemist": 75,
        "Ambidextrous": 196,
        "Avatar": 59,
        "Barbarian": 169,
        "Blademaster": 124,
        "Blood": 114,
        "Bowbane": 62,
        "Bowsmith": 43,
        "Chemist": 77,
        "Dark": 172,
        "Earth": 24,
        "Energist": 192,
        "Fire": 195,
        "Flesh": 108,
        "Focused": 157,
        "Force": 196,
        "Goldbane": 82,
        "Goldsmith": 151,
        "Hammerbane": 196,
        "Hammersmith": 160,
        "Healer": 124,
        "Holy": 7,
        "Ice": 56,
        "Light": 41,
        "Mage": 172,
        "Mind": 86,
        "Platebane": 187,
        "Platesmith": 162,
        "Rogue": 186,
        "Scalebane": 99,
        "Scalesmith": 136,
        "Shieldbane": 86,
        "Shieldsmith": 79,
        "Shock": 150,
        "Spellbane": 86,
        "Spellsmith": 140,
        "Stalwart": 165,
        "StudRemover": 183,
        "Swordbane": 87,
        "Swordsmith": 143,
        "Tanner": 108,
        "Threadbare": 185,
        "Weaver": 96,
        "Wind": 192
    }
}
)";

// Random character 3
extern const String RANDOM_CHARACTER_3_JSON = R"(
{
    "BasicData": {
        "Age": 93,
        "BaseRace": "Caetian",
        "CharacterID": "RandomCharacter3",
        "Eyes": "Eyes1",
        "FirstName": "Shia-pou",
        "Gender": "Male",
        "Hair": "Hair2",
        "Handedness": "LeftHanded",
        "LastName": "Shiapoun",
        "PowerSet": "Vampire",
        "TransformedRace": "Skeleton",
        "WeaponSet": "WeaponSet1"
    },
    "MediaData": null,
    "ProgressData": {
        "BluntAttack": 166,
        "BluntDefense": 12,
        "EnergyAttack": 102,
        "EnergyDefense": 122,
        "EnergyPointsCurrent": 106,
        "EnergyPointsMax": 106,
        "EnergyRegen": 60,
        "HealthPointsCurrent": 55,
        "HealthPointsMax": 55,
        "HealthRegen": 106,
        "MagicAttack": 121,
        "MagicDefense": 121,
        "MagicPointsCurrent": 175,
        "MagicPointsMax": 175,
        "MagicRegen": 122,
        "PierceAttack": 115,
        "PierceDefense": 190,
        "SlashAttack": 159,
        "SlashDefense": 183,
        "Speed": 143
    },
    "SkillData": {
        "Alchemist": 195,
        "Ambidextrous": 7,
        "Avatar": 2,
        "Barbarian": 175,
        "Blademaster": 184,
        "Blood": 123,
        "Bowbane": 198,
        "Bowsmith": 165,
        "Chemist": 16,
        "Dark": 114,
        "Earth": 176,
        "Energist": 104,
        "Fire": 124,
        "Flesh": 134,
        "Focused": 103,
        "Force": 191,
        "Goldbane": 188,
        "Goldsmith": 193,
        "Hammerbane": 187,
        "Hammersmith": 200,
        "Healer": 146,
        "Holy": 178,
        "Ice": 140,
        "Light": 36,
        "Mage": 30,
        "Mind": 106,
        "Platebane": 104,
        "Platesmith": 105,
        "Rogue": 114,
        "Scalebane": 88,
        "Scalesmith": 89,
        "Shieldbane": 175,
        "Shieldsmith": 178,
        "Shock": 198,
        "Spellbane": 164,
        "Spellsmith": 80,
        "Stalwart": 34,
        "StudRemover": 167,
        "Swordbane": 75,
        "Swordsmith": 188,
        "Tanner": 190,
        "Threadbare": 143,
        "Weaver": 187,
        "Wind": 159
    }
}
)";

// Random character 4
extern const String RANDOM_CHARACTER_4_JSON = R"(
{
    "BasicData": {
        "Age": 49,
        "BaseRace": "Elf",
        "CharacterID": "RandomCharacter4",
        "Eyes": "Eyes1",
        "FirstName": "Adocia",
        "Gender": "Male",
        "Hair": "Hair2",
        "Handedness": "LeftHanded",
        "LastName": "Athucia",
        "PowerSet": "Dragon",
        "TransformedRace": "Wraith",
        "WeaponSet": "WeaponSet2"
    },
    "MediaData": null,
    "ProgressData": {
        "BluntAttack": 126,
        "BluntDefense": 183,
        "EnergyAttack": 47,
        "EnergyDefense": 181,
        "EnergyPointsCurrent": 57,
        "EnergyPointsMax": 57,
        "EnergyRegen": 72,
        "HealthPointsCurrent": 125,
        "HealthPointsMax": 125,
        "HealthRegen": 153,
        "MagicAttack": 49,
        "MagicDefense": 175,
        "MagicPointsCurrent": 180,
        "MagicPointsMax": 180,
        "MagicRegen": 194,
        "PierceAttack": 179,
        "PierceDefense": 166,
        "SlashAttack": 163,
        "SlashDefense": 142,
        "Speed": 196
    },
    "SkillData": {
        "Alchemist": 198,
        "Ambidextrous": 68,
        "Avatar": 156,
        "Barbarian": 186,
        "Blademaster": 181,
        "Blood": 199,
        "Bowbane": 180,
        "Bowsmith": 198,
        "Chemist": 113,
        "Dark": 16,
        "Earth": 94,
        "Energist": 135,
        "Fire": 88,
        "Flesh": 110,
        "Focused": 25,
        "Force": 158,
        "Goldbane": 167,
        "Goldsmith": 178,
        "Hammerbane": 132,
        "Hammersmith": 165,
        "Healer": 105,
        "Holy": 163,
        "Ice": 86,
        "Light": 125,
        "Mage": 181,
        "Mind": 164,
        "Platebane": 101,
        "Platesmith": 160,
        "Rogue": 155,
        "Scalebane": 29,
        "Scalesmith": 165,
        "Shieldbane": 140,
        "Shieldsmith": 41,
        "Shock": 82,
        "Spellbane": 63,
        "Spellsmith": 122,
        "Stalwart": 84,
        "StudRemover": 142,
        "Swordbane": 150,
        "Swordsmith": 70,
        "Tanner": 109,
        "Threadbare": 170,
        "Weaver": 35,
        "Wind": 155
    }
}
)";

};
