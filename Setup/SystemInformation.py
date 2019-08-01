# Imports
import os, os.path
import sys
import platform

###########################################################################
# System information
class SystemInformation:
    def __init__(self):
        pass
###########################################################################
# Get system information
def GetSystemInformation(program_options, root_path):
    current_system = platform.system().lower()
    detect_cygwin = False
    detect_mingw = False
    detect_wsl = False
    detect_macosx = False
    detect_linux = False
    detect_windows = False
    detect_bsd = False
    detect_make_bin = ""
    detect_premake_bin = ""
    detect_zip_bin = ""
    detect_unzip_bin = ""
    if 'cygwin' in current_system:
        detect_cygwin = True
    elif 'darwin' in current_system:
        detect_macosx = True
    elif 'linux' in current_system:
        detect_linux = True
        with open('/proc/version','r') as f:
            if 'microsoft' in f.read().lower():
                detect_wsl = True
                detect_linux = False
    elif 'windows' in current_system:
        detect_windows = True
    elif 'bsd' in current_system:
        detect_bsd = True
    if detect_linux or detect_macosx or detect_bsd or detect_wsl or detect_cygwin or detect_mingw:
        detect_make_bin = "make"
        detect_zip_bin = "zip"
        detect_unzip_bin = "unzip"
        detect_premake_bin = os.path.normpath(os.path.join(root_path, "Project/Programs/Premake5/orig/bin/release/premake5"))
    elif detect_windows:
        detect_make_bin = "nmake"
        detect_zip_bin = os.path.normpath(os.path.join(root_path, "Project/Programs/Zip/bin/windows-x86-32/zip.exe"))
        detect_unzip_bin = os.path.normpath(os.path.join(root_path, "Project/Programs/Unzip/bin/windows-x86-32/unzip.exe"))
        detect_premake_bin = os.path.normpath(os.path.join(root_path, "Project/Programs/Premake5/orig/bin/release/premake5.exe"))
    info = SystemInformation()
    info.root_path = os.path.normpath(root_path)
    info.make_bin = detect_make_bin
    info.zip_bin = detect_zip_bin
    info.unzip_bin = detect_unzip_bin
    info.premake_bin = detect_premake_bin
    info.python3_libdir = os.path.normpath(os.path.join(root_path, "Project/Libs/Python3/orig/Lib"))
    detect_64bits = sys.maxsize > 2**32
    info.is_32bits = not detect_64bits
    info.is_64bits = detect_64bits
    info.has_forced_platform = (
        program_options.force_linux or
        program_options.force_macosx or
        program_options.force_windows or
        program_options.force_bsd or
        program_options.force_wsl or
        program_options.force_cygwin or
        program_options.force_mingw)
    if info.has_forced_platform:
        info.is_linux = program_options.force_linux
        info.is_macosx = program_options.force_macosx
        info.is_windows = program_options.force_windows
        info.is_bsd = program_options.force_bsd
        info.is_wsl = program_options.force_wsl
        info.is_cygwin = program_options.force_cygwin
        info.is_mingw = program_options.force_mingw
        info.is_posix = (info.is_linux or info.is_macosx or info.is_bsd or info.is_wsl or info.is_cygwin or info.is_mingw)
    else:
        info.is_linux = detect_linux
        info.is_macosx = detect_macosx
        info.is_windows = detect_windows
        info.is_bsd = detect_bsd
        info.is_wsl = detect_wsl
        info.is_cygwin = detect_cygwin
        info.is_mingw = detect_mingw
        info.is_posix = (info.is_linux or info.is_macosx or info.is_bsd or info.is_wsl or info.is_cygwin or info.is_mingw)
    if program_options.force_32bits:
        info.is_32bits = True
        info.is_64bits = False
    elif program_options.force_64bits:
        info.is_32bits = False
        info.is_64bits = True
    if info.is_linux or info.is_wsl:
        info.build_path = os.path.normpath(os.path.join(root_path, "Project/Build_linux"))
    elif info.is_macosx:
        info.build_path = os.path.normpath(os.path.join(root_path, "Project/Build_macosx"))
    elif info.is_windows:
        info.build_path = os.path.normpath(os.path.join(root_path, "Project/Build_windows"))
    elif info.is_bsd:
        info.build_path = os.path.normpath(os.path.join(root_path, "Project/Build_bsd"))
    elif info.is_cygwin:
        info.build_path = os.path.normpath(os.path.join(root_path, "Project/Build_cygwin"))
    elif info.is_mingw and info.is_32bits:
        info.build_path = os.path.normpath(os.path.join(root_path, "Project/Build_mingw32"))
    elif info.is_mingw and info.is_64bits:
        info.build_path = os.path.normpath(os.path.join(root_path, "Project/Build_mingw64"))
    else:
        info.build_path = os.path.normpath(os.path.join(root_path, "Project/Build_unknown"))
    return info
###########################################################################
