// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_MODULE_RESULT_MANAGER_H_
#define _GECKO_MODULE_RESULT_MANAGER_H_

#include "Utility/Types.h"
#include "Utility/Singleton.h"
#include "Utility/Macros.h"

namespace Gecko
{

class ModuleResultManager : public Singleton<ModuleResultManager>
{
public:

    // Types
    typedef STDUnorderedMap<String, String> ModuleResultMappingType;

    // Constructors
    ModuleResultManager();

    // Store result in the given id
    void StoreResult(const String& sID, const String& sResult);

    // Store result in the run id
    void StoreCurrentResult(const String& sResult);

    // Get result from the given slot
    String GetResult(const String& sID);

    // Determine if result exists
    Bool DoesResultExist(const String& sID);

    // Clear the results from the given slot
    void ClearResult(const String& sID);

    // Clear all the results
    void ClearAllResults();

    // Current result ID
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(CurrentResultID, String);

    // Module results
    MAKE_RAW_OBJECT_TYPE_ACCESSORS(ModuleResults, ModuleResultMappingType);
};

};

#endif
