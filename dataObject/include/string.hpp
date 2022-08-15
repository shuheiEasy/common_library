#ifndef STRING_H
#define STRING_H

#include "./core.hpp"
#include "./list.hpp"

namespace dataObject
{
    struct Moji
    {
        char *data;
        int size;
    };

    class String : public DataObject
    {
    private:
        int _MOJI_SIZE = 4;
        int _MEMORY_SIZE = 4;

        Moji *_data;
        int _length;
        int _memory_unit;

        Moji *_converter(const char *text, int &size);
        void _init();
        void _free_ptr();
        void _getMemory(const int memory_size);
        int _getPos(int pos) const;
        Moji *_malloc(int size);
        void _setData(const char *text, int start);
        int _remove(int start, int length);

    public:
        String();
        String(const char *text);
        String(const String &text);
        ~String();
        void append(const char *text);
        void append(const String text);
        void clear();
        char *getChar() const;
        const char *getType() const;
        int getSize() const;
        Moji *getStr() const;
        void insert(const char *text, int start);
        void insert(const String text, int start);
        bool operator==(const char *text) const;
        bool operator==(const String &text) const;
        bool operator!=(const char *text) const;
        bool operator!=(const String &text) const;
        String operator[](const int id) const;
        String &operator=(const char *str);
        String &operator=(const String &str);
        String &operator+=(const char *str);
        String &operator+=(const String &str);
        void remove(int start, int length);
        String slice(int start, int length) const;
        List<String> split(const char *sep);
        List<String> split(const String sep);
        String pop(int start, int length);
        void _test();
    };
}

#endif