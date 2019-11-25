# Source: https://github.com/NearlyTRex/Bootstrap
# Version: 4.3.1

# Steps
CopyFileBootstrapCss = 'CopyFile("dist/css/bootstrap.min.css", "$(RootPath)/Data/Libs/bootstrap.min.css")'
CopyFileBootstrapCssMap = 'CopyFile("dist/css/bootstrap.min.css.map", "$(RootPath)/Data/Libs/bootstrap.min.css.map")'
CopyFileBootstrapGridCss = 'CopyFile("dist/css/bootstrap-grid.min.css", "$(RootPath)/Data/Libs/bootstrap-grid.min.css")'
CopyFileBootstrapGridCssMap = 'CopyFile("dist/css/bootstrap-grid.min.css.map", "$(RootPath)/Data/Libs/bootstrap-grid.min.css.map")'
CopyFileBootstrapRebootCss = 'CopyFile("dist/css/bootstrap-reboot.min.css", "$(RootPath)/Data/Libs/bootstrap-reboot.min.css")'
CopyFileBootstrapRebootCssMap = 'CopyFile("dist/css/bootstrap-reboot.min.css.map", "$(RootPath)/Data/Libs/bootstrap-reboot.min.css.map")'
CopyFileBootstrapJs = 'CopyFile("dist/js/bootstrap.min.js", "$(RootPath)/Data/Libs/bootstrap.min.js")'
CopyFileBootstrapJsMap = 'CopyFile("dist/js/bootstrap.min.js.map", "$(RootPath)/Data/Libs/bootstrap.min.js.map")'

# Library info
Setup = {}
Setup['url'] = "https://github.com/NearlyTRex/Bootstrap/archive/Bootstrap-4.3.1.zip"
Setup['extractdir'] = "Bootstrap-Bootstrap-4.3.1"
Setup['steps'] = {}
Setup['steps']['all'] = []
Setup['steps']['all'].append(CopyFileBootstrapCss)
Setup['steps']['all'].append(CopyFileBootstrapCssMap)
Setup['steps']['all'].append(CopyFileBootstrapGridCss)
Setup['steps']['all'].append(CopyFileBootstrapGridCssMap)
Setup['steps']['all'].append(CopyFileBootstrapRebootCss)
Setup['steps']['all'].append(CopyFileBootstrapRebootCssMap)
Setup['steps']['all'].append(CopyFileBootstrapJs)
Setup['steps']['all'].append(CopyFileBootstrapJsMap)
