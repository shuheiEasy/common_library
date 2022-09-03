#ifndef DOUBLE_H
#define DOUBLE_H

#include <dataObject/core.hpp>

namespace dataObject
{
    class Double : public None
    {
    private:
        double _data;

        void _init();

    public:
        Double();
        Double(const double &data);
        ~Double();
        double getDouble() const;
        const char *getLog() const;
        int getSize() const;
        const char *getType() const;
        operator double() const { return _data; }
        Double operator=(const double &data);
        Double operator=(const Double &data);
        bool operator==(const double &data) const;
        bool operator==(const Double &data) const;
        bool operator!=(const double &data) const;
        bool operator!=(const Double &data) const;
        bool operator<(const double &data) const;
        bool operator<(const Double &data) const;
        bool operator<=(const double &data) const;
        bool operator<=(const Double &data) const;
        bool operator>(const double &data) const;
        bool operator>(const Double &data) const;
        bool operator>=(const double &data) const;
        bool operator>=(const Double &data) const;
        Double &operator+=(const double &data);
        Double &operator+=(const Double &data);
        Double &operator-=(const double &data);
        Double &operator-=(const Double &data);
        Double &operator*=(const double &data);
        Double &operator*=(const Double &data);
        Double &operator/=(const double &data);
        Double &operator/=(const Double &data);
        Double operator++();
        Double operator++(int);
        Double operator--();
        Double operator--(int);
    };
}

#endif