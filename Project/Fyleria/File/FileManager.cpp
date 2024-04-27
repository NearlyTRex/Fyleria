// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "File/FileManager.h"
#include "File/FileConstants.h"
#include "Cache/CacheConstants.h"
#include "Utility/Converters.h"
#include "Utility/Time.h"

namespace Gecko
{

FileManager::FileManager()
{
    // Initialize caches
    GetFileReaderCache().Initialize(CACHE_FILE_MANAGER_TIMED_CAPACITY, CACHE_FILE_MANAGER_TIMED_TTL);
    GetFilesystemCache().Initialize(CACHE_FILE_MANAGER_BASIC_CAPACITY);
}

Bool FileManager::DoesPathExist(const String& sPath)
{
    // Determine if path exists
    return BoostFilesystemExists(BoostFilesystemPath(sPath));
}

Bool FileManager::IsFile(const String& sPath)
{
    // Determine if path is a file
    return BoostFilesystemIsFile(BoostFilesystemPath(sPath));
}

Bool FileManager::IsDirectory(const String& sPath)
{
    // Determine if path is a directory
    return BoostFilesystemIsDirectory(BoostFilesystemPath(sPath));
}

Bool FileManager::IsSymbolicLink(const String& sPath)
{
    // Determine if path is a symbolic link
    return BoostFilesystemIsSymbolicLink(BoostFilesystemPath(sPath));
}

Bool FileManager::IsPosixPath(const String& sPath)
{
    // Determine if path is from a posix system
    if (sPath.length() >= 1)
    {
        return (sPath.at(0) == '/');
    }
    return false;
}

Bool FileManager::IsWindowsPath(const String& sPath)
{
    // Determine if path is from a windows system
    if (sPath.length() >= 2)
    {
        return (isalpha(sPath.at(0)) != 0) && (sPath.at(1) == ':');
    }
    return false;
}

Bool FileManager::IsWindowsNetworkDriveLocation(const String& sPath)
{
    // Determine if path is from a windows network drive
    if (sPath.length() >= 2)
    {
        return (sPath.at(0) == '\\') && (sPath.at(1) == '\\');
    }
    return false;
}

Bool FileManager::IsAbsolutePath(const String& sPath)
{
    // Determine if path is absolute
    return BoostFilesystemPath(sPath).is_absolute();
}

Bool FileManager::IsRelativePath(const String& sPath)
{
    // Determine if path is relative
    return BoostFilesystemPath(sPath).is_relative();
}

Bool FileManager::CreateTempDirectory(String& sPath)
{
    // Create temp dir
    sPath = BoostFilesystemTempDirectory().string();
    return CreateNewDirectory(sPath);
}

Bool FileManager::CreateTempFile(String& sPath, const String& sContents /*= ""*/)
{
    // Create temp file
    sPath = (BoostFilesystemTempDirectory() / BoostFilesystemTempFilename()).string();
    return WriteStringToFile(sPath, sContents);
}

Bool FileManager::CreateNewDirectory(const String& sPath)
{
    // Create new directory
    return BoostFilesystemCreateDirectory(BoostFilesystemPath(sPath));
}

Bool FileManager::CreateNewDirectories(const String& sPath)
{
    // Create new directories
    return BoostFilesystemCreateDirectories(BoostFilesystemPath(sPath));
}

Bool FileManager::RemoveDirectoryAndFiles(const String& sPath)
{
    // Remove directory and all contents
    return BoostFilesystemRemoveAll(BoostFilesystemPath(sPath)) > 0;
}

Bool FileManager::RemoveFile(const String& sPath)
{
    // Remove file
    return BoostFilesystemRemove(BoostFilesystemPath(sPath));
}

SizeType FileManager::GetFileSize(const String& sPath)
{
    // Get file size
    return static_cast<SizeType>(BoostFilesystemFileSize(BoostFilesystemPath(sPath)));
}

String FileManager::GetParentPath(const String& sPath)
{
    // Get parent path
    if (BoostFilesystemPath(sPath).has_parent_path())
    {
        return BoostFilesystemPath(sPath).parent_path().string();
    }
    return sPath;
}

String FileManager::GetAbsolutePath(const String& sPath)
{
    // Get absolute path
    return BoostFilesystemAbsolute(BoostFilesystemPath(sPath)).string();
}

String FileManager::GetCanonicalPath(const String& sPath)
{
    // Get canonical path
    return BoostFilesystemCanonical(BoostFilesystemPath(sPath)).string();
}

String FileManager::GetUriPath(const String& sPath, const String& sFileRoot /*= ""*/)
{
    // Get full path
    String sFullPath = sPath;
    if(IsRelativePath(sPath))
    {
        sFullPath = JoinPaths(sFileRoot, sPath);
    }

    // Ignored characters for URI
    const UByteArray vIgnoreChars = {'/', ':', '-', '_', '~', '.'};

    // Get URI prefix
#if defined(PLATFORM_OS_WINDOWS)
    const String sPrefix = IsWindowsNetworkDriveLocation(sFullPath) ? "file:" : "file:///";
#else
    const String sPrefix = FILE_URI_BASE;
#endif

    // Encode path as URI
    String sLocation = ConvertToUrlEncodedString(BoostReplaceAllCopy(sFullPath, "\\", "/"), vIgnoreChars);
    return sPrefix + sLocation;
}

String FileManager::JoinPaths(const String& sPath1, const String& sPath2)
{
    // Join paths together
    return (BoostFilesystemPath(sPath1) / BoostFilesystemPath(sPath2)).string();
}

String FileManager::JoinPathsCanonical(const String& sPath1, const String& sPath2)
{
    // Join paths together canonically
    return GetCanonicalPath(JoinPaths(sPath1, sPath2));
}

Bool FileManager::ReadFileToString(const String& sPath, String& sString, const String& sFileRoot /*= ""*/)
{
    // Get full path
    String sFullPath = sPath;
    if(IsRelativePath(sPath))
    {
        sFullPath = JoinPaths(sFileRoot, sPath);
    }

    // Check cache first
    CacheKey cacheKey = GenerateCacheKey(sFullPath);
    if(GetFilesystemCache().ContainsKey(cacheKey))
    {
        String sFileContents;
        if(GetFilesystemCache().GetValue(cacheKey, sFileContents))
        {
            sString = sFileContents;
            return true;
        }
    }

    // Check if path exists
    if(!DoesPathExist(sFullPath))
    {
        return false;
    }

    // Open file
    InputFile inputFile(sFullPath.c_str(), STDIOSFlagInputOperations | STDIOSFlagBinaryMode);
    if(!inputFile.is_open() && inputFile.good())
    {
        return false;
    }

    // Read string
    StringStream sBuffer;
    sBuffer << inputFile.rdbuf();
    sString = sBuffer.str();

    // Cleanup
    inputFile.close();
    GetFilesystemCache().SetValue(cacheKey, sString);
    return true;
}

Bool FileManager::ReadFileToByteArray(const String& sPath, FixedUnsigned8Array& vBytes, const String& sFileRoot /*= ""*/)
{
    // Get full path
    String sFullPath = sPath;
    if(IsRelativePath(sPath))
    {
        sFullPath = JoinPaths(sFileRoot, sPath);
    }

    // Check cache first
    CacheKey cacheKey = GenerateCacheKey(sFullPath);
    if(GetFilesystemCache().ContainsKey(cacheKey))
    {
        String sFileContents;
        if(GetFilesystemCache().GetValue(cacheKey, sFileContents))
        {
            vBytes.clear();
            vBytes.resize(sFileContents.size());
            vBytes.assign(sFileContents.begin(), sFileContents.end());
            return true;
        }
    }

    // Check if path exists
    if(!DoesPathExist(sFullPath))
    {
        return false;
    }

    // Open file
    InputFile inputFile(sFullPath.c_str(), STDIOSFlagInputOperations | STDIOSFlagBinaryMode);
    if(!inputFile.is_open() && inputFile.good())
    {
        return false;
    }

    // Read bytes
    SizeType uSize = GetFileSize(sFullPath);
    vBytes.clear();
    vBytes.resize(uSize);
    inputFile.read(reinterpret_cast<char*>(vBytes.data()), uSize);

    // Cleanup
    inputFile.close();
    GetFilesystemCache().SetValue(cacheKey, String(vBytes.begin(), vBytes.end()));
    return true;
}

Bool FileManager::WriteStringToFile(const String& sPath, const String& sString, const String& sFileRoot /*= ""*/)
{
    // Get full path
    String sFullPath = sPath;
    if(IsRelativePath(sPath))
    {
        sFullPath = JoinPaths(sFileRoot, sPath);
    }

    // Create parent dirs
    CreateNewDirectories(GetParentPath(sFullPath));

    // Open file
    OutputFile outputFile(sFullPath.c_str(), STDIOSFlagOutputOperations | STDIOSFlagBinaryMode | STDIOSFlagTruncate);
    if(!outputFile.is_open() && outputFile.good())
    {
        return false;
    }

    // Write string
    outputFile << sString;

    // Cleanup
    outputFile.close();

    // Check file
    return DoesPathExist(sFullPath);
}

Bool FileManager::WriteByteArrayToFile(const String& sPath, const FixedUnsigned8Array& vBytes, const String& sFileRoot /*= ""*/)
{
    // Get full path
    String sFullPath = sPath;
    if(IsRelativePath(sPath))
    {
        sFullPath = JoinPaths(sFileRoot, sPath);
    }

    // Open file
    OutputFile outputFile(sFullPath.c_str(), STDIOSFlagOutputOperations | STDIOSFlagBinaryMode | STDIOSFlagTruncate);
    if(!outputFile.is_open() && outputFile.good())
    {
        return false;
    }

    // Write bytes
    SizeType szLength = vBytes.size() * sizeof(FixedUnsigned8);
    for(SizeType index = 0; index < szLength; index++)
    {
        Byte byte = vBytes[index];
        outputFile.write(&byte, sizeof(Byte));
    }

    // Cleanup
    outputFile.close();

    // Check file
    return DoesPathExist(sFullPath);
}

String FileManager::GetProgramDirectory()
{
    // Check cache first
    if(GetFilesystemCache().ContainsKey(CACHE_KEY_PROGRAM_DIRECTORY))
    {
        String sProgramDirectory;
        if(GetFilesystemCache().GetValue(CACHE_KEY_PROGRAM_DIRECTORY, sProgramDirectory))
        {
            return sProgramDirectory;
        }
    }

    // Calculate program directory
    // The loop is to make sure we have the right string size
    BoostFilesystemPath sFullPath;
#if defined(PLATFORM_OS_WINDOWS)
    WByteArray vBuffer;
#else
    ByteArray vBuffer;
#endif
    ULong uLength = 0;
    do
    {
        vBuffer.resize(vBuffer.size() + DEFAULT_MAX_PATH_SIZE);
#if defined(PLATFORM_OS_LINUX)
        auto iSize = ::readlink("/proc/self/exe", vBuffer.data(), vBuffer.size());
        if(iSize == -1)
        {
            uLength = 0;
            break;
        }
        uLength = static_cast<ULong>(iSize);
#elif defined(PLATFORM_OS_WINDOWS)
        uLength = GetModuleFileName(NULL, vBuffer.data(), static_cast<DWORD>(vBuffer.size()));
#else
        uLength = 0;
        break;
#endif
    }
    while(uLength >= vBuffer.size());
    vBuffer.resize(uLength);
#if defined(PLATFORM_OS_WINDOWS)
    sFullPath = WString(vBuffer.begin(), vBuffer.end());
#else
    sFullPath = String(vBuffer.begin(), vBuffer.end());
#endif
    sFullPath.remove_filename();

    // Get absolute path
    sFullPath = BoostFilesystemCanonical(sFullPath);

    // Return program directory
    GetFilesystemCache().SetValue(CACHE_KEY_PROGRAM_DIRECTORY, sFullPath.string());
    return sFullPath.string();
}

String FileManager::GetRootDirectory()
{
    // Get root directory
    return GetParentPath(GetProgramDirectory());
}

String FileManager::GetBinDirectory()
{
    // Get bin directory
    return JoinPaths(GetRootDirectory(), FOLDER_BIN);
}

String FileManager::GetDataDirectory()
{
    // Get data directory
    return JoinPaths(GetRootDirectory(), FOLDER_DATA);
}

String FileManager::GetDataLogsDirectory()
{
    // Get log directory
    return JoinPaths(GetRootDirectory(), FOLDER_DATA_LOGS);
}

String FileManager::GetDataSavesDirectory()
{
    // Get saves directory
    return JoinPaths(GetRootDirectory(), FOLDER_DATA_SAVES);
}

String FileManager::GetDataCharactersDirectory()
{
    // Get characters directory
    return JoinPaths(GetRootDirectory(), FOLDER_DATA_CHARACTERS);
}

String FileManager::GetDataGeneratorsDirectory()
{
    // Get character generators directory
    return JoinPaths(GetRootDirectory(), FOLDER_DATA_GENERATORS);
}

String FileManager::GetDataPartiesDirectory()
{
    // Get character parties directory
    return JoinPaths(GetRootDirectory(), FOLDER_DATA_PARTIES);
}

String FileManager::GetDataLibsDirectory()
{
    // Get libs directory
    return JoinPaths(GetRootDirectory(), FOLDER_DATA_LIBS);
}

String FileManager::GetDataLibsMainDirectory()
{
    // Get main libs directory
    return JoinPaths(GetRootDirectory(), FOLDER_DATA_LIBS_MAIN);
}

String FileManager::GetDataLibsThirdPartyDirectory()
{
    // Get third party libs directory
    return JoinPaths(GetRootDirectory(), FOLDER_DATA_LIBS_THIRDPARTY);
}

String FileManager::GetDataTreesItemsDirectory()
{
    // Get items directory
    return JoinPaths(GetRootDirectory(), FOLDER_DATA_TREES_ITEMS);
}

String FileManager::GetDataTreesSkillsDirectory()
{
    // Get skills directory
    return JoinPaths(GetRootDirectory(), FOLDER_DATA_TREES_SKILLS);
}

String FileManager::GetLogFile()
{
    // Check cache first
    if(GetFilesystemCache().ContainsKey(CACHE_KEY_LOG_FILE))
    {
        String sLogFile;
        if(GetFilesystemCache().GetValue(CACHE_KEY_LOG_FILE, sLogFile))
        {
            return sLogFile;
        }
    }

    // Store log file time for the process
    static TimeType uTime = STDTime(nullptr);

    // Create log filename
    String sLogFile = "Log_";
#if DEBUG
    sLogFile += "Debug_";
#else
    sLogFile += "Release_";
#endif
    sLogFile += GetFormattedTimestamp(uTime, "%Y%m%d-%OH%OM%OS");
    sLogFile += ".txt";

    // Return log file
    GetFilesystemCache().SetValue(CACHE_KEY_LOG_FILE, sLogFile);
    return sLogFile;
}

String FileManager::GetSceneStyleFile(const String& sSceneID)
{
    // Get scene style file
    String sFile;
    sFile = JoinPaths(sFile, GetDataLibsMainDirectory());
    sFile = JoinPaths(sFile, "Scene");
    sFile = JoinPaths(sFile, "Scene" + sSceneID);
    sFile = JoinPaths(sFile, "Scene" + sSceneID + ".css");
    return sFile;
}

String FileManager::GetSceneScriptFile(const String& sSceneID)
{
    // Get scene script file
    String sFile;
    sFile = JoinPaths(sFile, GetDataLibsMainDirectory());
    sFile = JoinPaths(sFile, "Scene");
    sFile = JoinPaths(sFile, "Scene" + sSceneID);
    sFile = JoinPaths(sFile, "Scene" + sSceneID + ".js");
    return sFile;
}

String FileManager::GetScenePageFile(const String& sSceneID)
{
    // Get scene page file
    String sFile;
    sFile = JoinPaths(sFile, GetDataLibsMainDirectory());
    sFile = JoinPaths(sFile, "Scene");
    sFile = JoinPaths(sFile, "Scene" + sSceneID);
    sFile = JoinPaths(sFile, "Scene" + sSceneID + ".html");
    return sFile;
}

};
