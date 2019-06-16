// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Saves/SaveManager.h"
#include "Saves/SaveTypes.h"
#include "Utility/Constants.h"

namespace Gecko
{

SaveManager::SaveManager()
    : Singleton<SaveManager>()
{
}

void SaveManager::LoadSave(const String& sSlot, const Save& save)
{
    // Load a save
    GetSaves().insert({sSlot, save});
    GetSaves().at(sSlot).SetSlot(sSlot);
}

void SaveManager::CreateSave(const String& sSlot)
{
    // Create a new save
    ASSERT_ERROR(!DoesSaveExist(sSlot), "Save slot '%s' was already registered", sSlot.c_str());
    Save newSave;
    newSave.SetSlot(sSlot);
    GetSaves().insert({sSlot, newSave});
}

void SaveManager::UnloadSave(const String& sSlot)
{
    // Unload save
    ASSERT_ERROR(DoesSaveExist(sSlot), "Save slot '%s' was not registered", sSlot.c_str());
    GetSaves().erase(sSlot);
}

void SaveManager::UnloadAllSaves()
{
    // Unload all saves
    GetSaves().clear();
}

Bool SaveManager::DoesSaveExist(const String& sSlot) const
{
    // Check if save exists
    auto iSearch = GetSaves().find(sSlot);
    return (iSearch != GetSaves().end());
}

UByte SaveManager::GetSaveCapacity() const
{
    // Get max number of save slots
    return MAX_SAVE_SLOT;
}

StringArray SaveManager::GetAllAvailableSaveSlots() const
{
    // Get a list of all slots that are not used
    StringArray vSlots;
    for(auto& sSlotName : GetEnumNames<SaveSlotType>())
    {
        if(!DoesSaveExist(sSlotName))
        {
            vSlots.push_back(sSlotName);
        }
    }
    return vSlots;
}

StringArray SaveManager::GetAllSaveDescriptions() const
{
    // Get all save descriptions
    StringArray vDescriptions;
    for(auto& sSlotName : GetEnumNames<SaveSlotType>())
    {
        vDescriptions.push_back(DoesSaveExist(sSlotName) ? GetSave(sSlotName).GetDescription() : "");
    }
    return vDescriptions;
}

Bool SaveManager::IsSaveCapacityReached() const
{
    // Get whether save capacity is reached
    StringArray vAvailableSlots = GetAllAvailableSaveSlots();
    return vAvailableSlots.empty();
}

const Save& SaveManager::GetSave(const String& sSlot) const
{
    // Get save
    ASSERT_ERROR(DoesSaveExist(sSlot), "Save slot '%s' was not registered", sSlot.c_str());
    auto iSearch = GetSaves().find(sSlot);
    return iSearch->second;
}

Save& SaveManager::GetSave(const String& sSlot)
{
    // Get save
    return const_cast<Save&>(static_cast<const SaveManager&>(*this).GetSave(sSlot));
}

SaveArray SaveManager::GetAllSaves() const
{
    SaveArray vSaves;
    for(auto it = GetSaves().begin(); it != GetSaves().end(); it++)
    {
        vSaves.push_back(it->second);
    }
    return vSaves;
}

void SaveManager::CollectSaveData(const String& sSlot, const String& sPartyID)
{
    const CharacterParty& party = CharacterPartyManager::GetInstance()->GetPartyByID(sPartyID);
    CollectSaveData(sSlot, {sPartyID}, party.GetDescription(), party.GetPlayTime());
}

void SaveManager::CollectSaveData(const String& sSlot, const StringArray& vPartyIDs, const String& sDescription, ULong uPlayTime)
{
    // Get parties and attached characters
    CharacterPartyArray vParties;
    CharacterArray vCharacters;
    for (auto& sPartyID : vPartyIDs)
    {
        // Add party
        CharacterParty& party = CharacterPartyManager::GetInstance()->GetPartyByID(sPartyID);
        party.RegenerateCharacterData();
        vParties.push_back(party);

        // Add members of this party
        for(auto& member : party.GetMembers())
        {
            vCharacters.push_back(CharacterManager::GetInstance()->GetCharacter(member.first));
        }
    }

    // Create save from this
    Save newSave;
    newSave.SetSlot(sSlot);
    newSave.SetTime(uPlayTime);
    newSave.SetParties(vParties);
    newSave.SetCharacters(vCharacters);
    newSave.SetDescription(sDescription);

    // Load save into manager, potentially overwriting an existing save
    LoadSave(sSlot, newSave);
}

void SaveManager::DisperseSaveData(const String& sSlot)
{
    // Get save from slot
    const Save& save = GetSave(sSlot);

    // Load characters
    for(const Character& character : save.GetCharacters())
    {
        CharacterManager::GetInstance()->LoadCharacter(character);
    }

    // Load parties
    for(const CharacterParty& party : save.GetParties())
    {
        CharacterPartyManager::GetInstance()->LoadParty(party);
    }
}

void SaveManager::SaveToFile(const String& sSlot, const String& sFile, const String& sType)
{
    // Save to file based on the file type
    Bool bSuccess = false;
    const FileType eFileType = GetEnumFromString<FileType>(sType);
    switch(eFileType)
    {
        case FileType::TextJson:
            bSuccess = GetSave(sSlot).ToFile(sFile);
            ASSERT_ERROR(bSuccess, "Saving to Json file '%s' failed", sFile.c_str());
            break;
        case FileType::BinaryCBOR:
            bSuccess = GetSave(sSlot).ToCBORFile(sFile);
            ASSERT_ERROR(bSuccess, "Saving to CBOR file '%s' failed", sFile.c_str());
            break;
        case FileType::BinaryMsgPack:
            bSuccess = GetSave(sSlot).ToMsgPackFile(sFile);
            ASSERT_ERROR(bSuccess, "Saving to MsgPack file '%s' failed", sFile.c_str());
            break;
        default:
            break;
    }
}

void SaveManager::LoadFromFile(const String& sSlot, const String& sFile, const String& sType)
{
    // Load from file based on the file type
    Bool bSuccess = false;
    const FileType eFileType = GetEnumFromString<FileType>(sType);
    switch(eFileType)
    {
        case FileType::TextJson:
            bSuccess = GetSave(sSlot).FromFile(sFile);
            ASSERT_ERROR(bSuccess, "Loading from Json file '%s' failed", sFile.c_str());
            break;
        case FileType::BinaryCBOR:
            bSuccess = GetSave(sSlot).FromCBORFile(sFile);
            ASSERT_ERROR(bSuccess, "Loading from CBOR file '%s' failed", sFile.c_str());
            break;
        case FileType::BinaryMsgPack:
            bSuccess = GetSave(sSlot).FromMsgPackFile(sFile);
            ASSERT_ERROR(bSuccess, "Loading from MsgPack file '%s' failed", sFile.c_str());
            break;
        default:
            break;
    }
}

void SaveManager::SaveAllToDirectory(const String& sDirectory, const String& sBase, const String& sExt, const String& sType)
{
    // Create directory if it does not yet exist
    String sSavePath = GetAbsolutePath(sDirectory);
    if(!DoesPathExist(sSavePath))
    {
        CreateDirectory(sSavePath);
    }

    // Save each slot into a save file
    for(auto& sSlotName : GetEnumNames<SaveSlotType>())
    {
        if(IsNoneTypeForEnum<SaveSlotType>(sSlotName))
        {
            continue;
        }
        String sPath = JoinPaths(sDirectory, sBase + sSlotName + String(".") + sExt);
        SaveToFile(sSlotName, String(sPath), sType);
    }
}

void SaveManager::LoadAllFromDirectory(const String& sDirectory, const String& sBase, const String& sExt, const String& sType)
{
    // Get save path
    String sSavePath = GetCanonicalPath(sDirectory);

    // Load each slot from a save file
    for(auto& sSlotName : GetEnumNames<SaveSlotType>())
    {
        if(IsNoneTypeForEnum<SaveSlotType>(sSlotName))
        {
            continue;
        }
        String sPath = JoinPaths(sSavePath, sBase + sSlotName + String(".") + sExt);
        if(DoesPathExist(sPath))
        {
            LoadFromFile(sSlotName, String(sPath), sType);
        }
    }
}

void SaveManager::InitializeAllSaveSlots()
{
    // Unload all saves first
    UnloadAllSaves();

    // Create a save for all slots
    for(auto& sSlotName : GetEnumNames<SaveSlotType>())
    {
        if(IsNoneTypeForEnum<SaveSlotType>(sSlotName))
        {
            continue;
        }
        CreateSave(sSlotName);
    }
}

void SaveManager::InitializeEmptySaveSlots()
{
    // Create a save for empty slots
    for(auto& sSlotName : GetEnumNames<SaveSlotType>())
    {
        if(IsNoneTypeForEnum<SaveSlotType>(sSlotName))
        {
            continue;
        }
        if (!DoesSaveExist(sSlotName))
        {
            CreateSave(sSlotName);
        }
    }
}

};
