// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "Module/Module.h"
#include "Utility/IndexedString.h"

namespace Gecko
{

ModuleResultManager::ModuleResultManager()
    : Singleton<ModuleResultManager>()
{
}

void ModuleResultManager::StoreResult(const String& sID, const String& sResult)
{
    GetModuleResults().insert({sID, sResult});
}

void ModuleResultManager::StoreCurrentResult(const String& sResult)
{
    StoreResult(GetCurrentResult(), sResult);
}

String ModuleResultManager::GetResult(const String& sID)
{
    auto iSearch = GetModuleResults().find(sID);
    if(iSearch != GetModuleResults().end())
    {
        return iSearch->second;
    }
    else
    {
        return String();
    }
}

Bool ModuleResultManager::DoesResultExist(const String& sID)
{
    auto iSearch = GetModuleResults().find(sID);
    return (iSearch != GetModuleResults().end());
}

void ModuleResultManager::ClearResult(const String& sID)
{
    GetModuleResults().erase(sID);
}

void ModuleResultManager::ClearAllResults()
{
    GetModuleResults().clear();
}

};
