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

        inline void _append(Node<T> *n_ptr, Node<T> **tail, const T data)
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
        inline T *_at(int id) const
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
        inline T *_at_change(int id)
        {
            if (id < _length)
            {
                Node<T> *ptr;
                if (id < 0)
                {
                    ptr = _get_ptr_change(id - 1);
                }
                else
                {
                    ptr = _get_ptr_change(id);
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
        inline Node<T> *_get_ptr(int id) const
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
        inline Node<T> *_get_ptr_change(int id)
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
        inline void _insert(Node<T> *ptr, const T data)
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
        inline void _malloc(const T data)
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
                    ptr = tmp->prev;
                    if (tmp != NULL)
                    {
                        free(tmp);
                        tmp = NULL;
                    }
                    else
                    {
                        break;
                    }
                }
                if (_data != NULL)
                {
                    free(_data);
                    _data = NULL;
                }
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
        List(const List<T> &list)
        {
            _data = NULL;
            _tail = NULL;
            _length = 0;

            this->extend(list);
        }
        ~List()
        {
            _free();
        }
        inline void append(const T &data)
        {
            if (_length == 0)
            {
                _malloc(data);
            }
            else
            {
                Node<T> *ptr = _get_ptr(this->_length - 1);
                _append(ptr, &(this->_tail), data);
            }
        }
        inline int count(const T &data)
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
        inline void clear() { _free(); }
        inline void del(int id)
        {
            _del(id, 1);
        }
        inline void del(int id, int length)
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
        inline void extend(const List<T> &list)
        {
            for (int i = 0; i < list.getSize(); i++)
            {
                append(list.get(i));
            }
        }
        inline T get(int id) const
        {
            return *_at(id);
        }
        const char *getLog() const;
        inline int getSize() const { return this->_length; }
        inline int getSize() { return this->_length; }
        inline const char *getType() const { return "List"; }
        inline const char *getType() { return "List"; }
        inline int index(const T data)
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
        inline void insert(const int id, const T &data)
        {
            _insert(_get_ptr(id), data);
        }
        inline T operator[](const int id)
        {
            return *(this->_at_change(id));
        }
        inline List<T> &operator=(const List<T> &list)
        {
            clear();
            this->extend(list);
            return *this;
        }
        inline List<T> &operator+=(const T &data)
        {
            append(data);
            return *this;
        }
        inline List<T> &operator+=(const List<T> &list)
        {
            extend(list);
            return *this;
        }
        inline List<T> slice(int start, int length)
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

    template <class T>
    class Vec : public DataObject, public std::vector<T>
    {
    public:
        const char *getType() const { return "Vec"; }
        int getSize() const { return this->size(); }
        const char *getLog() const { return "実装中"; }
    };

}

#endif