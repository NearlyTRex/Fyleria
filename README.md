# Fyleria
This is the game engine for an upcoming RPG.

# Badges
[![Build (Linux)](https://github.com/NearlyTRex/Fyleria/actions/workflows/build-linux.yml/badge.svg)](https://github.com/NearlyTRex/Fyleria/actions/workflows/build-linux.yml)
[![Build (Windows)](https://github.com/NearlyTRex/Fyleria/actions/workflows/build-windows.yml/badge.svg)](https://github.com/NearlyTRex/Fyleria/actions/workflows/build-windows.yml)
[![Deploy (Linux)](https://github.com/NearlyTRex/Fyleria/actions/workflows/deploy-linux.yml/badge.svg)](https://github.com/NearlyTRex/Fyleria/actions/workflows/deploy-linux.yml)
[![Deploy (Windows)](https://github.com/NearlyTRex/Fyleria/actions/workflows/deploy-windows.yml/badge.svg)](https://github.com/NearlyTRex/Fyleria/actions/workflows/deploy-windows.yml)

# License
The engine itself is released here under the BSD 2-Clause License.
All other materials (such as game assets) are proprietary and confidential.

# Building - Linux
To build in debug mode:
```
python3 Setup.py -v --configuration debug --buildtype gmake2 all
```
To build in release mode:
```
python3 Setup.py -v --configuration release --buildtype gmake2 all
```

# Building - Windows
To build in debug mode:
```
python Setup.py -v --configuration debug --buildtype vs2022 all
```
To build in release mode:
```
python Setup.py -v --configuration release --buildtype vs2022 all
```

# Project Generator
The Setup.py script can setup libraries/tools and create/run build scripts.

Available options:
- all (do everything)
- setup_libs (setup all libs)
- setup_c_libs (setup only c libs)
- setup_cpp_libs (setup only c++ libs)
- setup_py_libs (setup only python libs)
- setup_js_libs (setup only javascript libs)
- setup_tools (setup tools)
- create_project (create project files)
- build_project (build project files)

Force setup steps (regardless of autodetection):
- --force_32 (Force 32-bit configuration)
- --force_64 (Force 64-bit configuration)
- --force_linux (Force Linux configuration)
- --force_macosx (Force MacOSX configuration)
- --force_windows (Force Windows configuration)
- --force_wsl (Force Windows Subsystem for Linux configuration)
- --force_cygwin (Force Cygwin configuration)
- --force_mingw (Force MinGW configuration)

Configuration (--configuration):
- release
- debug (default)

Build type (--buildtype):
- gmake
- gmake2 (default)
- codelite
- vs2005
- vs2008
- vs2010
- vs2012
- vs2013
- vs2015
- vs2017
- vs2019
- vs2022
- xcode4

Verbose (-v, --verbose)

# Third Party Libraries
The following libraries are used.

**Library**|**Language**|**License**
:-----:|:-----:|:-----:
[JSMin](https://www.github.com/NearlyTrex/CJSMin)|C|[MIT](https://opensource.org/license/mit)
[ZLib](https://www.github.com/NearlyTrex/Zlib)|C|[zlib](https://opensource.org/license/zlib)
[Backward Cpp](https://www.github.com/NearlyTrex/Backward)|C++|[MIT](https://opensource.org/license/mit)
[Better Enums](https://www.github.com/NearlyTrex/BetterEnums)|C++|[BSD 2-Clause](https://opensource.org/license/bsd-2-clause)
[Boost](https://www.github.com/NearlyTrex/Boost)|C++|[Boost](https://opensource.org/license/bsl-1-0)
[Date](https://www.github.com/NearlyTrex/Date)|C++|[MIT](https://opensource.org/license/mit)
[Fantasy Name Generator](https://www.github.com/NearlyTrex/FantasyName)|C++|[Unlicense](https://opensource.org/license/unlicense)
[C++ Immutable String](https://www.github.com/NearlyTrex/ImmutableString)|C++|[MIT](https://opensource.org/license/mit)
[JSON for Modern C++](https://www.github.com/NearlyTrex/Json)|C++|[MIT](https://opensource.org/license/mit)
[LRU Cache](https://www.github.com/NearlyTrex/LRUCache)|C++|[MIT](https://opensource.org/license/mit)
[MicroPather](https://www.github.com/NearlyTrex/MicroPather)|C++|[zlib](https://opensource.org/license/zlib)
[Object Threadsafe](https://www.github.com/NearlyTrex/ObjectThreadsafe)|C++|[Apache 2.0](https://opensource.org/license/apache-2-0)
[SpdLog](https://www.github.com/NearlyTrex/SpdLog)|C++|[MIT](https://opensource.org/license/mit)
[WebView](https://www.github.com/NearlyTrex/WebView)|C++|[MIT](https://opensource.org/license/mit)
[WebKit](https://www.github.com/NearlyTrex/WebKit)|C++|[LGPL](https://opensource.org/license/lgpl-license-html) / [BSD 2-Clause](https://opensource.org/license/bsd-2-clause)
