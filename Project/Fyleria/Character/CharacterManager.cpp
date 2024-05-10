// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Character/CharacterTypes.h"
#include "Utility/Errors.h"
#include "Utility/Templates.h"
#include "Application/Application.h"

namespace Gecko
{

CharacterManager::CharacterManager()
{
}

Bool CharacterManager::LoadCharacter(const Character& character, Bool bRegenerateData)
{
    // Get character ID
    const String& sCharacterID = character.GetCharacterID();
    if(!IsValidCharacterID(sCharacterID))
    {
        return false;
    }

    // Load character
    GetCharacters().insert({sCharacterID, character});
    if(bRegenerateData)
    {
        GetCharacters().at(sCharacterID).RegenerateAllCharacterData();
    }

    // Check character
    return DoesCharacterExist(sCharacterID);
}

Bool CharacterManager::LoadCharacterFromFile(const String& sFilename, const String& sType, Bool bRegenerateData)
{
    // Deserialize file into character data
    Json jsonData;
    Bool bSuccess = ReadSerializedFile(sFilename, sType, jsonData, GetManagers()->GetFileManager()->GetDataCharactersDirectory());
    if(!bSuccess)
    {
        return false;
    }

    // Load character
    return LoadCharacter(jsonData.get<Character>(), bRegenerateData);
}

Bool CharacterManager::SaveCharacterToFile(const String& sCharacterID, const String& sFilename, const String& sType)
{
    // Check character ID
    if(!IsValidCharacterID(sCharacterID))
    {
        return false;
    }

    // Serialize character data into file
    Json jsonData = GetSaveableData(GetCharacter(sCharacterID));
    return WriteSerializedFile(sFilename, sType, jsonData, GetManagers()->GetFileManager()->GetDataCharactersDirectory());
}

Bool CharacterManager::CreateCharacter(const String& sCharacterID)
{
    // Check character ID
    if(!IsValidCharacterID(sCharacterID))
    {
        return false;
    }

    // Create a new character
    Character newCharacter;
    newCharacter.Clear();
    newCharacter.GetBasicData().SetCharacterID(sCharacterID);
    GetCharacters().insert({sCharacterID, newCharacter});

    // Check character
    return DoesCharacterExist(sCharacterID);
}

Bool CharacterManager::UnloadCharacter(const String& sCharacterID)
{
    // Check character ID
    if(!IsValidCharacterID(sCharacterID))
    {
        return false;
    }

    // Unload character
    GetCharacters().erase(sCharacterID);

    // Check character
    return !DoesCharacterExist(sCharacterID);
}

Bool CharacterManager::UnloadAllCharacters()
{
    // Unload all characters
    GetCharacters().clear();

    // Check characters
    return GetCharacters().empty();
}

Bool CharacterManager::DoesCharacterExist(const String& sCharacterID) const
{
    // Check character ID
    if(!IsValidCharacterID(sCharacterID))
    {
        return false;
    }

    // Check if character exists
    auto iSearch = GetCharacters().find(sCharacterID);
    return (iSearch != GetCharacters().end());
}

Bool CharacterManager::GenerateCharacter(const String& sCharacterID, const CharacterGenerator& generator, Bool bRegenerateData)
{
    // Check character ID
    if(!IsValidCharacterID(sCharacterID))
    {
        return false;
    }

    // Log start
    LOG_FORMAT_STATEMENT("Generating character (CharacterID = '{}') ...", sCharacterID.c_str());

    // Create a new character
    CreateCharacter(sCharacterID);
    Character& newCharacter = GetCharacter(sCharacterID);
    newCharacter.SetBasicData(generator.GenerateBasicData(sCharacterID));
    newCharacter.SetProgressData(generator.GenerateProgressData());
    newCharacter.SetSkillData(generator.GenerateSkillData());
    if(bRegenerateData)
    {
        newCharacter.RegenerateAllCharacterData();
    }

    // Check character
    return DoesCharacterExist(sCharacterID);
}

Bool CharacterManager::IsValidCharacterID(const String& sCharacterID) const
{
    // Check character ID validity
    return (!sCharacterID.empty());
}

const Character& CharacterManager::GetCharacter(const String& sCharacterID) const
{
    // Check character ID
    if(!IsValidCharacterID(sCharacterID))
    {
        THROW_RUNTIME_ERROR("Character ID '" + sCharacterID + "' was not valid");
    }

    // Check if character exists
    if(!DoesCharacterExist(sCharacterID))
    {
        THROW_RUNTIME_ERROR("Character with ID '" + sCharacterID + "' was not registered");
    }

    // Get character
    auto iSearch = GetCharacters().find(sCharacterID);
    if(iSearch != GetCharacters().end())
    {
        return iSearch->second;
    }
    THROW_RUNTIME_ERROR("Invalid or unknown character ID requested: " + sCharacterID);
}

Character& CharacterManager::GetCharacter(const String& sCharacterID)
{
    // Get character
    return const_cast<Character&>(static_cast<const CharacterManager&>(*this).GetCharacter(sCharacterID));
}

StringArray CharacterManager::GetAllCharacterIDs() const
{
    StringArray vAllCharacters;
    for(auto it = GetCharacters().begin(); it != GetCharacters().end(); it++)
    {
        vAllCharacters.push_back(it->first);
    }
    return vAllCharacters;
}

Bool CharacterManager::ApplyStatChange(
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
        LOG_FORMAT_STATEMENT("Skipping stat change (Skill = '{}', "
                             "Item = '{}', "
                             "StatChangeEntries = {})",
            skillIndex.GetTreeBranchLeafType().c_str(),
            itemIndex.GetTreeBranchLeafType().c_str(),
            change.GetStatChangeEntries().size());
        return false;
    }

    // Get character IDs
    StringArray vSourceCharIDs;
    StringArray vDestCharIDs;
    if(!change.GetResolvedCharacterArrays(vSourceCharIDs, vDestCharIDs))
    {
        LOG_FORMAT_STATEMENT("Invalid character IDs (Skill = '{}', "
                             "Item = '{}', "
                             "StatChangeEntries = {})",
            skillIndex.GetTreeBranchLeafType().c_str(),
            itemIndex.GetTreeBranchLeafType().c_str(),
            change.GetStatChangeEntries().size());
        return false;
    }

    // Get tree index info
    const TreeIndex& treeIndex = (!skillIndex.empty()) ? skillIndex : itemIndex;
    LOG_FORMAT_STATEMENT("Applying stat change (Tree = '{}', "
                         "Branch = '{}', "
                         "Leaf = '{}', "
                         "StatChangeEntries = {}, "
                         "IsSkill = {}, "
                         "IsItem = {})",
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
        String sOperationType = entry.GetOperationType();
        if(sOperationType.empty())
        {
            WARNING_FORMAT_STATEMENT("Stat change (tree = '{}', type = '{}', skill = '{}') is missing a valid operation type",
                treeIndex.GetTree().c_str(),
                treeIndex.GetBranch().c_str(),
                treeIndex.GetLeaf().c_str());
            continue;
        }

        // Check assignment type
        String sAssignmentType = entry.GetAssignmentType();
        if(sAssignmentType.empty())
        {
            WARNING_FORMAT_STATEMENT("Stat change (tree = '{}', type = '{}', skill = '{}') is missing a valid assignment type",
                treeIndex.GetTree().c_str(),
                treeIndex.GetBranch().c_str(),
                treeIndex.GetLeaf().c_str());
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
            Character& character = GetManagers()->GetCharacterManager()->GetCharacter(sSourceCharID);

            // Create prolonged stat change
            ProlongedStatChange prolongedStatChange;
            prolongedStatChange.SetStatChangeEntry(localEntry);
            if(localEntry.GetRound() > 1)
            {
                prolongedStatChange.SetRound(GetManagers()->GetBattleManager()->GetCurrentBattle().GetCurrentRoundIndex() + localEntry.GetRound());
            }
            else if(localEntry.GetAttack() > 1)
            {
                prolongedStatChange.SetAttack(character.GetBattleData().GetAttackCounter() + localEntry.GetAttack());
            }
            else if(localEntry.GetDefend() > 1)
            {
                prolongedStatChange.SetDefend(character.GetBattleData().GetDefendCounter() + localEntry.GetDefend());
            }

            // Add prolonged entry
            character.GetStatChangeData().AddProlongedStatChange(treeIndex.GetTreeBranchLeafType(), prolongedStatChange);
        }
        else
        {
            // Process entry now
            Bool bSuccessful = false;
            if (IsStatInt(localEntry.GetDestinationStatType()))
            {
                bSuccessful = ApplyStatChangeEntry<Int>(localEntry);
            }
            else if(IsStatFloat(localEntry.GetDestinationStatType()))
            {
                bSuccessful = ApplyStatChangeEntry<Float>(localEntry);
            }
            bAllChangesApplied = bAllChangesApplied && bSuccessful;
            bAtLeastOneChange = bAtLeastOneChange || bSuccessful;
        }
    }
    return bAtLeastOneChange;
}

};
