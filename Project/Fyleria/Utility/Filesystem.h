// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_UTILITY_FILESYSTEM_H_
#define _GECKO_UTILITY_FILESYSTEM_H_

// Internal includes
#include "Utility/Types.h"

namespace Gecko
{

// Does file exist
Bool DoesFileExist(const String& sPath);

// Is path a file
Bool IsFile(const String& sPath);

// Is path a directory
Bool IsDirectory(const String& sPath);

// Is path a symbolic link
Bool IsSymbolicLink(const String& sPath);

// Get list of files
StringArray GetListOfFiles(const String& sPath);

// Create directory
Bool CreateDirectory(const String& sPath);

// Remove directory
Bool RemoveDirectory(const String& sPath);

// Remove file
void RemoveFile(const String& sPath);

// Get file size in bytes
SizeType GetFileSize(const String& sPath);

// Concatenation of paths with dividers
String operator/(const String& path1, const String& path2);

};

#endif
