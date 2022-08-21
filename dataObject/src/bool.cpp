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

Bool::~Bool() {}

const char *Bool::getType() const
{
    return "Bool";
}
const char *Bool::getLog() const
{
    if(this->_data){
        return "True";
    }else{
        return "False";
    }
}
int Bool::getSize() const
{
    return 1;
}

void Int::_init()
{
    this->_data = false;
}