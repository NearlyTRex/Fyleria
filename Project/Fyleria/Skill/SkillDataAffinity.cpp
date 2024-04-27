// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Skill/SkillDataAffinity.h"
#include "Utility/JsonMacros.h"

namespace Gecko
{

SkillDataAffinity::SkillDataAffinity()
    : SkillData()
{
}

SkillDataAffinity::SkillDataAffinity(const Json& jsonData)
    : SkillData(jsonData)
{
    from_json(jsonData, *this);
}

SkillDataAffinity::~SkillDataAffinity()
{
}

void SkillDataAffinity::Clear()
{
    // Base clear
    SkillData::Clear();
}

void to_json(Json& jsonData, const SkillDataAffinity& obj)
{
}

void from_json(const Json& jsonData, SkillDataAffinity& obj)
{
}

};
