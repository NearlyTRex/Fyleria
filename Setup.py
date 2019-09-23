# Setup script
# Download, extract, and configure libraries
# Configure project for various platforms

# Base imports
import sys
import os
import os.path
from Setup import ProgramOptions
from Setup import SystemInformation
from Setup import Project
from Setup import Utility

###########################################################################
## Main
def main():

    # Get program options and system info
    program_options = ProgramOptions.GetProgramOptions()
    system_info = SystemInformation.GetSystemInformation(program_options, os.path.dirname(os.path.abspath( __file__ )))

    # Update module path
    sys.path.append(os.path.join(system_info.root_path, "Project/Programs/JSMin/extra"))

    # Check Python
    if Utility.DetectPython(Utility.GetRequiredPythonVersion()) == False:
        Utility.ErrorStatement("Python %d.%d or higher is required to run this script" % Utility.GetRequiredPythonVersion())
        sys.exit(-1)

    # Parse program options
    do_all = program_options.mode == "all"
    do_setup_cpp_libraries = program_options.mode == "setup_cpp_libraries"
    do_setup_javascript_libraries = program_options.mode == "setup_javascript_libraries"
    do_build_premake = program_options.mode == "build_premake"
    do_build_jsmin = program_options.mode == "build_jsmin"
    do_build_tiled = program_options.mode == "build_tiled"
    do_build_zip = program_options.mode == "build_zip"
    do_build_game = program_options.mode == "build_game"
    if do_build_premake or do_all:
        Project.SetupProject("Premake5", "Project/Programs", system_info, program_options)
    if do_build_jsmin or do_all:
        Project.SetupProject("JSMin", "Project/Programs", system_info, program_options)
    if do_build_tiled or do_all:
        Project.SetupProject("Tiled", "Project/Programs", system_info, program_options)
    if do_build_zip or do_all:
        Project.SetupProject("Zip", "Project/Programs", system_info, program_options)
        Project.SetupProject("Unzip", "Project/Programs", system_info, program_options)
    if do_setup_cpp_libraries or do_all:
        Project.SetupProject("Atk", "Project/Libs", system_info, program_options)
        Project.SetupProject("AtkBridge", "Project/Libs", system_info, program_options)
        Project.SetupProject("AtkCore", "Project/Libs", system_info, program_options)
        Project.SetupProject("BackwardCPP", "Project/Libs", system_info, program_options)
        Project.SetupProject("BetterEnums", "Project/Libs", system_info, program_options)
        Project.SetupProject("Boost", "Project/Libs", system_info, program_options)
        Project.SetupProject("Brotli", "Project/Libs", system_info, program_options)
        Project.SetupProject("DateCPP", "Project/Libs", system_info, program_options)
        Project.SetupProject("Cairo", "Project/Libs", system_info, program_options)
        Project.SetupProject("Curl", "Project/Libs", system_info, program_options)
        Project.SetupProject("ElfUtils", "Project/Libs", system_info, program_options)
        Project.SetupProject("Epoxy", "Project/Libs", system_info, program_options)
        Project.SetupProject("FantasyName", "Project/Libs", system_info, program_options)
        Project.SetupProject("FFI", "Project/Libs", system_info, program_options)
        Project.SetupProject("Fontconfig", "Project/Libs", system_info, program_options)
        Project.SetupProject("FreeType2", "Project/Libs", system_info, program_options)
        Project.SetupProject("Fribidi", "Project/Libs", system_info, program_options)
        Project.SetupProject("GCrypt", "Project/Libs", system_info, program_options)
        Project.SetupProject("GdkPixbuf", "Project/Libs", system_info, program_options)
        Project.SetupProject("Glib", "Project/Libs", system_info, program_options)
        Project.SetupProject("GPGError", "Project/Libs", system_info, program_options)
        Project.SetupProject("Graphene", "Project/Libs", system_info, program_options)
        Project.SetupProject("Gtk", "Project/Libs", system_info, program_options)
        Project.SetupProject("Harfbuzz", "Project/Libs", system_info, program_options)
        Project.SetupProject("Icu", "Project/Libs", system_info, program_options)
        Project.SetupProject("ImmutableString", "Project/Libs", system_info, program_options)
        Project.SetupProject("Jpeg", "Project/Libs", system_info, program_options)
        Project.SetupProject("LibreSSL", "Project/Libs", system_info, program_options)
        Project.SetupProject("LRUCache", "Project/Libs", system_info, program_options)
        Project.SetupProject("MicroPather", "Project/Libs", system_info, program_options)
        Project.SetupProject("ModernCPPJson", "Project/Libs", system_info, program_options)
        Project.SetupProject("ObjectThreadsafe", "Project/Libs", system_info, program_options)
        Project.SetupProject("OpenCFLite", "Project/Libs", system_info, program_options)
        Project.SetupProject("Pango", "Project/Libs", system_info, program_options)
        Project.SetupProject("Pixman", "Project/Libs", system_info, program_options)
        Project.SetupProject("PCRE", "Project/Libs", system_info, program_options)
        Project.SetupProject("PNG", "Project/Libs", system_info, program_options)
        Project.SetupProject("PSL", "Project/Libs", system_info, program_options)
        Project.SetupProject("PThreadsWin32", "Project/Libs", system_info, program_options)
        Project.SetupProject("Soup", "Project/Libs", system_info, program_options)
        Project.SetupProject("SpdLog", "Project/Libs", system_info, program_options)
        Project.SetupProject("SQLite", "Project/Libs", system_info, program_options)
        Project.SetupProject("UtilLinux", "Project/Libs", system_info, program_options)
        Project.SetupProject("WebKitGTK", "Project/Libs", system_info, program_options)
        Project.SetupProject("Webp", "Project/Libs", system_info, program_options)
        Project.SetupProject("XkbCommon", "Project/Libs", system_info, program_options)
        Project.SetupProject("XML2", "Project/Libs", system_info, program_options)
        Project.SetupProject("XSLT", "Project/Libs", system_info, program_options)
        Project.SetupProject("Zlib", "Project/Libs", system_info, program_options)
    if do_setup_javascript_libraries or do_all:
        Project.SetupProject("Bootstrap", "Project/Libs", system_info, program_options)
        Project.SetupProject("jQuery", "Project/Libs", system_info, program_options)
        Project.SetupProject("jQueryTerminal", "Project/Libs", system_info, program_options)
        Project.SetupProject("Phaser", "Project/Libs", system_info, program_options)
        Project.SetupProject("Polyfill", "Project/Libs", system_info, program_options)
        Project.SetupProject("Screenfull", "Project/Libs", system_info, program_options)
    if do_build_game or do_all:
        Project.BuildProject(system_info, program_options)
###########################################################################
main()
