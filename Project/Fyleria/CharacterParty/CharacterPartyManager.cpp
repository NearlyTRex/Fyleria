// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "CharacterParty/CharacterPartyManager.h"
#include "Character/CharacterConstants.h"
#include "Character/CharacterTypes.h"
#include "Utility/Errors.h"
#include "Application/Application.h"

namespace Gecko
{

CharacterPartyManager::CharacterPartyManager()
{
}

Bool CharacterPartyManager::LoadParty(const CharacterParty& party, Bool bRegenerateData /*= false*/, Bool bSetAsCurrent /*= false*/)
{
    // Check if party ID is valid
    const String& sPartyID = party.GetPartyID();
    if(!IsValidPartyID(sPartyID))
    {
        return false;
    }

    // Check if party type is valid
    const String& sPartyType = party.GetPartyType();
    if(!IsValidEnumString<CharacterPartyType>(sPartyType))
    {
        return false;
    }

    // Load party
    GetParties().insert({sPartyID, party});
    if(bRegenerateData)
    {
        GetParties().at(sPartyID).RegenerateCharacterData();
    }

    // Set as current party
    if(bSetAsCurrent)
    {
        SetAsCurrentParty(sPartyID, sPartyType);
    }

    // Check party
    return DoesPartyExistByID(sPartyID);
}

Bool CharacterPartyManager::LoadPartyFromFile(const String& sFilename, const String& sType, Bool bRegenerateData /*= false*/, Bool bSetAsCurrent /*= false*/)
{
    // Deserialize file into party data
    Json jsonData;
    Bool bSuccess = ReadSerializedFile(sFilename, sType, jsonData, GetManagers()->GetFileManager()->GetDataPartiesDirectory());
    if(!bSuccess)
    {
        return false;
    }

    // Load party
    return LoadParty(jsonData.get<CharacterParty>(), bRegenerateData, bSetAsCurrent);
}

Bool CharacterPartyManager::SavePartyToFile(const String& sPartyID, const String& sFilename, const String& sType)
{
    // Check party ID
    if(!IsValidPartyID(sPartyID))
    {
        return false;
    }

    // Serialize party data into file
    Json jsonData = GetPartyByID(sPartyID);
    return WriteSerializedFile(sFilename, sType, jsonData, GetManagers()->GetFileManager()->GetDataPartiesDirectory());
}

Bool CharacterPartyManager::CreateParty(const String& sPartyID, const String& sPartyType, Bool bSetAsCurrent /*= false*/)
{
    // Check party ID
    if(!IsValidPartyID(sPartyID))
    {
        return false;
    }

    // Check party type
    if(!IsValidEnumString<CharacterPartyType>(sPartyType))
    {
        return false;
    }

    // Create a new party
    StringArray vAvailableTargetTypes;
    for(UInt i = 1; i <= MAX_TEAM_CHARACTER_AMOUNT; i++)
    {
        vAvailableTargetTypes.push_back(sPartyType + String(STDToString(i)));
    }
    CharacterParty newParty;
    newParty.SetPartyID(sPartyID);
    newParty.SetPartyType(sPartyType);
    newParty.SetAvailableTargetTypes(vAvailableTargetTypes);
    newParty.ResetPlayTime();
    GetParties().insert({sPartyID, newParty});

    // Set as current ally/enemy
    if(bSetAsCurrent)
    {
        SetAsCurrentParty(sPartyID, sPartyType);
    }

    // Check party
    return DoesPartyExistByID(sPartyID);
}

Bool CharacterPartyManager::UnloadParty(const String& sPartyID)
{
    // Check party ID
    if(!IsValidPartyID(sPartyID))
    {
        return false;
    }

    // Unload party
    GetParties().erase(sPartyID);
    if(sPartyID == GetCurrentAllyPartyID())
    {
        SetCurrentAllyPartyID("");
    }
    else if(sPartyID == GetCurrentEnemyPartyID())
    {
        SetCurrentEnemyPartyID("");
    }

    // Check party
    return !DoesPartyExistByID(sPartyID);
}

Bool CharacterPartyManager::UnloadAllParties()
{
    // Unload parties
    GetParties().clear();
    SetCurrentAllyPartyID("");
    SetCurrentEnemyPartyID("");
    return GetParties().empty();
}

Bool CharacterPartyManager::SetAsCurrentParty(const String& sPartyID, const String& sPartyType)
{
    const CharacterPartyType ePartyType = GetEnumFromString<CharacterPartyType>(sPartyType);
    switch(ePartyType)
    {
        case CharacterPartyType::Ally:
            SetCurrentAllyPartyID(sPartyID);
            return true;
            break;
        case CharacterPartyType::Enemy:
            SetCurrentEnemyPartyID(sPartyID);
            return true;
            break;
        default:
            break;
    }
    return false;
}

Bool CharacterPartyManager::DoesPartyExistByID(const String& sPartyID) const
{
    // Check party ID
    if(!IsValidPartyID(sPartyID))
    {
        return false;
    }

    // Check if party exists
    auto iSearch = GetParties().find(sPartyID);
    return (iSearch != GetParties().end());
}

Bool CharacterPartyManager::DoesPartyExistByType(const String& sPartyType) const
{
    // Check party type
    if(!IsValidEnumString<CharacterPartyType>(sPartyType))
    {
        return false;
    }

    // Check if party exists
    for(auto it = GetParties().begin(); it != GetParties().end(); it++)
    {
        if(sPartyType == it->second.GetPartyType())
        {
            return true;
        }
    }
    return false;
}

Bool CharacterPartyManager::IsValidPartyID(const String& sPartyID) const
{
    // Check party ID validity
    return (!sPartyID.empty());
}

const CharacterParty& CharacterPartyManager::GetPartyByID(const String& sPartyID) const
{
    // Check if party exists
    if(!DoesPartyExistByID(sPartyID))
    {
        THROW_RUNTIME_ERROR("Party '" + sPartyID + "' was not registered");
    }

    // Get party
    auto iSearch = GetParties().find(sPartyID);
    if(iSearch != GetParties().end())
    {
        return iSearch->second;
    }
    THROW_RUNTIME_ERROR("Invalid or unknown party ID requested: " + sPartyID);
}

CharacterParty& CharacterPartyManager::GetPartyByID(const String& sPartyID)
{
    // Get party
    return const_cast<CharacterParty&>(static_cast<const CharacterPartyManager&>(*this).GetPartyByID(sPartyID));
}

const CharacterParty& CharacterPartyManager::GetPartyByType(const String& sPartyType) const
{
    // Get party
    const CharacterPartyType ePartyType = GetEnumFromString<CharacterPartyType>(sPartyType);
    switch(ePartyType)
    {
        case CharacterPartyType::Ally:
            return GetCurrentAllyParty();
        case CharacterPartyType::Enemy:
            return GetCurrentEnemyParty();
        default:
            break;
    }
    THROW_RUNTIME_ERROR("Invalid or unknown party type requested: " + sPartyType);
}

CharacterParty& CharacterPartyManager::GetPartyByType(const String& sPartyType)
{
    // Get party
    return const_cast<CharacterParty&>(static_cast<const CharacterPartyManager&>(*this).GetPartyByType(sPartyType));
}

const CharacterParty& CharacterPartyManager::GetCurrentAllyParty() const
{
    // Check current ally party
    if(GetCurrentAllyPartyID() == "")
    {
        THROW_RUNTIME_ERROR("No current ally party set");
    }

    // Get current ally party
    return GetPartyByID(GetCurrentAllyPartyID());
}

CharacterParty& CharacterPartyManager::GetCurrentAllyParty()
{
    // Get current ally party
    return const_cast<CharacterParty&>(static_cast<const CharacterPartyManager&>(*this).GetCurrentAllyParty());
}

const CharacterParty& CharacterPartyManager::GetCurrentEnemyParty() const
{
    // Check current enemy party
    if(GetCurrentEnemyPartyID() == "")
    {
        THROW_RUNTIME_ERROR("No current enemy party set");
    }

    // Get current enemy party
    return GetPartyByID(GetCurrentEnemyPartyID());
}

CharacterParty& CharacterPartyManager::GetCurrentEnemyParty()
{
    // Get current enemy party
    return const_cast<CharacterParty&>(static_cast<const CharacterPartyManager&>(*this).GetCurrentEnemyParty());
}

StringArray CharacterPartyManager::GetAllPartyIDs() const
{
    StringArray vAllParties;
    for(auto it = GetParties().begin(); it != GetParties().end(); it++)
    {
        vAllParties.push_back(it->first);
    }
    return vAllParties;
}

};
