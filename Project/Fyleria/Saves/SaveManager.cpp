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

void SaveManager::LoadSave(UByte uSlot, const Save& save)
{
    // Load a save
    GetSaves().insert({uSlot, save});
    GetSaves().at(uSlot).SetSlot(uSlot);
}

void SaveManager::CreateSave(UByte uSlot)
{
    // Create a new save
    ASSERT_ERROR(!DoesSaveExist(uSlot), "Save slot '%u' was already registered", uSlot);
    Save newSave;
    newSave.SetSlot(uSlot);
    GetSaves().insert({uSlot, newSave});
}

void SaveManager::UnloadSave(UByte uSlot)
{
    // Unload save
    ASSERT_ERROR(DoesSaveExist(uSlot), "Save slot '%u' was not registered", uSlot);
    GetSaves().erase(uSlot);
}

void SaveManager::UnloadAllSaves()
{
    // Unload all saves
    GetSaves().clear();
}

Bool SaveManager::DoesSaveExist(UByte uSlot) const
{
    // Check if save exists
    auto iSearch = GetSaves().find(uSlot);
    return (iSearch != GetSaves().end());
}

UByte SaveManager::GetSaveCapacity() const
{
    // Get max number of save slots
    return MAX_SAVE_SLOT;
}

UByteArray SaveManager::GetAllAvailableSaveSlots() const
{
    // Get a list of all slots that are not used
    UByteArray vSlots;
    for(Int i = 0; i < GetSaveCapacity(); i++)
    {
        if(!DoesSaveExist(i))
        {
            vSlots.push_back(i);
        }
    }
    return vSlots;
}

StringArray SaveManager::GetAllSaveDescriptions() const
{
    // Get all save descriptions
    StringArray vDescriptions;
    for(Int i = 0; i < GetSaveCapacity(); i++)
    {
        vDescriptions.push_back(DoesSaveExist(i) ? GetSave(i).GetDescription() : "");
    }
    return vDescriptions;
}

Bool SaveManager::IsSaveCapacityReached() const
{
    // Get whether save capacity is reached
    STDVector<UByte> vAvailableSlots = GetAllAvailableSaveSlots();
    return vAvailableSlots.empty();
}

const Save& SaveManager::GetSave(UByte uSlot) const
{
    // Get save
    ASSERT_ERROR(DoesSaveExist(uSlot), "Save slot '%u' was not registered", uSlot);
    auto iSearch = GetSaves().find(uSlot);
    return iSearch->second;
}

Save& SaveManager::GetSave(UByte uSlot)
{
    // Get save
    return const_cast<Save&>(static_cast<const SaveManager&>(*this).GetSave(uSlot));
}

SaveArray SaveManager::GetAllSaves() const
{
    SaveArray vSaves;
    for(Int i = 0; i < GetSaveCapacity(); i++)
    {
        vSaves.push_back(GetSave(i));
    }
    return vSaves;
}

void SaveManager::CollectSaveData(UByte uSlot, const String& sPartyID)
{
    const CharacterParty& party = CharacterPartyManager::GetInstance()->GetPartyByID(sPartyID);
    CollectSaveData(uSlot, {sPartyID}, party.GetDescription(), party.GetPlayTime());
}

void SaveManager::CollectSaveData(UByte uSlot, const StringArray& vPartyIDs, const String& sDescription, ULong uPlayTime)
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
    newSave.SetSlot(uSlot);
    newSave.SetTime(uPlayTime);
    newSave.SetParties(vParties);
    newSave.SetCharacters(vCharacters);
    newSave.SetDescription(sDescription);

    // Load save into manager, potentially overwriting an existing save
    LoadSave(uSlot, newSave);
}

void SaveManager::DisperseSaveData(UByte uSlot)
{
    // Get save from slot
    const Save& save = GetSave(uSlot);

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

void SaveManager::SaveToFile(UByte uSlot, const String& sFile, const String& sType)
{
    // Save to file based on the file type
    Bool bSuccess = false;
    const FileType eFileType = GetEnumFromString<FileType>(sType);
    switch(eFileType)
    {
        case FileType::TextJson:
            bSuccess = GetSave(uSlot).ToFile(sFile);
            ASSERT_ERROR(bSuccess, "Saving to Json file '%s' failed", sFile.c_str());
            break;
        case FileType::BinaryCBOR:
            bSuccess = GetSave(uSlot).ToCBORFile(sFile);
            ASSERT_ERROR(bSuccess, "Saving to CBOR file '%s' failed", sFile.c_str());
            break;
        case FileType::BinaryMsgPack:
            bSuccess = GetSave(uSlot).ToMsgPackFile(sFile);
            ASSERT_ERROR(bSuccess, "Saving to MsgPack file '%s' failed", sFile.c_str());
            break;
        default:
            break;
    }
}

void SaveManager::LoadFromFile(UByte uSlot, const String& sFile, const String& sType)
{
    // Load from file based on the file type
    Bool bSuccess = false;
    const FileType eFileType = GetEnumFromString<FileType>(sType);
    switch(eFileType)
    {
        case FileType::TextJson:
            bSuccess = GetSave(uSlot).FromFile(sFile);
            ASSERT_ERROR(bSuccess, "Loading from Json file '%s' failed", sFile.c_str());
            break;
        case FileType::BinaryCBOR:
            bSuccess = GetSave(uSlot).FromCBORFile(sFile);
            ASSERT_ERROR(bSuccess, "Loading from CBOR file '%s' failed", sFile.c_str());
            break;
        case FileType::BinaryMsgPack:
            bSuccess = GetSave(uSlot).FromMsgPackFile(sFile);
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
        SaveSlotType eSlotType = GetEnumFromString<SaveSlotType>(sSlotName);
        String sPath = JoinPaths(sDirectory, sBase + sSlotName + String(".") + sExt);
        SaveToFile(eSlotType._to_integral(), String(sPath), sType);
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
        SaveSlotType eSlotType = GetEnumFromString<SaveSlotType>(sSlotName);
        String sPath = JoinPaths(sSavePath, sBase + sSlotName + String(".") + sExt);
        if(DoesPathExist(sPath))
        {
            LoadFromFile(eSlotType._to_integral(), String(sPath), sType);
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
        SaveSlotType eSlotType = GetEnumFromString<SaveSlotType>(sSlotName);
        CreateSave(eSlotType._to_integral());
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
        SaveSlotType eSlotType = GetEnumFromString<SaveSlotType>(sSlotName);
        if (!DoesSaveExist(eSlotType._to_integral()))
        {
            CreateSave(eSlotType._to_integral());
        }
    }
}

};
