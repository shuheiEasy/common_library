#include <dataObject/dataObject.hpp>

using namespace dataObject;

Double::Double(): ArithmeticObject<double>(){}

Double::Double(const NoneType &none): ArithmeticObject<double>(none){}

Double::Double(const double &data): ArithmeticObject<double>(data){}

Double::~Double() {}

const char *Double::getType() const
{
    return "Double";
}