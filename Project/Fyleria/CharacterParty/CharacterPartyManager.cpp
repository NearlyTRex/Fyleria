// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "CharacterParty/CharacterPartyManager.h"
#include "Character/CharacterTypes.h"
#include "Utility/Errors.h"
#include "Utility/Constants.h"

namespace Gecko
{

CharacterPartyManager::CharacterPartyManager()
    : Singleton<CharacterPartyManager>()
{
}

void CharacterPartyManager::LoadParty(const CharacterParty& party)
{
    // Load a party
    const String& sPartyID = party.GetPartyID();
    const String& sPartyType = party.GetPartyType();
    ASSERT_ERROR(IsValidPartyID(sPartyID), "Party ID '%s' was not valid", sPartyID.c_str());
    ASSERT_ERROR(IsValidEnumString<CharacterPartyType>(sPartyType), "Party type '%s' was not valid", sPartyType.c_str());
    GetParties().insert({sPartyID, party});
}

void CharacterPartyManager::LoadPartyFromFile(const String& sFilename, const String& sType)
{
    // Load a party
    Json jsonData;
    Bool bSuccess = ReadSerializedFile(sFilename, sType, jsonData);
    ASSERT_ERROR(bSuccess, "Unable to read file '%s' as type '%s'", sFilename.c_str(), sType.c_str());
    LoadParty(jsonData.get<CharacterParty>());
}

void CharacterPartyManager::SavePartyToFile(const String& sPartyID, const String& sFilename, const String& sType)
{
    // Save a party
    Json jsonData = GetPartyByID(sPartyID);
    Bool bSuccess = WriteSerializedFile(sFilename, sType, jsonData);
    ASSERT_ERROR(bSuccess, "Unable to write file '%s' as type '%s'", sFilename.c_str(), sType.c_str());
}

void CharacterPartyManager::CreateParty(const String& sPartyID, const String& sPartyType, Bool bSetAsCurrent /*= false*/)
{
    // Create a new party
    ASSERT_ERROR(!DoesPartyExistByID(sPartyID), "Party '%s' was already registered", sPartyID.c_str());
    ASSERT_ERROR(IsValidEnumString<CharacterPartyType>(sPartyType), "Party type '%s' was not valid", sPartyType.c_str());
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
        const CharacterPartyType ePartyType = GetEnumFromString<CharacterPartyType>(sPartyType);
        switch(ePartyType)
        {
            case CharacterPartyType::Ally:
                SetCurrentAllyPartyID(sPartyID);
                break;
            case CharacterPartyType::Enemy:
                SetCurrentEnemyPartyID(sPartyID);
                break;
            default:
                break;
        }
    }
}

void CharacterPartyManager::UnloadParty(const String& sPartyID)
{
    // Unload party
    ASSERT_ERROR(DoesPartyExistByID(sPartyID), "Party '%s' was not registered", sPartyID.c_str());
    GetParties().erase(sPartyID);
    if(sPartyID == GetCurrentAllyPartyID())
    {
        SetCurrentAllyPartyID("");
    }
    else if(sPartyID == GetCurrentEnemyPartyID())
    {
        SetCurrentEnemyPartyID("");
    }
}

Bool CharacterPartyManager::DoesPartyExistByID(const String& sPartyID) const
{
    // Check if party exists
    auto iSearch = GetParties().find(sPartyID);
    return (iSearch != GetParties().end());
}

Bool CharacterPartyManager::DoesPartyExistByType(const String& sPartyType) const
{
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
    // Get party
    ASSERT_ERROR(DoesPartyExistByID(sPartyID), "Party '%s' was not registered", sPartyID.c_str());
    auto iSearch = GetParties().find(sPartyID);
    if(iSearch != GetParties().end())
    {
        return iSearch->second;
    }
    throw RuntimeError("Invalid or unknown party ID requested: " + sPartyID);
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
    throw RuntimeError("Invalid or unknown party type requested: " + sPartyType);
}

CharacterParty& CharacterPartyManager::GetPartyByType(const String& sPartyType)
{
    // Get party
    return const_cast<CharacterParty&>(static_cast<const CharacterPartyManager&>(*this).GetPartyByType(sPartyType));
}

const CharacterParty& CharacterPartyManager::GetCurrentAllyParty() const
{
    return GetPartyByID(GetCurrentAllyPartyID());
}

CharacterParty& CharacterPartyManager::GetCurrentAllyParty()
{
    return GetPartyByID(GetCurrentAllyPartyID());
}

const CharacterParty& CharacterPartyManager::GetCurrentEnemyParty() const
{
    return GetPartyByID(GetCurrentEnemyPartyID());
}

CharacterParty& CharacterPartyManager::GetCurrentEnemyParty()
{
    return GetPartyByID(GetCurrentEnemyPartyID());
}

};
