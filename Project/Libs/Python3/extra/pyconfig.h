#ifndef _PYTHON3_EXTRA_PYCONFIG_H_
#define _PYTHON3_EXTRA_PYCONFIG_H_

// Include the correct pyconfig.h
#if defined(_MSC_VER) || defined(__MINGW32__) || defined(__MINGW64__)
    #include "pyconfig-windows.h"
#elif defined(__linux__) && defined(__i386__)
    #include "pyconfig-linux_x86_32.h"
#elif defined(__linux__) && defined(__x86_64__)
    #include "pyconfig-linux_x86_64.h"
#elif defined(__linux__) && defined(__ppc__)
    #include "pyconfig-linux_ppc_32.h"
#elif defined(__linux__) && defined(__ppc64__)
    #include "pyconfig-linux_ppc_64.h"
#endif

#endif

