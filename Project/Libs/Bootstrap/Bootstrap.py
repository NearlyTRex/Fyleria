# Source: https://github.com/NearlyTRex/bootstrap
# Version: Gitmaster

# Steps
MakeBootstrapDir = 'MakeDirectory("$(ProjectRoot)/Web/lib/bootstrap/")'
MakeBootstrapCssDir = 'MakeDirectory("$(ProjectRoot)/Web/lib/bootstrap/css/")'
MakeBootstrapJsDir = 'MakeDirectory("$(ProjectRoot)/Web/lib/bootstrap/js/")'
CopyFileBootstrapCss = 'CopyFile("dist/css/bootstrap.min.css", "$(ProjectRoot)/Web/lib/bootstrap/css/bootstrap.min.css")'
CopyFileBootstrapCssMap = 'CopyFile("dist/css/bootstrap.min.css.map", "$(ProjectRoot)/Web/lib/bootstrap/css/bootstrap.min.css.map")'
CopyFileBootstrapGridCss = 'CopyFile("dist/css/bootstrap-grid.min.css", "$(ProjectRoot)/Web/lib/bootstrap/css/bootstrap-grid.min.css")'
CopyFileBootstrapGridCssMap = 'CopyFile("dist/css/bootstrap-grid.min.css.map", "$(ProjectRoot)/Web/lib/bootstrap/css/bootstrap-grid.min.css.map")'
CopyFileBootstrapRebootCss = 'CopyFile("dist/css/bootstrap-reboot.min.css", "$(ProjectRoot)/Web/lib/bootstrap/css/bootstrap-reboot.min.css")'
CopyFileBootstrapRebootCssMap = 'CopyFile("dist/css/bootstrap-reboot.min.css.map", "$(ProjectRoot)/Web/lib/bootstrap/css/bootstrap-reboot.min.css.map")'
CopyFileBootstrapJs = 'CopyFile("dist/js/bootstrap.min.js", "$(ProjectRoot)/Web/lib/bootstrap/js/bootstrap.min.js")'
CopyFileBootstrapJsMap = 'CopyFile("dist/js/bootstrap.min.js.map", "$(ProjectRoot)/Web/lib/bootstrap/js/bootstrap.min.js.map")'

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
Setup['steps']['all'].append(CopyFileBootstrapCssMap)
Setup['steps']['all'].append(CopyFileBootstrapGridCss)
Setup['steps']['all'].append(CopyFileBootstrapGridCssMap)
Setup['steps']['all'].append(CopyFileBootstrapRebootCss)
Setup['steps']['all'].append(CopyFileBootstrapRebootCssMap)
Setup['steps']['all'].append(CopyFileBootstrapJs)
Setup['steps']['all'].append(CopyFileBootstrapJsMap)
