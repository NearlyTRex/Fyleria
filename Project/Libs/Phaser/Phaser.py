# Source: https://github.com/NearlyTRex/Phaser
# Version: 3.20.1

# Steps
CopyFilePhaserJs = 'CopyFile("dist/phaser.min.js", "$(RootPath)/Data/Libs/phaser.min.js")'
CopyFilePhaserArcadePhysicsJs = 'CopyFile("dist/phaser-arcade-physics.min.js", "$(RootPath)/Data/Libs/phaser-arcade-physics.min.js")'

# Library info
Setup = {}
Setup['url'] = "https://github.com/NearlyTRex/Phaser/archive/Phaser-3.20.1.zip"
Setup['extractdir'] = "Phaser-Phaser-3.20.1"
Setup['steps'] = {}
Setup['steps']['all'] = []
Setup['steps']['all'].append(CopyFilePhaserJs)
Setup['steps']['all'].append(CopyFilePhaserArcadePhysicsJs)
