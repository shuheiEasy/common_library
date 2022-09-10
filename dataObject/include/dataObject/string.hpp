#ifndef STRING_H
#define STRING_H

#include <dataObject/core.hpp>
#include <dataObject/list_impl.hpp>

namespace dataObject
{
    struct Moji
    {
        char *data;
        int size;
    };

    class String : public None
    {
    private:
        int _MOJI_SIZE = 4;
        int _MEMORY_SIZE = 4;

        Moji *_data;
        int _length;
        int _memory_unit;

        void _converter(Moji *&ret, const char *text, int &size);
        int _del(int start, int length);
        void _init();
        void _free_ptr();
        void _fromInt(const int data, const int start);
        void _fromFloat(const float data, const int start);
        void _fromDouble(const double data, const int start);
        void _getMemory(const int memory_size);
        int _getPos(int pos) const;
        void _malloc(Moji *&ret, int size);
        void _setData(const char *text, int start);

    public:
        String();
        String(const int &data);
        String(const float &data);
        String(const double &data);
        String(const char *text);
        String(const String &text);
        ~String();
        void append(const int &data);
        void append(const float &data);
        void append(const double &data);
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
        bool operator==(const int &data) const;
        bool operator==(const float &data) const;
        bool operator==(const double &data) const;
        bool operator==(const char *text) const;
        bool operator==(const String &text) const;
        bool operator!=(const int &data) const;
        bool operator!=(const float &data) const;
        bool operator!=(const double &data) const;
        bool operator!=(const char *text) const;
        bool operator!=(const String &text) const;
        String operator[](const int id) const;
        String operator=(const int &data);
        String operator=(const float &data);
        String operator=(const double &data);
        String operator=(const char *str);
        String operator=(const String &str);
        String operator+(const int &data) const;
        String operator+(const float &data) const;
        String operator+(const double &data) const;
        String operator+(const char *str) const;
        String operator+(const String &str) const;
        String &operator+=(const int &data);
        String &operator+=(const float &data);
        String &operator+=(const double &data);
        String &operator+=(const char *str);
        String &operator+=(const String &str);
        String slice(int start, int length) const;
        List<String> split(const char *sep);
        List<String> split(const String sep);
        String pop(int start, int length);
        void _test();
    };

    // String型変換
    template <class T,int dummy=(&T::getLog, 0)>
    inline String toString(T *&text)
    {
        return String(text->getLog());
    }
    
    template <class T>
    inline String toString(T &text, typename std::enable_if<std::is_base_of<DataObject,T>::value>::type* = nullptr)
    {
        return String(text.getLog());
    }
    template <class T>
    inline String toString(const T &num, typename std::enable_if<std::is_arithmetic<T>::value>::type* = nullptr)
    {
        return String(num);
    }
    template <class T>
    inline String toString(const T &text, typename std::enable_if<!std::is_arithmetic<T>::value>::type* = nullptr)
    {
        return "";
    }
    // inline String toString(int *&num)
    // {
    //     return String(*num);
    // }

    inline String toString(const char *text)
    {
        return String(text);
    }

}

#endif