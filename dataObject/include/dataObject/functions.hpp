#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <dataObject/core.hpp>
#include <dataObject/string.hpp>

namespace dataObject
{
    int len(DataObject &data);
    String type(DataObject &data);
    String getEnv(const String &data);
}

#endif
