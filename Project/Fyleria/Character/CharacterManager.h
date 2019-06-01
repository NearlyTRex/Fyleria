// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_CHARACTER_MANAGER_H_
#define _GECKO_CHARACTER_MANAGER_H_

#include "Character/Character.h"
#include "Character/CharacterGenerator.h"
#include "Module/ModuleResultManager.h"

namespace Gecko
{

class CharacterManager : public Singleton<CharacterManager>
{
public:

    // Types
    typedef STDUnorderedMap<IndexedString, Character, IndexedStringHasher> CharacterMappingType;

    // Constructors
    CharacterManager();

    // Load a character
    // This will overwrite any existing matching data
    void LoadCharacter(const Character& character);

    // Load a character from a file
    // This will overwrite any existing matching data
    void LoadCharacterFromFile(const IndexedString& sFilename, const IndexedString& sType);

    // Save a character to file
    void SaveCharacterToFile(const IndexedString& sCharacterID, const IndexedString& sFilename, const IndexedString& sType);

    // Create a character
    void CreateCharacter(const IndexedString& sCharacterID);

    // Unload a character
    void UnloadCharacter(const IndexedString& sCharacterID);

    // Does a character exist
    Bool DoesCharacterExist(const IndexedString& sCharacterID) const;
    MAKE_MODULE_RESULT_VARIANT_A1(DoesCharacterExist, const IndexedString&, sCharacterID);

    // Generate a character
    void GenerateCharacter(const IndexedString& sCharacterID, const CharacterGenerator& generator);

    // Check if character ID is valid
    Bool IsValidCharacterID(const IndexedString& sCharacterID) const;
    MAKE_MODULE_RESULT_VARIANT_A1(IsValidCharacterID, const IndexedString&, sCharacterID);

    // Get character
    const Character& GetCharacter(const IndexedString& sCharacterID) const;
    Character& GetCharacter(const IndexedString& sCharacterID);
    MAKE_MODULE_RESULT_VARIANT_A1(GetCharacter, const IndexedString&, sCharacterID);

    // Apply a stat change
    void ApplyStatChange(
        const IndexedString& sSegment,
        const StatChange& change,
        Bool& bAllChangesApplied,
        Bool& bAtLeastOneChange,
        Bool bApplyAllEntries = false);

    // Apply a stat change entry
    Bool ApplyStatChangeEntry(const IndexedString& sSegment, const StatChangeEntry& entry);

    // Apply a stat change entry bool operation
    Bool ApplyStatChangeEntryOperation(
        const IndexedString& sSegment,
        const IndexedString& sCharacterID,
        const IndexedString& sOperation,
        const IndexedString& sStat,
        Bool bValue);

    // Apply a stat change entry int operation
    Bool ApplyStatChangeEntryOperation(
        const IndexedString& sSegment,
        const IndexedString& sCharacterID,
        const IndexedString& sOperation,
        const IndexedString& sStat,
        Int iValue);

    // Apply a stat change entry float operation
    Bool ApplyStatChangeEntryOperation(
        const IndexedString& sSegment,
        const IndexedString& sCharacterID,
        const IndexedString& sOperation,
        const IndexedString& sStat,
        Float fValue);

    // Apply a stat change entry string operation
    Bool ApplyStatChangeEntryOperation(
        const IndexedString& sSegment,
        const IndexedString& sCharacterID,
        const IndexedString& sOperation,
        const IndexedString& sStat,
        const IndexedString& sValue);

    // Apply a stat change entry string array operation
    Bool ApplyStatChangeEntryOperation(
        const IndexedString& sSegment,
        const IndexedString& sCharacterID,
        const IndexedString& sOperation,
        const IndexedString& sStat,
        const IndexedStringArray& sValue);

    // Determine if stat change entry uses a delta from source to destination characters
    Bool DoesStatChangeEntryUseDelta(const StatChangeEntry& changeEntry) const;

    // Get delta changed values from stat change entry
    Bool GetDeltaStatChangeEntryValues(
        const IndexedString& sSegment,
        const IndexedString& sCharacterID,
        const StatChangeEntry& changeEntry,
        BoolArray& vBoolValues,
        IntArray& vIntValues,
        FloatArray& vFloatValues,
        IndexedStringArray& vStringValues) const;

    // Get fully changed values from stat change entry
    Bool GetFullStatChangeEntryValues(
        const IndexedString& sSegment,
        const IndexedString& sCharacterID,
        const StatChangeEntry& changeEntry,
        BoolArray& vBoolValues,
        IntArray& vIntValues,
        FloatArray& vFloatValues,
        IndexedStringArray& vStringValues) const;

    // Characters
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(Characters, CharacterMappingType);
};

};

#endif
