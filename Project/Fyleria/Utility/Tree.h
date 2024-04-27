// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_UTILITY_TREE_H_
#define _GECKO_UTILITY_TREE_H_

// Internal includes
#include "Utility/Logging.h"
#include "Utility/Errors.h"
#include "Utility/TreeIndex.h"
#include "Utility/Serialization.h"

namespace Gecko
{

template <class T>
class Tree
{
public:

    // Constructors
    Tree()
        : m_tBranches()
    {
    }

    // Get tree type
    static String GetTreeType()
    {
        return T::GetTreeType();
    }

    // Clear all data
    void ClearAllData()
    {
        m_tBranches.clear();
    }

    // Add branch
    void AddBranch(const String& sBranchName, const Json& jsonData)
    {
        // Add branches
        for(auto it = jsonData.begin(); it != jsonData.end(); it++)
        {
            AddLeaf(sBranchName, String(it.key()), T(it.value()));
        }
    }

    // Add leaf
    void AddLeaf(const String& sBranchName, const String& sLeafName, const T& data)
    {
        if(!sBranchName.empty() && !sLeafName.empty())
        {
            m_tBranches[sBranchName][sLeafName] = data;
        }
    }

    // Get leaf
    const T& GetLeaf(const String& sBranchName, const String& sLeafName) const
    {
        return m_tBranches.at(sBranchName).at(sLeafName);
    }
    T& GetLeaf(const String& sBranchName, const String& sLeafName)
    {
        return const_cast<T&>(static_cast<const Tree<T>&>(*this).GetLeaf(sBranchName, sLeafName));
    }

    // Get leaf
    const T& GetLeaf(const String& sLeafName) const
    {
        String sBranchName = GetBranchFromLeaf(sLeafName);
        if(sBranchName.empty())
        {
            THROW_RUNTIME_ERROR("Specified leaf '" + sLeafName + "' was not found on any branches");
        }
        return GetLeaf(sBranchName, sLeafName);
    }
    T& GetLeaf(const String& sLeafName)
    {
        return const_cast<T&>(static_cast<const Tree<T>&>(*this).GetLeaf(sLeafName));
    }

    // Get leaf
    const T& GetLeaf(const TreeIndex& index) const
    {
        return GetLeaf(index.GetBranch(), index.GetLeaf());
    }
    T& GetLeaf(const TreeIndex& index)
    {
        return const_cast<T&>(static_cast<const Tree<T>&>(*this).GetLeaf(index));
    }

    // Get numbered leaf
    const T& GetNumberedLeaf(const String& sBranchName, const String& sLeafBase, Int iLeafNumber) const
    {
        return GetLeaf(sBranchName, GetLeafNameFromNumber(sLeafBase, iLeafNumber));
    }
    T& GetNumberedLeaf(const String& sBranchName, const String& sLeafBase, Int iLeafNumber)
    {
        return const_cast<T&>(static_cast<const Tree<T>&>(*this).GetNumberedLeaf(sBranchName, sLeafBase, iLeafNumber));
    }

    // Get all leaves
    TreeIndexArray GetAllLeaves(const String& sBranchName) const
    {
        // Check branch
        TreeIndexArray vLeaves;
        if(sBranchName.empty())
        {
            return vLeaves;
        }

        // Look at all the leaves
        for(auto it = m_tBranches.at(sBranchName).cbegin(); it != m_tBranches.at(sBranchName).cend(); it++)
        {
            // Add new leaf
            vLeaves.push_back(TreeIndex(GetTreeType(), sBranchName, it->first));
        }
        return vLeaves;
    }

    // Get all unique leaves under the given number
    TreeIndexArray GetLeavesUnderNumber(const String& sBranchName, const String& sLeafBase, Int iLeafNumber, Bool bUniqueOnly) const
    {
        // Check branch
        TreeIndexArray vLeaves;
        if(sBranchName.empty())
        {
            return vLeaves;
        }

        // Look at each of the leaves at or below the given number
        StringArray vCheckedClasses;
        for(Int i = iLeafNumber; i >= 0; i--)
        {
            // Ignore invalid leaves
            if(!HasLeaf(sBranchName, sLeafBase, i))
            {
                continue;
            }

            // Only store unique leaves if they asked for that
            if(bUniqueOnly)
            {
                // Get leaf
                const T& leaf = GetNumberedLeaf(sBranchName, sLeafBase, i);

                // Skip if we already have a matching class
                String sClass = leaf.GetSkillType() + String("_") + leaf.GetDataClass();
                auto iClassSearch = STDFindData(vCheckedClasses.begin(), vCheckedClasses.end(), sClass);
                if(iClassSearch != vCheckedClasses.end())
                {
                    continue;
                }

                // Store newly checked class
                vCheckedClasses.push_back(sClass);
            }

            // Add new leaf
            vLeaves.push_back(TreeIndex(GetTreeType(), sBranchName, GetLeafNameFromNumber(sLeafBase, i)));
        }
        return vLeaves;
    }

    // Check if a branch exists
    Bool HasBranch(const String& sBranchName) const
    {
        return (m_tBranches.find(sBranchName) != m_tBranches.end());
    }

    // Check if a leaf exists
    Bool HasLeaf(const String& sBranchName, const String& sLeafName) const
    {
        return (m_tBranches.find(sBranchName) != m_tBranches.end() &&
                m_tBranches.at(sBranchName).find(sLeafName) != m_tBranches.at(sBranchName).end());
    }

    // Check if a numbered leaf exists
    Bool HasLeaf(const String& sBranchName, const String& sLeafBase, Int iLeafNumber) const
    {
        return HasLeaf(sBranchName, GetLeafNameFromNumber(sLeafBase, iLeafNumber));
    }

    // Check if a leaf exists
    Bool HasLeaf(const String& sLeafName) const
    {
        return HasLeaf(GetBranchFromLeaf(sLeafName), sLeafName);
    }

    // Check if a leaf exists
    Bool HasLeaf(const TreeIndex& index) const
    {
        return HasLeaf(index.GetBranch(), index.GetLeaf());
    }

    // Get branch name from leaf name
    String GetBranchFromLeaf(const String& sLeafName) const
    {
        String sBranchName("");
        for(auto it = m_tBranches.cbegin(); it != m_tBranches.cend(); ++it)
        {
            if(HasLeaf(it->first, sLeafName))
            {
                sBranchName = it->first;
                break;
            }
        }
        return sBranchName;
    }

    // Get leaf name from base and number
    String GetLeafNameFromNumber(const String& sLeafBase, Int iLeafNumber) const
    {
        return sLeafBase + String(STDToString(iLeafNumber));
    }

private:

    // Leaves
    typedef STDUnorderedMap<String, T> LeafType;
    typedef STDUnorderedMap<String, LeafType> BranchType;
    typedef typename LeafType::iterator LeafTypeIterator;
    typedef typename LeafType::const_iterator LeafTypeConstIterator;
    typedef STDPair<String, T> BranchNodeType;
    BranchType m_tBranches;
};

};

#endif
