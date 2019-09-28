# Source: https://github.com/NearlyTRex/infozip-zip
# Version: Gitmaster

# Program info
Setup = {}
Setup['url'] = "https://github.com/NearlyTRex/infozip-zip/archive/master.zip"
Setup['extractdir'] = "infozip-zip-master"
Setup['steps'] = {}
Setup['steps']['posix'] = []
Setup['steps']['posix'].append('RunProcess("make -f unix/Makefile CC=gcc generic")')
