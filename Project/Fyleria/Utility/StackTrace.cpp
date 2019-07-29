// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// Internal includes
#include "Utility/StackTrace.h"
#include "Utility/Logging.h"

namespace Gecko
{
    void DefaultSignalHandler(Int iSignal
#ifndef _WIN32
        , siginfo_t* pInfo, void* pContext
#endif
    )
    {
        STDCerr << "Program terminated by signal " << iSignal << STDEndl;
#ifdef __linux__
        psiginfo(info, "Details");
#endif
        DumpStacktrace(STDCerr, GetStacktrace());
#ifdef _WIN32
        STDSignal(iSignal, SIG_DFL);
#endif
        STDRaise(iSignal);
    }

    void RegisterSignalHandler()
    {
#ifdef _WIN32
        const IntArray vSignals = { SIGSEGV, SIGABRT, SIGFPE, SIGILL };
        for (Int iSignal : vSignals)
        {
            STDSignal(iSignal, DefaultSignalHandler);
        }
#else
        const IntArray vSignals = { SIGSEGV, SIGABRT, SIGBUS, SIGFPE, SIGILL, SIGXCPU, SIGXFSZ };
        for (Int iSignal : vSignals)
        {
            struct sigaction action;
            memset(&action, 0, sizeof(struct sigaction));
            sigfillset(&action.sa_mask);
            action.sa_sigaction = DefaultSignalHandler;
            action.sa_flags = static_cast<Int>(SA_SIGINFO | SA_RESETHAND);
            sigaction(iSignal, &action, nullptr);
        }
#endif
    }

    StackTrace GetStacktrace()
    {
#ifdef _WIN32
        return STDMakePair(BoostStacktrace(), 0);
#else
        StackTrace stackTrace;
        stackTrace.load_here();
        return stackTrace;
#endif
    }

    void DumpStacktrace(STDOutputStream& sStream, const StackTrace& stackTrace)
    {
#ifdef _WIN32
        STDVector<StackResolvedTrace> vResolvedTraces;
        SizeType uFrameID = 0;
        for (const auto& stackFrame : stackTrace.first)
        {
            StackResolvedTrace resolvedTrace;
            resolvedTrace.addr = const_cast<void*>(stackFrame.address());
            resolvedTrace.idx = uFrameID++;
            resolvedTrace.source.function = stackFrame.name();
            resolvedTrace.source.filename = stackFrame.source_file();
            resolvedTrace.source.line = static_cast<UInt>(stackFrame.source_line());
            resolvedTrace.source.col = 0;
            resolvedTrace.object_filename = {};
            resolvedTrace.object_function = resolvedTrace.source.function;
            resolvedTrace.inliners = {};
            vResolvedTraces.push_back(resolvedTrace);
        }
        StackTracePrinter printer;
        printer.snippet = true;
        printer.address = true;
        printer.object = false;
        printer.print(vResolvedTraces.rbegin(), vResolvedTraces.rend(), sStream, static_cast<size_t>(stackTrace.second));
        sStream.flush();
#else
        StackTracePrinter printer;
        printer.snippet = true;
        printer.address = true;
        printer.object = false;
        printer.print(stackTrace, sStream);
        sStream.flush();
#endif
    }
};
