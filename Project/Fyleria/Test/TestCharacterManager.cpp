// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Character/CharacterManager.h"
#include "Utility/Enum.h"
#include "TestFixture/TestFixtureAppLoaded.h"
#include "TestSample/TestSamples.h"

// External includes
#include <boost/test/unit_test.hpp>

// CharacterManagement
BOOST_AUTO_TEST_SUITE(CharacterManager)

// Create empty character
BOOST_FIXTURE_TEST_CASE(CreateEmptyCharacter, Gecko::TestFixtureAppLoaded)
{
    Gecko::String sCharID = "EmptyCharacter";
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterManager()->CreateCharacter(sCharID));
}

// Create empty character from invalid character ID
BOOST_FIXTURE_TEST_CASE(CreateEmptyCharacterFromInvalidCharID, Gecko::TestFixtureAppLoaded)
{
    Gecko::String sInvalidCharID = "";
    BOOST_CHECK_EQUAL(Gecko::GetManagers()->GetCharacterManager()->CreateCharacter(sInvalidCharID), false);
}

// Load character from json
BOOST_FIXTURE_TEST_CASE(LoadCharacterFromJson, Gecko::TestFixtureAppLoaded)
{
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterManager()->LoadCharacter(Gecko::Character(Gecko::EMPTY_CHARACTER_JSON), false));
}

// Load character from invalid json
BOOST_FIXTURE_TEST_CASE(LoadCharacterFromInvalidJson, Gecko::TestFixtureAppLoaded)
{
    BOOST_CHECK_THROW(Gecko::GetManagers()->GetCharacterManager()->LoadCharacter(Gecko::Character(Gecko::INVALID_CHARACTER_JSON), false), STDException);
}

// Load character from file
BOOST_FIXTURE_TEST_CASE(LoadCharacterFromFile, Gecko::TestFixtureAppLoaded)
{
    Gecko::String sCharID = "EmptyCharacter";
    Gecko::String sCharFile;
    Gecko::String sCharFileType = GetEnumString(Gecko::FileType::TextJson);
    BOOST_CHECK(Gecko::GetManagers()->GetFileManager()->CreateTempFile(sCharFile));
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterManager()->LoadCharacter(Gecko::Character(Gecko::EMPTY_CHARACTER_JSON), false));
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterManager()->SaveCharacterToFile(sCharID, sCharFile, sCharFileType));
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterManager()->UnloadCharacter(sCharID));
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterManager()->LoadCharacterFromFile(sCharFile, sCharFileType, false));
}

// Load character from invalid file
BOOST_FIXTURE_TEST_CASE(LoadCharacterFromInvalidFile, Gecko::TestFixtureAppLoaded)
{
    Gecko::String sCharFile = "invalidfile.json";
    Gecko::String sCharFileType = GetEnumString(Gecko::FileType::TextJson);
    BOOST_CHECK_EQUAL(Gecko::GetManagers()->GetCharacterManager()->LoadCharacterFromFile(sCharFile, sCharFileType, false), false);
}

// Save character to file
BOOST_FIXTURE_TEST_CASE(SaveCharacterToFile, Gecko::TestFixtureAppLoaded)
{
    Gecko::String sCharID = "EmptyCharacter";
    Gecko::String sCharFile;
    Gecko::String sCharFileType = GetEnumString(Gecko::FileType::TextJson);
    BOOST_CHECK(Gecko::GetManagers()->GetFileManager()->CreateTempFile(sCharFile));
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterManager()->CreateCharacter(sCharID));
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterManager()->SaveCharacterToFile(sCharID, sCharFile, sCharFileType));
}

// Unload character
BOOST_FIXTURE_TEST_CASE(UnloadCharacter, Gecko::TestFixtureAppLoaded)
{
    Gecko::String sCharID = "EmptyCharacter";
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterManager()->LoadCharacter(Gecko::Character(Gecko::EMPTY_CHARACTER_JSON), false));
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterManager()->UnloadCharacter(sCharID));
}

// Load multiple characters
BOOST_FIXTURE_TEST_CASE(LoadMultipleCharacters, Gecko::TestFixtureAppLoaded)
{
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterManager()->LoadCharacter(Gecko::Character(Gecko::RANDOM_CHARACTER_1_JSON), false));
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterManager()->LoadCharacter(Gecko::Character(Gecko::RANDOM_CHARACTER_2_JSON), false));
}

// Get invalid character
BOOST_FIXTURE_TEST_CASE(GetInvalidCharacter, Gecko::TestFixtureAppLoaded)
{
    Gecko::String sInvalidCharID = "InvalidCharacter";
    BOOST_CHECK_THROW(Gecko::GetManagers()->GetCharacterManager()->GetCharacter(sInvalidCharID), Gecko::GeneralError);
}

// Create empty character generator
BOOST_FIXTURE_TEST_CASE(CreateEmptyCharacterGenerator, Gecko::TestFixtureAppLoaded)
{
    Gecko::String sGeneratorFile;
    Gecko::String sGeneratorFileType = GetEnumString(Gecko::FileType::TextJson);
    Gecko::CharacterGenerator generator;
    BOOST_CHECK(Gecko::GetManagers()->GetFileManager()->CreateTempFile(sGeneratorFile));
    BOOST_CHECK(generator.SaveToFile(sGeneratorFile, sGeneratorFileType));
}

// Create randomized character generator
BOOST_FIXTURE_TEST_CASE(CreateRandomizedCharacterGenerator, Gecko::TestFixtureAppLoaded)
{
    Gecko::String sGeneratorFile;
    Gecko::String sGeneratorFileType = GetEnumString(Gecko::FileType::TextJson);
    Gecko::CharacterGenerator generator;
    BOOST_CHECK(Gecko::GetManagers()->GetFileManager()->CreateTempFile(sGeneratorFile));
    generator.RandomizeAll();
    BOOST_CHECK(generator.SaveToFile(sGeneratorFile, sGeneratorFileType));
}

// Generate character from generator json
BOOST_FIXTURE_TEST_CASE(GenerateCharacterFromGeneratorJson, Gecko::TestFixtureAppLoaded)
{
    Gecko::String sCharID = "GeneratedCharacter";
    Gecko::String sCharFile;
    Gecko::String sCharFileType = GetEnumString(Gecko::FileType::TextJson);
    Gecko::CharacterGenerator generator(Gecko::CHARACTER_GENERATOR_RANDOM_JSON);
    BOOST_CHECK(Gecko::GetManagers()->GetFileManager()->CreateTempFile(sCharFile));
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterManager()->GenerateCharacter(sCharID, generator, true));
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterManager()->SaveCharacterToFile(sCharID, sCharFile, sCharFileType));
}

// Generate completely random character
BOOST_FIXTURE_TEST_CASE(GenerateCompletelyRandomCharacter, Gecko::TestFixtureAppLoaded)
{
    Gecko::String sCharID = "RandomCharacter";
    Gecko::String sCharFile;
    Gecko::String sCharFileType = GetEnumString(Gecko::FileType::TextJson);
    Gecko::CharacterGenerator generator;
    BOOST_CHECK(Gecko::GetManagers()->GetFileManager()->CreateTempFile(sCharFile));
    generator.RandomizeAll();
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterManager()->GenerateCharacter(sCharID, generator, true));
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterManager()->SaveCharacterToFile(sCharID, sCharFile, sCharFileType));
}

// Regenerate character data
BOOST_FIXTURE_TEST_CASE(RegenerateCharacterData, Gecko::TestFixtureAppLoaded)
{
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterManager()->LoadCharacter(Gecko::Character(Gecko::EMPTY_CHARACTER_JSON), true));
}

BOOST_AUTO_TEST_SUITE_END()
