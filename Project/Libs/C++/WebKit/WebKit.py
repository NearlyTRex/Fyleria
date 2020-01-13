# Source: https://github.com/NearlyTRex/WebKit
# Version: r254199

# Steps
WebKitCairo_Build = 'RunProcess("perl Tools/Scripts/build-webkit --wincairo --release")'
WebKitGTK_InstallDeps = 'RunProcess("perl Tools/gtk/install-dependencies")'
WebKitGTK_UpdateLibs = 'RunProcess("perl Tools/Scripts/update-webkitgtk-libs")'
WebKitGTK_Build = 'RunProcess("perl Tools/Scripts/build-webkit --gtk --release")'

# Library info
Setup = {}
Setup['url'] = "https://github.com/NearlyTRex/WebKit/archive/WebKit-r254199.zip"
Setup['extractdir'] = "WebKit-WebKit-r254199"
Setup['steps'] = {}
Setup['steps']['windows'] = []
Setup['steps']['windows'].append(WebKitCairo_Build)
Setup['steps']['linux'] = []
Setup['steps']['linux'].append(WebKitGTK_InstallDeps)
Setup['steps']['linux'].append(WebKitGTK_UpdateLibs)
Setup['steps']['linux'].append(WebKitGTK_Build)
