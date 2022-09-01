#include <logSystem.hpp>

using namespace logSystem;
using namespace dataObject;

LogSystem::LogSystem()
{
}

LogSystem::~LogSystem()
{
    delete file;
}

void LogSystem::print(const String &format, ...)
{
    // 変数
    String format_str=format;
    List<String> format_list;
    va_list args;

    // // 引数取得
    va_start(args, format);

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

    va_end(args);
}

void LogSystem::print(const char *format_char, ...)
{
    // 変数
    String format=format_char;
    List<String> format_list;
    va_list args;

    // 引数取得
    va_start(args, format_char);

    // 構文分析
    format_list = format.split("%s");
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

    va_end(args);
}