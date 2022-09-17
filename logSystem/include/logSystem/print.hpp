#include <logSystem/core.hpp>

#ifndef PRINT_IMPL_H
#define PRINT_IMPL_H

namespace logSystem
{
    template <class... Args>
    void logSystem::print(const Args &...args)
    {
        PrintSystem p(args...);
        p.print();
    }

    template <class... Args>
    void LogSystem::print(LogLevel log_level, Args &&...args)
    {
        _setLoglevelText(log_level);
        PrintSystem p(args...);
        dataObject::String print_text = _generatePrintText(p.getPrintStr());

        printf("%s", print_text.getLog());
    }

    template <class HeadClass, class... TailClass>
    void PrintSystem::_extractStr(const HeadClass &head, TailClass &...tail)
    {
        _text_list->append(dataObject::toString(head));
        _extractStr(tail...);
    }

    template <class... Args>
    PrintSystem::PrintSystem(const Args &...args)
    {
        _text_list = new dataObject::List<dataObject::String>();
        _extractStr(args...);
    }
}
#endif