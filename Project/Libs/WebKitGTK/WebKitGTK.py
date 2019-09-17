# Source: https://github.com/NearlyTRex/WebKit_GTK_standalone
# Version: Gitmaster

# Steps
MakeSymlinkJSC = 'MakeSymlink("$(RootPath)/Project/Libs/WebKitGTK/orig/Source/JavaScriptCore/API/glib", "$(RootPath)/Project/Libs/WebKitGTK/orig/DerivedSources/ForwardingHeaders/JavaScriptCore/glib/jsc")'
MakeSymlinkUIProcess = 'MakeSymlink("$(RootPath)/Project/Libs/WebKitGTK/orig/Source/WebKit/UIProcess/API/gtk", "$(RootPath)/Project/Libs/WebKitGTK/orig/DerivedSources/ForwardingHeaders/webkit2gtk/webkit2")'
MakeSymlinkWebProcess1 = 'MakeSymlink("$(RootPath)/Project/Libs/WebKitGTK/orig/Source/WebKit/WebProcess/InjectedBundle/API/gtk", "$(RootPath)/Project/Libs/WebKitGTK/orig/DerivedSources/ForwardingHeaders/webkit2gtk-webextension/webkit2")'
MakeSymlinkWebProcess2 = 'MakeSymlink("$(RootPath)/Project/Libs/WebKitGTK/orig/Source/WebKit/WebProcess/InjectedBundle/API/gtk/DOM", "$(RootPath)/Project/Libs/WebKitGTK/orig/DerivedSources/ForwardingHeaders/webkit2gtk-webextension/webkitdom")'

# Library info
Setup = {}
Setup['url'] = "https://github.com/NearlyTRex/WebKit_GTK_standalone/archive/master.zip"
Setup['extractdir'] = "WebKit_GTK_standalone-master"
Setup['steps'] = {}
Setup['steps']['all'] = []
Setup['steps']['all'].append(MakeSymlinkJSC)
Setup['steps']['all'].append(MakeSymlinkUIProcess)
Setup['steps']['all'].append(MakeSymlinkWebProcess1)
Setup['steps']['all'].append(MakeSymlinkWebProcess2)
