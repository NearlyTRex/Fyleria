// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_UTILITY_BOOST_H_
#define _GECKO_UTILITY_BOOST_H_

// External includes
#include <boost/any.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <boost/filesystem.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/program_options.hpp>

// External function defines
#define BoostAnyCast boost::any_cast
#define BoostLexicalCast boost::lexical_cast
#define BoostFormatString boost::format
#define BoostFilesystemExists boost::filesystem::exists
#define BoostFilesystemCanonical boost::filesystem::canonical
#define BoostFilesystemFileSize boost::filesystem::file_size
#define BoostFilesystemIsDirectory boost::filesystem::is_directory
#define BoostFilesystemIsFile boost::filesystem::is_regular_file
#define BoostFilesystemIsSymbolicLink boost::filesystem::is_symlink
#define BoostFilesystemCreateDirectory boost::filesystem::create_directory
#define BoostFilesystemRemove boost::filesystem::remove
#define BoostFilesystemRemoveAll boost::filesystem::remove_all

// External type defines
#define BoostAny boost::any
#define BoostFunction boost::function
#define BoostBind boost::bind
#define BoostFilesystemPath boost::filesystem::path

// External exception defines
#define BoostBadAnyCast boost::bad_any_cast
#define BoostBadLexicalCast boost::bad_lexical_cast

#endif
