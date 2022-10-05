#include <dataObject/dataObject.hpp>

using namespace dataObject;

Float::Float() : ArithmeticObject<float>()
{
}
Float::Float(const NoneType &none) : ArithmeticObject<float>(none)
{
}

Float::Float(const float &data) : ArithmeticObject<float>(data)
{
}

Float::~Float() {}

const char *Float::getType() const
{
    return "Float";
}