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
        int _del(int start, int length);
        void _init();
        void _free_ptr();
        void _getMemory(const int memory_size);
        int _getPos(int pos) const;
        Moji *_malloc(int size);
        void _setData(const char *text, int start);

    public:
        String();
        String(const char *text);
        String(const String &text);
        ~String();
        void append(const char *text);
        void append(const String text);
        void clear();
        void del(int start);
        void del(int start, int length);
        char *getChar() const;
        const char *getType() const;
        const char *getLog() const;
        int getSize() const;
        Moji *getStr() const;
        void insert(const char *text, int start);
        void insert(const String text, int start);
        bool isdigit() const;
        bool isnumeric() const;
        bool operator==(const char *text) const;
        bool operator==(const String &text) const;
        bool operator!=(const char *text) const;
        bool operator!=(const String &text) const;
        String operator[](const int id) const;
        String operator=(const char *str);
        String operator=(const String &str);
        String operator+(const char *str) const;
        String operator+(const String &str) const;
        String &operator+=(const char *str);
        String &operator+=(const String &str);
        String slice(int start, int length) const;
        List<String> split(const char *sep);
        List<String> split(const String sep);
        String pop(int start, int length);
        void _test();
    };

    // String型変換
    template <class T>
    inline String toString(T &a)
    {
        return "";
    }
    inline String toString(String &a)
    {
        return a;
    }
}

#endif