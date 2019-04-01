// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "Character/Character.h"
#include "Character/CharacterManager.h"
#include "CharacterParty/CharacterPartyManager.h"
#include "Character/CharacterTypes.h"
#include "Config/ConfigManager.h"
#include "Battle/BattleManager.h"
#include "Items/ItemTypes.h"
#include "Utility/Constants.h"
#include "Utility/Errors.h"

namespace Gecko
{

Character::Character()
{
}

Character::~Character()
{
}

void Character::RegenerateCharacterData(
    Bool bUpdateSkillRankings /*= true*/,
    Bool bUpdateEquipmentRatings /*= true*/,
    Bool bUpdateAvailableChanges /*= true*/,
    Bool bUpdateAvailableActions /*= true*/,
    Bool bUpdateAvailableAP /*= true*/
)
{
    // Reset all non-base data
    GetProgressDataPassives().Clear();
    GetBattleDataPassives().Clear();
    GetProgressDataActives().Clear();
    GetBattleDataActives().Clear();

    // Update character data
    if(bUpdateSkillRankings) { UpdateSkillRankings(IndexedString("Base")); }
    if(bUpdateEquipmentRatings) { UpdateEquipmentRatings(IndexedString("Base")); }
    if(bUpdateAvailableChanges) { UpdateAvailableChanges(IndexedString("Base")); }
    if(bUpdateAvailableActions) { UpdateAvailableActions(IndexedString("Base")); }
    if(bUpdateAvailableAP) { UpdateAvailableAP(IndexedString("Base")); }

    // Apply passives
    ApplyPassiveChanges();

    // Display the new data
#ifdef DEBUG
    Json jsonData = *this;
    LOG_FORMAT_STATEMENT("Completed regenerating character data (CharacterID = '%s'):\n%s\n",
        GetBasicData().GetCharacterID().c_str(),
        jsonData.dump(4).c_str());
#endif
}

CharacterProgressData& Character::GetProgressSegment(const IndexedString& sSegment)
{
    CharacterSegmentType eSegmentType = StringToCharacterSegmentType(sSegment);
    switch(eSegmentType)
    {
        case CharacterSegmentType::Base: return GetProgressDataBase();
        case CharacterSegmentType::Passive: return GetProgressDataPassives();
        case CharacterSegmentType::Active: return GetProgressDataActives();
        default: throw LogicError("Invalid character segment type: " + sSegment.Get());
    }
    return s_EmptyCharacterProgressData;
}

const CharacterProgressData& Character::GetProgressSegment(const IndexedString& sSegment) const
{
    CharacterSegmentType eSegmentType = StringToCharacterSegmentType(sSegment);
    switch(eSegmentType)
    {
        case CharacterSegmentType::Base: return GetProgressDataBase();
        case CharacterSegmentType::Passive: return GetProgressDataPassives();
        case CharacterSegmentType::Active: return GetProgressDataActives();
        default: throw LogicError("Invalid character segment type: " + sSegment.Get());
    }
    return s_EmptyCharacterProgressData;
}

CharacterBattleData& Character::GetBattleSegment(const IndexedString& sSegment)
{
    CharacterSegmentType eSegmentType = StringToCharacterSegmentType(sSegment);
    switch(eSegmentType)
    {
        case CharacterSegmentType::Base: return GetBattleDataBase();
        case CharacterSegmentType::Passive: return GetBattleDataPassives();
        case CharacterSegmentType::Active: return GetBattleDataActives();
        default: throw LogicError("Invalid character segment type: " + sSegment.Get());
    }
    return s_EmptyCharacterBattleData;
}

const CharacterBattleData& Character::GetBattleSegment(const IndexedString& sSegment) const
{
    CharacterSegmentType eSegmentType = StringToCharacterSegmentType(sSegment);
    switch(eSegmentType)
    {
        case CharacterSegmentType::Base: return GetBattleDataBase();
        case CharacterSegmentType::Passive: return GetBattleDataPassives();
        case CharacterSegmentType::Active: return GetBattleDataActives();
        default: throw LogicError("Invalid character segment type: " + sSegment.Get());
    }
    return s_EmptyCharacterBattleData;
}

Bool Character::GetBoolStatValue(const IndexedString& sSegment, const IndexedString& sStat, Bool& bValue) const
{
    const CharacterBattleData& battleData = GetBattleSegment(sSegment);
    return battleData.GetBoolStatValue(sStat, bValue);
}

Bool Character::GetIntStatValue(const IndexedString& sSegment, const IndexedString& sStat, Int& iValue) const
{
    const CharacterProgressData& progressData = GetProgressSegment(sSegment);
    const CharacterBattleData& battleData = GetBattleSegment(sSegment);
    return (progressData.GetIntStatValue(sStat, iValue) || battleData.GetIntStatValue(sStat, iValue));
}

Bool Character::GetFloatStatValue(const IndexedString& sSegment, const IndexedString& sStat, Float& fValue) const
{
    const CharacterBattleData& battleData = GetBattleSegment(sSegment);
    return battleData.GetFloatStatValue(sStat, fValue);
}

Bool Character::GetStringStatValue(const IndexedString& sSegment, const IndexedString& sStat, IndexedString& sValue) const
{
    const CharacterBattleData& battleData = GetBattleSegment(sSegment);
    return battleData.GetStringStatValue(sStat, sValue);
}

Bool Character::GetStringArrayStatValue(const IndexedString& sSegment, const IndexedString& sStat, IndexedStringArray& vValues) const
{
    const CharacterBattleData& battleData = GetBattleSegment(sSegment);
    return battleData.GetStringArrayStatValue(sStat, vValues);
}

Bool Character::SetBoolStatValue(const IndexedString& sSegment, const IndexedString& sStat, const Bool& bValue)
{
    CharacterBattleData& battleData = GetBattleSegment(sSegment);
    return battleData.SetBoolStatValue(sStat, bValue);
}

Bool Character::SetIntStatValue(const IndexedString& sSegment, const IndexedString& sStat, const Int& iValue)
{
    CharacterProgressData& progressData = GetProgressSegment(sSegment);
    CharacterBattleData& battleData = GetBattleSegment(sSegment);
    return (progressData.SetIntStatValue(sStat, iValue) || battleData.SetIntStatValue(sStat, iValue));
}

Bool Character::SetFloatStatValue(const IndexedString& sSegment, const IndexedString& sStat, const Float& fValue)
{
    CharacterBattleData& battleData = GetBattleSegment(sSegment);
    return battleData.SetFloatStatValue(sStat, fValue);
}

Bool Character::SetStringStatValue(const IndexedString& sSegment, const IndexedString& sStat, const IndexedString& sValue)
{
    CharacterBattleData& battleData = GetBattleSegment(sSegment);
    return battleData.SetStringStatValue(sStat, sValue);
}

Bool Character::SetStringArrayStatValue(const IndexedString& sSegment, const IndexedString& sStat, const IndexedStringArray& vValues)
{
    CharacterBattleData& battleData = GetBattleSegment(sSegment);
    return battleData.SetStringArrayStatValue(sStat, vValues);
}

Bool Character::operator==(const Character& other) const
{
    return (Json(*this) == Json(other));
}

Bool Character::operator!=(const Character& other) const
{
    return not operator==(other);
}

void Character::UpdateEquipmentRatings(const IndexedString& sSegment)
{
    // Get character data
    const CharacterProgressData& progressData = GetProgressSegment(sSegment);
    CharacterBattleData& battleData = GetBattleSegment(sSegment);

    // Update ratings
    battleData.UpdateEquipmentRatings(GetCurrentWeaponSet(), GetEquippedItems(), *progressData);
}

void Character::UpdateAvailableChanges(const IndexedString& sSegment)
{
    // Get character ID
    const IndexedString& sCharacterID = GetBasicData().GetCharacterID();

    // Fill skill indices
    TreeIndexArray vSkillPassives;
    TreeIndexArray vSkillActives;
    TreeIndexArray vSkillActionables;
    FillSkillStatChangeArrays(sCharacterID, vSkillPassives, vSkillActives, vSkillActionables, true);

    // Fill item indices
    TreeIndexArray vItemPassives;
    TreeIndexArray vItemActives;
    TreeIndexArray vItemActionables;
    FillItemStatChangeArrays(GetAllEquippedItems(sCharacterID), vItemPassives, vItemActives, vItemActionables);

    // Add to stored changes
    SetPassiveSkillDataArray(vSkillPassives);
    SetPassiveItemDataArray(vItemPassives);
    SetActiveSkillDataArray(vSkillActives);
    SetActiveItemDataArray(vItemActives);
    SetActionableSkillDataArray(vSkillActionables);
    SetActionableItemDataArray(vItemActionables);
}

void Character::UpdateAvailableActions(const IndexedString& sSegment)
{
    // Get character ID
    const IndexedString& sCharacterID = GetBasicData().GetCharacterID();

    // Clear stored actions
    CharacterActionArray& vAvailableActions = GetAvailableActions();
    vAvailableActions.clear();

    // Look at each type of tree index
    for(const IndexedString& sIndexTreeType : CharacterTreeIndexType::_names())
    {
        // Skip invalid tree types
        if(sIndexTreeType.IsNone())
        {
            continue;
        }

        // Get actionable data
        Bool bIsSkillAction = sIndexTreeType == IndexedString("Skill");

        // Look at each active change index of that type
        for(const TreeIndex& index : GetActionableChanges(sIndexTreeType))
        {
            // Look at each weapon set
            for(const IndexedString& sWeaponSet : CharacterWeaponSetType::_names())
            {
                // Skip invalid weapon sets
                if(sWeaponSet.IsNone())
                {
                    continue;
                }

                // Add skill actions
                CharacterActionArray vSkillActions;
                if(bIsSkillAction && GenerateSkillCharacterActions(index, sCharacterID, sWeaponSet, vSkillActions))
                {
                   vAvailableActions.insert(vAvailableActions.end(), vSkillActions.begin(), vSkillActions.end());
                }

                // Add item actions
                CharacterActionArray vItemActions;
                if(bIsSkillAction && GenerateItemCharacterActions(index, sCharacterID, sWeaponSet, vItemActions))
                {
                   vAvailableActions.insert(vAvailableActions.end(), vItemActions.begin(), vItemActions.end());
                }
            }
        }
    }
}

void Character::UpdateAvailableAP(const IndexedString& sSegment)
{
    // Get character ID
    const IndexedString& sCharacterID = GetBasicData().GetCharacterID();

    // Get character data
    CharacterProgressData& progressData = GetProgressSegment(sSegment);

    // Get weapon skills
    TreeIndexArray vWeaponSkills = GetWeaponSkills(sCharacterID, true);
    if(vWeaponSkills.empty())
    {
        return;
    }

    // Update available AP
    progressData.UpdateAvailableAP(vWeaponSkills);
}

void Character::UpdateSkillRankings(const IndexedString& sSegment)
{
    const SkillUseTrackingMapType& tSkillTracking = GetSkillUseTrackingMap();
    for(auto it = tSkillTracking.begin(); it != tSkillTracking.end(); it++)
    {
        const IndexedString& sSkillType = it->first;
        UInt uUseCount = it->second;
        if(sSkillType.IsNone() || uUseCount == 0)
        {
            continue;
        }

        Character::CharacterSkillFunctionNode node = GetSkillFunctions(sSkillType);
        if(node.IsValid())
        {
            UByte uRank = node.GetRank(*this);
            if(uRank >= s_kuMaxSkillRank)
            {
                continue;
            }

            UByte uCurrent = node.GetCurrent(*this);
            node.SetCurrent(*this, uCurrent + 1);
            if(static_cast<UInt>(uCurrent + 1) >= s_kuSkillRankUpgradeAmount)
            {
                node.SetCurrent(*this, 0);
                node.SetRank(*this, uRank + 1);
            }
        }
    }
}

void Character::ApplyPassiveChanges()
{
    // Get character ID
    const IndexedString& sCharacterID = GetBasicData().GetCharacterID();

    // Data sources should come from base but apply to passive
    const IndexedString sSourceSegment("Base");
    const IndexedString sDestSegment("Passive");

    // Get character base data
    const CharacterProgressData& progressData = GetProgressDataBase();
    const CharacterBattleData& battleData = GetBattleDataBase();

    // Copy passive data into active to start with
    SetProgressDataPassives(progressData);
    SetBattleDataPassives(battleData);

    // Apply passives
    for(const IndexedString& sTreeIndexType : CharacterTreeIndexType::_names())
    {
        for(const TreeIndex& index : GetPassiveChanges(sTreeIndexType))
        {
            for(StatChange change : GetStatChangesFromTreeIndex(sTreeIndexType, index))
            {
                // Resolve target placeholders
                change.ResolveTargetPlaceholders(sCharacterID, sSourceSegment);

                // Apply change
                Bool bAllChangesApplied = false;
                Bool bAtLeastOneChange = false;
                CharacterManager::GetInstance()->ApplyStatChange(sDestSegment, change, bAllChangesApplied, bAtLeastOneChange);
            }
        }
    }
}

void Character::ApplyActiveChanges(const CharacterActionSharedPtr& pAction)
{
    // Get character ID
    const IndexedString& sCharacterID = GetBasicData().GetCharacterID();

    // Data sources should come from passive but apply to active
    const IndexedString sSourceSegment("Passive");
    const IndexedString sDestSegment("Active");

    // Get character passive data
    const CharacterProgressData& progressData = GetProgressDataPassives();
    const CharacterBattleData& battleData = GetBattleDataPassives();

    // Copy passive data into active to start with
    SetProgressDataActives(progressData);
    SetBattleDataActives(battleData);

    // Apply actives
    for(const IndexedString& sTreeIndexType : CharacterTreeIndexType::_names())
    {
        for(const TreeIndex& index : GetActiveChanges(sTreeIndexType))
        {
            for(const StatChange& change : GetStatChangesFromTreeIndex(sTreeIndexType, index))
            {
                // Ignore active changes that do not meet requirements
                if(!DoesChangeMeetActiveRequirements(change, pAction))
                {
                    continue;
                }

                // Make a local copy now that we have passed the check
                StatChange localStatChange(change);

                // Resolve target placeholders
                localStatChange.ResolveTargetPlaceholders(sCharacterID, sSourceSegment);

                // Apply change
                Bool bAllChangesApplied = false;
                Bool bAtLeastOneChange = false;
                CharacterManager::GetInstance()->ApplyStatChange(sDestSegment, localStatChange, bAllChangesApplied, bAtLeastOneChange);
            }
        }
    }

    // Apply prolonged stat changes
    for(const StatChangeEntry& entry : GetProlongedStatChangeEntries())
    {
        CharacterManager::GetInstance()->ApplyStatChangeEntry(sDestSegment, entry);
    }
}

void Character::ClearActiveChanges()
{
    GetProgressDataActives().Clear();
    GetBattleDataActives().Clear();
}

void to_json(Json& jsonData, const Character& obj)
{
    // Segmented progress data
    SET_JSON_DATA_IF_NOT_DEFAULT(ProgressDataBase, CharacterProgressData());
    SET_JSON_DATA_IF_NOT_DEFAULT(ProgressDataPassives, CharacterProgressData());

    // Segmented battle data
    SET_JSON_DATA_IF_NOT_DEFAULT(BattleDataBase, CharacterBattleData());
    SET_JSON_DATA_IF_NOT_DEFAULT(BattleDataPassives, CharacterBattleData());

    // Basic data
    SET_JSON_DATA_IF_NOT_DEFAULT(BasicData, CharacterBasicData());

    // Action data
    SET_JSON_DATA_IF_NOT_DEFAULT(ActionData, CharacterActionData());

    // Item data
    SET_JSON_DATA_IF_NOT_DEFAULT(ItemData, CharacterItemData());

    // Skill data
    SET_JSON_DATA_IF_NOT_DEFAULT(SkillData, CharacterSkillData());

    // Skill use data
    SET_JSON_DATA_IF_NOT_DEFAULT(SkillUseData, CharacterSkillUseData());

    // Stat change data
    SET_JSON_DATA_IF_NOT_DEFAULT(StatChangeData, CharacterStatChangeData());
}

void from_json(const Json& jsonData, Character& obj)
{
    // Segmented progress data
    obj.SetProgressDataBase(GET_JSON_DATA_OR_DEFAULT(ProgressDataBase, CharacterProgressData));
    obj.SetProgressDataPassives(GET_JSON_DATA_OR_DEFAULT(ProgressDataPassives, CharacterProgressData));

    // Segmented battle data
    obj.SetBattleDataBase(GET_JSON_DATA_OR_DEFAULT(BattleDataBase, CharacterBattleData));
    obj.SetBattleDataPassives(GET_JSON_DATA_OR_DEFAULT(BattleDataPassives, CharacterBattleData));

    // Basic data
    obj.SetBasicData(GET_JSON_DATA_OR_DEFAULT(BasicData, CharacterBasicData));

    // Action data
    obj.SetActionData(GET_JSON_DATA_OR_DEFAULT(ActionData, CharacterActionData));

    // Item data
    obj.SetItemData(GET_JSON_DATA_OR_DEFAULT(ItemData, CharacterItemData));

    // Skill data
    obj.SetSkillData(GET_JSON_DATA_OR_DEFAULT(SkillData, CharacterSkillData));

    // Skill use data
    obj.SetSkillUseData(GET_JSON_DATA_OR_DEFAULT(SkillUseData, CharacterSkillUseData));

    // Stat change data
    obj.SetStatChangeData(GET_JSON_DATA_OR_DEFAULT(StatChangeData, CharacterStatChangeData));
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(Character, Character);

Bool operator==(const Character& a, const Character& b)
{
    return (a.GetBasicData().GetCharacterID() == b.GetBasicData().GetCharacterID());
}

};
