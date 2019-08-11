# Source: https://github.com/NearlyTRex/screenfull.js
# Version: Gitmaster

# Steps
CopyFileScreenfullJs = 'CopyFile("dist/screenfull.min.js", "$(RootPath)/Data/Libs/screenfull.min.js")'

# Library info
Setup = {}
Setup['url'] = "https://github.com/NearlyTRex/screenfull.js/archive/gh-pages.zip"
Setup['extractdir'] = "screenfull.js-gh-pages"
Setup['steps'] = {}
Setup['steps']['all'] = []
Setup['steps']['all'].append(CopyFileScreenfullJs)
