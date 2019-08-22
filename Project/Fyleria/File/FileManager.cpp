// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Utility/FileManager.h"
#include "Utility/Constants.h"
#include "Utility/Converters.h"

namespace Gecko
{

FileManager::FileManager()
{
    GetTimedCache().Initialize(CACHE_FILE_SYSTEM_TIMED_ID, CACHE_FILE_SYSTEM_TIMED_CAPACITY, CACHE_FILE_SYSTEM_TIMED_TTL);
    GetBasicCache().Initialize(CACHE_FILE_SYSTEM_BASIC_ID, CACHE_FILE_SYSTEM_BASIC_CAPACITY);
}

Bool FileManager::DoesPathExist(const String& sPath)
{
    return BoostFilesystemExists(BoostFilesystemPath(sPath));
}

Bool FileManager::IsFile(const String& sPath)
{
    return BoostFilesystemIsFile(BoostFilesystemPath(sPath));
}

Bool FileManager::IsDirectory(const String& sPath)
{
    return BoostFilesystemIsDirectory(BoostFilesystemPath(sPath));
}

Bool FileManager::IsSymbolicLink(const String& sPath)
{
    return BoostFilesystemIsSymbolicLink(BoostFilesystemPath(sPath));
}

Bool FileManager::IsPosixPath(const String& sPath)
{
    return (sPath.at(0) == '/');
}

Bool FileManager::IsWindowsPath(const String& sPath)
{
    return (isalpha(sPath.at(0)) != 0) && (sPath.at(1) == ':');
}

Bool FileManager::IsWindowsNetworkDriveLocation(const String& sPath)
{
    return (sPath.at(0) == '\\') && (sPath.at(1) == '\\');
}

Bool FileManager::CreateNewDirectory(const String& sPath)
{
    return BoostFilesystemCreateDirectory(BoostFilesystemPath(sPath));
}

Bool FileManager::RemoveDirectoryAndFiles(const String& sPath)
{
    return BoostFilesystemRemoveAll(BoostFilesystemPath(sPath)) > 0;
}

Bool FileManager::RemoveFile(const String& sPath)
{
    return BoostFilesystemRemove(BoostFilesystemPath(sPath));
}

SizeType FileManager::GetFileSize(const String& sPath)
{
    return static_cast<SizeType>(BoostFilesystemFileSize(BoostFilesystemPath(sPath)));
}

String FileManager::GetAbsolutePath(const String& sPath)
{
    return BoostFilesystemAbsolute(BoostFilesystemPath(sPath)).string();
}

String FileManager::GetCanonicalPath(const String& sPath)
{
    return BoostFilesystemCanonical(BoostFilesystemPath(sPath)).string();
}

String FileManager::GetUriPath(const String& sPath, const String& sFileRoot)
{
    const String sActualPath = JoinPaths(sFileRoot, sPath);
    const UByteArray vIgnoreChars = {'/', ':', '-', '_', '~', '.'};
#if defined(PLATFORM_OS_WINDOWS)
    const String sPrefix = IsWindowsNetworkDriveLocation(sActualPath) ? "file:" : "file:///";
#else
    const String sPrefix = FILE_URI_BASE;
#endif
    String sLocation = ConvertToUrlEncodedString(BoostReplaceAllCopy(sActualPath, "\\", "/"), vIgnoreChars);
    return sPrefix + sLocation;
}

String FileManager::JoinPaths(const String& sPath1, const String& sPath2)
{
    return (BoostFilesystemPath(sPath1) / BoostFilesystemPath(sPath2)).string();
}

String FileManager::JoinPathsCanonical(const String& sPath1, const String& sPath2)
{
    return GetCanonicalPath(JoinPaths(sPath1, sPath2));
}

Bool FileManager::ReadFileToString(const String& sPath, String& sString, const String& sFileRoot)
{
    // Get actual path
    const String sActualPath = JoinPaths(sFileRoot, sPath);
    if(!DoesPathExist(sActualPath))
    {
        return false;
    }

    // Open file
    InputFile inputFile(sActualPath.c_str(), STDIOSFlagInputOperations | STDIOSFlagBinaryMode);
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
    return true;
}

Bool FileManager::ReadFileToByteArray(const String& sPath, FixedUnsigned8Array& vBytes, const String& sFileRoot)
{
    // Get actual path
    const String sActualPath = JoinPaths(sFileRoot, sPath);
    if(!DoesPathExist(sActualPath))
    {
        return false;
    }

    // Open file
    InputFile inputFile(sActualPath.c_str(), STDIOSFlagInputOperations | STDIOSFlagBinaryMode);
    if(!inputFile.is_open() && inputFile.good())
    {
        return false;
    }

    // Read bytes
    SizeType uSize = GetFileSize(sActualPath);
    vBytes.clear();
    vBytes.resize(uSize);
    inputFile.read(reinterpret_cast<char*>(vBytes.data()), uSize);

    // Cleanup
    inputFile.close();
    return true;
}

Bool FileManager::WriteStringToFile(const String& sPath, const String& sString, const String& sFileRoot)
{
    // Get actual path
    const String sActualPath = JoinPaths(sFileRoot, sPath);

    // Open file
    OutputFile outputFile(sActualPath.c_str(), STDIOSFlagOutputOperations | STDIOSFlagBinaryMode | STDIOSFlagTruncate);
    if(!outputFile.is_open() && outputFile.good())
    {
        return false;
    }

    // Write string
    outputFile << sString;

    // Cleanup
    outputFile.close();
    return true;
}

Bool FileManager::WriteByteArrayToFile(const String& sPath, const FixedUnsigned8Array& vBytes, const String& sFileRoot)
{
    // Get actual path
    const String sActualPath = JoinPaths(sFileRoot, sPath);

    // Open file
    OutputFile outputFile(sActualPath.c_str(), STDIOSFlagOutputOperations | STDIOSFlagBinaryMode | STDIOSFlagTruncate);
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
    return true;
}

String FileManager::GetProgramDirectory()
{
    if(GetBasicCache().ContainsKey(CACHE_KEY_PROGRAM_DIRECTORY))
    {
        String sProgramDirectory;
        if(GetBasicCache().GetValue(CACHE_KEY_PROGRAM_DIRECTORY, sProgramDirectory))
        {
            return sProgramDirectory;
        }
    }

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

    String sProgramDirectory = GetAbsolutePath(sFullPath.string());
    GetBasicCache().SetValue(CACHE_KEY_PROGRAM_DIRECTORY, sProgramDirectory);
    return sProgramDirectory;
}

String FileManager::GetDataDirectory()
{
    return JoinPaths(GetProgramDirectory(), FOLDER_DATA);
}

String FileManager::GetDataCharactersDirectory()
{
    return JoinPaths(GetProgramDirectory(), FOLDER_DATA_CHARACTERS);
}

String FileManager::GetDataIconsDirectory()
{
    return JoinPaths(GetProgramDirectory(), FOLDER_DATA_ICONS);
}

String FileManager::GetDataItemsDirectory()
{
    return JoinPaths(GetProgramDirectory(), FOLDER_DATA_ITEMS);
}

String FileManager::GetDataLibsDirectory()
{
    return JoinPaths(GetProgramDirectory(), FOLDER_DATA_LIBS);
}

String FileManager::GetDataPagesDirectory()
{
    return JoinPaths(GetProgramDirectory(), FOLDER_DATA_PAGES);
}

String FileManager::GetDataPartiesDirectory()
{
    return JoinPaths(GetProgramDirectory(), FOLDER_DATA_PARTIES);
}

String FileManager::GetDataPortraitsDirectory()
{
    return JoinPaths(GetProgramDirectory(), FOLDER_DATA_PORTRAITS);
}

String FileManager::GetDataSkillsDirectory()
{
    return JoinPaths(GetProgramDirectory(), FOLDER_DATA_SKILLS);
}

String FileManager::GetSaveDirectory()
{
    return JoinPaths(GetProgramDirectory(), FOLDER_SAVE);
}

String FileManager::GetLogDirectory()
{
    return JoinPaths(GetProgramDirectory(), FOLDER_LOG);
}

String FileManager::GetLogFile()
{
    static TimeType uTime = STDTime(nullptr);
    String sFilename = "Log_";
#if DEBUG
    sFilename += "Debug_";
#else
    sFilename += "Release_";
#endif
    sFilename += BoostLexicalCast<String>(STDPutTime(STDLocalTime(&uTime), "%Y%m%d-%OH%OM%OS"));
    sFilename += ".txt";
    return sFilename;
}

};
