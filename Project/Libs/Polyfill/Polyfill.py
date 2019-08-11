# Source: https://github.com/NearlyTRex/polyfill
# Version: Gitmaster

# Steps
CopyFilePolyfillKeyboardJs = 'CopyFile("keyboard.js", "$(RootPath)/Data/Libs/keyboard.js")'

# Library info
Setup = {}
Setup['url'] = "https://github.com/NearlyTRex/polyfill/archive/master.zip"
Setup['extractdir'] = "polyfill-master"
Setup['steps'] = {}
Setup['steps']['all'] = []
Setup['steps']['all'].append(CopyFilePolyfillKeyboardJs)
