// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Web/WebPageSaveManager.h"
#include "Saves/SaveManager.h"
#include "Saves/SaveTypes.h"
#include "Utility/Enum.h"
#include "Utility/Constants.h"
#include "Utility/Templates.h"

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
    <form action="%sSubmit_Url%" method="post">
        <div class="form-group row">
            <div class="col"><hr></div>
            <div class="col-auto">Controls</div>
            <div class="col"><hr></div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Initialize Empty Save Slots</label>
            <div class="col-sm-8">
                <button type="submit" class="btn btn-primary form-control" name="action" value="initalize_empty_save_slots">Initialize Save Slots</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Initialize All Save Slots</label>
            <div class="col-sm-8">
                <button type="submit" class="btn btn-primary form-control" name="action" value="initalize_all_save_slots">Initialize Save Slots</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-4 col-form-label">Collect Save Data</label>
            <div class="col-sm-2">
                <select class="form-control" name="sCollectSaveData_SaveSlotType">
                    <option value="" disabled="disabled">Save Slot Type...</option>
                    %sOptionList_SaveSlotType%
                </select>
            </div>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="sCollectSaveData_PartyID" placeholder="Party Identifier" value="%sCollectSaveData_PartyID%"/>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="collect_save_data">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-4 col-form-label">Disperse Save Data</label>
            <div class="col-sm-2">
                <select class="form-control" name="sDisperseSaveData_SaveSlotType">
                    <option value="" disabled="disabled">Save Slot Type...</option>
                    %sOptionList_SaveSlotType%
                </select>
            </div>
            <div class="col-sm-4">
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="disperse_save_data">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Load Save</label>
            <div class="col-sm-2">
                <select class="form-control" name="sLoadSave_SaveSlotType">
                    <option value="" disabled="disabled">Save Slot Type...</option>
                    %sOptionList_SaveSlotType%
                </select>
            </div>
            <div class="col-sm-6">
                <textarea style="resize: none;" class="form-control" rows="3" name="sLoadSave_Textarea" placeholder="Raw save json">%sLoadSave_Textarea%</textarea>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="load_save">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Unload Save</label>
            <div class="col-sm-2">
                <select class="form-control" name="sUnloadSave_SaveSlotType">
                    <option value="" disabled="disabled">Save Slot Type...</option>
                    %sOptionList_SaveSlotType%
                </select>
            </div>
            <div class="col-sm-6">
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="unload_save">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Load From File</label>
            <div class="col-sm-2">
                <select class="form-control" name="sLoadFromFile_SaveSlotType">
                    <option value="" disabled="disabled">Save Slot Type...</option>
                    %sOptionList_SaveSlotType%
                </select>
            </div>
            <div class="col-sm-2">
                <select class="form-control" name="sLoadFromFile_FileType">
                    <option value="" disabled="disabled">File Type...</option>
                    %sOptionList_FileType%
                </select>
            </div>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="sLoadFromFile_Filename" placeholder="Filename" value="%sLoadFromFile_Filename%"/>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="load_from_file">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Save To File</label>
            <div class="col-sm-2">
                <select class="form-control" name="sSaveToFile_SaveSlotType">
                    <option value="" disabled="disabled">Save Slot Type...</option>
                    %sOptionList_SaveSlotType%
                </select>
            </div>
            <div class="col-sm-2">
                <select class="form-control" name="sSaveToFile_FileType">
                    <option value="" disabled="disabled">File Type...</option>
                    %sOptionList_FileType%
                </select>
            </div>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="sSaveToFile_Filename" placeholder="Filename" value="%sSaveToFile_Filename%"/>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="save_to_file">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Save All To Dir</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sSaveAllToDir_Directory" placeholder="Directory" value="%sSaveAllToDir_Directory%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sSaveAllToDir_Basename" placeholder="Basename" value="%sSaveAllToDir_Basename%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sSaveAllToDir_Extension" placeholder="Extension" value="%sSaveAllToDir_Extension%"/>
            </div>
            <div class="col-sm-2">
                <select class="form-control" name="sSaveAllToDir_FileType">
                    <option value="" disabled="disabled">File Type...</option>
                    %sOptionList_FileType%
                </select>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="save_all_to_dir">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Load All From Dir</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sLoadAllFromDir_Directory" placeholder="Directory" value="%sLoadAllFromDir_Directory%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sLoadAllFromDir_Basename" placeholder="Basename" value="%sLoadAllFromDir_Basename%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sLoadAllFromDir_Extension" placeholder="Extension" value="%sLoadAllFromDir_Extension%"/>
            </div>
            <div class="col-sm-2">
                <select class="form-control" name="sLoadAllFromDir_FileType">
                    <option value="" disabled="disabled">File Type...</option>
                    %sOptionList_FileType%
                </select>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="load_all_from_dir">Run</button>
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
    String sAction = GetMapDataOrDefault(tParams, "action", "");
    String sCollectSaveData_SaveSlotType = GetMapDataOrDefault(tParams, "sCollectSaveData_SaveSlotType", "");
    String sCollectSaveData_PartyID = GetMapDataOrDefault(tParams, "sCollectSaveData_PartyID", "");
    String sDisperseSaveData_SaveSlotType = GetMapDataOrDefault(tParams, "sDisperseSaveData_SaveSlotType", "");
    String sLoadSave_SaveSlotType = GetMapDataOrDefault(tParams, "sLoadSave_SaveSlotType", "");
    String sLoadSave_Textarea = GetMapDataOrDefault(tParams, "sLoadSave_Textarea", "");
    String sUnloadSave_SaveSlotType = GetMapDataOrDefault(tParams, "sUnloadSave_SaveSlotType", "");
    String sLoadFromFile_SaveSlotType = GetMapDataOrDefault(tParams, "sLoadFromFile_SaveSlotType", "");
    String sLoadFromFile_FileType = GetMapDataOrDefault(tParams, "sLoadFromFile_FileType", "");
    String sLoadFromFile_Filename = GetMapDataOrDefault(tParams, "sLoadFromFile_Filename", "");
    String sSaveToFile_SaveSlotType = GetMapDataOrDefault(tParams, "sSaveToFile_SaveSlotType", "");
    String sSaveToFile_FileType = GetMapDataOrDefault(tParams, "sSaveToFile_FileType", "");
    String sSaveToFile_Filename = GetMapDataOrDefault(tParams, "sSaveToFile_Filename", "");
    String sLoadAllFromDir_Directory = GetMapDataOrDefault(tParams, "sLoadAllFromDir_Directory", "");
    String sLoadAllFromDir_Basename = GetMapDataOrDefault(tParams, "sLoadAllFromDir_Basename", "");
    String sLoadAllFromDir_Extension = GetMapDataOrDefault(tParams, "sLoadAllFromDir_Extension", "");
    String sLoadAllFromDir_FileType = GetMapDataOrDefault(tParams, "sLoadAllFromDir_FileType", "");
    String sSaveAllToDir_Directory = GetMapDataOrDefault(tParams, "sSaveAllToDir_Directory", "");
    String sSaveAllToDir_Basename = GetMapDataOrDefault(tParams, "sSaveAllToDir_Basename", "");
    String sSaveAllToDir_Extension = GetMapDataOrDefault(tParams, "sSaveAllToDir_Extension", "");
    String sSaveAllToDir_FileType = GetMapDataOrDefault(tParams, "sSaveAllToDir_FileType", "");

    // Check action
    if(sAction == "initalize_empty_save_slots")
    {
        SaveManager::GetInstance()->InitializeEmptySaveSlots();
    }
    else if(sAction == "initalize_all_save_slots")
    {
        SaveManager::GetInstance()->InitializeAllSaveSlots();
    }
    else if(sAction == "collect_save_data")
    {
        SaveManager::GetInstance()->CollectSaveData(
            StringToSaveSlotType(sCollectSaveData_SaveSlotType)._to_integral(),
            sCollectSaveData_PartyID
        );
    }
    else if(sAction == "disperse_save_data")
    {
        SaveManager::GetInstance()->DisperseSaveData(
            StringToSaveSlotType(sDisperseSaveData_SaveSlotType)._to_integral()
        );
    }
    else if(sAction == "load_save")
    {
        SaveManager::GetInstance()->LoadSave(
            StringToSaveSlotType(sLoadSave_SaveSlotType)._to_integral(),
            Save(sLoadSave_Textarea)
        );
    }
    else if(sAction == "unload_save")
    {
        SaveManager::GetInstance()->UnloadSave(
            StringToSaveSlotType(sUnloadSave_SaveSlotType)._to_integral()
        );
    }
    else if(sAction == "load_from_file")
    {
        SaveManager::GetInstance()->LoadFromFile(
            StringToSaveSlotType(sLoadFromFile_SaveSlotType)._to_integral(),
            sLoadFromFile_Filename,
            sLoadFromFile_FileType
        );
    }
    else if(sAction == "save_to_file")
    {
        SaveManager::GetInstance()->SaveToFile(
            StringToSaveSlotType(sSaveToFile_SaveSlotType)._to_integral(),
            sSaveToFile_Filename,
            sSaveToFile_FileType
        );
    }
    else if(sAction == "load_all_from_dir")
    {
        SaveManager::GetInstance()->LoadAllFromDirectory(
            sLoadAllFromDir_Directory,
            sLoadAllFromDir_Basename,
            sLoadAllFromDir_Extension,
            sLoadAllFromDir_FileType
        );
    }
    else if(sAction == "save_all_to_dir")
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
    BoostReplaceAll(sPage, "%sSubmit_Url%", WEB_PAGE_TOOL_SAVE_MANAGER);
    BoostReplaceAll(sPage, "%sOptionList_SaveSlotType%", sOptionList_SaveSlotType);
    BoostReplaceAll(sPage, "%sOptionList_FileType%", sOptionList_FileType);
    BoostReplaceAll(sPage, "%sCollectSaveData_PartyID%", sCollectSaveData_PartyID);
    BoostReplaceAll(sPage, "%sLoadSave_Textarea%", sLoadSave_Textarea);
    BoostReplaceAll(sPage, "%sLoadFromFile_Filename%", sLoadFromFile_Filename);
    BoostReplaceAll(sPage, "%sSaveToFile_Filename%", sSaveToFile_Filename);
    BoostReplaceAll(sPage, "%sSaveAllToDir_Directory%", sSaveAllToDir_Directory);
    BoostReplaceAll(sPage, "%sSaveAllToDir_Basename%", sSaveAllToDir_Basename);
    BoostReplaceAll(sPage, "%sSaveAllToDir_Extension%", sSaveAllToDir_Extension);
    BoostReplaceAll(sPage, "%sLoadAllFromDir_Directory%", sLoadAllFromDir_Directory);
    BoostReplaceAll(sPage, "%sLoadAllFromDir_Basename%", sLoadAllFromDir_Basename);
    BoostReplaceAll(sPage, "%sLoadAllFromDir_Extension%", sLoadAllFromDir_Extension);
    SetPageContent(sPage);
}

};
