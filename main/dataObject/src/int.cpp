#include <dataObject/dataObject.hpp>
using namespace dataObject;

Int::Int() : ArithmeticObject<int>()
{
}
Int::Int(const NoneType &none) : ArithmeticObject<int>(none)
{
}

Int::Int(const int &data) : ArithmeticObject<int>(data)
{
}

Int::~Int() {}

const char *Int::getType() const
{
    return "Int";
}