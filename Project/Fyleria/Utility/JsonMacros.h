// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_UTILITY_JSON_MACROS_H_
#define _GECKO_UTILITY_JSON_MACROS_H_

//===============================================================================================================================================

#define SET_JSON_DATA(name)                                                                                                                     \
{                                                                                                                                               \
    jsonData[#name] = obj.Get##name();                                                                                                          \
}

#define SET_OBJ_DATA(name, value_type)                                                                                                          \
{                                                                                                                                               \
    if(jsonData.find(#name) != jsonData.end())                                                                                                  \
    {                                                                                                                                           \
        obj.Set##name(jsonData[#name].get<value_type>());                                                                                       \
    }                                                                                                                                           \
    else                                                                                                                                        \
    {                                                                                                                                           \
        obj.Set##name({});                                                                                                                      \
    }                                                                                                                                           \
}

//===============================================================================================================================================

#define MAKE_JSONDATA_WRAPPER_CLASS_PROTO(category, type)                                                                                       \
void Write##type##Wrapper();                                                                                                                    \
String Get##type##Wrapper();

#define MAKE_JSONDATA_WRAPPER_CLASS_IMPL_START(category, type)                                                                                  \
void Write##type##Wrapper()                                                                                                                     \
{                                                                                                                                               \
    String sPath = GetManagers()->GetFileManager()->GetDataLibsMainDirectory();                                                                 \
    sPath = GetManagers()->GetFileManager()->JoinPaths(sPath, #category);                                                                       \
    sPath = GetManagers()->GetFileManager()->JoinPaths(sPath, #type ".js");                                                                     \
    GetManagers()->GetFileManager()->WriteStringToFile(sPath, Get##type##Wrapper());                                                            \
}                                                                                                                                               \
String Get##type##Wrapper()                                                                                                                     \
{                                                                                                                                               \
    String sWrapper;                                                                                                                            \
    sWrapper += "/*autogenerated, do not edit*/\n";                                                                                             \
    sWrapper += "/*jshint esversion: 6*/\n";                                                                                                    \
    sWrapper += "export class " #type " {\n";                                                                                                   \
    sWrapper += "    constructor(jsonData) {\n";                                                                                                \
    sWrapper += "        this.jsonData = jsonData;\n";                                                                                          \
    sWrapper += "    }\n";

#define MAKE_JSONDATA_WRAPPER_CLASS_IMPL_PROPERTY(name)                                                                                         \
    sWrapper += "    get " #name "() {\n";                                                                                                      \
    sWrapper += "        if (\"" #name "\" in this.jsonData) {\n";                                                                              \
    sWrapper += "            return this.jsonData." #name ";\n";                                                                                \
    sWrapper += "        }\n";                                                                                                                  \
    sWrapper += "        else {\n";                                                                                                             \
    sWrapper += "            return null;\n";                                                                                                   \
    sWrapper += "        }\n";                                                                                                                  \
    sWrapper += "    }\n";                                                                                                                      \
    sWrapper += "    set " #name "(val) {\n";                                                                                                   \
    sWrapper += "        this.jsonData." #name " = val;\n";                                                                                     \
    sWrapper += "    }\n";

#define MAKE_JSONDATA_WRAPPER_CLASS_IMPL_END()                                                                                                  \
    sWrapper += "}\n";                                                                                                                          \
    return sWrapper;                                                                                                                            \
}

//===============================================================================================================================================

#endif
