#ifndef FLOAT_H
#define FLOAT_H

#include <dataObject/core.hpp>

namespace dataObject
{
    class Float : public None
    {
    private:
        float _data;

        void _init();

    public:
        Float();
        Float(const float &data);
        ~Float();
        float getFloat() const;
        const char *getLog() const;
        int getSize() const;
        const char *getType() const;
        operator float() const { return _data; }
        Float operator=(const float &data);
        Float operator=(const Float &data);
        bool operator==(const float &data) const;
        bool operator==(const Float &data) const;
        bool operator!=(const float &data) const;
        bool operator!=(const Float &data) const;
        bool operator<(const float &data) const;
        bool operator<(const Float &data) const;
        bool operator<=(const float &data) const;
        bool operator<=(const Float &data) const;
        bool operator>(const float &data) const;
        bool operator>(const Float &data) const;
        bool operator>=(const float &data) const;
        bool operator>=(const Float &data) const;
        Float &operator+=(const float &data);
        Float &operator+=(const Float &data);
        Float &operator-=(const float &data);
        Float &operator-=(const Float &data);
        Float &operator*=(const float &data);
        Float &operator*=(const Float &data);
        Float &operator/=(const float &data);
        Float &operator/=(const Float &data);
        Float operator++();
        Float operator++(int);
        Float operator--();
        Float operator--(int);
    };
}

#endif