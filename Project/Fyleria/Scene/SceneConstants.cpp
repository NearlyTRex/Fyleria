// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Scene/SceneConstants.h"

// Starting information
const Gecko::String Gecko::STARTING_URI                         = "about:blank";
const Gecko::String Gecko::STARTING_SCENE                       = "Start";

// Third-party files
const Gecko::String Gecko::THIRDPARTY_FILE_JQUERY_JS            = "ThirdParty/jQuery/jquery.min.js";
const Gecko::String Gecko::THIRDPARTY_FILE_JQUERY_TERMINAL_CSS  = "ThirdParty/jQueryTerminal/jquery.terminal.min.css";
const Gecko::String Gecko::THIRDPARTY_FILE_JQUERY_TERMINAL_JS   = "ThirdParty/jQueryTerminal/jquery.terminal.min.js";
const Gecko::String Gecko::THIRDPARTY_FILE_PHASER_JS            = "ThirdParty/Phaser/phaser.min.js";

// Common styles
const Gecko::String Gecko::COMMON_CSS_DISABLE_USER_SELECTIONS = R"(
body{-webkit-touch-callout:none;-webkit-user-select:none;-khtml-user-select:none;-moz-user-select:none;-ms-user-select:none;user-select:none}
)";

// Common scripts
const Gecko::String Gecko::COMMON_JS_DISABLE_SUBMIT_ACTIONS = R"(
document.addEventListener("submit",e=>e.preventDefault())
)";
const Gecko::String Gecko::COMMON_JS_DISABLE_CONTEXT_MENU = R"(
document.addEventListener("contextmenu",e=>e.preventDefault())
)";
const Gecko::String Gecko::COMMON_JS_DISABLE_CTRL_SHORTCUTS = R"(
document.addEventListener("keydown",e=>{e.ctrlKey&&"cvxspwuazr".indexOf(e.key)!==-1&&e.preventDefault()})
)";

// Common markups
const Gecko::String Gecko::COMMON_HTML_SCENE_SELECTOR = R"(
<label for="SceneSelector">Switch to scene:</label>
<select id="SceneSelector">
    <option value="None">Select Scene...</option>
    <option value="Battle">Battle</option>
    <option value="CharacterCreation">CharacterCreation</option>
    <option value="CraftingMenu">CraftingMenu</option>
    <option value="Credits">Credits</option>
    <option value="Intro">Intro</option>
    <option value="Loading">Loading</option>
    <option value="MainMenu">MainMenu</option>
    <option value="Map">Map</option>
    <option value="SaveMenu">SaveMenu</option>
    <option value="Shop">Shop</option>
    <option value="Start">Start</option>
    <option value="StatusMenu">StatusMenu</option>
    <option value="ToolCharacter">ToolCharacter</option>
    <option value="ToolParty">ToolParty</option>
    <option value="ToolSave">ToolSave</option>
</select>
<script>
var sceneSelector = document.getElementById("SceneSelector");
sceneSelector.addEventListener("change", function() {
    if (sceneSelector.value !== "None") {
        SwitchToScene(sceneSelector.value);
    }
});
</script>
)";
