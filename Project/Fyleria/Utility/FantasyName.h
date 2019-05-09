// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_UTILITY_FANTASYNAME_H_
#define _GECKO_UTILITY_FANTASYNAME_H_

// External includes
#include <namegen.h>

// Internal includes
#include "Utility/Types.h"
#include "Utility/IndexedString.h"

namespace Gecko
{
    // FantasyName types
    typedef NameGen::Generator FantasyNameGenerator;

    // Generate a random fantasy name
    String GenerateRandomFantasyName(const String& sPattern);

    // Get random name pattern
    IndexedString GetRandomNamePattern();

    // Tokens
    IndexedString GetCapitalizationToken();
    IndexedString GetReverseToken();

    // Prebuilt patterns
    IndexedString GetMiddleEarthNamePattern();
    IndexedString GetJapaneseNameConstrainedPattern();
    IndexedString GetJapaneseNameDiversePattern();
    IndexedString GetChineseNamePattern();
    IndexedString GetGreekNamePattern();
    IndexedString GetHawaiianName1Pattern();
    IndexedString GetHawaiianName2Pattern();
    IndexedString GetOldLatinPlaceNamePattern();
    IndexedString GetDragonPernNamePattern();
    IndexedString GetDragonRiderNamePattern();
    IndexedString GetPokemonNamePattern();
    IndexedString GetFantasyVowelsRNamePattern();
    IndexedString GetFantasySANamePattern();
    IndexedString GetFantasyHLNamePattern();
    IndexedString GetFantasyNLNamePattern();
    IndexedString GetFantasyKNNamePattern();
    IndexedString GetFantasyJGZNamePattern();
    IndexedString GetFantasyKJYNamePattern();
    IndexedString GetFantasySENamePattern();
};

#endif
