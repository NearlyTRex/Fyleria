// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Utility/TreeIndex.h"
#include "Utility/Json.h"
#include "Utility/Macros.h"

namespace Gecko
{

TreeIndex::TreeIndex()
    : SerializableToJson()
{
    SetTree("");
    SetBranch("");
    SetLeaf("");
}

TreeIndex::TreeIndex(const String& sTree, const String& sBranch, const String& sLeaf)
    : SerializableToJson()
{
    SetTree(sTree);
    SetBranch(sBranch);
    SetLeaf(sLeaf);
}

TreeIndex::TreeIndex(const Json& jsonData)
    : SerializableToJson(jsonData)
{
    from_json(jsonData, *this);
}

TreeIndex::TreeIndex(const String& jsonString)
    : SerializableToJson(JsonParse(jsonString))
{
    from_json(JsonParse(jsonString), *this);
}

TreeIndex::~TreeIndex()
{
}

String TreeIndex::GetTreeBranchType() const
{
    return (GetTree() + GetBranch());
}

String TreeIndex::GetTreeBranchLeafType() const
{
    return (GetTree() + GetBranch() + GetLeaf());
}

StringArray TreeIndex::GetTypes() const
{
    StringArray vTypes = {
        GetTree(),
        GetBranch(),
        GetLeaf()
    };
    return vTypes;
}

Bool TreeIndex::empty() const
{
    return (GetTree().empty() ||
            GetBranch().empty() ||
            GetLeaf().empty());
}

TreeIndex& TreeIndex::operator=(const TreeIndex& other)
{
    if(this != &other)
    {
        SetTree(other.GetTree());
        SetBranch(other.GetBranch());
        SetLeaf(other.GetLeaf());
    }
    return *this;
}

Bool TreeIndex::operator==(const TreeIndex& other) const
{
    return ((GetTree() == other.GetTree()) &&
            (GetBranch() == other.GetBranch()) &&
            (GetLeaf() == other.GetLeaf()));
}

Bool TreeIndex::operator!=(const TreeIndex& other) const
{
    return not operator==(other);
}

void to_json(Json& jsonData, const TreeIndex& obj)
{
    SET_JSON_DATA(Tree);
    SET_JSON_DATA(Branch);
    SET_JSON_DATA(Leaf);
}

void from_json(const Json& jsonData, TreeIndex& obj)
{
    SET_OBJ_DATA(Tree, String);
    SET_OBJ_DATA(Branch, String);
    SET_OBJ_DATA(Leaf, String);
}

MAKE_JSON_SEQUENCE_TYPE_CONVERTERS_IMPL(TreeIndexArray);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(TreeIndex, TreeIndex);

};
