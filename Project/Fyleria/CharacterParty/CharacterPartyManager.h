// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_CHARACTER_PARTY_MANAGER_H_
#define _GECKO_CHARACTER_PARTY_MANAGER_H_

#include "CharacterParty/CharacterParty.h"
#include "Utility/Singleton.h"

namespace Gecko
{

class CharacterPartyManager : public Singleton<CharacterPartyManager>
{
public:

    // Types
    typedef STDUnorderedMap<IndexedString, CharacterParty, IndexedStringHasher> CharacterPartyMappingType;

    // Constructors
    CharacterPartyManager();

    // Load a party
    // This will overwrite any existing matching data
    void LoadParty(const CharacterParty& party);

    // Load a party from a file
    // This will overwrite any existing matching data
    void LoadPartyFromFile(const IndexedString& sFilename, const IndexedString& sType);

    // Save a party to file
    void SavePartyToFile(const IndexedString& sPartyID, const IndexedString& sFilename, const IndexedString& sType);

    // Create a party
    void CreateParty(const IndexedString& sPartyID, const IndexedString& sPartyType, Bool bSetAsCurrent = false);

    // Unload party
    void UnloadParty(const IndexedString& sPartyID);

    // Determine if party exists
    Bool DoesPartyExist(const IndexedString& sPartyID) const;

    // Check if party ID is valid
    Bool IsValidPartyID(const IndexedString& sPartyID) const;

    // Get party
    const CharacterParty& GetPartyByID(const IndexedString& sPartyID) const;
    CharacterParty& GetPartyByID(const IndexedString& sPartyID);
    const CharacterParty& GetPartyByType(const IndexedString& sPartyType) const;
    CharacterParty& GetPartyByType(const IndexedString& sPartyType);
    const CharacterParty& GetCurrentAllyParty() const;
    CharacterParty& GetCurrentAllyParty();
    const CharacterParty& GetCurrentEnemyParty() const;
    CharacterParty& GetCurrentEnemyParty();

    // Parties
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(Parties, CharacterPartyMappingType);

    // Current ally/enemy party
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(CurrentAllyPartyID, IndexedString);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(CurrentEnemyPartyID, IndexedString);

private:

    // Empty party
    static CharacterParty s_EmptyCharacterParty;
};

};

#endif
