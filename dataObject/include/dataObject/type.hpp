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
    template <>
    class Type<Bool>
    {
    public:
        ClassType class_id;
        Type() { class_id = DATATYPE_CLASS; }
    };

    template <>
    class Type<Int>
    {
    public:
        ClassType class_id;
        Type() { class_id = DATATYPE_CLASS; }
    };

    template <>
    class Type<Float>
    {
    public:
        ClassType class_id;
        Type() { class_id = DATATYPE_CLASS; }
    };

    template <>
    class Type<Double>
    {
    public:
        ClassType class_id;
        Type() { class_id = DATATYPE_CLASS; }
    };

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
            _Node<T> *ptr = _head->next;
            String ret = "[ ";

            while (ptr != _tail)
            {
                String tmp = toString(ptr->data->getLog());

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

        return "";
    }
}
#endif