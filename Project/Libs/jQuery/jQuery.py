# Source: https://github.com/NearlyTRex/jquery
# Version: Gitmaster

# Steps
RunProcessNpmBuild = 'RunProcess("npm run build")'
MakeBootstrapDir = 'MakeDirectory("$(RootPath)/Web/lib/jquery/")'
CopyFileBootstrapJs = 'CopyFile("dist/jquery.min.js", "$(RootPath)/Web/lib/jquery/jquery.min.js")'

# Library info
Setup = {}
Setup['url'] = "https://github.com/NearlyTRex/jquery/archive/master.zip"
Setup['extractdir'] = "jquery-master"
Setup['steps'] = {}
Setup['steps']['all'] = []
Setup['steps']['all'].append(RunProcessNpmBuild)
Setup['steps']['all'].append(MakeBootstrapDir)
Setup['steps']['all'].append(CopyFileBootstrapJs)
