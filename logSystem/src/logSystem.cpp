#include <logSystem/logSystem.hpp>

using namespace logSystem;
using namespace dataObject;
using namespace fileSystem;

/////////////////////////////////////////////////
//
// 関数
//
/////////////////////////////////////////////////

void logSystem::fprint(const String &format, ...)
{
    // 変数
    va_list args;

    // 引数取得
    va_start(args, format);

    // 出力
    String print_text = _vprint(format, args);

    // 解析終了
    va_end(args);

    // 出力
    printf("%s\n", print_text.getChar());
}

void logSystem::fprint(const char *format_char, ...)
{
    // 変数
    va_list args;

    // 引数取得
    va_start(args, format_char);

    // 出力
    String print_text = _vprint(String(format_char), args);

    // 解析終了
    va_end(args);

    // 出力
    printf("%s\n", print_text.getChar());
}

dataObject::String logSystem::_vprint(const String &format, va_list args)
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

    return print_text;
}

String logSystem::logLevel_str(LogLevel level)
{
    String ret = "";
    switch (level)
    {
    case NOTSET:
        ret += "NOTSET";
        break;
    case DEBUG:
        ret += "DEBUG";
        break;
    case INFO:
        ret += "INFO";
        break;
    case WARNING:
        ret += "WARNING";
        break;
    case ERROR:
        ret += "ERROR";
        break;
    case CRITICAL:
        ret += "CRITICAL";
        break;
    default:
        ret += "CUSTOM";
        break;
    }
    return ret;
}
/////////////////////////////////////////////////
//
// LogSystem
//
/////////////////////////////////////////////////
/////////////////////////////////////////////////
//
// public
//
/////////////////////////////////////////////////
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

void LogSystem::setFormat(const char *format)
{
    _formatter.setFormat(format);
}

void LogSystem::setFormat(const dataObject::String &format)
{
    _formatter.setFormat(format);
}

void LogSystem::setLevel(LogLevel log_level)
{
    _log_level = log_level;
}

int LogSystem::fprint(LogLevel log_level, const dataObject::String &format, ...)
{
    if (log_level <= _log_level)
    {
        return -1;
    }

    _setLoglevelText(log_level);

    va_list args;
    va_start(args, format);
    String print_text = _generatePrintText(logSystem::_vprint(format, args));
    va_end(args);

    printf("%s", print_text.getChar());

    return 0;
}

/////////////////////////////////////////////////
//
// private
//
/////////////////////////////////////////////////
String LogSystem::_generatePrintText(dataObject::String &&msg)
{
    _formatter.setData("message", msg.getChar());
    _datetime.now();
    _formatter.setData("year", String(_datetime.year()));
    _formatter.setData("month", String(_datetime.month()));
    _formatter.setData("day", String(_datetime.day()));
    _formatter.setData("hour", String(_datetime.hour()));
    _formatter.setData("min", String(_datetime.minute()));
    _formatter.setData("sec", String(_datetime.second()));
    _formatter.setData("msec", String(_datetime.millisec()));
    return _formatter.generateText();
}

void LogSystem::_init()
{
    _file = NULL;
    _log_level = WARNING;
    setFormat("${year}-${month:02}-${day:02} ${hour:02}:${min:02}:${sec:02},${msec:03} [${levelname}] ${message}\n");
}

void LogSystem::_setLoglevelText(LogLevel log_level)
{
    _formatter.setData("levelname", logLevel_str(log_level));
}

/////////////////////////////////////////////////
//
// PrintSystem
//
/////////////////////////////////////////////////

dataObject::String PrintSystem::getPrintStr()
{
    String print_text = "";
    for (int i = 0; i < _text_list->getSize(); i++)
    {
        print_text += _text_list->get(i);
    }
    return print_text;
}

void PrintSystem::print()
{
    String print_text = getPrintStr();
    printf("%s\n", print_text.getLog());
}