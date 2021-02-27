# Source: https://github.com/NearlyTRex/Screenfull

# Steps
CopyFileScreenfullJs = 'CopyFile("dist/screenfull.min.js", "$(RootPath)/Data/Libs/screenfull.min.js")'

# Library info
Setup = {}
Setup['steps'] = {}
Setup['steps']['all'] = []
Setup['steps']['all'].append(CopyFileScreenfullJs)
