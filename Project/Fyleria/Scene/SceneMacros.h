// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_SCENE_SCENE_MACROS_H_
#define _GECKO_SCENE_SCENE_MACROS_H_

//===============================================================================================================================

#define BIND_SYNCHRONOUS_FUNCTION(name)                                                                                         \
BindSynchronousFunction(#name, {}, [&](const String& sReq) -> String {                                                          \
    return name();                                                                                                              \
});

#define BIND_SYNCHRONOUS_FUNCTION_NORETURN(name)                                                                                \
BindSynchronousFunction(#name, {}, [&](const String& sReq) -> String {                                                          \
    name();                                                                                                                     \
    return "";                                                                                                                  \
});

#define BIND_SYNCHRONOUS_FUNCTION_ARG1(name, arg1_type, arg1_name)                                                              \
BindSynchronousFunction(#name, {#arg1_name}, [&](const String& sReq) -> String {                                                \
    Json jsonParams = JsonParse(sReq);                                                                                          \
    arg1_type arg1_name = jsonParams[0].template get<arg1_type>();                                                              \
    return name(arg1_name);                                                                                                     \
});

#define BIND_SYNCHRONOUS_FUNCTION_ARG1_NORETURN(name, arg1_type, arg1_name)                                                     \
BindSynchronousFunction(#name, {#arg1_name}, [&](const String& sReq) -> String {                                                \
    Json jsonParams = JsonParse(sReq);                                                                                          \
    arg1_type arg1_name = jsonParams[0].template get<arg1_type>();                                                              \
    name(arg1_name);                                                                                                            \
    return "";                                                                                                                  \
});

#define BIND_SYNCHRONOUS_FUNCTION_ARG2(name, arg1_type, arg1_name, arg2_type, arg2_name)                                        \
BindSynchronousFunction(#name, {#arg1_name, #arg2_name}, [&](const String& sReq) -> String {                                    \
    Json jsonParams = JsonParse(sReq);                                                                                          \
    arg1_type arg1_name = jsonParams[0].template get<arg1_type>();                                                              \
    arg2_type arg2_name = jsonParams[1].template get<arg2_type>();                                                              \
    return name(arg1_name, arg2_name);                                                                                          \
});

#define BIND_SYNCHRONOUS_FUNCTION_ARG2_NORETURN(name, arg1_type, arg1_name, arg2_type, arg2_name)                               \
BindSynchronousFunction(#name, {#arg1_name, #arg2_name}, [&](const String& sReq) -> String {                                    \
    Json jsonParams = JsonParse(sReq);                                                                                          \
    arg1_type arg1_name = jsonParams[0].template get<arg1_type>();                                                              \
    arg2_type arg2_name = jsonParams[1].template get<arg2_type>();                                                              \
    name(arg1_name, arg2_name);                                                                                                 \
    return "";                                                                                                                  \
});

#define BIND_SYNCHRONOUS_FUNCTION_ARG3(name, arg1_type, arg1_name, arg2_type, arg2_name, arg3_type, arg3_name)                  \
BindSynchronousFunction(#name, {#arg1_name, #arg2_name, #arg3_name}, [&](const String& sReq) -> String {                        \
    Json jsonParams = JsonParse(sReq);                                                                                          \
    arg1_type arg1_name = jsonParams[0].template get<arg1_type>();                                                              \
    arg2_type arg2_name = jsonParams[1].template get<arg2_type>();                                                              \
    arg3_type arg3_name = jsonParams[2].template get<arg3_type>();                                                              \
    return name(arg1_name, arg2_name, arg3_name);                                                                               \
});

#define BIND_SYNCHRONOUS_FUNCTION_ARG3_NORETURN(name, arg1_type, arg1_name, arg2_type, arg2_name, arg3_type, arg3_name)         \
BindSynchronousFunction(#name, {#arg1_name, #arg2_name, #arg3_name}, [&](const String& sReq) -> String {                        \
    Json jsonParams = JsonParse(sReq);                                                                                          \
    arg1_type arg1_name = jsonParams[0].template get<arg1_type>();                                                              \
    arg2_type arg2_name = jsonParams[1].template get<arg2_type>();                                                              \
    arg3_type arg3_name = jsonParams[2].template get<arg3_type>();                                                              \
    name(arg1_name, arg2_name, arg3_name);                                                                                      \
    return "";                                                                                                                  \
});

//===============================================================================================================================

#endif
