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
        WRAPPING_ADD_METHOD_SIMPLE(Clear, Gecko::SkillData)
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
        WRAPPING_ADD_METHOD_SIMPLE(Clear, Gecko::SkillDataAffinity)
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
        WRAPPING_ADD_METHOD_SIMPLE(Clear, Gecko::SkillDataAlchemy)
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
        WRAPPING_ADD_METHOD_SIMPLE(Clear, Gecko::SkillDataBreakdown)
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
        WRAPPING_ADD_METHOD_SIMPLE(Clear, Gecko::SkillDataCombat)
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
        WRAPPING_ADD_METHOD_SIMPLE(Clear, Gecko::SkillDataCrafting)
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
        WRAPPING_ADD_METHOD_SIMPLE(Clear, Gecko::SkillDataWeapon)
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
    PyBindClass<Gecko::SkillTree>(m, "SkillTree")
        WRAPPING_ADD_CONSTRUCTOR_SIMPLE()
        WRAPPING_ADD_METHOD_STATIC_SIMPLE(LoadSkillTreesIntoMemory, Gecko::SkillTree)
        WRAPPING_ADD_METHOD_STATIC_SIMPLE(UnloadSkillTreesFromMemory, Gecko::SkillTree)
        WRAPPING_ADD_METHOD_STATIC_SIMPLE(VerifySkillTrees, Gecko::SkillTree)
        WRAPPING_ADD_METHOD_STATIC_SIMPLE(DoesSkillDataAffinityExist, Gecko::SkillTree)
        WRAPPING_ADD_METHOD_STATIC_SIMPLE(DoesSkillDataAlchemyExist, Gecko::SkillTree)
        WRAPPING_ADD_METHOD_STATIC_SIMPLE(DoesSkillDataBreakdownExist, Gecko::SkillTree)
        WRAPPING_ADD_METHOD_STATIC_SIMPLE(DoesSkillDataCombatExist, Gecko::SkillTree)
        WRAPPING_ADD_METHOD_STATIC_SIMPLE(DoesSkillDataCraftingExist, Gecko::SkillTree)
        WRAPPING_ADD_METHOD_STATIC_SIMPLE(DoesSkillDataWeaponExist, Gecko::SkillTree)
        WRAPPING_ADD_METHOD_STATIC_POLICY(RetrieveSkillDataAffinity, Gecko::SkillTree, PyBindReturnCopy)
        WRAPPING_ADD_METHOD_STATIC_POLICY(RetrieveSkillDataAlchemy, Gecko::SkillTree, PyBindReturnCopy)
        WRAPPING_ADD_METHOD_STATIC_POLICY(RetrieveSkillDataBreakdown, Gecko::SkillTree, PyBindReturnCopy)
        WRAPPING_ADD_METHOD_STATIC_POLICY(RetrieveSkillDataCombat, Gecko::SkillTree, PyBindReturnCopy)
        WRAPPING_ADD_METHOD_STATIC_POLICY(RetrieveSkillDataCrafting, Gecko::SkillTree, PyBindReturnCopy)
        WRAPPING_ADD_METHOD_STATIC_POLICY(RetrieveSkillDataWeapon, Gecko::SkillTree, PyBindReturnCopy)
        WRAPPING_ADD_METHOD_STATIC_SIMPLE(GetAllAffinitySkills, Gecko::SkillTree)
        WRAPPING_ADD_METHOD_STATIC_SIMPLE(GetAllAlchemySkills, Gecko::SkillTree)
        WRAPPING_ADD_METHOD_STATIC_SIMPLE(GetAllBreakdownSkills, Gecko::SkillTree)
        WRAPPING_ADD_METHOD_STATIC_SIMPLE(GetAllCombatSkills, Gecko::SkillTree)
        WRAPPING_ADD_METHOD_STATIC_SIMPLE(GetAllCraftingSkills, Gecko::SkillTree)
        WRAPPING_ADD_METHOD_STATIC_SIMPLE(GetAllWeaponSkills, Gecko::SkillTree)
        WRAPPING_ADD_METHOD_STATIC_SIMPLE(GetAffinitySkills, Gecko::SkillTree)
        WRAPPING_ADD_METHOD_STATIC_SIMPLE(GetAlchemySkills, Gecko::SkillTree)
        WRAPPING_ADD_METHOD_STATIC_SIMPLE(GetBreakdownSkills, Gecko::SkillTree)
        WRAPPING_ADD_METHOD_STATIC_SIMPLE(GetCombatSkills, Gecko::SkillTree)
        WRAPPING_ADD_METHOD_STATIC_SIMPLE(GetCraftingSkills, Gecko::SkillTree)
        WRAPPING_ADD_METHOD_STATIC_SIMPLE(GetWeaponSkills, Gecko::SkillTree)
        WRAPPING_ADD_METHOD_STATIC_SIMPLE(GetSkillType, Gecko::SkillTree)
        WRAPPING_ADD_METHOD_STATIC_SIMPLE(IsBaseWeaponSkill, Gecko::SkillTree)
        WRAPPING_ADD_METHOD_STATIC_SIMPLE(IsSkillActionable, Gecko::SkillTree)
        WRAPPING_ADD_METHOD_STATIC_SIMPLE(GenerateSkillCharacterActions, Gecko::SkillTree)
        WRAPPING_ADD_METHOD_STATIC_SIMPLE(FillSkillStatChangeArrays, Gecko::SkillTree)
    ;

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
