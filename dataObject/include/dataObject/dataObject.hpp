#ifndef DATA_H
#define DATA_H

#include "./core.hpp"
#include "./bool.hpp"
#include "./int.hpp"
#include "./string.hpp"
#include "./type.hpp"

namespace dataObject
{
    int len(DataObject &data);
    String type(DataObject &data);
}

#endif