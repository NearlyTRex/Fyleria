# Source: https://github.com/NearlyTRex/bootstrap
# Version: Gitmaster

# Steps
MakeBootstrapDir = 'MakeDirectory("$(RootPath)/Web/lib/bootstrap/")'
MakeBootstrapCssDir = 'MakeDirectory("$(RootPath)/Web/lib/bootstrap/css/")'
MakeBootstrapJsDir = 'MakeDirectory("$(RootPath)/Web/lib/bootstrap/js/")'
CopyFileBootstrapCss = 'CopyFile("dist/css/bootstrap.min.css", "$(RootPath)/Web/lib/bootstrap/css/bootstrap.min.css")'
CopyFileBootstrapGridCss = 'CopyFile("dist/css/bootstrap-grid.min.css", "$(RootPath)/Web/lib/bootstrap/css/bootstrap-grid.min.css")'
CopyFileBootstrapRebootCss = 'CopyFile("dist/css/bootstrap-reboot.min.css", "$(RootPath)/Web/lib/bootstrap/css/bootstrap-reboot.min.css")'
CopyFileBootstrapJs = 'CopyFile("dist/js/bootstrap.min.js", "$(RootPath)/Web/lib/bootstrap/js/bootstrap.min.js")'

# Library info
Setup = {}
Setup['url'] = "https://github.com/NearlyTRex/bootstrap/archive/master.zip"
Setup['extractdir'] = "bootstrap-master"
Setup['steps'] = {}
Setup['steps']['all'] = []
Setup['steps']['all'].append(MakeBootstrapDir)
Setup['steps']['all'].append(MakeBootstrapCssDir)
Setup['steps']['all'].append(MakeBootstrapJsDir)
Setup['steps']['all'].append(CopyFileBootstrapCss)
Setup['steps']['all'].append(CopyFileBootstrapGridCss)
Setup['steps']['all'].append(CopyFileBootstrapRebootCss)
Setup['steps']['all'].append(CopyFileBootstrapJs)
