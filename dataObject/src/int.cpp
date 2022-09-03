#include <dataObject/dataObject.hpp>

using namespace dataObject;

Int::Int()
{
    this->_init();
}
Int::Int(const int &data)
{
    this->_init();
    this->_data = data;
}

Int::~Int() {}

int Int::getInt() const
{
    return this->_data;
}

const char *Int::getLog() const
{
    String ret(this->_data);
    return ret.getChar();
}
int Int::getSize() const
{
    return 1;
}
const char *Int::getType() const
{
    return "Int";
}
Int Int::operator=(const int &data)
{
    this->_data = data;
    return *this;
}
Int Int::operator=(const Int &data)
{
    this->_data = data.getInt();
    return *this;
}
bool Int::operator==(const int &data) const
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
bool Int::operator==(const Int &data) const
{
    if (this->_data == data.getInt())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Int::operator!=(const int &data) const
{
    return !operator==(data);
}
bool Int::operator!=(const Int &data) const
{
    return !operator==(data);
}
bool Int::operator<(const int &data) const
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
bool Int::operator<(const Int &data) const
{
    if (this->_data < data.getInt())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Int::operator<=(const int &data) const
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
bool Int::operator<=(const Int &data) const
{
    if (this->_data <= data.getInt())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Int::operator>(const int &data) const
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
bool Int::operator>(const Int &data) const
{
    if (this->_data > data.getInt())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Int::operator>=(const int &data) const
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
bool Int::operator>=(const Int &data) const
{
    if (this->_data >= data.getInt())
    {
        return true;
    }
    else
    {
        return false;
    }
}
Int &Int::operator+=(const int &data)
{
    this->_data = this->_data + data;
    return *this;
}
Int &Int::operator+=(const Int &data)
{
    this->_data = this->_data + data.getInt();
    return *this;
}
Int &Int::operator-=(const int &data)
{
    this->_data = this->_data - data;
    return *this;
}
Int &Int::operator-=(const Int &data)
{
    this->_data = this->_data - data.getInt();
    return *this;
}
Int &Int::operator*=(const int &data)
{
    this->_data = this->_data * data;
    return *this;
}
Int &Int::operator*=(const Int &data)
{
    this->_data = this->_data * data.getInt();
    return *this;
}
Int &Int::operator/=(const int &data)
{
    this->_data = (int)(this->_data / data);
    return *this;
}
Int &Int::operator/=(const Int &data)
{
    this->_data = (int)(this->_data / data.getInt());
    return *this;
}
Int Int::operator++()
{
    *this += 1;
    return *this;
}
Int Int::operator++(int)
{
    Int ret = *this;
    *this += 1;
    return ret;
}
Int Int::operator--()
{
    *this -= 1;
    return *this;
}
Int Int::operator--(int)
{
    Int ret = *this;
    *this -= 1;
    return ret;
}
void Int::_init()
{
    this->_data = 0;
}
