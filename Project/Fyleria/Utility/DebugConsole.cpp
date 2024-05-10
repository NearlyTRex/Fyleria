// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Utility/DebugConsole.h"
#include "Utility/Boost.h"

// Console html
const char* sConsoleHTML = R"CONSOLE_HTML(
<div id="debug_console"></div>
)CONSOLE_HTML";

// Console javascript header
const char* sConsoleJavaScriptHeader = R"CONSOLE_JS_HEAD(
(function($) {
    $.fn.debug_console = function(eval, options) {
        if ($('body').data('debug_console')) {
            return $('body').data('debug_console').terminal;
        }
        this.addClass('debug_console');
        options = options || {};
        eval = eval || function(command, term) {
            term.echo("No debug command handler set");
        };
        var settings = {
            name: 'Debug',
            prompt: '$ ',
            height: 200,
            enabled: false,
            completion: true,
            greetings: "Fyleria debug console.\nType 'help' to invoke help.\nType ~ to exit.",
            keypress: function(e) {
                if (e.which == 96) {
                    return false;
                }
            }
        };
        if (options) {
            $.extend(settings, options);
        }
        this.append('<div class="td"></div>');
        var self = this;
        self.terminal = this.find('.td').terminal(eval, settings);
        var focus = false;
        $(document.documentElement).keypress(function(e) {
            if (e.which == 96) {
                self.slideToggle('fast');
                self.terminal.focus(focus = !focus);
                self.terminal.attr({
                    scrollTop: self.terminal.attr("scrollHeight")
                });
            }
        });
        $('body').data('debug_console', this);
        this.hide();
        return self;
    };
})(jQuery);
var cmds = {};
)CONSOLE_JS_HEAD";

// Console javascript footer
const char* sConsoleJavaScriptFooter = R"CONSOLE_JS_FOOT(
jQuery(document).ready(function($) {
    $('#debug_console').debug_console(cmds);
});
)CONSOLE_JS_FOOT";

namespace Gecko
{

DebugConsole::DebugConsole()
{
}

DebugConsole::~DebugConsole()
{
}

void DebugConsole::AddCommand(const String& sName, const StringArray& vArgs)
{
    // Add command
    GetCommands().push_back(DebugCommand(sName, vArgs));
}

void DebugConsole::ClearCommands()
{
    // Clear commands
    GetCommands().clear();
}

String DebugConsole::GenerateConsoleHTML() const
{
    // Generate html
    String sHtml(sConsoleHTML);
    return sHtml;
}

String DebugConsole::GenerateConsoleJavaScript() const
{
    // Generate javascript
    String sJavaScript;
    sJavaScript += sConsoleJavaScriptHeader;
    sJavaScript += "cmds.help = " + CreateHelpFunction() + ";\n";
    for (auto it : CreateRegisteredFunctions())
    {
        sJavaScript += "cmds." + it.first + " = " + it.second + ";\n";
    }
    sJavaScript += sConsoleJavaScriptFooter;
    return sJavaScript;
}

String DebugConsole::CreateHelpFunction() const
{
    // Create help function
    String sFunction;
    sFunction = "function() {\n";
    sFunction += "\tvar command_list = [\"clear\"];\n";
    sFunction += "\tfor(var key in cmds) {\n";
    sFunction += "\t\tcommand_list.push(key);\n";
    sFunction += "\t}\n";
    sFunction += "\treturn \"Available commands are \" + command_list.join(\", \");\n";
    sFunction += "}";
    return sFunction;
}

StringStringUnorderedMap DebugConsole::CreateRegisteredFunctions() const
{
    // Create registered functions
    StringStringUnorderedMap vFunctions;
    for (auto& cmd : GetCommands())
    {
        String sCmdName = cmd.GetName();
        String sCmdArgs = BoostJoin(cmd.GetArgs(), ", ");
        String sFunction;
        sFunction = "function(" + sCmdArgs + ") {\n";
        sFunction += "\twindow." + sCmdName + "(" + sCmdArgs + ");\n";
        sFunction += "}";
        vFunctions[sCmdName] = sFunction;
    }
    return vFunctions;
}

};
