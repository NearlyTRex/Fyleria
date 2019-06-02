// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Web/WebPageSaveManager.h"
#include "Utility/Constants.h"

namespace Gecko
{

WebPageSaveManager::WebPageSaveManager()
    : WebPage()
{
    SetPageTemplate(R"TEMPLATE(
<html>
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
            <label class="col-sm-2 col-form-label">Initialize Save Slots</label>
            <div class="col-sm-8">
                <button type="submit" class="btn btn-primary form-control" name="action" value="initalizeSaveSlots_submit">Initialize Save Slots</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Pull Save</label>
            <div class="col-sm-2">
                <select class="form-control" name="pullSave_saveSlot">
                    <option value="">Save Slot...</option>
                    %optionList_saveSlot%
                </select>
            </div>
            <div class="col-sm-6">
                <input type="text" class="form-control" name="pullSave_partyID" placeholder="Party Identifier" value="%pullSave_partyID%"></input>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="pullSave_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Push Save</label>
            <div class="col-sm-2">
                <select class="form-control" name="pushSave_saveSlot">
                    <option value="">Save Slot...</option>
                    %optionList_saveSlot%
                </select>
            </div>
            <div class="col-sm-6">
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="pushSave_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Load Save</label>
            <div class="col-sm-2">
                <select class="form-control" name="loadSave_saveSlot">
                    <option value="">Save Slot...</option>
                    %optionList_saveSlot%
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
                <select class="form-control" name="unloadSave_saveSlot">
                    <option value="">Save Slot...</option>
                    %optionList_saveSlot%
                </select>
            </div>
            <div class="col-sm-6">
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="unloadSave_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Delete Save</label>
            <div class="col-sm-2">
                <select class="form-control" name="deleteSave_saveSlot">
                    <option value="">Save Slot...</option>
                    %optionList_saveSlot%
                </select>
            </div>
            <div class="col-sm-6">
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="deleteSave_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Load From File</label>
            <div class="col-sm-2">
                <select class="form-control" name="loadFromFile_saveSlot">
                    <option value="">Save Slot...</option>
                    %optionList_saveSlot%
                </select>
            </div>
            <div class="col-sm-2">
                <select class="form-control" name="loadFromFile_saveType">
                    <option value="">Save Type...</option>
                    %optionList_saveType%
                </select>
            </div>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="loadFromFile_filename" placeholder="Filename" value="%loadFromFile_filename%"></input>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="loadFromFile_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Save To File</label>
            <div class="col-sm-2">
                <select class="form-control" name="saveToFile_saveSlot">
                    <option value="">Save Slot...</option>
                    %optionList_saveSlot%
                </select>
            </div>
            <div class="col-sm-2">
                <select class="form-control" name="saveToFile_saveType">
                    <option value="">Save Type...</option>
                    %optionList_saveType%
                </select>
            </div>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="saveToFile_filename" placeholder="Filename" value="%saveToFile_filename%"></input>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="saveToFile_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Save All To Dir</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="saveAllToDir_directory" placeholder="Directory" value="%saveAllToDir_directory%"></input>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="saveAllToDir_basename" placeholder="Basename" value="%saveAllToDir_basename%"></input>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="saveAllToDir_extension" placeholder="Extension" value="%saveAllToDir_extension%"></input>
            </div>
            <div class="col-sm-2">
                <select class="form-control" name="saveAllToDir_saveType">
                    <option value="">Save Type...</option>
                    %optionList_saveType%
                </select>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="saveAllToDir_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Load All From Dir</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="loadAllFromDir_directory" placeholder="Directory" value="%loadAllFromDir_directory%"></input>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="loadAllFromDir_basename" placeholder="Basename" value="%loadAllFromDir_basename%"></input>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="loadAllFromDir_extension" placeholder="Extension" value="%loadAllFromDir_extension%"></input>
            </div>
            <div class="col-sm-2">
                <select class="form-control" name="loadAllFromDir_saveType">
                    <option value="">Save Type...</option>
                    %optionList_saveType%
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
    // Replacement tokens
    String sSubmitUrl = WEB_PAGE_TOOL_SAVE_MANAGER;
    String sOptionList_SaveSlot;
    String sOptionList_SaveType;
    String sPullSave_PartyID;
    String sLoadSave_Textarea;
    String sLoadFromFile_Filename;
    String sSaveToFile_Filename;
    String sSaveAllToDir_Directory;
    String sSaveAllToDir_Basename;
    String sSaveAllToDir_Extension;
    String sLoadAllFromDir_Directory;
    String sLoadAllFromDir_Basename;
    String sLoadAllFromDir_Extension;

    // Set page content
    String sPage = GetPageTemplate();
    BoostReplaceAll(sPage, "%submit_url%", sSubmitUrl);
    BoostReplaceAll(sPage, "%optionList_saveSlot%", sOptionList_SaveSlot);
    BoostReplaceAll(sPage, "%optionList_saveType%", sOptionList_SaveType);
    BoostReplaceAll(sPage, "%pullSave_partyID%", sPullSave_PartyID);
    BoostReplaceAll(sPage, "%loadSave_textarea%", sLoadSave_Textarea);
    BoostReplaceAll(sPage, "%loadFromFile_filename%", sLoadFromFile_Filename);
    BoostReplaceAll(sPage, "%saveToFile_filename%", sSaveToFile_Filename);
    BoostReplaceAll(sPage, "%saveAllToDir_directory%", sSaveAllToDir_Directory);
    BoostReplaceAll(sPage, "%saveAllToDir_basename%", sSaveAllToDir_Basename);
    BoostReplaceAll(sPage, "%saveAllToDir_extension%", sSaveAllToDir_Basename);
    BoostReplaceAll(sPage, "%loadAllFromDir_directory%", sLoadAllFromDir_Directory);
    BoostReplaceAll(sPage, "%loadAllFromDir_basename%", sLoadAllFromDir_Basename);
    BoostReplaceAll(sPage, "%loadAllFromDir_extension%", sLoadAllFromDir_Extension);
    SetPageContent(sPage);
}

};
