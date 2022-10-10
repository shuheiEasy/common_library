/**
 * @file dict.hpp
 * @author iijima-robot
 * @brief Dictクラスを宣言するヘッダファイル
 * @date 2022-10-10
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef COMMON_DATAOBJECT_DICT_H
#define COMMON_DATAOBJECT_DICT_H

#include <dataObject/core.hpp>
#include <dataObject/list_impl.hpp>

namespace dataObject
{
    /// @brief 辞書型クラス
    /// @tparam K_T Keyの型
    /// @tparam V_T Valueの型
    template <class K_T, class V_T>
    class Dict : public DataObject
    {
    private:
        List<K_T> _key_list;
        List<V_T> _value_list;

    public:
        Dict(){}
        Dict(const Dict<K_T, V_T> &dict);
        
        void clear();
        void del(const K_T &key);
        const char *getLog() const;
        int getSize() const;
        const char *getType() const;
        void update(const K_T &key, const V_T &value);
    };
}
#endif