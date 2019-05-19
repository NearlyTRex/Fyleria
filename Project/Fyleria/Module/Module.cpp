// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "Module/Module.h"
#include "Utility/IndexedString.h"

namespace Gecko
{

namespace ModuleResult
{
    typedef STDMap<String, String> ModuleResultMapType;
    typedef SafeObject<ModuleResultMapType> SafeModuleResultMapType;
    static SafeIndexedString s_pRunResultID;
    static SafeModuleResultMapType s_pResultsStorage;

    void SetRunResultID(const String& sID)
    {
        s_pRunResultID->Set(sID);
    }

    String GetRunResultID()
    {
        return s_pRunResultID->Get();
    }

    void StoreResult(const String& sID, const String& sResult)
    {
        s_pResultsStorage->insert({sID, sResult});
    }

    void StoreRunResult(const String& sResult)
    {
        StoreResult(GetRunResultID(), sResult);
    }

    String GetResult(const String& sID)
    {
        auto iSearch = s_pResultsStorage->find(sID);
        if(iSearch != s_pResultsStorage->end())
        {
            return iSearch->second;
        }
        else
        {
            return String();
        }
    }

    Bool DoesResultExist(const String& sID)
    {
        auto iSearch = s_pResultsStorage->find(sID);
        return (iSearch != s_pResultsStorage->end());
    }

    void ClearResult(const String& sID)
    {
        s_pResultsStorage->erase(sID);
    }

    void ClearAllResults()
    {
        s_pResultsStorage->clear();
    }
};

};
