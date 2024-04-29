// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Scene/SceneToolCharacter.h"
#include "Scene/SceneTypes.h"
#include "Scene/SceneMacros.h"
#include "Application/Application.h"

namespace Gecko
{

SceneToolCharacter::SceneToolCharacter()
    : Scene(GetEnumString(SceneType::ToolCharacter))
{
}

SceneToolCharacter::~SceneToolCharacter()
{
}

void SceneToolCharacter::Bind()
{
    // Call parent
    Scene::Bind();

    // Bind functions
    BIND_SYNCHRONOUS_FUNCTION_ARG1_NORETURN(CreateCharacter, String, character_id);
    BIND_SYNCHRONOUS_FUNCTION_ARG1(GetCharacter, String, character_id);
    BIND_SYNCHRONOUS_FUNCTION_ARG1_NORETURN(LoadCharacterFromJson, String, character_json);
    BIND_SYNCHRONOUS_FUNCTION_ARG2_NORETURN(LoadCharacterFromFile, String, file_location, String, file_type);
    BIND_SYNCHRONOUS_FUNCTION_ARG3_NORETURN(SaveCharacterFromID, String, character_id, String, file_location, String, file_type);
    BIND_SYNCHRONOUS_FUNCTION_ARG3_NORETURN(SaveCharacterFromJson, String, character_json, String, file_location, String, file_type);
    BIND_SYNCHRONOUS_FUNCTION_ARG1_NORETURN(UnloadCharacter, String, character_id);
    BIND_SYNCHRONOUS_FUNCTION_ARG2_NORETURN(GenerateCharacter, String, character_id, String, generator_json);
    BIND_SYNCHRONOUS_FUNCTION_ARG1_NORETURN(GenerateRandomCharacter, String, character_id);
    BIND_SYNCHRONOUS_FUNCTION_ARG1_NORETURN(RegenerateCharacterData, String, character_id);
}

void SceneToolCharacter::Start()
{
    // Call parent
    Scene::Start();

    // Set main page content
    SetMainPageContent();
}

void SceneToolCharacter::Finish()
{
    // Call parent
    Scene::Finish();
}

void SceneToolCharacter::Update()
{
}

void SceneToolCharacter::Input()
{
}

void SceneToolCharacter::CreateCharacter(const String& sCharacterID)
{
    GetManagers()->GetCharacterManager()->CreateCharacter(sCharacterID);
}

String SceneToolCharacter::GetCharacter(const String& sCharacterID)
{
    Json jsonData = GetManagers()->GetCharacterManager()->GetCharacter(sCharacterID);
    return jsonData.dump();
}

void SceneToolCharacter::LoadCharacterFromJson(const String& sCharacterJson)
{
    GetManagers()->GetCharacterManager()->LoadCharacter(Character(sCharacterJson), true);
}

void SceneToolCharacter::LoadCharacterFromFile(const String& sFileLocation, const String& sFileType)
{
    GetManagers()->GetCharacterManager()->LoadCharacterFromFile(sFileLocation, sFileType, true);
}

void SceneToolCharacter::SaveCharacterFromID(const String& sCharacterID, const String& sFileLocation, const String& sFileType)
{
    GetManagers()->GetCharacterManager()->SaveCharacterToFile(sCharacterID, sFileLocation, sFileType);
}

void SceneToolCharacter::SaveCharacterFromJson(const String& sCharacterJson, const String& sFileLocation, const String& sFileType)
{
    Character character(sCharacterJson);
    GetManagers()->GetCharacterManager()->LoadCharacter(character, true);
    GetManagers()->GetCharacterManager()->SaveCharacterToFile(character.GetCharacterID(), sFileLocation, sFileType);
}

void SceneToolCharacter::UnloadCharacter(const String& sCharacterID)
{
    GetManagers()->GetCharacterManager()->UnloadCharacter(sCharacterID);
}

void SceneToolCharacter::GenerateCharacter(const String& sCharacterID, const String& sGeneratorJson)
{
    GetManagers()->GetCharacterManager()->GenerateCharacter(sCharacterID, CharacterGenerator(sGeneratorJson));
}

void SceneToolCharacter::GenerateRandomCharacter(const String& sCharacterID)
{
    CharacterGenerator generator;
    generator.RandomizeAll();
    GetManagers()->GetCharacterManager()->GenerateCharacter(sCharacterID, generator);
}

void SceneToolCharacter::RegenerateCharacterData(const String& sCharacterID)
{
    Character& character = GetManagers()->GetCharacterManager()->GetCharacter(sCharacterID);
    character.RegenerateCharacterData();
}

};
