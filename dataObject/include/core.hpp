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
    protected:
        const int _MEMORY_SIZE = 4;

    public:
        virtual const char *getType() const = 0;
        virtual int getSize() const = 0;
    };
}

#endif