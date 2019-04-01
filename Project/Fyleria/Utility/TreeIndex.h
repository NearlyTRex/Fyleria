// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

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

    // Tree/branch/leaf name
    const IndexedString& GetTree() const;
    const IndexedString& GetBranch() const;
    const IndexedString& GetLeaf() const;
    void SetTree(const IndexedString& sName);
    void SetBranch(const IndexedString& sName);
    void SetLeaf(const IndexedString& sName);

    // Composite types
    IndexedString GetTreeBranchType() const;
    IndexedString GetTreeBranchLeafType() const;
    IndexedStringArray GetTypes() const;

    // Compatibility
    Bool empty() const;

    // Comparisons
    Bool operator==(const TreeIndex& other) const;
    Bool operator!=(const TreeIndex& other) const;

private:

    // Branch/leaf name
    IndexedString m_sTreeName;
    IndexedString m_sBranchName;
    IndexedString m_sLeafName;
};
typedef STDVector<TreeIndex> TreeIndexArray;
void to_json(Json& jsonData, const TreeIndex& obj);
void from_json(const Json& jsonData, TreeIndex& obj);
MAKE_JSON_GENERIC_TYPE_CONVERTERS_DECL(TreeIndex, TreeIndex);

};

#endif
