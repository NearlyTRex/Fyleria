// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_UTILITY_BOOST_H_
#define _GECKO_UTILITY_BOOST_H_

// External includes
#include <boost/any.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <boost/filesystem.hpp>
#include <boost/function.hpp>
#include <boost/stacktrace.hpp>
#include <boost/bind/bind.hpp>
#include <boost/thread.hpp>
#include <boost/program_options.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>

// External function defines
#define BoostAnyCast boost::any_cast
#define BoostLexicalCast boost::lexical_cast
#define BoostFormatString boost::format
#define BoostStartsWith boost::starts_with
#define BoostEndsWith boost::ends_with
#define BoostToUpper boost::to_upper
#define BoostToUpperCopy boost::to_upper_copy
#define BoostToLower boost::to_lower
#define BoostToLowerCopy boost::to_lower_copy
#define BoostFilesystemExists boost::filesystem::exists
#define BoostFilesystemCopy boost::filesystem::copy
#define BoostFilesystemCopyDirectory boost::filesystem::copy_directory
#define BoostFilesystemCopyFile boost::filesystem::copy_file
#define BoostFilesystemCopySymlink boost::filesystem::copy_symlink
#define BoostFilesystemAbsolute boost::filesystem::absolute
#define BoostFilesystemCanonical boost::filesystem::canonical
#define BoostFilesystemFileSize boost::filesystem::file_size
#define BoostFilesystemCurrentPath boost::filesystem::current_path
#define BoostFilesystemInitialPath boost::filesystem::initial_path
#define BoostFilesystemIsEmpty boost::filesystem::is_empty
#define BoostFilesystemIsDirectory boost::filesystem::is_directory
#define BoostFilesystemIsFile boost::filesystem::is_regular_file
#define BoostFilesystemIsSymbolicLink boost::filesystem::is_symlink
#define BoostFilesystemCreateDirectories boost::filesystem::create_directories
#define BoostFilesystemCreateDirectory boost::filesystem::create_directory
#define BoostFilesystemCreateDirectorySymlink boost::filesystem::create_directory_symlink
#define BoostFilesystemCreateHardLink boost::filesystem::create_hard_link
#define BoostFilesystemCreateSymlink boost::filesystem::create_symlink
#define BoostFilesystemRemove boost::filesystem::remove
#define BoostFilesystemRemoveAll boost::filesystem::remove_all
#define BoostFilesystemRename boost::filesystem::rename
#define BoostFilesystemTempDirectory boost::filesystem::temp_directory_path
#define BoostFilesystemTempFilename boost::filesystem::unique_path
#define BoostProgramOptionsDescription boost::program_options::options_description
#define BoostProgramOptionsVariablesMap boost::program_options::variables_map
#define BoostProgramOptionsStore boost::program_options::store
#define BoostProgramOptionsNotify boost::program_options::notify
#define BoostProgramOptionsCommandLineParser boost::program_options::command_line_parser
#define BoostProgramOptionsParseCommandLine boost::program_options::parse_command_line
#define BoostReplaceAll boost::algorithm::replace_all
#define BoostReplaceAllCopy boost::algorithm::replace_all_copy
#define BoostJoin boost::algorithm::join

// External type defines
#define BoostAny boost::any
#define BoostFunction boost::function
#define BoostBind boost::bind
#define BoostThread boost::thread
#define BoostFilesystemPath boost::filesystem::path
#define BoostProgramOptionsDescription boost::program_options::options_description
#define BoostProgramOptionsVariablesMap boost::program_options::variables_map
#define BoostProgramOptionsValue boost::program_options::value
#define BoostProgramOptionsBoolSwitch boost::program_options::bool_switch
#define BoostTokenizer boost::tokenizer
#define BoostCharSeparator boost::char_separator
#define BoostStacktrace boost::stacktrace::stacktrace

// External exception defines
#define BoostBadAnyCast boost::bad_any_cast
#define BoostBadLexicalCast boost::bad_lexical_cast

#endif
