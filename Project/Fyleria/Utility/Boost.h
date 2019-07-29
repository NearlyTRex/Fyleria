// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_UTILITY_BOOST_H_
#define _GECKO_UTILITY_BOOST_H_

// External includes
#include <boost/any.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <boost/filesystem.hpp>
#include <boost/function.hpp>
#include <boost/stacktrace.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/program_options.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/replace.hpp>

// External function defines
#define BoostAnyCast boost::any_cast
#define BoostLexicalCast boost::lexical_cast
#define BoostFormatString boost::format
#define BoostFilesystemExists boost::filesystem::exists
#define BoostFilesystemAbsolute boost::filesystem::absolute
#define BoostFilesystemCanonical boost::filesystem::canonical
#define BoostFilesystemFileSize boost::filesystem::file_size
#define BoostFilesystemIsDirectory boost::filesystem::is_directory
#define BoostFilesystemIsFile boost::filesystem::is_regular_file
#define BoostFilesystemIsSymbolicLink boost::filesystem::is_symlink
#define BoostFilesystemCreateDirectory boost::filesystem::create_directory
#define BoostFilesystemRemove boost::filesystem::remove
#define BoostFilesystemRemoveAll boost::filesystem::remove_all
#define BoostProgramOptionsStore boost::program_options::store
#define BoostProgramOptionsNotify boost::program_options::notify
#define BoostProgramOptionsParseCommandLine boost::program_options::parse_command_line
#define BoostReplaceAll boost::replace_all
#define BoostReplaceAllCopy boost::replace_all_copy

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
