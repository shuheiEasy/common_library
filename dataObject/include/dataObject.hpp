#ifndef DATA_H
#define DATA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

namespace dataObject
{
    class DataObject
    {
    protected:
        const int _MEMORY_SIZE = 4;

    public:
        virtual const char *getType() const = 0;
        virtual int getSize() const = 0;
    };

    template <class DATATYPE>
    struct Node
    {
        DATATYPE data;
        Node *next;
    };

    struct Moji
    {
        char *data;
        int size;
    };

    template <class T>
    class List : public DataObject
    {
    private:
        Node<T> *data;

    public:
        List();
        ~List();
        int getSize() const;
        const char *getType() const;
    };

    class String : public DataObject
    {
    private:
        const int _MOJI_SIZE = 4;

        Moji *_data;
        int _length;
        int _memory_unit;

        Moji *_converter(const char *text, int &size);
        void _init();
        void _free_ptr();
        void _getMemory(const int memory_size);
        int _getPos(int pos);
        Moji *_malloc(int size);
        void _setData(const char *text, int start);

    public:
        String();
        String(const char *text);
        String(const String &text);
        ~String();
        void append(const char *text);
        void clear();
        char *getChar() const;
        const char *getType() const;
        int getSize() const;
        Moji *getStr() const;
        void insert(const char *text, int start);
        bool operator==(const char *text) const;
        bool operator==(const String &text) const;
        bool operator!=(const String &text) const;
        String &operator=(const char *str);
        String &operator=(const String &str);
        String &operator+=(const String &str);
        void remove(int start, int end);

        void _test();
    };

}

#endif