// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_CHARACTER_PARTY_MANAGER_H_
#define _GECKO_CHARACTER_PARTY_MANAGER_H_

#include "CharacterParty/CharacterParty.h"
#include "Module/ModuleResultManager.h"

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
    MAKE_MODULE_RESULT_VARIANT_A1(DoesPartyExist, const IndexedString&, sPartyID);

    // Check if party ID is valid
    Bool IsValidPartyID(const IndexedString& sPartyID) const;
    MAKE_MODULE_RESULT_VARIANT_A1(IsValidPartyID, const IndexedString&, sPartyID);

    // Get party by ID
    const CharacterParty& GetPartyByID(const IndexedString& sPartyID) const;
    CharacterParty& GetPartyByID(const IndexedString& sPartyID);
    MAKE_MODULE_RESULT_VARIANT_A1(GetPartyByID, const IndexedString&, sPartyID);

    // Get party by type
    const CharacterParty& GetPartyByType(const IndexedString& sPartyType) const;
    CharacterParty& GetPartyByType(const IndexedString& sPartyType);
    MAKE_MODULE_RESULT_VARIANT_A1(GetPartyByType, const IndexedString&, sPartyType);

    // Get current ally party
    const CharacterParty& GetCurrentAllyParty() const;
    CharacterParty& GetCurrentAllyParty();
    MAKE_MODULE_RESULT_VARIANT(GetCurrentAllyParty);

    // Get current enemy party
    const CharacterParty& GetCurrentEnemyParty() const;
    CharacterParty& GetCurrentEnemyParty();
    MAKE_MODULE_RESULT_VARIANT(GetCurrentEnemyParty);

    // Parties
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(Parties, CharacterPartyMappingType);

    // Current ally/enemy party
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(CurrentAllyPartyID, IndexedString);
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(CurrentEnemyPartyID, IndexedString);
};

};

#endif
