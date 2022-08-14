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
        Node<T> *_head;
        Node<T> *_tail;
        int _length;
        inline void _append(Node<T> *n_ptr, Node<T> **tail, T data)
        {
            Node<T> *tmp = (Node<T> *)malloc(sizeof(Node<T>));

            if (tmp != NULL)
            {
                tmp->data = data;
                tmp->next = NULL;
                tmp->prev = n_ptr;
                n_ptr->next = tmp;
                *tail = tmp;
                _length++;
            }
            else
            {
                printf("失敗\n");
            }
        }
        inline T _at(int id)
        {
            if (id < _length)
            {
                Node<T> *ptr = _get_ptr(id);
                return ptr->data;
            }
            return NULL;
        }
        inline int _get_id(int id)
        {
            if (id < 0)
            {
                return _length + id;
            }
            else
            {
                return id;
            }
        }
        inline Node<T> *_get_ptr(int id)
        {
            Node<T> *ptr;
            if (id < 0)
            {
                ptr = _tail;
            }
            else
            {
                ptr = _head;
                for (int i = 0; i < id; i++)
                {
                    ptr = ptr->next;
                }
            }
            return ptr;
        }
        inline void _insert(Node<T> *ptr, T data)
        {
            Node<T> *tmp = (Node<T> *)malloc(sizeof(Node<T>));
            if (tmp != NULL)
            {
                tmp->data = data;

                if (ptr == _head)
                {
                    tmp->next = ptr;
                    tmp->prev = NULL;
                    ptr->prev = tmp;
                    _head = tmp;
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
        inline void _malloc(T data)
        {
            _head = (Node<T> *)malloc(sizeof(Node<T>));
            _tail = _head;

            if (_head != NULL)
            {
                _head->data = data;
                _head->prev = NULL;
                _head->next = NULL;
                _length++;
            }
        }
        inline void _free()
        {
            if (_length > 0)
            {
                Node<T> *ptr = _tail;
                for (int i = 0; i < _length - 1; i++)
                {
                    Node<T> *tmp = ptr;
                    ptr = ptr->prev;
                    free(tmp);
                }
                free(_head);
                _length = 0;
            }
        }
        inline int _remove(int start, int length)
        {
            if (length >= _length)
            {
                _free();
                return -1;
            }
            Node<T> *remove_node = _get_ptr(start);
            if (remove_node != _head && remove_node != _tail)
            {
                Node<T> *p_ptr = remove_node->prev;
                Node<T> *n_ptr = remove_node;
                for (int i = 0; i < length; i++)
                {
                    Node<T> *tmp = n_ptr;
                    n_ptr = n_ptr->next;
                    if (n_ptr == NULL)
                    {
                        p_ptr->next = NULL;
                        _tail = p_ptr;
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
            else if (remove_node == _head)
            {
                Node<T> *n_ptr = remove_node;
                for (int i = 0; i < length; i++)
                {
                    Node<T> *tmp = n_ptr;
                    n_ptr = n_ptr->next;
                    free(tmp);
                    _length--;
                }
                _head = n_ptr;
            }
            else
            {
                Node<T> *p_ptr = remove_node;
                for (int i = 0; i < length; i++)
                {
                    Node<T> *tmp = p_ptr;
                    p_ptr = p_ptr->prev;
                    free(tmp);
                    _length--;
                }
                _tail = p_ptr;
            }
            return 0;
        }

    public:
        List()
        {
            _head = NULL;
            _length = 0;
        }
        ~List()
        {
            _free();
        }
        void append(const T data)
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
            Node<T> *ptr = _head;
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
        void clear() { _free(); };
        T get(int id)
        {
            return _at(id);
        }
        int getSize() const { return _length; }
        const char *getType() const { return "List"; }
        int index(const T data)
        {
            Node<T> *ptr = _head;
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
        void insert(const int id, const T data)
        {
            _insert(_get_ptr(id), data);
        }
        T operator[](const int id)
        {
            return _at(id);
        }
        List<T> &operator+=(const T &data){
            append(data);
        }
        void remove(int id)
        {
            _remove(id, 1);
        }
        void remove(int id, int length)
        {
            if (length < 0)
            {
                id = _get_id(id);
                id += length + 1;
                _remove(id, length * -1);
            }
            else
            {
                _remove(id, length);
            }
        }
    };

}

#endif