#ifndef LIST_H
#define LIST_H

#include "./core.hpp"

namespace dataObject
{

    template <class DATATYPE>
    struct Node
    {
        DATATYPE data;
        Node *prev;
        Node *next;
    };

    template <class T>
    class List : public DataObject
    {
    private:
        Node<T> *_data;
        Node<T> *_tail;
        int _length;
        inline void _append(Node<T> *n_ptr, Node<T> **tail, T &data)
        {
            Node<T> *tmp = (Node<T> *)malloc(sizeof(Node<T>));

            if (tmp != NULL)
            {
                tmp->data = data;
                tmp->next = _tail;
                tmp->prev = n_ptr;
                n_ptr->next = tmp;
                _tail->prev = tmp;
                _length++;
            }
            else
            {
                printf("失敗\n");
            }
        }
        inline T *_at(int id)
        {
            if (id < _length)
            {
                Node<T> *ptr;
                if (id < 0)
                {
                    ptr = _get_ptr(id - 1);
                }
                else
                {
                    ptr = _get_ptr(id);
                }
                return &(ptr->data);
            }
            return NULL;
        }
        inline int _del(int start, int length)
        {
            // 長過ぎるとき
            if (length >= _length)
            {
                _free();
                return -1;
            }

            // 削除開始地点
            Node<T> *remove_node;
            if (start < 0)
            {
                remove_node = _get_ptr(start - 1);
            }
            else
            {
                remove_node = _get_ptr(start);
            }

            // 削除
            if (remove_node != _data)
            {
                Node<T> *p_ptr = remove_node->prev;
                Node<T> *n_ptr = remove_node;
                for (int i = 0; i < length; i++)
                {
                    Node<T> *tmp = n_ptr;
                    n_ptr = n_ptr->next;
                    if (n_ptr == _tail)
                    {
                        p_ptr->next = _tail;
                        _tail->prev = p_ptr;
                        _length--;
                        free(tmp);
                        break;
                    }
                    else
                    {
                        p_ptr->next = n_ptr;
                        n_ptr->prev = p_ptr;
                        _length--;
                        free(tmp);
                    }
                }
            }
            else
            {
                Node<T> *n_ptr = remove_node;
                for (int i = 0; i < length; i++)
                {
                    Node<T> *tmp = n_ptr;
                    n_ptr = n_ptr->next;
                    free(tmp);
                    _length--;
                }
                _data = n_ptr;
            }
            return 0;
        }
        inline Node<T> *_get_ptr(int id)
        {
            Node<T> *ptr;
            if (id < 0)
            {
                ptr = _tail;
                for (int i = -1; i > id; i--)
                {
                    // 安全装置
                    if (ptr->prev == NULL)
                    {
                        break;
                    }
                    ptr = ptr->prev;
                }
            }
            else
            {
                ptr = _data;
                for (int i = 0; i < id; i++)
                {
                    // 安全装置
                    if (ptr->next == NULL)
                    {
                        break;
                    }
                    ptr = ptr->next;
                }
            }
            return ptr;
        }
        inline void _insert(Node<T> *ptr, T &data)
        {
            Node<T> *tmp = (Node<T> *)malloc(sizeof(Node<T>));
            if (tmp != NULL)
            {
                tmp->data = data;

                if (ptr == _data)
                {
                    tmp->next = ptr;
                    tmp->prev = NULL;
                    ptr->prev = tmp;
                    _data = tmp;
                }
                else
                {
                    tmp->next = ptr;
                    tmp->prev = ptr->prev;
                    ptr->prev = tmp;
                    Node<T> *p_ptr = tmp->prev;
                    p_ptr->next = tmp;
                }

                _length++;
            }
            else
            {
                printf("失敗\n");
            }
        }
        inline void _malloc(T &data)
        {
            _data = (Node<T> *)malloc(sizeof(Node<T>));
            _tail = (Node<T> *)malloc(sizeof(Node<T>));

            if ((_data != NULL) && (_tail != NULL))
            {

                _data->data = data;
                _data->prev = NULL;
                _data->next = _tail;
                _tail->prev = _data;
                _tail->next = NULL;

                _length++;
            }
        }
        inline void _free()
        {
            if (_length > 0)
            {
                Node<T> *ptr = _tail;
                while (ptr != _data)
                {
                    Node<T> *tmp = ptr;
                    ptr = ptr->prev;
                    free(tmp);
                }
                free(_data);
                _length = 0;
            }
        }

    public:
        List()
        {
            _data = NULL;
            _tail = NULL;
            _length = 0;
        }
        ~List()
        {
            _free();
        }
        void append(T &data)
        {
            if (_length == 0)
            {
                _malloc(data);
            }
            else
            {
                Node<T> *ptr = _get_ptr(_length - 1);                
                _append(ptr, &_tail, data);                
            }
        }
        int count(const T data)
        {
            Node<T> *ptr = _data;
            int ret = 0;
            for (int i = 0; i < _length; i++)
            {
                if (ptr->data == data)
                {
                    ret++;
                }
                ptr = ptr->next;
            }
            return ret;
        }
        void clear() { _free(); }
        void del(int id)
        {
            _del(id, 1);
        }
        void del(int id, int length)
        {
            if (length < 0)
            {
                Node<T> *ptr;
                int start;
                int checked_length = 1;
                if (id < 0)
                {
                    ptr = _get_ptr(id - 1);
                    start = id + 1;
                }
                else
                {
                    ptr = _get_ptr(id);
                    start = id;
                }

                for (int i = 0; i > length; i--)
                {
                    if (ptr->prev == NULL)
                    {
                        break;
                    }
                    ptr = ptr->prev;
                    start--;
                    checked_length++;
                }
                _del(start, checked_length);
            }
            else
            {
                _del(id, length);
            }
        }
        void extend(List<T> &list)
        {
            for (int i = 0; i < list.getSize(); i++)
            {
                append(list[i]);
            }
        }
        T get(int id)
        {
            return *_at(id);
        }
        const char *getLog() const;
        int getSize() const { return _length; }
        const char *getType() const { return "List"; }
        int index(const T data)
        {
            Node<T> *ptr = _data;
            for (int i = 0; i < _length; i++)
            {
                if (ptr->data == data)
                {
                    return i;
                }
                ptr = ptr->next;
            }
            return -1;
        }
        void insert(const int id, const T &data)
        {
            _insert(_get_ptr(id), data);
        }
        T &operator[](const int id)
        {
            return *_at(id);
        }
        List<T> &operator=(List<T> &list)
        {
            clear();
            this->extend(list);
            return *this;
        }
        List<T> &operator+=(const T &data)
        {
            append(data);
            return *this;
        }
        List<T> &operator+=(List<T> &list)
        {
            extend(list);
            return *this;
        }
        List<T> slice(int start, int length)
        {
            List<T> ret;

            // 探索開始地点
            Node<T> *node_ptr;
            if (start < 0)
            {
                node_ptr = _get_ptr(start - 1);
            }
            else
            {
                node_ptr = _get_ptr(start);
            }

            // 取得
            for (int i = 0; i < length; i++)
            {
                ret.append(node_ptr->data);
                if (node_ptr->next == _tail)
                {
                    break;
                }
                else
                {
                    node_ptr = node_ptr->next;
                }
            }

            return ret;
        }
    };

}

#endif