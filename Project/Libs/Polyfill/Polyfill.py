# Source: https://github.com/NearlyTRex/polyfill
# Version: Gitmaster

# Steps
MinifyFilePolyfillKeyboardJs = 'MinifyFile("keyboard.js", "keyboard.min.js")'
CopyFilePolyfillKeyboardJs = 'CopyFile("keyboard.min.js", "$(RootPath)/Data/Libs/polyfill.keyboard.min.js")'

# Library info
Setup = {}
Setup['url'] = "https://github.com/NearlyTRex/polyfill/archive/master.zip"
Setup['extractdir'] = "polyfill-master"
Setup['steps'] = {}
Setup['steps']['all'] = []
Setup['steps']['all'].append(MinifyFilePolyfillKeyboardJs)
Setup['steps']['all'].append(CopyFilePolyfillKeyboardJs)
