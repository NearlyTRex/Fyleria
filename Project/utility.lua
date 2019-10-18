-- Get architecture
function GetArchitecture()
    local raw_arch_name = ''

    -- LuaJIT shortcut
    if jit and jit.os and jit.arch then
        raw_arch_name = jit.arch
    else
        -- Is popen supported?
        local popen_status, popen_result = pcall(io.popen, "")
        if popen_status then
            popen_result:close()
            -- Unix-based OS
            raw_arch_name = io.popen('uname -m','r'):read('*l')
        else
            -- Windows
            local env_ARCH = os.getenv('PROCESSOR_ARCHITECTURE')
            if env_ARCH then
                raw_arch_name = env_ARCH
            end
        end
    end

    raw_arch_name = (raw_arch_name):lower()

    local arch_patterns = {
        ['^x86$'] = 'x86_32',
        ['i[%d]86'] = 'x86_32',
        ['amd64'] = 'x86_64',
        ['x86_64'] = 'x86_64',
        ['Power Macintosh'] = 'powerpc',
        ['^arm'] = 'arm',
        ['^mips'] = 'mips',
    }

    local arch_name = 'unknown'

    for pattern, name in pairs(arch_patterns) do
        if raw_arch_name:match(pattern) then
            arch_name = name
            break
        end
    end

    return arch_name
end

-- Get operating system
function GetOperatingSystem()
    local raw_os_name = ''

    -- LuaJIT shortcut
    if jit and jit.os and jit.arch then
        raw_os_name = jit.os
    else
        -- Is popen supported?
        local popen_status, popen_result = pcall(io.popen, "")
        if popen_status then
            popen_result:close()
            -- Unix-based OS
            raw_os_name = io.popen('uname -s','r'):read('*l')
        else
            -- Windows
            local env_OS = os.getenv('OS')
            if env_OS then
                raw_os_name = env_OS
            end
        end
    end

    raw_os_name = (raw_os_name):lower()

    local os_patterns = {
        ['linux'] = 'linux',
        ['mac'] = 'macos',
        ['darwin'] = 'macos',
        ['windows'] = 'windows',
        ['^mingw'] = 'windows',
        ['^cygwin'] = 'windows',
    }

    local os_name = 'unknown'

    for pattern, name in pairs(os_patterns) do
        if raw_os_name:match(pattern) then
            os_name = name
            break
        end
    end

    return os_name
end

-- Get C++ 14 dialect
function GetCpp14Dialect()
    return "C++14"
end

-- Get C++ 17 dialect
function GetCpp17Dialect()
    return "C++17"
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
    return "Build_" .. os.host()
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
    return ".."
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

-- Get app type
function GetAppType()
    if os.host() == "windows" then
        return "WindowedApp"
    else
        return "ConsoleApp"
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
