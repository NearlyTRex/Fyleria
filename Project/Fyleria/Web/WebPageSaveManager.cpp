// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Web/WebPageSaveManager.h"
#include "Saves/SaveManager.h"
#include "Saves/SaveTypes.h"
#include "Utility/Enum.h"
#include "Utility/Constants.h"

namespace Gecko
{

WebPageSaveManager::WebPageSaveManager()
    : WebPage()
{
    SetPageTemplate(R"TEMPLATE(
<!DOCTYPE html>
<html lang="en-GB">
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <title>Save Manager</title>
    <link href="/lib/bootstrap/css/bootstrap.min.css" rel="stylesheet" type="text/css">
    <script type="text/javascript" src="/lib/jquery/jquery.min.js"></script>
    <script type="text/javascript" src="/lib/bootstrap/js/bootstrap.min.js"></script>
</head>
<div class="container">
    <form action="%submit_url%" method="post">
        <div class="form-group row">
            <div class="col"><hr></div>
            <div class="col-auto">Controls</div>
            <div class="col"><hr></div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Initialize Empty Save Slots</label>
            <div class="col-sm-8">
                <button type="submit" class="btn btn-primary form-control" name="action" value="initalizeEmptySaveSlots_submit">Initialize Save Slots</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Initialize All Save Slots</label>
            <div class="col-sm-8">
                <button type="submit" class="btn btn-primary form-control" name="action" value="initalizeAllSaveSlots_submit">Initialize Save Slots</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-4 col-form-label">Collect Save Data</label>
            <div class="col-sm-2">
                <select class="form-control" name="collectSaveData_saveSlotType">
                    <option value="" disabled="disabled">Save Slot Type...</option>
                    %optionList_saveSlotType%
                </select>
            </div>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="collectSaveData_partyID" placeholder="Party Identifier" value="%collectSaveData_partyID%"/>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="collectSaveData_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-4 col-form-label">Disperse Save Data</label>
            <div class="col-sm-2">
                <select class="form-control" name="disperseSaveData_saveSlotType">
                    <option value="" disabled="disabled">Save Slot Type...</option>
                    %optionList_saveSlotType%
                </select>
            </div>
            <div class="col-sm-4">
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="disperseSaveData_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Load Save</label>
            <div class="col-sm-2">
                <select class="form-control" name="loadSave_saveSlotType">
                    <option value="" disabled="disabled">Save Slot Type...</option>
                    %optionList_saveSlotType%
                </select>
            </div>
            <div class="col-sm-6">
                <textarea style="resize: none;" class="form-control" rows="3" name="loadSave_textarea" placeholder="Raw save json">%loadSave_textarea%</textarea>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="loadSave_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Unload Save</label>
            <div class="col-sm-2">
                <select class="form-control" name="unloadSave_saveSlotType">
                    <option value="" disabled="disabled">Save Slot Type...</option>
                    %optionList_saveSlotType%
                </select>
            </div>
            <div class="col-sm-6">
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="unloadSave_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Load From File</label>
            <div class="col-sm-2">
                <select class="form-control" name="loadFromFile_saveSlotType">
                    <option value="" disabled="disabled">Save Slot Type...</option>
                    %optionList_saveSlotType%
                </select>
            </div>
            <div class="col-sm-2">
                <select class="form-control" name="loadFromFile_fileType">
                    <option value="" disabled="disabled">File Type...</option>
                    %optionList_fileType%
                </select>
            </div>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="loadFromFile_filename" placeholder="Filename" value="%loadFromFile_filename%"/>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="loadFromFile_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Save To File</label>
            <div class="col-sm-2">
                <select class="form-control" name="saveToFile_saveSlotType">
                    <option value="" disabled="disabled">Save Slot Type...</option>
                    %optionList_saveSlotType%
                </select>
            </div>
            <div class="col-sm-2">
                <select class="form-control" name="saveToFile_fileType">
                    <option value="" disabled="disabled">File Type...</option>
                    %optionList_fileType%
                </select>
            </div>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="saveToFile_filename" placeholder="Filename" value="%saveToFile_filename%"/>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="saveToFile_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Save All To Dir</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="saveAllToDir_directory" placeholder="Directory" value="%saveAllToDir_directory%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="saveAllToDir_basename" placeholder="Basename" value="%saveAllToDir_basename%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="saveAllToDir_extension" placeholder="Extension" value="%saveAllToDir_extension%"/>
            </div>
            <div class="col-sm-2">
                <select class="form-control" name="saveAllToDir_fileType">
                    <option value="" disabled="disabled">File Type...</option>
                    %optionList_fileType%
                </select>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="saveAllToDir_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Load All From Dir</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="loadAllFromDir_directory" placeholder="Directory" value="%loadAllFromDir_directory%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="loadAllFromDir_basename" placeholder="Basename" value="%loadAllFromDir_basename%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="loadAllFromDir_extension" placeholder="Extension" value="%loadAllFromDir_extension%"/>
            </div>
            <div class="col-sm-2">
                <select class="form-control" name="loadAllFromDir_fileType">
                    <option value="" disabled="disabled">File Type...</option>
                    %optionList_fileType%
                </select>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="loadAllFromDir_submit">Run</button>
            </div>
        </div>
    </form>
</div>
</html>
)TEMPLATE");
}

WebPageSaveManager::~WebPageSaveManager()
{
}

void WebPageSaveManager::UpdatePageContent(const ParameterMapType& tParams)
{
    // Build option lists
    MAKE_HTML_OPTION_LIST_STRING(SaveSlotType);
    MAKE_HTML_OPTION_LIST_STRING(FileType);

    // Get fields
    String sAction = GET_MAP_DATA_OR_DEFAULT(tParams, "action", "");
    String sCollectSaveData_SaveSlotType = GET_MAP_DATA_OR_DEFAULT(tParams, "collectSaveData_saveSlotType", "");
    String sCollectSaveData_PartyID = GET_MAP_DATA_OR_DEFAULT(tParams, "collectSaveData_partyID", "");
    String sDisperseSaveData_SaveSlotType = GET_MAP_DATA_OR_DEFAULT(tParams, "disperseSaveData_saveSlotType", "");
    String sLoadSave_SaveSlotType = GET_MAP_DATA_OR_DEFAULT(tParams, "loadSave_saveSlotType", "");
    String sLoadSave_Textarea = GET_MAP_DATA_OR_DEFAULT(tParams, "loadSave_textarea", "");
    String sUnloadSave_SaveSlotType = GET_MAP_DATA_OR_DEFAULT(tParams, "unloadSave_saveSlotType", "");
    String sLoadFromFile_SaveSlotType = GET_MAP_DATA_OR_DEFAULT(tParams, "loadFromFile_saveSlotType", "");
    String sLoadFromFile_FileType = GET_MAP_DATA_OR_DEFAULT(tParams, "loadFromFile_fileType", "");
    String sLoadFromFile_Filename = GET_MAP_DATA_OR_DEFAULT(tParams, "loadFromFile_filename", "");
    String sSaveToFile_SaveSlotType = GET_MAP_DATA_OR_DEFAULT(tParams, "saveToFile_saveSlotType", "");
    String sSaveToFile_FileType = GET_MAP_DATA_OR_DEFAULT(tParams, "saveToFile_fileType", "");
    String sSaveToFile_Filename = GET_MAP_DATA_OR_DEFAULT(tParams, "saveToFile_filename", "");
    String sLoadAllFromDir_Directory = GET_MAP_DATA_OR_DEFAULT(tParams, "loadAllFromDir_directory", "");
    String sLoadAllFromDir_Basename = GET_MAP_DATA_OR_DEFAULT(tParams, "loadAllFromDir_basename", "");
    String sLoadAllFromDir_Extension = GET_MAP_DATA_OR_DEFAULT(tParams, "loadAllFromDir_extension", "");
    String sLoadAllFromDir_FileType = GET_MAP_DATA_OR_DEFAULT(tParams, "loadAllFromDir_fileType", "");
    String sSaveAllToDir_Directory = GET_MAP_DATA_OR_DEFAULT(tParams, "saveAllToDir_directory", "");
    String sSaveAllToDir_Basename = GET_MAP_DATA_OR_DEFAULT(tParams, "saveAllToDir_basename", "");
    String sSaveAllToDir_Extension = GET_MAP_DATA_OR_DEFAULT(tParams, "saveAllToDir_extension", "");
    String sSaveAllToDir_FileType = GET_MAP_DATA_OR_DEFAULT(tParams, "saveAllToDir_fileType", "");

    // Check action
    if(sAction == "initalizeEmptySaveSlots_submit")
    {
        SaveManager::GetInstance()->InitializeEmptySaveSlots();
    }
    else if(sAction == "initalizeAllSaveSlots_submit")
    {
        SaveManager::GetInstance()->InitializeAllSaveSlots();
    }
    else if(sAction == "collectSaveData_submit")
    {
        SaveManager::GetInstance()->CollectSaveData(
            StringToSaveSlotType(sCollectSaveData_SaveSlotType)._to_integral(),
            sCollectSaveData_PartyID
        );
    }
    else if(sAction == "disperseSaveData_submit")
    {
        SaveManager::GetInstance()->DisperseSaveData(
            StringToSaveSlotType(sDisperseSaveData_SaveSlotType)._to_integral()
        );
    }
    else if(sAction == "loadSave_submit")
    {
        SaveManager::GetInstance()->LoadSave(
            StringToSaveSlotType(sLoadSave_SaveSlotType)._to_integral(),
            Save(sLoadSave_Textarea)
        );
    }
    else if(sAction == "unloadSave_submit")
    {
        SaveManager::GetInstance()->UnloadSave(
            StringToSaveSlotType(sUnloadSave_SaveSlotType)._to_integral()
        );
    }
    else if(sAction == "loadFromFile_submit")
    {
        SaveManager::GetInstance()->LoadFromFile(
            StringToSaveSlotType(sLoadFromFile_SaveSlotType)._to_integral(),
            sLoadFromFile_Filename,
            sLoadFromFile_FileType
        );
    }
    else if(sAction == "saveToFile_submit")
    {
        SaveManager::GetInstance()->SaveToFile(
            StringToSaveSlotType(sSaveToFile_SaveSlotType)._to_integral(),
            sSaveToFile_Filename,
            sSaveToFile_FileType
        );
    }
    else if(sAction == "loadAllFromDir_submit")
    {
        SaveManager::GetInstance()->LoadAllFromDirectory(
            sLoadAllFromDir_Directory,
            sLoadAllFromDir_Basename,
            sLoadAllFromDir_Extension,
            sLoadAllFromDir_FileType
        );
    }
    else if(sAction == "saveAllToDir_submit")
    {
        SaveManager::GetInstance()->SaveAllToDirectory(
            sSaveAllToDir_Directory,
            sSaveAllToDir_Basename,
            sSaveAllToDir_Extension,
            sSaveAllToDir_FileType
        );
    }

    // Set page content
    String sPage = GetPageTemplate();
    BoostReplaceAll(sPage, "%submit_url%", WEB_PAGE_TOOL_SAVE_MANAGER);
    BoostReplaceAll(sPage, "%optionList_saveSlotType%", sOptionList_SaveSlotType);
    BoostReplaceAll(sPage, "%optionList_fileType%", sOptionList_FileType);
    BoostReplaceAll(sPage, "%collectSaveData_partyID%", sCollectSaveData_PartyID);
    BoostReplaceAll(sPage, "%loadSave_textarea%", sLoadSave_Textarea);
    BoostReplaceAll(sPage, "%loadFromFile_filename%", sLoadFromFile_Filename);
    BoostReplaceAll(sPage, "%saveToFile_filename%", sSaveToFile_Filename);
    BoostReplaceAll(sPage, "%saveAllToDir_directory%", sSaveAllToDir_Directory);
    BoostReplaceAll(sPage, "%saveAllToDir_basename%", sSaveAllToDir_Basename);
    BoostReplaceAll(sPage, "%saveAllToDir_extension%", sSaveAllToDir_Extension);
    BoostReplaceAll(sPage, "%loadAllFromDir_directory%", sLoadAllFromDir_Directory);
    BoostReplaceAll(sPage, "%loadAllFromDir_basename%", sLoadAllFromDir_Basename);
    BoostReplaceAll(sPage, "%loadAllFromDir_extension%", sLoadAllFromDir_Extension);
    SetPageContent(sPage);
}

};
