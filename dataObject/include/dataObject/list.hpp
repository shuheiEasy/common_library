/**
 * @file list.hpp
 * @author iijima-robot
 * @brief Listクラスを宣言するヘッダファイル
 * @date 2022-09-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef COMMON_DATAOBJECT_LIST_H
#define COMMON_DATAOBJECT_LIST_H

#include <dataObject/core.hpp>

namespace dataObject
{
    /**
     * @brief 可変長リスト
     *
     * @tparam T リストに格納するデータの型
     */
    template <class T>
    class List : public None
    {
    private:
        /**
         * @brief リストの各要素を格納する構造体
         * @tparam DATATYPE 格納するデータの型
         *
         */
        template <class DATATYPE>
        struct _Node
        {
            DATATYPE *data;
            _Node *prev;
            _Node *next;
        };

        // メンバ変数

        // データの先頭
        _Node<T> *_head;
        _Node<T> *_tail;

        // メモリー削除
        void _del(_Node<T> *start, _Node<T> *end);
        // 解放
        void _free();
        // 初期化
        void _init();
        // メモリー確保
        void _malloc(_Node<T> *&tmp, _Node<T> *&prev, _Node<T> *&next);
        // メモリー確保(ラッパー関数)
        void _new(_Node<T> *prev, int memory_size = 1);
        // 探索
        void _search(_Node<T> *&ptr, int id) const;

    public:
        /// @brief リストへデータを追加する関数
        /// @param data 追加するデータ
        void append(const T &data);
        /// @brief データのポインターを取得する関数
        /// @param id 要素番号
        /// @return [データの型] データを指すポインタ
        T *at(int id);
        /// @brief リストを空にする関数
        void clear();
        /// @brief リスト内にある条件に合うデータの数を計測する関数
        /// @param data 計測したいデータ
        /// @return [int] データ数
        int count(const T &data);
        /// @brief 指定したデータをリストから削除する関数
        /// @param start 削除する要素番号
        void del(int start);
        /// @brief 指定したデータをリストから削除する関数
        /// @param start 削除する要素番号の先頭
        /// @param end 削除する要素番号の末尾
        void del(int start, int end);
        /// @brief リストを拡張する関数
        /// @param list 格納するリスト
        void extend(const List<T> &list);
        /// @brief データ取得する関数
        /// @note データを取得する関数であるため、リスト内のデータの変更はできない
        /// @param id 取得したいデータの要素番号
        /// @return [データの型] 取得したデータ
        T get(int id) const;
        const char *getLog() const;
        int getSize() const;
        const char *getType() const;
        /// @brief 要素の位置取得
        /// @param data 取得したいデータ
        /// @param count 取得する回数（初期値：１）
        int index(const T &data, int count = 1);
        /// @brief 要素を挿入する関数
        /// @param id 挿入する要素番号
        /// @param data 挿入するデータ
        void insert(const int id, const T &data);
        /// @brief コンストラクタ
        List() { _init(); }
        /// @brief コンストラクタ
        /// @param list 代入するリスト
        List(const List<T> &list);
        /// @brief デコンストラクタ
        ~List() { _free(); }
        /// @brief オペレータ(添字演算子)
        /// @param id 要素番号
        T &operator[](const int id);
        /// @brief オペレータ(代入演算子)
        /// @param list 代入するリスト
        /// @return [List] データが代入されたリスト
        List<T> &operator=(const List<T> &list);
        /// @brief オペレータ(複合代入演算子)
        /// @param data 追加するデータ
        /// @return [List] データが追加されたリスト
        List<T> &operator+=(const T &data);
        /// @brief オペレータ(複合代入演算子)
        /// @param list 追加するリスト
        /// @return [List] データが追加されたリスト
        List<T> &operator+=(const List<T> &list);
        /// @brief スライス
        /// @param start 取得する要素の先頭の要素番号
        /// @param length 取得する要素数
        /// @return [List] スライスしたリスト
        List<T> slice(int start, int length);
    };
}

#endif