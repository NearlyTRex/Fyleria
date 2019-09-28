# Source: https://github.com/NearlyTRex/infozip-unzip
# Version: Gitmaster

# Program info
Setup = {}
Setup['url'] = "https://github.com/NearlyTRex/infozip-unzip/archive/master.zip"
Setup['extractdir'] = "infozip-unzip-master"
Setup['steps'] = {}
Setup['steps']['posix'] = []
Setup['steps']['posix'].append('RunProcess("make -f unix/Makefile CC=gcc generic")')
