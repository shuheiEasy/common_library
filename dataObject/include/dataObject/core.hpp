#ifndef CORE_H
#define CORE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define LANGUAGECODE "ja_JP.UTF-8"

namespace dataObject
{
    class DataObject
    {
    public:
        virtual const char *getType() const { return "DataObject"; }
        virtual int getSize() const { return 0; }
        virtual const char *getLog() const { return "None"; }
    };

    enum ClassType
    {
        ANYTYPE_CLASS = -1,
        NONETYPE_CLASS = 0,
        DATATYPE_CLASS = 100,
        LISTTYPE_CLASS
    };

    template <class TYPE>
    class Type
    {
    public:
        ClassType class_id;
        Type() { class_id = ANYTYPE_CLASS; }
    };
}

#endif