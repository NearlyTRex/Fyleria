# Source: https://github.com/NearlyTRex/JSMin
# Version: Gitmaster

# Program info
Setup = {}
Setup['url'] = "https://github.com/NearlyTRex/JSMin/archive/master.zip"
Setup['extractdir'] = "JSMin-master"
Setup['steps'] = {}
Setup['steps']['posix'] = []
Setup['steps']['posix'].append('RunProcess("gcc jsmin.c -O3 -o jsmin")')
