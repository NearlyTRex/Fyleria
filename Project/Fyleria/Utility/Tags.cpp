// Fyleria Engine
// Copyright (c) 2019 Go Go Gecko Productions. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Internal includes
#include "Utility/Tags.h"
#include "Application/Application.h"

namespace Gecko
{

String MakeInlineStylesheetTag(const String& sStyle)
{
    // Make tag
    String sTag = "<style>" + sStyle + "</style>\n";
    return sTag;
}

String MakeFileStylesheetTag(const String& sFile, const String& sFileRoot)
{
    // Make tag
    String sUri = GetManagers()->GetFileManager()->GetUriPath(sFile, sFileRoot);
    String sTag = "<link rel=\"stylesheet\" type=\"text/css\" href='" + sUri + "'>\n";
    return sTag;
}

String MakeInlineJavascriptTag(const String& sScript)
{
    // Make tag
    String sTag = "<script type=\"text/javascript\">" + sScript + "</script>\n";
    return sTag;
}

String MakeFileJavascriptTag(const String& sFile, const String& sFileRoot)
{
    // Make tag
    String sUri = GetManagers()->GetFileManager()->GetUriPath(sFile, sFileRoot);
    String sTag = "<script type=\"text/javascript\" src=\"" + sUri + "\"></script>\n";
    return sTag;
}

};
