# Imports
import os, os.path
import sys
import importlib
import shutil
import subprocess
from . import Utility

###########################################################################
# Setup project
def SetupProject(project_name, project_base_dir, system_info, program_options):

    # Inform user
    Utility.LogStatement("Setting up project: " + project_name)

    # Import library module
    projectdir = os.path.join(project_base_dir, project_name)
    sys.path.append(projectdir)
    module = importlib.import_module(project_name)

    # Generate archive info
    archive_base = module.Setup['url'].split('/')[-1].split('.')[0]
    archive_ext = module.Setup['url'].split('.')[-1]
    archive_file = os.path.join(projectdir, archive_base + '.' + archive_ext)
    archive_olddir = os.path.join(projectdir, module.Setup['extractdir'])
    archive_newdir = os.path.join(projectdir, "orig")

    # Remove archive if we are forcing a new download
    if program_options.force_download and os.path.exists(archive_file):
        Utility.LogStatement("Removing old archive file %s" % archive_file)
        os.remove(archive_file)

    # Remove old folders if we are forcing a new download
    if program_options.force_download:
        Utility.LogStatement("Removing old folders %s and %s" % (archive_olddir, archive_newdir))
        shutil.rmtree(archive_olddir, ignore_errors=True)
        shutil.rmtree(archive_newdir, ignore_errors=True)

    # Download archive if we are forcing a new download and the archive does not exist yet
    if program_options.force_download and not os.path.exists(archive_file):
        from urllib.request import urlopen
        Utility.LogStatement("Downloading " + module.Setup['url'] + " to file " + archive_file)
        request = urlopen(module.Setup['url'])
        output = open(archive_file, "wb")
        output.write(request.read())
        output.close()
        if not os.path.exists(archive_file):
            Utility.ErrorStatement("Could not download archive for %s" % project_name)
            sys.exit(-1)

    # Extract library archive
    if os.path.isfile(archive_file) and os.path.exists(projectdir) and not os.path.exists(archive_newdir):
        Utility.LogStatement("Extracting " + archive_file + " to " + projectdir)
        Utility.RunLiveSubprocess(subprocess_args = [system_info.unzip_bin, archive_file, "-d", projectdir], verbose_output = True)

    # Move extracted archive
    if os.path.exists(archive_olddir) and not os.path.exists(archive_newdir):
        Utility.LogStatement("Moving " + archive_olddir + " to " + archive_newdir)
        shutil.move(archive_olddir, archive_newdir)

    # Run extra setup steps
    if module.Setup['steps'] and os.path.exists(archive_newdir):

        # Go to new archive directory
        if os.path.exists(archive_newdir):
            Utility.LogStatement("Changing directory to " + archive_newdir)
            os.chdir(archive_newdir)

        # Run basic extra steps
        Utility.RunExtraSteps(module.Setup['steps'], "linux", system_info.is_linux and not system_info.is_mingw)
        Utility.RunExtraSteps(module.Setup['steps'], "macosx", system_info.is_macosx and not system_info.is_mingw)
        Utility.RunExtraSteps(module.Setup['steps'], "bsd", system_info.is_bsd and not system_info.is_mingw)
        Utility.RunExtraSteps(module.Setup['steps'], "wsl", system_info.is_macosx and not system_info.is_mingw)
        Utility.RunExtraSteps(module.Setup['steps'], "posix", system_info.is_posix and not system_info.is_mingw)
        Utility.RunExtraSteps(module.Setup['steps'], "windows", system_info.is_windows)
        Utility.RunExtraSteps(module.Setup['steps'], "cygwin", system_info.is_cygwin)
        Utility.RunExtraSteps(module.Setup['steps'], "mingw", system_info.is_mingw)
        Utility.RunExtraSteps(module.Setup['steps'], "all", True)

        # Run bitsize extra steps
        Utility.RunExtraSteps(module.Setup['steps'], "linux32", system_info.is_linux and system_info.is_32bits and not system_info.is_mingw)
        Utility.RunExtraSteps(module.Setup['steps'], "linux64", system_info.is_linux and system_info.is_64bits and not system_info.is_mingw)
        Utility.RunExtraSteps(module.Setup['steps'], "macosx32", system_info.is_macosx and system_info.is_32bits and not system_info.is_mingw)
        Utility.RunExtraSteps(module.Setup['steps'], "macosx64", system_info.is_macosx and system_info.is_64bits and not system_info.is_mingw)
        Utility.RunExtraSteps(module.Setup['steps'], "bsd32", system_info.is_bsd and system_info.is_32bits and not system_info.is_mingw)
        Utility.RunExtraSteps(module.Setup['steps'], "bsd64", system_info.is_bsd and system_info.is_64bits and not system_info.is_mingw)
        Utility.RunExtraSteps(module.Setup['steps'], "wsl32", system_info.is_wsl and system_info.is_32bits and not system_info.is_mingw)
        Utility.RunExtraSteps(module.Setup['steps'], "wsl64", system_info.is_wsl and system_info.is_64bits and not system_info.is_mingw)
        Utility.RunExtraSteps(module.Setup['steps'], "posix32", system_info.is_posix and system_info.is_32bits and not system_info.is_mingw)
        Utility.RunExtraSteps(module.Setup['steps'], "posix64", system_info.is_posix and system_info.is_64bits and not system_info.is_mingw)
        Utility.RunExtraSteps(module.Setup['steps'], "windows32", system_info.is_windows and system_info.is_32bits)
        Utility.RunExtraSteps(module.Setup['steps'], "windows64", system_info.is_windows and system_info.is_64bits)
        Utility.RunExtraSteps(module.Setup['steps'], "cygwin32", system_info.is_cygwin and system_info.is_32bits)
        Utility.RunExtraSteps(module.Setup['steps'], "cygwin64", system_info.is_cygwin and system_info.is_64bits)
        Utility.RunExtraSteps(module.Setup['steps'], "mingw32", system_info.is_mingw and system_info.is_32bits)
        Utility.RunExtraSteps(module.Setup['steps'], "mingw64", system_info.is_mingw and system_info.is_64bits)
        Utility.RunExtraSteps(module.Setup['steps'], "all32", system_info.is_32bits)
        Utility.RunExtraSteps(module.Setup['steps'], "all64", system_info.is_64bits)

        # Go back to root directory
        Utility.LogStatement("Changing directory to " + system_info.root_path)
        os.chdir(system_info.root_path)
###########################################################################
## Build Project
def BuildProject(system_info, program_options):

    # Inform user
    Utility.LogStatement("Building project")

    # Flags
    premake_file_flag = "--file=Project/premake5.lua"
    premake_verbose_flag = "--verbose=1" if program_options.verbose else ""
    make_verbose_flag = "verbose=1"
    make_debug32_flag = "config=debug32" if (system_info.is_32bits and program_options.configuration == "debug") else ""
    make_debug64_flag = "config=debug64" if (system_info.is_64bits and program_options.configuration == "debug") else ""
    make_release32_flag = "config=release32" if (system_info.is_32bits and program_options.configuration == "release") else ""
    make_release64_flag = "config=release64" if (system_info.is_64bits and program_options.configuration == "release") else ""

    # Create project files
    Utility.RunSubprocess(subprocess_args=[
        system_info.premake_bin,
        program_options.build_type,
        premake_file_flag,
        premake_verbose_flag
    ], verbose_output=program_options.verbose)

    # Change to build directory
    if os.path.exists(system_info.build_path):
        Utility.LogStatement("Changing directory to " + system_info.build_path)
        os.chdir(system_info.build_path)

    # Build project
    Utility.RunLiveSubprocess(subprocess_args=[
        system_info.make_bin,
        make_debug32_flag,
        make_debug64_flag,
        make_release32_flag,
        make_release64_flag,
        make_verbose_flag
    ], verbose_output=program_options.verbose)
###########################################################################
