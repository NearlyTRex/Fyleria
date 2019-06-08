// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_SAVE_MANAGER_H_
#define _GECKO_SAVE_MANAGER_H_

#include "Saves/Save.h"
#include "Module/ModuleResultManager.h"
#include "Utility/Singleton.h"

namespace Gecko
{

class SaveManager : public Singleton<SaveManager>
{
public:

    // Types
    typedef STDUnorderedMap<UByte, Save> SaveMappingType;

    // Constructors
    SaveManager();

    // Load save
    void LoadSave(UByte uSlot, const Save& save);

    // Create save
    void CreateSave(UByte uSlot);

    // Unload save
    void UnloadSave(UByte uSlot);

    // Unload all saves
    void UnloadAllSaves();

    // Does save exist
    Bool DoesSaveExist(UByte uSlot) const;
    MAKE_MODULE_RESULT_VARIANT_A1(DoesSaveExist, UByte, uSlot);

    // Get save capacity
    UByte GetSaveCapacity() const;
    MAKE_MODULE_RESULT_VARIANT(GetSaveCapacity);

    // Get list of all available save slots
    UByteArray GetAllAvailableSaveSlots() const;
    MAKE_MODULE_RESULT_VARIANT(GetAllAvailableSaveSlots);

    // Get list of all descriptions from save slots
    // Unused slots are also included
    StringArray GetAllSaveDescriptions() const;
    MAKE_MODULE_RESULT_VARIANT(GetAllSaveDescriptions);

    // Is save capacity reached
    Bool IsSaveCapacityReached() const;
    MAKE_MODULE_RESULT_VARIANT(IsSaveCapacityReached);

    // Get save
    const Save& GetSave(UByte uSlot) const;
    Save& GetSave(UByte uSlot);
    MAKE_MODULE_RESULT_VARIANT_A1(GetSave, UByte, uSlot);

    // Get all saves
    SaveArray GetAllSaves() const;
    MAKE_MODULE_RESULT_VARIANT(GetAllSaves);

    // Collect data and create a save
    void CollectSaveData(UByte uSlot, const String& sPartyID);
    void CollectSaveData(UByte uSlot, const StringArray& vPartyIDs, const String& sDescription, ULong uPlayTime);

    // Disperse save data
    void DisperseSaveData(UByte uSlot);

    // Save to file
    void SaveToFile(UByte uSlot, const String& sFile, const String& sType);

    // Load to file
    void LoadFromFile(UByte uSlot, const String& sFile, const String& sType);

    // Save all to the given directory
    void SaveAllToDirectory(const String& sDirectory, const String& sBase, const String& sExt, const String& sType);

    // Load all from the given directory
    void LoadAllFromDirectory(const String& sDirectory, const String& sBase, const String& sExt, const String& sType);

    // Initialize all save slots
    void InitializeAllSaveSlots();

    // Initialize empty save slots
    void InitializeEmptySaveSlots();

    // Saves
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(Saves, SaveMappingType);
};

};

#endif
