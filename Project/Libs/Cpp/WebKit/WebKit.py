# Source: https://github.com/NearlyTRex/WebKit

# Steps
WebKit_MakeBinDir = 'MakeDirectory("$(RootPath)/Bin")'
WebKitCairo_Build = 'RunProcess("perl Tools/Scripts/build-webkit --wincairo --release")'
WebKitCairo_CopyCairo = 'CopyFile("WebKitLibraries/win/bin64/cairo.dll", "$(RootPath)/Bin/cairo.dll")'
WebKitCairo_CopyCFLite = 'CopyFile("WebKitLibraries/win/bin64/CFLite.dll", "$(RootPath)/Bin/CFLite.dll")'
WebKitCairo_CopyCrypto = 'CopyFile("WebKitLibraries/win/bin64/crypto-45.dll", "$(RootPath)/Bin/crypto-45.dll")'
WebKitCairo_CopyCurl = 'CopyFile("WebKitLibraries/win/bin64/libcurl.dll", "$(RootPath)/Bin/libcurl.dll")'
WebKitCairo_CopyIcuDt = 'CopyFile("WebKitLibraries/win/bin64/icudt63.dll", "$(RootPath)/Bin/icudt63.dll")'
WebKitCairo_CopyIcuIn = 'CopyFile("WebKitLibraries/win/bin64/icuin63.dll", "$(RootPath)/Bin/icuin63.dll")'
WebKitCairo_CopyIcuUc = 'CopyFile("WebKitLibraries/win/bin64/icuuc63.dll", "$(RootPath)/Bin/icuuc63.dll")'
WebKitCairo_CopyJpeg = 'CopyFile("WebKitLibraries/win/bin64/jpeg62.dll", "$(RootPath)/Bin/jpeg62.dll")'
WebKitCairo_CopyPng = 'CopyFile("WebKitLibraries/win/bin64/libpng16.dll", "$(RootPath)/Bin/libpng16.dll")'
WebKitCairo_CopyNgHttp2 = 'CopyFile("WebKitLibraries/win/bin64/nghttp2.dll", "$(RootPath)/Bin/nghttp2.dll")'
WebKitCairo_CopyOpenJpeg = 'CopyFile("WebKitLibraries/win/bin64/openjp2.dll", "$(RootPath)/Bin/openjp2.dll")'
WebKitCairo_CopyPsl = 'CopyFile("WebKitLibraries/win/bin64/psl.dll", "$(RootPath)/Bin/psl.dll")'
WebKitCairo_CopyPthreads = 'CopyFile("WebKitLibraries/win/bin64/pthreadsVC2.dll", "$(RootPath)/Bin/pthreadsVC2.dll")'
WebKitCairo_CopySQLite = 'CopyFile("WebKitLibraries/win/bin64/sqlite3.dll", "$(RootPath)/Bin/sqlite3.dll")'
WebKitCairo_CopySSL = 'CopyFile("WebKitLibraries/win/bin64/ssl-47.dll", "$(RootPath)/Bin/ssl-47.dll")'
WebKitCairo_CopyXML2 = 'CopyFile("WebKitLibraries/win/bin64/xml2.dll", "$(RootPath)/Bin/xml2.dll")'
WebKitCairo_CopyXSLT = 'CopyFile("WebKitLibraries/win/bin64/xslt.dll", "$(RootPath)/Bin/xslt.dll")'
WebKitCairo_CopyZlib = 'CopyFile("WebKitLibraries/win/bin64/zlib1.dll", "$(RootPath)/Bin/zlib1.dll")'
WebKitCairo_CopyEGL = 'CopyFile("WebKitBuild/Release/bin64/libEGL.dll", "$(RootPath)/Bin/libEGL.dll")'
WebKitCairo_CopyGLES = 'CopyFile("WebKitBuild/Release/bin64/libGLESv2.dll", "$(RootPath)/Bin/libGLESv2.dll")'
WebKitCairo_CopyJavaScriptCore = 'CopyFile("WebKitBuild/Release/bin64/JavaScriptCore.dll", "$(RootPath)/Bin/JavaScriptCore.dll")'
WebKitCairo_CopyWebKit = 'CopyFile("WebKitBuild/Release/bin64/WebKit2.dll", "$(RootPath)/Bin/WebKit2.dll")'
WebKitCairo_CopyWTF = 'CopyFile("WebKitBuild/Release/bin64/WTF.dll", "$(RootPath)/Bin/WTF.dll")'
WebKitCairo_CopyWebKitNetworkProcess = 'CopyFile("WebKitBuild/Release/bin64/WebKitNetworkProcess.exe", "$(RootPath)/Bin/WebKitNetworkProcess.exe")'
WebKitCairo_CopyWebKitWebProcess = 'CopyFile("WebKitBuild/Release/bin64/WebKitWebProcess.exe", "$(RootPath)/Bin/WebKitWebProcess.exe")'
WebKitCairo_CopyWebKitResources = 'CopyDirectory("WebKitBuild/Release/bin64/WebKit.resources", "$(RootPath)/Bin/WebKit.resources")'
WebKitGTK_InstallDeps = 'RunProcess("perl Tools/gtk/install-dependencies")'
WebKitGTK_UpdateLibs = 'RunProcess("perl Tools/Scripts/update-webkitgtk-libs")'
WebKitGTK_Build = 'RunProcess("perl Tools/Scripts/build-webkit --gtk --release")'
WebKitGTK_CopyJavaScriptCore = 'CopySubstringFiles("WebKitBuild/GTK/Release/lib/", "$(RootPath)/Bin/", "libjavascriptcoregtk-4.0.so")'
WebKitGTK_CopyWebKit = 'CopySubstringFiles("WebKitBuild/GTK/Release/lib/", "$(RootPath)/Bin/", "libwebkit2gtk-4.0.so")'
WebKitGTK_CopyWebKitGPUProcess = 'CopySubstringFiles("WebKitBuild/GTK/Release/bin/", "$(RootPath)/Bin/", "WebKitGPUProcess")'
WebKitGTK_CopyWebKitNetworkProcess = 'CopySubstringFiles("WebKitBuild/GTK/Release/bin/", "$(RootPath)/Bin/", "WebKitNetworkProcess")'
WebKitGTK_CopyWebKitWebDriver = 'CopySubstringFiles("WebKitBuild/GTK/Release/bin/", "$(RootPath)/Bin/", "WebKitWebDriver")'
WebKitGTK_CopyWebKitWebProcess = 'CopySubstringFiles("WebKitBuild/GTK/Release/bin/", "$(RootPath)/Bin/", "WebKitWebProcess")'

# Library info
Setup = {}
Setup['steps'] = {}
Setup['steps']['windows'] = []
Setup['steps']['windows'].extend([WebKitCairo_Build, WebKit_MakeBinDir])
Setup['steps']['windows'].extend([WebKitCairo_CopyCairo, WebKitCairo_CopyCFLite, WebKitCairo_CopyCrypto, WebKitCairo_CopyCurl, WebKitCairo_CopyIcuDt, WebKitCairo_CopyIcuIn, WebKitCairo_CopyIcuUc])
Setup['steps']['windows'].extend([WebKitCairo_CopyJpeg, WebKitCairo_CopyPng, WebKitCairo_CopyNgHttp2, WebKitCairo_CopyOpenJpeg, WebKitCairo_CopyPsl, WebKitCairo_CopyPthreads])
Setup['steps']['windows'].extend([WebKitCairo_CopySQLite, WebKitCairo_CopySSL, WebKitCairo_CopyXML2, WebKitCairo_CopyXSLT, WebKitCairo_CopyZlib, WebKitCairo_CopyEGL, WebKitCairo_CopyGLES])
Setup['steps']['windows'].extend([WebKitCairo_CopyJavaScriptCore, WebKitCairo_CopyWebKit, WebKitCairo_CopyWTF])
Setup['steps']['windows'].extend([WebKitCairo_CopyWebKitNetworkProcess, WebKitCairo_CopyWebKitWebProcess, WebKitCairo_CopyWebKitResources])
Setup['steps']['linux'] = []
Setup['steps']['linux'].extend([WebKitGTK_InstallDeps, WebKitGTK_UpdateLibs, WebKitGTK_Build, WebKit_MakeBinDir])
Setup['steps']['linux'].extend([WebKitGTK_CopyJavaScriptCore, WebKitGTK_CopyWebKit])
Setup['steps']['linux'].extend([WebKitGTK_CopyWebKitGPUProcess, WebKitGTK_CopyWebKitNetworkProcess, WebKitGTK_CopyWebKitWebDriver, WebKitGTK_CopyWebKitWebProcess])
