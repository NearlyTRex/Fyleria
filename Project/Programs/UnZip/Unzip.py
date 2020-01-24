# Source: https://github.com/NearlyTRex/UnZip
# Version: 6.10-c25

# Program info
Setup = {}
Setup['url'] = "https://github.com/NearlyTRex/UnZip/archive/UnZip-6.10-c25.zip"
Setup['extractdir'] = "UnZip-UnZip-6.10-c25"
Setup['steps'] = {}
Setup['steps']['posix'] = []
Setup['steps']['posix'].append('RunProcess("make -f unix/Makefile CC=gcc generic")')
