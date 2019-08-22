// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Utility/Filesystem.h"
#include "Utility/Constants.h"
#include "Utility/Converters.h"

namespace Gecko
{

Bool DoesPathExist(const String& sPath)
{
    return BoostFilesystemExists(BoostFilesystemPath(sPath));
}

Bool IsFile(const String& sPath)
{
    return BoostFilesystemIsFile(BoostFilesystemPath(sPath));
}

Bool IsDirectory(const String& sPath)
{
    return BoostFilesystemIsDirectory(BoostFilesystemPath(sPath));
}

Bool IsSymbolicLink(const String& sPath)
{
    return BoostFilesystemIsSymbolicLink(BoostFilesystemPath(sPath));
}

Bool IsPosixPath(const String& sPath)
{
    return (sPath.at(0) == '/');
}

Bool IsWindowsPath(const String& sPath)
{
    return (isalpha(sPath.at(0)) != 0) && (sPath.at(1) == ':');
}

Bool IsWindowsNetworkDriveLocation(const String& sPath)
{
    return (sPath.at(0) == '\\') && (sPath.at(1) == '\\');
}

Bool CreateNewDirectory(const String& sPath)
{
    return BoostFilesystemCreateDirectory(BoostFilesystemPath(sPath));
}

Bool RemoveDirectoryAndFiles(const String& sPath)
{
    return BoostFilesystemRemoveAll(BoostFilesystemPath(sPath)) > 0;
}

Bool RemoveFile(const String& sPath)
{
    return BoostFilesystemRemove(BoostFilesystemPath(sPath));
}

SizeType GetFileSize(const String& sPath)
{
    return static_cast<SizeType>(BoostFilesystemFileSize(BoostFilesystemPath(sPath)));
}

String GetAbsolutePath(const String& sPath)
{
    return BoostFilesystemAbsolute(BoostFilesystemPath(sPath)).string();
}

String GetCanonicalPath(const String& sPath)
{
    return BoostFilesystemCanonical(BoostFilesystemPath(sPath)).string();
}

String GetUriPath(const String& sPath, const String& sFileRoot)
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

String JoinPaths(const String& sPath1, const String& sPath2)
{
    return (BoostFilesystemPath(sPath1) / BoostFilesystemPath(sPath2)).string();
}

String JoinPathsCanonical(const String& sPath1, const String& sPath2)
{
    return GetCanonicalPath(JoinPaths(sPath1, sPath2));
}

Bool ReadFileToString(const String& sPath, String& sString, const String& sFileRoot)
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

Bool ReadFileToByteArray(const String& sPath, FixedUnsigned8Array& vBytes, const String& sFileRoot)
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

Bool WriteStringToFile(const String& sPath, const String& sString, const String& sFileRoot)
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

Bool WriteByteArrayToFile(const String& sPath, const FixedUnsigned8Array& vBytes, const String& sFileRoot)
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

String GetProgramDirectory()
{
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
    return GetAbsolutePath(sFullPath.string());
}

String GetDataDirectory()
{
    return JoinPaths(GetProgramDirectory(), FOLDER_DATA);
}

String GetDataCharactersDirectory()
{
    return JoinPaths(GetProgramDirectory(), FOLDER_DATA_CHARACTERS);
}

String GetDataIconsDirectory()
{
    return JoinPaths(GetProgramDirectory(), FOLDER_DATA_ICONS);
}

String GetDataItemsDirectory()
{
    return JoinPaths(GetProgramDirectory(), FOLDER_DATA_ITEMS);
}

String GetDataLibsDirectory()
{
    return JoinPaths(GetProgramDirectory(), FOLDER_DATA_LIBS);
}

String GetDataPagesDirectory()
{
    return JoinPaths(GetProgramDirectory(), FOLDER_DATA_PAGES);
}

String GetDataPartiesDirectory()
{
    return JoinPaths(GetProgramDirectory(), FOLDER_DATA_PARTIES);
}

String GetDataPortraitsDirectory()
{
    return JoinPaths(GetProgramDirectory(), FOLDER_DATA_PORTRAITS);
}

String GetDataSkillsDirectory()
{
    return JoinPaths(GetProgramDirectory(), FOLDER_DATA_SKILLS);
}

String GetSaveDirectory()
{
    return JoinPaths(GetProgramDirectory(), FOLDER_SAVE);
}

String GetLogDirectory()
{
    return JoinPaths(GetProgramDirectory(), FOLDER_LOG);
}

String GetLogFile()
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
