# Steps
MakeBootstrapDir = 'MakeDirectory("$(RootPath)/Data/Libs/ThirdParty/Bootstrap")'
CopyFileBootstrapCss = 'CopyFile("dist/css/bootstrap.min.css", "$(RootPath)/Data/Libs/ThirdParty/Bootstrap/bootstrap.min.css")'
CopyFileBootstrapCssMap = 'CopyFile("dist/css/bootstrap.min.css.map", "$(RootPath)/Data/Libs/ThirdParty/Bootstrap/bootstrap.min.css.map")'
CopyFileBootstrapJs = 'CopyFile("dist/js/bootstrap.min.js", "$(RootPath)/Data/Libs/ThirdParty/Bootstrap/bootstrap.min.js")'
CopyFileBootstrapJsMap = 'CopyFile("dist/js/bootstrap.min.js.map", "$(RootPath)/Data/Libs/ThirdParty/Bootstrap/bootstrap.min.js.map")'

# Library info
Setup = {}
Setup["url"] = "https://github.com/NearlyTRex/Bootstrap"
Setup['steps'] = {}
Setup['steps']['all'] = []
Setup['steps']['all'].append(MakeBootstrapDir)
Setup['steps']['all'].append(CopyFileBootstrapCss)
Setup['steps']['all'].append(CopyFileBootstrapCssMap)
Setup['steps']['all'].append(CopyFileBootstrapJs)
Setup['steps']['all'].append(CopyFileBootstrapJsMap)
