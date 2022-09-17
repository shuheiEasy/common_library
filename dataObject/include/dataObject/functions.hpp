#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <dataObject/int.hpp>
#include <dataObject/string.hpp>

namespace dataObject
{
    Int len(DataObject &data);
    String type(DataObject &data);
    String getEnv(const String &data);
    String command(const char* cmd);
}

#endif
