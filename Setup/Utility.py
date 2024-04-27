# Imports
import os, os.path
import sys
import shutil
import subprocess
import stat

###########################################################################
# Required python version
def GetRequiredPythonVersion():
    return (3,5)
###########################################################################
# Detect Python version
def DetectPython(required_version):
    if (sys.version_info <= required_version):
        return False
    else:
        return True
###########################################################################
## Print log statement
def LogStatement(message, include_elipses = True):
    output = " -- "
    output += message
    if include_elipses:
        output += " ... "
    print(output)
###########################################################################
## Print error statement
def ErrorStatement(message, include_elipses = True):
    output = "ERROR: "
    output += message
    if include_elipses:
        output += " ... "
    print(output)
###########################################################################
## Run subprocess
def RunSubprocess(subprocess_args = [], subprocess_env = None, expected_substr = "", verbose_output = False):
    cleared_subprocess_args = [x for x in subprocess_args if x.strip()]
    if not len(cleared_subprocess_args):
        return (False, "")
    try:
        if verbose_output:
            LogStatement("Running subprocess '%s'" % (" ".join(cleared_subprocess_args)))
        result = subprocess.run(
            args=cleared_subprocess_args,
            stderr=subprocess.STDOUT,
            stdout=subprocess.PIPE,
            env=subprocess_env,
            shell=False,
            universal_newlines=True)
        if verbose_output:
            if len(result.stdout) > 0:
                print(result.stdout)
        if len(expected_substr) > 0:
            return (expected_substr in output, result.stdout)
        return (True, result.stdout)
    except Exception as e:
        if verbose_output:
            print(e)
        return (False, "")
###########################################################################
## Run subprocess and get live output
def RunLiveSubprocess(subprocess_args = [], subprocess_env = None, verbose_output = False):
    cleared_subprocess_args = [x for x in subprocess_args if x.strip()]
    if not len(cleared_subprocess_args):
        return (False, "")
    try:
        if verbose_output:
            LogStatement("Running subprocess '%s'" % (" ".join(cleared_subprocess_args)))
        process = subprocess.Popen(
            args=cleared_subprocess_args,
            stderr=subprocess.STDOUT,
            stdout=subprocess.PIPE,
            env=subprocess_env,
            shell=False,
            universal_newlines=True)
        while verbose_output and True:
            output = process.stdout.readline()
            if output == '' and process.poll() is not None:
                break
            if output:
                print(output.strip())
        code = process.poll()
        return code
    except Exception as e:
        if verbose_output:
            print(e)
        return -1
###########################################################################
# Run extra steps
def RunExtraSteps(steps, platform, root_path, flags):

    # Resolve paths
    def ResolvePaths(path):
        new_path = path.replace("$(RootPath)", root_path)
        return new_path

    # Run process and show output in realtime
    def RunProcess(process):
        new_process = ResolvePaths(process)
        subprocess.call(new_process, shell=True)

    # Minify file
    def MinifyFile(src, dest):
        new_src = ResolvePaths(src)
        new_dest = ResolvePaths(dest)
        import jsmin
        with open(new_src, 'r') as input_file:
            minified = jsmin.jsmin(input_file.read())
            with open(new_dest, 'w') as output_file:
                output_file.write(minified)

    # Copy file
    def CopyFile(src, dest):
        new_src = ResolvePaths(src)
        new_dest = ResolvePaths(dest)
        shutil.copyfile(new_src, new_dest)

    # Copy files matching a substring
    def CopySubstringFiles(src, dest, substring):
        new_src = ResolvePaths(src)
        new_dest = ResolvePaths(dest)
        matching_files = []
        for root, dirs, files in os.walk(new_src):
            for name in files:
                if substring in name:
                    matching_files.append(os.path.join(root, name))
        for file in matching_files:
            shutil.copy(file, new_dest)

    # Copy directory
    def CopyDirectory(src, dest):
        new_src = ResolvePaths(src)
        new_dest = ResolvePaths(dest)
        if not os.path.exists(new_dest):
            try:
                shutil.copytree(new_src, new_dest)
            except:
                pass

    # Make symlink
    def MakeSymlink(src, dest):
        new_src = ResolvePaths(src)
        new_dest = ResolvePaths(dest)
        if os.path.islink(new_dest):
            os.unlink(new_dest)
        os.symlink(new_src, new_dest)

    # Make directory
    def MakeDirectory(dest):
        new_dest = ResolvePaths(dest)
        if not os.path.exists(new_dest):
            try:
                os.makedirs(new_dest)
            except:
                pass

    # Replace text in the given file
    def ReplaceText(filename, old, new):
        new_filename = ResolvePaths(filename)
        f = open(new_filename,'r')
        filedata = f.read()
        f.close()
        newdata = filedata.replace(old, new)
        f = open(new_filename,'w')
        f.write(newdata)
        f.close()

    # Make the file executable
    def MakeExecutable(filename):
        new_filename = ResolvePaths(filename)
        st = os.stat(new_filename)
        os.chmod(new_filename, st.st_mode | stat.S_IEXEC)

    # Evaluate the steps for the given platform
    if platform in steps and flags:
        for step in steps[platform]:
            LogStatement("Running extra step " + step)
            eval(step)
###########################################################################
