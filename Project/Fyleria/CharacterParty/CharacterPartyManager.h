// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_CHARACTER_CHARACTER_PARTY_MANAGER_H_
#define _GECKO_CHARACTER_CHARACTER_PARTY_MANAGER_H_

// Internal includes
#include "CharacterParty/CharacterParty.h"

namespace Gecko
{

// Character party manager
class CharacterPartyManager
{
public:

    // Types
    typedef STDUnorderedMap<String, CharacterParty> CharacterPartyMappingType;

    // Constructors
    CharacterPartyManager();

    // Load a party
    // This will overwrite any existing matching data
    Bool LoadParty(const CharacterParty& party, Bool bRegenerateData = false, Bool bSetAsCurrent = false);

    // Load a party from a file
    // This will overwrite any existing matching data
    Bool LoadPartyFromFile(const String& sFilename, const String& sType, Bool bRegenerateData = false, Bool bSetAsCurrent = false);

    // Save a party to file
    Bool SavePartyToFile(const String& sPartyID, const String& sFilename, const String& sType);

    // Create a party
    Bool CreateParty(const String& sPartyID, const String& sPartyType, Bool bSetAsCurrent = false);

    // Unload party
    Bool UnloadParty(const String& sPartyID);

    // Unload all parties
    Bool UnloadAllParties();

    // Set as current party
    Bool SetAsCurrentParty(const String& sPartyID, const String& sPartyType);

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
