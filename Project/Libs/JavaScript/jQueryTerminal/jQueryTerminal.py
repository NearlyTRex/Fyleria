# Steps
MakejQueryTerminalDir = 'MakeDirectory("$(RootPath)/Data/Libs/ThirdParty/jQueryTerminal")'
CopyFileJQueryTerminalCss = 'CopyFile("css/jquery.terminal.min.css", "$(RootPath)/Data/Libs/ThirdParty/jQueryTerminal/jquery.terminal.min.css")'
CopyFileJQueryTerminalCssMap = 'CopyFile("css/jquery.terminal.min.css.map", "$(RootPath)/Data/Libs/ThirdParty/jQueryTerminal/jquery.terminal.min.css.map")'
CopyFileJQueryTerminalJs = 'CopyFile("js/jquery.terminal.min.js", "$(RootPath)/Data/Libs/ThirdParty/jQueryTerminal/jquery.terminal.min.js")'
CopyFileJQueryTerminalJsMap = 'CopyFile("js/jquery.terminal.min.js.map", "$(RootPath)/Data/Libs/ThirdParty/jQueryTerminal/jquery.terminal.min.js.map")'

# Library info
Setup = {}
Setup["url"] = "https://github.com/NearlyTRex/jQueryTerminal"
Setup['steps'] = {}
Setup['steps']['all'] = []
Setup['steps']['all'].append(MakejQueryTerminalDir)
Setup['steps']['all'].append(CopyFileJQueryTerminalCss)
Setup['steps']['all'].append(CopyFileJQueryTerminalCssMap)
Setup['steps']['all'].append(CopyFileJQueryTerminalJs)
Setup['steps']['all'].append(CopyFileJQueryTerminalJsMap)
