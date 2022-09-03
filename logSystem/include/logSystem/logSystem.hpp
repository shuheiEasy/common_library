#ifndef LOGSYS_H
#define LOGSYS_H

#include <stdarg.h>
#include <dataObject/dataObject.hpp>
#include <fileSystem/fileSystem.hpp>

namespace logSystem
{
    // 関数
    void print(const dataObject::String &format, ...);
    void print(const char *format, ...);

    class LogSystem
    {
    private:
        fileSystem::File *file;

    public:
        LogSystem();
        ~LogSystem();
    };

}

#endif