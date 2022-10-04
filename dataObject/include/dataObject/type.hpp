/**
 * @file type.hpp
 * @author iijima-robot
 * @brief typeクラスを実装するヘッダファイル
 * @date 2022-09-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef COMMON_DATAOBJECT_LIST_EX_H
#define COMMON_DATAOBJECT_LIST_EX_H

#include <dataObject/bool.hpp>
#include <dataObject/int.hpp>
#include <dataObject/float.hpp>
#include <dataObject/double.hpp>
#include <dataObject/list.hpp>
#include <dataObject/string.hpp>

namespace dataObject
{
    /// @cond
    // 型判定
    template <class T>
    class Type<List<T>>
    {
    public:
        ClassType class_id;
        Type() { class_id = LISTTYPE_CLASS; }
    };
    /// @endcond

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