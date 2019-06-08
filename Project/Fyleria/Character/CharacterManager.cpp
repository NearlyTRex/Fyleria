// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Character/CharacterManager.h"
#include "CharacterParty/CharacterPartyManager.h"
#include "Character/CharacterTypes.h"
#include "Battle/BattleManager.h"
#include "Utility/Errors.h"
#include "Utility/Templates.h"

namespace Gecko
{

CharacterManager::CharacterManager()
    : Singleton<CharacterManager>()
{
}

void CharacterManager::LoadCharacter(const Character& character)
{
    // Load a character
    const String& sCharacterID = character.GetCharacterID();
    ASSERT_ERROR(IsValidCharacterID(sCharacterID), "Character ID '%s' was not valid", sCharacterID.c_str());
    GetCharacters().insert({sCharacterID, character});
}

void CharacterManager::LoadCharacterFromFile(const String& sFilename, const String& sType)
{
    // Load a character
    Json jsonData;
    Bool bSuccess = ReadSerializedFile(sFilename, sType, jsonData);
    ASSERT_ERROR(bSuccess, "Unable to read file '%s' as type '%s'", sFilename.c_str(), sType.c_str());
    LoadCharacter(jsonData.get<Character>());
}

void CharacterManager::SaveCharacterToFile(const String& sCharacterID, const String& sFilename, const String& sType)
{
    // Save a character
    Json jsonData = GetCharacter(sCharacterID);
    Bool bSuccess = WriteSerializedFile(sFilename, sType, jsonData);
    ASSERT_ERROR(bSuccess, "Unable to write file '%s' as type '%s'", sFilename.c_str(), sType.c_str());
}

void CharacterManager::CreateCharacter(const String& sCharacterID)
{
    // Create a new character
    ASSERT_ERROR(!DoesCharacterExist(sCharacterID), "Character with ID '%s' was already registered", sCharacterID.c_str());
    Character newCharacter;
    newCharacter.GetBasicData().SetCharacterID(sCharacterID);
    GetCharacters().insert({sCharacterID, newCharacter});
}

void CharacterManager::UnloadCharacter(const String& sCharacterID)
{
    // Unload character
    ASSERT_ERROR(DoesCharacterExist(sCharacterID), "Character with ID '%s' was not registered", sCharacterID.c_str());
    GetCharacters().erase(sCharacterID);
}

Bool CharacterManager::DoesCharacterExist(const String& sCharacterID) const
{
    // Check if party exists
    auto iSearch = GetCharacters().find(sCharacterID);
    return (iSearch != GetCharacters().end());
}

void CharacterManager::GenerateCharacter(const String& sCharacterID, const CharacterGenerator& generator)
{
    // Log start
    LOG_FORMAT_STATEMENT("Generating character (CharacterID = '%s') ...\n", sCharacterID.c_str());

    // Check generator
    ASSERT_ERROR(!generator.IsEmpty(), "Generator is empty, it should have some data set to it. Check that it loaded properly.");
    if(generator.IsEmpty())
    {
        return;
    }

    // Make sure that this character does not already exist
    ASSERT_ERROR(!DoesCharacterExist(sCharacterID), "Character with ID '%s' was already registered", sCharacterID.c_str());

    // Create a new character
    CreateCharacter(sCharacterID);
    Character& newCharacter = GetCharacter(sCharacterID);
    newCharacter.SetBasicData(generator.GenerateBasicData(sCharacterID));
    newCharacter.SetProgressDataBase(generator.GenerateProgressData());

    // Display the new character
#ifdef DEBUG
    Json jsonData = newCharacter;
    String sJsonString = jsonData.dump(4);
    LOG_FORMAT_STATEMENT("Completed generating character (CharacterID = '%s'):\n%s\n",
        sCharacterID.c_str(),
        sJsonString.c_str());
#endif
}

Bool CharacterManager::IsValidCharacterID(const String& sCharacterID) const
{
    // Check character ID validity
    return (!sCharacterID.empty());
}

const Character& CharacterManager::GetCharacter(const String& sCharacterID) const
{
    // Get character
    ASSERT_ERROR(DoesCharacterExist(sCharacterID), "Character with ID '%s' was not registered", sCharacterID.c_str());
    auto iSearch = GetCharacters().find(sCharacterID);
    if(iSearch != GetCharacters().end())
    {
        return iSearch->second;
    }
    throw RuntimeError("Invalid or unknown character ID requested: " + sCharacterID);
}

Character& CharacterManager::GetCharacter(const String& sCharacterID)
{
    // Get character
    return const_cast<Character&>(static_cast<const CharacterManager&>(*this).GetCharacter(sCharacterID));
}

void CharacterManager::ApplyStatChange(
    const String& sSegment,
    const StatChange& change,
    Bool& bAllChangesApplied,
    Bool& bAtLeastOneChange,
    Bool bApplyAllEntries /*= false*/)
{
    // Skip invalid changes
    const TreeIndex& skillIndex = change.GetSkillTreeIndex();
    const TreeIndex& itemIndex = change.GetItemTreeIndex();
    if((skillIndex.empty() && itemIndex.empty()) ||
       change.GetStatChangeEntries().empty())
    {
        LOG_FORMAT_STATEMENT("Skipping stat change (Skill = '%s', "
                             "Item = '%s', "
                             "StatChangeEntries = %zu)\n",
            skillIndex.GetTreeBranchLeafType().c_str(),
            itemIndex.GetTreeBranchLeafType().c_str(),
            change.GetStatChangeEntries().size());
        return;
    }

    // Get character IDs
    StringArray vSourceCharIDs;
    StringArray vDestCharIDs;
    if(!change.GetResolvedCharacterArrays(vSourceCharIDs, vDestCharIDs))
    {
        LOG_FORMAT_STATEMENT("Invalid character IDs (Skill = '%s', "
                             "Item = '%s', "
                             "StatChangeEntries = %zu)\n",
            skillIndex.GetTreeBranchLeafType().c_str(),
            itemIndex.GetTreeBranchLeafType().c_str(),
            change.GetStatChangeEntries().size());
        return;
    }

    // Get tree index info
    const TreeIndex& treeIndex = (!skillIndex.empty()) ? skillIndex : itemIndex;
    LOG_FORMAT_STATEMENT("Applying stat change (Tree = '%s', "
                         "Branch = '%s', "
                         "Leaf = '%s', "
                         "StatChangeEntries = %zu, "
                         "IsSkill = %d, "
                         "IsItem = %d)\n",
        treeIndex.GetTree().c_str(),
        treeIndex.GetBranch().c_str(),
        treeIndex.GetLeaf().c_str(),
        change.GetStatChangeEntries().size(),
        (!skillIndex.empty()),
        (!itemIndex.empty()));

    // Apply each change entry
    bAllChangesApplied = (change.GetStatChangeEntries().empty()) ? false : true;
    bAtLeastOneChange = false;
    for(const StatChangeEntry& entry : change.GetStatChangeEntries())
    {
        // Check operation type
        String sOperation = entry.GetOperationType();
        ASSERT_WARNING(!sOperation.empty(),
            "Stat change (tree = '%s', type = '%s', skill = '%s') is missing a valid operation type",
            treeIndex.GetTree().c_str(),
            treeIndex.GetBranch().c_str(),
            treeIndex.GetLeaf().c_str());
        if(sOperation.empty())
        {
            continue;
        }

        // Check chance of application first
        if(change.GetChanceToApply() != 0 && !DoesChanceSucceed<Float>(change.GetChanceToApply()))
        {
            continue;
        }

        // Get source character ID
        // This normally should be just one character as the source of the value
        // Otherwise, we could have a many-to-many relationship which is harder to resolve
        String sSourceCharID = (vSourceCharIDs.size() >= 1) ? vSourceCharIDs.front() : "";

        // Check that source character ID can resolve
        if(!DoesCharacterExist(sSourceCharID))
        {
            continue;
        }

        // Make copy of stat change entry and save character data
        StatChangeEntry localEntry(entry);
        localEntry.SetSourceCharacterID(sSourceCharID);
        localEntry.SetDestinationCharacterIDs(vDestCharIDs);

        // This is where you want to determine if it is a prolonged entry
        // Create a prolonged stat change entry object and fill in the relevant start/end data
        if(!bApplyAllEntries && (localEntry.GetRound() > 1 || localEntry.GetAttack() > 1 || localEntry.GetDefend() > 1))
        {
            // Get character
            Character& character = CharacterManager::GetInstance()->GetCharacter(sSourceCharID);

            // Create prolonged stat change
            ProlongedStatChange prolongedStatChange;
            prolongedStatChange.SetStatChangeEntry(localEntry);
            if(localEntry.GetRound() > 1)
            {
                prolongedStatChange.SetRound(BattleManager::GetInstance()->GetCurrentBattle().GetCurrentRoundIndex() + localEntry.GetRound());
            }
            else if(localEntry.GetAttack() > 1)
            {
                prolongedStatChange.SetAttack(character.GetBattleDataBase().GetAttackCounter() + localEntry.GetAttack());
            }
            else if(localEntry.GetDefend() > 1)
            {
                prolongedStatChange.SetDefend(character.GetBattleDataBase().GetDefendCounter() + localEntry.GetDefend());
            }

            // Add prolonged entry
            character.GetStatChangeData().AddProlongedStatChange(treeIndex.GetTreeBranchLeafType(), prolongedStatChange);
        }
        else
        {
            // Process entry now
            Bool bSuccessful = ApplyStatChangeEntry(sSegment, localEntry);
            bAllChangesApplied = bAllChangesApplied && bSuccessful;
            bAtLeastOneChange = bAtLeastOneChange || bSuccessful;
        }
    }
}

Bool CharacterManager::ApplyStatChangeEntry(const String& sSegment, const StatChangeEntry& entry)
{
    // Source values
    BoolArray vSourceBoolValues;
    IntArray vSourceIntValues;
    FloatArray vSourceFloatValues;
    StringArray vSourceStringValues;

    // Get source values
    Bool bDoesUseDelta = DoesStatChangeEntryUseDelta(entry);
    if(bDoesUseDelta)
    {
        if(!GetDeltaStatChangeEntryValues(sSegment, entry.GetSourceCharacterID(), entry,
            vSourceBoolValues, vSourceIntValues, vSourceFloatValues, vSourceStringValues))
        {
            return false;
        }
    }
    else
    {
        if(!GetFullStatChangeEntryValues(sSegment, entry.GetSourceCharacterID(), entry,
            vSourceBoolValues, vSourceIntValues, vSourceFloatValues, vSourceStringValues))
        {
            return false;
        }
    }

    // Loop through destination characters
    // We are going to try to apply this change to all of them
    String sDestStatType = entry.GetDestinationStatType();
    Bool bAtLeastOneChange = false;
    String sOperation = entry.GetOperationType();
    for(const String& sDestCharID : entry.GetDestinationCharacterIDs())
    {
        // Float value in a Float stat
        if(vSourceFloatValues.size() == 1 && IsStatFloat(sDestStatType))
        {
            Float fNewValue = vSourceFloatValues[0];
            Bool bResult = ApplyStatChangeEntryOperation(sSegment, sDestCharID, sOperation, sDestStatType, fNewValue);
            bAtLeastOneChange = bAtLeastOneChange || bResult;
        }

        // Float value in an Int stat
        else if(vSourceFloatValues.size() == 1 && IsStatInt(sDestStatType))
        {
            Int iNewValue = static_cast<Int>(STDRound(vSourceFloatValues[0]));
            Bool bResult = ApplyStatChangeEntryOperation(sSegment, sDestCharID, sOperation, sDestStatType, iNewValue);
            bAtLeastOneChange = bAtLeastOneChange || bResult;
        }

        // Int value in an Int stat
        else if(vSourceIntValues.size() == 1 && IsStatInt(sDestStatType))
        {
            Int iNewValue = vSourceIntValues[0];
            Bool bResult = ApplyStatChangeEntryOperation(sSegment, sDestCharID, sOperation, sDestStatType, iNewValue);
            bAtLeastOneChange = bAtLeastOneChange || bResult;
        }

        // Int value in a Float stat
        else if(vSourceIntValues.size() == 1 && IsStatFloat(sDestStatType))
        {
            Float fNewValue = static_cast<Float>(vSourceIntValues[0]);
            Bool bResult = ApplyStatChangeEntryOperation(sSegment, sDestCharID, sOperation, sDestStatType, fNewValue);
            bAtLeastOneChange = bAtLeastOneChange || bResult;
        }

        // Int value in a Bool stat
        else if(vSourceIntValues.size() == 1 && IsStatBool(sDestStatType))
        {
            Bool bNewValue = static_cast<Bool>(vSourceIntValues[0]);
            Bool bResult = ApplyStatChangeEntryOperation(sSegment, sDestCharID, sOperation, sDestStatType, bNewValue);
            bAtLeastOneChange = bAtLeastOneChange || bResult;
        }

        // Bool value in a Bool stat
        else if(vSourceBoolValues.size() == 1 && IsStatBool(sDestStatType))
        {
            Bool bNewValue = vSourceBoolValues[0];
            Bool bResult = ApplyStatChangeEntryOperation(sSegment, sDestCharID, sOperation, sDestStatType, bNewValue);
            bAtLeastOneChange = bAtLeastOneChange || bResult;
        }

        // String value in a String stat
        else if(vSourceStringValues.size() == 1 && IsStatString(sDestStatType))
        {
            String sNewValue = vSourceStringValues[0];
            Bool bResult = ApplyStatChangeEntryOperation(sSegment, sDestCharID, sOperation, sDestStatType, sNewValue);
            bAtLeastOneChange = bAtLeastOneChange || bResult;
        }

        // StringArray value in a StringArray stat
        else if(vSourceStringValues.size() > 1 && IsStatStringArray(sDestStatType))
        {
            StringArray vNewValues = vSourceStringValues;
            Bool bResult = ApplyStatChangeEntryOperation(sSegment, sDestCharID, sOperation, sDestStatType, vNewValues);
            bAtLeastOneChange = bAtLeastOneChange || bResult;
        }
    }
    return bAtLeastOneChange;
}

Bool CharacterManager::ApplyStatChangeEntryOperation(
    const String& sSegment,
    const String& sCharacterID,
    const String& sOperation,
    const String& sStat,
    Bool bValue)
{
    // Get character
    Character& character = GetCharacter(sCharacterID);

    // Apply new value
    const OperationType eOperationType = StringToOperationType(sOperation);
    switch(eOperationType)
    {
        case OperationType::Set:
            LOG_FORMAT_STATEMENT("-- Setting %d to %s stat in character '%s'\n",
                bValue,
                sStat.c_str(),
                sCharacterID.c_str());
            return character.SetBoolStatValue(sSegment, sStat, bValue);
        default:
            break;
    }
    return false;
}

Bool CharacterManager::ApplyStatChangeEntryOperation(
    const String& sSegment,
    const String& sCharacterID,
    const String& sOperation,
    const String& sStat,
    Int iValue)
{
    // Get character
    Character& character = GetCharacter(sCharacterID);

    // Get existing value
    Int iStatValue = 0;
    if(!character.GetIntStatValue(sSegment, sStat, iStatValue))
    {
        return false;
    }

    // Apply new value
    const OperationType eOperationType = StringToOperationType(sOperation);
    switch(eOperationType)
    {
        case OperationType::Add:
            LOG_FORMAT_STATEMENT("-- Adding %i to %s's current value of %i in character '%s'\n",
                iValue,
                sStat.c_str(),
                iStatValue,
                sCharacterID.c_str());
            return character.SetIntStatValue(sSegment, sStat, iStatValue + iValue);
        case OperationType::Subtract:
            LOG_FORMAT_STATEMENT("-- Subtracting %i from %s's current value of %i in character '%s'\n",
                iValue,
                sStat.c_str(),
                iStatValue,
                sCharacterID.c_str());
            return character.SetIntStatValue(sSegment, sStat, iStatValue - iValue);
        case OperationType::Multiply:
            LOG_FORMAT_STATEMENT("-- Multiplying %i against %s's current value of %i in character '%s'\n",
                iValue,
                sStat.c_str(),
                iStatValue,
                sCharacterID.c_str());
            return character.SetIntStatValue(sSegment, sStat, iStatValue * iValue);
        case OperationType::Divide:
            if(iValue != 0)
            {
                LOG_FORMAT_STATEMENT("-- Dividing %s's current value of %i by %i in character '%s'\n",
                    sStat.c_str(),
                    iStatValue,
                    iValue,
                    sCharacterID.c_str());
                return character.SetIntStatValue(sSegment, sStat, iStatValue / iValue);
            }
        case OperationType::Modulus:
            if(iValue != 0)
            {
                LOG_FORMAT_STATEMENT("-- Modulusing %s's current value of %i by %i in character '%s'\n",
                    sStat.c_str(),
                    iStatValue,
                    iValue,
                    sCharacterID.c_str());
                return character.SetIntStatValue(sSegment, sStat, iStatValue % iValue);
            }
        case OperationType::Set:
            LOG_FORMAT_STATEMENT("-- Setting %i to %s stat in character '%s'\n",
                iValue,
                sStat.c_str(),
                sCharacterID.c_str());
            return character.SetIntStatValue(sSegment, sStat, iValue);
        default:
            break;
    }
    return false;
}

Bool CharacterManager::ApplyStatChangeEntryOperation(
    const String& sSegment,
    const String& sCharacterID,
    const String& sOperation,
    const String& sStat,
    Float fValue)
{
    // Get character
    Character& character = GetCharacter(sCharacterID);

    // Get existing value
    Float fStatValue = 0;
    if(!character.GetFloatStatValue(sSegment, sStat, fStatValue))
    {
        return false;
    }

    // Apply new value
    const OperationType eOperationType = StringToOperationType(sOperation);
    switch(eOperationType)
    {
        case OperationType::Add:
            LOG_FORMAT_STATEMENT("-- Adding %f to %s's current value of %f in character '%s'\n",
                fValue,
                sStat.c_str(),
                fStatValue,
                sCharacterID.c_str());
            return character.SetFloatStatValue(sSegment, sStat, fStatValue + fValue);
        case OperationType::Subtract:
            LOG_FORMAT_STATEMENT("-- Subtracting %f from %s's current value of %f in character '%s'\n",
                fValue,
                sStat.c_str(),
                fStatValue,
                sCharacterID.c_str());
            return character.SetFloatStatValue(sSegment, sStat, fStatValue - fValue);
        case OperationType::Multiply:
            LOG_FORMAT_STATEMENT("-- Multiplying %f against %s's current value of %f in character '%s'\n",
                fValue,
                sStat.c_str(),
                fStatValue,
                sCharacterID.c_str());
            return character.SetFloatStatValue(sSegment, sStat, fStatValue * fValue);
        case OperationType::Divide:
            if(fValue != 0)
            {
                LOG_FORMAT_STATEMENT("-- Dividing %s's current value of %f by %f in character '%s'\n",
                    sStat.c_str(),
                    fStatValue,
                    fValue,
                    sCharacterID.c_str());
                return character.SetFloatStatValue(sSegment, sStat, fStatValue / fValue);
            }
        case OperationType::Modulus:
            if(fValue != 0)
            {
                LOG_FORMAT_STATEMENT("-- Modulusing %s's current value of %f by %f in character '%s'\n",
                    sStat.c_str(),
                    fStatValue,
                    fValue,
                    sCharacterID.c_str());
                return character.SetFloatStatValue(sSegment, sStat, STDFmod(fStatValue, fValue));
            }
        case OperationType::Set:
            LOG_FORMAT_STATEMENT("-- Setting %f to %s in character '%s'\n",
                fValue,
                sStat.c_str(),
                sCharacterID.c_str());
            return character.SetFloatStatValue(sSegment, sStat, fValue);
        default:
            break;
    }
    return false;
}

Bool CharacterManager::ApplyStatChangeEntryOperation(
    const String& sSegment,
    const String& sCharacterID,
    const String& sOperation,
    const String& sStat,
    const String& sValue)
{
    // Get character
    Character& character = GetCharacter(sCharacterID);

    // Get existing value
    String sStatValue("");
    if(!character.GetStringStatValue(sSegment, sStat, sStatValue))
    {
        return false;
    }

    // Apply new value
    const OperationType eOperationType = StringToOperationType(sOperation);
    switch(eOperationType)
    {
        case OperationType::Add:
            LOG_FORMAT_STATEMENT("-- Adding %s to %s's current value of %s in character '%s'\n",
                sValue.c_str(),
                sStat.c_str(),
                sStatValue.c_str(),
                sCharacterID.c_str());
            return character.SetStringStatValue(sSegment, sStat, sStatValue + sValue);
        case OperationType::Set:
            LOG_FORMAT_STATEMENT("-- Setting %s to %s stat in character '%s'\n",
                sValue.c_str(),
                sStat.c_str(),
                sCharacterID.c_str());
            return character.SetStringStatValue(sSegment, sStat, sValue);
        default:
            break;
    }
    return false;
}

Bool CharacterManager::ApplyStatChangeEntryOperation(
    const String& sSegment,
    const String& sCharacterID,
    const String& sOperation,
    const String& sStat,
    const StringArray& vValues)
{
    // Get character
    Character& character = GetCharacter(sCharacterID);

    // Apply new value
    const OperationType eOperationType = StringToOperationType(sOperation);
    switch(eOperationType)
    {
        case OperationType::Set:
        {
#ifdef DEBUG
            String sValue = "";
            for(UInt i = 0; i < vValues.size(); i++)
            {
                sValue += (vValues[i] + String(","));
            }
            LOG_FORMAT_STATEMENT("-- Setting (%s) to %s stat in character '%s'\n",
                sValue.c_str(),
                sStat.c_str(),
                sCharacterID.c_str());
#endif
            return character.SetStringArrayStatValue(sSegment, sStat, vValues);
        }
        default:
            break;
    }
    return false;
}

Bool CharacterManager::DoesStatChangeEntryUseDelta(const StatChangeEntry& changeEntry) const
{
    return (changeEntry.GetDeltaInt() != 0 || changeEntry.GetDeltaFloat() != 0);
}

Bool CharacterManager::GetDeltaStatChangeEntryValues(
    const String& sSegment,
    const String& sCharacterID,
    const StatChangeEntry& changeEntry,
    BoolArray& vBoolValues,
    IntArray& vIntValues,
    FloatArray& vFloatValues,
    StringArray& vStringValues) const
{
    // Clear values
    vBoolValues.clear();
    vIntValues.clear();
    vFloatValues.clear();
    vStringValues.clear();

    // Get character
    const Character& character = GetCharacter(sCharacterID);

    // Delta changes require a source stat type which will later be applied to a dest stat type
    String sSourceStatType = changeEntry.GetSourceStatType();

    // Get source value
    Bool bSuccess = false;
    if(changeEntry.GetDeltaInt() != 0)
    {
        Int iStatValue = 0;
        if(character.GetIntStatValue(sSegment, sSourceStatType, iStatValue))
        {
            Int iNewValue = iStatValue + changeEntry.GetDeltaInt();
            LOG_FORMAT_STATEMENT("-- Getting %s value of %i from character '%s' and adding delta int of %i to get int value %i\n",
                sSourceStatType.c_str(),
                iStatValue,
                sCharacterID.c_str(),
                changeEntry.GetDeltaInt(),
                iNewValue);
            vIntValues.push_back(iNewValue);
            bSuccess = true;
        }
    }
    else if(changeEntry.GetDeltaFloat() != 0)
    {
        Float fStatValue = 0;
        if(character.GetFloatStatValue(sSegment, sSourceStatType, fStatValue))
        {
            Float fNewValue = fStatValue + changeEntry.GetDeltaFloat();
            LOG_FORMAT_STATEMENT("-- Getting %s value of %f from character '%s' and adding delta float of %f to get float value %f\n",
                sSourceStatType.c_str(),
                fStatValue,
                sCharacterID.c_str(),
                changeEntry.GetDeltaFloat(),
                fNewValue);
            vFloatValues.push_back(fNewValue);
            bSuccess = true;
        }
    }
    return bSuccess;
}

Bool CharacterManager::GetFullStatChangeEntryValues(
    const String& sSegment,
    const String& sCharacterID,
    const StatChangeEntry& changeEntry,
    BoolArray& vBoolValues,
    IntArray& vIntValues,
    FloatArray& vFloatValues,
    StringArray& vStringValues) const
{
    // Clear values
    vBoolValues.clear();
    vIntValues.clear();
    vFloatValues.clear();
    vStringValues.clear();

    // Get character
    const Character& character = GetCharacter(sCharacterID);

    // Full changes require just a destination stat type
    String sDestStatType = changeEntry.GetDestinationStatType();

    // Get dest value
    Bool bSuccess = false;
    if(changeEntry.GetFullPercent() != 0)
    {
        Float fStatValue = 0;
        Int iStatValue = 0;
        if(character.GetIntStatValue(sSegment, sDestStatType, iStatValue))
        {
            fStatValue = static_cast<Float>(iStatValue);
            Float fNewValue = changeEntry.GetFullPercent() * fStatValue;
            LOG_FORMAT_STATEMENT("-- Getting %s value of %i from character '%s' and multiplying by full percent of %f to get float value %f\n",
                sDestStatType.c_str(),
                iStatValue,
                sCharacterID.c_str(),
                changeEntry.GetFullPercent(),
                fNewValue);
            vFloatValues.push_back(fNewValue);
            bSuccess = true;
        }
        else if(character.GetFloatStatValue(sSegment, sDestStatType, fStatValue))
        {
            Float fNewValue = changeEntry.GetFullPercent() * fStatValue;
            LOG_FORMAT_STATEMENT("-- Getting %s value of %f from character '%s' and multiplying by full percent of %f to get float value %f\n",
                sDestStatType.c_str(),
                fStatValue,
                sCharacterID.c_str(),
                changeEntry.GetFullPercent(),
                fNewValue);
            vFloatValues.push_back(fNewValue);
            bSuccess = true;
        }
    }
    else if(changeEntry.GetFullInt() != 0)
    {
        Int iNewValue = changeEntry.GetFullInt();
        LOG_FORMAT_STATEMENT("-- Using full int value of %i directly\n", iNewValue);
        vIntValues.push_back(iNewValue);
        bSuccess = true;
    }
    else if(changeEntry.GetFullFloat() != 0)
    {
        Float fNewValue = changeEntry.GetFullFloat();
        LOG_FORMAT_STATEMENT("-- Using full float value of %f directly\n", fNewValue);
        vFloatValues.push_back(fNewValue);
        bSuccess = true;
    }
    else if(!changeEntry.GetFullString().empty())
    {
        String sNewValue = changeEntry.GetFullString();
        LOG_FORMAT_STATEMENT("-- Using full string value of %s directly\n", sNewValue.c_str());
        vStringValues.push_back(sNewValue);
        bSuccess = true;
    }
    else if(!changeEntry.GetFullStringArray().empty())
    {
        StringArray vNewValues = changeEntry.GetFullStringArray();
        LOG_FORMAT_STATEMENT("-- Using full string array value of %s directly\n", ConcatStringVector<String>(vNewValues).c_str());
        vStringValues = vNewValues;
        bSuccess = true;
    }
    return bSuccess;
}

};
