// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "CharacterActionHandler/CharacterActionHandlerSkillAttack.h"
#include "Battle/BattleEvents.h"

namespace Gecko
{

CharacterActionHandlerSkillAttack::CharacterActionHandlerSkillAttack()
{
}

CharacterActionHandlerSkillAttack::~CharacterActionHandlerSkillAttack()
{
}

CharacterActionResult CharacterActionHandlerSkillAttack::GetSkillAttackResult(const CharacterAction& action, const CharacterActionEntry& entry) const
{
    // Action result
    CharacterActionResult result;

    // Get character data
    const IndexedString& sSourceCharID = action.GetSourceCharacterID();
    const IndexedString& sDestCharID = entry.GetDestinationCharacterID();
    const Character& sourceCharacter = CharacterManager::GetInstance()->GetCharacter(sSourceCharID);
    const Character& destCharacter = CharacterManager::GetInstance()->GetCharacter(sDestCharID);
    const CharacterBattleData& sourceBattleData = sourceCharacter.GetBattleDataActives();
    const CharacterBattleData& destBattleData = destCharacter.GetBattleDataActives();
    const CharacterProgressData& sourceProgressData = sourceCharacter.GetProgressDataActives();

    // Gather critical/multiple hit info
    const Float fSourceChanceToCauseCriticalHit = sourceBattleData.GetChanceToCauseCriticalHit();
    const Float fSourceChanceToApplyMultipleAttacks = sourceBattleData.GetChanceToApplyMultipleAttacks();
    //const Float fSourceCriticalHitMultiplier = sourceBattleData.GetCriticalHitMultiplier();
    const Float fSourceAttacksMultiplier = sourceBattleData.GetAttacksMultiplier();
    const Float fDestChanceToBlockCriticalHit = destBattleData.GetChanceToBlockCriticalHit();

    // Get hand info
    const CharacterHandType eHandType = StringToCharacterHandType(entry.GetHandType());
    Bool bIsPrimaryHandAction = (eHandType == +CharacterHandType::Primary);
    Bool bIsSecondaryHandAction = (eHandType == +CharacterHandType::Secondary);
    Bool bIsShield = entry.GetIsHandTypeShield();

    // Gather source ratings
    Float fPrimaryBlunt = 0;
    Float fPrimaryPierce = 0;
    Float fPrimarySlash = 0;
    Float fSecondaryBlunt = 0;
    Float fSecondaryPierce = 0;
    Float fSecondarySlash = 0;
    const IndexedString& sHandedness = sourceCharacter.GetHandedness();
    if(bIsPrimaryHandAction && !bIsShield) { sourceBattleData.GetPrimaryWeaponRatings(sHandedness, fPrimaryBlunt, fPrimaryPierce, fPrimarySlash); }
    if(bIsPrimaryHandAction && bIsShield) { sourceBattleData.GetPrimaryShieldRatings(sHandedness, fPrimaryBlunt, fPrimaryPierce, fPrimarySlash); }
    if(bIsSecondaryHandAction && !bIsShield) { sourceBattleData.GetSecondaryWeaponRatings(sHandedness, fSecondaryBlunt, fSecondaryPierce, fSecondarySlash); }
    if(bIsSecondaryHandAction && bIsShield) { sourceBattleData.GetSecondaryShieldRatings(sHandedness, fSecondaryBlunt, fSecondaryPierce, fSecondarySlash); }

    // Gather damage bonus values
    const Float fSourcePrimaryDamageBonusValue = (bIsPrimaryHandAction) ? sourceBattleData.GetWeaponPrimaryDamageBonusValue() : 0;
    const Float fSourcePrimaryDamageBonusPercent = (bIsPrimaryHandAction) ? sourceBattleData.GetWeaponPrimaryDamageBonusPercent() : 1;
    const Float fSourceSecondaryDamageBonusValue = (bIsSecondaryHandAction) ? sourceBattleData.GetWeaponSecondaryDamageBonusValue() : 0;
    const Float fSourceSecondaryDamageBonusPercent = (bIsSecondaryHandAction) ? sourceBattleData.GetWeaponSecondaryDamageBonusPercent() : 1;
    const Float fGeneralDamageBonusValue = sourceBattleData.GetGeneralDamageBonusValue();
    const Float fGeneralDamageBonusPercent = sourceBattleData.GetGeneralDamageBonusPercent();

    // Add in primary/secondary damage bonuses
    Float fSourceBlunt = 0;
    //Float fSourcePierce = 0;
    Float fSourceSlash = 0;
    if(bIsPrimaryHandAction)
    {
        fSourceBlunt = (fPrimaryBlunt * fSourcePrimaryDamageBonusPercent) + fSourcePrimaryDamageBonusValue;
        //fSourcePierce = (fPrimaryPierce * fSourcePrimaryDamageBonusPercent) + fSourcePrimaryDamageBonusValue;
        fSourceSlash = (fPrimarySlash * fSourcePrimaryDamageBonusPercent) + fSourcePrimaryDamageBonusValue;
    }
    else if(bIsSecondaryHandAction)
    {
        fSourceBlunt = (fSecondaryBlunt * fSourceSecondaryDamageBonusPercent) + fSourceSecondaryDamageBonusValue;
        //fSourcePierce = (fSecondaryPierce * fSourceSecondaryDamageBonusPercent) + fSourceSecondaryDamageBonusValue;
        fSourceSlash = (fSecondarySlash * fSourceSecondaryDamageBonusPercent) + fSourceSecondaryDamageBonusValue;
    }

    // Gather destination armor values
    const Float fDestBlunt = destBattleData.GetEquippedArmorBluntRating() +
        destBattleData.GetEquippedShieldLeftBluntRating() +
        destBattleData.GetEquippedShieldRightBluntRating();
    const Float fDestPierce = destBattleData.GetEquippedArmorPierceRating() +
        destBattleData.GetEquippedShieldLeftPierceRating() +
        destBattleData.GetEquippedShieldRightPierceRating();
    const Float fDestSlash = destBattleData.GetEquippedArmorSlashRating() +
        destBattleData.GetEquippedShieldLeftSlashRating() +
        destBattleData.GetEquippedShieldRightSlashRating();

    // Gather information about the actions requested
    Float fSourceAttackRating = 0;
    Float fDestDefendRating = 0;
    for(const IndexedString& sActionType : entry.GetActionTypes())
    {
        const CharacterActionType eActionType = StringToCharacterActionType(sActionType);
        switch(eActionType)
        {
            case CharacterActionType::WeaponBasePierce:
                fSourceAttackRating = fDestPierce;
                fDestDefendRating = fDestPierce;
                break;
            case CharacterActionType::WeaponBaseBlunt:
                fSourceAttackRating = fSourceBlunt;
                fDestDefendRating = fDestBlunt;
                break;
            case CharacterActionType::WeaponBaseSlash:
                fSourceAttackRating = fSourceSlash;
                fDestDefendRating = fDestSlash;
                break;
            default:
                break;
        }
    }

    // Check rating difference (positive means it was a successful damage)
    Float fSkillRatingDiff = fSourceAttackRating - fDestDefendRating;
    if(fSkillRatingDiff <= 0)
    {
        // If the attack is less than 10% lower than defense, apply 1 damage, otherwise none
        if(fSourceAttackRating <= (fDestDefendRating * s_kfSkillDamageBoundaryPercent))
        {
            // No damage at all
            result.SetHasTargetDefendedSuccessfully(true);
            return result;
        }
        else
        {
            // Default damage
            fSkillRatingDiff = s_kfSkillDamageBoundaryDefaultValue;
        }
    }

    // Determine number of attacks
    Bool bShouldApplyMultipleAttacks = STDDoesChanceSucceed<Float>(fSourceChanceToApplyMultipleAttacks);
    Int iNumAttacks = (bShouldApplyMultipleAttacks) ? (s_kuBaseNumberOfSkillAttacks * fSourceAttacksMultiplier) : s_kuBaseNumberOfSkillAttacks;
    result.SetHaveMultipleAttacksSucceeded(bShouldApplyMultipleAttacks);
    result.SetNumAttacksOnTarget(iNumAttacks);

    // In each attack, calculate the damage
    // This includes critical hits, which can be blocked
    Float fSkillAttackDamage = 0;
    BoolList vCriticalHitOnTarget = result.GetIndividualAttackIsCriticalCausedList();
    BoolList vTargetBlockedCriticalHit = result.GetIndividualAttackIsCriticalBlockedList();
    FloatList vIndividualAttackTargetDamage = result.GetIndividualAttackTargetDamageList();
    for(Int i = 0; i < iNumAttacks; i++)
    {
        // Determine if critical hits will happen
        Bool bCauseCriticalHit = STDDoesChanceSucceed<Float>(fSourceChanceToCauseCriticalHit);
        Bool bBlockCriticalHit = STDDoesChanceSucceed<Float>(fDestChanceToBlockCriticalHit);
        vCriticalHitOnTarget.push_back(bCauseCriticalHit);
        vTargetBlockedCriticalHit.push_back(bBlockCriticalHit);

        // Get damage for this attack
        if(!bCauseCriticalHit)
        {
            fSkillAttackDamage += fSkillRatingDiff;
            vIndividualAttackTargetDamage.push_back(fSkillRatingDiff);
        }
        else if(bCauseCriticalHit && !bBlockCriticalHit)
        {
            fSkillAttackDamage += (fSkillRatingDiff * fSourceAttacksMultiplier);
            vIndividualAttackTargetDamage.push_back(fSkillRatingDiff * fSourceAttacksMultiplier);
        }

    }
    ASSERT_ERROR((vCriticalHitOnTarget.size() == vTargetBlockedCriticalHit.size()) == vIndividualAttackTargetDamage.size());
    result.SetIndividualAttackIsCriticalCausedList(vCriticalHitOnTarget);
    result.SetIndividualAttackIsCriticalBlockedList(vTargetBlockedCriticalHit);
    result.SetIndividualAttackTargetDamageList(vIndividualAttackTargetDamage);

    // Calculate result damage now
    Int iDamage = STDRound((fSkillAttackDamage * fGeneralDamageBonusPercent) + fGeneralDamageBonusValue);
    result.SetFinalDamage(iDamage);
    return result;
}

Bool CharacterActionHandlerSkillAttack::Setup(CharacterAction& action)
{
    // Prepare character IDs
    action.PrepareCharacterIDs();

    // Setup destination characters
    for(const CharacterActionEntry& entry : action.GetActionEntries())
    {
        HandleBattleActionDefendSetup(entry.GetDestinationCharacterID());
    }

    // Setup source character
    HandleBattleActionAttackSetup(action.GetSourceCharacterID());
    return true;
}

Bool CharacterActionHandlerSkillAttack::Finish(CharacterAction& action)
{
    // Check characters
    if(!action.AreAllCharacterIDsValid())
    {
        return false;
    }

    // Finish destination character actions
    for(const CharacterActionEntry& entry : action.GetActionEntries())
    {
        HandleBattleActionFinished(entry.GetDestinationCharacterID());
    }

    // Finish source character action
    HandleBattleActionFinished(action.GetSourceCharacterID());
    return true;
}

Bool CharacterActionHandlerSkillAttack::GenerateResult(CharacterAction& action)
{
    // Check characters
    if(!action.AreAllCharacterIDsValid())
    {
        return false;
    }

    // Search action types
    for(CharacterActionEntry& entry : action.GetActionEntries())
    {
        // Generate result
        if(entry.DoesMatchActionType(IndexedString("WeaponBasePierce")) ||
           entry.DoesMatchActionType(IndexedString("WeaponBaseBlunt")) ||
           entry.DoesMatchActionType(IndexedString("WeaponBaseSlash")))
        {
            entry.SetResult(GetSkillAttackResult(entry));
        }
    }
    return true;
}

Bool CharacterActionHandlerSkillAttack::ApplyResult(CharacterAction& action)
{
    // Check characters
    if(!action.AreAllCharacterIDsValid())
    {
        return false;
    }

    // Look at each entry
    Int iFinalDamage = 0;
    for(const CharacterActionEntry& entry : action.GetActionEntries())
    {
        // Send entry damage to character
        Int iEntryDamage = entry.GetResult().GetFinalDamage();
        HandleBattleTakingDamage(entry.GetDestinationCharacterID(), iEntryDamage);

        // Add to final damage that the source character applied
        iFinalDamage += iEntryDamage;
    }

    // Send final damage to source character so they can record how much they gave
    HandleBattleGivingDamage(action.GetSourceCharacterID(), iFinalDamage);

    // Notify source character that their action was applied
    HandleBattleActionApplied(action.GetSourceCharacterID());
    return true;
}

};
