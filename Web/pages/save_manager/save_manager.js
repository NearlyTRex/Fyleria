// Enable strict mode
"use strict";

// Handle save management
let SaveManager = function() {

    // Current server object
    let currentServerObject = null;

    // Load save manager
    let loadSaveManager = function () {
        let cmd = `
import GeckoUtility
import GeckoSaves`;
        return currentServerObject.runModuleCommand(cmd);
    };

    // Get save file type names
    let getSaveFileTypeNames = function () {
        let cmd = "GeckoUtility.GetFileTypeNames()";
        let resultid = "SaveManager:getSaveFileTypeNames";
        return currentServerObject.runModuleCommandResults(cmd, resultid, true);
    };

    // Get save capacity
    let getSaveCapacity = function () {
        let cmd = "GeckoSaves.GetSaveManager().GetSaveCapacity()";
        let resultid = "SaveManager:getSaveCapacity";
        return currentServerObject.runModuleCommandResults(cmd, resultid, true);
    };

    // Get all saves
    let getAllSaves = function () {
        let cmd = "GeckoSaves.GetSaveManager().GetAllSaves()";
        let resultid = "SaveManager:getAllSaves";
        return currentServerObject.runModuleCommandResults(cmd, resultid, false);
    };

    // Initialize empty save slots
    let initializeEmptySaveSlots = function () {
        let cmd = "GeckoSaves.GetSaveManager().InitializeEmptySaveSlots()";
        return currentServerObject.runModuleCommand(cmd);
    };

    // Initialize all save slots
    let initializeAllSaveSlots = function () {
        let cmd = "GeckoSaves.GetSaveManager().InitializeAllSaveSlots()";
        return currentServerObject.runModuleCommand(cmd);
    };

    // Pull save from memory
    let pullSaveFromMemory = function (sSlot, sPartyID) {
        let cmd = "GeckoSaves.GetSaveManager().PullSaveFromMemory(" + sSlot + ", \"" + sPartyID + "\")";
        return currentServerObject.runModuleCommand(cmd);
    };

    // Push save to memory
    let pushSaveToMemory = function (sSlot) {
        let cmd = "GeckoSaves.GetSaveManager().PushSaveIntoMemory(" + sSlot + ")";
        return currentServerObject.runModuleCommand(cmd);
    };

    // Load save
    let loadSave = function (sSlot, sSaveJson) {
        let cmd = `
sSaveSlot = %SAVESLOT%
sSaveJson = "%SAVEJSON%"
GeckoSaves.GetSaveManager().LoadSave(sSaveSlot, sSaveJson)`;
        cmd = cmd.replace(/%SAVESLOT%/g, sSlot);
        cmd = cmd.replace(/%SAVEJSON%/g, sSaveJson);
        return currentServerObject.runModuleCommand(cmd);
    };

    // Unload save
    let unloadSave = function (sSlot) {
        let cmd = "GeckoSaves.GetSaveManager().UnloadSave(" + sSlot + ")";
        return currentServerObject.runModuleCommand(cmd);
    };

    // Save to file
    let saveToFile = function (sSlot, sFile, sType) {
        let cmd = "GeckoSaves.GetSaveManager().SaveToFile(" + sSlot + ", \"" + sFile + "\", \"" + sType + "\")";
        return currentServerObject.runModuleCommand(cmd);
    };

    // Load from file
    let loadFromFile = function (sSlot, sFile, sType) {
        let cmd = "GeckoSaves.GetSaveManager().LoadFromFile(" + sSlot + ", \"" + sFile + "\", \"" + sType + "\")";
        return currentServerObject.runModuleCommand(cmd);
    };

    // Save all to directory
    let saveAllToDirectory = function (sDirectory, sBase, sExt, sType) {
        let cmd = "GeckoSaves.GetSaveManager().SaveAllToDirectory(\"" + sDirectory + "\", \"" + sBase + "\", \"" + sExt + "\", \"" + sType + "\")";
        return currentServerObject.runModuleCommand(cmd);
    };

    // Load all from directory
    let loadAllFromDirectory = function (sDirectory, sBase, sExt, sType) {
        let cmd = "GeckoSaves.GetSaveManager().LoadAllFromDirectory(\"" + sDirectory + "\", \"" + sBase + "\", \"" + sExt + "\", \"" + sType + "\")";
        return currentServerObject.runModuleCommand(cmd);
    };

    // ------ UI Updates ------ //

    // Type names have been updated
    let typeNamesUpdated = function () {

        // Update save file type selectors
        for (let i = 0; i < saveFileTypeSelectTags.length; i++) {
            let saveFileTypeTag = saveFileTypeSelectTags[i];
            $(saveFileTypeTag).empty();
            $(saveFileTypeTag).append("<option value=''>Save Type...</option>");
            for (let j = 0; j < saveFileTypeNames.length; j++) {
                if (saveFileTypeNames[j].length > 0 && saveFileTypeNames[j] != "None") {
                    $(saveFileTypeTag).append("<option value='" + saveFileTypeNames[j] + "'>" + saveFileTypeNames[j] + "</option>");
                }
            }
        }
    };

    // Save capacity updated
    let saveCapacityUpdated = function () {

        // Update save slot selectors
        for (let i = 0; i < saveSlotSelectTags.length; i++) {
            let saveSlotTag = saveSlotSelectTags[i];
            $(saveSlotTag).empty();
            $(saveSlotTag).append("<option value=''>Save Slot...</option>");
            for (let j = 0; j < saveCapacity; j++) {
                $(saveSlotTag).append("<option value='" + j + "'>" + j + "</option>");
            }
        }

        // Update save data rows
        $(savaDataGroupTag).empty();
        for (let j = 0; j < saveCapacity; j++) {
            let newRow = saveDataGroupRowBase.replace(/%SAVESLOT%/g, j);
            $(savaDataGroupTag).append(newRow);
        }
    };

    // Save data updated
    let saveDataUpdated = function () {

        // Update save descriptions and raw info
        for (let i = 0; i < allSaves.length; i++) {
            let saveSlot = allSaves[i].Slot;
            let saveDescription = allSaves[i].Description;
            let saveTime = allSaves[i].Time;
            let saveRaw = JSON.stringify(allSaves[i]);
            let tagSaveDescription = "#save" + saveSlot + "Data_description";
            let tagSaveRaw = "#save" + saveSlot + "Data_raw";
            saveRaw = saveRaw.replace(/\"/g, "\\\"");
            $(tagSaveDescription).html(saveDescription);
            $(tagSaveRaw).val(saveRaw);
        }
    };

    // ------ Buttons ------ //

    // Register button handlers
    let registerButtonHandlers = function () {
        $(document).on("click", "#initalizeSaveSlots_submit", function(event) {
            initializeAllSaveSlots().then(function () {
                return getAllSaves();
            }).then(function (results) {
                allSaves = results;
                saveDataUpdated();
                displayResults(true, "Initialized all save slots.");
            }).catch(onError);
        });

        $(document).on("click", "#pullSave_submit", function(event) {
            let sSlot = $("#pullSave_saveSlot").val() || "";
            let sPartyID = $("#pullSave_partyID").val() || "";
            if (sSlot.length == 0 || sPartyID.length == 0) {
                onError("Error: Invalid save slot or party ID.");
                return;
            }
            pullSaveFromMemory(sSlot, sPartyID).then(function () {
                return getAllSaves();
            }).then(function (results) {
                allSaves = results;
                saveDataUpdated();
                displayResults(true, "Pulled save for party " + sPartyID + " and placed in slot " + sSlot + ".");
            }).catch(onError);
        });

        $(document).on("click", "#pushSave_submit", function(event) {
            let sSlot = $("#pushSave_saveSlot").val() || "";
            if (sSlot.length == 0) {
                onError("Error: Invalid save slot.");
                return;
            }
            pushSaveToMemory(sSlot).then(function () {
                displayResults(true, "Pushed save in slot " + sSlot + " into party manager.");
            }).catch(onError);
        });

        $(document).on("click", "#loadSave_submit", function(event) {
            let sSlot = $("#loadSave_saveSlot").val() || "";
            let sSaveJson = $("#loadSave_textarea").val() || "";
            if (sSlot.length == 0 || sSaveJson.length == 0) {
                onError("Error: Invalid save slot or save json.");
                return;
            }
            loadSave(sSlot, sSaveJson).then(function () {
                return getAllSaves();
            }).then(function (results) {
                allSaves = results;
                saveDataUpdated();
                displayResults(true, "Loaded save into slot " + sSlot + ".");
            }).catch(onError);
        });

        $(document).on("click", "#unloadSave_submit", function(event) {
            let sSlot = $("#unloadSave_saveSlot").val() || "";
            if (sSlot.length == 0) {
                onError("Error: Invalid save slot.");
                return;
            }
            unloadSave(sSlot).then(function () {
                return initializeEmptySaveSlots();
            }).then(function () {
                return getAllSaves();
            }).then(function (results) {
                allSaves = results;
                saveDataUpdated();
                displayResults(true, "Unloaded save from slot " + sSlot + ".");
            }).catch(onError);
        });

        $(document).on("click", "#loadFromFile_submit", function(event) {
            let sSlot = $("#loadFromFile_saveSlot").val() || "";
            let sFile = $("#loadFromFile_filename").val() || "";
            let sType = $("#loadFromFile_saveType").val() || "";
            if (sSlot.length == 0 || sFile.length == 0 || sType.length == 0) {
                onError("Error: Invalid save slot, filename, or save type.");
                return;
            }
            loadFromFile(sSlot, sFile, sType).then(function () {
                return getAllSaves();
            }).then(function (results) {
                allSaves = results;
                saveDataUpdated();
                displayResults(true, "Loaded save from file " + sFile + " into slot " + sSlot + ".");
            }).catch(onError);
        });

        $(document).on("click", "#saveToFile_submit", function(event) {
            let sSlot = $("#saveToFile_saveSlot").val() || "";
            let sFile = $("#saveToFile_filename").val() || "";
            let sType = $("#saveToFile_saveType").val() || "";
            if (sSlot.length == 0 || sFile.length == 0 || sType.length == 0) {
                onError("Error: Invalid save slot, filename, or save type.");
                return;
            }
            saveToFile(sSlot, sFile, sType).then(function () {
                displayResults(true, "Saved slot " + sSlot + " into file " + sFile + ".");
            }).catch(onError);
        });

        $(document).on("click", "#saveAllToDir_submit", function(event) {
            let sDir = $("#saveAllToDir_directory").val() || "";
            let sBase = $("#saveAllToDir_basename").val() || "";
            let sExt = $("#saveAllToDir_extension").val() || "";
            let sType = $("#saveAllToDir_saveType").val() || "";
            if (sDir.length == 0 || sBase.length == 0 || sExt.length == 0 || sType.length == 0) {
                onError("Error: Invalid directory, basename, extension, or save type.");
                return;
            }
            saveAllToDirectory(sDir, sBase, sExt, sType).then(function () {
                displayResults(true, "Saved all saves into directory " + sDir + " with a save type of " + sType + ".");
            }).catch(onError);
        });

        $(document).on("click", "#loadAllFromDir_submit", function(event) {
            let sDir = $("#loadAllFromDir_directory").val() || "";
            let sBase = $("#loadAllFromDir_basename").val() || "";
            let sExt = $("#loadAllFromDir_extension").val() || "";
            let sType = $("#loadAllFromDir_saveType").val() || "";
            if (sDir.length == 0 || sBase.length == 0 || sExt.length == 0 || sType.length == 0) {
                onError("Error: Invalid directory, basename, extension, or save type.");
                return;
            }
            loadAllFromDirectory(sDir, sBase, sExt, sType).then(function () {
                return getAllSaves();
            }).then(function (results) {
                allSaves = results;
                saveDataUpdated();
                displayResults(true, "Loaded all saves from directory " + sDir + " with a save type of " + sType + ".");
            }).catch(onError);
        });
    };

    // Local data
    let saveFileTypeNames = [];
    let saveCapacity = 0;
    let allSaves = [];

    // Tags
    let saveSlotSelectTags = [
        "#pullSave_saveSlot",
        "#pushSave_saveSlot",
        "#loadSave_saveSlot",
        "#unloadSave_saveSlot",
        "#loadFromFile_saveSlot",
        "#saveToFile_saveSlot"
    ];
    let saveFileTypeSelectTags = [
        "#loadFromFile_saveType",
        "#saveToFile_saveType",
        "#saveAllToDir_saveType",
        "#loadAllFromDir_saveType"
    ];
    let savaDataGroupTag = "#saveDataGroup";

    // Base strings
    let saveDataGroupRowBase = `
<div class="row">
    <div class="col-sm-6">
        <div class="card">
            <div class="card-header">Save %SAVESLOT%</div>
            <div class="card-body">
                <p class="card-text" id="save%SAVESLOT%Data_description">Save description.</p>
            </div>
        </div>
    </div>
    <div class="col-sm-6">
        <div class="form-group">
            <textarea style="resize: none;" class="form-control" rows="3" id="save%SAVESLOT%Data_raw" placeholder="Raw save data" readonly></textarea>
        </div>
    </div>
</div>`;

    // ------ Public API ------ //
    let pub = {};

    // Init
    pub.init = function (serverObj) {
        currentServerObject = serverObj;
        loadSaveManager().then(function () {
            return getSaveFileTypeNames();
        }).then(function (results) {
            saveFileTypeNames = results;
            typeNamesUpdated();
            return getSaveCapacity();
        }).then(function (results) {
            saveCapacity = results;
            saveCapacityUpdated();
            return initializeEmptySaveSlots();
        }).then(function () {
            return getAllSaves();
        }).then(function (results) {
            allSaves = results;
            saveDataUpdated();
            registerButtonHandlers();
        });
    };

    // Return our public api
    return pub;
}();

//# sourceURL=save_manager.js
