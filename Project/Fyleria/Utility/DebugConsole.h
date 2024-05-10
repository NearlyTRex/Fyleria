// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_UTILITY_DEBUG_CONSOLE_H_
#define _GECKO_UTILITY_DEBUG_CONSOLE_H_

// Internal includes
#include "Utility/Types.h"
#include "Utility/Macros.h"

namespace Gecko
{

// DebugCommand
class DebugCommand
{
public:

    // Constructor
    DebugCommand(const String& sName, const StringArray& vArgs)
    {
        SetName(sName);
        SetArgs(vArgs);
    }

    // Name
    MAKE_RAW_TYPE_ACCESSORS(Name, String);

    // Args
    MAKE_RAW_TYPE_ACCESSORS(Args, StringArray);
};

// Typedef
MAKE_COMMON_TYPEDEFS(DebugCommand);

// DebugConsole
class DebugConsole
{
public:

    // Constructor
    DebugConsole();

    // Destructor
    virtual ~DebugConsole();

    // Add command
    virtual void AddCommand(const String& sName, const StringArray& vArgs);

    // Clear commands
    virtual void ClearCommands();

    // Generate console html
    String GenerateConsoleHTML() const;

    // Generate console javascript
    String GenerateConsoleJavaScript() const;

    // Commands
    MAKE_RAW_TYPE_ACCESSORS_GET_ONLY(Commands, DebugCommandArray);

private:

    // Create help function
    String CreateHelpFunction() const;

    // Create registered functions
    StringStringUnorderedMap CreateRegisteredFunctions() const;
};

// Typedef
MAKE_COMMON_TYPEDEFS(DebugConsole);

};

#endif
