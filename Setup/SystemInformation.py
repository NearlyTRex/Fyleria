# Imports
import os, os.path
import sys
import platform
import datetime

###########################################################################
# System information
class SystemInformation:
    def __init__(self):
        pass
###########################################################################
# Get system information
def GetSystemInformation(program_options, root_path):

    # Architecture conversions
    arch_conversions = {}
    arch_conversions["i386"] = "x86"
    arch_conversions["amd64"] = "x86_64"

    # Detection defaults
    detect_arch = platform.machine().lower()
    if detect_arch in arch_conversions:
        detect_arch = arch_conversions[detect_arch]
    detect_os = platform.system().lower()
    detect_64bits = sys.maxsize > 2**32
    detect_date = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    detect_uname = "%s %s %s %s" % (platform.machine(), platform.version(), platform.system(), platform.release())
    detect_cygwin = False
    detect_mingw = False
    detect_wsl = False
    detect_macosx = False
    detect_linux = False
    detect_windows = False
    detect_make_bin = ""
    detect_build_bin = ""
    detect_premake_bin = ""

    # Detect platform
    if 'cygwin' in detect_os:
        detect_cygwin = True
    elif 'darwin' in detect_os:
        detect_macosx = True
    elif 'linux' in detect_os:
        detect_linux = True
        with open('/proc/version','r') as f:
            if 'microsoft' in f.read().lower():
                detect_wsl = True
                detect_linux = False
    elif 'windows' in detect_os:
        detect_windows = True

    # Detect binaries
    if detect_linux or detect_wsl:
        detect_make_bin = "make"
        detect_build_bin = "make"
        detect_premake_bin = os.path.normpath(os.path.join(root_path, "Project/Programs/Premake/orig/bin/release/premake5"))
    elif detect_macosx:
        detect_make_bin = "make"
        detect_build_bin = "xcodebuild"
        detect_premake_bin = os.path.normpath(os.path.join(root_path, "Project/Programs/Premake/orig/bin/release/premake5"))
    elif detect_windows or detect_cygwin or detect_mingw:
        detect_make_bin = "nmake"
        detect_build_bin = "devenv.com"
        detect_premake_bin = os.path.normpath(os.path.join(root_path, "Project/Programs/Premake/orig/bin/release/premake5.exe"))

    # Create system information
    info = SystemInformation()
    info.arch = detect_arch
    info.os = detect_os
    info.date = detect_date
    info.uname = detect_uname
    info.is_32bits = not detect_64bits
    info.is_64bits = detect_64bits
    info.root_path = os.path.normpath(root_path)
    info.make_bin = detect_make_bin
    info.build_bin = detect_build_bin
    info.premake_bin = detect_premake_bin
    info.has_forced_platform = (
        program_options.force_linux or
        program_options.force_macosx or
        program_options.force_windows or
        program_options.force_wsl or
        program_options.force_cygwin or
        program_options.force_mingw)

    # Override system information by force
    if info.has_forced_platform:
        info.is_linux = program_options.force_linux
        info.is_macosx = program_options.force_macosx
        info.is_windows = program_options.force_windows
        info.is_wsl = program_options.force_wsl
        info.is_cygwin = program_options.force_cygwin
        info.is_mingw = program_options.force_mingw
        info.is_posix = (info.is_linux or info.is_macosx or info.is_wsl or info.is_cygwin or info.is_mingw)
    else:
        info.is_linux = detect_linux
        info.is_macosx = detect_macosx
        info.is_windows = detect_windows
        info.is_wsl = detect_wsl
        info.is_cygwin = detect_cygwin
        info.is_mingw = detect_mingw
        info.is_posix = (info.is_linux or info.is_macosx or info.is_wsl or info.is_cygwin or info.is_mingw)

    # Override bitness by force
    if program_options.force_32bits:
        info.is_32bits = True
        info.is_64bits = False
    elif program_options.force_64bits:
        info.is_32bits = False
        info.is_64bits = True

    # Set build path
    if info.is_linux or info.is_wsl:
        info.build_path = os.path.normpath(os.path.join(root_path, "Project/Build_linux_" + program_options.build_type))
    elif info.is_macosx:
        info.build_path = os.path.normpath(os.path.join(root_path, "Project/Build_macosx_" + program_options.build_type))
    elif info.is_windows:
        info.build_path = os.path.normpath(os.path.join(root_path, "Project/Build_windows_" + program_options.build_type))
    elif info.is_cygwin:
        info.build_path = os.path.normpath(os.path.join(root_path, "Project/Build_cygwin_" + program_options.build_type))
    elif info.is_mingw and info.is_32bits:
        info.build_path = os.path.normpath(os.path.join(root_path, "Project/Build_mingw32_" + program_options.build_type))
    elif info.is_mingw and info.is_64bits:
        info.build_path = os.path.normpath(os.path.join(root_path, "Project/Build_mingw64_" + program_options.build_type))
    else:
        info.build_path = os.path.normpath(os.path.join(root_path, "Project/Build_unknown_" + program_options.build_type))
    return info
###########################################################################
