# Source: https://github.com/NearlyTRex/jQueryTerminal

# Steps
CopyFileJQueryTerminalCss = 'CopyFile("css/jquery.terminal.min.css", "$(RootPath)/Data/Libs/jquery.terminal.min.css")'
CopyFileJQueryTerminalCssMap = 'CopyFile("css/jquery.terminal.min.css.map", "$(RootPath)/Data/Libs/jquery.terminal.min.css.map")'
CopyFileJQueryTerminalJs = 'CopyFile("js/jquery.terminal.min.js", "$(RootPath)/Data/Libs/jquery.terminal.min.js")'
CopyFileJQueryTerminalJsMap = 'CopyFile("js/jquery.terminal.min.js.map", "$(RootPath)/Data/Libs/jquery.terminal.min.js.map")'
CopyFileJQueryMousewheelJs = 'CopyFile("js/jquery.mousewheel-min.js", "$(RootPath)/Data/Libs/jquery.mousewheel.min.js")'

# Library info
Setup = {}
Setup['steps'] = {}
Setup['steps']['all'] = []
Setup['steps']['all'].append(CopyFileJQueryTerminalCss)
Setup['steps']['all'].append(CopyFileJQueryTerminalCssMap)
Setup['steps']['all'].append(CopyFileJQueryTerminalJs)
Setup['steps']['all'].append(CopyFileJQueryTerminalJsMap)
Setup['steps']['all'].append(CopyFileJQueryMousewheelJs)
