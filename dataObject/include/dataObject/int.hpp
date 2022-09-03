#ifndef INT_H
#define INT_H

#include <dataObject/core.hpp>

namespace dataObject
{
    class Int : public None
    {
    private:
        int _data;

        void _init();

    public:
        Int();
        Int(const int &data);
        ~Int();
        int getInt() const;
        const char *getLog() const;
        int getSize() const;
        const char *getType() const;
        operator int() const { return _data; }
        Int operator=(const int &data);
        Int operator=(const Int &data);
        bool operator==(const int &data) const;
        bool operator==(const Int &data) const;
        bool operator!=(const int &data) const;
        bool operator!=(const Int &data) const;
        bool operator<(const int &data) const;
        bool operator<(const Int &data) const;
        bool operator<=(const int &data) const;
        bool operator<=(const Int &data) const;
        bool operator>(const int &data) const;
        bool operator>(const Int &data) const;
        bool operator>=(const int &data) const;
        bool operator>=(const Int &data) const;
        Int &operator+=(const int &data);
        Int &operator+=(const Int &data);
        Int &operator-=(const int &data);
        Int &operator-=(const Int &data);
        Int &operator*=(const int &data);
        Int &operator*=(const Int &data);
        Int &operator/=(const int &data);
        Int &operator/=(const Int &data);
        Int operator++();
        Int operator++(int);
        Int operator--();
        Int operator--(int);
    };
}

#endif