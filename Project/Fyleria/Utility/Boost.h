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

// External function defines
#define BoostAnyCast boost::any_cast
#define BoostLexicalCast boost::lexical_cast
#define BoostFormatString boost::format

// External type defines
#define BoostAny boost::any
#define BoostFunction boost::function
#define BoostBind boost::bind
#define BoostFilesystemPath boost::filesystem::path

// External exception defines
#define BoostBadAnyCast boost::bad_any_cast
#define BoostBadLexicalCast boost::bad_lexical_cast

#endif
