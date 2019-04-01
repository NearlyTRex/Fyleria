// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "Skills/SkillData.h"
#include "Skills/SkillDataAffinity.h"
#include "Skills/SkillDataAlchemy.h"
#include "Skills/SkillDataBreakdown.h"
#include "Skills/SkillDataCombat.h"
#include "Skills/SkillDataCrafting.h"
#include "Skills/SkillDataWeapon.h"
#include "Skills/SkillTree.h"
#include "Utility/Macros.h"
#include "Utility/Serializable.h"
#include "Utility/Python.h"

PYBIND11_EMBEDDED_MODULE(GeckoSkills, m)
{
    // SkillData.h
    PyBindClass<Gecko::SkillData>(m, "SkillData")
        WRAPPING_ADD_CONSTRUCTOR_SIMPLE()
        WRAPPING_ADD_METHOD_SIMPLE(IsActionable, Gecko::SkillData)
        WRAPPING_ADD_METHOD_SIMPLE(DoesMeetActionRequirements, Gecko::SkillData)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(DataClass, Gecko::SkillData)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillRank, Gecko::SkillData)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillName, Gecko::SkillData)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillDescription, Gecko::SkillData)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(SkillType, Gecko::SkillData)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillCostAP, Gecko::SkillData)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(SkillCostHP, Gecko::SkillData)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(StatChanges, Gecko::SkillDataAffinity)
    ;

    // SkillDataAffinity.h
    PyBindClass<Gecko::SkillDataAffinity, Gecko::SkillData>(m, "SkillDataAffinity")
        WRAPPING_ADD_CONSTRUCTOR_SIMPLE()
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(TreeType, Gecko::SkillDataAffinity)
    ;
    PyBindVector<Gecko::SkillDataAffinityArray>(m, "SkillDataAffinityArray");
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertSkillDataAffinityToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertSkillDataAffinityArrayToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetSkillDataAffinityFromJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetSkillDataAffinityArrayFromJsonString, Gecko);

    // SkillDataAlchemy.h
    PyBindClass<Gecko::SkillDataAlchemy, Gecko::SkillData>(m, "SkillDataAlchemy")
        WRAPPING_ADD_CONSTRUCTOR_SIMPLE()
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(TreeType, Gecko::SkillDataAlchemy)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(Recipes, Gecko::SkillDataAlchemy)
    ;
    PyBindVector<Gecko::SkillDataAlchemyArray>(m, "SkillDataAlchemyArray");
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertSkillDataAlchemyToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertSkillDataAlchemyArrayToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetSkillDataAlchemyFromJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetSkillDataAlchemyArrayFromJsonString, Gecko);

    // SkillDataBreakdown.h
    PyBindClass<Gecko::SkillDataBreakdown, Gecko::SkillData>(m, "SkillDataBreakdown")
        WRAPPING_ADD_CONSTRUCTOR_SIMPLE()
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(TreeType, Gecko::SkillDataBreakdown)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(Recipes, Gecko::SkillDataBreakdown)
    ;
    PyBindVector<Gecko::SkillDataBreakdownArray>(m, "SkillDataBreakdownArray");
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertSkillDataBreakdownToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertSkillDataBreakdownArrayToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetSkillDataBreakdownFromJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetSkillDataBreakdownArrayFromJsonString, Gecko);

    // SkillDataCombat.h
    PyBindClass<Gecko::SkillDataCombat, Gecko::SkillData>(m, "SkillDataCombat")
        WRAPPING_ADD_CONSTRUCTOR_SIMPLE()
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(TreeType, Gecko::SkillDataCombat)
        WRAPPING_ADD_METHOD_SIMPLE(CreateCombatActions, Gecko::SkillDataCombat)
    ;
    PyBindVector<Gecko::SkillDataCombatArray>(m, "SkillDataCombatArray");
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertSkillDataCombatToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertSkillDataCombatArrayToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetSkillDataCombatFromJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetSkillDataCombatArrayFromJsonString, Gecko);

    // SkillDataCrafting.h
    PyBindClass<Gecko::SkillDataCrafting, Gecko::SkillData>(m, "SkillDataCrafting")
        WRAPPING_ADD_CONSTRUCTOR_SIMPLE()
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(TreeType, Gecko::SkillDataCrafting)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(Recipes, Gecko::SkillDataCrafting)
    ;
    PyBindVector<Gecko::SkillDataCraftingArray>(m, "SkillDataCraftingArray");
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertSkillDataCraftingToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertSkillDataCraftingArrayToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetSkillDataCraftingFromJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetSkillDataCraftingArrayFromJsonString, Gecko);

    // SkillDataWeapon.h
    PyBindClass<Gecko::SkillDataWeapon, Gecko::SkillData>(m, "SkillDataWeapon")
        WRAPPING_ADD_CONSTRUCTOR_SIMPLE()
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(TreeType, Gecko::SkillDataWeapon)
        WRAPPING_ADD_METHOD_SIMPLE(CreateWeaponActions, Gecko::SkillDataWeapon)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_MULTIGET(WeaponBaseType, Gecko::SkillDataWeapon)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(ActionPoints, Gecko::SkillDataWeapon)
    ;
    PyBindVector<Gecko::SkillDataWeaponArray>(m, "SkillDataWeaponArray");
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertSkillDataWeaponToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertSkillDataWeaponArrayToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetSkillDataWeaponFromJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetSkillDataWeaponArrayFromJsonString, Gecko);

    // SkillTree.h
    WRAPPING_STANDALONE_METHOD_SIMPLE(LoadSkillTreesIntoMemory, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(UnloadSkillTreesFromMemory, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(VerifySkillTrees, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(DoesSkillDataAffinityExist, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(DoesSkillDataAlchemyExist, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(DoesSkillDataBreakdownExist, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(DoesSkillDataCombatExist, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(DoesSkillDataCraftingExist, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(DoesSkillDataWeaponExist, Gecko);
    WRAPPING_STANDALONE_METHOD_POLICY(RetrieveSkillDataAffinity, Gecko, PyBindReturnCopy);
    WRAPPING_STANDALONE_METHOD_POLICY(RetrieveSkillDataAlchemy, Gecko, PyBindReturnCopy);
    WRAPPING_STANDALONE_METHOD_POLICY(RetrieveSkillDataBreakdown, Gecko, PyBindReturnCopy);
    WRAPPING_STANDALONE_METHOD_POLICY(RetrieveSkillDataCombat, Gecko, PyBindReturnCopy);
    WRAPPING_STANDALONE_METHOD_POLICY(RetrieveSkillDataCrafting, Gecko, PyBindReturnCopy);
    WRAPPING_STANDALONE_METHOD_POLICY(RetrieveSkillDataWeapon, Gecko, PyBindReturnCopy);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetAllAffinitySkills, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetAllAlchemySkills, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetAllBreakdownSkills, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetAllCombatSkills, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetAllCraftingSkills, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetAllWeaponSkills, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetAffinitySkills, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetAlchemySkills, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetBreakdownSkills, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCombatSkills, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCraftingSkills, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetWeaponSkills, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetSkillType, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(IsBaseWeaponSkill, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(IsSkillActionable, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GenerateSkillCharacterActions, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(FillSkillStatChangeArrays, Gecko);

    // SkillTypes.h
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetSkillTreeTypeNames, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetSkillWeaponBaseTypeNames, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetSkillWeaponTypeNames, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetSkillAlchemyTypeNames, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetSkillBreakdownTypeNames, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetSkillCombatTypeNames, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetSkillCraftingTypeNames, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetSkillAffinityTypeNames, Gecko);
}
