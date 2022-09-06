#ifndef TEST_H
#define TEST_H

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
    class Vector : public None
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
        // 削除
        void del(int start);
        // 削除
        void del(int start, int end);
        // 拡張
        void extend(const Vector<T> &list);
        // データ取得
        T get(int id) const;
        // サイズ取得
        int getSize() const;
        // 形式取得
        const char *getType() const;
        // オペレータ(添字演算子)
        T &operator[](const int id);
        // オペレータ(代入演算子)
        Vector<T> &operator=(const Vector<T> &list);
        // オペレータ(複合代入演算子)
        Vector<T> &operator+=(const T &data);
        Vector<T> &operator+=(const Vector<T> &list);
        // コンストラクタ
        Vector() { _init(); }
        Vector(const Vector<T> &list);
        ~Vector() { _free(); }
    };
}

#endif