// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

#ifndef _GECKO_APPLICATION_H_
#define _GECKO_APPLICATION_H_

// Internal includes
#include "Utility/Types.h"
#include "Utility/Macros.h"
#include "Utility/ManagerSet.h"

namespace Gecko
{

class Application
{
public:

    // Constructor
    Application();

    // Destructor
    virtual ~Application();

    // Run application
    Int Run();

private:

    // Initialize
    Bool Initialize();

    // Finalize
    Bool Finalize();

    // Managers
    MAKE_RAW_TYPE_ACCESSORS(Managers, ManagerSetSharedPtr);
};

};

#endif
