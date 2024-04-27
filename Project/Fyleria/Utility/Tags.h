// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef _GECKO_UTILITY_TAGS_H_
#define _GECKO_UTILITY_TAGS_H_

// Internal includes
#include "Utility/Enum.h"
#include "Utility/Types.h"

namespace Gecko
{

// Make inline stylesheet tag
String MakeInlineStylesheetTag(const String& sStyle);

// Make file stylesheet tag
String MakeFileStylesheetTag(const String& sFile, const String& sFileRoot);

// Make inline javascript tag
String MakeInlineJavascriptTag(const String& sScript);

// Make file javascript tag
String MakeFileJavascriptTag(const String& sFile, const String& sFileRoot);

// Make enum option tags
template <class EnumType>
String MakeEnumOptionTags(const String& sSelection = "")
{
    String sTags;
    for(auto& sTypeName : GetEnumNames<EnumType>())
    {
        if(IsNoneTypeForEnum<EnumType>(sTypeName))
        {
            continue;
        }
        if (sSelection.size() > 0 && sTypeName == sSelection)
        {
            sTags += "<option value=\"" + sTypeName + "\" selected=\"selected\">" + sTypeName + "</option>";
        }
        else
        {
            sTags += "<option value=\"" + sTypeName + "\">" + sTypeName + "</option>";
        }
    }
    return sTags;
}

};

#endif
