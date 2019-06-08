// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_SKILLDATA_ALCHEMY_H_
#define _GECKO_SKILLDATA_ALCHEMY_H_

#include "Skills/SkillData.h"
#include "Skills/SkillTypes.h"
#include "Recipes/Recipe.h"

namespace Gecko
{

class SkillDataAlchemy : public SkillData
{
public:

    // Constructors
    SkillDataAlchemy();
    SkillDataAlchemy(const Json& jsonData);

    // Clear all data
    virtual void Clear();

    // Skill tree type
    static String GetTreeType()
    {
        return String(SkillTreeType(SkillTreeType::Alchemy)._to_string());
    }

    // Recipes
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(Recipes, RecipeArray);
};

// Typedef
MAKE_TYPE_TYPEDEFS(SkillDataAlchemy);

// JSON Converters
void to_json(Json& jsonData, const SkillDataAlchemy& obj);
void from_json(const Json& jsonData, SkillDataAlchemy& obj);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_DECL(SkillDataAlchemy, SkillDataAlchemy);

};

#endif
