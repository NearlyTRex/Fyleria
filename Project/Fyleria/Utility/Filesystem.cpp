// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "Utility/Filesystem.h"

namespace Gecko
{

Bool DoesPathExist(const String& sPath)
{
    return false;
}

Bool IsFile(const String& sPath)
{
    return false;
}

Bool IsDirectory(const String& sPath)
{
    return false;
}

Bool IsSymbolicLink(const String& sPath)
{
    return false;
}

StringArray GetListOfFiles(const String& sPath)
{
    return StringArray();
}

Bool CreateDirectory(const String& sPath)
{
    return false;
}

Bool RemoveDirectory(const String& sPath)
{
    return false;
}

void RemoveFile(const String& sPath)
{
}

SizeType GetFileSize(const String& sPath)
{
    return 0;
}

String JoinPaths(const String& sPath1, const String& sPath2)
{
    return String();
}

};
