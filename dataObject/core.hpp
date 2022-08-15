#ifndef CORE_H
#define CORE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

namespace dataObject
{
    class DataObject
    {
    public:
        virtual const char *getType() const = 0;
        virtual int getSize() const = 0;
        virtual const char *getLog() const = 0;
    };

    enum ClassType
    {
        ANYTYPE_CLASS = -1,
        DATATYPE_CLASS = 0,
        NONETYPE_CLASS
    };

    template <class TYPE>
    class Type
    {
        public:
        ClassType class_id;
        Type(){class_id = ANYTYPE_CLASS;}
    };
}

#endif