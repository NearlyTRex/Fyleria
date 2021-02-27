# Source: https://github.com/NearlyTRex/BetterEnums

# Steps
CreateEnumMacrosHeader = 'RunProcess("python script/make_macros.py 124 128 > enum_macros.h")'

# Library info
Setup = {}
Setup['steps'] = {}
Setup['steps']['all'] = []
Setup['steps']['all'].append(CreateEnumMacrosHeader)
