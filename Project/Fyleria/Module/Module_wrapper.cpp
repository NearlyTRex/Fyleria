// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "Module/ModuleResultManager.h"
#include "Utility/Macros.h"
#include "Utility/Python.h"

namespace Gecko
{

SafePtr<ModuleResultManager>& GetModuleResultManager() { return ModuleResultManager::GetInstance(); }

};

PYBIND11_EMBEDDED_MODULE(GeckoModule, m)
{
    // ModuleResultManager.h
    PyBindClass<Gecko::ModuleResultManager>(m, "ModuleResultManager")
        WRAPPING_ADD_METHOD_SIMPLE(StoreResult, Gecko::ModuleResultManager)
        WRAPPING_ADD_METHOD_SIMPLE(StoreCurrentResult, Gecko::ModuleResultManager)
        WRAPPING_ADD_METHOD_SIMPLE(GetResult, Gecko::ModuleResultManager)
        WRAPPING_ADD_METHOD_SIMPLE(DoesResultExist, Gecko::ModuleResultManager)
        WRAPPING_ADD_METHOD_SIMPLE(ClearResult, Gecko::ModuleResultManager)
        WRAPPING_ADD_METHOD_SIMPLE(ClearAllResults, Gecko::ModuleResultManager)
        WRAPPING_ADD_BASIC_PROPERTY_MULTIGET(CurrentResultID, Gecko::ModuleResultManager)
    ;

    // Local
    WRAPPING_STANDALONE_METHOD_POLICY(GetModuleResultManager, Gecko, PyBindReturnCopy);
}
