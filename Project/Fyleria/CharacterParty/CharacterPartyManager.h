// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_CHARACTER_PARTY_MANAGER_H_
#define _GECKO_CHARACTER_PARTY_MANAGER_H_

// Internal includes
#include "CharacterParty/CharacterParty.h"

namespace Gecko
{

class CharacterPartyManager : public Singleton<CharacterPartyManager>
{
public:

    // Types
    typedef STDUnorderedMap<String, CharacterParty> CharacterPartyMappingType;

    // Constructors
    CharacterPartyManager();

    // Load a party and return the party ID
    // This will overwrite any existing matching data
    String LoadParty(const CharacterParty& party, Bool bRegenerateData);

    // Load a party from a file and return the party ID
    // This will overwrite any existing matching data
    String LoadPartyFromFile(const String& sFilename, const String& sType, Bool bRegenerateData);

    // Save a party to file
    void SavePartyToFile(const String& sPartyID, const String& sFilename, const String& sType);

    // Create a party
    void CreateParty(const String& sPartyID, const String& sPartyType, Bool bSetAsCurrent = false);

    // Unload party
    void UnloadParty(const String& sPartyID);

    // Determine if party exists
    Bool DoesPartyExistByID(const String& sPartyID) const;
    Bool DoesPartyExistByType(const String& sPartyType) const;

    // Check if party ID is valid
    Bool IsValidPartyID(const String& sPartyID) const;

    // Get party by ID
    const CharacterParty& GetPartyByID(const String& sPartyID) const;
    CharacterParty& GetPartyByID(const String& sPartyID);

    // Get party by type
    const CharacterParty& GetPartyByType(const String& sPartyType) const;
    CharacterParty& GetPartyByType(const String& sPartyType);

    // Get current ally party
    const CharacterParty& GetCurrentAllyParty() const;
    CharacterParty& GetCurrentAllyParty();

    // Get current enemy party
    const CharacterParty& GetCurrentEnemyParty() const;
    CharacterParty& GetCurrentEnemyParty();

    // Get all party IDs
    StringArray GetAllPartyIDs() const;

    // Parties
    MAKE_RAW_TYPE_ACCESSORS(Parties, CharacterPartyMappingType);

    // Current ally/enemy party
    MAKE_RAW_TYPE_ACCESSORS(CurrentAllyPartyID, String);
    MAKE_RAW_TYPE_ACCESSORS(CurrentEnemyPartyID, String);
};

};

#endif
