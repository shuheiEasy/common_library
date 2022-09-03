#include <dataObject/dataObject.hpp>

using namespace dataObject;

Double::Double()
{
    this->_init();
}
Double::Double(const double &data)
{
    this->_init();
    this->_data = data;
}

Double::~Double() {}

double Double::getDouble() const
{
    return this->_data;
}

const char *Double::getLog() const
{
    String ret(this->_data);
    return ret.getChar();
}
int Double::getSize() const
{
    return 1;
}
const char *Double::getType() const
{
    return "Double";
}
Double Double::operator=(const double &data)
{
    this->_data = data;
    return *this;
}
Double Double::operator=(const Double &data)
{
    this->_data = data.getDouble();
    return *this;
}
bool Double::operator==(const double &data) const
{
    if (this->_data == data)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Double::operator==(const Double &data) const
{
    if (this->_data == data.getDouble())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Double::operator!=(const double &data) const
{
    return !operator==(data);
}
bool Double::operator!=(const Double &data) const
{
    return !operator==(data);
}
bool Double::operator<(const double &data) const
{
    if (this->_data < data)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Double::operator<(const Double &data) const
{
    if (this->_data < data.getDouble())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Double::operator<=(const double &data) const
{
    if (this->_data <= data)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Double::operator<=(const Double &data) const
{
    if (this->_data <= data.getDouble())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Double::operator>(const double &data) const
{
    if (this->_data > data)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Double::operator>(const Double &data) const
{
    if (this->_data > data.getDouble())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Double::operator>=(const double &data) const
{
    if (this->_data >= data)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Double::operator>=(const Double &data) const
{
    if (this->_data >= data.getDouble())
    {
        return true;
    }
    else
    {
        return false;
    }
}
Double &Double::operator+=(const double &data)
{
    this->_data = this->_data + data;
    return *this;
}
Double &Double::operator+=(const Double &data)
{
    this->_data = this->_data + data.getDouble();
    return *this;
}
Double &Double::operator-=(const double &data)
{
    this->_data = this->_data - data;
    return *this;
}
Double &Double::operator-=(const Double &data)
{
    this->_data = this->_data - data.getDouble();
    return *this;
}
Double &Double::operator*=(const double &data)
{
    this->_data = this->_data * data;
    return *this;
}
Double &Double::operator*=(const Double &data)
{
    this->_data = this->_data * data.getDouble();
    return *this;
}
Double &Double::operator/=(const double &data)
{
    this->_data = (double)(this->_data / data);
    return *this;
}
Double &Double::operator/=(const Double &data)
{
    this->_data = (double)(this->_data / data.getDouble());
    return *this;
}
Double Double::operator++()
{
    *this += 1;
    return *this;
}
Double Double::operator++(int)
{
    Double ret = *this;
    *this += 1.;
    return ret;
}
Double Double::operator--()
{
    *this -= 1.;
    return *this;
}
Double Double::operator--(int)
{
    Double ret = *this;
    *this -= 1.;
    return ret;
}
void Double::_init()
{
    this->_data = 0;
}
