/**
 * @file print.hpp
 * @author iijima-robot
 * @brief リストクラスおよび辞書クラスの出力を実装するヘッダファイル
 * @date 2022-09-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef COMMON_DATAOBJECT_PRINT_H
#define COMMON_DATAOBJECT_PRINT_H

#include <dataObject/list.hpp>
#include <dataObject/string.hpp>
#include <dataObject/dict_impl.hpp>

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

    template <class K_T, class V_T>
    const char *Dict<K_T, V_T>::getLog() const
    {
        String ret = "{ ";

        for(int i = 0; i < _key_list.getSize(); i++){
            if(i != 0){
                ret += ", ";
            }            
            K_T key = _key_list.get(i);
            V_T value = _value_list.get(i);
            ret += toString(key);
            ret += ": ";
            ret += toString(value);
        }

        ret += " }";

        return ret.getChar();
    }
}
#endif