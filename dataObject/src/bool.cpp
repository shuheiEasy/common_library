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