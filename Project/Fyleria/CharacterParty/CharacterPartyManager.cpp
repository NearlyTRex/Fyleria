// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

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
    const IndexedString& sPartyID = party.GetPartyID();
    const IndexedString& sPartyType = party.GetPartyType();
    ASSERT_ERROR(IsValidPartyID(sPartyID), "Party ID '%s' was not valid", sPartyID.c_str());
    ASSERT_ERROR(IsValidCharacterPartyType(sPartyType), "Party type '%s' was not valid", sPartyType.c_str());
    GetParties().insert({sPartyID, party});
}

void CharacterPartyManager::LoadPartyFromFile(const IndexedString& sFilename, const IndexedString& sType)
{
    // Load a party
    Json jsonData;
    Bool bSuccess = ReadSerializedFile(sFilename, sType, jsonData);
    ASSERT_ERROR(bSuccess, "Unable to read file '%s' as type '%s'", sFilename.c_str(), sType.c_str());
    LoadParty(jsonData.get<CharacterParty>());
}

void CharacterPartyManager::SavePartyToFile(const IndexedString& sPartyID, const IndexedString& sFilename, const IndexedString& sType)
{
    // Save a party
    Json jsonData = GetPartyByID(sPartyID);
    Bool bSuccess = WriteSerializedFile(sFilename, sType, jsonData);
    ASSERT_ERROR(bSuccess, "Unable to write file '%s' as type '%s'", sFilename.c_str(), sType.c_str());
}

void CharacterPartyManager::CreateParty(const IndexedString& sPartyID, const IndexedString& sPartyType, Bool bSetAsCurrent /*= false*/)
{
    // Create a new party
    ASSERT_ERROR(!DoesPartyExist(sPartyID), "Party '%s' was already registered", sPartyID.c_str());
    ASSERT_ERROR(IsValidCharacterPartyType(sPartyType), "Party type '%s' was not valid", sPartyType.c_str());
    IndexedStringArray vAvailableTargetTypes;
    for(UInt i = 1; i <= MAX_TEAM_CHARACTER_AMOUNT; i++)
    {
        vAvailableTargetTypes.push_back(sPartyType + IndexedString(STDToString(i)));
    }
    CharacterParty newParty;
    newParty.SetPartyID(sPartyID);
    newParty.SetPartyType(sPartyType);
    newParty.SetAvailableTargetTypes(vAvailableTargetTypes);
    GetParties().insert({sPartyID, newParty});

    // Set as current ally/enemy
    if(bSetAsCurrent)
    {
        const CharacterPartyType ePartyType = StringToCharacterPartyType(sPartyType);
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

void CharacterPartyManager::UnloadParty(const IndexedString& sPartyID)
{
    // Unload party
    ASSERT_ERROR(DoesPartyExist(sPartyID), "Party '%s' was not registered", sPartyID.c_str());
    GetParties().erase(sPartyID);
}

Bool CharacterPartyManager::DoesPartyExist(const IndexedString& sPartyID) const
{
    // Check if party exists
    auto iSearch = GetParties().find(sPartyID);
    return (iSearch != GetParties().end());
}

Bool CharacterPartyManager::IsValidPartyID(const IndexedString& sPartyID) const
{
    // Check party ID validity
    return (!sPartyID.empty() && !sPartyID.IsNone());
}

const CharacterParty& CharacterPartyManager::GetPartyByID(const IndexedString& sPartyID) const
{
    // Get party
    ASSERT_ERROR(DoesPartyExist(sPartyID), "Party '%s' was not registered", sPartyID.c_str());
    auto iSearch = GetParties().find(sPartyID);
    if(iSearch != GetParties().end())
    {
        return iSearch->second;
    }
    throw RuntimeError("Invalid or unknown party ID requested: " + sPartyID.Get());
}

CharacterParty& CharacterPartyManager::GetPartyByID(const IndexedString& sPartyID)
{
    // Get party
    return const_cast<CharacterParty&>(static_cast<const CharacterPartyManager&>(*this).GetPartyByID(sPartyID));
}

const CharacterParty& CharacterPartyManager::GetPartyByType(const IndexedString& sPartyType) const
{
    // Get party
    const CharacterPartyType ePartyType = StringToCharacterPartyType(sPartyType);
    switch(ePartyType)
    {
        case CharacterPartyType::Ally:
            return GetCurrentAllyParty();
        case CharacterPartyType::Enemy:
            return GetCurrentEnemyParty();
        default:
            break;
    }
    throw RuntimeError("Invalid or unknown party type requested: " + sPartyType.Get());
}

CharacterParty& CharacterPartyManager::GetPartyByType(const IndexedString& sPartyType)
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
