#ifndef DATA_H
#define DATA_H

#include "./core.hpp"
#include "./bool.hpp"
#include "./int.hpp"
#include "./float.hpp"
#include "./double.hpp"
#include "./string.hpp"
#include "./type.hpp"

namespace dataObject
{
    int len(DataObject &data);
    String type(DataObject &data);
    String getEnv(const String &data);
}

#endif