#include <logSystem.hpp>

using namespace logSystem;
using namespace dataObject;
using namespace fileSystem;

LogSystem::LogSystem()
{
    _init();
}

LogSystem::LogSystem(const char *file_name)
{
    _init();
    setFile(file_name);
}

LogSystem::~LogSystem()
{
    if (_file != NULL)
    {
        delete _file;
    }
}

void LogSystem::setFile(const char *file_name)
{
    _file = new TextFile(file_name);
}

int LogSystem::print(LogLevel log_level, const dataObject::String &format, ...)
{
    if (log_level <= _log_level)
    {
        return -1;
    }

    String print_fromat = "[";
    switch (log_level)
    {
    case NOTSET:
        print_fromat += "NOTSET";
        break;
    case DEBUG:
        print_fromat += "DEBUG";
        break;
    case INFO:
        print_fromat += "INFO";
        break;
    case WARNING:
        print_fromat += "WARNING";
        break;
    case ERROR:
        print_fromat += "ERROR";
        break;
    case CRITICAL:
        print_fromat += "CRITICAL";
        break;
    default:
        print_fromat += "CUSTOM";
        break;
    }
    print_fromat += "] ";
    print_fromat += format;

    va_list args;
    va_start(args, format);
    logSystem::_vprint(print_fromat, args);
    va_end(args);

    return 0;
}

void logSystem::print(const String &format, ...)
{
    // 変数
    va_list args;

    // 引数取得
    va_start(args, format);

    // 出力
    _vprint(format, args);

    // 解析終了
    va_end(args);
}

void logSystem::print(const char *format_char, ...)
{
    // 変数
    va_list args;

    // 引数取得
    va_start(args, format_char);

    // 出力
    _vprint(String(format_char), args);

    // 解析終了
    va_end(args);
}

void logSystem::_vprint(const String &format, va_list args)
{
    // 変数
    String format_str = format;
    List<String> format_list;

    // // 構文分析
    format_list = format_str.split("%s");
    String print_text = "";

    // 出力文作成
    for (int i = 0; i < format_list.getSize() - 1; i++)
    {
        print_text += format_list[i];
        print_text += va_arg(args, DataObject).getLog();
    }
    print_text += format_list[-1];

    // 出力
    printf("%s", print_text.getChar());
}

/////////////////////////////////////////////////
//
// private
//
/////////////////////////////////////////////////

void LogSystem::_init()
{
    _file = NULL;
    _log_level = WARNING;
}