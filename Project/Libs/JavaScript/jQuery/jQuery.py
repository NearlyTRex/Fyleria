# Source: https://github.com/NearlyTRex/jQuery

# Steps
Build = 'RunProcess("npm run build")'
CopyFileJQueryJs = 'CopyFile("dist/jquery.min.js", "$(RootPath)/Data/Libs/jquery.min.js")'

# Library info
Setup = {}
Setup['steps'] = {}
Setup['steps']['all'] = []
Setup['steps']['all'].append(Build)
Setup['steps']['all'].append(CopyFileJQueryJs)
