# Source: https://github.com/NearlyTRex/jQuery

# Steps
CopyFileJQueryJs = 'CopyFile("dist/jquery.min.js", "$(RootPath)/Data/Libs/jquery.min.js")'
CopyFileJQuerySlimJs = 'CopyFile("dist/jquery.slim.min.js", "$(RootPath)/Data/Libs/jquery.slim.min.js")'

# Library info
Setup = {}
Setup['steps'] = {}
Setup['steps']['all'] = []
Setup['steps']['all'].append(CopyFileJQueryJs)
Setup['steps']['all'].append(CopyFileJQuerySlimJs)
