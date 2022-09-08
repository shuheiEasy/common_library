#include <logSystem/core.hpp>

#ifndef PRINT_IMPL_H
#define PRINT_IMPL_H

namespace logSystem
{
    template <class... Args>
    void logSystem::print(const Args &...args)
    {
        PrintSystem p(args...);
    }

    template <class T>
    void PrintSystem::_convertTypes(dataObject::String &text, const T &data)
    {
        text += dataObject::String(data);
    }

    template <class... TailClass>
    void PrintSystem::_extractStr(dataObject::String &text, const dataObject::DataObject &head, TailClass &...tail)
    {
        text += dataObject::String(head.getLog());
        _extractStr(text, tail...);
    }

    template <class... TailClass>
    void PrintSystem::_extractStr(dataObject::String &text, const int &head, TailClass &...tail)
    {
        _convertTypes(text, head);
        _extractStr(text, tail...);
    }

    template <class... TailClass>
    void PrintSystem::_extractStr(dataObject::String &text, const float &head, TailClass &...tail)
    {
        _convertTypes(text, head);
        _extractStr(text, tail...);
    }
    template <class... TailClass>
    void PrintSystem::_extractStr(dataObject::String &text, const double &head, TailClass &...tail)
    {
        _convertTypes(text, head);
        _extractStr(text, tail...);
    }
    template <class... TailClass>
    void PrintSystem::_extractStr(dataObject::String &text, const char *head, TailClass &...tail)
    {
        _convertTypes(text, head);
        _extractStr(text, tail...);
    }
    template <class... Args>
    PrintSystem::PrintSystem(const Args &...args)
    {
        dataObject::String text = "";
        _extractStr(text, args...);
        printf("%s\n", text.getChar());
    }
}
#endif