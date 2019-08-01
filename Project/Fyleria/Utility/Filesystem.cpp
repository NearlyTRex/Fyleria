// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Utility/Filesystem.h"
#include "Utility/Constants.h"

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

Bool CreateDirectory(const String& sPath)
{
    return BoostFilesystemCreateDirectory(BoostFilesystemPath(sPath));
}

Bool RemoveDirectory(const String& sPath)
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

String JoinPaths(const String& sPath1, const String& sPath2)
{
    return (BoostFilesystemPath(sPath1) / BoostFilesystemPath(sPath2)).string();
}

String JoinPathsCanonical(const String& sPath1, const String& sPath2)
{
    return GetCanonicalPath(JoinPaths(sPath1, sPath2));
}

String GetFileContents(const String& sPath)
{
    InputFile inputFile(sPath, STDInputFileStreamFlagInput | STDInputFileStreamFlagBinary);
    StringStream sBuffer;
    sBuffer << inputFile.rdbuf();
    return sBuffer.str();
}

String GetProgramDirectory()
{
    BoostFilesystemPath sFullPath;
#if defined(PLATFORM_OS_LINUX)
    STDVector<Byte> vBuffer;
#elif defined(PLATFORM_OS_WINDOWS)
    STDVector<WByte> vBuffer;
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
#endif
    }
    while(uLength >= vBuffer.size());
    vBuffer.resize(uLength);
#if defined(PLATFORM_OS_LINUX)
    sFullPath = String(vBuffer.begin(), vBuffer.end());
#elif defined(PLATFORM_OS_WINDOWS)
    sFullPath = WString(vBuffer.begin(), vBuffer.end());
#endif
    sFullPath.remove_filename();
    return GetAbsolutePath(sFullPath.string());
}

String GetDataDirectory()
{
    return JoinPaths(GetProgramDirectory(), FOLDER_DATA);
}

String GetSaveDirectory()
{
    return JoinPaths(GetProgramDirectory(), FOLDER_SAVE);
}

};
