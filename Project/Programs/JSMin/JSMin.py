# Source: https://github.com/NearlyTRex/CJSMin
# Version: 03292013

# Program info
Setup = {}
Setup['url'] = "https://github.com/NearlyTRex/CJSMin/archive/JSMin-03292013.zip"
Setup['extractdir'] = "CJSMin-JSMin-03292013"
Setup['steps'] = {}
Setup['steps']['posix'] = []
Setup['steps']['posix'].append('RunProcess("gcc jsmin.c -O3 -o jsmin")')
