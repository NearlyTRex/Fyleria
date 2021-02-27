# Source: https://github.com/NearlyTRex/CJSMin

# Program info
Setup = {}
Setup['steps'] = {}
Setup['steps']['posix'] = []
Setup['steps']['posix'].append('RunProcess("gcc jsmin.c -O3 -o jsmin")')
