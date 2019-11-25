# Source: https://github.com/NearlyTRex/Screenfull
# Version: 5.0.0

# Steps
CopyFileScreenfullJs = 'CopyFile("dist/screenfull.min.js", "$(RootPath)/Data/Libs/screenfull.min.js")'

# Library info
Setup = {}
Setup['url'] = "https://github.com/NearlyTRex/Screenfull/archive/Screenfull-5.0.0.zip"
Setup['extractdir'] = "Screenfull-Screenfull-5.0.0"
Setup['steps'] = {}
Setup['steps']['all'] = []
Setup['steps']['all'].append(CopyFileScreenfullJs)
