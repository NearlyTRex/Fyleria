# Fyleria

This is the game engine for an upcoming RPG.

## Badges

[![CI](https://github.com/NearlyTRex/Fyleria/actions/workflows/ci.yml/badge.svg)](https://github.com/NearlyTRex/Fyleria/actions/workflows/ci.yml)
[![Security](https://github.com/NearlyTRex/Fyleria/actions/workflows/security.yml/badge.svg)](https://github.com/NearlyTRex/Fyleria/actions/workflows/security.yml)
[![Release](https://github.com/NearlyTRex/Fyleria/actions/workflows/release.yml/badge.svg)](https://github.com/NearlyTRex/Fyleria/actions/workflows/release.yml)

## License

The engine itself is released here under the BSD 2-Clause License.
All other materials (such as game assets) are proprietary and confidential.

## Building

Fyleria builds with CMake 3.25 or newer. The third party libraries are git submodules, so clone
with `--recurse-submodules`, or fetch them in an existing clone:

```bash
git submodule update --init
```

Each preset configures, builds and runs the unit tests. The programs land in `Bin`, next to
`Data`, named for the platform and configuration (`FyleriaMain_linux_x86_64_release`).

### Linux

Needs Ninja, a C++17 compiler, and the GTK, WebKitGTK and libdw development packages. On
Ubuntu:

```bash
sudo apt install cmake ninja-build g++ pkg-config binutils-dev libdw-dev libgtk-3-dev libwebkit2gtk-4.1-dev
```

```bash
cmake --workflow --preset linux-debug
cmake --workflow --preset linux-release
```

### Windows

Needs Visual Studio 2022 with the C++ workload. From any shell:

```bash
cmake --workflow --preset windows-debug
cmake --workflow --preset windows-release
```

To work in Visual Studio, open the generated `Build/windows/Fyleria.sln`, or open the folder
and pick a preset.

## Third Party Libraries

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
