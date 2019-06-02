// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Web/WebPageCharacterManager.h"
#include "Utility/Constants.h"

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
    <form action="%submit_url%" method="post">
        <div class="form-group row">
            <div class="col"><hr></div>
            <div class="col-auto">Controls</div>
            <div class="col"><hr></div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Load From JSON</label>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="loadCharacterFromJson_charID" placeholder="Character Identifier" value="%loadCharacterFromJson_charID%"/>
            </div>
            <div class="col-sm-4">
                <textarea style="resize: none;" class="form-control" rows="3" name="loadCharacterFromJson_textarea" placeholder="Raw character json">%loadCharacterFromJson_textarea%</textarea>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="loadCharacterFromJson_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Load From File</label>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="loadCharacterFromFile_charID" placeholder="Character Identifier" value="%loadCharacterFromFile_charID%"/>
            </div>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="loadCharacterFromFile_filename" placeholder="Filename" value="%loadCharacterFromFile_filename%"/>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="loadCharacterFromFile_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Save To File</label>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="saveCharacterToFile_charID" placeholder="Character Identifier" value="%saveCharacterToFile_charID%"/>
            </div>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="saveCharacterToFile_filename" placeholder="Filename" value="%saveCharacterToFile_filename%"/>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="saveCharacterToFile_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Unload Character</label>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="unloadCharacter_charID" placeholder="Character Identifier" value="%unloadCharacter_charID%"/>
            </div>
            <div class="col-sm-4">
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="unloadCharacter_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Delete Character</label>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="deleteCharacter_charID" placeholder="Character Identifier" value="%deleteCharacter_charID%"/>
            </div>
            <div class="col-sm-4">
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="deleteCharacter_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Generate Character</label>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="generateCharacter_charID" placeholder="Character Identifier" value="%generateCharacter_charID%"/>
            </div>
            <div class="col-sm-4">
                <textarea style="resize: none;" class="form-control" rows="3" name="generateCharacter_textarea" placeholder="Raw character generator json">%generateCharacter_textarea%</textarea>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="generateCharacter_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Create Character</label>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="createCharacter_charID" placeholder="Character Identifier" value="%createCharacter_charID%"/>
            </div>
            <div class="col-sm-4">
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="createCharacter_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Save Character Changes</label>
            <div class="col-sm-8">
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="saveCharacter_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <div class="col"><hr></div>
            <div class="col-auto">Character Details</div>
            <div class="col"><hr></div>
        </div>
        <div class="form-group row">
            <div class="col-sm-3">
                <input type="text" class="form-control" name="characterDetails_charID" placeholder="Character Identifier" readonly="readonly" value="%characterDetails_charID%"/>
            </div>
            <div class="col-sm-3">
                <input type="text" class="form-control" name="characterDetails_fname" placeholder="First Name" value="%characterDetails_fname%"/>
            </div>
            <div class="col-sm-3">
                <input type="text" class="form-control" name="characterDetails_lname" placeholder="Last Name" value="%characterDetails_lname%"/>
            </div>
            <div class="col-sm-3">
                <input type="text" class="form-control" name="characterDetails_age" placeholder="Age" value="%characterDetails_age%"/>
            </div>
        </div>
        <div class="form-group row">
            <div class="col-sm-3">
                <select class="form-control" name="characterDetails_gender">
                    <option value="">Gender...</option>
                    %optionList_gender%
                </select>
            </div>
            <div class="col-sm-3">
                <select class="form-control" name="characterDetails_hair">
                    <option value="">Hair...</option>
                    %optionList_hair%
                </select>
            </div>
            <div class="col-sm-3">
                <select class="form-control" name="characterDetails_eyes">
                    <option value="">Eyes...</option>
                    %optionList_eyes%
                </select>
            </div>
            <div class="col-sm-3">
                <select class="form-control" name="characterDetails_handed">
                    <option value="">Handedness...</option>
                    %optionList_handed%
                </select>
            </div>
            <div class="col-sm-4">
            </div>
        </div>
        <div class="form-group row">
            <div class="col-sm-3">
                <select class="form-control" name="characterDetails_powerset">
                    <option value="">Power Set...</option>
                    %optionList_powerset%
                </select>
            </div>
            <div class="col-sm-3">
                <select class="form-control" name="characterDetails_baserace">
                    <option value="">Base Race...</option>
                    %optionList_baserace%
                </select>
            </div>
            <div class="col-sm-3">
                <select class="form-control" name="characterDetails_transformedrace">
                    <option value="">Transformed Race...</option>
                    %optionList_transformedrace%
                </select>
            </div>
            <div class="col-sm-3">
                <select class="form-control" name="characterDetails_currentweaponset">
                    <option value="">Weapon Set...</option>
                    %optionList_currentweaponset%
                </select>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Weapon 1 Left</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_weapon1left" readonly="readonly" value="%characterDetails_weapon1left%"/>
            </div>
            <label class="col-sm-2 col-form-label">Weapon 1 Right</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_weapon1right" readonly="readonly" value="%characterDetails_weapon1right%"/>
            </div>
            <label class="col-sm-2 col-form-label">Neck</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_neck" readonly="readonly" value="%characterDetails_neck%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Weapon 2 Left</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_weapon2left" readonly="readonly" value="%characterDetails_weapon2left%"/>
            </div>
            <label class="col-sm-2 col-form-label">Weapon 2 Right</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_weapon2right" readonly="readonly" value="%characterDetails_weapon2right%"/>
            </div>
            <label class="col-sm-2 col-form-label">Head</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_head" readonly="readonly" value="%characterDetails_head%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Left Fingers</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_leftfingers" readonly="readonly" value="%characterDetails_leftfingers%"/>
            </div>
            <label class="col-sm-2 col-form-label">Right Fingers</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_rightfingers" readonly="readonly" value="%characterDetails_rightfingers%"/>
            </div>
            <label class="col-sm-2 col-form-label">Hands</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_hands" readonly="readonly" value="%characterDetails_hands%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Feet</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_feet" readonly="readonly" value="%characterDetails_feet%"/>
            </div>
            <label class="col-sm-2 col-form-label">Legs</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_legs" readonly="readonly" value="%characterDetails_legs%"/>
            </div>
            <label class="col-sm-2 col-form-label">Chest</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_chest" readonly="readonly" value="%characterDetails_chest%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-1 col-form-label">Health</label>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_hpcur" placeholder="Cur" value="%characterDetails_hpcur%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_hpmax" placeholder="Max" value="%characterDetails_hpmax%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_hpregen" placeholder="Reg" value="%characterDetails_hpregen%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_hpdelta" placeholder="Delta" value="%characterDetails_hpdelta%"/>
            </div>
            <label class="col-sm-1 col-form-label">Blunt</label>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_batk" placeholder="Atk" value="%characterDetails_batk%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_bdef" placeholder="Def" value="%characterDetails_bdef%"/>
            </div>
            <label class="col-sm-1 col-form-label">Pierce</label>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_patk" placeholder="Atk" value="%characterDetails_patk%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_pdef" placeholder="Def" value="%characterDetails_pdef%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-1 col-form-label">Magic</label>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_mpcur" placeholder="Cur" value="%characterDetails_mpcur%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_mpmax" placeholder="Max" value="%characterDetails_mpmax%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_mpregen" placeholder="Reg" value="%characterDetails_mpregen%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_mpdelta" placeholder="Delta" value="%characterDetails_mpdelta%"/>
            </div>
            <label class="col-sm-1 col-form-label">Magic</label>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_matk" placeholder="Atk" value="%characterDetails_matk%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_mdef" placeholder="Def" value="%characterDetails_mdef%"/>
            </div>
            <label class="col-sm-1 col-form-label">Energy</label>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_eatk" placeholder="Atk" value="%characterDetails_eatk%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_edef" placeholder="Def" value="%characterDetails_edef%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-1 col-form-label">Energy</label>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_epcur" placeholder="Cur" value="%characterDetails_epcur%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_epmax" placeholder="Max" value="%characterDetails_epmax%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_epregen" placeholder="Reg" value="%characterDetails_epregen%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_epdelta" placeholder="Delta" value="%characterDetails_epdelta%"/>
            </div>
            <label class="col-sm-1 col-form-label">Slash</label>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_satk" placeholder="Atk" value="%characterDetails_satk%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_sdef" placeholder="Def" value="%characterDetails_sdef%"/>
            </div>
            <label class="col-sm-1 col-form-label">Speed</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_speed" placeholder="Speed" value="%characterDetails_speed%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-1 col-form-label">Slash</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_slash_cur" placeholder="Current" value="%characterDetails_slash_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_slash_rank" placeholder="Rank" value="%characterDetails_slash_rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_slash_ap" placeholder="AP" value="%characterDetails_slash_ap%"/>
            </div>
            <label class="col-sm-1 col-form-label">Sever</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_sever_cur" placeholder="Current" value="%characterDetails_sever_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_sever_rank" placeholder="Rank" value="%characterDetails_sever_rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_sever_ap" placeholder="AP" value="%characterDetails_sever_ap%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-1 col-form-label">Slice</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_slice_cur" placeholder="Current" value="%characterDetails_slice_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_slice_rank" placeholder="Rank" value="%characterDetails_slice_rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_slice_ap" placeholder="AP" value="%characterDetails_slice_ap%"/>
            </div>
            <label class="col-sm-1 col-form-label">Slit</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_slit_cur" placeholder="Current" value="%characterDetails_slit_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_slit_rank" placeholder="Rank" value="%characterDetails_slit_rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_slit_ap" placeholder="AP" value="%characterDetails_slit_ap%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-1 col-form-label">Cleave</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_cleave_cur" placeholder="Current" value="%characterDetails_cleave_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_cleave_rank" placeholder="Rank" value="%characterDetails_cleave_rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_cleave_ap" placeholder="AP" value="%characterDetails_cleave_ap%"/>
            </div>
            <label class="col-sm-1 col-form-label">Decapitate</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_decapitate_cur" placeholder="Current" value="%characterDetails_decapitate_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_decapitate_rank" placeholder="Rank" value="%characterDetails_decapitate_rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_decapitate_ap" placeholder="AP" value="%characterDetails_decapitate_ap%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-1 col-form-label">Parry</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_parry_cur" placeholder="Current" value="%characterDetails_parry_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_parry_rank" placeholder="Rank" value="%characterDetails_parry_rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_parry_ap" placeholder="AP" value="%characterDetails_parry_ap%"/>
            </div>
            <label class="col-sm-1 col-form-label">Riposte</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_riposte_cur" placeholder="Current" value="%characterDetails_riposte_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_riposte_rank" placeholder="Rank" value="%characterDetails_riposte_rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_riposte_ap" placeholder="AP" value="%characterDetails_riposte_ap%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-1 col-form-label">Bash</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_bash_cur" placeholder="Current" value="%characterDetails_bash_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_bash_rank" placeholder="Rank" value="%characterDetails_bash_rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_bash_ap" placeholder="AP" value="%characterDetails_bash_ap%"/>
            </div>
            <label class="col-sm-1 col-form-label">Smash</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_smash_cur" placeholder="Current" value="%characterDetails_smash_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_smash_rank" placeholder="Rank" value="%characterDetails_smash_rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_smash_ap" placeholder="AP" value="%characterDetails_smash_ap%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-1 col-form-label">Crush</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_crush_cur" placeholder="Current" value="%characterDetails_crush_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_crush_rank" placeholder="Rank" value="%characterDetails_crush_rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_crush_ap" placeholder="AP" value="%characterDetails_crush_ap%"/>
            </div>
            <label class="col-sm-1 col-form-label">Impact</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_impact_cur" placeholder="Current" value="%characterDetails_impact_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_impact_rank" placeholder="Rank" value="%characterDetails_impact_rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_impact_ap" placeholder="AP" value="%characterDetails_impact_ap%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-1 col-form-label">Break</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_break_cur" placeholder="Current" value="%characterDetails_break_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_break_rank" placeholder="Rank" value="%characterDetails_break_rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_break_ap" placeholder="AP" value="%characterDetails_break_ap%"/>
            </div>
            <label class="col-sm-1 col-form-label">Crack</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_crack_cur" placeholder="Current" value="%characterDetails_crack_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_crack_rank" placeholder="Rank" value="%characterDetails_crack_rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_crack_ap" placeholder="AP" value="%characterDetails_crack_ap%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-1 col-form-label">Block</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_block_cur" placeholder="Current" value="%characterDetails_block_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_block_rank" placeholder="Rank" value="%characterDetails_block_rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_block_ap" placeholder="AP" value="%characterDetails_block_ap%"/>
            </div>
            <label class="col-sm-1 col-form-label">Rush</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_rush_cur" placeholder="Current" value="%characterDetails_rush_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_rush_rank" placeholder="Rank" value="%characterDetails_rush_rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_rush_ap" placeholder="AP" value="%characterDetails_rush_ap%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-1 col-form-label">Pierce</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_pierce_cur" placeholder="Current" value="%characterDetails_pierce_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_pierce_rank" placeholder="Rank" value="%characterDetails_pierce_rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_pierce_ap" placeholder="AP" value="%characterDetails_pierce_ap%"/>
            </div>
            <label class="col-sm-1 col-form-label">Drill</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_drill_cur" placeholder="Current" value="%characterDetails_drill_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_drill_rank" placeholder="Rank" value="%characterDetails_drill_rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_drill_ap" placeholder="AP" value="%characterDetails_drill_ap%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-1 col-form-label">Shoot</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_shoot_cur" placeholder="Current" value="%characterDetails_shoot_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_shoot_rank" placeholder="Rank" value="%characterDetails_shoot_rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_shoot_ap" placeholder="AP" value="%characterDetails_shoot_ap%"/>
            </div>
            <label class="col-sm-1 col-form-label">Impale</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_impale_cur" placeholder="Current" value="%characterDetails_impale_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_impale_rank" placeholder="Rank" value="%characterDetails_impale_rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_impale_ap" placeholder="AP" value="%characterDetails_impale_ap%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-1 col-form-label">Stealth Strike</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_sstrike_cur" placeholder="Current" value="%characterDetails_sstrike_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_sstrike_rank" placeholder="Rank" value="%characterDetails_sstrike_rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_sstrike_ap" placeholder="AP" value="%characterDetails_sstrike_ap%"/>
            </div>
            <label class="col-sm-1 col-form-label">Critical Shot</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_cshot_cur" placeholder="Current" value="%characterDetails_cshot_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_cshot_rank" placeholder="Rank" value="%characterDetails_cshot_rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_cshot_ap" placeholder="AP" value="%characterDetails_cshot_ap%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-1 col-form-label">Dodge</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_dodge_cur" placeholder="Current" value="%characterDetails_dodge_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_dodge_rank" placeholder="Rank" value="%characterDetails_dodge_rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_dodge_ap" placeholder="AP" value="%characterDetails_dodge_ap%"/>
            </div>
            <label class="col-sm-1 col-form-label">Counter</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_counter_cur" placeholder="Current" value="%characterDetails_counter_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_counter_rank" placeholder="Rank" value="%characterDetails_counter_rank%"/>
            </div>
            <div class="col-sm-1">
                <input type="text" class="form-control" name="characterDetails_counter_ap" placeholder="AP" value="%characterDetails_counter_ap%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Barbarian</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_barbarian_cur" placeholder="Current" value="%characterDetails_barbarian_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_barbarian_rank" placeholder="Rank" value="%characterDetails_barbarian_rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Mage</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_mage_cur" placeholder="Current" value="%characterDetails_mage_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_mage_rank" placeholder="Rank" value="%characterDetails_mage_rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Rogue</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_rogue_cur" placeholder="Current" value="%characterDetails_rogue_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_rogue_rank" placeholder="Rank" value="%characterDetails_rogue_rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Blademaster</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_blademaster_cur" placeholder="Current" value="%characterDetails_blademaster_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_blademaster_rank" placeholder="Rank" value="%characterDetails_blademaster_rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Avatar</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_avatar_cur" placeholder="Current" value="%characterDetails_avatar_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_avatar_rank" placeholder="Rank" value="%characterDetails_avatar_rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Ambidextrous</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_ambidext_cur" placeholder="Current" value="%characterDetails_ambidext_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_ambidext_rank" placeholder="Rank" value="%characterDetails_ambidext_rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Focused</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_focused_cur" placeholder="Current" value="%characterDetails_focused_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_focused_rank" placeholder="Rank" value="%characterDetails_focused_rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Stalwart</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_stalwart_cur" placeholder="Current" value="%characterDetails_stalwart_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_stalwart_rank" placeholder="Rank" value="%characterDetails_stalwart_rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Healer</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_healer_cur" placeholder="Current" value="%characterDetails_healer_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_healer_rank" placeholder="Rank" value="%characterDetails_healer_rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Alchemist</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_alchemist_cur" placeholder="Current" value="%characterDetails_alchemist_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_alchemist_rank" placeholder="Rank" value="%characterDetails_alchemist_rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Energist</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_energist_cur" placeholder="Current" value="%characterDetails_energist_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_energist_rank" placeholder="Rank" value="%characterDetails_energist_rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Chemist</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_chemist_cur" placeholder="Current" value="%characterDetails_chemist_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_chemist_rank" placeholder="Rank" value="%characterDetails_chemist_rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Hammersmith</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_hammersmith_cur" placeholder="Current" value="%characterDetails_hammersmith_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_hammersmith_rank" placeholder="Rank" value="%characterDetails_hammersmith_rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Spellsmith</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_spellsmith_cur" placeholder="Current" value="%characterDetails_spellsmith_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_spellsmith_rank" placeholder="Rank" value="%characterDetails_spellsmith_rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Bowsmith</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_bowsmith_cur" placeholder="Current" value="%characterDetails_bowsmith_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_bowsmith_rank" placeholder="Rank" value="%characterDetails_bowsmith_rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Swordsmith</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_swordsmith_cur" placeholder="Current" value="%characterDetails_swordsmith_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_swordsmith_rank" placeholder="Rank" value="%characterDetails_swordsmith_rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Weaver</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_weaver_cur" placeholder="Current" value="%characterDetails_weaver_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_weaver_rank" placeholder="Rank" value="%characterDetails_weaver_rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Tanner</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_tanner_cur" placeholder="Current" value="%characterDetails_tanner_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_tanner_rank" placeholder="Rank" value="%characterDetails_tanner_rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Scalesmith</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_scalesmith_cur" placeholder="Current" value="%characterDetails_scalesmith_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_scalesmith_rank" placeholder="Rank" value="%characterDetails_scalesmith_rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Platesmith</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_platesmith_cur" placeholder="Current" value="%characterDetails_platesmith_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_platesmith_rank" placeholder="Rank" value="%characterDetails_platesmith_rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Goldsmith</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_goldsmith_cur" placeholder="Current" value="%characterDetails_goldsmith_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_goldsmith_rank" placeholder="Rank" value="%characterDetails_goldsmith_rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Shieldsmith</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_shieldsmith_cur" placeholder="Current" value="%characterDetails_shieldsmith_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_shieldsmith_rank" placeholder="Rank" value="%characterDetails_shieldsmith_rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Hammerbane</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_hammerbane_cur" placeholder="Current" value="%characterDetails_hammerbane_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_hammerbane_rank" placeholder="Rank" value="%characterDetails_hammerbane_rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Spellbane</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_spellbane_cur" placeholder="Current" value="%characterDetails_spellbane_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_spellbane_rank" placeholder="Rank" value="%characterDetails_spellbane_rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Bowbane</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_bowbane_cur" placeholder="Current" value="%characterDetails_bowbane_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_bowbane_rank" placeholder="Rank" value="%characterDetails_bowbane_rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Swordbane</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_swordbane_cur" placeholder="Current" value="%characterDetails_swordbane_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_swordbane_rank" placeholder="Rank" value="%characterDetails_swordbane_rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Threadbare</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_threadbare_cur" placeholder="Current" value="%characterDetails_threadbare_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_threadbare_rank" placeholder="Rank" value="%characterDetails_threadbare_rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Stud Remover</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_studremover_cur" placeholder="Current" value="%characterDetails_studremover_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_studremover_rank" placeholder="Rank" value="%characterDetails_studremover_rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Scalebane</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_scalebane_cur" placeholder="Current" value="%characterDetails_scalebane_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_scalebane_rank" placeholder="Rank" value="%characterDetails_scalebane_rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Platebane</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_platebane_cur" placeholder="Current" value="%characterDetails_platebane_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_platebane_rank" placeholder="Rank" value="%characterDetails_platebane_rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Goldbane</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_goldbane_cur" placeholder="Current" value="%characterDetails_goldbane_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_goldbane_rank" placeholder="Rank" value="%characterDetails_goldbane_rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Shieldbane</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_shieldbane_cur" placeholder="Current" value="%characterDetails_shieldbane_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_shieldbane_rank" placeholder="Rank" value="%characterDetails_shieldbane_rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Holy</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_holy_cur" placeholder="Current" value="%characterDetails_holy_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_holy_rank" placeholder="Rank" value="%characterDetails_holy_rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Fire</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_fire_cur" placeholder="Current" value="%characterDetails_fire_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_fire_rank" placeholder="Rank" value="%characterDetails_fire_rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Ice</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_ice_cur" placeholder="Current" value="%characterDetails_ice_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_ice_rank" placeholder="Rank" value="%characterDetails_ice_rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Shock</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_shock_cur" placeholder="Current" value="%characterDetails_shock_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_shock_rank" placeholder="Rank" value="%characterDetails_shock_rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Dark</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_dark_cur" placeholder="Current" value="%characterDetails_dark_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_dark_rank" placeholder="Rank" value="%characterDetails_dark_rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Light</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_light_cur" placeholder="Current" value="%characterDetails_light_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_light_rank" placeholder="Rank" value="%characterDetails_light_rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Force</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_force_cur" placeholder="Current" value="%characterDetails_force_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_force_rank" placeholder="Rank" value="%characterDetails_force_rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Mind</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_mind_cur" placeholder="Current" value="%characterDetails_mind_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_mind_rank" placeholder="Rank" value="%characterDetails_mind_rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Earth</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_earth_cur" placeholder="Current" value="%characterDetails_earth_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_earth_rank" placeholder="Rank" value="%characterDetails_earth_rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Blood</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_blood_cur" placeholder="Current" value="%characterDetails_blood_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_blood_rank" placeholder="Rank" value="%characterDetails_blood_rank%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Flesh</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_flesh_cur" placeholder="Current" value="%characterDetails_flesh_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_flesh_rank" placeholder="Rank" value="%characterDetails_flesh_rank%"/>
            </div>
            <label class="col-sm-2 col-form-label">Wind</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_wind_cur" placeholder="Current" value="%characterDetails_wind_cur%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="characterDetails_wind_rank" placeholder="Rank" value="%characterDetails_wind_rank%"/>
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
    // Replacement tokens
    String sSubmitUrl = WEB_PAGE_TOOL_CHARACTER_MANAGER;
    String sOptionList_Gender;
    String sOptionList_Hair;
    String sOptionList_Eyes;
    String sOptionList_Handed;
    String sOptionList_PowerSet;
    String sOptionList_BaseRace;
    String sOptionList_TransformedRace;
    String sOptionList_CurrentWeaponSet;

    // Set page content
    String sPage = GetPageTemplate();
    BoostReplaceAll(sPage, "%submit_url%", sSubmitUrl);
    BoostReplaceAll(sPage, "%optionList_gender%", sOptionList_Gender);
    BoostReplaceAll(sPage, "%optionList_hair%", sOptionList_Hair);
    BoostReplaceAll(sPage, "%optionList_eyes%", sOptionList_Eyes);
    BoostReplaceAll(sPage, "%optionList_handed%", sOptionList_Handed);
    BoostReplaceAll(sPage, "%optionList_powerset%", sOptionList_PowerSet);
    BoostReplaceAll(sPage, "%optionList_baserace%", sOptionList_BaseRace);
    BoostReplaceAll(sPage, "%optionList_transformedrace%", sOptionList_TransformedRace);
    BoostReplaceAll(sPage, "%optionList_currentweaponset%", sOptionList_CurrentWeaponSet);
    BoostReplaceAll(sPage, "%createCharacter_charID%", "");
    BoostReplaceAll(sPage, "%deleteCharacter_charID%", "");
    BoostReplaceAll(sPage, "%generateCharacter_charID%", "");
    BoostReplaceAll(sPage, "%generateCharacter_textarea%", "");
    BoostReplaceAll(sPage, "%loadCharacterFromFile_charID%", "");
    BoostReplaceAll(sPage, "%loadCharacterFromFile_filename%", "");
    BoostReplaceAll(sPage, "%loadCharacterFromJson_charID%", "");
    BoostReplaceAll(sPage, "%loadCharacterFromJson_textarea%", "");
    BoostReplaceAll(sPage, "%saveCharacterToFile_charID%", "");
    BoostReplaceAll(sPage, "%saveCharacterToFile_filename%", "");
    BoostReplaceAll(sPage, "%unloadCharacter_charID%", "");
    BoostReplaceAll(sPage, "%characterDetails_charID%", "");
    BoostReplaceAll(sPage, "%characterDetails_fname%", "");
    BoostReplaceAll(sPage, "%characterDetails_lname%", "");
    BoostReplaceAll(sPage, "%characterDetails_age%", "");
    BoostReplaceAll(sPage, "%characterDetails_batk%", "");
    BoostReplaceAll(sPage, "%characterDetails_bdef%", "");
    BoostReplaceAll(sPage, "%characterDetails_eatk%", "");
    BoostReplaceAll(sPage, "%characterDetails_edef%", "");
    BoostReplaceAll(sPage, "%characterDetails_matk%", "");
    BoostReplaceAll(sPage, "%characterDetails_mdef%", "");
    BoostReplaceAll(sPage, "%characterDetails_patk%", "");
    BoostReplaceAll(sPage, "%characterDetails_pdef%", "");
    BoostReplaceAll(sPage, "%characterDetails_satk%", "");
    BoostReplaceAll(sPage, "%characterDetails_sdef%", "");
    BoostReplaceAll(sPage, "%characterDetails_hpcur%", "");
    BoostReplaceAll(sPage, "%characterDetails_hpmax%", "");
    BoostReplaceAll(sPage, "%characterDetails_hpregen%", "");
    BoostReplaceAll(sPage, "%characterDetails_hpdelta%", "");
    BoostReplaceAll(sPage, "%characterDetails_mpcur%", "");
    BoostReplaceAll(sPage, "%characterDetails_mpmax%", "");
    BoostReplaceAll(sPage, "%characterDetails_mpregen%", "");
    BoostReplaceAll(sPage, "%characterDetails_mpdelta%", "");
    BoostReplaceAll(sPage, "%characterDetails_epcur%", "");
    BoostReplaceAll(sPage, "%characterDetails_epmax%", "");
    BoostReplaceAll(sPage, "%characterDetails_epregen%", "");
    BoostReplaceAll(sPage, "%characterDetails_epdelta%", "");
    BoostReplaceAll(sPage, "%characterDetails_speed%", "");
    BoostReplaceAll(sPage, "%characterDetails_chest%", "");
    BoostReplaceAll(sPage, "%characterDetails_feet%", "");
    BoostReplaceAll(sPage, "%characterDetails_hands%", "");
    BoostReplaceAll(sPage, "%characterDetails_head%", "");
    BoostReplaceAll(sPage, "%characterDetails_legs%", "");
    BoostReplaceAll(sPage, "%characterDetails_neck%", "");
    BoostReplaceAll(sPage, "%characterDetails_leftfingers%", "");
    BoostReplaceAll(sPage, "%characterDetails_rightfingers%", "");
    BoostReplaceAll(sPage, "%characterDetails_weapon1left%", "");
    BoostReplaceAll(sPage, "%characterDetails_weapon1right%", "");
    BoostReplaceAll(sPage, "%characterDetails_weapon2left%", "");
    BoostReplaceAll(sPage, "%characterDetails_weapon2right%", "");
    BoostReplaceAll(sPage, "%characterDetails_bash_ap%", "");
    BoostReplaceAll(sPage, "%characterDetails_block_ap%", "");
    BoostReplaceAll(sPage, "%characterDetails_break_ap%", "");
    BoostReplaceAll(sPage, "%characterDetails_cleave_ap%", "");
    BoostReplaceAll(sPage, "%characterDetails_counter_ap%", "");
    BoostReplaceAll(sPage, "%characterDetails_crack_ap%", "");
    BoostReplaceAll(sPage, "%characterDetails_crush_ap%", "");
    BoostReplaceAll(sPage, "%characterDetails_cshot_ap%", "");
    BoostReplaceAll(sPage, "%characterDetails_decapitate_ap%", "");
    BoostReplaceAll(sPage, "%characterDetails_dodge_ap%", "");
    BoostReplaceAll(sPage, "%characterDetails_drill_ap%", "");
    BoostReplaceAll(sPage, "%characterDetails_impact_ap%", "");
    BoostReplaceAll(sPage, "%characterDetails_impale_ap%", "");
    BoostReplaceAll(sPage, "%characterDetails_parry_ap%", "");
    BoostReplaceAll(sPage, "%characterDetails_pierce_ap%", "");
    BoostReplaceAll(sPage, "%characterDetails_riposte_ap%", "");
    BoostReplaceAll(sPage, "%characterDetails_rush_ap%", "");
    BoostReplaceAll(sPage, "%characterDetails_sever_ap%", "");
    BoostReplaceAll(sPage, "%characterDetails_shoot_ap%", "");
    BoostReplaceAll(sPage, "%characterDetails_slash_ap%", "");
    BoostReplaceAll(sPage, "%characterDetails_slice_ap%", "");
    BoostReplaceAll(sPage, "%characterDetails_slit_ap%", "");
    BoostReplaceAll(sPage, "%characterDetails_smash_ap%", "");
    BoostReplaceAll(sPage, "%characterDetails_sstrike_ap%", "");
    BoostReplaceAll(sPage, "%characterDetails_alchemist_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_alchemist_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_ambidext_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_ambidext_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_avatar_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_avatar_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_barbarian_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_barbarian_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_bash_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_bash_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_blademaster_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_blademaster_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_block_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_block_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_blood_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_blood_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_bowbane_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_bowbane_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_bowsmith_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_bowsmith_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_break_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_break_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_chemist_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_chemist_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_cleave_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_cleave_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_counter_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_counter_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_crack_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_crack_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_crush_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_crush_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_cshot_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_cshot_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_dark_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_dark_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_decapitate_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_decapitate_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_dodge_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_dodge_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_drill_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_drill_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_earth_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_earth_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_energist_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_energist_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_fire_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_fire_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_flesh_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_flesh_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_focused_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_focused_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_force_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_force_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_goldbane_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_goldbane_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_goldsmith_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_goldsmith_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_hammerbane_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_hammerbane_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_hammersmith_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_hammersmith_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_healer_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_healer_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_holy_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_holy_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_ice_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_ice_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_impact_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_impact_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_impale_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_impale_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_light_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_light_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_mage_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_mage_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_mind_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_mind_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_parry_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_parry_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_pierce_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_pierce_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_platebane_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_platebane_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_platesmith_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_platesmith_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_riposte_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_riposte_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_rogue_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_rogue_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_rush_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_rush_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_scalebane_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_scalebane_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_scalesmith_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_scalesmith_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_sever_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_sever_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_shieldbane_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_shieldbane_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_shieldsmith_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_shieldsmith_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_shock_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_shock_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_shoot_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_shoot_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_slash_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_slash_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_slice_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_slice_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_slit_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_slit_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_smash_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_smash_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_spellbane_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_spellbane_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_spellsmith_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_spellsmith_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_sstrike_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_sstrike_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_stalwart_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_stalwart_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_studremover_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_studremover_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_swordbane_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_swordbane_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_swordsmith_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_swordsmith_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_tanner_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_tanner_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_threadbare_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_threadbare_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_weaver_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_weaver_rank%", "");
    BoostReplaceAll(sPage, "%characterDetails_wind_cur%", "");
    BoostReplaceAll(sPage, "%characterDetails_wind_rank%", "");
    SetPageContent(sPage);
}

};
