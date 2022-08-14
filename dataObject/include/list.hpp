#ifndef LIST_H
#define LIST_H

#include "./core.hpp"

namespace dataObject
{

    template <class DATATYPE>
    struct Node
    {
        DATATYPE data;
        Node *next;
    };

    template <class T>
    class List : public DataObject
    {
    private:
        Node<T> *data;

    public:
        List() {}
        ~List() {}
        int getSize() const { return 0; }
        const char *getType() const { return "List"; }
    };

}

#endif