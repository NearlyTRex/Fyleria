# Imports
import argparse

###########################################################################
# Program options
class ProgramOptions:
    def __init__(self):
        pass
###########################################################################
# Get program options
def GetProgramOptions():
    parser = argparse.ArgumentParser(description="Setup build environment.")
    parser.add_argument("--force_32", action="store_true", help="Force 32-bit steps")
    parser.add_argument("--force_64", action="store_true", help="Force 64-bit steps")
    parser.add_argument("--force_linux", action="store_true", help="Force Linux steps")
    parser.add_argument("--force_macosx", action="store_true", help="Force MacOSX steps")
    parser.add_argument("--force_windows", action="store_true", help="Force Windows steps")
    parser.add_argument("--force_wsl", action="store_true", help="Force Windows Subsystem for Linux steps")
    parser.add_argument("--force_cygwin", action="store_true", help="Force Cygwin steps")
    parser.add_argument("--force_mingw", action="store_true", help="Force MinGW steps")
    parser.add_argument("--force_download", action="store_true", help="Force downloads")
    parser.add_argument("--configuration", choices=[
        "release",
        "debug"
    ], default="debug", help="Configuration type")
    parser.add_argument("--buildtype", choices=[
        "gmake",
        "gmake2",
        "codelite",
        "vs2005",
        "vs2008",
        "vs2010",
        "vs2012",
        "vs2013",
        "vs2015",
        "vs2017",
        "vs2019",
        "xcode4"
    ], default="gmake2", help="Project type to pass to Premake")
    parser.add_argument("-v", "--verbose", action="store_true", help="Enable verbose messages")
    parser.add_argument("mode", choices=[
        "all",
        "setup_c_libs",
        "setup_cpp_libs",
        "setup_py_libs",
        "setup_js_libs",
        "build_tools",
        "build_game",
    ], help="Setup mode")
    args = parser.parse_args()
    options = ProgramOptions()
    options.force_32bits = args.force_32
    options.force_64bits = args.force_64
    options.force_linux = args.force_linux
    options.force_macosx = args.force_macosx
    options.force_windows = args.force_windows
    options.force_wsl = args.force_wsl
    options.force_cygwin = args.force_cygwin
    options.force_mingw = args.force_mingw
    options.force_download = args.force_download
    options.configuration = args.configuration
    options.build_type = args.buildtype
    options.verbose = args.verbose
    options.mode = args.mode
    return options
###########################################################################
