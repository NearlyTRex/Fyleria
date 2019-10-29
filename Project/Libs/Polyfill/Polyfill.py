# Source: https://github.com/NearlyTRex/Polyfill
# Version: 0.1.41

# Steps
MinifyFilePolyfillKeyboardJs = 'MinifyFile("keyboard.js", "keyboard.min.js")'
CopyFilePolyfillKeyboardJs = 'CopyFile("keyboard.min.js", "$(RootPath)/Data/Libs/polyfill.keyboard.min.js")'

# Library info
Setup = {}
Setup['url'] = "https://github.com/NearlyTRex/Polyfill/archive/Polyfill-0.1.41.zip"
Setup['extractdir'] = "Polyfill-Polyfill-0.1.41"
Setup['steps'] = {}
Setup['steps']['all'] = []
Setup['steps']['all'].append(MinifyFilePolyfillKeyboardJs)
Setup['steps']['all'].append(CopyFilePolyfillKeyboardJs)
