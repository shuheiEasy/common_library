#ifndef LIST_EX_H
#define LIST_EX_H

#include <dataObject/bool.hpp>
#include <dataObject/int.hpp>
#include <dataObject/float.hpp>
#include <dataObject/double.hpp>
#include <dataObject/list.hpp>
#include <dataObject/string.hpp>

namespace dataObject
{
    // 型判定
    template <class T>
    class Type<List<T>>
    {
    public:
        ClassType class_id;
        Type() { class_id = LISTTYPE_CLASS; }
    };

    template <class T>
    const char *List<T>::getLog() const
    {
        _Node<T> *ptr = _head->next;
        String ret = "[ ";

        while (ptr != _tail)
        {
            String tmp = toString(ptr->data);

            if (ptr != _head->next)
            {
                ret += ", ";
            }
            ret += tmp;
            ptr = ptr->next;
        }

        ret += " ]";

        return ret.getChar();
    }
}
#endif