# Source: https://github.com/NearlyTRex/jQuery
# Version: 3.4.1

# Steps
CopyFileJQueryJs = 'CopyFile("dist/jquery.min.js", "$(RootPath)/Data/Libs/jquery.min.js")'
CopyFileJQuerySlimJs = 'CopyFile("dist/jquery.slim.min.js", "$(RootPath)/Data/Libs/jquery.slim.min.js")'

# Library info
Setup = {}
Setup['url'] = "https://github.com/NearlyTRex/jQuery/archive/jQuery-3.4.1.zip"
Setup['extractdir'] = "jQuery-jQuery-3.4.1"
Setup['steps'] = {}
Setup['steps']['all'] = []
Setup['steps']['all'].append(CopyFileJQueryJs)
Setup['steps']['all'].append(CopyFileJQuerySlimJs)
