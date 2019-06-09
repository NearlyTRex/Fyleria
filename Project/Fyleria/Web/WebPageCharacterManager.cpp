// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Web/WebPageCharacterManager.h"
#include "Character/CharacterTypes.h"
#include "Utility/Constants.h"
#include "Utility/Converters.h"

namespace Gecko
{

WebPageCharacterManager::WebPageCharacterManager()
    : WebPage()
{
    SetPageTemplate(R"TEMPLATE(
<!DOCTYPE html>
<html lang="en-GB">
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <title>Character Manager</title>
    <link href="/lib/bootstrap/css/bootstrap.min.css" rel="stylesheet" type="text/css">
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
            <label class="col-sm-2 col-form-label">Load From JSON</label>
            <div class="col-sm-8">
                <textarea style="resize: none;" class="form-control" rows="3" name="sLoadCharacterFromJson_Textarea" placeholder="Raw character json">%sLoadCharacterFromJson_Textarea%</textarea>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="load_character_from_json">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Load From File</label>
            <div class="col-sm-6">
                <input type="text" class="form-control" name="sLoadCharacterFromFile_Filename" placeholder="Filename" value="%sLoadCharacterFromFile_Filename%"/>
            </div>
            <div class="col-sm-2">
                <select class="form-control" name="sLoadCharacterFromFile_FileType">
                    <option value="" disabled="disabled">File Type...</option>
                    %sOptionList_FileType%
                </select>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="load_character_from_file">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Save To File</label>
            <div class="col-sm-3">
                <input type="text" class="form-control" name="sSaveCharacterToFile_CharID" placeholder="Character Identifier" value="%sSaveCharacterToFile_CharID%"/>
            </div>
            <div class="col-sm-3">
                <input type="text" class="form-control" name="sSaveCharacterToFile_Filename" placeholder="Filename" value="%sSaveCharacterToFile_Filename%"/>
            </div>
            <div class="col-sm-2">
                <select class="form-control" name="sSaveCharacterToFile_FileType">
                    <option value="" disabled="disabled">File Type...</option>
                    %sOptionList_FileType%
                </select>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="save_character_to_file">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Unload Character</label>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="sUnloadCharacter_CharID" placeholder="Character Identifier" value="%sUnloadCharacter_CharID%"/>
            </div>
            <div class="col-sm-4">
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="unload_character">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Generate Character</label>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="sGenerateCharacter_CharID" placeholder="Character Identifier" value="%sGenerateCharacter_CharID%"/>
            </div>
            <div class="col-sm-4">
                <textarea style="resize: none;" class="form-control" rows="3" name="sGenerateCharacter_Textarea" placeholder="Raw character generator json">%sGenerateCharacter_Textarea%</textarea>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="generate_character">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Create Character</label>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="sCreateCharacter_CharID" placeholder="Character Identifier" value="%sCreateCharacter_CharID%"/>
            </div>
            <div class="col-sm-4">
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="create_character">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-4 col-form-label">Save Character Changes</label>
            <div class="col-sm-6">
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="save_character">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <div class="col"><hr></div>
            <div class="col-auto">Character Details</div>
            <div class="col"><hr></div>
        </div>
        <div class="form-group row">
            <div class="col-sm-3">
                <input type="text" class="form-control" name="sCharacterDetails_CharID" placeholder="Character Identifier" readonly="readonly" value="%sCharacterDetails_CharID%"/>
            </div>
            <div class="col-sm-3">
                <input type="text" class="form-control" name="sCharacterDetails_First_Name" placeholder="First Name" value="%sCharacterDetails_First_Name%"/>
            </div>
            <div class="col-sm-3">
                <input type="text" class="form-control" name="sCharacterDetails_Last_Name" placeholder="Last Name" value="%sCharacterDetails_Last_Name%"/>
            </div>
            <div class="col-sm-3">
                <input type="text" class="form-control" name="sCharacterDetails_Age" placeholder="Age" value="%sCharacterDetails_Age%"/>
            </div>
        </div>
        <div class="form-group row">
            <div class="col-sm-3">
                <select class="form-control" name="sCharacterDetails_Gender">
                    <option value="" disabled="disabled">Gender...</option>
                    %sOptionList_Gender%
                </select>
            </div>
            <div class="col-sm-3">
                <select class="form-control" name="sCharacterDetails_Hair">
                    <option value="" disabled="disabled">Hair...</option>
                    %sOptionList_Hair%
                </select>
            </div>
            <div class="col-sm-3">
                <select class="form-control" name="sCharacterDetails_Eyes">
                    <option value="" disabled="disabled">Eyes...</option>
                    %sOptionList_Eyes%
                </select>
            </div>
            <div class="col-sm-3">
                <select class="form-control" name="sCharacterDetails_Handed">
                    <option value="" disabled="disabled">Handedness...</option>
                    %sOptionList_Handed%
                </select>
            </div>
            <div class="col-sm-4">
            </div>
        </div>
        <div class="form-group row">
            <div class="col-sm-3">
                <select class="form-control" name="sCharacterDetails_PowerSet">
                    <option value="" disabled="disabled">Power Set...</option>
                    %sOptionList_PowerSet%
                </select>
            </div>
            <div class="col-sm-3">
                <select class="form-control" name="sCharacterDetails_BaseRace">
                    <option value="" disabled="disabled">Base Race...</option>
                    %sOptionList_BaseRace%
                </select>
            </div>
            <div class="col-sm-3">
                <select class="form-control" name="sCharacterDetails_TransformedRace">
                    <option value="" disabled="disabled">Transformed Race...</option>
                    %sOptionList_TransformedRace%
                </select>
            </div>
            <div class="col-sm-3">
                <select class="form-control" name="sCharacterDetails_CurrentWeaponSet">
                    <option value="" disabled="disabled">Weapon Set...</option>
                    %sOptionList_CurrentWeaponSet%
                </select>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Weapon 1 Left</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Weapon1Left" readonly="readonly" value="%sCharacterDetails_Weapon1Left%"/>
            </div>
            <label class="col-sm-2 col-form-label">Weapon 1 Right</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Weapon1Right" readonly="readonly" value="%sCharacterDetails_Weapon1Right%"/>
            </div>
            <label class="col-sm-2 col-form-label">Neck</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Neck" readonly="readonly" value="%sCharacterDetails_Neck%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Weapon 2 Left</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Weapon2Left" readonly="readonly" value="%sCharacterDetails_Weapon2Left%"/>
            </div>
            <label class="col-sm-2 col-form-label">Weapon 2 Right</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Weapon2Right" readonly="readonly" value="%sCharacterDetails_Weapon2Right%"/>
            </div>
            <label class="col-sm-2 col-form-label">Head</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Head" readonly="readonly" value="%sCharacterDetails_Head%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Left Fingers</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_LeftFingers" readonly="readonly" value="%sCharacterDetails_LeftFingers%"/>
            </div>
            <label class="col-sm-2 col-form-label">Right Fingers</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_RightFingers" readonly="readonly" value="%sCharacterDetails_RightFingers%"/>
            </div>
            <label class="col-sm-2 col-form-label">Hands</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Hands" readonly="readonly" value="%sCharacterDetails_Hands%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Feet</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Feet" readonly="readonly" value="%sCharacterDetails_Feet%"/>
            </div>
            <label class="col-sm-2 col-form-label">Legs</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Legs" readonly="readonly" value="%sCharacterDetails_Legs%"/>
            </div>
            <label class="col-sm-2 col-form-label">Chest</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Chest" readonly="readonly" value="%sCharacterDetails_Chest%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-1 col-form-label">Health</label>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_HP_Current" placeholder="Cur" value="%sCharacterDetails_HP_Current%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_HP_Max" placeholder="Max" value="%sCharacterDetails_HP_Max%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_HP_Regen" placeholder="Reg" value="%sCharacterDetails_HP_Regen%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_HP_Delta" placeholder="Delta" value="%sCharacterDetails_HP_Delta%"/>
            </div>
            <label class="col-sm-1 col-form-label">Blunt</label>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_Blunt_Attack" placeholder="Atk" value="%sCharacterDetails_Blunt_Attack%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_Blunt_Defense" placeholder="Def" value="%sCharacterDetails_Blunt_Defense%"/>
            </div>
            <label class="col-sm-1 col-form-label">Pierce</label>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_Pierce_Attack" placeholder="Atk" value="%sCharacterDetails_Pierce_Attack%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_Pierce_Defense" placeholder="Def" value="%sCharacterDetails_Pierce_Defense%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-1 col-form-label">Magic</label>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_MP_Current" placeholder="Cur" value="%sCharacterDetails_MP_Current%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_MP_Max" placeholder="Max" value="%sCharacterDetails_MP_Max%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_MP_Regen" placeholder="Reg" value="%sCharacterDetails_MP_Regen%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_MP_Delta" placeholder="Delta" value="%sCharacterDetails_MP_Delta%"/>
            </div>
            <label class="col-sm-1 col-form-label">Magic</label>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_Magic_Attack" placeholder="Atk" value="%sCharacterDetails_Magic_Attack%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_Magic_Defense" placeholder="Def" value="%sCharacterDetails_Magic_Defense%"/>
            </div>
            <label class="col-sm-1 col-form-label">Energy</label>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_Energy_Attack" placeholder="Atk" value="%sCharacterDetails_Energy_Attack%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_Energy_Defense" placeholder="Def" value="%sCharacterDetails_Energy_Defense%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-1 col-form-label">Energy</label>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_EP_Current" placeholder="Cur" value="%sCharacterDetails_EP_Current%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_EP_Max" placeholder="Max" value="%sCharacterDetails_EP_Max%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_EP_Regen" placeholder="Reg" value="%sCharacterDetails_EP_Regen%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_EP_Delta" placeholder="Delta" value="%sCharacterDetails_EP_Delta%"/>
            </div>
            <label class="col-sm-1 col-form-label">Slash</label>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_Slash_Attack" placeholder="Atk" value="%sCharacterDetails_Slash_Attack%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_Slash_Defense" placeholder="Def" value="%sCharacterDetails_Slash_Defense%"/>
            </div>
            <label class="col-sm-1 col-form-label">Speed</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Speed" placeholder="Speed" value="%sCharacterDetails_Speed%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-1 col-form-label">Slash</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Slash_Current" placeholder="Current" value="%sCharacterDetails_Slash_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Slash_Rank" placeholder="Rank" value="%sCharacterDetails_Slash_Rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_Slash_ActionPoints" placeholder="AP" value="%sCharacterDetails_Slash_ActionPoints%"/>
            </div>
            <label class="col-sm-1 col-form-label">Sever</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Sever_Current" placeholder="Current" value="%sCharacterDetails_Sever_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Sever_Rank" placeholder="Rank" value="%sCharacterDetails_Sever_Rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_Sever_ActionPoints" placeholder="AP" value="%sCharacterDetails_Sever_ActionPoints%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-1 col-form-label">Slice</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Slice_Current" placeholder="Current" value="%sCharacterDetails_Slice_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Slice_Rank" placeholder="Rank" value="%sCharacterDetails_Slice_Rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_Slice_ActionPoints" placeholder="AP" value="%sCharacterDetails_Slice_ActionPoints%"/>
            </div>
            <label class="col-sm-1 col-form-label">Slit</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Slit_Current" placeholder="Current" value="%sCharacterDetails_Slit_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Slit_Rank" placeholder="Rank" value="%sCharacterDetails_Slit_Rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_Slit_ActionPoints" placeholder="AP" value="%sCharacterDetails_Slit_ActionPoints%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-1 col-form-label">Cleave</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Cleave_Current" placeholder="Current" value="%sCharacterDetails_Cleave_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Cleave_Rank" placeholder="Rank" value="%sCharacterDetails_Cleave_Rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_Cleave_ActionPoints" placeholder="AP" value="%sCharacterDetails_Cleave_ActionPoints%"/>
            </div>
            <label class="col-sm-1 col-form-label">Decapitate</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Decapitate_Current" placeholder="Current" value="%sCharacterDetails_Decapitate_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Decapitate_Rank" placeholder="Rank" value="%sCharacterDetails_Decapitate_Rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_Decapitate_ActionPoints" placeholder="AP" value="%sCharacterDetails_Decapitate_ActionPoints%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-1 col-form-label">Parry</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Parry_Current" placeholder="Current" value="%sCharacterDetails_Parry_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Parry_Rank" placeholder="Rank" value="%sCharacterDetails_Parry_Rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_Parry_ActionPoints" placeholder="AP" value="%sCharacterDetails_Parry_ActionPoints%"/>
            </div>
            <label class="col-sm-1 col-form-label">Riposte</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Riposte_Current" placeholder="Current" value="%sCharacterDetails_Riposte_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Riposte_Rank" placeholder="Rank" value="%sCharacterDetails_Riposte_Rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_Riposte_ActionPoints" placeholder="AP" value="%sCharacterDetails_Riposte_ActionPoints%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-1 col-form-label">Bash</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Bash_Current" placeholder="Current" value="%sCharacterDetails_Bash_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Bash_Rank" placeholder="Rank" value="%sCharacterDetails_Bash_Rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_Bash_ActionPoints" placeholder="AP" value="%sCharacterDetails_Bash_ActionPoints%"/>
            </div>
            <label class="col-sm-1 col-form-label">Smash</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Smash_Current" placeholder="Current" value="%sCharacterDetails_Smash_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Smash_Rank" placeholder="Rank" value="%sCharacterDetails_Smash_Rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_Smash_ActionPoints" placeholder="AP" value="%sCharacterDetails_Smash_ActionPoints%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-1 col-form-label">Crush</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Crush_Current" placeholder="Current" value="%sCharacterDetails_Crush_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Crush_Rank" placeholder="Rank" value="%sCharacterDetails_Crush_Rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_Crush_ActionPoints" placeholder="AP" value="%sCharacterDetails_Crush_ActionPoints%"/>
            </div>
            <label class="col-sm-1 col-form-label">Impact</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Impact_Current" placeholder="Current" value="%sCharacterDetails_Impact_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Impact_Rank" placeholder="Rank" value="%sCharacterDetails_Impact_Rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_Impact_ActionPoints" placeholder="AP" value="%sCharacterDetails_Impact_ActionPoints%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-1 col-form-label">Break</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Break_Current" placeholder="Current" value="%sCharacterDetails_Break_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Break_Rank" placeholder="Rank" value="%sCharacterDetails_Break_Rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_Break_ActionPoints" placeholder="AP" value="%sCharacterDetails_Break_ActionPoints%"/>
            </div>
            <label class="col-sm-1 col-form-label">Crack</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Crack_Current" placeholder="Current" value="%sCharacterDetails_Crack_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Crack_Rank" placeholder="Rank" value="%sCharacterDetails_Crack_Rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_Crack_ActionPoints" placeholder="AP" value="%sCharacterDetails_Crack_ActionPoints%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-1 col-form-label">Block</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Block_Current" placeholder="Current" value="%sCharacterDetails_Block_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Block_Rank" placeholder="Rank" value="%sCharacterDetails_Block_Rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_Block_ActionPoints" placeholder="AP" value="%sCharacterDetails_Block_ActionPoints%"/>
            </div>
            <label class="col-sm-1 col-form-label">Rush</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Rush_Current" placeholder="Current" value="%sCharacterDetails_Rush_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Rush_Rank" placeholder="Rank" value="%sCharacterDetails_Rush_Rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_Rush_ActionPoints" placeholder="AP" value="%sCharacterDetails_Rush_ActionPoints%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-1 col-form-label">Pierce</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Pierce_Current" placeholder="Current" value="%sCharacterDetails_Pierce_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Pierce_Rank" placeholder="Rank" value="%sCharacterDetails_Pierce_Rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_Pierce_ActionPoints" placeholder="AP" value="%sCharacterDetails_Pierce_ActionPoints%"/>
            </div>
            <label class="col-sm-1 col-form-label">Drill</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Drill_Current" placeholder="Current" value="%sCharacterDetails_Drill_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Drill_Rank" placeholder="Rank" value="%sCharacterDetails_Drill_Rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_Drill_ActionPoints" placeholder="AP" value="%sCharacterDetails_Drill_ActionPoints%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-1 col-form-label">Shoot</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Shoot_Current" placeholder="Current" value="%sCharacterDetails_Shoot_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Shoot_Rank" placeholder="Rank" value="%sCharacterDetails_Shoot_Rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_Shoot_ActionPoints" placeholder="AP" value="%sCharacterDetails_Shoot_ActionPoints%"/>
            </div>
            <label class="col-sm-1 col-form-label">Impale</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Impale_Current" placeholder="Current" value="%sCharacterDetails_Impale_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Impale_Rank" placeholder="Rank" value="%sCharacterDetails_Impale_Rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_Impale_ActionPoints" placeholder="AP" value="%sCharacterDetails_Impale_ActionPoints%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-1 col-form-label">Stealth Strike</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_StealthStrike_Current" placeholder="Current" value="%sCharacterDetails_StealthStrike_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_StealthStrike_Rank" placeholder="Rank" value="%sCharacterDetails_StealthStrike_Rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_StealthStrike_ActionPoints" placeholder="AP" value="%sCharacterDetails_StealthStrike_ActionPoints%"/>
            </div>
            <label class="col-sm-1 col-form-label">Critical Shot</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_CriticalShot_Current" placeholder="Current" value="%sCharacterDetails_CriticalShot_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_CriticalShot_Rank" placeholder="Rank" value="%sCharacterDetails_CriticalShot_Rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_CriticalShot_ActionPoints" placeholder="AP" value="%sCharacterDetails_CriticalShot_ActionPoints%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-1 col-form-label">Dodge</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Dodge_Current" placeholder="Current" value="%sCharacterDetails_Dodge_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Dodge_Rank" placeholder="Rank" value="%sCharacterDetails_Dodge_Rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_Dodge_ActionPoints" placeholder="AP" value="%sCharacterDetails_Dodge_ActionPoints%"/>
            </div>
            <label class="col-sm-1 col-form-label">Counter</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Counter_Current" placeholder="Current" value="%sCharacterDetails_Counter_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Counter_Rank" placeholder="Rank" value="%sCharacterDetails_Counter_Rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="sCharacterDetails_Counter_ActionPoints" placeholder="AP" value="%sCharacterDetails_Counter_ActionPoints%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Barbarian</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Barbarian_Current" placeholder="Current" value="%sCharacterDetails_Barbarian_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Barbarian_Rank" placeholder="Rank" value="%sCharacterDetails_Barbarian_Rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Mage</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Mage_Current" placeholder="Current" value="%sCharacterDetails_Mage_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Mage_Rank" placeholder="Rank" value="%sCharacterDetails_Mage_Rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Rogue</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Rogue_Current" placeholder="Current" value="%sCharacterDetails_Rogue_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Rogue_Rank" placeholder="Rank" value="%sCharacterDetails_Rogue_Rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Blademaster</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Blademaster_Current" placeholder="Current" value="%sCharacterDetails_Blademaster_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Blademaster_Rank" placeholder="Rank" value="%sCharacterDetails_Blademaster_Rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Avatar</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Avatar_Current" placeholder="Current" value="%sCharacterDetails_Avatar_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Avatar_Rank" placeholder="Rank" value="%sCharacterDetails_Avatar_Rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Ambidextrous</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Ambidext_Current" placeholder="Current" value="%sCharacterDetails_Ambidext_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Ambidext_Rank" placeholder="Rank" value="%sCharacterDetails_Ambidext_Rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Focused</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Focused_Current" placeholder="Current" value="%sCharacterDetails_Focused_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Focused_Rank" placeholder="Rank" value="%sCharacterDetails_Focused_Rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Stalwart</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Stalwart_Current" placeholder="Current" value="%sCharacterDetails_Stalwart_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Stalwart_Rank" placeholder="Rank" value="%sCharacterDetails_Stalwart_Rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Healer</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Healer_Current" placeholder="Current" value="%sCharacterDetails_Healer_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Healer_Rank" placeholder="Rank" value="%sCharacterDetails_Healer_Rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Alchemist</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Alchemist_Current" placeholder="Current" value="%sCharacterDetails_Alchemist_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Alchemist_Rank" placeholder="Rank" value="%sCharacterDetails_Alchemist_Rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Energist</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Energist_Current" placeholder="Current" value="%sCharacterDetails_Energist_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Energist_Rank" placeholder="Rank" value="%sCharacterDetails_Energist_Rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Chemist</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Chemist_Current" placeholder="Current" value="%sCharacterDetails_Chemist_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Chemist_Rank" placeholder="Rank" value="%sCharacterDetails_Chemist_Rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Hammersmith</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Hammersmith_Current" placeholder="Current" value="%sCharacterDetails_Hammersmith_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Hammersmith_Rank" placeholder="Rank" value="%sCharacterDetails_Hammersmith_Rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Spellsmith</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Spellsmith_Current" placeholder="Current" value="%sCharacterDetails_Spellsmith_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Spellsmith_Rank" placeholder="Rank" value="%sCharacterDetails_Spellsmith_Rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Bowsmith</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Bowsmith_Current" placeholder="Current" value="%sCharacterDetails_Bowsmith_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Bowsmith_Rank" placeholder="Rank" value="%sCharacterDetails_Bowsmith_Rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Swordsmith</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Swordsmith_Current" placeholder="Current" value="%sCharacterDetails_Swordsmith_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Swordsmith_Rank" placeholder="Rank" value="%sCharacterDetails_Swordsmith_Rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Weaver</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Weaver_Current" placeholder="Current" value="%sCharacterDetails_Weaver_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Weaver_Rank" placeholder="Rank" value="%sCharacterDetails_Weaver_Rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Tanner</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Tanner_Current" placeholder="Current" value="%sCharacterDetails_Tanner_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Tanner_Rank" placeholder="Rank" value="%sCharacterDetails_Tanner_Rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Scalesmith</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Scalesmith_Current" placeholder="Current" value="%sCharacterDetails_Scalesmith_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Scalesmith_Rank" placeholder="Rank" value="%sCharacterDetails_Scalesmith_Rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Platesmith</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Platesmith_Current" placeholder="Current" value="%sCharacterDetails_Platesmith_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Platesmith_Rank" placeholder="Rank" value="%sCharacterDetails_Platesmith_Rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Goldsmith</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Goldsmith_Current" placeholder="Current" value="%sCharacterDetails_Goldsmith_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Goldsmith_Rank" placeholder="Rank" value="%sCharacterDetails_Goldsmith_Rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Shieldsmith</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Shieldsmith_Current" placeholder="Current" value="%sCharacterDetails_Shieldsmith_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Shieldsmith_Rank" placeholder="Rank" value="%sCharacterDetails_Shieldsmith_Rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Hammerbane</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Hammerbane_Current" placeholder="Current" value="%sCharacterDetails_Hammerbane_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Hammerbane_Rank" placeholder="Rank" value="%sCharacterDetails_Hammerbane_Rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Spellbane</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Spellbane_Current" placeholder="Current" value="%sCharacterDetails_Spellbane_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Spellbane_Rank" placeholder="Rank" value="%sCharacterDetails_Spellbane_Rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Bowbane</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Bowbane_Current" placeholder="Current" value="%sCharacterDetails_Bowbane_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Bowbane_Rank" placeholder="Rank" value="%sCharacterDetails_Bowbane_Rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Swordbane</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Swordbane_Current" placeholder="Current" value="%sCharacterDetails_Swordbane_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Swordbane_Rank" placeholder="Rank" value="%sCharacterDetails_Swordbane_Rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Threadbare</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Threadbare_Current" placeholder="Current" value="%sCharacterDetails_Threadbare_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Threadbare_Rank" placeholder="Rank" value="%sCharacterDetails_Threadbare_Rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Stud Remover</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Studremover_Current" placeholder="Current" value="%sCharacterDetails_Studremover_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Studremover_Rank" placeholder="Rank" value="%sCharacterDetails_Studremover_Rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Scalebane</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Scalebane_Current" placeholder="Current" value="%sCharacterDetails_Scalebane_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Scalebane_Rank" placeholder="Rank" value="%sCharacterDetails_Scalebane_Rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Platebane</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Platebane_Current" placeholder="Current" value="%sCharacterDetails_Platebane_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Platebane_Rank" placeholder="Rank" value="%sCharacterDetails_Platebane_Rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Goldbane</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Goldbane_Current" placeholder="Current" value="%sCharacterDetails_Goldbane_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Goldbane_Rank" placeholder="Rank" value="%sCharacterDetails_Goldbane_Rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Shieldbane</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Shieldbane_Current" placeholder="Current" value="%sCharacterDetails_Shieldbane_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Shieldbane_Rank" placeholder="Rank" value="%sCharacterDetails_Shieldbane_Rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Holy</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Holy_Current" placeholder="Current" value="%sCharacterDetails_Holy_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Holy_Rank" placeholder="Rank" value="%sCharacterDetails_Holy_Rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Fire</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Fire_Current" placeholder="Current" value="%sCharacterDetails_Fire_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Fire_Rank" placeholder="Rank" value="%sCharacterDetails_Fire_Rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Ice</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Ice_Current" placeholder="Current" value="%sCharacterDetails_Ice_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Ice_Rank" placeholder="Rank" value="%sCharacterDetails_Ice_Rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Shock</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Shock_Current" placeholder="Current" value="%sCharacterDetails_Shock_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Shock_Rank" placeholder="Rank" value="%sCharacterDetails_Shock_Rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Dark</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Dark_Current" placeholder="Current" value="%sCharacterDetails_Dark_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Dark_Rank" placeholder="Rank" value="%sCharacterDetails_Dark_Rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Light</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Light_Current" placeholder="Current" value="%sCharacterDetails_Light_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Light_Rank" placeholder="Rank" value="%sCharacterDetails_Light_Rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Force</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Force_Current" placeholder="Current" value="%sCharacterDetails_Force_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Force_Rank" placeholder="Rank" value="%sCharacterDetails_Force_Rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Mind</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Mind_Current" placeholder="Current" value="%sCharacterDetails_Mind_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Mind_Rank" placeholder="Rank" value="%sCharacterDetails_Mind_Rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Earth</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Earth_Current" placeholder="Current" value="%sCharacterDetails_Earth_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Earth_Rank" placeholder="Rank" value="%sCharacterDetails_Earth_Rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Blood</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Blood_Current" placeholder="Current" value="%sCharacterDetails_Blood_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Blood_Rank" placeholder="Rank" value="%sCharacterDetails_Blood_Rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Flesh</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Flesh_Current" placeholder="Current" value="%sCharacterDetails_Flesh_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Flesh_Rank" placeholder="Rank" value="%sCharacterDetails_Flesh_Rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Wind</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Wind_Current" placeholder="Current" value="%sCharacterDetails_Wind_Current%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="sCharacterDetails_Wind_Rank" placeholder="Rank" value="%sCharacterDetails_Wind_Rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <div class="col-sm-12">
                <textarea style="resize: none;" class="form-control" rows="3" name="sCharacterDetails_RawJson" placeholder="Raw character json" readonly="readonly">%sCharacterDetails_RawJson%</textarea>
            </div>
        </div>
    </form>
</div>
</html>
)TEMPLATE");
}

WebPageCharacterManager::~WebPageCharacterManager()
{
}

void WebPageCharacterManager::UpdatePageContent(const ParameterMapType& tParams)
{
    // Build option lists
    MAKE_HTML_OPTION_LIST_STRING(CharacterGenderType);
    MAKE_HTML_OPTION_LIST_STRING(CharacterHairType);
    MAKE_HTML_OPTION_LIST_STRING(CharacterEyeType);
    MAKE_HTML_OPTION_LIST_STRING(CharacterHandednessType);
    MAKE_HTML_OPTION_LIST_STRING(CharacterPowerSetType);
    MAKE_HTML_OPTION_LIST_STRING(CharacterBaseRaceType);
    MAKE_HTML_OPTION_LIST_STRING(CharacterTransformedRaceType);
    MAKE_HTML_OPTION_LIST_STRING(CharacterWeaponSetType);
    MAKE_HTML_OPTION_LIST_STRING(FileType);



    // Set page content
    String sPage = GetPageTemplate();
    BoostReplaceAll(sPage, "%sSubmit_Url%", WEB_PAGE_TOOL_CHARACTER_MANAGER);
    BoostReplaceAll(sPage, "%sOptionList_Gender%", sOptionList_CharacterGenderType);
    BoostReplaceAll(sPage, "%sOptionList_Hair%", sOptionList_CharacterHairType);
    BoostReplaceAll(sPage, "%sOptionList_Eyes%", sOptionList_CharacterEyeType);
    BoostReplaceAll(sPage, "%sOptionList_Handed%", sOptionList_CharacterHandednessType);
    BoostReplaceAll(sPage, "%sOptionList_PowerSet%", sOptionList_CharacterPowerSetType);
    BoostReplaceAll(sPage, "%sOptionList_BaseRace%", sOptionList_CharacterBaseRaceType);
    BoostReplaceAll(sPage, "%sOptionList_TransformedRace%", sOptionList_CharacterTransformedRaceType);
    BoostReplaceAll(sPage, "%sOptionList_CurrentWeaponSet%", sOptionList_CharacterWeaponSetType);
    BoostReplaceAll(sPage, "%sOptionList_FileType%", sOptionList_FileType);
    BoostReplaceAll(sPage, "%sCreateCharacter_CharID%", "");
    BoostReplaceAll(sPage, "%sDeleteCharacter_CharID%", "");
    BoostReplaceAll(sPage, "%sGenerateCharacter_CharID%", "");
    BoostReplaceAll(sPage, "%sGenerateCharacter_Textarea%", "");
    BoostReplaceAll(sPage, "%sLoadCharacterFromFile_Filename%", "");
    BoostReplaceAll(sPage, "%sLoadCharacterFromJson_Textarea%", "");
    BoostReplaceAll(sPage, "%sSaveCharacterToFile_CharID%", "");
    BoostReplaceAll(sPage, "%sSaveCharacterToFile_Filename%", "");
    BoostReplaceAll(sPage, "%sUnloadCharacter_CharID%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_CharID%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_First_Name%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Last_Name%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Age%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Blunt_Attack%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Blunt_Defense%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Energy_Attack%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Energy_Defense%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Magic_Attack%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Magic_Defense%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Pierce_Attack%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Pierce_Defense%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Slash_Attack%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Slash_Defense%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_HP_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_HP_Max%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_HP_Regen%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_HP_Delta%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_MP_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_MP_Max%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_MP_Regen%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_MP_Delta%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_EP_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_EP_Max%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_EP_Regen%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_EP_Delta%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Speed%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Chest%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Feet%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Hands%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Head%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Legs%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Neck%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_LeftFingers%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_RightFingers%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Weapon1Left%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Weapon1Right%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Weapon2Left%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Weapon2Right%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Bash_ActionPoints%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Block_ActionPoints%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Break_ActionPoints%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Cleave_ActionPoints%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Counter_ActionPoints%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Crack_ActionPoints%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Crush_ActionPoints%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_CriticalShot_ActionPoints%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Decapitate_ActionPoints%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Dodge_ActionPoints%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Drill_ActionPoints%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Impact_ActionPoints%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Impale_ActionPoints%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Parry_ActionPoints%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Pierce_ActionPoints%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Riposte_ActionPoints%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Rush_ActionPoints%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Sever_ActionPoints%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Shoot_ActionPoints%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Slash_ActionPoints%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Slice_ActionPoints%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Slit_ActionPoints%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Smash_ActionPoints%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_StealthStrike_ActionPoints%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Alchemist_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Alchemist_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Ambidext_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Ambidext_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Avatar_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Avatar_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Barbarian_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Barbarian_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Bash_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Bash_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Blademaster_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Blademaster_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Block_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Block_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Blood_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Blood_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Bowbane_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Bowbane_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Bowsmith_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Bowsmith_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Break_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Break_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Chemist_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Chemist_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Cleave_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Cleave_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Counter_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Counter_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Crack_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Crack_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Crush_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Crush_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_CriticalShot_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_CriticalShot_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Dark_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Dark_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Decapitate_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Decapitate_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Dodge_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Dodge_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Drill_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Drill_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Earth_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Earth_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Energist_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Energist_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Fire_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Fire_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Flesh_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Flesh_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Focused_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Focused_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Force_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Force_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Goldbane_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Goldbane_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Goldsmith_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Goldsmith_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Hammerbane_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Hammerbane_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Hammersmith_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Hammersmith_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Healer_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Healer_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Holy_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Holy_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Ice_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Ice_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Impact_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Impact_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Impale_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Impale_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Light_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Light_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Mage_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Mage_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Mind_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Mind_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Parry_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Parry_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Pierce_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Pierce_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Platebane_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Platebane_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Platesmith_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Platesmith_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Riposte_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Riposte_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Rogue_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Rogue_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Rush_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Rush_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Scalebane_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Scalebane_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Scalesmith_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Scalesmith_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Sever_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Sever_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Shieldbane_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Shieldbane_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Shieldsmith_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Shieldsmith_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Shock_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Shock_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Shoot_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Shoot_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Slash_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Slash_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Slice_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Slice_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Slit_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Slit_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Smash_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Smash_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Spellbane_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Spellbane_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Spellsmith_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Spellsmith_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_StealthStrike_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_StealthStrike_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Stalwart_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Stalwart_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Studremover_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Studremover_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Swordbane_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Swordbane_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Swordsmith_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Swordsmith_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Tanner_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Tanner_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Threadbare_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Threadbare_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Weaver_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Weaver_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Wind_Current%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_Wind_Rank%", "");
    BoostReplaceAll(sPage, "%sCharacterDetails_RawJson%", "");
    SetPageContent(sPage);
}

};
