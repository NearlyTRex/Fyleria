// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Web/WebPagePartyManager.h"
#include "Character/CharacterTypes.h"
#include "Items/ItemTypes.h"
#include "Utility/Constants.h"

namespace Gecko
{

WebPagePartyManager::WebPagePartyManager()
    : WebPage()
{
    SetPageTemplate(R"TEMPLATE(
<!DOCTYPE html>
<html lang="en-GB">
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <title>Party Manager</title>
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
            <label class="col-sm-2 col-form-label">Load From JSON</label>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="loadPartyFromJson_partyID" placeholder="Party Identifier" value="%loadPartyFromJson_partyID%"/>
            </div>
            <div class="col-sm-4">
                <textarea style="resize: none;" class="form-control" rows="3" name="loadPartyFromJson_textarea" placeholder="Raw party json">%loadPartyFromJson_textarea%</textarea>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="loadPartyFromJson_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Load From File</label>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="loadPartyFromFile_partyID" placeholder="Party Identifier" value="%loadPartyFromFile_partyID%"/>
            </div>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="loadPartyFromFile_filename" placeholder="Filename" value="%loadPartyFromFile_filename%"/>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="loadPartyFromFile_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Save To File</label>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="savePartyToFile_partyID" placeholder="Party Identifier" value="%savePartyToFile_partyID%"/>
            </div>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="savePartyToFile_filename" placeholder="Filename" value="%savePartyToFile_filename%"/>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="savePartyToFile_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Unload Party</label>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="unloadParty_partyID" placeholder="Party Identifier" value="%unloadParty_partyID%"/>
            </div>
            <div class="col-sm-4">
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="unloadParty_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Set As Current Party</label>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="setCurrentParty_partyID" placeholder="Party Identifier" value="%setCurrentParty_partyID%"/>
            </div>
            <div class="col-sm-2">
                <select class="form-control" name="setCurrentParty_partytype">
                    <option value="" disabled="disabled">Party Type...</option>
                    %optionList_partytype%
                </select>
            </div>
            <div class="col-sm-2">
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="setCurrentParty_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Create Party</label>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="createParty_partyID" placeholder="Party Identifier" value="%createParty_partyID%"/>
            </div>
            <div class="col-sm-2">
                <select class="form-control" name="createParty_partytype">
                    <option value="" disabled="disabled">Party Type...</option>
                    %optionList_partytype%
                </select>
            </div>
            <div class="col-sm-2">
                <div class="form-check">
                    <input class="form-check-input" type="checkbox" value="current" name="createParty_setascurrent" checked="%createParty_setascurrent%"/>
                    <label class="form-check-label" for="createParty_setascurrent">
                        Set as current
                    </label>
                </div>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="createParty_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Add Member</label>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="addMember_partyID" placeholder="Party Identifier" value="%addMember_partyID%"/>
            </div>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="addMember_charID" placeholder="Character Identifier" value="%addMember_charID%"/>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="addMember_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Remove Member</label>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="removeMember_partyID" placeholder="Party Identifier" value="%removeMember_partyID%"/>
            </div>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="removeMember_charID" placeholder="Character Identifier" value="%removeMember_charID%"/>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="removeMember_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Move Member</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="moveMember_partyID" placeholder="Party Identifier" value="%moveMember_partyID%"/>
            </div>
            <div class="col-sm-3">
                <input type="text" class="form-control" name="moveMember_charID" placeholder="Character Identifier" value="%moveMember_charID%"/>
            </div>
            <div class="col-sm-3">
                <select class="form-control" name="moveMember_charTargetType">
                    <option value="" disabled="disabled">Character Target Type...</option>
                    %optionList_chartargettype%
                </select>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="moveMember_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Swap Member</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="swapMember_partyID" placeholder="Party Identifier" value="%swapMember_partyID%"/>
            </div>
            <div class="col-sm-3">
                <input type="text" class="form-control" name="swapMember_first_charID" placeholder="First Character Identifier" value="%swapMember_first_charID%"/>
            </div>
            <div class="col-sm-3">
                <input type="text" class="form-control" name="swapMember_second_charID" placeholder="Second Character Identifier" value="%swapMember_second_charID%"/>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="swapMember_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Add Item</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="addItem_partyID" placeholder="Party Identifier" value="%addItem_partyID%"/>
            </div>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="addItem_itemName" placeholder="Item Name" value="%addItem_itemName%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="addItem_itemAmount" placeholder="Item Amount" value="%addItem_itemAmount%"/>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="addItem_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Add Random Items</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="addRandomItems_partyID" placeholder="Party Identifier" value="%addRandomItems_partyID%"/>
            </div>
            <div class="col-sm-2">
                <select class="form-control" name="addRandomItems_itemtreetype">
                    <option value="" disabled="disabled">Item Tree Type...</option>
                    %optionList_itemtreetype%
                </select>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="addRandomItems_itemCount" placeholder="Item Count" value="%addRandomItems_itemCount%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="addRandomItems_itemAmount" placeholder="Item Amount" value="%addRandomItems_itemAmount%"/>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="addItem_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Remove Item</label>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="removeItem_partyID" placeholder="Party Identifier" value="%removeItem_partyID%"/>
            </div>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="removeItem_itemName" placeholder="Item Name" value="%removeItem_itemName%"/>
            </div>
            <div class="col-sm-2">
                <input type="text" class="form-control" name="removeItem_itemAmount" placeholder="Item Amount" value="%removeItem_itemAmount%"/>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="removeItem_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Equip Best Items</label>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="equipBestItems_partyID" placeholder="Party Identifier" value="%equipBestItems_partyID%"/>
            </div>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="equipBestItems_charID" placeholder="Character Identifier" value="%equipBestItems_charID%"/>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="equipBestItems_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Unequip Best Items</label>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="unequipBestItems_partyID" placeholder="Party Identifier" value="%unequipBestItems_partyID%"/>
            </div>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="unequipBestItems_charID" placeholder="Character Identifier" value="%unequipBestItems_charID%"/>
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="unequipBestItems_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Equip Best Items</label>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="equipBestItemsAllMembers_partyID" placeholder="Party Identifier" value="%equipBestItemsAllMembers_partyID%"/>
            </div>
            <div class="col-sm-4">
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="equipBestItemsAllMembers_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Unequip Best Items</label>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="unequipBestItemsAllMembers_partyID" placeholder="Party Identifier" value="%unequipBestItemsAllMembers_partyID%"/>
            </div>
            <div class="col-sm-4">
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="unequipBestItemsAllMembers_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Display Party</label>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="displayParty_partyID" placeholder="Party Identifier" value="%displayParty_partyID%"/>
            </div>
            <div class="col-sm-4">
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="displayParty_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-4 col-form-label">Save Party Changes</label>
            <div class="col-sm-6">
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="saveParty_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <div class="col"><hr></div>
            <div class="col-auto">Party List</div>
            <div class="col"><hr></div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Current Ally Party</label>
            <div class="col-sm-4">
                <input type="text" class="form-control" readonly="readonly" value="%currentParty_ally%"/>
            </div>
            <label class="col-sm-2 col-form-label">Current Enemy Party</label>
            <div class="col-sm-4">
                <input type="text" class="form-control" readonly="readonly" value="%currentParty_enemy%"/>
            </div>
        </div>
        <div class="form-group row">
            <div class="col"><hr></div>
            <div class="col-auto">Party Details</div>
            <div class="col"><hr></div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Party ID</label>
            <div class="col-sm-4">
                <input type="text" class="form-control" readonly="readonly" value="%partyDetails_partyID%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Party Type</label>
            <div class="col-sm-4">
                <select class="form-control" name="partyDetails_partytype">
                    <option value="" disabled="disabled">Party Type...</option>
                    %optionList_partytype%
                </select>
            </div>
            <label class="col-sm-2 col-form-label">Play Time</label>
            <div class="col-sm-4">
                <input type="text" class="form-control" value="%partyDetails_playtime%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Taken Target Types</label>
            <div class="col-sm-10">
                <input type="text" class="form-control" readonly="readonly" value="%partyDetails_takenTargetTypes%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Available Target Types</label>
            <div class="col-sm-10">
                <input type="text" class="form-control" readonly="readonly" value="%partyDetails_availableTargetTypes%"/>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Members</label>
            <div class="col-sm-10">
                <textarea style="resize: none;" class="form-control" rows="4" readonly="readonly">%partyDetails_members%</textarea>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Items</label>
            <div class="col-sm-10">
                <textarea style="resize: none;" class="form-control" rows="4" readonly="readonly">%partyDetails_items%</textarea>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Description</label>
            <div class="col-sm-10">
                <textarea style="resize: none;" class="form-control" rows="4" readonly="readonly">%partyDetails_description%</textarea>
            </div>
        </div>
    </form>
</div>
</html>
)TEMPLATE");
}

WebPagePartyManager::~WebPagePartyManager()
{
}

void WebPagePartyManager::UpdatePageContent(const ParameterMapType& tParams)
{
    // Build option lists
    MAKE_HTML_OPTION_LIST_STRING(CharacterPartyType);
    MAKE_HTML_OPTION_LIST_STRING(CharacterResolvedTargetType);
    MAKE_HTML_OPTION_LIST_STRING(ItemTreeType);

    // Get fields
    String sAction = GET_MAP_DATA_OR_DEFAULT(tParams, "action", "");
    String sCreateParty_PartyID = GET_MAP_DATA_OR_DEFAULT(tParams, "createParty_partyID", "");
    String sCreateParty_SetAsCurrent = GET_MAP_DATA_OR_DEFAULT(tParams, "createParty_setascurrent", "");
    String sLoadPartyFromFile_Filename = GET_MAP_DATA_OR_DEFAULT(tParams, "loadPartyFromFile_filename", "");
    String sLoadPartyFromFile_PartyID = GET_MAP_DATA_OR_DEFAULT(tParams, "loadPartyFromFile_partyID", "");
    String sLoadPartyFromJson_Textarea = GET_MAP_DATA_OR_DEFAULT(tParams, "loadPartyFromJson_textarea", "");
    String sLoadPartyFromJson_PartyID = GET_MAP_DATA_OR_DEFAULT(tParams, "loadPartyFromJson_partyID", "");
    String sSavePartyToFile_Filename = GET_MAP_DATA_OR_DEFAULT(tParams, "savePartyToFile_filename", "");
    String sSavePartyToFile_PartyID = GET_MAP_DATA_OR_DEFAULT(tParams, "savePartyToFile_partyID", "");
    String sSetCurrentParty_PartyID = GET_MAP_DATA_OR_DEFAULT(tParams, "setCurrentParty_partyID", "");
    String sUnloadParty_PartyID = GET_MAP_DATA_OR_DEFAULT(tParams, "unloadParty_partyID", "");
    String sAddMember_PartyID = GET_MAP_DATA_OR_DEFAULT(tParams, "addMember_partyID", "");
    String sAddMember_CharID = GET_MAP_DATA_OR_DEFAULT(tParams, "addMember_charID", "");
    String sRemoveMember_PartyID = GET_MAP_DATA_OR_DEFAULT(tParams, "removeMember_partyID", "");
    String sRemoveMember_CharID = GET_MAP_DATA_OR_DEFAULT(tParams, "removeMember_charID", "");
    String sMoveMember_PartyID = GET_MAP_DATA_OR_DEFAULT(tParams, "moveMember_partyID", "");
    String sMoveMember_CharID = GET_MAP_DATA_OR_DEFAULT(tParams, "moveMember_charID", "");
    String sSwapMember_PartyID = GET_MAP_DATA_OR_DEFAULT(tParams, "swapMember_partyID", "");
    String sSwapMember_First_CharID = GET_MAP_DATA_OR_DEFAULT(tParams, "swapMember_first_charID", "");
    String sSwapMember_Second_CharID = GET_MAP_DATA_OR_DEFAULT(tParams, "swapMember_second_charID", "");
    String sAddItem_PartyID = GET_MAP_DATA_OR_DEFAULT(tParams, "addItem_partyID", "");
    String sAddItem_ItemName = GET_MAP_DATA_OR_DEFAULT(tParams, "addItem_itemName", "");
    String sAddItem_ItemAmount = GET_MAP_DATA_OR_DEFAULT(tParams, "addItem_itemAmount", "");
    String sAddRandomItems_PartyID = GET_MAP_DATA_OR_DEFAULT(tParams, "addRandomItems_partyID", "");
    String sAddRandomItems_ItemCount = GET_MAP_DATA_OR_DEFAULT(tParams, "addRandomItems_itemCount", "");
    String sAddRandomItems_ItemAmount = GET_MAP_DATA_OR_DEFAULT(tParams, "addRandomItems_itemAmount", "");
    String sRemoveItem_PartyID = GET_MAP_DATA_OR_DEFAULT(tParams, "removeItem_partyID", "");
    String sRemoveItem_ItemName = GET_MAP_DATA_OR_DEFAULT(tParams, "removeItem_itemName", "");
    String sRemoveItem_ItemAmount = GET_MAP_DATA_OR_DEFAULT(tParams, "removeItem_itemAmount", "");
    String sEquipBestItems_PartyID = GET_MAP_DATA_OR_DEFAULT(tParams, "equipBestItems_partyID", "");
    String sEquipBestItems_CharID = GET_MAP_DATA_OR_DEFAULT(tParams, "equipBestItems_charID", "");
    String sUnequipBestItems_PartyID = GET_MAP_DATA_OR_DEFAULT(tParams, "unequipBestItems_partyID", "");
    String sUnequipBestItems_CharID = GET_MAP_DATA_OR_DEFAULT(tParams, "unequipBestItems_charID", "");
    String sEquipBestItemsAllMembers_PartyID = GET_MAP_DATA_OR_DEFAULT(tParams, "equipBestItemsAllMembers_partyID", "");
    String sUnequipBestItemsAllMembers_PartyID = GET_MAP_DATA_OR_DEFAULT(tParams, "unequipBestItemsAllMembers_partyID", "");
    String sDisplayParty_PartyID = GET_MAP_DATA_OR_DEFAULT(tParams, "displayParty_partyID", "");

    // Get current parties
    String sCurrentParty_Ally;
    String sCurrentParty_Enemy;

    // Get party details
    String sPartyDetails_PartyID;
    String sPartyDetails_PlayTime;
    String sPartyDetails_TakenTargetTypes;
    String sPartyDetails_AvailableTargetTypes;
    String sPartyDetails_Members;
    String sPartyDetails_Items;
    String sPartyDetails_Description;

    // Set page content
    String sPage = GetPageTemplate();
    BoostReplaceAll(sPage, "%submit_url%", WEB_PAGE_TOOL_PARTY_MANAGER);
    BoostReplaceAll(sPage, "%optionList_partytype%", sOptionList_CharacterPartyType);
    BoostReplaceAll(sPage, "%optionList_chartargettype%", sOptionList_CharacterResolvedTargetType);
    BoostReplaceAll(sPage, "%optionList_itemtreetype%", sOptionList_ItemTreeType);
    BoostReplaceAll(sPage, "%createParty_partyID%", sCreateParty_PartyID);
    BoostReplaceAll(sPage, "%createParty_setascurrent%", sCreateParty_SetAsCurrent);
    BoostReplaceAll(sPage, "%loadPartyFromFile_filename%", sLoadPartyFromFile_Filename);
    BoostReplaceAll(sPage, "%loadPartyFromFile_partyID%", sLoadPartyFromFile_PartyID);
    BoostReplaceAll(sPage, "%loadPartyFromJson_textarea%", sLoadPartyFromJson_Textarea);
    BoostReplaceAll(sPage, "%loadPartyFromJson_partyID%", sLoadPartyFromJson_PartyID);
    BoostReplaceAll(sPage, "%savePartyToFile_filename%", sSavePartyToFile_Filename);
    BoostReplaceAll(sPage, "%savePartyToFile_partyID%", sSavePartyToFile_PartyID);
    BoostReplaceAll(sPage, "%setCurrentParty_partyID%", sSetCurrentParty_PartyID);
    BoostReplaceAll(sPage, "%unloadParty_partyID%", sUnloadParty_PartyID);
    BoostReplaceAll(sPage, "%addMember_partyID%", sAddMember_PartyID);
    BoostReplaceAll(sPage, "%addMember_charID%", sAddMember_CharID);
    BoostReplaceAll(sPage, "%removeMember_partyID%", sRemoveMember_PartyID);
    BoostReplaceAll(sPage, "%removeMember_charID%", sRemoveMember_CharID);
    BoostReplaceAll(sPage, "%moveMember_partyID%", sMoveMember_PartyID);
    BoostReplaceAll(sPage, "%moveMember_charID%", sMoveMember_CharID);
    BoostReplaceAll(sPage, "%swapMember_partyID%", sSwapMember_PartyID);
    BoostReplaceAll(sPage, "%swapMember_first_charID%", sSwapMember_First_CharID);
    BoostReplaceAll(sPage, "%swapMember_second_charID%", sSwapMember_Second_CharID);
    BoostReplaceAll(sPage, "%addItem_partyID%", sAddItem_PartyID);
    BoostReplaceAll(sPage, "%addItem_itemName%", sAddItem_ItemName);
    BoostReplaceAll(sPage, "%addItem_itemAmount%", sAddItem_ItemAmount);
    BoostReplaceAll(sPage, "%addRandomItems_partyID%", sAddRandomItems_PartyID);
    BoostReplaceAll(sPage, "%addRandomItems_itemCount%", sAddRandomItems_ItemCount);
    BoostReplaceAll(sPage, "%addRandomItems_itemAmount%", sAddRandomItems_ItemAmount);
    BoostReplaceAll(sPage, "%removeItem_partyID%", sRemoveItem_PartyID);
    BoostReplaceAll(sPage, "%removeItem_itemName%", sRemoveItem_ItemName);
    BoostReplaceAll(sPage, "%removeItem_itemAmount%", sRemoveItem_ItemAmount);
    BoostReplaceAll(sPage, "%equipBestItems_partyID%", sEquipBestItems_PartyID);
    BoostReplaceAll(sPage, "%equipBestItems_charID%", sEquipBestItems_CharID);
    BoostReplaceAll(sPage, "%unequipBestItems_partyID%", sUnequipBestItems_PartyID);
    BoostReplaceAll(sPage, "%unequipBestItems_charID%", sUnequipBestItems_CharID);
    BoostReplaceAll(sPage, "%equipBestItemsAllMembers_partyID%", sEquipBestItemsAllMembers_PartyID);
    BoostReplaceAll(sPage, "%unequipBestItemsAllMembers_partyID%", sUnequipBestItemsAllMembers_PartyID);
    BoostReplaceAll(sPage, "%displayParty_partyID%", sDisplayParty_PartyID);
    BoostReplaceAll(sPage, "%currentParty_ally%", sCurrentParty_Ally);
    BoostReplaceAll(sPage, "%currentParty_enemy%", sCurrentParty_Enemy);
    BoostReplaceAll(sPage, "%partyDetails_partyID%", sPartyDetails_PartyID);
    BoostReplaceAll(sPage, "%partyDetails_playtime%", sPartyDetails_PlayTime);
    BoostReplaceAll(sPage, "%partyDetails_takenTargetTypes%", sPartyDetails_TakenTargetTypes);
    BoostReplaceAll(sPage, "%partyDetails_availableTargetTypes%", sPartyDetails_AvailableTargetTypes);
    BoostReplaceAll(sPage, "%partyDetails_members%", sPartyDetails_Members);
    BoostReplaceAll(sPage, "%partyDetails_items%", sPartyDetails_Items);
    BoostReplaceAll(sPage, "%partyDetails_description%", sPartyDetails_Description);
    SetPageContent(sPage);
}

};
