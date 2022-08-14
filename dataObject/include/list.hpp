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
        void append(T data)
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

        T get(int id)
        {
            if (id < _length)
            {
                Node<T> *ptr = _get_ptr(id);
                return ptr->data;
            }
            return NULL;
        }
        int getSize() const { return _length; }
        const char *getType() const { return "List"; }
        T operator[](const int id)
        {
            if (id < _length)
            {
                Node<T> *ptr = _get_ptr(id);
                return ptr->data;
            }
            return NULL;
        }
    };

}

#endif