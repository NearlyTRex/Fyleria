// Display character by json
function DisplayCharacterByJson(sCharJson) {

    // Basic data
    var basicData = sCharJson["BasicData"];
    $("#CharacterDetails_CharID").val(basicData["CharacterID"]);
    $("#CharacterDetails_First_Name").val(basicData["FirstName"]);
    $("#CharacterDetails_Last_Name").val(basicData["LastName"]);
    $("#CharacterDetails_Age").val(basicData["Age"]);
    $("#CharacterDetails_Gender").val(basicData["Gender"]);
    $("#CharacterDetails_Hair").val(basicData["Hair"]);
    $("#CharacterDetails_Eyes").val(basicData["Eyes"]);
    $("#CharacterDetails_Handedness").val(basicData["Handedness"]);
    $("#CharacterDetails_PowerSet").val(basicData["PowerSet"]);
    $("#CharacterDetails_BaseRace").val(basicData["BaseRace"]);
    $("#CharacterDetails_TransformedRace").val(basicData["TransformedRace"]);
    $("#CharacterDetails_WeaponSet").val(basicData["WeaponSet"]);

    // Progress data
    var progressData = sCharJson["ProgressData"];
    $("#CharacterDetails_HP_Current").val(progressData["HealthPointsCurrent"]);
    $("#CharacterDetails_MP_Current").val(progressData["MagicPointsCurrent"]);
    $("#CharacterDetails_EP_Current").val(progressData["EnergyPointsCurrent"]);
    $("#CharacterDetails_HP_Max").val(progressData["HealthPointsMax"]);
    $("#CharacterDetails_MP_Max").val(progressData["MagicPointsMax"]);
    $("#CharacterDetails_EP_Max").val(progressData["EnergyPointsMax"]);
    $("#CharacterDetails_HP_Regen").val(progressData["HealthRegen"]);
    $("#CharacterDetails_MP_Regen").val(progressData["MagicRegen"]);
    $("#CharacterDetails_EP_Regen").val(progressData["EnergyRegen"]);
    $("#CharacterDetails_HP_Delta").val(progressData["HealthCostDelta"]);
    $("#CharacterDetails_MP_Delta").val(progressData["MagicCostDelta"]);
    $("#CharacterDetails_EP_Delta").val(progressData["EnergyCostDelta"]);
    $("#CharacterDetails_Speed").val(progressData["Speed"]);
    $("#CharacterDetails_Blunt_Attack").val(progressData["BluntAttack"]);
    $("#CharacterDetails_Blunt_Defense").val(progressData["BluntDefense"]);
    $("#CharacterDetails_Pierce_Attack").val(progressData["PierceAttack"]);
    $("#CharacterDetails_Pierce_Defense").val(progressData["PierceDefense"]);
    $("#CharacterDetails_Slash_Attack").val(progressData["SlashAttack"]);
    $("#CharacterDetails_Slash_Defense").val(progressData["SlashDefense"]);
    $("#CharacterDetails_Magic_Attack").val(progressData["MagicAttack"]);
    $("#CharacterDetails_Magic_Defense").val(progressData["MagicDefense"]);
    $("#CharacterDetails_Energy_Attack").val(progressData["EnergyAttack"]);
    $("#CharacterDetails_Energy_Defense").val(progressData["EnergyDefense"]);

    // Action data
    var actionData = sCharJson["ActionData"];
    $("#CharacterDetails_Slash_ActionPoints").val(progressData["SlashPoints"]);
}

// Main
$(document).ready(function() {

    // Load character from json
    $("#LoadCharacterFromJson_Button").click(function() {
        var sCharJson = $("#LoadCharacterFromJson_Textarea").val();
        if (sCharJson !== "") {
            LoadCharacterFromJson(sCharJson);
        }
    });

    // Load character from file
    $("#LoadCharacterFromFile_Button").click(function() {
        var sFileLocation = $("#LoadCharacterFromFile_Filename").val();
        var sFileType = $("#LoadCharacterFromFile_FileType").val();
        if (sFileLocation !== "" && sFileType !== "") {
            LoadCharacterFromFile(sFileLocation, sFileType);
        }
    });

    // Save character to file
    $("#SaveCharacterToFile_Button").click(function() {
        var sCharID = $("#SaveCharacterToFile_CharID").val();
        var sFileLocation = $("#SaveCharacterToFile_Filename").val();
        var sFileType = $("#SaveCharacterToFile_FileType").val();
        if (sCharID !== "" && sFileLocation !== "" && sFileType !== "") {
            SaveCharacterFromID(sCharID, sFileLocation, sFileType);
        }
    });

    // Unload character
    $("#UnloadCharacter_Button").click(function() {
        var sCharID = $("#UnloadCharacter_CharID").val();
        if (sCharID !== "") {
            UnloadCharacter(sCharID);
        }
    });

    // Generate character
    $("#GenerateCharacter_Button").click(function() {
        var sCharID = $("#GenerateCharacter_CharID").val();
        var sGeneratorJson = $("#GenerateCharacter_Textarea").val();
        if (sCharID !== "" && sGeneratorJson !== "") {
            GenerateCharacter(sCharID, sGeneratorJson);
        }
    });

    // Generate random character
    $("#GenerateRandomCharacter_Button").click(async function() {
        var sCharID = $("#GenerateRandomCharacter_CharID").val();
        if (sCharID !== "") {
            GenerateRandomCharacter(sCharID);
            var sCharJson = await GetCharacter(sCharID);
            DisplayCharacterByJson(sCharJson);
        }
    });

    // Regenerate character data
    $("#RegenerateCharacterData_Button").click(function() {
        var sCharID = $("#RegenerateCharacterData_CharID").val();
        if (sCharID !== "") {
            RegenerateCharacterData(sCharID);
        }
    });

    // Create character
    $("#CreateCharacter_Button").click(function() {
        var sCharID = $("#CreateCharacter_CharID").val();
        if (sCharID !== "") {
            CreateCharacter(sCharID);
        }
    });

    // Display character
    $("#DisplayCharacter_Button").click(function() {
        var sCharID = $("#DisplayCharacter_CharID").val();
    });

    // Save character
    $("#SaveCharacter_Button").click(function() {
    });
});



//CharacterDetails_Slash_SkillPoints
//CharacterDetails_Slash_ActionPoints
//CharacterDetails_Sever_SkillPoints
//CharacterDetails_Sever_ActionPoints
//CharacterDetails_Slice_SkillPoints
//CharacterDetails_Slice_ActionPoints
//CharacterDetails_Slit_SkillPoints
//CharacterDetails_Slit_ActionPoints
//CharacterDetails_Cleave_SkillPoints
//CharacterDetails_Cleave_ActionPoints
//CharacterDetails_Decapitate_SkillPoints
//CharacterDetails_Decapitate_ActionPoints
//CharacterDetails_Parry_SkillPoints
//CharacterDetails_Parry_ActionPoints
//CharacterDetails_Riposte_SkillPoints
//CharacterDetails_Riposte_ActionPoints
//CharacterDetails_Bash_SkillPoints
//CharacterDetails_Bash_ActionPoints
//CharacterDetails_Smash_SkillPoints
//CharacterDetails_Smash_ActionPoints
//CharacterDetails_Crush_SkillPoints
//CharacterDetails_Crush_ActionPoints
//CharacterDetails_Impact_SkillPoints
//CharacterDetails_Impact_ActionPoints
//CharacterDetails_Break_SkillPoints
//CharacterDetails_Break_ActionPoints
//CharacterDetails_Crack_SkillPoints
//CharacterDetails_Crack_ActionPoints
//CharacterDetails_Block_SkillPoints
//CharacterDetails_Block_ActionPoints
//CharacterDetails_Rush_SkillPoints
//CharacterDetails_Rush_ActionPoints
//CharacterDetails_Pierce_SkillPoints
//CharacterDetails_Pierce_ActionPoints
//CharacterDetails_Drill_SkillPoints
//CharacterDetails_Drill_ActionPoints
//CharacterDetails_Shoot_SkillPoints
//CharacterDetails_Shoot_ActionPoints
//CharacterDetails_Impale_SkillPoints
//CharacterDetails_Impale_ActionPoints
//CharacterDetails_StealthStrike_SkillPoints
//CharacterDetails_StealthStrike_ActionPoints
//CharacterDetails_CriticalShot_SkillPoints
//CharacterDetails_CriticalShot_ActionPoints
//CharacterDetails_Dodge_SkillPoints
//CharacterDetails_Dodge_ActionPoints
//CharacterDetails_Counter_SkillPoints
//CharacterDetails_Counter_ActionPoints
//CharacterDetails_Barbarian_SkillPoints
//CharacterDetails_Mage_SkillPoints
//CharacterDetails_Rogue_SkillPoints
//CharacterDetails_Blademaster_SkillPoints
//CharacterDetails_Avatar_SkillPoints
//CharacterDetails_Ambidext_SkillPoints
//CharacterDetails_Focused_SkillPoints
//CharacterDetails_Stalwart_SkillPoints
//CharacterDetails_Healer_SkillPoints
//CharacterDetails_Alchemist_SkillPoints
//CharacterDetails_Energist_SkillPoints
//CharacterDetails_Chemist_SkillPoints
//CharacterDetails_Hammersmith_SkillPoints
//CharacterDetails_Spellsmith_SkillPoints
//CharacterDetails_Bowsmith_SkillPoints
//CharacterDetails_Swordsmith_SkillPoints
//CharacterDetails_Weaver_SkillPoints
//CharacterDetails_Tanner_SkillPoints
//CharacterDetails_Scalesmith_SkillPoints
//CharacterDetails_Platesmith_SkillPoints
//CharacterDetails_Goldsmith_SkillPoints
//CharacterDetails_Shieldsmith_SkillPoints
//CharacterDetails_Hammerbane_SkillPoints
//CharacterDetails_Spellbane_SkillPoints
//CharacterDetails_Bowbane_SkillPoints
//CharacterDetails_Swordbane_SkillPoints
//CharacterDetails_Threadbare_SkillPoints
//CharacterDetails_Studremover_SkillPoints
//CharacterDetails_Scalebane_SkillPoints
//CharacterDetails_Platebane_SkillPoints
//CharacterDetails_Goldbane_SkillPoints
//CharacterDetails_Shieldbane_SkillPoints
//CharacterDetails_Holy_SkillPoints
//CharacterDetails_Fire_SkillPoints
//CharacterDetails_Ice_SkillPoints
//CharacterDetails_Shock_SkillPoints
//CharacterDetails_Dark_SkillPoints
//CharacterDetails_Light_SkillPoints
//CharacterDetails_Force_SkillPoints
//CharacterDetails_Mind_SkillPoints
//CharacterDetails_Earth_SkillPoints
//CharacterDetails_Blood_SkillPoints
//CharacterDetails_Flesh_SkillPoints
//CharacterDetails_Wind_SkillPoints
