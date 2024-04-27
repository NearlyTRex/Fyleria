# Steps
MakePhaserDir = 'MakeDirectory("$(RootPath)/Data/Libs/ThirdParty/Phaser")'
CopyFilePhaserJs = 'CopyFile("dist/phaser.min.js", "$(RootPath)/Data/Libs/ThirdParty/Phaser/phaser.min.js")'

# Library info
Setup = {}
Setup["url"] = "https://github.com/NearlyTRex/Phaser"
Setup['steps'] = {}
Setup['steps']['all'] = []
Setup['steps']['all'].append(MakePhaserDir)
Setup['steps']['all'].append(CopyFilePhaserJs)
