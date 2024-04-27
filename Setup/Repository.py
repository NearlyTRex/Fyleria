# Imports
import os, os.path
import sys
import importlib
import shutil
import subprocess
from . import Utility

###########################################################################
## Get git version
def GetGitVersion():
    success, output = Utility.RunSubprocess(["git", "describe", "--dirty", "--always", "--tags"])
    if not success:
        raise Exception("Unable to get git version")
    return output.strip()
###########################################################################
## Add submodule
def AddSubmodule(url, dir):
    success, output = Utility.RunSubprocess(["git", "submodule", "add", "-f", url, dir])
    if not success:
        raise Exception("Unable to add git submodule")
    return output.strip()
###########################################################################
