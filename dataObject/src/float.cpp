#include <dataObject/dataObject.hpp>

using namespace dataObject;

Float::Float()
{
    this->_init();
}
Float::Float(const float &data)
{
    this->_init();
    this->_data = data;
}

Float::~Float() {}

float Float::getFloat() const
{
    return this->_data;
}

const char *Float::getLog() const
{
    String ret(this->_data);
    return ret.getChar();
}
int Float::getSize() const
{
    return 1;
}
const char *Float::getType() const
{
    return "Float";
}
Float Float::operator=(const float &data)
{
    this->_data = data;
    return *this;
}
Float Float::operator=(const Float &data)
{
    this->_data = data.getFloat();
    return *this;
}
bool Float::operator==(const float &data) const
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
bool Float::operator==(const Float &data) const
{
    if (this->_data == data.getFloat())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Float::operator!=(const float &data) const
{
    return !operator==(data);
}
bool Float::operator!=(const Float &data) const
{
    return !operator==(data);
}
bool Float::operator<(const float &data) const
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
bool Float::operator<(const Float &data) const
{
    if (this->_data < data.getFloat())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Float::operator<=(const float &data) const
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
bool Float::operator<=(const Float &data) const
{
    if (this->_data <= data.getFloat())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Float::operator>(const float &data) const
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
bool Float::operator>(const Float &data) const
{
    if (this->_data > data.getFloat())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Float::operator>=(const float &data) const
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
bool Float::operator>=(const Float &data) const
{
    if (this->_data >= data.getFloat())
    {
        return true;
    }
    else
    {
        return false;
    }
}
Float &Float::operator+=(const float &data)
{
    this->_data = this->_data + data;
    return *this;
}
Float &Float::operator+=(const Float &data)
{
    this->_data = this->_data + data.getFloat();
    return *this;
}
Float &Float::operator-=(const float &data)
{
    this->_data = this->_data - data;
    return *this;
}
Float &Float::operator-=(const Float &data)
{
    this->_data = this->_data - data.getFloat();
    return *this;
}
Float &Float::operator*=(const float &data)
{
    this->_data = this->_data * data;
    return *this;
}
Float &Float::operator*=(const Float &data)
{
    this->_data = this->_data * data.getFloat();
    return *this;
}
Float &Float::operator/=(const float &data)
{
    this->_data = (float)(this->_data / data);
    return *this;
}
Float &Float::operator/=(const Float &data)
{
    this->_data = (float)(this->_data / data.getFloat());
    return *this;
}
Float Float::operator++()
{
    *this += 1;
    return *this;
}
Float Float::operator++(int)
{
    Float ret = *this;
    *this += 1.f;
    return ret;
}
Float Float::operator--()
{
    *this -= 1.f;
    return *this;
}
Float Float::operator--(int)
{
    Float ret = *this;
    *this -= 1.f;
    return ret;
}
void Float::_init()
{
    this->_data = 0;
}
