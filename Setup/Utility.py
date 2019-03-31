# Imports
import os, os.path
import shutil
import subprocess
import stat

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
def RunSubprocess(subprocess_args = [], expected_substr = "", verbose_output = False):
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
            universal_newlines=True)
        if verbose_output:
            if len(result.stdout) > 0:
                print(result.stdout)
        if len(expected_substr) > 0:
            return (expected_substr in output, result.stdout)
        return (True, result.stdout)
    except Exception:
        return (False, "")
###########################################################################
## Run subprocess and get live output
def RunLiveSubprocess(subprocess_args = [], verbose_output = False):
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
            universal_newlines=True)
        while verbose_output and True:
            output = process.stdout.readline()
            if output == '' and process.poll() is not None:
                break
            if output:
                print(output.strip())
        code = process.poll()
        return code
    except Exception:
        return -1
###########################################################################
# Run extra steps
def RunExtraSteps(steps, platform, flags):

    # Run process and show output in realtime
    def RunProcess(process):
        subprocess.call(process, shell=True)

    # Copy file
    def CopyFile(src, dest):
        if os.path.isfile(src) and not os.path.exists(dest):
            shutil.copyfile(src, dest)

    # Replace text in the given file
    def ReplaceText(filename, old, new):
        if os.path.isfile(filename):
            f = open(filename,'r')
            filedata = f.read()
            f.close()
            newdata = filedata.replace(old, new)
            f = open(filename,'w')
            f.write(newdata)
            f.close()

    # Make the file executable
    def MakeExecutable(file):
        if os.path.isfile(file):
            st = os.stat(file)
            os.chmod(file, st.st_mode | stat.S_IEXEC)

    # Evaluate the steps for the given platform
    if platform in steps and flags:
        for step in steps[platform]:
            LogStatement("Running extra step " + step)
            eval(step)
###########################################################################
