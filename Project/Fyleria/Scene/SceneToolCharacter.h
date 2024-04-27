// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_SCENE_SCENE_TOOL_CHARACTER_H_
#define _GECKO_SCENE_SCENE_TOOL_CHARACTER_H_

// Internal includes
#include "Scene/Scene.h"

namespace Gecko
{

class SceneToolCharacter : public Scene
{
public:

    // Constructor
    SceneToolCharacter();

    // Destructor
    virtual ~SceneToolCharacter();

    // Bind scene functions
    virtual void Bind() override;

    // Start scene
    virtual void Start() override;

    // Finish scene
    virtual void Finish() override;

    // Update scene
    virtual void Update() override;

    // Handle scene input
    virtual void Input() override;

private:

    // Create character
    void CreateCharacter(const String& sCharacterID);

    // Get character
    String GetCharacter(const String& sCharacterID);

    // Load character from json
    void LoadCharacterFromJson(const String& sCharacterJson);

    // Load character from file
    void LoadCharacterFromFile(const String& sFileLocation, const String& sFileType);

    // Save character from id
    void SaveCharacterFromID(const String& sCharacterID, const String& sFileLocation, const String& sFileType);

    // Save character from json
    void SaveCharacterFromJson(const String& sCharacterJson, const String& sFileLocation, const String& sFileType);

    // Unload character
    void UnloadCharacter(const String& sCharacterID);

    // Generate character
    void GenerateCharacter(const String& sCharacterID, const String& sGeneratorJson);

    // Generate random character
    void GenerateRandomCharacter(const String& sCharacterID);

    // Regenerate character data
    void RegenerateCharacterData(const String& sCharacterID);
};

// Typedef
MAKE_COMMON_TYPEDEFS(SceneToolCharacter);

};

#endif
