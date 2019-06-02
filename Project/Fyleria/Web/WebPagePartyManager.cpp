// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Web/WebPagePartyManager.h"
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
            <label class="col-sm-2 col-form-label">Delete Party</label>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="deleteParty_partyID" placeholder="Party Identifier" value="%deleteParty_partyID%"/>
            </div>
            <div class="col-sm-4">
            </div>
            <div class="col-sm-2">
                <button type="submit" class="btn btn-primary form-control" name="action" value="deleteParty_submit">Run</button>
            </div>
        </div>
        <div class="form-group row">
            <label class="col-sm-2 col-form-label">Set As Current Party</label>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="setCurrentParty_partyID" placeholder="Party Identifier" value="%setCurrentParty_partyID%"/>
            </div>
            <div class="col-sm-2">
                <select class="form-control" name="setCurrentParty_partytype">
                    <option value="">Party Type...</option>
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
                    <option value="">Party Type...</option>
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
            <label class="col-sm-2 col-form-label">Save Party Changes</label>
            <div class="col-sm-8">
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
            <label class="col-sm-2 col-form-label">Current Party</label>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="currentParty_ally" placeholder="Ally Party" readonly="readonly" value="%currentParty_ally%"/>
            </div>
            <div class="col-sm-4">
                <input type="text" class="form-control" name="currentParty_enemy" placeholder="Enemy Party" readonly="readonly" value="%currentParty_enemy%"/>
            </div>
        </div>
        <div class="form-group row">
            <div class="col"><hr></div>
            <div class="col-auto">Party Details</div>
            <div class="col"><hr></div>
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
    // Replacement tokens
    String sSubmitUrl = WEB_PAGE_TOOL_PARTY_MANAGER;
    String sOptionList_PartyType;
    String sCreateParty_PartyID;
    String sCreateParty_SetAsCurrent;
    String sCurrentParty_Ally;
    String sCurrentParty_Enemy;
    String sDeleteParty_PartyID;
    String sLoadPartyFromFile_Filename;
    String sLoadPartyFromFile_PartyID;
    String sLoadPartyFromJson_Textarea;
    String sLoadPartyFromJson_PartyID;
    String sSavePartyToFile_Filename;
    String sSavePartyToFile_PartyID;
    String sSetCurrentParty_PartyID;
    String sUnloadParty_PartyID;

    // Set page content
    String sPage = GetPageTemplate();
    BoostReplaceAll(sPage, "%submit_url%", sSubmitUrl);
    BoostReplaceAll(sPage, "%optionList_partytype%", sOptionList_PartyType);
    BoostReplaceAll(sPage, "%createParty_partyID%", sCreateParty_PartyID);
    BoostReplaceAll(sPage, "%createParty_setascurrent%", sCreateParty_SetAsCurrent);
    BoostReplaceAll(sPage, "%currentParty_ally%", sCurrentParty_Ally);
    BoostReplaceAll(sPage, "%currentParty_enemy%", sCurrentParty_Enemy);
    BoostReplaceAll(sPage, "%deleteParty_partyID%", sDeleteParty_PartyID);
    BoostReplaceAll(sPage, "%loadPartyFromFile_filename%", sLoadPartyFromFile_Filename);
    BoostReplaceAll(sPage, "%loadPartyFromFile_partyID%", sLoadPartyFromFile_PartyID);
    BoostReplaceAll(sPage, "%loadPartyFromJson_textarea%", sLoadPartyFromJson_Textarea);
    BoostReplaceAll(sPage, "%loadPartyFromJson_partyID%", sLoadPartyFromJson_PartyID);
    BoostReplaceAll(sPage, "%savePartyToFile_filename%", sSavePartyToFile_Filename);
    BoostReplaceAll(sPage, "%savePartyToFile_partyID%", sSavePartyToFile_PartyID);
    BoostReplaceAll(sPage, "%setCurrentParty_partyID%", sSetCurrentParty_PartyID);
    BoostReplaceAll(sPage, "%unloadParty_partyID%", sUnloadParty_PartyID);
    SetPageContent(sPage);
}

};
