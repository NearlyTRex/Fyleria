# Source: https://github.com/NearlyTRex/jquery
# Version: Gitmaster

# Steps
RunProcessNpmBuild = 'RunProcess("npm run build")'
CopyFileBootstrapJs = 'CopyFile("dist/jquery.min.js", "$(RootPath)/Data/Libs/jquery.min.js")'

# Library info
Setup = {}
Setup['url'] = "https://github.com/NearlyTRex/jquery/archive/master.zip"
Setup['extractdir'] = "jquery-master"
Setup['steps'] = {}
Setup['steps']['all'] = []
Setup['steps']['all'].append(RunProcessNpmBuild)
Setup['steps']['all'].append(CopyFileBootstrapJs)
