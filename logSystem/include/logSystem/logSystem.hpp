#ifndef LOGSYS_H
#define LOGSYS_H

#include <stdarg.h>
#include <dataObject/dataObject.hpp>
#include <fileSystem/fileSystem.hpp>

namespace logSystem
{
    class LogSystem
    {
    private:
        fileSystem::File *file;

    public:
        LogSystem();
        ~LogSystem();
        void print(const dataObject::String &format, ...);
        void print(const char* format, ...);
    };

    

}

#endif