/**
 * @file dict.hpp
 * @author iijima-robot
 * @brief Dictクラスを宣言するヘッダファイル
 * @date 2022-10-10
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef COMMON_DATAOBJECT_DICT_IMPL_H
#define COMMON_DATAOBJECT_DICT_IMPL_H

#include <dataObject/dict.hpp>

namespace dataObject
{
    template <class K_T, class V_T>
    Dict<K_T, V_T>::Dict(const Dict<K_T, V_T> &dict)
    {
    }

    template <class K_T, class V_T>
    void Dict<K_T, V_T>::clear()
    {
        _key_list.clear();
        _value_list.clear();
    }

    template <class K_T, class V_T>
    void Dict<K_T, V_T>::del(const K_T &key)
    {
        int del_id = -1;
        for (int i = 0; i < _key_list.getSize(); i++)
        {
            if (_key_list[i] == key)
            {
                del_id = i;
                break;
            }
        }

        if (del_id > -1)
        {
            _key_list.del(del_id);
            _value_list.del(del_id);
        }
    }

    template <class K_T, class V_T>
    int Dict<K_T, V_T>::getSize() const
    {
        return _key_list.getSize();
    }

    template <class K_T, class V_T>
    const char *Dict<K_T, V_T>::getType() const
    {
        return "Dict";
    }

    template <class K_T, class V_T>
    void Dict<K_T, V_T>::update(const K_T &key, const V_T &value)
    {
        // 同じ名前が登録されていないか判定
        int add_id = -1;
        for (int i = 0; i < _key_list.getSize(); i++)
        {
            if (_key_list[i] == key)
            {
                add_id = i;
                break;
            }
        }

        if (add_id < 0)
        {
            _key_list.append(key);
            _value_list.append(value);
        }
        else
        {
            _value_list[add_id] = value;
        }
    }
}

#endif