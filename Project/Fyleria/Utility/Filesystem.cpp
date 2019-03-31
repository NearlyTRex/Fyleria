// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "Utility/Filesystem.h"

namespace Gecko
{

Bool DoesFileExist(const String& sPath)
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

String operator/(const String& path1, const String& path2)
{
    return String();
}

};
