// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#ifndef _GECKO_INTERFACE_H_
#define _GECKO_INTERFACE_H_

#if defined(NO_DLL)
    #define DLL_PUBLIC
#else
    #if defined(_MSC_VER) || defined(__MINGW32__) || defined(__MINGW64__)
        #ifdef BUILDING_DLL
            #define DLL_PUBLIC __declspec(dllexport)
        #else
            #define DLL_PUBLIC __declspec(dllimport)
        #endif
    #elif defined(__GNUC__)
        #define DLL_PUBLIC __attribute__((visibility("default")))
    #else
        #define DLL_PUBLIC
        #pragma warning Unknown dynamic link import/export semantics.
    #endif
#endif

// Initialize module
// This must be run before any other DLL calls
extern "C" DLL_PUBLIC bool DLL_InitModule();

// Finalize module
// This must be run last after all DLL calls are finished
extern "C" DLL_PUBLIC bool DLL_FinalizeModule();

// Run module file
extern "C" DLL_PUBLIC bool DLL_RunModuleFile(const char* sFile);

// Run module command
extern "C" DLL_PUBLIC bool DLL_RunModuleCommand(const char* sCommand);

// Set the current module result ID
extern "C" DLL_PUBLIC void DLL_SetCurrentModuleResultID(const char* sResultsID);

// Clear the results pointed to by the given ID
extern "C" DLL_PUBLIC void DLL_ClearModuleResult(const char* sResultsID);

// Clear all the stored results
extern "C" DLL_PUBLIC void DLL_ClearAllModuleResults();

// Determine if results exist at the given ID
extern "C" DLL_PUBLIC bool DLL_DoesModuleResultExist(const char* sResultsID);

// Get the size of the results from the given ID
extern "C" DLL_PUBLIC unsigned int DLL_GetModuleResultSize(const char* sResultsID);

// Get the results from the given ID
extern "C" DLL_PUBLIC bool DLL_GetModuleResults(const char* sResultsID, char* sResultStr, unsigned int uResultLen);

// Verify module data
extern "C" DLL_PUBLIC void DLL_VerifyModuleData();

#endif
