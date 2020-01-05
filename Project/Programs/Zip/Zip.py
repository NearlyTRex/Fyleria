# Source: https://github.com/NearlyTRex/Zip
# Version: 3.1-d34-s3

# Program info
Setup = {}
Setup['url'] = "https://github.com/NearlyTRex/Zip/archive/Zip-3.1-d34-s3.zip"
Setup['extractdir'] = "Zip-Zip-3.1-d34-s3"
Setup['steps'] = {}
Setup['steps']['posix'] = []
Setup['steps']['posix'].append('RunProcess("make -f unix/Makefile CC=gcc generic")')
