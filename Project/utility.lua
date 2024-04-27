-- Guess architecture
function GuessArchitecture()
    local arch_name = 'unknown'

    if jit and jit.os and jit.arch then
        arch_name = jit.arch
    else
        if os.target() == "windows" then
            local env_ARCH = os.getenv('PROCESSOR_ARCHITECTURE')
            if env_ARCH then
                arch_name = env_ARCH
            end
        else
            arch_name = io.popen('uname -m','r'):read('*l')
        end
    end

    arch_name = (arch_name):lower()
    return arch_name
end

-- Guess operating system
function GuessOperatingSystem()
    local os_name = 'unknown'

    if jit and jit.os and jit.arch then
        os_name = jit.os
    else
        if os.target() == "windows" then
            local env_OS = os.getenv('OS')
            if env_OS then
                os_name = env_OS
            end
        else
            os_name = io.popen('uname -s','r'):read('*l')
        end
    end

    os_name = (os_name):lower()
    return os_name
end

-- Get architecture
function GetArchitecture()
    return (_OPTIONS["arch"] or GuessArchitecture())
end

-- Get operating system
function GetOperatingSystem()
    return (_OPTIONS["os"] or GuessOperatingSystem())
end

-- Get C++ 14 dialect
function GetCpp14Dialect()
    return "C++14"
end

-- Get C++ 17 dialect
function GetCpp17Dialect()
    return "C++17"
end

-- Get C++ 20 dialect
function GetCpp20Dialect()
    return "C++20"
end

-- Get C++ 23 dialect
function GetCpp23Dialect()
    return "C++23"
end

-- Get build toolset
function GetBuildToolset()
    if os.host() == "linux" then
        return "gcc"
    elseif os.host() == "windows" then
        return "msc"
    end
end

-- Get build location
function GetBuildLocation()
    return "Build_" .. os.host() .. "_" .. _ACTION
end

-- Get target debug suffix
function GetTargetDebugSuffix()
    return "_debug"
end

-- Get target release suffix
function GetTargetReleaseSuffix()
    return "_release"
end

-- Get application target directory
function GetAppTargetDirectory()
    return "../Bin"
end

-- Get library target directory
function GetLibraryTargetDirectory()
    return "../Bin"
end

-- Get process target directory
function GetProcessTargetDirectory()
    return "../Bin"
end

-- Get target name
function GetTargetName(target)
    return target .. "_" .. GetOperatingSystem() .. "_" .. GetArchitecture()
end

-- Get application run paths
function GetAppRunPaths()
    return {
    }
end

-- Get library run paths
function GetLibraryRunPaths()
    return {
    }
end

-- Get process run paths
function GetProcessRunPaths()
    return {
    }
end

-- Get console app type
function GetConsoleAppType()
    return "ConsoleApp"
end

-- Get windowed app type
function GetWindowedAppType()
    return "WindowedApp"
end

-- Get app type
function GetAppType()
    if os.host() == "windows" then
        return GetWindowedAppType()
    else
        return GetConsoleAppType()
    end
end

-- Get static library type
function GetStaticLibraryType()
    return "StaticLib"
end

-- Get shared library type
function GetSharedLibraryType()
    return "SharedLib"
end

-- Get executable extension
function GetExecutableExtension()
    if os.host() == "windows" then
        return ".exe"
    else
        return ""
    end
end

-- Get static library extension
function GetStaticLibraryExtension()
    if os.host() == "windows" then
        return ".lib"
    else
        return ".a"
    end
end

-- Get shared library extension
function GetSharedLibraryExtension()
    if os.host() == "windows" then
        return ".dll"
    elseif os.host() == "linux" then
        return ".so"
    elseif os.host() == "darwin" then
        return ".dylib"
    end
end

-- Get executable filename
function GetExecutableFilename(target, mode)
    if mode == "release" then
        return GetTargetName(target) .. GetTargetReleaseSuffix() .. GetExecutableExtension()
    elseif mode == "debug" then
        return GetTargetName(target) .. GetTargetDebugSuffix() .. GetExecutableExtension()
    end
end

-- Get static library filename
function GetStaticLibraryFilename(target, mode)
    if mode == "release" then
        return "lib" .. GetTargetName(target) .. GetTargetReleaseSuffix() .. GetStaticLibraryExtension()
    elseif mode == "debug" then
        return "lib" .. GetTargetName(target) .. GetTargetDebugSuffix() .. GetStaticLibraryExtension()
    end
end

-- Get shared library filename
function GetSharedLibraryFilename(target, mode)
    if mode == "release" then
        return "lib" .. GetTargetName(target) .. GetTargetReleaseSuffix() .. GetSharedLibraryExtension()
    elseif mode == "debug" then
        return "lib" .. GetTargetName(target) .. GetTargetDebugSuffix() .. GetSharedLibraryExtension()
    end
end
