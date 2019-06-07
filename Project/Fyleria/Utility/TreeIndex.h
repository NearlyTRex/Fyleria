// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_UTILITY_TREEINDEX_H_
#define _GECKO_UTILITY_TREEINDEX_H_

#include "Utility/IndexedString.h"
#include "Utility/Serializable.h"

namespace Gecko
{

class TreeIndex : public SerializableToJson
{
public:

    // Constructors
    TreeIndex();
    TreeIndex(const IndexedString& sTree, const IndexedString& sBranch, const IndexedString& sLeaf);
    explicit TreeIndex(const Json& jsonData);
    explicit TreeIndex(const String& jsonString);

    // Composite types
    IndexedString GetTreeBranchType() const;
    IndexedString GetTreeBranchLeafType() const;
    IndexedStringArray GetTypes() const;

    // Compatibility
    Bool empty() const;

    // Operators
    TreeIndex& operator=(const TreeIndex& other);

    // Comparisons
    Bool operator==(const TreeIndex& other) const;
    Bool operator!=(const TreeIndex& other) const;

    // Tree name
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(Tree, IndexedString);

    // Branch name
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(Branch, IndexedString);

    // Leaf name
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(Leaf, IndexedString);
};

// Typedef
MAKE_TYPE_TYPEDEFS(TreeIndex);

// JSON Converters
void to_json(Json& jsonData, const TreeIndex& obj);
void from_json(const Json& jsonData, TreeIndex& obj);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_DECL(TreeIndex, TreeIndex);

};

#endif
