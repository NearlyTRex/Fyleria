// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Character/CharacterManager.h"
#include "CharacterParty/CharacterPartyManager.h"
#include "Utility/Enum.h"
#include "TestFixture/TestFixtureAppLoaded.h"
#include "TestSample/TestSamples.h"

// External includes
#include <boost/test/unit_test.hpp>

// CharacterPartyManager
BOOST_AUTO_TEST_SUITE(CharacterPartyManager)

// LoadParty
BOOST_FIXTURE_TEST_CASE(LoadParty, Gecko::TestFixtureAppLoaded)
{
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterPartyManager()->LoadParty(Gecko::CharacterParty(Gecko::EMPTY_ALLY_CHARACTER_PARTY), false));
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterPartyManager()->LoadParty(Gecko::CharacterParty(Gecko::EMPTY_ALLY_CHARACTER_PARTY), true));
}

// LoadPartyFromFile
BOOST_FIXTURE_TEST_CASE(LoadPartyFromFile, Gecko::TestFixtureAppLoaded)
{
    Gecko::String sPartyID = "EmptyParty";
    Gecko::String sPartyType = GetEnumString(Gecko::CharacterPartyType::Ally);
    Gecko::String sPartyFile;
    Gecko::String sPartyFileType = GetEnumString(Gecko::FileType::TextJson);
    BOOST_CHECK(Gecko::GetManagers()->GetFileManager()->CreateTempFile(sPartyFile));
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterPartyManager()->CreateParty(sPartyID, sPartyType, false));
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterPartyManager()->SavePartyToFile(sPartyID, sPartyFile, sPartyFileType));
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterPartyManager()->UnloadParty(sPartyID));
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterPartyManager()->LoadPartyFromFile(sPartyFile, sPartyFileType, false));
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterPartyManager()->UnloadParty(sPartyID));
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterPartyManager()->LoadPartyFromFile(sPartyFile, sPartyFileType, true));
}

// SavePartyToFile
BOOST_FIXTURE_TEST_CASE(SavePartyToFile, Gecko::TestFixtureAppLoaded)
{
    Gecko::String sPartyID = "EmptyParty";
    Gecko::String sPartyType = GetEnumString(Gecko::CharacterPartyType::Ally);
    Gecko::String sPartyFile;
    Gecko::String sPartyFileType = GetEnumString(Gecko::FileType::TextJson);
    BOOST_CHECK(Gecko::GetManagers()->GetFileManager()->CreateTempFile(sPartyFile));
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterPartyManager()->CreateParty(sPartyID, sPartyType, false));
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterPartyManager()->SavePartyToFile(sPartyID, sPartyFile, sPartyFileType));
}

// CreateParty
BOOST_FIXTURE_TEST_CASE(CreateParty, Gecko::TestFixtureAppLoaded)
{
    Gecko::String sPartyID = "EmptyParty";
    Gecko::String sInvalidPartyID = "";
    Gecko::String sPartyType = GetEnumString(Gecko::CharacterPartyType::Ally);
    Gecko::String sInvalidPartyType = GetEnumString(Gecko::CharacterPartyType::Ally);
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterPartyManager()->CreateParty(sPartyID, sPartyType, false));
    BOOST_CHECK_EQUAL(Gecko::GetManagers()->GetCharacterPartyManager()->CreateParty(sInvalidPartyID, sInvalidPartyType, false), false);
}

// UnloadParty
BOOST_FIXTURE_TEST_CASE(UnloadParty, Gecko::TestFixtureAppLoaded)
{
    Gecko::String sAllyPartyID = "AllyParty";
    Gecko::String sEnemyPartyID = "EnemyParty";
    Gecko::String sAllyPartyType = GetEnumString(Gecko::CharacterPartyType::Ally);
    Gecko::String sEnemyPartyType = GetEnumString(Gecko::CharacterPartyType::Enemy);
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterPartyManager()->CreateParty(sAllyPartyID, sAllyPartyType, false));
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterPartyManager()->UnloadParty(sAllyPartyID));
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterPartyManager()->CreateParty(sEnemyPartyID, sEnemyPartyType, false));
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterPartyManager()->UnloadParty(sAllyPartyID));
}

// SetAsCurrentParty
BOOST_FIXTURE_TEST_CASE(SetAsCurrentParty, Gecko::TestFixtureAppLoaded)
{
    Gecko::String sAllyPartyID = "AllyParty";
    Gecko::String sEnemyPartyID = "EnemyParty";
    Gecko::String sAllyPartyType = GetEnumString(Gecko::CharacterPartyType::Ally);
    Gecko::String sEnemyPartyType = GetEnumString(Gecko::CharacterPartyType::Enemy);
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterPartyManager()->CreateParty(sAllyPartyID, sAllyPartyType, false));
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterPartyManager()->CreateParty(sEnemyPartyID, sEnemyPartyType, false));
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterPartyManager()->SetAsCurrentParty(sAllyPartyID, sAllyPartyType));
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterPartyManager()->SetAsCurrentParty(sEnemyPartyID, sEnemyPartyType));
}

// UnloadAllParties
BOOST_FIXTURE_TEST_CASE(UnloadAllParties, Gecko::TestFixtureAppLoaded)
{
    Gecko::String sAllyPartyID = "AllyParty";
    Gecko::String sEnemyPartyID = "EnemyParty";
    Gecko::String sAllyPartyType = GetEnumString(Gecko::CharacterPartyType::Ally);
    Gecko::String sEnemyPartyType = GetEnumString(Gecko::CharacterPartyType::Enemy);
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterPartyManager()->CreateParty(sAllyPartyID, sAllyPartyType, false));
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterPartyManager()->CreateParty(sEnemyPartyID, sEnemyPartyType, false));
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterPartyManager()->UnloadAllParties());
}

// DoesPartyExistByID
BOOST_FIXTURE_TEST_CASE(DoesPartyExistByID, Gecko::TestFixtureAppLoaded)
{
    Gecko::String sAllyPartyID = "AllyParty";
    Gecko::String sAllyPartyType = GetEnumString(Gecko::CharacterPartyType::Ally);
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterPartyManager()->CreateParty(sAllyPartyID, sAllyPartyType, false));
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterPartyManager()->DoesPartyExistByID(sAllyPartyID));
}

// DoesPartyExistByType
BOOST_FIXTURE_TEST_CASE(DoesPartyExistByType, Gecko::TestFixtureAppLoaded)
{
    Gecko::String sAllyPartyID = "AllyParty";
    Gecko::String sAllyPartyType = GetEnumString(Gecko::CharacterPartyType::Ally);
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterPartyManager()->CreateParty(sAllyPartyID, sAllyPartyType, false));
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterPartyManager()->DoesPartyExistByType(sAllyPartyType));
}

// IsValidPartyID
BOOST_FIXTURE_TEST_CASE(IsValidPartyID, Gecko::TestFixtureAppLoaded)
{
    BOOST_CHECK_EQUAL(Gecko::GetManagers()->GetCharacterPartyManager()->IsValidPartyID("PartyID"), true);
    BOOST_CHECK_EQUAL(Gecko::GetManagers()->GetCharacterPartyManager()->IsValidPartyID("Ano ther party ID String@!"), true);
    BOOST_CHECK_EQUAL(Gecko::GetManagers()->GetCharacterPartyManager()->IsValidPartyID(""), false);
}

// GetPartyByID
BOOST_FIXTURE_TEST_CASE(GetPartyByID, Gecko::TestFixtureAppLoaded)
{
    Gecko::String sAllyPartyID = "EmptyAllyParty";
    Gecko::String sUnknownPartyID = "UnknownParty";
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterPartyManager()->LoadParty(Gecko::CharacterParty(Gecko::EMPTY_ALLY_CHARACTER_PARTY), false));
    BOOST_CHECK_NO_THROW(Gecko::GetManagers()->GetCharacterPartyManager()->GetPartyByID(sAllyPartyID));
    BOOST_CHECK_THROW(Gecko::GetManagers()->GetCharacterPartyManager()->GetPartyByID(sUnknownPartyID), Gecko::GeneralError);
}

// GetPartyByType
BOOST_FIXTURE_TEST_CASE(GetPartyByType, Gecko::TestFixtureAppLoaded)
{
    Gecko::String sAllyPartyID = "EmptyAllyParty";
    Gecko::String sAllyPartyType = GetEnumString(Gecko::CharacterPartyType::Ally);
    Gecko::String sUnknownPartyType = "";
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterPartyManager()->LoadParty(Gecko::CharacterParty(Gecko::EMPTY_ALLY_CHARACTER_PARTY), false, true));
    BOOST_CHECK_NO_THROW(Gecko::GetManagers()->GetCharacterPartyManager()->GetPartyByType(sAllyPartyType));
    BOOST_CHECK_THROW(Gecko::GetManagers()->GetCharacterPartyManager()->GetPartyByType(sUnknownPartyType), STDException);
}

// GetCurrentAllyParty
BOOST_FIXTURE_TEST_CASE(GetCurrentAllyParty, Gecko::TestFixtureAppLoaded)
{
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterPartyManager()->LoadParty(Gecko::CharacterParty(Gecko::EMPTY_ALLY_CHARACTER_PARTY), false, true));
    BOOST_CHECK_NO_THROW(Gecko::GetManagers()->GetCharacterPartyManager()->GetCurrentAllyParty());
}

// GetCurrentEnemyParty
BOOST_FIXTURE_TEST_CASE(GetCurrentEnemyParty, Gecko::TestFixtureAppLoaded)
{
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterPartyManager()->LoadParty(Gecko::CharacterParty(Gecko::EMPTY_ENEMY_CHARACTER_PARTY), false, true));
    BOOST_CHECK_NO_THROW(Gecko::GetManagers()->GetCharacterPartyManager()->GetCurrentEnemyParty());
}

// GetAllPartyIDs
BOOST_FIXTURE_TEST_CASE(GetAllPartyIDs, Gecko::TestFixtureAppLoaded)
{
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterPartyManager()->LoadParty(Gecko::CharacterParty(Gecko::EMPTY_ALLY_CHARACTER_PARTY), false));
    BOOST_CHECK(Gecko::GetManagers()->GetCharacterPartyManager()->LoadParty(Gecko::CharacterParty(Gecko::EMPTY_ENEMY_CHARACTER_PARTY), false));
    BOOST_CHECK_EQUAL(Gecko::GetManagers()->GetCharacterPartyManager()->GetAllPartyIDs().size(), static_cast<Gecko::UInt>(2));
}

BOOST_AUTO_TEST_SUITE_END()
