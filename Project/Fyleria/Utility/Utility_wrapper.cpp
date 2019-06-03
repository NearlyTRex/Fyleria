// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Character/CharacterTypes.h"
#include "Module/ModuleResultManager.h"
#include "Items/ItemTypes.h"
#include "Skills/SkillTypes.h"
#include "Saves/SaveTypes.h"
#include "Utility/Serializable.h"
#include "Utility/Tree.h"
#include "Utility/Enum.h"
#include "Utility/FantasyName.h"
#include "Utility/Python.h"
#include "Utility/Templates.h"

namespace Gecko
{

String GetAllTypeNames()
{
    Json jsonData;

    // CharacterTypes.h
    jsonData["CharacterTreeIndexType"] = GetCharacterTreeIndexTypeNames();
    jsonData["CharacterSegmentType"] = GetCharacterSegmentTypeNames();
    jsonData["CharacterBasicStatType_IndexedString"] = GetCharacterBasicStatType_IndexedStringNames();
    jsonData["CharacterBasicStatType_Int"] = GetCharacterBasicStatType_IntNames();
    jsonData["CharacterProgressStatType_Int"] = GetCharacterProgressStatType_IntNames();
    jsonData["CharacterBattleStatType_IndexedString"] = GetCharacterBattleStatType_IndexedStringNames();
    jsonData["CharacterBattleStatType_IndexedStringArray"] = GetCharacterBattleStatType_IndexedStringArrayNames();
    jsonData["CharacterBattleStatType_Bool"] = GetCharacterBattleStatType_BoolNames();
    jsonData["CharacterBattleStatType_Int"] = GetCharacterBattleStatType_IntNames();
    jsonData["CharacterBattleStatType_Float"] = GetCharacterBattleStatType_FloatNames();
    jsonData["CharacterStatusType"] = GetCharacterStatusTypeNames();
    jsonData["CharacterBaseRaceType"] = GetCharacterBaseRaceTypeNames();
    jsonData["CharacterTransformedRaceType"] = GetCharacterTransformedRaceTypeNames();
    jsonData["CharacterPowerSetType"] = GetCharacterPowerSetTypeNames();
    jsonData["CharacterWeaponSetType"] = GetCharacterWeaponSetTypeNames();
    jsonData["CharacterGenderType"] = GetCharacterGenderTypeNames();
    jsonData["CharacterHairType"] = GetCharacterHairTypeNames();
    jsonData["CharacterEyeType"] = GetCharacterEyeTypeNames();
    jsonData["CharacterHandednessType"] = GetCharacterHandednessTypeNames();
    jsonData["CharacterHandType"] = GetCharacterHandTypeNames();
    jsonData["CharacterEquipmentType"] = GetCharacterEquipmentTypeNames();
    jsonData["CharacterTargetType"] = GetCharacterTargetTypeNames();
    jsonData["CharacterPartyType"] = GetCharacterPartyTypeNames();
    jsonData["CharacterActionType"] = GetCharacterActionTypeNames();

    // SaveTypes.h
    jsonData["SaveSlotType"] = GetSaveSlotTypeNames();

    // SkillTypes.h
    jsonData["SkillTreeType"] = GetSkillTreeTypeNames();
    jsonData["SkillWeaponBaseType"] = GetSkillWeaponBaseTypeNames();
    jsonData["SkillWeaponType"] = GetSkillWeaponTypeNames();
    jsonData["SkillAlchemyType"] = GetSkillAlchemyTypeNames();
    jsonData["SkillBreakdownType"] = GetSkillBreakdownTypeNames();
    jsonData["SkillCombatType"] = GetSkillCombatTypeNames();
    jsonData["SkillCraftingType"] = GetSkillCraftingTypeNames();
    jsonData["SkillAffinityType"] = GetSkillAffinityTypeNames();

    // ItemTypes.h
    jsonData["ItemTreeType"] = GetItemTreeTypeNames();
    jsonData["ItemType"] = GetItemTypeNames();

    // TypesEnum.h
    jsonData["OperationType"] = GetOperationTypeNames();
    jsonData["ComparisonType"] = GetComparisonTypeNames();
    jsonData["FileType"] = GetFileTypeNames();
    return jsonData.dump();
}

MAKE_MODULE_RESULT_VARIANT(GetAllTypeNames);

};

PYBIND11_MAKE_OPAQUE(Gecko::TreeIndexArray);
PYBIND11_MAKE_OPAQUE(Gecko::IndexedStringArray);

PYBIND11_EMBEDDED_MODULE(GeckoUtility, m)
{
    // IndexedString.h
    PyBindClass<Gecko::IndexedString>(m, "IndexedString")
        WRAPPING_ADD_CONSTRUCTOR_SIMPLE()
        WRAPPING_ADD_CONSTRUCTOR_ARGS(const Gecko::String&)
        WRAPPING_ADD_METHOD_SIMPLE(Set, Gecko::IndexedString)
        WRAPPING_ADD_METHOD_SIMPLE(Get, Gecko::IndexedString)
        WRAPPING_ADD_METHOD_FUNC(Empty, empty, Gecko::IndexedString)
        WRAPPING_ADD_METHOD_FUNC(Length, length, Gecko::IndexedString)
        WRAPPING_ADD_METHOD_SIMPLE(IsNone, Gecko::IndexedString)
        WRAPPING_ADD_METHOD_SIMPLE(IsValid, Gecko::IndexedString)
        WRAPPING_ADD_METHOD_SIMPLE(GetIndex, Gecko::IndexedString)
    ;
    PyBindVector<Gecko::IndexedStringArray>(m, "IndexedStringArray");
    PyBindMakeImplicitlyConvertible<Gecko::String, Gecko::IndexedString>();
    PyBindMakeImplicitlyConvertible<Gecko::StringArray, Gecko::IndexedStringArray>();

    // Serializable.h
    PyBindClass<Gecko::SerializableToJson>(m, "SerializableToJson")
        WRAPPING_ADD_METHOD_SIMPLE(FromJsonString, Gecko::SerializableToJson)
        WRAPPING_ADD_METHOD_ARGS(ToJsonString, Gecko::SerializableToJson, PyBindArg("iIndent") = -1)
        WRAPPING_ADD_METHOD_SIMPLE(FromCBOR, Gecko::SerializableToJson)
        WRAPPING_ADD_METHOD_SIMPLE(FromMsgPack, Gecko::SerializableToJson)
        WRAPPING_ADD_METHOD_SIMPLE(ToCBOR, Gecko::SerializableToJson)
        WRAPPING_ADD_METHOD_SIMPLE(ToMsgPack, Gecko::SerializableToJson)
        WRAPPING_ADD_METHOD_SIMPLE(FromFile, Gecko::SerializableToJson)
        WRAPPING_ADD_METHOD_SIMPLE(FromCBORFile, Gecko::SerializableToJson)
        WRAPPING_ADD_METHOD_SIMPLE(FromMsgPackFile, Gecko::SerializableToJson)
        WRAPPING_ADD_METHOD_SIMPLE(ToFile, Gecko::SerializableToJson)
        WRAPPING_ADD_METHOD_SIMPLE(ToCBORFile, Gecko::SerializableToJson)
        WRAPPING_ADD_METHOD_SIMPLE(ToMsgPackFile, Gecko::SerializableToJson)
        WRAPPING_ADD_METHOD_SIMPLE(Reset, Gecko::SerializableToJson)
        WRAPPING_ADD_METHOD_SIMPLE(Clear, Gecko::SerializableToJson)
        WRAPPING_ADD_METHOD_SIMPLE(IsEmpty, Gecko::SerializableToJson)
        WRAPPING_ADD_BASIC_PROPERTY_READONLY_SIMPLE(Size, Gecko::SerializableToJson)
    ;

    // TreeIndex.h
    PyBindClass<Gecko::TreeIndex, Gecko::SerializableToJson>(m, "TreeIndex")
        WRAPPING_ADD_CONSTRUCTOR_SIMPLE()
        WRAPPING_ADD_CONSTRUCTOR_ARGS(const Gecko::IndexedString&, const Gecko::IndexedString&, const Gecko::IndexedString&)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(Tree, Gecko::TreeIndex)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(Branch, Gecko::TreeIndex)
        WRAPPING_ADD_BASIC_PROPERTY_SIMPLE(Leaf, Gecko::TreeIndex)
        WRAPPING_ADD_METHOD_SIMPLE(GetTreeBranchType, Gecko::TreeIndex)
        WRAPPING_ADD_METHOD_SIMPLE(GetTreeBranchLeafType, Gecko::TreeIndex)
        WRAPPING_ADD_METHOD_SIMPLE(GetTypes, Gecko::TreeIndex)
    ;
    PyBindVector<Gecko::TreeIndexArray>(m, "TreeIndexArray");
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertTreeIndexToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(ConvertTreeIndexArrayToJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetTreeIndexFromJsonString, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetTreeIndexArrayFromJsonString, Gecko);

    // Serialization.h
    WRAPPING_STANDALONE_METHOD_SIMPLE(ReadBinaryFile, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(WriteBinaryFile, Gecko);

    // Enum.h
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetOperationTypeNames, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetComparisonTypeNames, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetFileTypeNames, Gecko);

    // Templates.h
    WRAPPING_STANDALONE_METHOD_FUNC(PrintStringVector, PrintStringVector<Gecko::String>, Gecko);
    WRAPPING_STANDALONE_METHOD_FUNC(PrintIndexedStringVector, PrintStringVector<Gecko::IndexedString>, Gecko);
    WRAPPING_STANDALONE_METHOD_FUNC(ConcatStringVector, ConcatStringVector<Gecko::String>, Gecko);
    WRAPPING_STANDALONE_METHOD_FUNC(ConcatIndexedStringVector, ConcatStringVector<Gecko::IndexedString>, Gecko);

    // FantasyName.h
    WRAPPING_STANDALONE_METHOD_SIMPLE(GenerateRandomFantasyName, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetRandomNamePattern, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetCapitalizationToken, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetReverseToken, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetMiddleEarthNamePattern, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetJapaneseNameConstrainedPattern, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetJapaneseNameDiversePattern, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetChineseNamePattern, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetGreekNamePattern, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetHawaiianName1Pattern, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetHawaiianName2Pattern, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetOldLatinPlaceNamePattern, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetDragonPernNamePattern, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetDragonRiderNamePattern, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetPokemonNamePattern, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetFantasyVowelsRNamePattern, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetFantasySANamePattern, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetFantasyHLNamePattern, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetFantasyNLNamePattern, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetFantasyKNNamePattern, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetFantasyJGZNamePattern, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetFantasyKJYNamePattern, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetFantasySENamePattern, Gecko);

    // Local
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetAllTypeNames, Gecko);
    WRAPPING_STANDALONE_METHOD_SIMPLE(GetAllTypeNames_StoreResult, Gecko);
}
