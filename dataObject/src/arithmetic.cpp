#include <dataObject/dataObject.hpp>

using namespace dataObject;

template <class T>
const char *ArithmeticObject<T>::getLog() const
{
    String ret(this->_data);
    return ret.getLog();
}
template <class T>
int ArithmeticObject<T>::getSize() const
{
    return 1;
}
template <class T>
const char *ArithmeticObject<T>::getType() const
{
    return "ArithmeticObject";
}

template <class T>
ArithmeticObject<T>::ArithmeticObject()
{
    _init();
}

template <class T>
ArithmeticObject<T>::ArithmeticObject(const NoneType &data)
{
    _init();
}

template <class T>
ArithmeticObject<T>::ArithmeticObject(const T &data)
{
    _init();
    _data = data;
}

template <class T>
ArithmeticObject<T>::ArithmeticObject(const ArithmeticObject<T> &data)
{
    _init();
    _data = data.getData();
}

template <class T>
T ArithmeticObject<T>::getData() const
{
    return this->_data;
}

template <class T>
ArithmeticObject<T> ArithmeticObject<T>::operator=(const NoneType &data)
{
    _init();
    return *this;
}

template <class T>
ArithmeticObject<T> ArithmeticObject<T>::operator=(const T &data)
{
    _data = data;
    return *this;
}

template <class T>
ArithmeticObject<T> ArithmeticObject<T>::operator=(const ArithmeticObject<T> &data)
{
    _data = data.getData();
    return *this;
}

template <class T>
bool ArithmeticObject<T>::operator==(const NoneType &data) const
{
    if (this->_data == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <class T>
bool ArithmeticObject<T>::operator==(const T &data) const
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

template <class T>
bool ArithmeticObject<T>::operator==(const ArithmeticObject<T> &data) const
{
    if (this->_data == data.getData())
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
bool ArithmeticObject<T>::operator!=(const NoneType &data) const
{
    return !operator==(data);
}

template <class T>
bool ArithmeticObject<T>::operator!=(const T &data) const
{
    return !operator==(data);
}

template <class T>
bool ArithmeticObject<T>::operator!=(const ArithmeticObject<T> &data) const
{
    return !operator==(data);
}

template <class T>
bool ArithmeticObject<T>::operator<(const NoneType &data) const
{
    if (this->_data < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
bool ArithmeticObject<T>::operator<(const T &data) const
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

template <class T>
bool ArithmeticObject<T>::operator<(const ArithmeticObject<T> &data) const
{
    if (this->_data < data.getData())
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
bool ArithmeticObject<T>::operator<=(const NoneType &data) const
{
    if (this->_data <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
bool ArithmeticObject<T>::operator<=(const T &data) const
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

template <class T>
bool ArithmeticObject<T>::operator<=(const ArithmeticObject<T> &data) const
{
    if (this->_data <= data.getData())
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
bool ArithmeticObject<T>::operator>(const NoneType &data) const
{
    if (this->_data > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
bool ArithmeticObject<T>::operator>(const T &data) const
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

template <class T>
bool ArithmeticObject<T>::operator>(const ArithmeticObject<T> &data) const
{
    if (this->_data > data.getData())
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
bool ArithmeticObject<T>::operator>=(const NoneType &data) const
{
    if (this->_data >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
bool ArithmeticObject<T>::operator>=(const T &data) const
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

template <class T>
bool ArithmeticObject<T>::operator>=(const ArithmeticObject<T> &data) const
{
    if (this->_data >= data.getData())
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
ArithmeticObject<T> &ArithmeticObject<T>::operator+=(const NoneType &data)
{
    this->_data = this->_data;
    return *this;
}
template <class T>
ArithmeticObject<T> &ArithmeticObject<T>::operator+=(const T &data)
{
    this->_data = this->_data + data;
    return *this;
}
template <class T>
ArithmeticObject<T> &ArithmeticObject<T>::operator+=(const ArithmeticObject<T> &data)
{
    this->_data = this->_data + data.getData();
    return *this;
}

template <class T>
ArithmeticObject<T> &ArithmeticObject<T>::operator-=(const NoneType &data)
{
    this->_data = this->_data;
    return *this;
}
template <class T>
ArithmeticObject<T> &ArithmeticObject<T>::operator-=(const T &data)
{
    this->_data = this->_data - data;
    return *this;
}
template <class T>
ArithmeticObject<T> &ArithmeticObject<T>::operator-=(const ArithmeticObject<T> &data)
{
    this->_data = this->_data - data.getData();
    return *this;
}

template <class T>
ArithmeticObject<T> &ArithmeticObject<T>::operator*=(const NoneType &data)
{
    _init();
    return *this;
}
template <class T>
ArithmeticObject<T> &ArithmeticObject<T>::operator*=(const T &data)
{
    this->_data = this->_data * data;
    return *this;
}
template <class T>
ArithmeticObject<T> &ArithmeticObject<T>::operator*=(const ArithmeticObject<T> &data)
{
    this->_data = this->_data * data.getData();
    return *this;
}

template <class T>
ArithmeticObject<T> &ArithmeticObject<T>::operator/=(const T &data)
{
    this->_data = this->_data / data;
    return *this;
}
template <class T>
ArithmeticObject<T> &ArithmeticObject<T>::operator/=(const ArithmeticObject<T> &data)
{
    this->_data = this->_data / data.getData();
    return *this;
}

template <class T>
ArithmeticObject<T> ArithmeticObject<T>::operator++()
{
    *this += static_cast<T>(1);
    return *this;
}
template <class T>
ArithmeticObject<T> ArithmeticObject<T>::operator++(int)
{
    ArithmeticObject<T> ret = *this;
    *this += static_cast<T>(1);
    return ret;
}
template <class T>
ArithmeticObject<T> ArithmeticObject<T>::operator--()
{
    *this -= static_cast<T>(1);
    return *this;
}
template <class T>
ArithmeticObject<T> ArithmeticObject<T>::operator--(int)
{
    ArithmeticObject<T> ret = *this;
    *this -= static_cast<T>(1);
    return ret;
}
template <class T>
void ArithmeticObject<T>::_init()
{
    _data = static_cast<T>(0);
}

// 明示的に宣言
template class ArithmeticObject<int>;
template class ArithmeticObject<float>;
template class ArithmeticObject<double>;
