// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_UTILITY_FILESYSTEM_H_
#define _GECKO_UTILITY_FILESYSTEM_H_

// Internal includes
#include "Utility/Types.h"

namespace Gecko
{

// Does path exist
Bool DoesPathExist(const String& sPath);

// Is path a file
Bool IsFile(const String& sPath);

// Is path a directory
Bool IsDirectory(const String& sPath);

// Is path a symbolic link
Bool IsSymbolicLink(const String& sPath);

// Create directory
Bool CreateDirectory(const String& sPath);

// Remove directory
Bool RemoveDirectory(const String& sPath);

// Remove file
Bool RemoveFile(const String& sPath);

// Get file size in bytes
SizeType GetFileSize(const String& sPath);

// Get absolute path
String GetAbsolutePath(const String& sPath);

// Get canonical path
String GetCanonicalPath(const String& sPath);

// Join paths together
String JoinPaths(const String& sPath1, const String& sPath2);

// Get file contents
String GetFileContents(const String& sPath);

};

#endif
