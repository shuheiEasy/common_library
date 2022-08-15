#ifndef LIST_EX_H
#define LIST_EX_H

#include "./list.hpp"
#include "./string.hpp"

namespace dataObject
{
    template <>
    class Type<String>
    {
        public:
        ClassType class_id;
        Type(){class_id = DATATYPE_CLASS;}
    };
}
#endif