# Source: https://github.com/NearlyTRex/Tiled
# Version: 1.2.5

# Program info
Setup = {}
Setup['url'] = "https://github.com/NearlyTRex/Tiled/archive/Tiled-1.2.5.zip"
Setup['extractdir'] = "Tiled-Tiled-1.2.5"
Setup['steps'] = {}
Setup['steps']['posix'] = []
Setup['steps']['posix'].append('RunProcess("qmake")')
Setup['steps']['posix'].append('RunProcess("make")')
Setup['steps']['posix'].append('MakeExecutable("./bin/tiled")')
Setup['steps']['windows'] = []
Setup['steps']['windows'].append('RunProcess("qmake")')
Setup['steps']['windows'].append('RunProcess("make")')
Setup['steps']['windows'].append('MakeExecutable("./bin/tiled.exe")')
