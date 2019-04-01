// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

#include "Utility/Enum.h"

namespace Gecko
{

MAKE_ENUM_GETSTRINGARRAY_IMPL(OperationType);
MAKE_ENUM_GETSTRINGARRAY_IMPL(ComparisonType);
MAKE_ENUM_GETSTRINGARRAY_IMPL(FileType);

MAKE_ENUM_CONVERTERS_IMPL(OperationType);
MAKE_ENUM_CONVERTERS_IMPL(ComparisonType);
MAKE_ENUM_CONVERTERS_IMPL(FileType);

};
