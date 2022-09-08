#ifndef LOG_CORE_H
#define LOG_CORE_H

#include <stdarg.h>
#include <dataObject/dataObject.hpp>
#include <fileSystem/fileSystem.hpp>

namespace logSystem
{
    enum LogLevel
    {
        NOTSET = 0,
        DEBUG = 10,
        INFO = 20,
        WARNING = 30,
        ERROR = 40,
        CRITICAL = 50
    };

    // 関数
    template <class... Args>
    void print(Args &...args);
    void fprint(const dataObject::String &format, ...);
    void fprint(const char *format, ...);
    void _vprint(const dataObject::String &format, va_list args);
    dataObject::String logLevel_str(LogLevel level);

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
        void setLevel(LogLevel log_level);
        int print(LogLevel log_level, const dataObject::String &format, ...);
        template <class... Args>
        void test(LogLevel log_level, Args &...args);
    };

    class PrintSystem
    {
    private:
        dataObject::List<dataObject::String> *_text_list;
        template <class T>
        void _convertTypes(const T &data);
        void _extractStr() {}
        template <class... TailClass>
        void _extractStr(const dataObject::DataObject &head, TailClass &...tail);
        template <class... TailClass>
        void _extractStr(const int &head, TailClass &...tail);
        template <class... TailClass>
        void _extractStr(const float &head, TailClass &...tail);
        template <class... TailClass>
        void _extractStr(const double &head, TailClass &...tail);
        template <class... TailClass>
        void _extractStr(const char *head, TailClass &...tail);

    public:
        template <class... Args>
        PrintSystem(const Args &...args);
        ~PrintSystem() { delete _text_list; }
        void print(void);
    };

}

#endif