# Source: https://github.com/NearlyTRex/WebKitGTK
# Version: 2.24.3

# Steps
MakeSymlinkJSC = 'MakeSymlink("$(RootPath)/Project/Libs/C/WebKitGTK/orig/Source/JavaScriptCore/API/glib", "$(RootPath)/Project/Libs/C/WebKitGTK/orig/DerivedSources/ForwardingHeaders/JavaScriptCore/glib/jsc")'
MakeSymlinkUIProcess = 'MakeSymlink("$(RootPath)/Project/Libs/C/WebKitGTK/orig/Source/WebKit/UIProcess/API/gtk", "$(RootPath)/Project/Libs/C/WebKitGTK/orig/DerivedSources/ForwardingHeaders/webkit2gtk/webkit2")'
MakeSymlinkWebProcess1 = 'MakeSymlink("$(RootPath)/Project/Libs/C/WebKitGTK/orig/Source/WebKit/WebProcess/InjectedBundle/API/gtk", "$(RootPath)/Project/Libs/C/WebKitGTK/orig/DerivedSources/ForwardingHeaders/webkit2gtk-webextension/webkit2")'
MakeSymlinkWebProcess2 = 'MakeSymlink("$(RootPath)/Project/Libs/C/WebKitGTK/orig/Source/WebKit/WebProcess/InjectedBundle/API/gtk/DOM", "$(RootPath)/Project/Libs/C/WebKitGTK/orig/DerivedSources/ForwardingHeaders/webkit2gtk-webextension/webkitdom")'

# Library info
Setup = {}
Setup['url'] = "https://github.com/NearlyTRex/WebKitGTK/archive/WebKitGTK-2.24.3.zip"
Setup['extractdir'] = "WebKitGTK-WebKitGTK-2.24.3"
Setup['steps'] = {}
Setup['steps']['all'] = []
Setup['steps']['all'].append(MakeSymlinkJSC)
Setup['steps']['all'].append(MakeSymlinkUIProcess)
Setup['steps']['all'].append(MakeSymlinkWebProcess1)
Setup['steps']['all'].append(MakeSymlinkWebProcess2)
