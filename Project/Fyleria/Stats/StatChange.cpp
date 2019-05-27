// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "Stats/StatChange.h"
#include "Character/CharacterManager.h"
#include "CharacterParty/CharacterPartyManager.h"
#include "Items/ItemTree.h"
#include "Items/ItemTypes.h"
#include "Skills/SkillTypes.h"
#include "Skills/SkillTree.h"
#include "Utility/Errors.h"
#include "Utility/Templates.h"

namespace Gecko
{

StatChange::StatChange()
{
    SetID(GenerateNewID());
}

StatChange::StatChange(const Json& jsonData)
{
    from_json(jsonData, *this);
}

void StatChange::Clear()
{
    // Relevant skill data
    SetSkillTreeIndex({});

    // Relevant item data
    SetItemTreeIndex({});

    // Percent chance to apply this change
    SetChanceToApply(0);

    // Amount of rounds to apply this change (0 is indefinite)
    SetRoundAmount(0);

    // Amount of attacks to apply this change (0 is indefinite)
    SetAttackAmount(0);

    // Amount of defends to apply this change (0 is indefinite)
    SetDefendAmount(0);

    // Required items or attack types
    SetRequiredItemEquippedTypesOR({});
    SetRequiredItemEquippedTypesAND({});
    SetRequiredItemUsedTypesOR({});
    SetRequiredItemUsedTypesAND({});
    SetRequiredAttackTypesOR({});
    SetRequiredAttackTypesAND({});
    SetRequiredDefendTypesOR({});
    SetRequiredDefendTypesAND({});
    SetRequiredPreviousAttackTypesOR({});
    SetRequiredPreviousAttackTypesAND({});
    SetRequiredPreviousDefendTypesOR({});
    SetRequiredPreviousDefendTypesAND({});
    SetRequiredEquippedWeaponCount(0);
    SetRequiredEquippedShieldCount(0);

    // Whether destination target is the same as the source target
    SetDestinationIsSource(false);

    // Source and destination targets
    SetSourceTargetType(IndexedString("None"));
    SetDestinationTargetType(IndexedString("None"));

    // Stat change entry list
    SetStatChangeEntries({});
}

ULongLong StatChange::GenerateNewID()
{
    static AtomicULongLong s_uCurrentCount(0);
    s_uCurrentCount++;
    return s_uCurrentCount;
}

Bool StatChange::IsActive() const
{
    if(GetChanceToApply() > 0)
    {
        return true;
    }
    else if(GetRoundAmount() > 0)
    {
        return true;
    }
    else if(GetAttackAmount() > 0)
    {
        return true;
    }
    else if(GetDefendAmount() > 0)
    {
        return true;
    }
    else if(DoesHaveActiveRequirements())
    {
        return true;
    }
    return false;
}

Bool StatChange::IsPassive() const
{
    return !IsActive();
}

Bool StatChange::DoesHaveActiveRequirements() const
{
    return (
        DoesHaveItemEquippedRequirements() ||
        DoesHaveItemUsedRequirements() ||
        DoesHaveAttackRequirements() ||
        DoesHaveDefendRequirements()
    );
}

Bool StatChange::DoesHaveItemEquippedRequirements() const
{
    return (
        (GetRequiredEquippedWeaponCount() > 0) ||
        (GetRequiredEquippedShieldCount() > 0) ||
        (!GetRequiredItemEquippedTypesOR().empty()) ||
        (!GetRequiredItemEquippedTypesAND().empty())
    );
}

Bool StatChange::DoesHaveItemUsedRequirements() const
{
    return (
        (!GetRequiredItemUsedTypesOR().empty()) ||
        (!GetRequiredItemUsedTypesAND().empty())
    );
}

Bool StatChange::DoesHaveAttackRequirements() const
{
    return (
        (!GetRequiredAttackTypesOR().empty()) ||
        (!GetRequiredAttackTypesAND().empty()) ||
        (!GetRequiredPreviousAttackTypesOR().empty()) ||
        (!GetRequiredPreviousAttackTypesAND().empty())
    );
}

Bool StatChange::DoesHaveDefendRequirements() const
{
    return (
        (!GetRequiredDefendTypesOR().empty()) ||
        (!GetRequiredDefendTypesAND().empty()) ||
        (!GetRequiredPreviousDefendTypesOR().empty()) ||
        (!GetRequiredPreviousDefendTypesAND().empty())
    );
}

Bool StatChange::DoesMeetItemEquippedRequirements(const IndexedString& sCharacterID, const IndexedString& sWeaponSet) const
{
    // Check character first
    if(!CharacterManager::GetInstance()->DoesCharacterExist(sCharacterID))
    {
        return false;
    }

    // Get character
    const Character& character = CharacterManager::GetInstance()->GetCharacter(sCharacterID);
    const CharacterParty& party = CharacterPartyManager::GetInstance()->GetPartyByID(character.GetPartyID());
    const CharacterPartyMember& partyMember = party.GetMemberByID(sCharacterID);

    // Get equipped item types
    IndexedStringArray vEquippedItemTypes;
    for(auto&& item : partyMember.GetEquippedItems())
    {
        vEquippedItemTypes.push_back(ItemTree::RetrieveItemType(item.GetTreeIndex()));
    }

    // Get equipped item counts
    const UInt uActualWeaponCount = partyMember.GetEquippedWeaponCount(sWeaponSet);
    const UInt uActualShieldCount = partyMember.GetEquippedShieldCount(sWeaponSet);

    // Get some info regarding this change
    const UInt uChangeRequiredWeaponCount = GetRequiredEquippedWeaponCount();
    const UInt uChangeRequiredShieldCount = GetRequiredEquippedShieldCount();
    const IndexedStringArray vChangeRequiredItemEquippedTypesOR = GetRequiredItemEquippedTypesOR();
    const IndexedStringArray vChangeRequiredItemEquippedTypesAND = GetRequiredItemEquippedTypesAND();

    // Change requires certain amounts of weapon or shields
    if(uChangeRequiredWeaponCount > 0)
    {
        return (uChangeRequiredWeaponCount == uActualWeaponCount);
    }
    else if(uChangeRequiredShieldCount > 0)
    {
        return (uChangeRequiredShieldCount == uActualShieldCount);
    }

    // Change requires specific equipped items
    else if(!vChangeRequiredItemEquippedTypesOR.empty())
    {
        return DoesVectorIntersectOR<IndexedString>(vEquippedItemTypes, vChangeRequiredItemEquippedTypesOR);
    }
    else if(!vChangeRequiredItemEquippedTypesAND.empty())
    {
        return DoesVectorIntersectAND<IndexedString>(vEquippedItemTypes, vChangeRequiredItemEquippedTypesAND);
    }
    return false;
}

Bool StatChange::DoesMeetItemUsedRequirements(const IndexedStringArray& vActionItemTypes) const
{
    // Check action item types
    if(vActionItemTypes.empty())
    {
        return false;
    }

    // Get some info regarding this change
    const IndexedStringArray vChangeRequiredItemsUsedOR = GetRequiredItemUsedTypesOR();
    const IndexedStringArray vChangeRequiredItemsUsedAND = GetRequiredItemUsedTypesAND();

    // The item type being used by the action matches the change requirement
    if(!vChangeRequiredItemsUsedOR.empty() && !vActionItemTypes.front().empty())
    {
        return DoesVectorIntersectOR<IndexedString>(vActionItemTypes, vChangeRequiredItemsUsedOR);
    }
    else if(!vChangeRequiredItemsUsedAND.empty() && !vActionItemTypes.front().empty())
    {
        return DoesVectorIntersectAND<IndexedString>(vActionItemTypes, vChangeRequiredItemsUsedAND);
    }
    return false;
}

Bool StatChange::DoesMeetAttackRequirements(const IndexedStringArray& vActionTypes) const
{
    // Get some info regarding this change
    const IndexedStringArray vChangeRequiredAttackTypesOR = GetRequiredAttackTypesOR();
    const IndexedStringArray vChangeRequiredAttackTypesAND = GetRequiredAttackTypesAND();

    // Our character is sending action, and the action's types match the required attack types
    if(!vActionTypes.empty() && !vChangeRequiredAttackTypesOR.empty())
    {
        return DoesVectorIntersectOR<IndexedString>(vActionTypes, vChangeRequiredAttackTypesOR);
    }
    else if(!vActionTypes.empty() && !vChangeRequiredAttackTypesAND.empty())
    {
        return DoesVectorIntersectAND<IndexedString>(vActionTypes, vChangeRequiredAttackTypesAND);
    }
    return false;
}

Bool StatChange::DoesMeetAttackRequirements(const IndexedStringArray& vActionTypes, const IndexedStringArray& vPreviousActionTypes) const
{
    // Check non-previous action types
    if(!DoesMeetAttackRequirements(vActionTypes))
    {
        return false;
    }

    // Get some info regarding this change
    const IndexedStringArray vChangeRequiredPreviousAttackTypesOR = GetRequiredPreviousAttackTypesOR();
    const IndexedStringArray vChangeRequiredPreviousAttackTypesAND = GetRequiredPreviousAttackTypesAND();

    // Our character is sending action, and the action's previous types match the required previous attack types
    if(!vPreviousActionTypes.empty() && !vChangeRequiredPreviousAttackTypesOR.empty())
    {
        return DoesVectorIntersectOR<IndexedString>(vPreviousActionTypes, vChangeRequiredPreviousAttackTypesOR);
    }
    else if(!vPreviousActionTypes.empty() && !vChangeRequiredPreviousAttackTypesAND.empty())
    {
        return DoesVectorIntersectAND<IndexedString>(vPreviousActionTypes, vChangeRequiredPreviousAttackTypesAND);
    }
    return false;
}

Bool StatChange::DoesMeetDefendRequirements(const IndexedStringArray& vActionTypes) const
{
    // Get some info regarding this change
    const IndexedStringArray vChangeRequiredDefendTypesOR = GetRequiredDefendTypesOR();
    const IndexedStringArray vChangeRequiredDefendTypesAND = GetRequiredDefendTypesAND();

    // Our character is receiving action, and the action's types match the required defend types
    if(!vActionTypes.empty() && !vChangeRequiredDefendTypesOR.empty())
    {
        return DoesVectorIntersectOR<IndexedString>(vActionTypes, vChangeRequiredDefendTypesOR);
    }
    else if(!vActionTypes.empty() && !vChangeRequiredDefendTypesAND.empty())
    {
        return DoesVectorIntersectAND<IndexedString>(vActionTypes, vChangeRequiredDefendTypesAND);
    }
    return false;
}

Bool StatChange::DoesMeetDefendRequirements(const IndexedStringArray& vActionTypes, const IndexedStringArray& vPreviousActionTypes) const
{
    // Check non-previous action types
    if(!DoesMeetDefendRequirements(vActionTypes))
    {
        return false;
    }

    // Get some info regarding this change
    const IndexedStringArray vChangeRequiredPreviousDefendTypesOR = GetRequiredPreviousDefendTypesOR();
    const IndexedStringArray vChangeRequiredPreviousDefendTypesAND = GetRequiredPreviousDefendTypesAND();

    // Our character is receiving action, and the action's previous types match the required previous defend types
    if(!vPreviousActionTypes.empty() && !vChangeRequiredPreviousDefendTypesOR.empty())
    {
        return DoesVectorIntersectOR<IndexedString>(vPreviousActionTypes, vChangeRequiredPreviousDefendTypesOR);
    }
    else if(!vPreviousActionTypes.empty() && !vChangeRequiredPreviousDefendTypesAND.empty())
    {
        return DoesVectorIntersectAND<IndexedString>(vPreviousActionTypes, vChangeRequiredPreviousDefendTypesAND);
    }
    return false;
}

Bool StatChange::DoesMeetActiveRequirements(const IndexedString& sCharacterID, const IndexedString& sWeaponSet) const
{
    // Check change requirements
    if(DoesHaveItemEquippedRequirements() && DoesMeetItemEquippedRequirements(sCharacterID, sWeaponSet))
    {
        return true;
    }
    return false;
}

Bool StatChange::DoesMeetActiveRequirements(const IndexedString& sCharacterID, const IndexedString& sCharacterTargetType, const IndexedString& sWeaponSet, const CharacterAction& action) const
{
    // Make sure there are some entries first
    if(action.GetActionEntries().empty())
    {
        return false;
    }

    // Find out target information for action
    Bool bSelfIsActionSender = (sCharacterTargetType == action.GetSourceTargetType());
    Bool bSelfIsActionRecipient = DoesVectorIntersectElement<IndexedString>(action.GetAllDestinationTargetTypes(), sCharacterTargetType);

    // Check change requirements
    // Only check attack/defend if they are the attacker/defender referenced by the action
    if(DoesHaveItemEquippedRequirements())
    {
        return DoesMeetItemEquippedRequirements(sCharacterID, sWeaponSet);
    }
    else if(DoesHaveItemUsedRequirements())
    {
        return DoesMeetItemUsedRequirements(ItemTree::GetActionTypes(GetItemTreeIndex()));
    }
    else if(DoesHaveAttackRequirements() && bSelfIsActionSender)
    {
        return DoesMeetAttackRequirements(action.GetAllActionTypes(), action.GetPreviousActionTypes());
    }
    else if(DoesHaveDefendRequirements() && bSelfIsActionRecipient)
    {
        return DoesMeetDefendRequirements(action.GetAllActionTypes(), action.GetPreviousActionTypes());
    }
    return false;
}

IndexedStringArray StatChange::GetIntersectingAttackRequirements(const IndexedStringArray& vActionTypes) const
{
    // Get some info regarding this change
    const IndexedStringArray vChangeRequiredAttackTypesOR = GetRequiredAttackTypesOR();
    const IndexedStringArray vChangeRequiredAttackTypesAND = GetRequiredAttackTypesAND();

    // Get the intersection of attack types
    if(!vActionTypes.empty() && !vChangeRequiredAttackTypesOR.empty())
    {
        return FindVectorIntersection<IndexedString>(vActionTypes, vChangeRequiredAttackTypesOR);
    }
    else if(!vActionTypes.empty() && !vChangeRequiredAttackTypesAND.empty())
    {
        return FindVectorIntersection<IndexedString>(vActionTypes, vChangeRequiredAttackTypesAND);
    }
    return IndexedStringArray();
}

IndexedStringArray StatChange::GetIntersectingDefendRequirements(const IndexedStringArray& vActionTypes) const
{
    // Get some info regarding this change
    const IndexedStringArray vChangeRequiredDefendTypesOR = GetRequiredDefendTypesOR();
    const IndexedStringArray vChangeRequiredDefendTypesAND = GetRequiredDefendTypesAND();

    // Get the intersection of defend types
    if(!vActionTypes.empty() && !vChangeRequiredDefendTypesOR.empty())
    {
        return FindVectorIntersection<IndexedString>(vActionTypes, vChangeRequiredDefendTypesOR);
    }
    else if(!vActionTypes.empty() && !vChangeRequiredDefendTypesAND.empty())
    {
        return FindVectorIntersection<IndexedString>(vActionTypes, vChangeRequiredDefendTypesAND);
    }
    return IndexedStringArray();
}

Bool StatChange::GetResolvedCharacterArrays(IndexedStringArray& vSourceCharIDs, IndexedStringArray& vDestCharIDs) const
{
    IndexedString sSourceTargetType = GetSourceTargetType();
    IndexedString sDestTargetType = GetDestinationTargetType();
    IndexedString sSourcePartyType = ConvertCharacterTargetTypeToCharacterPartyType(sSourceTargetType);
    IndexedString sDestPartyType = ConvertCharacterTargetTypeToCharacterPartyType(sDestTargetType);
    CharacterPartyManager::GetInstance()->GetPartyByType(sSourcePartyType).GetCharacterIDsFromTargetType(sSourceTargetType, vSourceCharIDs);
    CharacterPartyManager::GetInstance()->GetPartyByType(sDestPartyType).GetCharacterIDsFromTargetType(sDestTargetType, vDestCharIDs);
    return (!vSourceCharIDs.empty() || !vDestCharIDs.empty());
}

void StatChange::ResolveTargetPlaceholders(const IndexedString& sCharacterID, const IndexedString& sSegment)
{
    // Check character first
    if(!CharacterManager::GetInstance()->DoesCharacterExist(sCharacterID))
    {
        return;
    }

    // Get battle data
    const Character& character = CharacterManager::GetInstance()->GetCharacter(sCharacterID);
    const CharacterBattleData& battleData = character.GetBattleDataSegment(sSegment);

    // Get resolved target types
    IndexedString sSelfTargetType = character.GetCharacterTargetType();
    IndexedStringArray vSourceTargetTypes = battleData.ResolveTargetPlaceholder(sSelfTargetType, GetSourceTargetType());
    IndexedStringArray vDestTargetTypes = battleData.ResolveTargetPlaceholder(sSelfTargetType, GetDestinationTargetType());

    // Save resolved target types
    if(!vSourceTargetTypes.empty())
    {
        SetSourceTargetType(vSourceTargetTypes.front());
    }
    if(!vDestTargetTypes.empty())
    {
        SetDestinationTargetType(vDestTargetTypes.front());
    }
}

Bool StatChange::operator==(const StatChange& other) const
{
    return (GetID() == other.GetID());
}

Bool StatChange::operator<(const StatChange& other) const
{
    return (GetID() < other.GetID());
}

void to_json(Json& jsonData, const StatChange& obj)
{
    // ID
    SET_JSON_DATA_IF_NOT_DEFAULT(ID, 0);

    // Relevant skill data
    SET_JSON_DATA_IF_NOT_DEFAULT(SkillTreeIndex, TreeIndex());

    // Relevant item data
    SET_JSON_DATA_IF_NOT_DEFAULT(ItemTreeIndex, TreeIndex());

    // Percent chance to apply this change
    SET_JSON_DATA_IF_NOT_DEFAULT(ChanceToApply, 0);

    // Amount of rounds to apply this change (0 is indefinite)
    SET_JSON_DATA_IF_NOT_DEFAULT(RoundAmount, 0);

    // Amount of attacks to apply this change (0 is indefinite)
    SET_JSON_DATA_IF_NOT_DEFAULT(AttackAmount, 0);

    // Amount of defends to apply this change (0 is indefinite)
    SET_JSON_DATA_IF_NOT_DEFAULT(DefendAmount, 0);

    // Required items or attack types
    SET_JSON_DATA_IF_NOT_EMPTY(RequiredItemEquippedTypesOR);
    SET_JSON_DATA_IF_NOT_EMPTY(RequiredItemEquippedTypesAND);
    SET_JSON_DATA_IF_NOT_EMPTY(RequiredItemUsedTypesOR);
    SET_JSON_DATA_IF_NOT_EMPTY(RequiredItemUsedTypesAND);
    SET_JSON_DATA_IF_NOT_EMPTY(RequiredAttackTypesOR);
    SET_JSON_DATA_IF_NOT_EMPTY(RequiredAttackTypesAND);
    SET_JSON_DATA_IF_NOT_EMPTY(RequiredDefendTypesOR);
    SET_JSON_DATA_IF_NOT_EMPTY(RequiredDefendTypesAND);
    SET_JSON_DATA_IF_NOT_EMPTY(RequiredPreviousAttackTypesOR);
    SET_JSON_DATA_IF_NOT_EMPTY(RequiredPreviousAttackTypesAND);
    SET_JSON_DATA_IF_NOT_EMPTY(RequiredPreviousDefendTypesOR);
    SET_JSON_DATA_IF_NOT_EMPTY(RequiredPreviousDefendTypesAND);
    SET_JSON_DATA_IF_NOT_DEFAULT(RequiredEquippedWeaponCount, 0);
    SET_JSON_DATA_IF_NOT_DEFAULT(RequiredEquippedShieldCount, 0);

    // Whether destination target is the same as the source target
    SET_JSON_DATA_IF_NOT_DEFAULT(DestinationIsSource, false);

    // Source and destination targets
    SET_JSON_DATA_IF_NOT_DEFAULT(SourceTargetType, IndexedString("None"));
    SET_JSON_DATA_IF_NOT_DEFAULT(DestinationTargetType, IndexedString("None"));

    // Stat change list
    SET_JSON_DATA_IF_NOT_EMPTY(StatChangeEntries);
}

void from_json(const Json& jsonData, StatChange& obj)
{
    // ID
    obj.SetID(GET_JSON_DATA_OR_DEFAULT(ID, ULongLong, 0));

    // Relevant skill data
    obj.SetSkillTreeIndex(GET_JSON_DATA_OR_DEFAULT(SkillTreeIndex, TreeIndex, TreeIndex()));

    // Relevant item data
    obj.SetItemTreeIndex(GET_JSON_DATA_OR_DEFAULT(ItemTreeIndex, TreeIndex, TreeIndex()));

    // Percent chance to apply this change
    obj.SetChanceToApply(GET_JSON_DATA_OR_DEFAULT(ChanceToApply, Int, 0));

    // Amount of rounds to apply this change (0 is indefinite)
    obj.SetRoundAmount(GET_JSON_DATA_OR_DEFAULT(RoundAmount, Int, 0));

    // Amount of attacks to apply this change (0 is indefinite)
    obj.SetAttackAmount(GET_JSON_DATA_OR_DEFAULT(AttackAmount, Int, 0));

    // Amount of defends to apply this change (0 is indefinite)
    obj.SetDefendAmount(GET_JSON_DATA_OR_DEFAULT(DefendAmount, Int, 0));

    // Required items or attack types
    obj.SetRequiredItemEquippedTypesOR(GET_JSON_DATA_OR_DEFAULT(RequiredItemEquippedTypesOR, IndexedStringArray, IndexedStringArray()));
    obj.SetRequiredItemEquippedTypesAND(GET_JSON_DATA_OR_DEFAULT(RequiredItemEquippedTypesAND, IndexedStringArray, IndexedStringArray()));
    obj.SetRequiredItemUsedTypesOR(GET_JSON_DATA_OR_DEFAULT(RequiredItemUsedTypesOR, IndexedStringArray, IndexedStringArray()));
    obj.SetRequiredItemUsedTypesAND(GET_JSON_DATA_OR_DEFAULT(RequiredItemUsedTypesAND, IndexedStringArray, IndexedStringArray()));
    obj.SetRequiredAttackTypesOR(GET_JSON_DATA_OR_DEFAULT(RequiredAttackTypesOR, IndexedStringArray, IndexedStringArray()));
    obj.SetRequiredAttackTypesAND(GET_JSON_DATA_OR_DEFAULT(RequiredAttackTypesAND, IndexedStringArray, IndexedStringArray()));
    obj.SetRequiredDefendTypesOR(GET_JSON_DATA_OR_DEFAULT(RequiredDefendTypesOR, IndexedStringArray, IndexedStringArray()));
    obj.SetRequiredDefendTypesAND(GET_JSON_DATA_OR_DEFAULT(RequiredDefendTypesAND, IndexedStringArray, IndexedStringArray()));
    obj.SetRequiredPreviousAttackTypesOR(GET_JSON_DATA_OR_DEFAULT(RequiredPreviousAttackTypesOR, IndexedStringArray, IndexedStringArray()));
    obj.SetRequiredPreviousAttackTypesAND(GET_JSON_DATA_OR_DEFAULT(RequiredPreviousAttackTypesAND, IndexedStringArray, IndexedStringArray()));
    obj.SetRequiredPreviousDefendTypesOR(GET_JSON_DATA_OR_DEFAULT(RequiredPreviousDefendTypesOR, IndexedStringArray, IndexedStringArray()));
    obj.SetRequiredPreviousDefendTypesAND(GET_JSON_DATA_OR_DEFAULT(RequiredPreviousDefendTypesAND, IndexedStringArray, IndexedStringArray()));
    obj.SetRequiredEquippedWeaponCount(GET_JSON_DATA_OR_DEFAULT(RequiredEquippedWeaponCount, Int, 0));
    obj.SetRequiredEquippedShieldCount(GET_JSON_DATA_OR_DEFAULT(RequiredEquippedShieldCount, Int, 0));

    // Whether destination target is the same as the source target
    obj.SetDestinationIsSource(GET_JSON_DATA_OR_DEFAULT(DestinationIsSource, Bool, false));

    // Source and destination targets
    obj.SetSourceTargetType(GET_JSON_DATA_OR_DEFAULT(SourceTargetType, IndexedString, IndexedString("None")));
    obj.SetDestinationTargetType(GET_JSON_DATA_OR_DEFAULT(DestinationTargetType, IndexedString, IndexedString("None")));

    // Stat change entry list
    obj.SetStatChangeEntries(GET_JSON_DATA_OR_DEFAULT(StatChangeEntries, StatChangeEntryArray, StatChangeEntryArray()));
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(StatChange, StatChange);

const StatChangeArray& GetStatChangesFromTreeIndex(const IndexedString& sTreeIndexType, const TreeIndex& treeIndex)
{
    const CharacterTreeIndexType eTreeIndexType = StringToCharacterTreeIndexType(sTreeIndexType);
    switch(eTreeIndexType)
    {
        case CharacterTreeIndexType::Skill:
            return GetStatChangesFromSkillTreeIndex(treeIndex);
        case CharacterTreeIndexType::Item:
            return GetStatChangesFromItemTreeIndex(treeIndex);
        default:
            break;
    }
    throw RuntimeError("Invalid or unknown tree index type requested: " + sTreeIndexType.Get());
}

const StatChangeArray& GetStatChangesFromSkillTreeIndex(const TreeIndex& treeIndex)
{
    const SkillTreeType eSkillTreeType = (IsValidSkillTreeType(treeIndex.GetTree())) ? StringToSkillTreeType(treeIndex.GetTree()) : +SkillTreeType::None;
    switch(eSkillTreeType)
    {
        case SkillTreeType::Affinity:
            return SkillTree::RetrieveSkillDataAffinity(treeIndex).GetStatChanges();
        case SkillTreeType::Alchemy:
            return SkillTree::RetrieveSkillDataAlchemy(treeIndex).GetStatChanges();
        case SkillTreeType::Crafting:
            return SkillTree::RetrieveSkillDataCrafting(treeIndex).GetStatChanges();
        case SkillTreeType::Breakdown:
            return SkillTree::RetrieveSkillDataBreakdown(treeIndex).GetStatChanges();
        case SkillTreeType::Combat:
            return SkillTree::RetrieveSkillDataCombat(treeIndex).GetStatChanges();
        case SkillTreeType::Weapon:
            return SkillTree::RetrieveSkillDataWeapon(treeIndex).GetStatChanges();
        default:
            break;
    }
    throw RuntimeError("Invalid or unknown tree index requested: " + treeIndex.GetTreeBranchLeafType().Get());
}

const StatChangeArray& GetStatChangesFromItemTreeIndex(const TreeIndex& treeIndex)
{
    const ItemTreeType eItemTreeType = (IsValidItemTreeType(treeIndex.GetTree())) ? StringToItemTreeType(treeIndex.GetTree()) : +ItemTreeType::None;
    switch(eItemTreeType)
    {
        case ItemTreeType::Armor:
            return ItemTree::RetrieveItemDataArmor(treeIndex).GetStatChanges();
        case ItemTreeType::Ingredient:
            return ItemTree::RetrieveItemDataIngredient(treeIndex).GetStatChanges();
        case ItemTreeType::Potion:
            return ItemTree::RetrieveItemDataPotion(treeIndex).GetStatChanges();
        case ItemTreeType::Weapon:
            return ItemTree::RetrieveItemDataWeapon(treeIndex).GetStatChanges();
        default:
            break;
    }
    throw RuntimeError("Invalid or unknown tree index requested: " + treeIndex.GetTreeBranchLeafType().Get());
}

};
