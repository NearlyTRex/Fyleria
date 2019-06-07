// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#include "Utility/TreeIndex.h"
#include "Utility/Json.h"
#include "Utility/Macros.h"

namespace Gecko
{

TreeIndex::TreeIndex()
    : SerializableToJson()
{
}

TreeIndex::TreeIndex(const IndexedString& sTree, const IndexedString& sBranch, const IndexedString& sLeaf)
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

IndexedString TreeIndex::GetTreeBranchType() const
{
    return (GetTree() + GetBranch());
}

IndexedString TreeIndex::GetTreeBranchLeafType() const
{
    return (GetTree() + GetBranch() + GetLeaf());
}

IndexedStringArray TreeIndex::GetTypes() const
{
    IndexedStringArray vTypes = {
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
    SET_JSON_DATA_IF_NOT_DEFAULT(Tree, IndexedString(""));
    SET_JSON_DATA_IF_NOT_DEFAULT(Branch, IndexedString(""));
    SET_JSON_DATA_IF_NOT_DEFAULT(Leaf, IndexedString(""));
}

void from_json(const Json& jsonData, TreeIndex& obj)
{
    obj.SetTree(GET_JSON_DATA_OR_DEFAULT(Tree, IndexedString, IndexedString("")));
    obj.SetBranch(GET_JSON_DATA_OR_DEFAULT(Branch, IndexedString, IndexedString("")));
    obj.SetLeaf(GET_JSON_DATA_OR_DEFAULT(Leaf, IndexedString, IndexedString("")));
}

MAKE_JSON_GENERIC_TYPE_CONVERTERS_IMPL(TreeIndex, TreeIndex);

};
