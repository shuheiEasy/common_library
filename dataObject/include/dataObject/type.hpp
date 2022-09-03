#ifndef LIST_EX_H
#define LIST_EX_H

#include <dataObject/list.hpp>
#include <dataObject/string.hpp>

namespace dataObject
{
    // 型判定
    template <>
    class Type<String>
    {
    public:
        ClassType class_id;
        Type() { class_id = DATATYPE_CLASS; }
    };

    template <class T>
    class Type<List<T>>
    {
    public:
        ClassType class_id;
        Type() { class_id = DATATYPE_CLASS; }
    };

    template <class T>
    const char *List<T>::getLog() const
    {
        Type<T> buf;
        ClassType check = buf.class_id;
        if (check == DATATYPE_CLASS)
        {
            Node<T> *ptr = _data;
            String ret = "[ ";

            while (ptr != _tail)
            {
                String tmp = toString(ptr->data);

                if (ptr != _data)
                {
                    ret += ", ";
                }
                ret += tmp;
                ptr = ptr->next;
            }

            ret += " ]";

            return ret.getChar();
        }

        return "";
    }
}
#endif