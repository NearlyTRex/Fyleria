// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Utility/Filesystem.h"

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
    return BoostFilesystemFileSize(BoostFilesystemPath(sPath));
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

};
