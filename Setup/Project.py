# Imports
import os, os.path
import sys
import importlib
import shutil
import subprocess
from . import Utility
from . import Repository

###########################################################################
# Setup project
def SetupProject(project_name, project_base_dir, system_info, program_options):

    # Inform user
    Utility.LogStatement("Setting up project: " + project_name)

    # Get directories
    projectdir = os.path.normpath(os.path.join(project_base_dir, project_name))
    origdir = os.path.normpath(os.path.join(projectdir, "orig"))

    # Import library module
    sys.path.append(projectdir)
    module = importlib.import_module(project_name)

    # Add submodule
    if module.Setup["url"] and program_options.add_submodules:
        Repository.AddSubmodule(module.Setup["url"], origdir)

    # Run extra setup steps
    if module.Setup['steps'] and os.path.exists(origdir):

        # Go to orig directory
        if os.path.exists(origdir):
            Utility.LogStatement("Changing directory to " + origdir)
            os.chdir(origdir)

        # Run basic extra steps
        Utility.RunExtraSteps(module.Setup['steps'], "linux", system_info.root_path, system_info.is_linux)
        Utility.RunExtraSteps(module.Setup['steps'], "macosx", system_info.root_path, system_info.is_macosx)
        Utility.RunExtraSteps(module.Setup['steps'], "wsl", system_info.root_path, system_info.is_macosx)
        Utility.RunExtraSteps(module.Setup['steps'], "posix", system_info.root_path, system_info.is_posix)
        Utility.RunExtraSteps(module.Setup['steps'], "windows", system_info.root_path, system_info.is_windows)
        Utility.RunExtraSteps(module.Setup['steps'], "cygwin", system_info.root_path, system_info.is_cygwin)
        Utility.RunExtraSteps(module.Setup['steps'], "mingw", system_info.root_path, system_info.is_mingw)
        Utility.RunExtraSteps(module.Setup['steps'], "all", system_info.root_path, True)

        # Run bitsize extra steps
        Utility.RunExtraSteps(module.Setup['steps'], "linux32", system_info.root_path, system_info.is_linux and system_info.is_32bits)
        Utility.RunExtraSteps(module.Setup['steps'], "linux64", system_info.root_path, system_info.is_linux and system_info.is_64bits)
        Utility.RunExtraSteps(module.Setup['steps'], "macosx32", system_info.root_path, system_info.is_macosx and system_info.is_32bits)
        Utility.RunExtraSteps(module.Setup['steps'], "macosx64", system_info.root_path, system_info.is_macosx and system_info.is_64bits)
        Utility.RunExtraSteps(module.Setup['steps'], "wsl32", system_info.root_path, system_info.is_wsl and system_info.is_32bits)
        Utility.RunExtraSteps(module.Setup['steps'], "wsl64", system_info.root_path, system_info.is_wsl and system_info.is_64bits)
        Utility.RunExtraSteps(module.Setup['steps'], "posix32", system_info.root_path, system_info.is_posix and system_info.is_32bits)
        Utility.RunExtraSteps(module.Setup['steps'], "posix64", system_info.root_path, system_info.is_posix and system_info.is_64bits)
        Utility.RunExtraSteps(module.Setup['steps'], "windows32", system_info.root_path, system_info.is_windows and system_info.is_32bits)
        Utility.RunExtraSteps(module.Setup['steps'], "windows64", system_info.root_path, system_info.is_windows and system_info.is_64bits)
        Utility.RunExtraSteps(module.Setup['steps'], "cygwin32", system_info.root_path, system_info.is_cygwin and system_info.is_32bits)
        Utility.RunExtraSteps(module.Setup['steps'], "cygwin64", system_info.root_path, system_info.is_cygwin and system_info.is_64bits)
        Utility.RunExtraSteps(module.Setup['steps'], "mingw32", system_info.root_path, system_info.is_mingw and system_info.is_32bits)
        Utility.RunExtraSteps(module.Setup['steps'], "mingw64", system_info.root_path, system_info.is_mingw and system_info.is_64bits)
        Utility.RunExtraSteps(module.Setup['steps'], "all32", system_info.root_path, system_info.is_32bits)
        Utility.RunExtraSteps(module.Setup['steps'], "all64", system_info.root_path, system_info.is_64bits)

        # Go back to root directory
        Utility.LogStatement("Changing directory to " + system_info.root_path)
        os.chdir(system_info.root_path)
###########################################################################
## Create Project
def CreateProject(system_info, program_options):

    # Inform user
    Utility.LogStatement("Creating project")

    # Write version header file
    if not os.path.isfile("Project/Fyleria/Utility/Version.h"):
        with open(os.path.join("Project/Fyleria/Utility/Version.h"), "w") as f:
            f.write("#ifndef _GECKO_UTILITY_VERSION_H_\n")
            f.write("#define _GECKO_UTILITY_VERSION_H_\n")
            f.write("char const* GetVersionStringShort();\n")
            f.write("char const* GetVersionStringLong();\n")
            f.write("#endif\n")

    # Write version implementation file
    if not os.path.isfile("Project/Fyleria/Utility/Version.cpp"):
        with open(os.path.join("Project/Fyleria/Utility/Version.cpp"), "w") as f:
            f.write("char const* GetVersionStringShort() {\n")
            f.write("return \"%s\";\n" % (Repository.GetGitVersion()))
            f.write("}\n")
            f.write("char const* GetVersionStringLong() {\n")
            f.write("return \"%s (%s %s)\";\n" % (Repository.GetGitVersion(), system_info.date, system_info.uname))
            f.write("}\n")

    # Premake flags
    premake_file_flag = "--file=Project/premake5.lua"
    premake_file_arch = "--arch=" + system_info.arch
    premake_file_os = "--os=" + system_info.os
    premake_verbose_flag = "--verbose=1" if program_options.verbose else ""

    # Create project files
    Utility.RunSubprocess(
        subprocess_args=[
            system_info.premake_bin,
            program_options.build_type,
            premake_file_flag,
            premake_file_arch,
            premake_file_os,
            premake_verbose_flag
        ],
        verbose_output=program_options.verbose)
###########################################################################
## Build Project
def BuildProject(system_info, program_options):

    # Inform user
    Utility.LogStatement("Building project")

    # Change to build directory
    if os.path.exists(system_info.build_path):
        Utility.LogStatement("Changing directory to " + system_info.build_path)
        os.chdir(system_info.build_path)

    # Makefile build type
    if program_options.build_type.startswith("gmake"):

        # Build flags
        build_verbose_flag = "verbose=1"
        build_debug32_flag = "config=debug32" if (system_info.is_32bits and program_options.configuration == "debug") else ""
        build_debug64_flag = "config=debug64" if (system_info.is_64bits and program_options.configuration == "debug") else ""
        build_release32_flag = "config=release32" if (system_info.is_32bits and program_options.configuration == "release") else ""
        build_release64_flag = "config=release64" if (system_info.is_64bits and program_options.configuration == "release") else ""

        # Run build
        Utility.RunLiveSubprocess(
            subprocess_args=[
                system_info.make_bin,
                build_debug32_flag,
                build_debug64_flag,
                build_release32_flag,
                build_release64_flag,
                build_verbose_flag
            ],
            verbose_output=program_options.verbose)

    # Visual studio
    elif program_options.build_type.startswith("vs"):

        # Build flags
        build_solution_file = "all.sln"
        build_build_flag = "/Build"
        build_debug32_flag = "Debug32|Win32" if (system_info.is_32bits and program_options.configuration == "debug") else ""
        build_debug64_flag = "Debug64|x64" if (system_info.is_64bits and program_options.configuration == "debug") else ""
        build_release32_flag = "Release32|Win32" if (system_info.is_32bits and program_options.configuration == "release") else ""
        build_release64_flag = "Release64|x64" if (system_info.is_64bits and program_options.configuration == "release") else ""

        # Run build
        Utility.RunLiveSubprocess(
            subprocess_args=[
                system_info.build_bin,
                build_solution_file,
                build_build_flag,
                build_debug32_flag,
                build_debug64_flag,
                build_release32_flag,
                build_release64_flag
            ],
            verbose_output=program_options.verbose)
###########################################################################
