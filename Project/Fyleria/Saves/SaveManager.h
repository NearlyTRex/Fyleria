// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_SAVE_MANAGER_H_
#define _GECKO_SAVE_MANAGER_H_

// Internal includes
#include "Saves/Save.h"

namespace Gecko
{

// Manager set
class ManagerSet;

// Save manager
class SaveManager
{
public:

    // Types
    typedef STDUnorderedMap<String, Save> SaveMappingType;

    // Constructors
    SaveManager();

    // Load save
    void LoadSave(const Save& save);

    // Create save
    void CreateSave(const String& sSlot);

    // Unload save
    void UnloadSave(const String& sSlot);

    // Unload all saves
    void UnloadAllSaves();

    // Does save exist
    Bool DoesSaveExist(const String& sSlot) const;

    // Get save capacity
    UByte GetSaveCapacity() const;

    // Get list of all available save slots
    StringArray GetAllAvailableSaveSlots() const;

    // Get list of all descriptions from save slots
    // Unused slots are also included
    StringArray GetAllSaveDescriptions() const;

    // Is save capacity reached
    Bool IsSaveCapacityReached() const;

    // Check if save slot is valid
    Bool IsValidSaveSlot(const String& sSlot) const;

    // Get save
    const Save& GetSave(const String& sSlot) const;
    Save& GetSave(const String& sSlot);

    // Get all saves
    SaveArray GetAllSaves() const;

    // Collect data and create a save
    void CollectSaveData(
        SafeObject<ManagerSet>& pManagerSet,
        const String& sSlot,
        const String& sPartyID);
    void CollectSaveData(
        SafeObject<ManagerSet>& pManagerSet,
        const String& sSlot,
        const StringArray& vPartyIDs,
        const String& sDescription,
        ULongLong uPlayTime);

    // Disperse save data
    void DisperseSaveData(SafeObject<ManagerSet>& pManagerSet, const String& sSlot);

    // Save to file
    void SaveToFile(
        SafeObject<ManagerSet>& pManagerSet,
        const String& sSlot,
        const String& sFile,
        const String& sType);

    // Load to file
    void LoadFromFile(
        SafeObject<ManagerSet>& pManagerSet,
        const String& sSlot,
        const String& sFile,
        const String& sType);

    // Save all to the given directory
    void SaveAllToDirectory(
        SafeObject<ManagerSet>& pManagerSet,
        const String& sDirectory,
        const String& sBase,
        const String& sExt,
        const String& sType);

    // Load all from the given directory
    void LoadAllFromDirectory(
        SafeObject<ManagerSet>& pManagerSet,
        const String& sDirectory,
        const String& sBase,
        const String& sExt,
        const String& sType);

    // Initialize all save slots
    void InitializeAllSaveSlots();

    // Initialize empty save slots
    void InitializeEmptySaveSlots();

    // Saves
    MAKE_RAW_TYPE_ACCESSORS(Saves, SaveMappingType);
};

};

#endif
