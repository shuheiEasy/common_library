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

    template <class T>
    void PrintSystem::_convertTypes(T &data)
    {
        _text_list->append(dataObject::String(data));
    }

    template <class... TailClass>
    void PrintSystem::_extractStr(dataObject::DataObject &&head, TailClass &...tail)
    {
        _text_list->append(dataObject::String(head.getLog()));
        _extractStr(tail...);
    }
    template <class... TailClass>
    void PrintSystem::_extractStr(const dataObject::DataObject &head, TailClass &...tail)
    {
        _text_list->append(dataObject::String(head.getLog()));
        _extractStr(tail...);
    }

    template <class... TailClass>
    void PrintSystem::_extractStr(const int &head, TailClass &...tail)
    {
        _convertTypes(head);
        _extractStr(tail...);
    }

    template <class... TailClass>
    void PrintSystem::_extractStr(const float &head, TailClass &...tail)
    {
        _convertTypes(head);
        _extractStr(tail...);
    }
    template <class... TailClass>
    void PrintSystem::_extractStr(const double &head, TailClass &...tail)
    {
        _convertTypes(head);
        _extractStr(tail...);
    }
    template <class... TailClass>
    void PrintSystem::_extractStr(const char *head, TailClass &...tail)
    {
        _convertTypes(head);
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