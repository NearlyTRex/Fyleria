# Source: https://github.com/NearlyTRex/unzip
# Version: Gitmaster

# Program info
Setup = {}
Setup['url'] = "https://github.com/NearlyTRex/unzip/archive/master.zip"
Setup['extractdir'] = "unzip-master"
Setup['steps'] = {}
Setup['steps']['all'] = []
Setup['steps']['all'].append('RunProcess("cmake .")')
Setup['steps']['all'].append('RunProcess("make")')
