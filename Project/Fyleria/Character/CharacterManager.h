// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_CHARACTER_CHARACTER_MANAGER_H_
#define _GECKO_CHARACTER_CHARACTER_MANAGER_H_

// Internal includes
#include "Character/Character.h"
#include "Character/CharacterGenerator.h"
#include "Stat/StatChange.h"

namespace Gecko
{

// Character manager
class CharacterManager
{
public:

    // Types
    typedef STDUnorderedMap<String, Character> CharacterMappingType;

    // Constructors
    CharacterManager();

    // Load a character
    // This will overwrite any existing matching data
    Bool LoadCharacter(const Character& character, Bool bRegenerateData);

    // Load a character from a file
    // This will overwrite any existing matching data
    Bool LoadCharacterFromFile(const String& sFilename, const String& sType, Bool bRegenerateData);

    // Save a character to file
    Bool SaveCharacterToFile(const String& sCharacterID, const String& sFilename, const String& sType);

    // Create a character
    Bool CreateCharacter(const String& sCharacterID);

    // Unload a character
    Bool UnloadCharacter(const String& sCharacterID);

    // Unload all characters
    Bool UnloadAllCharacters();

    // Does a character exist
    Bool DoesCharacterExist(const String& sCharacterID) const;

    // Generate a character
    Bool GenerateCharacter(const String& sCharacterID, const CharacterGenerator& generator, Bool bRegenerateData);

    // Check if character ID is valid
    Bool IsValidCharacterID(const String& sCharacterID) const;

    // Get character
    const Character& GetCharacter(const String& sCharacterID) const;
    Character& GetCharacter(const String& sCharacterID);

    // Get all character IDs
    StringArray GetAllCharacterIDs() const;

    // Apply a stat change
    Bool ApplyStatChange(
        const String& sSegment,
        const StatChange& change,
        Bool& bAllChangesApplied,
        Bool& bAtLeastOneChange,
        Bool bApplyAllEntries = false);

    // Apply a stat change entry
    template <class T>
    Bool ApplyStatChangeEntry(
        const String& sSegment,
        const StatChangeEntry& entry)
    {
        T varSourceValue = 0;
        if(!GetStatChangeEntrySourceValue(sSegment, entry.GetSourceCharacterID(), entry, varSourceValue))
        {
            return false;
        }
        Bool bAtLeastOneChange = false;
        for(const String& sDestCharID : entry.GetDestinationCharacterIDs())
        {
            Bool bResult = ApplyStatChangeEntryDestValue(sSegment, sDestCharID, entry, varSourceValue);
            bAtLeastOneChange = bAtLeastOneChange || bResult;
        }
        return bAtLeastOneChange;
    }

    // Get stat change entry source value
    template <class T>
    Bool GetStatChangeEntrySourceValue(
        const String& sSegment,
        const String& sCharacterID,
        const StatChangeEntry& entry,
        T& varValue) const
    {
        T varStatValue = 0;
        Bool bSuccess = false;
        const Character& character = GetCharacter(sCharacterID);
        if(character.GetStatValue(sSegment, entry.GetSourceStatType(), varStatValue))
        {
            T varNewValue = 0;
            const StatOperationType eOperationType = GetEnumFromString<StatOperationType>(entry.GetOperationType());
            switch(eOperationType)
            {
                case StatOperationType::Add:
                    varNewValue = varStatValue + entry.GetChangeAmount();
                    break;
                case StatOperationType::Subtract:
                    varNewValue = varStatValue - entry.GetChangeAmount();
                    break;
                case StatOperationType::Multiply:
                    varNewValue = varStatValue * entry.GetChangeAmount();
                    break;
                case StatOperationType::Divide:
                    if(entry.GetChangeAmount() != 0)
                    {
                        varNewValue = varStatValue / entry.GetChangeAmount();
                    }
                    break;
                case StatOperationType::Modulus:
                    if(entry.GetChangeAmount() != 0)
                    {
                        varNewValue = static_cast<Int>(varStatValue) % static_cast<Int>(entry.GetChangeAmount());
                    }
                    break;
                default:
                    break;
            };
            varValue = varNewValue;
            bSuccess = true;
        }
        return bSuccess;
    }

    // Apply a stat change entry dest value
    template <class T>
    Bool ApplyStatChangeEntryDestValue(
        const String& sSegment,
        const String& sCharacterID,
        const StatChangeEntry& entry,
        T varValue)
    {
        Character& character = GetCharacter(sCharacterID);
        const StatAssignmentType eAssigmentType = GetEnumFromString<StatAssignmentType>(entry.GetAssignmentType());
        switch(eAssigmentType)
        {
            case StatAssignmentType::Set:
                return character.SetStatValue(sSegment, entry.GetDestinationStatType(), varValue);
            case StatAssignmentType::Increment:
                return character.IncrementStatValue(sSegment, entry.GetDestinationStatType(), varValue);
            case StatAssignmentType::Decrement:
                return character.DecrementStatValue(sSegment, entry.GetDestinationStatType(), varValue);
            default:
                break;
        }
        return false;
    }

    // Characters
    MAKE_RAW_TYPE_ACCESSORS(Characters, CharacterMappingType);
};

};

#endif
