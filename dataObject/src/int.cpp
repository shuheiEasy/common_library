#include <dataObject.hpp>

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

const char *Int::getType() const
{
    return "Int";
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

void Int::_init()
{
    this->_data = 0;
}
