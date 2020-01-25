# Source: https://github.com/NearlyTRex/BetterEnums
# Version: 08172019

# Steps
CreateEnumMacrosHeader = 'RunProcess("python script/make_macros.py 124 128 > enum_macros.h")'

# Library info
Setup = {}
Setup['url'] = "https://github.com/NearlyTRex/BetterEnums/archive/BetterEnums-08172019.zip"
Setup['extractdir'] = "BetterEnums-BetterEnums-08172019"
Setup['steps'] = {}
Setup['steps']['all'] = []
Setup['steps']['all'].append(CreateEnumMacrosHeader)
