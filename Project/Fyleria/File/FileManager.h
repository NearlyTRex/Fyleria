// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_FILE_FILE_MANAGER_H_
#define _GECKO_FILE_FILE_MANAGER_H_

// Internal includes
#include "Cache/BasicCache.h"
#include "Cache/TimedCache.h"

namespace Gecko
{

// File manager
class FileManager
{
public:

    // Constructors
    FileManager();

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

    // Is path absolute
    Bool IsAbsolutePath(const String& sPath);

    // Is path relative
    Bool IsRelativePath(const String& sPath);

    // Create temp directory
    Bool CreateTempDirectory(String& sPath);

    // Create temp file
    Bool CreateTempFile(String& sPath, const String& sContents = "");

    // Create new directory
    Bool CreateNewDirectory(const String& sPath);

    // Create new directories
    Bool CreateNewDirectories(const String& sPath);

    // Remove directory and all files
    Bool RemoveDirectoryAndFiles(const String& sPath);

    // Remove file
    Bool RemoveFile(const String& sPath);

    // Get file size in bytes
    SizeType GetFileSize(const String& sPath);

    // Get parent path
    String GetParentPath(const String& sPath);

    // Get absolute path
    String GetAbsolutePath(const String& sPath);

    // Get canonical path
    String GetCanonicalPath(const String& sPath);

    // Get uri path
    String GetUriPath(const String& sPath, const String& sFileRoot = "");

    // Join paths together
    String JoinPaths(const String& sPath1, const String& sPath2);

    // Join paths together and get canonical result
    String JoinPathsCanonical(const String& sPath1, const String& sPath2);

    // Read file to string
    Bool ReadFileToString(const String& sPath, String& sString, const String& sFileRoot = "");

    // Read file to byte array
    Bool ReadFileToByteArray(const String& sPath, FixedUnsigned8Array& vBytes, const String& sFileRoot = "");

    // Write string to file
    Bool WriteStringToFile(const String& sPath, const String& sString, const String& sFileRoot = "");

    // Write byte array to file
    Bool WriteByteArrayToFile(const String& sPath, const FixedUnsigned8Array& vBytes, const String& sFileRoot = "");

    // Get program directory
    String GetProgramDirectory();

    // Get root directory
    String GetRootDirectory();

    // Get bin directory
    String GetBinDirectory();

    // Get data directories
    String GetDataDirectory();
    String GetDataLogsDirectory();
    String GetDataSavesDirectory();
    String GetDataCharactersDirectory();
    String GetDataGeneratorsDirectory();
    String GetDataPartiesDirectory();
    String GetDataLibsDirectory();
    String GetDataLibsMainDirectory();
    String GetDataLibsThirdPartyDirectory();
    String GetDataTreesItemsDirectory();
    String GetDataTreesSkillsDirectory();

    // Get log file
    String GetLogFile();

    // Get scene files
    String GetSceneStyleFile(const String& sSceneID);
    String GetSceneScriptFile(const String& sSceneID);
    String GetScenePageFile(const String& sSceneID);

    // File reader cache
    MAKE_RAW_TYPE_ACCESSORS(FileReaderCache, TimedCache);

    // Filesystem cache
    MAKE_RAW_TYPE_ACCESSORS(FilesystemCache, BasicCache);
};

};

#endif
