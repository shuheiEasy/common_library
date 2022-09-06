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
    void _vprint(const dataObject::String &format, va_list args);

    enum LogLevel
    {
        NOTSET = 0,
        DEBUG = 10,
        INFO = 20,
        WARNING = 30,
        ERROR = 40,
        CRITICAL = 50
    };

    class LogSystem
    {
    private:
        fileSystem::File *_file;
        LogLevel _log_level;

        // メゾット
        void _init();

    public:
        LogSystem();
        LogSystem(const char *file_name);
        ~LogSystem();
        void setFile(const char *file_name);
        int print(LogLevel log_level, const dataObject::String &format, ...);
    };

}

#endif