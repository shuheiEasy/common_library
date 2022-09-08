#ifndef LOG_CORE_H
#define LOG_CORE_H

#include <stdarg.h>
#include <dataObject/dataObject.hpp>
#include <fileSystem/fileSystem.hpp>

namespace logSystem
{
    // 関数
    template <class... Args>
    void print(Args &...args);
    void fprint(const dataObject::String &format, ...);
    void fprint(const char *format, ...);
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

    class PrintSystem
    {
    private:
        template <class T>
        void _convertTypes(dataObject::String &text, const T &data);
        void _extractStr(dataObject::String &text) {}
        template <class... TailClass>
        void _extractStr(dataObject::String &text, const dataObject::DataObject &head, TailClass &...tail);
        template <class... TailClass>
        void _extractStr(dataObject::String &text, const int &head, TailClass &...tail);
        template <class... TailClass>
        void _extractStr(dataObject::String &text, const float &head, TailClass &...tail);
        template <class... TailClass>
        void _extractStr(dataObject::String &text, const double &head, TailClass &...tail);
        template <class... TailClass>
        void _extractStr(dataObject::String &text, const char *head, TailClass &...tail);

    public:
        template <class... Args>
        PrintSystem(const Args &...args);
        ~PrintSystem() {}
    };

}

#endif