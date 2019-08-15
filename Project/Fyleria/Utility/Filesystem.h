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

// Is path on a posix filesystem
Bool IsPosixPath(const String& sPath);

// Is path on a windows filesystem
Bool IsWindowsPath(const String& sPath);

// Is path on a windows network drive
Bool IsWindowsNetworkDriveLocation(const String& sPath);

// Create new directory
Bool CreateNewDirectory(const String& sPath);

// Remove directory and all files
Bool RemoveDirectoryAndFiles(const String& sPath);

// Remove file
Bool RemoveFile(const String& sPath);

// Get file size in bytes
SizeType GetFileSize(const String& sPath);

// Get absolute path
String GetAbsolutePath(const String& sPath);

// Get canonical path
String GetCanonicalPath(const String& sPath);

// Get uri path
String GetUriPath(const String& sPath, const String& sFileRoot);

// Join paths together
String JoinPaths(const String& sPath1, const String& sPath2);

// Join paths together and get canonical result
String JoinPathsCanonical(const String& sPath1, const String& sPath2);

// Read file to string
Bool ReadFileToString(const String& sPath, String& sString, const String& sFileRoot);

// Read file to byte array
Bool ReadFileToByteArray(const String& sPath, FixedUnsigned8Array& vBytes, const String& sFileRoot);

// Write string to file
Bool WriteStringToFile(const String& sPath, const String& sString, const String& sFileRoot);

// Write byte array to file
Bool WriteByteArrayToFile(const String& sPath, const FixedUnsigned8Array& vBytes, const String& sFileRoot);

// Get program directory
String GetProgramDirectory();

// Get data directories
String GetDataDirectory();
String GetDataCharactersDirectory();
String GetDataIconsDirectory();
String GetDataItemsDirectory();
String GetDataLibsDirectory();
String GetDataPagesDirectory();
String GetDataPartiesDirectory();
String GetDataPortraitsDirectory();
String GetDataSkillsDirectory();

// Get save directory
String GetSaveDirectory();

// Get log directory
String GetLogDirectory();

// Get log file
String GetLogFile();

};

#endif
