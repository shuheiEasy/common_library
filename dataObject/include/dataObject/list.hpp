#ifndef LIST_H
#define LIST_H

#include <dataObject/core.hpp>

namespace dataObject
{
    template <class DATATYPE>
    struct _Node
    {
        DATATYPE *data;
        _Node *prev;
        _Node *next;
    };

    template <class T>
    class List : public None
    {
    private:
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
        // データの追加
        void append(const T &data);
        // データのポインター取得
        T *at(int id);
        // 全削除
        void clear();
        // 計測
        // int count(const T &data);
        // 削除
        void del(int start);
        // 削除
        void del(int start, int end);
        // 拡張
        void extend(const List<T> &list);
        // データ取得
        T get(int id) const;
        // 出力
        const char *getLog() const;
        // サイズ取得
        int getSize() const;
        // 形式取得
        const char *getType() const;
        // 要素の位置取得
        // int index(const T &data);
        // 挿入
        void insert(const int id, const T &data);
        // コンストラクタ
        List() { _init(); }
        List(const List<T> &list);
        ~List() { _free(); }
        // オペレータ(添字演算子)
        T &operator[](const int id);
        // オペレータ(代入演算子)
        List<T> &operator=(const List<T> &list);
        // オペレータ(複合代入演算子)
        List<T> &operator+=(const T &data);
        List<T> &operator+=(const List<T> &list);
        // スライス
        // List<T> slice(int start, int end);
    };
}

#endif