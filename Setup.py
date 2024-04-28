# Setup script
# Configure libraries and project for various platforms

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
    sys.path.append(os.path.join(system_info.root_path, "Project/Libs/Python/PyJSMin/orig"))

    # Check Python
    if Utility.DetectPython(Utility.GetRequiredPythonVersion()) == False:
        Utility.ErrorStatement("Python %d.%d or higher is required to run this script" % Utility.GetRequiredPythonVersion())
        sys.exit(-1)

    # Project sets
    projects_clibs = [
        "CJSMin",
        "Zlib"
    ]
    projects_cpplibs = [
        "Backward",
        "BetterEnums",
        "Boost",
        "Date",
        "FantasyName",
        "ImmutableString",
        "Json",
        "LRUCache",
        "MicroPather",
        "ObjectThreadsafe",
        "PPKAssert",
        "SpdLog",
        "WebView"
    ]
    projects_jslibs = [
        "Bootstrap",
        "jQuery",
        "jQueryTerminal",
        "Phaser"
    ]
    projects_pylibs = [
        "PyJSMin"
    ]
    projects_tools = [
        "Premake"
    ]

    # Parse program options
    do_all = program_options.mode == "all"
    do_setup_libs = program_options.mode == "setup_libs"
    do_setup_c_libs = program_options.mode == "setup_c_libs"
    do_setup_cpp_libs = program_options.mode == "setup_cpp_libs"
    do_setup_js_libs = program_options.mode == "setup_js_libs"
    do_setup_py_libs = program_options.mode == "setup_py_libs"
    do_setup_tools = program_options.mode == "setup_tools"
    do_create_project = program_options.mode == "create_project"
    do_build_project = program_options.mode == "build_project"
    if do_setup_c_libs or do_setup_libs or do_all:
        for project in projects_clibs:
            Project.SetupProject(project, "Project/Libs/C", system_info, program_options)
    if do_setup_cpp_libs or do_setup_libs or do_all:
        for project in projects_cpplibs:
            Project.SetupProject(project, "Project/Libs/Cpp", system_info, program_options)
    if do_setup_js_libs or do_setup_libs or do_all:
        for project in projects_jslibs:
            Project.SetupProject(project, "Project/Libs/JavaScript", system_info, program_options)
    if do_setup_py_libs or do_setup_libs or do_all:
        for project in projects_pylibs:
            Project.SetupProject(project, "Project/Libs/Python", system_info, program_options)
    if do_setup_tools or do_all:
        for project in projects_tools:
            Project.SetupProject(project, "Project/Programs", system_info, program_options)
    if do_create_project or do_all:
        Project.CreateProject(system_info, program_options)
    if do_build_project or do_all:
        Project.CreateProject(system_info, program_options)
        Project.BuildProject(system_info, program_options)
###########################################################################
main()
