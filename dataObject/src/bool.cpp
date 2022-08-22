#include <dataObject.hpp>

using namespace dataObject;

Bool::Bool()
{
    this->_init();
}

Bool::Bool(const bool &data)
{
    this->_init();
    this->_data = data;
}

Bool::Bool(const Bool &data)
{
    this->_init();
    this->_data = data.getBool();
}

Bool::Bool(const int &data)
{
    this->_init();
    _fromInt(data);
}

Bool::Bool(const String &data)
{
    this->_init();
    _fromString(data);
}

Bool::~Bool() {}

bool Bool::getBool() const
{
    return this->_data;
}

const char *Bool::getType() const
{
    return "Bool";
}
const char *Bool::getLog() const
{
    if (this->_data)
    {
        return "True";
    }
    else
    {
        return "False";
    }
}
int Bool::getSize() const
{
    return 1;
}

Bool Bool::operator==(const bool &data) const
{
    if (this->_data == data)
    {
        return Bool("True");
    }
    else
    {
        return Bool("False");
    }
}
Bool Bool::operator==(const Bool &data) const
{
    if (this->_data == data.getBool())
    {
        return Bool("True");
    }
    else
    {
        return Bool("False");
    }
}
Bool Bool::operator==(const int &data) const
{
    if (*this == Bool(data))
    {
        return Bool("True");
    }
    else
    {
        return Bool("False");
    }
}
Bool Bool::operator==(const String &data) const
{
    if (*this == Bool(data))
    {
        return Bool("True");
    }
    else
    {
        return Bool("False");
    }
}
Bool Bool::operator!=(const bool &data) const
{
    return !operator==(data);
}
Bool Bool::operator!=(const Bool &data) const
{
    return !operator==(data);
}
Bool Bool::operator!=(const int &data) const
{
    return !operator==(data);
}
Bool Bool::operator!=(const String &data) const
{
    return !operator==(data);
}

Bool Bool::operator=(const bool &data)
{
    this->_data = data;
    return *this;
}

Bool Bool::operator=(const Bool &data)
{
    this->_data = data.getBool();
    return *this;
}

Bool Bool::operator=(const int &data)
{
    this->_fromInt(data);
    return *this;
}

Bool Bool::operator=(const String &data)
{
    this->_fromString(data);
    return *this;
}

Bool Bool::operator+(const bool &data) const
{
    Bool ret = this->_data + data;
    return ret;
}

Bool Bool::operator+(const Bool &data) const
{
    Bool ret = this->_data + data.getBool();
    return ret;
}

Bool Bool::operator+(const int &data) const
{
    Bool ret = *this + Bool(data);
    return ret;
}

Bool Bool::operator+(const String &data) const
{
    Bool ret = *this + Bool(data);
    return ret;
}

Bool Bool::operator-(const bool &data) const
{
    Bool ret = this->_data - data;
    return ret;
}

Bool Bool::operator-(const Bool &data) const
{
    Bool ret = this->_data - data.getBool();
    return ret;
}

Bool Bool::operator-(const int &data) const
{
    Bool ret = *this - Bool(data);
    return ret;
}

Bool Bool::operator-(const String &data) const
{
    Bool ret = *this -Bool(data);
    return ret;
}

Bool &Bool::operator+=(const bool &data)
{
    this->_data = this->_data + data;
    return *this;
}

Bool &Bool::operator+=(const Bool &data)
{
    this->_data = this->_data + data.getBool();
    return *this;
}

Bool &Bool::operator+=(const int &data)
{
    this->_data = this->_data + Bool(data).getBool();
    return *this;
}

Bool &Bool::operator+=(const String &data)
{
    this->_data = this->_data + Bool(data).getBool();
    return *this;
}

void Bool::_fromInt(const int &data)
{
    if (data > 0)
    {
        this->_data = true;
    }
    else
    {
        this->_data = false;
    }
}

void Bool::_fromString(const String &data)
{
    if (data == "True")
    {
        this->_data = true;
    }
    else if (data == "true")
    {
        this->_data = true;
    }
    else
    {
        this->_data = false;
    }
}

void Bool::_init()
{
    this->_data = false;
}