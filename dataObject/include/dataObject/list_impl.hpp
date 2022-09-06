#ifndef LIST_IMPL_H
#define LIST_IMPL_H

#include <dataObject/list.hpp>

namespace dataObject
{
    template <class T>
    void List<T>::_del(_Node<T> *start, _Node<T> *end)
    {
        // 消去領域の直前のポインター
        _Node<T> *prev;
        if (start == _head)
        {
            prev = _head;
        }
        else
        {
            prev = start->prev;
        }
        // 消去領域の直後のポインター
        _Node<T> *next;
        if (end == _tail)
        {
            next = _tail;
        }
        else
        {
            next = end->next;
        }

        // 消去
        _Node<T> *ptr = prev->next;
        while (ptr != _tail)
        {
            // 取得
            _Node<T> *tmp = ptr;
            ptr = ptr->next;

            // 消去
            if (tmp->data != NULL)
            {
                delete tmp->data;
            }
            delete tmp;

            // 終端
            if (ptr == next)
            {
                break;
            }
        }

        // 後始末
        prev->next = next;
        next->prev = prev;
    }
    template <class T>
    void List<T>::_free()
    {
        // 中身削除
        _del(_head, _tail);

        // 頭としっぽを削除
        delete _head;
        delete _tail;
    }

    template <class T>
    void List<T>::_init()
    {
        // _Nodeポインターの初期化
        _head = new _Node<T>();
        _tail = new _Node<T>();
        _head->data = NULL;
        _head->prev = NULL;
        _head->next = _tail;
        _tail->data = NULL;
        _tail->prev = _head;
        _tail->next = NULL;
    }

    template <class T>
    void List<T>::_malloc(_Node<T> *&tmp, _Node<T> *&prev, _Node<T> *&next)
    {
        tmp = new _Node<T>();
        tmp->data = NULL;
        tmp->prev = prev;
        tmp->next = next;
        prev->next = tmp;
        next->prev = tmp;
    }

    template <class T>
    void List<T>::_new(_Node<T> *prev, int memory_size)
    {
        // 追加領域の直後のポインター
        _Node<T> *next;
        if (prev == _tail)
        {
            next = _tail;
        }
        else
        {
            next = prev->next;
        }

        // メモリー確保
        _Node<T> *ptr = prev;
        for (int i = 0; i < memory_size; i++)
        {
            _Node<T> *tmp;
            _malloc(tmp, ptr, next);
            ptr = tmp;
        }
    }

    template <class T>
    void List<T>::_search(_Node<T> *&ptr, int id) const
    {
        if (id < 0)
        {
            ptr = _tail;
            for (int i = id; i < 0; ++i)
            {
                ptr = ptr->prev;
                // 安全装置
                if (ptr == _head)
                {
                    break;
                }
            }
        }
        else
        {
            ptr = _head;
            for (int i = 0; i < id + 1; i++)
            {
                ptr = ptr->next;
                // 安全装置
                if (ptr == _tail)
                {
                    break;
                }
            }
        }
    }

    template <class T>
    void List<T>::append(const T &data)
    {
        _new(_tail->prev);
        _Node<T> *ptr;
        _search(ptr, -1);
        ptr->data = new T(data);
    }

    template <class T>
    T *List<T>::at(int id)
    {
        _Node<T> *ptr;
        _search(ptr, id);
        return ptr->data;
    }

    template <class T>
    void List<T>::clear()
    {
        this->_del(_head, _tail);
    }

    template <class T>
    void List<T>::del(int start)
    {
        this->del(start, start);
    }

    template <class T>
    void List<T>::del(int start, int end)
    {
        _Node<T> *start_ptr;
        _Node<T> *end_ptr;
        int start_pos = start;
        int end_pos = end;
        if (start_pos > end_pos)
        {
            start_pos = end;
            end_pos = start;
        }
        _search(start_ptr, start_pos);
        _search(end_ptr, end_pos);

        this->_del(start_ptr, end_ptr);
    }

    template <class T>
    void List<T>::extend(const List<T> &list)
    {
        // 確保位置
        _Node<T> *ptr = _tail->prev;
        //メモリ確保
        _new(ptr, list.getSize());
        // データ代入
        ptr = ptr->next;
        int id = 0;
        while (ptr != _tail)
        {
            ptr->data = new T(list.get(id));
            ptr = ptr->next;
            id++;
        }
    }

    template <class T>
    T List<T>::get(int id) const
    {
        _Node<T> *ptr;
        _search(ptr, id);
        return *(ptr->data);
    }

    template <class T>
    int List<T>::getSize() const
    {
        int ret = 0;
        _Node<T> *ptr = _head->next;
        while (ptr != _tail)
        {
            ptr = ptr->next;
            ret++;
        }
        return ret;
    }

    template <class T>
    const char *List<T>::getType() const { return "List"; }

    template <class T>
    void List<T>::insert(const int id, const T &data)
    {
        // 挿入直前のポインター取得
        _Node<T> *ptr;
        _search(ptr, id);
        if (id >= 0)
        {
            if (ptr != _head)
            {
                ptr = ptr->prev;
            }
        }

        // メモリ確保
        _new(ptr);

        // 代入
        _Node<T> *insert_ptr = ptr->next;
        insert_ptr->data = new T(data);
    }

    template <class T>
    T &List<T>::operator[](const int id)
    {
        return *(this->at(id));
    }

    template <class T>
    List<T> &List<T>::operator=(const List<T> &list)
    {
        // 全削除
        clear();
        // 拡張
        extend(list);
        return *this;
    }

    template <class T>
    List<T> &List<T>::operator+=(const T &data)
    {
        this->append(data);
        return *this;
    }
    template <class T>
    List<T> &List<T>::operator+=(const List<T> &list)
    {
        this->extend(list);
        return *this;
    }

    template <class T>
    List<T>::List(const List<T> &list)
    {
        // 初期化
        _init();
        // 拡張
        extend(list);
    }
}
#endif