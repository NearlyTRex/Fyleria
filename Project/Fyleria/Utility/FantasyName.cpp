// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "Utility/FantasyName.h"

namespace Gecko
{

String GenerateRandomFantasyName(const String& sPattern)
{
    FantasyNameGenerator generator(sPattern);
    return generator.toString();
}

IndexedString GetRandomNamePattern()
{
    static const IndexedStringVector vNamePatterns = {
        GetMiddleEarthNamePattern(),
        GetJapaneseNameConstrainedPattern(),
        GetJapaneseNameDiversePattern(),
        GetChineseNamePattern(),
        GetGreekNamePattern(),
        GetHawaiianName1Pattern(),
        GetHawaiianName2Pattern(),
        GetOldLatinPlaceNamePattern(),
        GetDragonPernNamePattern(),
        GetDragonRiderNamePattern(),
        GetPokemonNamePattern(),
        GetFantasySANamePattern(),
        GetFantasyHLNamePattern(),
        GetFantasyNLNamePattern(),
        GetFantasyKNNamePattern(),
        GetFantasyJGZNamePattern(),
        GetFantasyKJYNamePattern(),
        GetFantasySENamePattern()
    };
    return GetRandomVectorValue<IndexedString>(vNamePatterns);
}

IndexedString GetCapitalizationToken() { return IndexedString("!"); }
IndexedString GetReverseToken() { return IndexedString("~"); }
IndexedString GetMiddleEarthNamePattern() { return IndexedString(MIDDLE_EARTH); }
IndexedString GetJapaneseNameConstrainedPattern() { return IndexedString(JAPANESE_NAMES_CONSTRAINED); }
IndexedString GetJapaneseNameDiversePattern() { return IndexedString(JAPANESE_NAMES_DIVERSE); }
IndexedString GetChineseNamePattern() { return IndexedString(CHINESE_NAMES); }
IndexedString GetGreekNamePattern() { return IndexedString(GREEK_NAMES); }
IndexedString GetHawaiianName1Pattern() { return IndexedString(HAWAIIAN_NAMES_1); }
IndexedString GetHawaiianName2Pattern() { return IndexedString(HAWAIIAN_NAMES_2); }
IndexedString GetOldLatinPlaceNamePattern() { return IndexedString(OLD_LATIN_PLACE_NAMES); }
IndexedString GetDragonPernNamePattern() { return IndexedString(DRAGONS_PERN); }
IndexedString GetDragonRiderNamePattern() { return IndexedString(DRAGON_RIDERS); }
IndexedString GetPokemonNamePattern() { return IndexedString(POKEMON); }
IndexedString GetFantasyVowelsRNamePattern() { return IndexedString(FANTASY_VOWELS_R); }
IndexedString GetFantasySANamePattern() { return IndexedString(FANTASY_S_A); }
IndexedString GetFantasyHLNamePattern() { return IndexedString(FANTASY_H_L); }
IndexedString GetFantasyNLNamePattern() { return IndexedString(FANTASY_N_L); }
IndexedString GetFantasyKNNamePattern() { return IndexedString(FANTASY_K_N); }
IndexedString GetFantasyJGZNamePattern() { return IndexedString(FANTASY_J_G_Z); }
IndexedString GetFantasyKJYNamePattern() { return IndexedString(FANTASY_K_J_Y); }
IndexedString GetFantasySENamePattern() { return IndexedString(FANTASY_S_E); }

};
