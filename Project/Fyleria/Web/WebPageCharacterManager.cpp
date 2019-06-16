// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Web/WebPageCharacterManager.h"
#include "Character/CharacterManager.h"
#include "Character/CharacterTypes.h"
#include "Utility/Constants.h"
#include "Utility/Converters.h"
#include "Utility/Templates.h"

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
            <div class="col-auto"><a href="/">Home</a></div>
            <div class="col"><hr></div>
        </div>
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
            <label class="col-sm-2 col-form-label">Generate Random Character</label>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="sGenerateRandomCharacter_CharID" placeholder="Character Identifier" value="%sGenerateRandomCharacter_CharID%"/>
            </div>
            <div class="col-sm-4">
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="generate_random_character">Run</button>
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
            <label class="col-sm-2 col-form-label">Display Character</label>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="sDisplayCharacter_CharID" placeholder="Character Identifier" value="%sDisplayCharacter_CharID%"/>
            </div>
            <div class="col-sm-4">
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="display_character">Run</button>
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
            <div class="col-auto">Character List</div>
            <div class="col"><hr></div>
        </div>
        <div class="form-group row">
            <div class="col-sm-12">
                <textarea style="resize: none;" class="form-control" rows="3" readonly="readonly">%sAllCharacterIDs%</textarea>
            </div>
        </div>
        <div class="form-group row">
            <div class="col"><hr></div>
            <div class="col-auto">Character Details</div>
            <div class="col"><hr></div>
        </div>
        <div class="form-group row">
            <div class="col-sm-4">
                <input type="text" class="form-control" name="sCharacterDetails_CharID" placeholder="Character Identifier" readonly="readonly" value="%sCharacterDetails_CharID%"/>
            </div>
            <div class="col-sm-4">
                <input type="text" class="form-control" placeholder="Party Identifier" readonly="readonly" value="%sCharacterDetails_PartyID%"/>
            </div>
            <div class="col-sm-4">
                <input type="text" class="form-control" placeholder="Character Target Type" readonly="readonly" value="%sCharacterDetails_CharTargetType%"/>
            </div>
        </div>
        <div class="form-group row">
            <div class="col-sm-4">
                <input type="text" class="form-control" name="sCharacterDetails_First_Name" placeholder="First Name" value="%sCharacterDetails_First_Name%"/>
            </div>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="sCharacterDetails_Last_Name" placeholder="Last Name" value="%sCharacterDetails_Last_Name%"/>
            </div>
            <div class="col-sm-4">
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
                <select class="form-control" name="sCharacterDetails_Handedness">
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
                <input type="text" class="form-control" readonly="readonly" value="%sCharacterDetails_Weapon1Left%"/>
            </div>
            <label class="col-sm-2 col-form-label">Weapon 1 Right</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" readonly="readonly" value="%sCharacterDetails_Weapon1Right%"/>
            </div>
            <label class="col-sm-2 col-form-label">Neck</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" readonly="readonly" value="%sCharacterDetails_Neck%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Weapon 2 Left</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" readonly="readonly" value="%sCharacterDetails_Weapon2Left%"/>
            </div>
            <label class="col-sm-2 col-form-label">Weapon 2 Right</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" readonly="readonly" value="%sCharacterDetails_Weapon2Right%"/>
            </div>
            <label class="col-sm-2 col-form-label">Head</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" readonly="readonly" value="%sCharacterDetails_Head%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Left Fingers</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" readonly="readonly" value="%sCharacterDetails_LeftFingers%"/>
            </div>
            <label class="col-sm-2 col-form-label">Right Fingers</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" readonly="readonly" value="%sCharacterDetails_RightFingers%"/>
            </div>
            <label class="col-sm-2 col-form-label">Hands</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" readonly="readonly" value="%sCharacterDetails_Hands%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Feet</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" readonly="readonly" value="%sCharacterDetails_Feet%"/>
            </div>
            <label class="col-sm-2 col-form-label">Legs</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" readonly="readonly" value="%sCharacterDetails_Legs%"/>
            </div>
            <label class="col-sm-2 col-form-label">Chest</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" readonly="readonly" value="%sCharacterDetails_Chest%"/>
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
            <label class="col-sm-2 col-form-label">Available Actions</label>
            <div class="col-sm-10">
                <textarea style="resize: none;" class="form-control" rows="4" readonly="readonly">%sCharacterDetails_AvailableActions%</textarea>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Skill Passive Changes</label>
            <div class="col-sm-10">
                <textarea style="resize: none;" class="form-control" rows="4" readonly="readonly">%sCharacterDetails_SkillPassiveChanges%</textarea>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Item Passive Changes</label>
            <div class="col-sm-10">
                <textarea style="resize: none;" class="form-control" rows="4" readonly="readonly">%sCharacterDetails_ItemPassiveChanges%</textarea>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Skill Active Changes</label>
            <div class="col-sm-10">
                <textarea style="resize: none;" class="form-control" rows="4" readonly="readonly">%sCharacterDetails_SkillActiveChanges%</textarea>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Item Active Changes</label>
            <div class="col-sm-10">
                <textarea style="resize: none;" class="form-control" rows="4" readonly="readonly">%sCharacterDetails_ItemActiveChanges%</textarea>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Skill Actionable Changes</label>
            <div class="col-sm-10">
                <textarea style="resize: none;" class="form-control" rows="4" readonly="readonly">%sCharacterDetails_SkillActionableChanges%</textarea>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Item Actionable Changes</label>
            <div class="col-sm-10">
                <textarea style="resize: none;" class="form-control" rows="4" readonly="readonly">%sCharacterDetails_ItemActionableChanges%</textarea>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Raw Character Json</label>
            <div class="col-sm-10">
                <textarea style="resize: none;" class="form-control" rows="8" readonly="readonly">%sCharacterDetails_RawJson%</textarea>
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

    // Get fields
    String sAction = GetMapDataOrDefault(tParams, "action", "");
    String sLoadCharacterFromJson_Textarea = GetMapDataOrDefault(tParams, "sLoadCharacterFromJson_Textarea", "");
    String sLoadCharacterFromFile_Filename = GetMapDataOrDefault(tParams, "sLoadCharacterFromFile_Filename", "");
    String sLoadCharacterFromFile_FileType = GetMapDataOrDefault(tParams, "sLoadCharacterFromFile_FileType", "");
    String sSaveCharacterToFile_CharID = GetMapDataOrDefault(tParams, "sSaveCharacterToFile_CharID", "");
    String sSaveCharacterToFile_Filename = GetMapDataOrDefault(tParams, "sSaveCharacterToFile_Filename", "");
    String sSaveCharacterToFile_FileType = GetMapDataOrDefault(tParams, "sSaveCharacterToFile_FileType", "");
    String sUnloadCharacter_CharID = GetMapDataOrDefault(tParams, "sUnloadCharacter_CharID", "");
    String sGenerateCharacter_CharID = GetMapDataOrDefault(tParams, "sGenerateCharacter_CharID", "");
    String sGenerateCharacter_Textarea = GetMapDataOrDefault(tParams, "sGenerateCharacter_Textarea", "");
    String sGenerateRandomCharacter_CharID = GetMapDataOrDefault(tParams, "sGenerateRandomCharacter_CharID", "");
    String sCreateCharacter_CharID = GetMapDataOrDefault(tParams, "sCreateCharacter_CharID", "");
    String sDisplayCharacter_CharID = GetMapDataOrDefault(tParams, "sDisplayCharacter_CharID", "");
    String sCharacterDetails_CharID = GetMapDataOrDefault(tParams, "sCharacterDetails_CharID", "");
    String sCharacterDetails_First_Name = GetMapDataOrDefault(tParams, "sCharacterDetails_First_Name", "");
    String sCharacterDetails_Last_Name = GetMapDataOrDefault(tParams, "sCharacterDetails_Last_Name", "");
    String sCharacterDetails_Age = GetMapDataOrDefault(tParams, "sCharacterDetails_Age", "");
    String sCharacterDetails_Gender = GetMapDataOrDefault(tParams, "sCharacterDetails_Gender", "");
    String sCharacterDetails_Hair = GetMapDataOrDefault(tParams, "sCharacterDetails_Hair", "");
    String sCharacterDetails_Eyes = GetMapDataOrDefault(tParams, "sCharacterDetails_Eyes", "");
    String sCharacterDetails_Handedness = GetMapDataOrDefault(tParams, "sCharacterDetails_Handedness", "");
    String sCharacterDetails_PowerSet = GetMapDataOrDefault(tParams, "sCharacterDetails_PowerSet", "");
    String sCharacterDetails_BaseRace = GetMapDataOrDefault(tParams, "sCharacterDetails_BaseRace", "");
    String sCharacterDetails_TransformedRace = GetMapDataOrDefault(tParams, "sCharacterDetails_TransformedRace", "");
    String sCharacterDetails_CurrentWeaponSet = GetMapDataOrDefault(tParams, "sCharacterDetails_CurrentWeaponSet", "");
    String sCharacterDetails_HP_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_HP_Current", "");
    String sCharacterDetails_HP_Max = GetMapDataOrDefault(tParams, "sCharacterDetails_HP_Max", "");
    String sCharacterDetails_HP_Regen = GetMapDataOrDefault(tParams, "sCharacterDetails_HP_Regen", "");
    String sCharacterDetails_HP_Delta = GetMapDataOrDefault(tParams, "sCharacterDetails_HP_Delta", "");
    String sCharacterDetails_MP_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_MP_Current", "");
    String sCharacterDetails_MP_Max = GetMapDataOrDefault(tParams, "sCharacterDetails_MP_Max", "");
    String sCharacterDetails_MP_Regen = GetMapDataOrDefault(tParams, "sCharacterDetails_MP_Regen", "");
    String sCharacterDetails_MP_Delta = GetMapDataOrDefault(tParams, "sCharacterDetails_MP_Delta", "");
    String sCharacterDetails_EP_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_EP_Current", "");
    String sCharacterDetails_EP_Max = GetMapDataOrDefault(tParams, "sCharacterDetails_EP_Max", "");
    String sCharacterDetails_EP_Regen = GetMapDataOrDefault(tParams, "sCharacterDetails_EP_Regen", "");
    String sCharacterDetails_EP_Delta = GetMapDataOrDefault(tParams, "sCharacterDetails_EP_Delta", "");
    String sCharacterDetails_Speed = GetMapDataOrDefault(tParams, "sCharacterDetails_Speed", "");
    String sCharacterDetails_Slash_ActionPoints = GetMapDataOrDefault(tParams, "sCharacterDetails_Slash_ActionPoints", "");
    String sCharacterDetails_Sever_ActionPoints = GetMapDataOrDefault(tParams, "sCharacterDetails_Sever_ActionPoints", "");
    String sCharacterDetails_Slice_ActionPoints = GetMapDataOrDefault(tParams, "sCharacterDetails_Slice_ActionPoints", "");
    String sCharacterDetails_Slit_ActionPoints = GetMapDataOrDefault(tParams, "sCharacterDetails_Slit_ActionPoints", "");
    String sCharacterDetails_Cleave_ActionPoints = GetMapDataOrDefault(tParams, "sCharacterDetails_Cleave_ActionPoints", "");
    String sCharacterDetails_Decapitate_ActionPoints = GetMapDataOrDefault(tParams, "sCharacterDetails_Decapitate_ActionPoints", "");
    String sCharacterDetails_Parry_ActionPoints = GetMapDataOrDefault(tParams, "sCharacterDetails_Parry_ActionPoints", "");
    String sCharacterDetails_Riposte_ActionPoints = GetMapDataOrDefault(tParams, "sCharacterDetails_Riposte_ActionPoints", "");
    String sCharacterDetails_Bash_ActionPoints = GetMapDataOrDefault(tParams, "sCharacterDetails_Bash_ActionPoints", "");
    String sCharacterDetails_Smash_ActionPoints = GetMapDataOrDefault(tParams, "sCharacterDetails_Smash_ActionPoints", "");
    String sCharacterDetails_Crush_ActionPoints = GetMapDataOrDefault(tParams, "sCharacterDetails_Crush_ActionPoints", "");
    String sCharacterDetails_Impact_ActionPoints = GetMapDataOrDefault(tParams, "sCharacterDetails_Impact_ActionPoints", "");
    String sCharacterDetails_Break_ActionPoints = GetMapDataOrDefault(tParams, "sCharacterDetails_Break_ActionPoints", "");
    String sCharacterDetails_Crack_ActionPoints = GetMapDataOrDefault(tParams, "sCharacterDetails_Crack_ActionPoints", "");
    String sCharacterDetails_Block_ActionPoints = GetMapDataOrDefault(tParams, "sCharacterDetails_Block_ActionPoints", "");
    String sCharacterDetails_Rush_ActionPoints = GetMapDataOrDefault(tParams, "sCharacterDetails_Rush_ActionPoints", "");
    String sCharacterDetails_Pierce_ActionPoints = GetMapDataOrDefault(tParams, "sCharacterDetails_Pierce_ActionPoints", "");
    String sCharacterDetails_Drill_ActionPoints = GetMapDataOrDefault(tParams, "sCharacterDetails_Drill_ActionPoints", "");
    String sCharacterDetails_Shoot_ActionPoints = GetMapDataOrDefault(tParams, "sCharacterDetails_Shoot_ActionPoints", "");
    String sCharacterDetails_Impale_ActionPoints = GetMapDataOrDefault(tParams, "sCharacterDetails_Impale_ActionPoints", "");
    String sCharacterDetails_StealthStrike_ActionPoints = GetMapDataOrDefault(tParams, "sCharacterDetails_StealthStrike_ActionPoints", "");
    String sCharacterDetails_CriticalShot_ActionPoints = GetMapDataOrDefault(tParams, "sCharacterDetails_CriticalShot_ActionPoints", "");
    String sCharacterDetails_Dodge_ActionPoints = GetMapDataOrDefault(tParams, "sCharacterDetails_Dodge_ActionPoints", "");
    String sCharacterDetails_Counter_ActionPoints = GetMapDataOrDefault(tParams, "sCharacterDetails_Counter_ActionPoints", "");
    String sCharacterDetails_Blunt_Attack = GetMapDataOrDefault(tParams, "sCharacterDetails_Blunt_Attack", "");
    String sCharacterDetails_Blunt_Defense = GetMapDataOrDefault(tParams, "sCharacterDetails_Blunt_Defense", "");
    String sCharacterDetails_Pierce_Attack = GetMapDataOrDefault(tParams, "sCharacterDetails_Pierce_Attack", "");
    String sCharacterDetails_Pierce_Defense = GetMapDataOrDefault(tParams, "sCharacterDetails_Pierce_Defense", "");
    String sCharacterDetails_Slash_Attack = GetMapDataOrDefault(tParams, "sCharacterDetails_Slash_Attack", "");
    String sCharacterDetails_Slash_Defense = GetMapDataOrDefault(tParams, "sCharacterDetails_Slash_Defense", "");
    String sCharacterDetails_Magic_Attack = GetMapDataOrDefault(tParams, "sCharacterDetails_Magic_Attack", "");
    String sCharacterDetails_Magic_Defense = GetMapDataOrDefault(tParams, "sCharacterDetails_Magic_Defense", "");
    String sCharacterDetails_Energy_Attack = GetMapDataOrDefault(tParams, "sCharacterDetails_Energy_Attack", "");
    String sCharacterDetails_Energy_Defense = GetMapDataOrDefault(tParams, "sCharacterDetails_Energy_Defense", "");
    String sCharacterDetails_Slash_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Slash_Current", "");
    String sCharacterDetails_Slash_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Slash_Rank", "");
    String sCharacterDetails_Sever_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Sever_Current", "");
    String sCharacterDetails_Sever_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Sever_Rank", "");
    String sCharacterDetails_Slice_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Slice_Current", "");
    String sCharacterDetails_Slice_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Slice_Rank", "");
    String sCharacterDetails_Slit_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Slit_Current", "");
    String sCharacterDetails_Slit_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Slit_Rank", "");
    String sCharacterDetails_Cleave_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Cleave_Current", "");
    String sCharacterDetails_Cleave_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Cleave_Rank", "");
    String sCharacterDetails_Decapitate_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Decapitate_Current", "");
    String sCharacterDetails_Decapitate_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Decapitate_Rank", "");
    String sCharacterDetails_Parry_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Parry_Current", "");
    String sCharacterDetails_Parry_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Parry_Rank", "");
    String sCharacterDetails_Riposte_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Riposte_Current", "");
    String sCharacterDetails_Riposte_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Riposte_Rank", "");
    String sCharacterDetails_Bash_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Bash_Current", "");
    String sCharacterDetails_Bash_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Bash_Rank", "");
    String sCharacterDetails_Smash_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Smash_Current", "");
    String sCharacterDetails_Smash_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Smash_Rank", "");
    String sCharacterDetails_Crush_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Crush_Current", "");
    String sCharacterDetails_Crush_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Crush_Rank", "");
    String sCharacterDetails_Impact_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Impact_Current", "");
    String sCharacterDetails_Impact_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Impact_Rank", "");
    String sCharacterDetails_Break_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Break_Current", "");
    String sCharacterDetails_Break_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Break_Rank", "");
    String sCharacterDetails_Crack_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Crack_Current", "");
    String sCharacterDetails_Crack_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Crack_Rank", "");
    String sCharacterDetails_Block_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Block_Current", "");
    String sCharacterDetails_Block_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Block_Rank", "");
    String sCharacterDetails_Rush_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Rush_Current", "");
    String sCharacterDetails_Rush_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Rush_Rank", "");
    String sCharacterDetails_Pierce_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Pierce_Current", "");
    String sCharacterDetails_Pierce_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Pierce_Rank", "");
    String sCharacterDetails_Drill_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Drill_Current", "");
    String sCharacterDetails_Drill_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Drill_Rank", "");
    String sCharacterDetails_Shoot_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Shoot_Current", "");
    String sCharacterDetails_Shoot_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Shoot_Rank", "");
    String sCharacterDetails_Impale_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Impale_Current", "");
    String sCharacterDetails_Impale_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Impale_Rank", "");
    String sCharacterDetails_StealthStrike_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_StealthStrike_Current", "");
    String sCharacterDetails_StealthStrike_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_StealthStrike_Rank", "");
    String sCharacterDetails_CriticalShot_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_CriticalShot_Current", "");
    String sCharacterDetails_CriticalShot_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_CriticalShot_Rank", "");
    String sCharacterDetails_Dodge_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Dodge_Current", "");
    String sCharacterDetails_Dodge_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Dodge_Rank", "");
    String sCharacterDetails_Counter_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Counter_Current", "");
    String sCharacterDetails_Counter_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Counter_Rank", "");
    String sCharacterDetails_Barbarian_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Barbarian_Current", "");
    String sCharacterDetails_Barbarian_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Barbarian_Rank", "");
    String sCharacterDetails_Mage_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Mage_Current", "");
    String sCharacterDetails_Mage_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Mage_Rank", "");
    String sCharacterDetails_Rogue_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Rogue_Current", "");
    String sCharacterDetails_Rogue_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Rogue_Rank", "");
    String sCharacterDetails_Blademaster_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Blademaster_Current", "");
    String sCharacterDetails_Blademaster_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Blademaster_Rank", "");
    String sCharacterDetails_Avatar_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Avatar_Current", "");
    String sCharacterDetails_Avatar_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Avatar_Rank", "");
    String sCharacterDetails_Ambidext_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Ambidext_Current", "");
    String sCharacterDetails_Ambidext_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Ambidext_Rank", "");
    String sCharacterDetails_Focused_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Focused_Current", "");
    String sCharacterDetails_Focused_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Focused_Rank", "");
    String sCharacterDetails_Stalwart_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Stalwart_Current", "");
    String sCharacterDetails_Stalwart_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Stalwart_Rank", "");
    String sCharacterDetails_Healer_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Healer_Current", "");
    String sCharacterDetails_Healer_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Healer_Rank", "");
    String sCharacterDetails_Alchemist_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Alchemist_Current", "");
    String sCharacterDetails_Alchemist_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Alchemist_Rank", "");
    String sCharacterDetails_Energist_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Energist_Current", "");
    String sCharacterDetails_Energist_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Energist_Rank", "");
    String sCharacterDetails_Chemist_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Chemist_Current", "");
    String sCharacterDetails_Chemist_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Chemist_Rank", "");
    String sCharacterDetails_Hammersmith_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Hammersmith_Current", "");
    String sCharacterDetails_Hammersmith_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Hammersmith_Rank", "");
    String sCharacterDetails_Spellsmith_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Spellsmith_Current", "");
    String sCharacterDetails_Spellsmith_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Spellsmith_Rank", "");
    String sCharacterDetails_Bowsmith_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Bowsmith_Current", "");
    String sCharacterDetails_Bowsmith_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Bowsmith_Rank", "");
    String sCharacterDetails_Swordsmith_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Swordsmith_Current", "");
    String sCharacterDetails_Swordsmith_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Swordsmith_Rank", "");
    String sCharacterDetails_Weaver_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Weaver_Current", "");
    String sCharacterDetails_Weaver_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Weaver_Rank", "");
    String sCharacterDetails_Tanner_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Tanner_Current", "");
    String sCharacterDetails_Tanner_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Tanner_Rank", "");
    String sCharacterDetails_Scalesmith_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Scalesmith_Current", "");
    String sCharacterDetails_Scalesmith_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Scalesmith_Rank", "");
    String sCharacterDetails_Platesmith_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Platesmith_Current", "");
    String sCharacterDetails_Platesmith_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Platesmith_Rank", "");
    String sCharacterDetails_Goldsmith_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Goldsmith_Current", "");
    String sCharacterDetails_Goldsmith_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Goldsmith_Rank", "");
    String sCharacterDetails_Shieldsmith_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Shieldsmith_Current", "");
    String sCharacterDetails_Shieldsmith_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Shieldsmith_Rank", "");
    String sCharacterDetails_Hammerbane_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Hammerbane_Current", "");
    String sCharacterDetails_Hammerbane_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Hammerbane_Rank", "");
    String sCharacterDetails_Spellbane_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Spellbane_Current", "");
    String sCharacterDetails_Spellbane_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Spellbane_Rank", "");
    String sCharacterDetails_Bowbane_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Bowbane_Current", "");
    String sCharacterDetails_Bowbane_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Bowbane_Rank", "");
    String sCharacterDetails_Swordbane_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Swordbane_Current", "");
    String sCharacterDetails_Swordbane_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Swordbane_Rank", "");
    String sCharacterDetails_Threadbare_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Threadbare_Current", "");
    String sCharacterDetails_Threadbare_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Threadbare_Rank", "");
    String sCharacterDetails_Studremover_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Studremover_Current", "");
    String sCharacterDetails_Studremover_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Studremover_Rank", "");
    String sCharacterDetails_Scalebane_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Scalebane_Current", "");
    String sCharacterDetails_Scalebane_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Scalebane_Rank", "");
    String sCharacterDetails_Platebane_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Platebane_Current", "");
    String sCharacterDetails_Platebane_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Platebane_Rank", "");
    String sCharacterDetails_Goldbane_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Goldbane_Current", "");
    String sCharacterDetails_Goldbane_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Goldbane_Rank", "");
    String sCharacterDetails_Shieldbane_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Shieldbane_Current", "");
    String sCharacterDetails_Shieldbane_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Shieldbane_Rank", "");
    String sCharacterDetails_Holy_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Holy_Current", "");
    String sCharacterDetails_Holy_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Holy_Rank", "");
    String sCharacterDetails_Fire_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Fire_Current", "");
    String sCharacterDetails_Fire_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Fire_Rank", "");
    String sCharacterDetails_Ice_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Ice_Current", "");
    String sCharacterDetails_Ice_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Ice_Rank", "");
    String sCharacterDetails_Shock_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Shock_Current", "");
    String sCharacterDetails_Shock_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Shock_Rank", "");
    String sCharacterDetails_Dark_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Dark_Current", "");
    String sCharacterDetails_Dark_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Dark_Rank", "");
    String sCharacterDetails_Light_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Light_Current", "");
    String sCharacterDetails_Light_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Light_Rank", "");
    String sCharacterDetails_Force_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Force_Current", "");
    String sCharacterDetails_Force_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Force_Rank", "");
    String sCharacterDetails_Mind_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Mind_Current", "");
    String sCharacterDetails_Mind_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Mind_Rank", "");
    String sCharacterDetails_Earth_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Earth_Current", "");
    String sCharacterDetails_Earth_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Earth_Rank", "");
    String sCharacterDetails_Blood_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Blood_Current", "");
    String sCharacterDetails_Blood_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Blood_Rank", "");
    String sCharacterDetails_Flesh_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Flesh_Current", "");
    String sCharacterDetails_Flesh_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Flesh_Rank", "");
    String sCharacterDetails_Wind_Current = GetMapDataOrDefault(tParams, "sCharacterDetails_Wind_Current", "");
    String sCharacterDetails_Wind_Rank = GetMapDataOrDefault(tParams, "sCharacterDetails_Wind_Rank", "");

    // Character details
    String sCharacterDetails_PartyID;
    String sCharacterDetails_CharTargetType;
    String sCharacterDetails_Chest;
    String sCharacterDetails_Feet;
    String sCharacterDetails_Hands;
    String sCharacterDetails_Head;
    String sCharacterDetails_Legs;
    String sCharacterDetails_Neck;
    String sCharacterDetails_LeftFingers;
    String sCharacterDetails_RightFingers;
    String sCharacterDetails_Weapon1Left;
    String sCharacterDetails_Weapon1Right;
    String sCharacterDetails_Weapon2Left;
    String sCharacterDetails_Weapon2Right;
    String sCharacterDetails_AvailableActions;
    String sCharacterDetails_SkillPassiveChanges;
    String sCharacterDetails_ItemPassiveChanges;
    String sCharacterDetails_SkillActiveChanges;
    String sCharacterDetails_ItemActiveChanges;
    String sCharacterDetails_SkillActionableChanges;
    String sCharacterDetails_ItemActionableChanges;
    String sCharacterDetails_RawJson;

    // Character to display
    String sCharacterToDisplay;

    // Check action
    if(sAction == "load_character_from_json")
    {
        CharacterManager::GetInstance()->LoadCharacter(
            Character(sLoadCharacterFromJson_Textarea)
        );
    }
    else if(sAction == "load_character_from_file")
    {
        CharacterManager::GetInstance()->LoadCharacterFromFile(
            sLoadCharacterFromFile_Filename,
            sLoadCharacterFromFile_FileType
        );
    }
    else if(sAction == "save_character_to_file")
    {
        CharacterManager::GetInstance()->SaveCharacterToFile(
            sSaveCharacterToFile_CharID,
            sSaveCharacterToFile_Filename,
            sSaveCharacterToFile_FileType
        );
        sCharacterToDisplay = sSaveCharacterToFile_CharID;
    }
    else if(sAction == "unload_character")
    {
        CharacterManager::GetInstance()->UnloadCharacter(
            sUnloadCharacter_CharID
        );
        sCharacterToDisplay = sUnloadCharacter_CharID;
    }
    else if(sAction == "generate_character")
    {
        CharacterManager::GetInstance()->GenerateCharacter(
            sGenerateCharacter_CharID,
            CharacterGenerator(sGenerateCharacter_Textarea)
        );
        sCharacterToDisplay = sGenerateCharacter_CharID;
    }
    else if(sAction == "generate_random_character")
    {
        CharacterGenerator generator;
        generator.RandomizeAll();
        CharacterManager::GetInstance()->GenerateCharacter(
            sGenerateRandomCharacter_CharID,
            generator
        );
        sCharacterToDisplay = sGenerateRandomCharacter_CharID;
    }
    else if(sAction == "create_character")
    {
        CharacterManager::GetInstance()->CreateCharacter(
            sCreateCharacter_CharID
        );
        sCharacterToDisplay = sCreateCharacter_CharID;
    }
    else if(sAction == "display_character")
    {
        sCharacterToDisplay = sDisplayCharacter_CharID;
    }
    else if(sAction == "save_character")
    {
        Character& character = CharacterManager::GetInstance()->GetCharacter(sCharacterDetails_CharID);
        CharacterBasicData& basicData = character.GetBasicData();
        basicData.SetFirstName(sCharacterDetails_First_Name);
        basicData.SetLastName(sCharacterDetails_Last_Name);
        basicData.SetGender(sCharacterDetails_Gender);
        basicData.SetHair(sCharacterDetails_Hair);
        basicData.SetEyes(sCharacterDetails_Eyes);
        basicData.SetHandedness(sCharacterDetails_Handedness);
        basicData.SetBaseRace(sCharacterDetails_BaseRace);
        basicData.SetTransformedRace(sCharacterDetails_TransformedRace);
        basicData.SetPowerSet(sCharacterDetails_PowerSet);
        basicData.SetAge(BoostLexicalCast<Int>(sCharacterDetails_Age));
        CharacterProgressData& progressData = character.GetProgressDataBase();
        progressData.SetHealthPointsCurrent(BoostLexicalCast<Int>(sCharacterDetails_HP_Current));
        progressData.SetMagicPointsCurrent(BoostLexicalCast<Int>(sCharacterDetails_MP_Current));
        progressData.SetEnergyPointsCurrent(BoostLexicalCast<Int>(sCharacterDetails_EP_Current));
        progressData.SetHealthPointsMax(BoostLexicalCast<Int>(sCharacterDetails_HP_Max));
        progressData.SetMagicPointsMax(BoostLexicalCast<Int>(sCharacterDetails_MP_Max));
        progressData.SetEnergyPointsMax(BoostLexicalCast<Int>(sCharacterDetails_EP_Max));
        progressData.SetHealthRegen(BoostLexicalCast<Int>(sCharacterDetails_HP_Regen));
        progressData.SetMagicRegen(BoostLexicalCast<Int>(sCharacterDetails_MP_Regen));
        progressData.SetEnergyRegen(BoostLexicalCast<Int>(sCharacterDetails_EP_Regen));
        progressData.SetHealthCostDelta(BoostLexicalCast<Int>(sCharacterDetails_HP_Delta));
        progressData.SetMagicCostDelta(BoostLexicalCast<Int>(sCharacterDetails_MP_Delta));
        progressData.SetEnergyCostDelta(BoostLexicalCast<Int>(sCharacterDetails_EP_Delta));
        progressData.SetSpeed(BoostLexicalCast<Int>(sCharacterDetails_Speed));
        progressData.SetBluntAttack(BoostLexicalCast<Int>(sCharacterDetails_Blunt_Attack));
        progressData.SetBluntDefense(BoostLexicalCast<Int>(sCharacterDetails_Blunt_Defense));
        progressData.SetMagicAttack(BoostLexicalCast<Int>(sCharacterDetails_Magic_Attack));
        progressData.SetMagicDefense(BoostLexicalCast<Int>(sCharacterDetails_Magic_Defense));
        progressData.SetPierceAttack(BoostLexicalCast<Int>(sCharacterDetails_Pierce_Attack));
        progressData.SetPierceDefense(BoostLexicalCast<Int>(sCharacterDetails_Pierce_Defense));
        progressData.SetSlashAttack(BoostLexicalCast<Int>(sCharacterDetails_Slash_Attack));
        progressData.SetSlashDefense(BoostLexicalCast<Int>(sCharacterDetails_Slash_Defense));
        progressData.SetEnergyAttack(BoostLexicalCast<Int>(sCharacterDetails_Energy_Attack));
        progressData.SetEnergyDefense(BoostLexicalCast<Int>(sCharacterDetails_Energy_Defense));
        progressData.SetSlashPoints(BoostLexicalCast<Int>(sCharacterDetails_Slash_ActionPoints));
        progressData.SetSeverPoints(BoostLexicalCast<Int>(sCharacterDetails_Sever_ActionPoints));
        progressData.SetSlicePoints(BoostLexicalCast<Int>(sCharacterDetails_Slice_ActionPoints));
        progressData.SetSlitPoints(BoostLexicalCast<Int>(sCharacterDetails_Slit_ActionPoints));
        progressData.SetCleavePoints(BoostLexicalCast<Int>(sCharacterDetails_Cleave_ActionPoints));
        progressData.SetDecapitatePoints(BoostLexicalCast<Int>(sCharacterDetails_Decapitate_ActionPoints));
        progressData.SetParryPoints(BoostLexicalCast<Int>(sCharacterDetails_Parry_ActionPoints));
        progressData.SetRipostePoints(BoostLexicalCast<Int>(sCharacterDetails_Riposte_ActionPoints));
        progressData.SetBashPoints(BoostLexicalCast<Int>(sCharacterDetails_Bash_ActionPoints));
        progressData.SetSmashPoints(BoostLexicalCast<Int>(sCharacterDetails_Smash_ActionPoints));
        progressData.SetImpactPoints(BoostLexicalCast<Int>(sCharacterDetails_Impact_ActionPoints));
        progressData.SetCrushPoints(BoostLexicalCast<Int>(sCharacterDetails_Crush_ActionPoints));
        progressData.SetBreakPoints(BoostLexicalCast<Int>(sCharacterDetails_Break_ActionPoints));
        progressData.SetCrackPoints(BoostLexicalCast<Int>(sCharacterDetails_Crack_ActionPoints));
        progressData.SetBlockPoints(BoostLexicalCast<Int>(sCharacterDetails_Block_ActionPoints));
        progressData.SetRushPoints(BoostLexicalCast<Int>(sCharacterDetails_Rush_ActionPoints));
        progressData.SetPiercePoints(BoostLexicalCast<Int>(sCharacterDetails_Pierce_ActionPoints));
        progressData.SetDrillPoints(BoostLexicalCast<Int>(sCharacterDetails_Drill_ActionPoints));
        progressData.SetShootPoints(BoostLexicalCast<Int>(sCharacterDetails_Shoot_ActionPoints));
        progressData.SetImpalePoints(BoostLexicalCast<Int>(sCharacterDetails_Impale_ActionPoints));
        progressData.SetStealthStrikePoints(BoostLexicalCast<Int>(sCharacterDetails_StealthStrike_ActionPoints));
        progressData.SetCriticalShotPoints(BoostLexicalCast<Int>(sCharacterDetails_CriticalShot_ActionPoints));
        progressData.SetDodgePoints(BoostLexicalCast<Int>(sCharacterDetails_Dodge_ActionPoints));
        progressData.SetCounterPoints(BoostLexicalCast<Int>(sCharacterDetails_Counter_ActionPoints));
        CharacterSkillData& skillData = character.GetSkillData();
        skillData.SetBarbarianCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Barbarian_Current));
        skillData.SetBarbarianRank(BoostLexicalCast<UByte>(sCharacterDetails_Barbarian_Rank));
        skillData.SetMageCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Mage_Current));
        skillData.SetMageRank(BoostLexicalCast<UByte>(sCharacterDetails_Mage_Rank));
        skillData.SetRogueCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Rogue_Current));
        skillData.SetRogueRank(BoostLexicalCast<UByte>(sCharacterDetails_Rogue_Rank));
        skillData.SetBlademasterCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Blademaster_Current));
        skillData.SetBlademasterRank(BoostLexicalCast<UByte>(sCharacterDetails_Blademaster_Rank));
        skillData.SetAvatarCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Avatar_Current));
        skillData.SetAvatarRank(BoostLexicalCast<UByte>(sCharacterDetails_Avatar_Rank));
        skillData.SetAmbidextrousCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Ambidext_Current));
        skillData.SetAmbidextrousRank(BoostLexicalCast<UByte>(sCharacterDetails_Ambidext_Rank));
        skillData.SetFocusedCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Focused_Current));
        skillData.SetFocusedRank(BoostLexicalCast<UByte>(sCharacterDetails_Focused_Rank));
        skillData.SetStalwartCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Stalwart_Current));
        skillData.SetStalwartRank(BoostLexicalCast<UByte>(sCharacterDetails_Stalwart_Rank));
        skillData.SetSlashCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Slash_Current));
        skillData.SetSlashRank(BoostLexicalCast<UByte>(sCharacterDetails_Slash_Rank));
        skillData.SetSeverCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Sever_Current));
        skillData.SetSeverRank(BoostLexicalCast<UByte>(sCharacterDetails_Sever_Rank));
        skillData.SetSliceCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Slice_Current));
        skillData.SetSliceRank(BoostLexicalCast<UByte>(sCharacterDetails_Slice_Rank));
        skillData.SetSlitCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Slit_Current));
        skillData.SetSlitRank(BoostLexicalCast<UByte>(sCharacterDetails_Slit_Rank));
        skillData.SetCleaveCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Cleave_Current));
        skillData.SetCleaveRank(BoostLexicalCast<UByte>(sCharacterDetails_Cleave_Rank));
        skillData.SetDecapitateCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Decapitate_Current));
        skillData.SetDecapitateRank(BoostLexicalCast<UByte>(sCharacterDetails_Decapitate_Rank));
        skillData.SetParryCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Parry_Current));
        skillData.SetParryRank(BoostLexicalCast<UByte>(sCharacterDetails_Parry_Rank));
        skillData.SetRiposteCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Riposte_Current));
        skillData.SetRiposteRank(BoostLexicalCast<UByte>(sCharacterDetails_Riposte_Rank));
        skillData.SetBashCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Bash_Current));
        skillData.SetBashRank(BoostLexicalCast<UByte>(sCharacterDetails_Bash_Rank));
        skillData.SetSmashCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Smash_Current));
        skillData.SetSmashRank(BoostLexicalCast<UByte>(sCharacterDetails_Smash_Rank));
        skillData.SetCrushCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Crush_Current));
        skillData.SetCrushRank(BoostLexicalCast<UByte>(sCharacterDetails_Crush_Rank));
        skillData.SetImpactCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Impact_Current));
        skillData.SetImpactRank(BoostLexicalCast<UByte>(sCharacterDetails_Impact_Rank));
        skillData.SetBreakCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Break_Current));
        skillData.SetBreakRank(BoostLexicalCast<UByte>(sCharacterDetails_Break_Rank));
        skillData.SetCrackCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Crack_Current));
        skillData.SetCrackRank(BoostLexicalCast<UByte>(sCharacterDetails_Crack_Rank));
        skillData.SetBlockCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Block_Current));
        skillData.SetBlockRank(BoostLexicalCast<UByte>(sCharacterDetails_Block_Rank));
        skillData.SetRushCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Rush_Current));
        skillData.SetRushRank(BoostLexicalCast<UByte>(sCharacterDetails_Rush_Rank));
        skillData.SetPierceCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Pierce_Current));
        skillData.SetPierceRank(BoostLexicalCast<UByte>(sCharacterDetails_Pierce_Rank));
        skillData.SetDrillCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Drill_Current));
        skillData.SetDrillRank(BoostLexicalCast<UByte>(sCharacterDetails_Drill_Rank));
        skillData.SetShootCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Shoot_Current));
        skillData.SetShootRank(BoostLexicalCast<UByte>(sCharacterDetails_Shoot_Rank));
        skillData.SetImpaleCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Impale_Current));
        skillData.SetImpaleRank(BoostLexicalCast<UByte>(sCharacterDetails_Impale_Rank));
        skillData.SetStealthStrikeCurrent(BoostLexicalCast<UByte>(sCharacterDetails_StealthStrike_Current));
        skillData.SetStealthStrikeRank(BoostLexicalCast<UByte>(sCharacterDetails_StealthStrike_Rank));
        skillData.SetCriticalShotCurrent(BoostLexicalCast<UByte>(sCharacterDetails_CriticalShot_Current));
        skillData.SetCriticalShotRank(BoostLexicalCast<UByte>(sCharacterDetails_CriticalShot_Rank));
        skillData.SetDodgeCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Dodge_Current));
        skillData.SetDodgeRank(BoostLexicalCast<UByte>(sCharacterDetails_Dodge_Rank));
        skillData.SetCounterCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Counter_Current));
        skillData.SetCounterRank(BoostLexicalCast<UByte>(sCharacterDetails_Counter_Rank));
        skillData.SetHealerCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Healer_Current));
        skillData.SetHealerRank(BoostLexicalCast<UByte>(sCharacterDetails_Healer_Rank));
        skillData.SetAlchemistCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Alchemist_Current));
        skillData.SetAlchemistRank(BoostLexicalCast<UByte>(sCharacterDetails_Alchemist_Rank));
        skillData.SetEnergistCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Energist_Current));
        skillData.SetEnergistRank(BoostLexicalCast<UByte>(sCharacterDetails_Energist_Rank));
        skillData.SetChemistCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Chemist_Current));
        skillData.SetChemistRank(BoostLexicalCast<UByte>(sCharacterDetails_Chemist_Rank));
        skillData.SetHammersmithCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Hammersmith_Current));
        skillData.SetHammersmithRank(BoostLexicalCast<UByte>(sCharacterDetails_Hammersmith_Rank));
        skillData.SetSpellsmithCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Spellsmith_Current));
        skillData.SetSpellsmithRank(BoostLexicalCast<UByte>(sCharacterDetails_Spellsmith_Rank));
        skillData.SetBowsmithCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Bowsmith_Current));
        skillData.SetBowsmithRank(BoostLexicalCast<UByte>(sCharacterDetails_Bowsmith_Rank));
        skillData.SetSwordsmithCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Swordsmith_Current));
        skillData.SetSwordsmithRank(BoostLexicalCast<UByte>(sCharacterDetails_Swordsmith_Rank));
        skillData.SetWeaverCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Weaver_Current));
        skillData.SetWeaverRank(BoostLexicalCast<UByte>(sCharacterDetails_Weaver_Rank));
        skillData.SetTannerCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Tanner_Current));
        skillData.SetTannerRank(BoostLexicalCast<UByte>(sCharacterDetails_Tanner_Rank));
        skillData.SetScalesmithCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Scalesmith_Current));
        skillData.SetScalesmithRank(BoostLexicalCast<UByte>(sCharacterDetails_Scalesmith_Rank));
        skillData.SetPlatesmithCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Platesmith_Current));
        skillData.SetPlatesmithRank(BoostLexicalCast<UByte>(sCharacterDetails_Platesmith_Rank));
        skillData.SetGoldsmithCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Goldsmith_Current));
        skillData.SetGoldsmithRank(BoostLexicalCast<UByte>(sCharacterDetails_Goldsmith_Rank));
        skillData.SetShieldsmithCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Shieldsmith_Current));
        skillData.SetShieldsmithRank(BoostLexicalCast<UByte>(sCharacterDetails_Shieldsmith_Rank));
        skillData.SetHammerbaneCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Hammerbane_Current));
        skillData.SetHammerbaneRank(BoostLexicalCast<UByte>(sCharacterDetails_Hammerbane_Rank));
        skillData.SetSpellbaneCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Spellbane_Current));
        skillData.SetSpellbaneRank(BoostLexicalCast<UByte>(sCharacterDetails_Spellbane_Rank));
        skillData.SetBowbaneCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Bowbane_Current));
        skillData.SetBowbaneRank(BoostLexicalCast<UByte>(sCharacterDetails_Bowbane_Rank));
        skillData.SetSwordbaneCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Swordbane_Current));
        skillData.SetSwordbaneRank(BoostLexicalCast<UByte>(sCharacterDetails_Swordbane_Rank));
        skillData.SetThreadbareCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Threadbare_Current));
        skillData.SetThreadbareRank(BoostLexicalCast<UByte>(sCharacterDetails_Threadbare_Rank));
        skillData.SetStudRemoverCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Studremover_Current));
        skillData.SetStudRemoverRank(BoostLexicalCast<UByte>(sCharacterDetails_Studremover_Rank));
        skillData.SetScalebaneCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Scalebane_Current));
        skillData.SetScalebaneRank(BoostLexicalCast<UByte>(sCharacterDetails_Scalebane_Rank));
        skillData.SetPlatebaneCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Platebane_Current));
        skillData.SetPlatebaneRank(BoostLexicalCast<UByte>(sCharacterDetails_Platebane_Rank));
        skillData.SetGoldbaneCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Goldbane_Current));
        skillData.SetGoldbaneRank(BoostLexicalCast<UByte>(sCharacterDetails_Goldbane_Rank));
        skillData.SetShieldbaneCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Shieldbane_Current));
        skillData.SetShieldbaneRank(BoostLexicalCast<UByte>(sCharacterDetails_Shieldbane_Rank));
        skillData.SetHolyCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Holy_Current));
        skillData.SetHolyRank(BoostLexicalCast<UByte>(sCharacterDetails_Holy_Rank));
        skillData.SetFireCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Fire_Current));
        skillData.SetFireRank(BoostLexicalCast<UByte>(sCharacterDetails_Fire_Rank));
        skillData.SetIceCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Ice_Current));
        skillData.SetIceRank(BoostLexicalCast<UByte>(sCharacterDetails_Ice_Rank));
        skillData.SetShockCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Shock_Current));
        skillData.SetShockRank(BoostLexicalCast<UByte>(sCharacterDetails_Shock_Rank));
        skillData.SetDarkCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Dark_Current));
        skillData.SetDarkRank(BoostLexicalCast<UByte>(sCharacterDetails_Dark_Rank));
        skillData.SetLightCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Light_Current));
        skillData.SetLightRank(BoostLexicalCast<UByte>(sCharacterDetails_Light_Rank));
        skillData.SetForceCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Force_Current));
        skillData.SetForceRank(BoostLexicalCast<UByte>(sCharacterDetails_Force_Rank));
        skillData.SetMindCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Mind_Current));
        skillData.SetMindRank(BoostLexicalCast<UByte>(sCharacterDetails_Mind_Rank));
        skillData.SetEarthCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Earth_Current));
        skillData.SetEarthRank(BoostLexicalCast<UByte>(sCharacterDetails_Earth_Rank));
        skillData.SetBloodCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Blood_Current));
        skillData.SetBloodRank(BoostLexicalCast<UByte>(sCharacterDetails_Blood_Rank));
        skillData.SetFleshCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Flesh_Current));
        skillData.SetFleshRank(BoostLexicalCast<UByte>(sCharacterDetails_Flesh_Rank));
        skillData.SetWindCurrent(BoostLexicalCast<UByte>(sCharacterDetails_Wind_Current));
        skillData.SetWindRank(BoostLexicalCast<UByte>(sCharacterDetails_Wind_Rank));
        character.RegenerateCharacterData();
        sCharacterToDisplay = sCharacterDetails_CharID;
    }

    // Get all character IDs
    String sAllCharacterIDs = ConcatStringVector(CharacterManager::GetInstance()->GetAllCharacterIDs());

    // Display character
    if(!sCharacterToDisplay.empty())
    {
        const String sSkillTreeIndexType = (+CharacterTreeIndexType::Skill)._to_string();
        const String sItemTreeIndexType = (+CharacterTreeIndexType::Item)._to_string();
        const Character& character = CharacterManager::GetInstance()->GetCharacter(sCharacterToDisplay);
        sCharacterDetails_Chest = character.GetEquippedChestItem().GetLeaf();
        sCharacterDetails_Feet = character.GetEquippedFeetItem().GetLeaf();
        sCharacterDetails_Hands = character.GetEquippedHandsItem().GetLeaf();
        sCharacterDetails_Head = character.GetEquippedHeadItem().GetLeaf();
        sCharacterDetails_Legs = character.GetEquippedLegsItem().GetLeaf();
        sCharacterDetails_Neck = character.GetEquippedNeckItem().GetLeaf();
        sCharacterDetails_LeftFingers = character.GetEquippedLeftFingersItem().GetLeaf();
        sCharacterDetails_RightFingers = character.GetEquippedRightFingersItem().GetLeaf();
        sCharacterDetails_Weapon1Left = character.GetEquippedWeapon1LeftItem().GetLeaf();
        sCharacterDetails_Weapon1Right = character.GetEquippedWeapon1RightItem().GetLeaf();
        sCharacterDetails_Weapon2Left = character.GetEquippedWeapon2LeftItem().GetLeaf();
        sCharacterDetails_Weapon2Right = character.GetEquippedWeapon2RightItem().GetLeaf();
        const CharacterBasicData& basicData = character.GetBasicData();
        sCharacterDetails_First_Name = basicData.GetFirstName();
        sCharacterDetails_Last_Name = basicData.GetLastName();
        sCharacterDetails_Gender = basicData.GetGender();
        sCharacterDetails_Hair = basicData.GetHair();
        sCharacterDetails_Eyes = basicData.GetEyes();
        sCharacterDetails_Handedness = basicData.GetHandedness();
        sCharacterDetails_BaseRace = basicData.GetBaseRace();
        sCharacterDetails_TransformedRace = basicData.GetTransformedRace();
        sCharacterDetails_PowerSet = basicData.GetPowerSet();
        sCharacterDetails_Age = STDToString(basicData.GetAge());
        const CharacterProgressData& progressData = character.GetProgressDataBase();
        sCharacterDetails_HP_Current = STDToString(progressData.GetHealthPointsCurrent());
        sCharacterDetails_MP_Current = STDToString(progressData.GetMagicPointsCurrent());
        sCharacterDetails_EP_Current = STDToString(progressData.GetEnergyPointsCurrent());
        sCharacterDetails_HP_Max = STDToString(progressData.GetHealthPointsMax());
        sCharacterDetails_MP_Max = STDToString(progressData.GetMagicPointsMax());
        sCharacterDetails_EP_Max = STDToString(progressData.GetEnergyPointsMax());
        sCharacterDetails_HP_Regen = STDToString(progressData.GetHealthRegen());
        sCharacterDetails_MP_Regen = STDToString(progressData.GetMagicRegen());
        sCharacterDetails_EP_Regen = STDToString(progressData.GetEnergyRegen());
        sCharacterDetails_HP_Delta = STDToString(progressData.GetHealthCostDelta());
        sCharacterDetails_MP_Delta = STDToString(progressData.GetMagicCostDelta());
        sCharacterDetails_EP_Delta = STDToString(progressData.GetEnergyCostDelta());
        sCharacterDetails_Speed = STDToString(progressData.GetSpeed());
        sCharacterDetails_Blunt_Attack = STDToString(progressData.GetBluntAttack());
        sCharacterDetails_Blunt_Defense = STDToString(progressData.GetBluntDefense());
        sCharacterDetails_Magic_Attack = STDToString(progressData.GetMagicAttack());
        sCharacterDetails_Magic_Defense = STDToString(progressData.GetMagicDefense());
        sCharacterDetails_Pierce_Attack = STDToString(progressData.GetPierceAttack());
        sCharacterDetails_Pierce_Defense = STDToString(progressData.GetPierceDefense());
        sCharacterDetails_Slash_Attack = STDToString(progressData.GetSlashAttack());
        sCharacterDetails_Slash_Defense = STDToString(progressData.GetSlashDefense());
        sCharacterDetails_Energy_Attack = STDToString(progressData.GetEnergyAttack());
        sCharacterDetails_Energy_Defense = STDToString(progressData.GetEnergyDefense());
        sCharacterDetails_Slash_ActionPoints = STDToString(progressData.GetSlashPoints());
        sCharacterDetails_Sever_ActionPoints = STDToString(progressData.GetSeverPoints());
        sCharacterDetails_Slice_ActionPoints = STDToString(progressData.GetSlicePoints());
        sCharacterDetails_Slit_ActionPoints = STDToString(progressData.GetSlitPoints());
        sCharacterDetails_Cleave_ActionPoints = STDToString(progressData.GetCleavePoints());
        sCharacterDetails_Decapitate_ActionPoints = STDToString(progressData.GetDecapitatePoints());
        sCharacterDetails_Parry_ActionPoints = STDToString(progressData.GetParryPoints());
        sCharacterDetails_Riposte_ActionPoints = STDToString(progressData.GetRipostePoints());
        sCharacterDetails_Bash_ActionPoints = STDToString(progressData.GetBashPoints());
        sCharacterDetails_Smash_ActionPoints = STDToString(progressData.GetSmashPoints());
        sCharacterDetails_Impact_ActionPoints = STDToString(progressData.GetImpactPoints());
        sCharacterDetails_Crush_ActionPoints = STDToString(progressData.GetCrushPoints());
        sCharacterDetails_Break_ActionPoints = STDToString(progressData.GetBreakPoints());
        sCharacterDetails_Crack_ActionPoints = STDToString(progressData.GetCrackPoints());
        sCharacterDetails_Block_ActionPoints = STDToString(progressData.GetBlockPoints());
        sCharacterDetails_Rush_ActionPoints = STDToString(progressData.GetRushPoints());
        sCharacterDetails_Pierce_ActionPoints = STDToString(progressData.GetPiercePoints());
        sCharacterDetails_Drill_ActionPoints = STDToString(progressData.GetDrillPoints());
        sCharacterDetails_Shoot_ActionPoints = STDToString(progressData.GetShootPoints());
        sCharacterDetails_Impale_ActionPoints = STDToString(progressData.GetImpalePoints());
        sCharacterDetails_StealthStrike_ActionPoints = STDToString(progressData.GetStealthStrikePoints());
        sCharacterDetails_CriticalShot_ActionPoints = STDToString(progressData.GetCriticalShotPoints());
        sCharacterDetails_Dodge_ActionPoints = STDToString(progressData.GetDodgePoints());
        sCharacterDetails_Counter_ActionPoints = STDToString(progressData.GetCounterPoints());
        const CharacterSkillData& skillData = character.GetSkillData();
        sCharacterDetails_Barbarian_Current = STDToString(skillData.GetBarbarianCurrent());
        sCharacterDetails_Barbarian_Rank = STDToString(skillData.GetBarbarianRank());
        sCharacterDetails_Mage_Current = STDToString(skillData.GetMageCurrent());
        sCharacterDetails_Mage_Rank = STDToString(skillData.GetMageRank());
        sCharacterDetails_Rogue_Current = STDToString(skillData.GetRogueCurrent());
        sCharacterDetails_Rogue_Rank = STDToString(skillData.GetRogueRank());
        sCharacterDetails_Blademaster_Current = STDToString(skillData.GetBlademasterCurrent());
        sCharacterDetails_Blademaster_Rank = STDToString(skillData.GetBlademasterRank());
        sCharacterDetails_Avatar_Current = STDToString(skillData.GetAvatarCurrent());
        sCharacterDetails_Avatar_Rank = STDToString(skillData.GetAvatarRank());
        sCharacterDetails_Ambidext_Current = STDToString(skillData.GetAmbidextrousCurrent());
        sCharacterDetails_Ambidext_Rank = STDToString(skillData.GetAmbidextrousRank());
        sCharacterDetails_Focused_Current = STDToString(skillData.GetFocusedCurrent());
        sCharacterDetails_Focused_Rank = STDToString(skillData.GetFocusedRank());
        sCharacterDetails_Stalwart_Current = STDToString(skillData.GetStalwartCurrent());
        sCharacterDetails_Stalwart_Rank = STDToString(skillData.GetStalwartRank());
        sCharacterDetails_Slash_Current = STDToString(skillData.GetSlashCurrent());
        sCharacterDetails_Slash_Rank = STDToString(skillData.GetSlashRank());
        sCharacterDetails_Sever_Current = STDToString(skillData.GetSeverCurrent());
        sCharacterDetails_Sever_Rank = STDToString(skillData.GetSeverRank());
        sCharacterDetails_Slice_Current = STDToString(skillData.GetSliceCurrent());
        sCharacterDetails_Slice_Rank = STDToString(skillData.GetSliceRank());
        sCharacterDetails_Slit_Current = STDToString(skillData.GetSlitCurrent());
        sCharacterDetails_Slit_Rank = STDToString(skillData.GetSlitRank());
        sCharacterDetails_Cleave_Current = STDToString(skillData.GetCleaveCurrent());
        sCharacterDetails_Cleave_Rank = STDToString(skillData.GetCleaveRank());
        sCharacterDetails_Decapitate_Current = STDToString(skillData.GetDecapitateCurrent());
        sCharacterDetails_Decapitate_Rank = STDToString(skillData.GetDecapitateRank());
        sCharacterDetails_Parry_Current = STDToString(skillData.GetParryCurrent());
        sCharacterDetails_Parry_Rank = STDToString(skillData.GetParryRank());
        sCharacterDetails_Riposte_Current = STDToString(skillData.GetRiposteCurrent());
        sCharacterDetails_Riposte_Rank = STDToString(skillData.GetRiposteRank());
        sCharacterDetails_Bash_Current = STDToString(skillData.GetBashCurrent());
        sCharacterDetails_Bash_Rank = STDToString(skillData.GetBashRank());
        sCharacterDetails_Smash_Current = STDToString(skillData.GetSmashCurrent());
        sCharacterDetails_Smash_Rank = STDToString(skillData.GetSmashRank());
        sCharacterDetails_Crush_Current = STDToString(skillData.GetCrushCurrent());
        sCharacterDetails_Crush_Rank = STDToString(skillData.GetCrushRank());
        sCharacterDetails_Impact_Current = STDToString(skillData.GetImpactCurrent());
        sCharacterDetails_Impact_Rank = STDToString(skillData.GetImpactRank());
        sCharacterDetails_Break_Current = STDToString(skillData.GetBreakCurrent());
        sCharacterDetails_Break_Rank = STDToString(skillData.GetBreakRank());
        sCharacterDetails_Crack_Current = STDToString(skillData.GetCrackCurrent());
        sCharacterDetails_Crack_Rank = STDToString(skillData.GetCrackRank());
        sCharacterDetails_Block_Current = STDToString(skillData.GetBlockCurrent());
        sCharacterDetails_Block_Rank = STDToString(skillData.GetBlockRank());
        sCharacterDetails_Rush_Current = STDToString(skillData.GetRushCurrent());
        sCharacterDetails_Rush_Rank = STDToString(skillData.GetRushRank());
        sCharacterDetails_Pierce_Current = STDToString(skillData.GetPierceCurrent());
        sCharacterDetails_Pierce_Rank = STDToString(skillData.GetPierceRank());
        sCharacterDetails_Drill_Current = STDToString(skillData.GetDrillCurrent());
        sCharacterDetails_Drill_Rank = STDToString(skillData.GetDrillRank());
        sCharacterDetails_Shoot_Current = STDToString(skillData.GetShootCurrent());
        sCharacterDetails_Shoot_Rank = STDToString(skillData.GetShootRank());
        sCharacterDetails_Impale_Current = STDToString(skillData.GetImpaleCurrent());
        sCharacterDetails_Impale_Rank = STDToString(skillData.GetImpaleRank());
        sCharacterDetails_StealthStrike_Current = STDToString(skillData.GetStealthStrikeCurrent());
        sCharacterDetails_StealthStrike_Rank = STDToString(skillData.GetStealthStrikeRank());
        sCharacterDetails_CriticalShot_Current = STDToString(skillData.GetCriticalShotCurrent());
        sCharacterDetails_CriticalShot_Rank = STDToString(skillData.GetCriticalShotRank());
        sCharacterDetails_Dodge_Current = STDToString(skillData.GetDodgeCurrent());
        sCharacterDetails_Dodge_Rank = STDToString(skillData.GetDodgeRank());
        sCharacterDetails_Counter_Current = STDToString(skillData.GetCounterCurrent());
        sCharacterDetails_Counter_Rank = STDToString(skillData.GetCounterRank());
        sCharacterDetails_Healer_Current = STDToString(skillData.GetHealerCurrent());
        sCharacterDetails_Healer_Rank = STDToString(skillData.GetHealerRank());
        sCharacterDetails_Alchemist_Current = STDToString(skillData.GetAlchemistCurrent());
        sCharacterDetails_Alchemist_Rank = STDToString(skillData.GetAlchemistRank());
        sCharacterDetails_Energist_Current = STDToString(skillData.GetEnergistCurrent());
        sCharacterDetails_Energist_Rank = STDToString(skillData.GetEnergistRank());
        sCharacterDetails_Chemist_Current = STDToString(skillData.GetChemistCurrent());
        sCharacterDetails_Chemist_Rank = STDToString(skillData.GetChemistRank());
        sCharacterDetails_Hammersmith_Current = STDToString(skillData.GetHammersmithCurrent());
        sCharacterDetails_Hammersmith_Rank = STDToString(skillData.GetHammersmithRank());
        sCharacterDetails_Spellsmith_Current = STDToString(skillData.GetSpellsmithCurrent());
        sCharacterDetails_Spellsmith_Rank = STDToString(skillData.GetSpellsmithRank());
        sCharacterDetails_Bowsmith_Current = STDToString(skillData.GetBowsmithCurrent());
        sCharacterDetails_Bowsmith_Rank = STDToString(skillData.GetBowsmithRank());
        sCharacterDetails_Swordsmith_Current = STDToString(skillData.GetSwordsmithCurrent());
        sCharacterDetails_Swordsmith_Rank = STDToString(skillData.GetSwordsmithRank());
        sCharacterDetails_Weaver_Current = STDToString(skillData.GetWeaverCurrent());
        sCharacterDetails_Weaver_Rank = STDToString(skillData.GetWeaverRank());
        sCharacterDetails_Tanner_Current = STDToString(skillData.GetTannerCurrent());
        sCharacterDetails_Tanner_Rank = STDToString(skillData.GetTannerRank());
        sCharacterDetails_Scalesmith_Current = STDToString(skillData.GetScalesmithCurrent());
        sCharacterDetails_Scalesmith_Rank = STDToString(skillData.GetScalesmithRank());
        sCharacterDetails_Platesmith_Current = STDToString(skillData.GetPlatesmithCurrent());
        sCharacterDetails_Platesmith_Rank = STDToString(skillData.GetPlatesmithRank());
        sCharacterDetails_Goldsmith_Current = STDToString(skillData.GetGoldsmithCurrent());
        sCharacterDetails_Goldsmith_Rank = STDToString(skillData.GetGoldsmithRank());
        sCharacterDetails_Shieldsmith_Current = STDToString(skillData.GetShieldsmithCurrent());
        sCharacterDetails_Shieldsmith_Rank = STDToString(skillData.GetShieldsmithRank());
        sCharacterDetails_Hammerbane_Current = STDToString(skillData.GetHammerbaneCurrent());
        sCharacterDetails_Hammerbane_Rank = STDToString(skillData.GetHammerbaneRank());
        sCharacterDetails_Spellbane_Current = STDToString(skillData.GetSpellbaneCurrent());
        sCharacterDetails_Spellbane_Rank = STDToString(skillData.GetSpellbaneRank());
        sCharacterDetails_Bowbane_Current = STDToString(skillData.GetBowbaneCurrent());
        sCharacterDetails_Bowbane_Rank = STDToString(skillData.GetBowbaneRank());
        sCharacterDetails_Swordbane_Current = STDToString(skillData.GetSwordbaneCurrent());
        sCharacterDetails_Swordbane_Rank = STDToString(skillData.GetSwordbaneRank());
        sCharacterDetails_Threadbare_Current = STDToString(skillData.GetThreadbareCurrent());
        sCharacterDetails_Threadbare_Rank = STDToString(skillData.GetThreadbareRank());
        sCharacterDetails_Studremover_Current = STDToString(skillData.GetStudRemoverCurrent());
        sCharacterDetails_Studremover_Rank = STDToString(skillData.GetStudRemoverRank());
        sCharacterDetails_Scalebane_Current = STDToString(skillData.GetScalebaneCurrent());
        sCharacterDetails_Scalebane_Rank = STDToString(skillData.GetScalebaneRank());
        sCharacterDetails_Platebane_Current = STDToString(skillData.GetPlatebaneCurrent());
        sCharacterDetails_Platebane_Rank = STDToString(skillData.GetPlatebaneRank());
        sCharacterDetails_Goldbane_Current = STDToString(skillData.GetGoldbaneCurrent());
        sCharacterDetails_Goldbane_Rank = STDToString(skillData.GetGoldbaneRank());
        sCharacterDetails_Shieldbane_Current = STDToString(skillData.GetShieldbaneCurrent());
        sCharacterDetails_Shieldbane_Rank = STDToString(skillData.GetShieldbaneRank());
        sCharacterDetails_Holy_Current = STDToString(skillData.GetHolyCurrent());
        sCharacterDetails_Holy_Rank = STDToString(skillData.GetHolyRank());
        sCharacterDetails_Fire_Current = STDToString(skillData.GetFireCurrent());
        sCharacterDetails_Fire_Rank = STDToString(skillData.GetFireRank());
        sCharacterDetails_Ice_Current = STDToString(skillData.GetIceCurrent());
        sCharacterDetails_Ice_Rank = STDToString(skillData.GetIceRank());
        sCharacterDetails_Shock_Current = STDToString(skillData.GetShockCurrent());
        sCharacterDetails_Shock_Rank = STDToString(skillData.GetShockRank());
        sCharacterDetails_Dark_Current = STDToString(skillData.GetDarkCurrent());
        sCharacterDetails_Dark_Rank = STDToString(skillData.GetDarkRank());
        sCharacterDetails_Light_Current = STDToString(skillData.GetLightCurrent());
        sCharacterDetails_Light_Rank = STDToString(skillData.GetLightRank());
        sCharacterDetails_Force_Current = STDToString(skillData.GetForceCurrent());
        sCharacterDetails_Force_Rank = STDToString(skillData.GetForceRank());
        sCharacterDetails_Mind_Current = STDToString(skillData.GetMindCurrent());
        sCharacterDetails_Mind_Rank = STDToString(skillData.GetMindRank());
        sCharacterDetails_Earth_Current = STDToString(skillData.GetEarthCurrent());
        sCharacterDetails_Earth_Rank = STDToString(skillData.GetEarthRank());
        sCharacterDetails_Blood_Current = STDToString(skillData.GetBloodCurrent());
        sCharacterDetails_Blood_Rank = STDToString(skillData.GetBloodRank());
        sCharacterDetails_Flesh_Current = STDToString(skillData.GetFleshCurrent());
        sCharacterDetails_Flesh_Rank = STDToString(skillData.GetFleshRank());
        sCharacterDetails_Wind_Current = STDToString(skillData.GetWindCurrent());
        sCharacterDetails_Wind_Rank = STDToString(skillData.GetWindRank());
        sCharacterDetails_CharID = character.GetCharacterID();
        sCharacterDetails_AvailableActions = Json(character.GetAvailableActions()).dump();
        sCharacterDetails_SkillPassiveChanges = Json(character.GetPassiveChanges(sSkillTreeIndexType)).dump();
        sCharacterDetails_ItemPassiveChanges = Json(character.GetPassiveChanges(sItemTreeIndexType)).dump();
        sCharacterDetails_SkillActiveChanges = Json(character.GetActiveChanges(sSkillTreeIndexType)).dump();
        sCharacterDetails_ItemActiveChanges = Json(character.GetActiveChanges(sItemTreeIndexType)).dump();
        sCharacterDetails_SkillActionableChanges = Json(character.GetActionableChanges(sSkillTreeIndexType)).dump();
        sCharacterDetails_ItemActionableChanges = Json(character.GetActionableChanges(sItemTreeIndexType)).dump();
        sCharacterDetails_RawJson = Json(character).dump();
    }

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
    BoostReplaceAll(sPage, "%sLoadCharacterFromJson_Textarea%", sLoadCharacterFromJson_Textarea);
    BoostReplaceAll(sPage, "%sLoadCharacterFromFile_Filename%", sLoadCharacterFromFile_Filename);
    BoostReplaceAll(sPage, "%sSaveCharacterToFile_CharID%", sSaveCharacterToFile_CharID);
    BoostReplaceAll(sPage, "%sSaveCharacterToFile_Filename%", sSaveCharacterToFile_Filename);
    BoostReplaceAll(sPage, "%sUnloadCharacter_CharID%", sUnloadCharacter_CharID);
    BoostReplaceAll(sPage, "%sGenerateCharacter_CharID%", sGenerateCharacter_CharID);
    BoostReplaceAll(sPage, "%sGenerateCharacter_Textarea%", sGenerateCharacter_Textarea);
    BoostReplaceAll(sPage, "%sGenerateRandomCharacter_CharID%", sGenerateRandomCharacter_CharID);
    BoostReplaceAll(sPage, "%sCreateCharacter_CharID%", sCreateCharacter_CharID);
    BoostReplaceAll(sPage, "%sDisplayCharacter_CharID%", sDisplayCharacter_CharID);
    BoostReplaceAll(sPage, "%sAllCharacterIDs%", sAllCharacterIDs);
    BoostReplaceAll(sPage, "%sCharacterDetails_CharID%", sCharacterDetails_CharID);
    BoostReplaceAll(sPage, "%sCharacterDetails_PartyID%", sCharacterDetails_PartyID);
    BoostReplaceAll(sPage, "%sCharacterDetails_CharTargetType%", sCharacterDetails_CharTargetType);
    BoostReplaceAll(sPage, "%sCharacterDetails_First_Name%", sCharacterDetails_First_Name);
    BoostReplaceAll(sPage, "%sCharacterDetails_Last_Name%", sCharacterDetails_Last_Name);
    BoostReplaceAll(sPage, "%sCharacterDetails_Age%", sCharacterDetails_Age);
    BoostReplaceAll(sPage, "%sCharacterDetails_Blunt_Attack%", sCharacterDetails_Blunt_Attack);
    BoostReplaceAll(sPage, "%sCharacterDetails_Blunt_Defense%", sCharacterDetails_Blunt_Defense);
    BoostReplaceAll(sPage, "%sCharacterDetails_Pierce_Attack%", sCharacterDetails_Pierce_Attack);
    BoostReplaceAll(sPage, "%sCharacterDetails_Pierce_Defense%", sCharacterDetails_Pierce_Defense);
    BoostReplaceAll(sPage, "%sCharacterDetails_Slash_Attack%", sCharacterDetails_Slash_Attack);
    BoostReplaceAll(sPage, "%sCharacterDetails_Slash_Defense%", sCharacterDetails_Slash_Defense);
    BoostReplaceAll(sPage, "%sCharacterDetails_Magic_Attack%", sCharacterDetails_Magic_Attack);
    BoostReplaceAll(sPage, "%sCharacterDetails_Magic_Defense%", sCharacterDetails_Magic_Defense);
    BoostReplaceAll(sPage, "%sCharacterDetails_Energy_Attack%", sCharacterDetails_Energy_Attack);
    BoostReplaceAll(sPage, "%sCharacterDetails_Energy_Defense%", sCharacterDetails_Energy_Defense);
    BoostReplaceAll(sPage, "%sCharacterDetails_HP_Current%", sCharacterDetails_HP_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_HP_Max%", sCharacterDetails_HP_Max);
    BoostReplaceAll(sPage, "%sCharacterDetails_HP_Regen%", sCharacterDetails_HP_Regen);
    BoostReplaceAll(sPage, "%sCharacterDetails_HP_Delta%", sCharacterDetails_HP_Delta);
    BoostReplaceAll(sPage, "%sCharacterDetails_MP_Current%", sCharacterDetails_MP_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_MP_Max%", sCharacterDetails_MP_Max);
    BoostReplaceAll(sPage, "%sCharacterDetails_MP_Regen%", sCharacterDetails_MP_Regen);
    BoostReplaceAll(sPage, "%sCharacterDetails_MP_Delta%", sCharacterDetails_MP_Delta);
    BoostReplaceAll(sPage, "%sCharacterDetails_EP_Current%", sCharacterDetails_EP_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_EP_Max%", sCharacterDetails_EP_Max);
    BoostReplaceAll(sPage, "%sCharacterDetails_EP_Regen%", sCharacterDetails_EP_Regen);
    BoostReplaceAll(sPage, "%sCharacterDetails_EP_Delta%", sCharacterDetails_EP_Delta);
    BoostReplaceAll(sPage, "%sCharacterDetails_Speed%", sCharacterDetails_Speed);
    BoostReplaceAll(sPage, "%sCharacterDetails_Chest%", sCharacterDetails_Chest);
    BoostReplaceAll(sPage, "%sCharacterDetails_Feet%", sCharacterDetails_Feet);
    BoostReplaceAll(sPage, "%sCharacterDetails_Hands%", sCharacterDetails_Hands);
    BoostReplaceAll(sPage, "%sCharacterDetails_Head%", sCharacterDetails_Head);
    BoostReplaceAll(sPage, "%sCharacterDetails_Legs%", sCharacterDetails_Legs);
    BoostReplaceAll(sPage, "%sCharacterDetails_Neck%", sCharacterDetails_Neck);
    BoostReplaceAll(sPage, "%sCharacterDetails_LeftFingers%", sCharacterDetails_LeftFingers);
    BoostReplaceAll(sPage, "%sCharacterDetails_RightFingers%", sCharacterDetails_RightFingers);
    BoostReplaceAll(sPage, "%sCharacterDetails_Weapon1Left%", sCharacterDetails_Weapon1Left);
    BoostReplaceAll(sPage, "%sCharacterDetails_Weapon1Right%", sCharacterDetails_Weapon1Right);
    BoostReplaceAll(sPage, "%sCharacterDetails_Weapon2Left%", sCharacterDetails_Weapon2Left);
    BoostReplaceAll(sPage, "%sCharacterDetails_Weapon2Right%", sCharacterDetails_Weapon2Right);
    BoostReplaceAll(sPage, "%sCharacterDetails_Bash_ActionPoints%", sCharacterDetails_Bash_ActionPoints);
    BoostReplaceAll(sPage, "%sCharacterDetails_Block_ActionPoints%", sCharacterDetails_Block_ActionPoints);
    BoostReplaceAll(sPage, "%sCharacterDetails_Break_ActionPoints%", sCharacterDetails_Break_ActionPoints);
    BoostReplaceAll(sPage, "%sCharacterDetails_Cleave_ActionPoints%", sCharacterDetails_Cleave_ActionPoints);
    BoostReplaceAll(sPage, "%sCharacterDetails_Counter_ActionPoints%", sCharacterDetails_Counter_ActionPoints);
    BoostReplaceAll(sPage, "%sCharacterDetails_Crack_ActionPoints%", sCharacterDetails_Crack_ActionPoints);
    BoostReplaceAll(sPage, "%sCharacterDetails_Crush_ActionPoints%", sCharacterDetails_Crush_ActionPoints);
    BoostReplaceAll(sPage, "%sCharacterDetails_CriticalShot_ActionPoints%", sCharacterDetails_CriticalShot_ActionPoints);
    BoostReplaceAll(sPage, "%sCharacterDetails_Decapitate_ActionPoints%", sCharacterDetails_Decapitate_ActionPoints);
    BoostReplaceAll(sPage, "%sCharacterDetails_Dodge_ActionPoints%", sCharacterDetails_Dodge_ActionPoints);
    BoostReplaceAll(sPage, "%sCharacterDetails_Drill_ActionPoints%", sCharacterDetails_Drill_ActionPoints);
    BoostReplaceAll(sPage, "%sCharacterDetails_Impact_ActionPoints%", sCharacterDetails_Impact_ActionPoints);
    BoostReplaceAll(sPage, "%sCharacterDetails_Impale_ActionPoints%", sCharacterDetails_Impale_ActionPoints);
    BoostReplaceAll(sPage, "%sCharacterDetails_Parry_ActionPoints%", sCharacterDetails_Parry_ActionPoints);
    BoostReplaceAll(sPage, "%sCharacterDetails_Pierce_ActionPoints%", sCharacterDetails_Pierce_ActionPoints);
    BoostReplaceAll(sPage, "%sCharacterDetails_Riposte_ActionPoints%", sCharacterDetails_Riposte_ActionPoints);
    BoostReplaceAll(sPage, "%sCharacterDetails_Rush_ActionPoints%", sCharacterDetails_Rush_ActionPoints);
    BoostReplaceAll(sPage, "%sCharacterDetails_Sever_ActionPoints%", sCharacterDetails_Sever_ActionPoints);
    BoostReplaceAll(sPage, "%sCharacterDetails_Shoot_ActionPoints%", sCharacterDetails_Shoot_ActionPoints);
    BoostReplaceAll(sPage, "%sCharacterDetails_Slash_ActionPoints%", sCharacterDetails_Slash_ActionPoints);
    BoostReplaceAll(sPage, "%sCharacterDetails_Slice_ActionPoints%", sCharacterDetails_Slice_ActionPoints);
    BoostReplaceAll(sPage, "%sCharacterDetails_Slit_ActionPoints%", sCharacterDetails_Slit_ActionPoints);
    BoostReplaceAll(sPage, "%sCharacterDetails_Smash_ActionPoints%", sCharacterDetails_Smash_ActionPoints);
    BoostReplaceAll(sPage, "%sCharacterDetails_StealthStrike_ActionPoints%", sCharacterDetails_StealthStrike_ActionPoints);
    BoostReplaceAll(sPage, "%sCharacterDetails_Alchemist_Current%", sCharacterDetails_Alchemist_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Alchemist_Rank%", sCharacterDetails_Alchemist_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Ambidext_Current%", sCharacterDetails_Ambidext_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Ambidext_Rank%", sCharacterDetails_Ambidext_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Avatar_Current%", sCharacterDetails_Avatar_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Avatar_Rank%", sCharacterDetails_Avatar_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Barbarian_Current%", sCharacterDetails_Barbarian_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Barbarian_Rank%", sCharacterDetails_Barbarian_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Bash_Current%", sCharacterDetails_Bash_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Bash_Rank%", sCharacterDetails_Bash_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Blademaster_Current%", sCharacterDetails_Blademaster_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Blademaster_Rank%", sCharacterDetails_Blademaster_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Block_Current%", sCharacterDetails_Block_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Block_Rank%", sCharacterDetails_Block_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Blood_Current%", sCharacterDetails_Blood_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Blood_Rank%", sCharacterDetails_Blood_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Bowbane_Current%", sCharacterDetails_Bowbane_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Bowbane_Rank%", sCharacterDetails_Bowbane_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Bowsmith_Current%", sCharacterDetails_Bowsmith_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Bowsmith_Rank%", sCharacterDetails_Bowsmith_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Break_Current%", sCharacterDetails_Break_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Break_Rank%", sCharacterDetails_Break_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Chemist_Current%", sCharacterDetails_Chemist_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Chemist_Rank%", sCharacterDetails_Chemist_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Cleave_Current%", sCharacterDetails_Cleave_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Cleave_Rank%", sCharacterDetails_Cleave_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Counter_Current%", sCharacterDetails_Counter_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Counter_Rank%", sCharacterDetails_Counter_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Crack_Current%", sCharacterDetails_Crack_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Crack_Rank%", sCharacterDetails_Crack_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Crush_Current%", sCharacterDetails_Crush_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Crush_Rank%", sCharacterDetails_Crush_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_CriticalShot_Current%", sCharacterDetails_CriticalShot_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_CriticalShot_Rank%", sCharacterDetails_CriticalShot_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Dark_Current%", sCharacterDetails_Dark_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Dark_Rank%", sCharacterDetails_Dark_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Decapitate_Current%", sCharacterDetails_Decapitate_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Decapitate_Rank%", sCharacterDetails_Decapitate_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Dodge_Current%", sCharacterDetails_Dodge_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Dodge_Rank%", sCharacterDetails_Dodge_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Drill_Current%", sCharacterDetails_Drill_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Drill_Rank%", sCharacterDetails_Drill_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Earth_Current%", sCharacterDetails_Earth_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Earth_Rank%", sCharacterDetails_Earth_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Energist_Current%", sCharacterDetails_Energist_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Energist_Rank%", sCharacterDetails_Energist_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Fire_Current%", sCharacterDetails_Fire_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Fire_Rank%", sCharacterDetails_Fire_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Flesh_Current%", sCharacterDetails_Flesh_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Flesh_Rank%", sCharacterDetails_Flesh_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Focused_Current%", sCharacterDetails_Focused_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Focused_Rank%", sCharacterDetails_Focused_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Force_Current%", sCharacterDetails_Force_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Force_Rank%", sCharacterDetails_Force_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Goldbane_Current%", sCharacterDetails_Goldbane_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Goldbane_Rank%", sCharacterDetails_Goldbane_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Goldsmith_Current%", sCharacterDetails_Goldsmith_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Goldsmith_Rank%", sCharacterDetails_Goldsmith_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Hammerbane_Current%", sCharacterDetails_Hammerbane_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Hammerbane_Rank%", sCharacterDetails_Hammerbane_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Hammersmith_Current%", sCharacterDetails_Hammersmith_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Hammersmith_Rank%", sCharacterDetails_Hammersmith_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Healer_Current%", sCharacterDetails_Healer_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Healer_Rank%", sCharacterDetails_Healer_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Holy_Current%", sCharacterDetails_Holy_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Holy_Rank%", sCharacterDetails_Holy_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Ice_Current%", sCharacterDetails_Ice_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Ice_Rank%", sCharacterDetails_Ice_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Impact_Current%", sCharacterDetails_Impact_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Impact_Rank%", sCharacterDetails_Impact_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Impale_Current%", sCharacterDetails_Impale_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Impale_Rank%", sCharacterDetails_Impale_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Light_Current%", sCharacterDetails_Light_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Light_Rank%", sCharacterDetails_Light_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Mage_Current%", sCharacterDetails_Mage_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Mage_Rank%", sCharacterDetails_Mage_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Mind_Current%", sCharacterDetails_Mind_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Mind_Rank%", sCharacterDetails_Mind_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Parry_Current%", sCharacterDetails_Parry_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Parry_Rank%", sCharacterDetails_Parry_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Pierce_Current%", sCharacterDetails_Pierce_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Pierce_Rank%", sCharacterDetails_Pierce_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Platebane_Current%", sCharacterDetails_Platebane_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Platebane_Rank%", sCharacterDetails_Platebane_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Platesmith_Current%", sCharacterDetails_Platesmith_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Platesmith_Rank%", sCharacterDetails_Platesmith_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Riposte_Current%", sCharacterDetails_Riposte_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Riposte_Rank%", sCharacterDetails_Riposte_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Rogue_Current%", sCharacterDetails_Rogue_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Rogue_Rank%", sCharacterDetails_Rogue_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Rush_Current%", sCharacterDetails_Rush_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Rush_Rank%", sCharacterDetails_Rush_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Scalebane_Current%", sCharacterDetails_Scalebane_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Scalebane_Rank%", sCharacterDetails_Scalebane_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Scalesmith_Current%", sCharacterDetails_Scalesmith_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Scalesmith_Rank%", sCharacterDetails_Scalesmith_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Sever_Current%", sCharacterDetails_Sever_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Sever_Rank%", sCharacterDetails_Sever_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Shieldbane_Current%", sCharacterDetails_Shieldbane_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Shieldbane_Rank%", sCharacterDetails_Shieldbane_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Shieldsmith_Current%", sCharacterDetails_Shieldsmith_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Shieldsmith_Rank%", sCharacterDetails_Shieldsmith_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Shock_Current%", sCharacterDetails_Shock_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Shock_Rank%", sCharacterDetails_Shock_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Shoot_Current%", sCharacterDetails_Shoot_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Shoot_Rank%", sCharacterDetails_Shoot_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Slash_Current%", sCharacterDetails_Slash_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Slash_Rank%", sCharacterDetails_Slash_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Slice_Current%", sCharacterDetails_Slice_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Slice_Rank%", sCharacterDetails_Slice_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Slit_Current%", sCharacterDetails_Slit_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Slit_Rank%", sCharacterDetails_Slit_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Smash_Current%", sCharacterDetails_Smash_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Smash_Rank%", sCharacterDetails_Smash_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Spellbane_Current%", sCharacterDetails_Spellbane_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Spellbane_Rank%", sCharacterDetails_Spellbane_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Spellsmith_Current%", sCharacterDetails_Spellsmith_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Spellsmith_Rank%", sCharacterDetails_Spellsmith_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_StealthStrike_Current%", sCharacterDetails_StealthStrike_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_StealthStrike_Rank%", sCharacterDetails_StealthStrike_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Stalwart_Current%", sCharacterDetails_Stalwart_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Stalwart_Rank%", sCharacterDetails_Stalwart_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Studremover_Current%", sCharacterDetails_Studremover_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Studremover_Rank%", sCharacterDetails_Studremover_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Swordbane_Current%", sCharacterDetails_Swordbane_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Swordbane_Rank%", sCharacterDetails_Swordbane_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Swordsmith_Current%", sCharacterDetails_Swordsmith_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Swordsmith_Rank%", sCharacterDetails_Swordsmith_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Tanner_Current%", sCharacterDetails_Tanner_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Tanner_Rank%", sCharacterDetails_Tanner_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Threadbare_Current%", sCharacterDetails_Threadbare_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Threadbare_Rank%", sCharacterDetails_Threadbare_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Weaver_Current%", sCharacterDetails_Weaver_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Weaver_Rank%", sCharacterDetails_Weaver_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_Wind_Current%", sCharacterDetails_Wind_Current);
    BoostReplaceAll(sPage, "%sCharacterDetails_Wind_Rank%", sCharacterDetails_Wind_Rank);
    BoostReplaceAll(sPage, "%sCharacterDetails_AvailableActions%", sCharacterDetails_AvailableActions);
    BoostReplaceAll(sPage, "%sCharacterDetails_SkillPassiveChanges%", sCharacterDetails_SkillPassiveChanges);
    BoostReplaceAll(sPage, "%sCharacterDetails_ItemPassiveChanges%", sCharacterDetails_ItemPassiveChanges);
    BoostReplaceAll(sPage, "%sCharacterDetails_SkillActiveChanges%", sCharacterDetails_SkillActiveChanges);
    BoostReplaceAll(sPage, "%sCharacterDetails_ItemActiveChanges%", sCharacterDetails_ItemActiveChanges);
    BoostReplaceAll(sPage, "%sCharacterDetails_SkillActionableChanges%", sCharacterDetails_SkillActionableChanges);
    BoostReplaceAll(sPage, "%sCharacterDetails_ItemActionableChanges%", sCharacterDetails_ItemActionableChanges);
    BoostReplaceAll(sPage, "%sCharacterDetails_RawJson%", sCharacterDetails_RawJson);
    SetPageContent(sPage);
}

};
