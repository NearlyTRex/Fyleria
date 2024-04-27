# Steps
MakejQueryDir = 'MakeDirectory("$(RootPath)/Data/Libs/ThirdParty/jQuery")'
CopyFileJQueryJs = 'CopyFile("dist/jquery.min.js", "$(RootPath)/Data/Libs/ThirdParty/jQuery/jquery.min.js")'

# Library info
Setup = {}
Setup["url"] = "https://github.com/NearlyTRex/jQuery"
Setup['steps'] = {}
Setup['steps']['all'] = []
Setup['steps']['all'].append(MakejQueryDir)
Setup['steps']['all'].append(CopyFileJQueryJs)
