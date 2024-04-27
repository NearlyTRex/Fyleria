// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Skill/SkillConstants.h"

// Tree limits
const Gecko::Int Gecko::MAX_SKILL_RANK = 20;

// Skill attacks
const Gecko::Int Gecko::BASE_NUMBER_OF_SKILL_ATTACKS = 1;

// Skill damage boundary
const Gecko::Float Gecko::SKILL_DAMAGE_BOUNDARY_PERCENT = 0.1f;
const Gecko::Float Gecko::SKILL_DAMAGE_BOUNDARY_DEFAULT_VALUE = 1.0f;

// Skill rank upgrade amount
const Gecko::Int Gecko::SKILL_RANK_UPGRADE_AMOUNT = 10;

// Skill files
const Gecko::String Gecko::SKILL_FILE_AFFINITY_BLOOD = "Affinity/SkillTreeAffinity-Blood.json";
const Gecko::String Gecko::SKILL_FILE_AFFINITY_DARK = "Affinity/SkillTreeAffinity-Dark.json";
const Gecko::String Gecko::SKILL_FILE_AFFINITY_EARTH = "Affinity/SkillTreeAffinity-Earth.json";
const Gecko::String Gecko::SKILL_FILE_AFFINITY_FIRE = "Affinity/SkillTreeAffinity-Fire.json";
const Gecko::String Gecko::SKILL_FILE_AFFINITY_FLESH = "Affinity/SkillTreeAffinity-Flesh.json";
const Gecko::String Gecko::SKILL_FILE_AFFINITY_FORCE = "Affinity/SkillTreeAffinity-Force.json";
const Gecko::String Gecko::SKILL_FILE_AFFINITY_HOLY = "Affinity/SkillTreeAffinity-Holy.json";
const Gecko::String Gecko::SKILL_FILE_AFFINITY_ICE = "Affinity/SkillTreeAffinity-Ice.json";
const Gecko::String Gecko::SKILL_FILE_AFFINITY_LIGHT = "Affinity/SkillTreeAffinity-Light.json";
const Gecko::String Gecko::SKILL_FILE_AFFINITY_MIND = "Affinity/SkillTreeAffinity-Mind.json";
const Gecko::String Gecko::SKILL_FILE_AFFINITY_SHOCK = "Affinity/SkillTreeAffinity-Shock.json";
const Gecko::String Gecko::SKILL_FILE_AFFINITY_WIND = "Affinity/SkillTreeAffinity-Wind.json";
const Gecko::String Gecko::SKILL_FILE_ALCHEMY_ALCHEMIST = "Alchemy/SkillTreeAlchemy-Alchemist.json";
const Gecko::String Gecko::SKILL_FILE_ALCHEMY_CHEMIST = "Alchemy/SkillTreeAlchemy-Chemist.json";
const Gecko::String Gecko::SKILL_FILE_ALCHEMY_ENERGIST = "Alchemy/SkillTreeAlchemy-Energist.json";
const Gecko::String Gecko::SKILL_FILE_ALCHEMY_HEALER = "Alchemy/SkillTreeAlchemy-Healer.json";
const Gecko::String Gecko::SKILL_FILE_BREAKDOWN_BOWBANE = "Breakdown/SkillTreeBreakdown-Bowbane.json";
const Gecko::String Gecko::SKILL_FILE_BREAKDOWN_GOLDBANE = "Breakdown/SkillTreeBreakdown-Goldbane.json";
const Gecko::String Gecko::SKILL_FILE_BREAKDOWN_HAMMERBANE = "Breakdown/SkillTreeBreakdown-Hammerbane.json";
const Gecko::String Gecko::SKILL_FILE_BREAKDOWN_PLATEBANE = "Breakdown/SkillTreeBreakdown-Platebane.json";
const Gecko::String Gecko::SKILL_FILE_BREAKDOWN_SCALEBANE = "Breakdown/SkillTreeBreakdown-Scalebane.json";
const Gecko::String Gecko::SKILL_FILE_BREAKDOWN_SHIELDBANE = "Breakdown/SkillTreeBreakdown-Shieldbane.json";
const Gecko::String Gecko::SKILL_FILE_BREAKDOWN_SPELLBANE = "Breakdown/SkillTreeBreakdown-Spellbane.json";
const Gecko::String Gecko::SKILL_FILE_BREAKDOWN_STUDREMOVER = "Breakdown/SkillTreeBreakdown-StudRemover.json";
const Gecko::String Gecko::SKILL_FILE_BREAKDOWN_SWORDBANE = "Breakdown/SkillTreeBreakdown-Swordbane.json";
const Gecko::String Gecko::SKILL_FILE_BREAKDOWN_THREADBARE = "Breakdown/SkillTreeBreakdown-Threadbare.json";
const Gecko::String Gecko::SKILL_FILE_COMBAT_AMBIDEXTROUS = "Combat/SkillTreeCombat-Ambidextrous.json";
const Gecko::String Gecko::SKILL_FILE_COMBAT_AVATAR = "Combat/SkillTreeCombat-Avatar.json";
const Gecko::String Gecko::SKILL_FILE_COMBAT_BARBARIAN = "Combat/SkillTreeCombat-Barbarian.json";
const Gecko::String Gecko::SKILL_FILE_COMBAT_BLADEMASTER = "Combat/SkillTreeCombat-Blademaster.json";
const Gecko::String Gecko::SKILL_FILE_COMBAT_FOCUSED = "Combat/SkillTreeCombat-Focused.json";
const Gecko::String Gecko::SKILL_FILE_COMBAT_MAGE = "Combat/SkillTreeCombat-Mage.json";
const Gecko::String Gecko::SKILL_FILE_COMBAT_ROGUE = "Combat/SkillTreeCombat-Rogue.json";
const Gecko::String Gecko::SKILL_FILE_COMBAT_STALWART = "Combat/SkillTreeCombat-Stalwart.json";
const Gecko::String Gecko::SKILL_FILE_CRAFTING_BOWSMITH = "Crafting/SkillTreeCrafting-Bowsmith.json";
const Gecko::String Gecko::SKILL_FILE_CRAFTING_GOLDSMITH = "Crafting/SkillTreeCrafting-Goldsmith.json";
const Gecko::String Gecko::SKILL_FILE_CRAFTING_HAMMERSMITH = "Crafting/SkillTreeCrafting-Hammersmith.json";
const Gecko::String Gecko::SKILL_FILE_CRAFTING_PLATESMITH = "Crafting/SkillTreeCrafting-Platesmith.json";
const Gecko::String Gecko::SKILL_FILE_CRAFTING_SCALESMITH = "Crafting/SkillTreeCrafting-Scalesmith.json";
const Gecko::String Gecko::SKILL_FILE_CRAFTING_SHIELDSMITH = "Crafting/SkillTreeCrafting-Shieldsmith.json";
const Gecko::String Gecko::SKILL_FILE_CRAFTING_SPELLSMITH = "Crafting/SkillTreeCrafting-Spellsmith.json";
const Gecko::String Gecko::SKILL_FILE_CRAFTING_SWORDSMITH = "Crafting/SkillTreeCrafting-Swordsmith.json";
const Gecko::String Gecko::SKILL_FILE_CRAFTING_TANNER = "Crafting/SkillTreeCrafting-Tanner.json";
const Gecko::String Gecko::SKILL_FILE_CRAFTING_WEAVER = "Crafting/SkillTreeCrafting-Weaver.json";
const Gecko::String Gecko::SKILL_FILE_WEAPON_BASH = "Weapon/SkillTreeWeapon-Bash.json";
const Gecko::String Gecko::SKILL_FILE_WEAPON_BLOCK = "Weapon/SkillTreeWeapon-Block.json";
const Gecko::String Gecko::SKILL_FILE_WEAPON_BREAK = "Weapon/SkillTreeWeapon-Break.json";
const Gecko::String Gecko::SKILL_FILE_WEAPON_CLEAVE = "Weapon/SkillTreeWeapon-Cleave.json";
const Gecko::String Gecko::SKILL_FILE_WEAPON_COUNTER = "Weapon/SkillTreeWeapon-Counter.json";
const Gecko::String Gecko::SKILL_FILE_WEAPON_CRACK = "Weapon/SkillTreeWeapon-Crack.json";
const Gecko::String Gecko::SKILL_FILE_WEAPON_CRITICALSHOT = "Weapon/SkillTreeWeapon-CriticalShot.json";
const Gecko::String Gecko::SKILL_FILE_WEAPON_CRUSH = "Weapon/SkillTreeWeapon-Crush.json";
const Gecko::String Gecko::SKILL_FILE_WEAPON_DECAPITATE = "Weapon/SkillTreeWeapon-Decapitate.json";
const Gecko::String Gecko::SKILL_FILE_WEAPON_DODGE = "Weapon/SkillTreeWeapon-Dodge.json";
const Gecko::String Gecko::SKILL_FILE_WEAPON_DRILL = "Weapon/SkillTreeWeapon-Drill.json";
const Gecko::String Gecko::SKILL_FILE_WEAPON_IMPACT = "Weapon/SkillTreeWeapon-Impact.json";
const Gecko::String Gecko::SKILL_FILE_WEAPON_IMPALE = "Weapon/SkillTreeWeapon-Impale.json";
const Gecko::String Gecko::SKILL_FILE_WEAPON_PARRY = "Weapon/SkillTreeWeapon-Parry.json";
const Gecko::String Gecko::SKILL_FILE_WEAPON_PIERCE = "Weapon/SkillTreeWeapon-Pierce.json";
const Gecko::String Gecko::SKILL_FILE_WEAPON_RIPOSTE = "Weapon/SkillTreeWeapon-Riposte.json";
const Gecko::String Gecko::SKILL_FILE_WEAPON_RUSH = "Weapon/SkillTreeWeapon-Rush.json";
const Gecko::String Gecko::SKILL_FILE_WEAPON_SEVER = "Weapon/SkillTreeWeapon-Sever.json";
const Gecko::String Gecko::SKILL_FILE_WEAPON_SHOOT = "Weapon/SkillTreeWeapon-Shoot.json";
const Gecko::String Gecko::SKILL_FILE_WEAPON_SLASH = "Weapon/SkillTreeWeapon-Slash.json";
const Gecko::String Gecko::SKILL_FILE_WEAPON_SLICE = "Weapon/SkillTreeWeapon-Slice.json";
const Gecko::String Gecko::SKILL_FILE_WEAPON_SLIT = "Weapon/SkillTreeWeapon-Slit.json";
const Gecko::String Gecko::SKILL_FILE_WEAPON_SMASH = "Weapon/SkillTreeWeapon-Smash.json";
const Gecko::String Gecko::SKILL_FILE_WEAPON_STEALTHSTRIKE = "Weapon/SkillTreeWeapon-StealthStrike.json";
