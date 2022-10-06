#include <dataObject/dataObject.hpp>

using namespace dataObject;

Double::Double(): ArithmeticObject<double>(){}

Double::Double(const NoneType &data): ArithmeticObject<double>(){}

Double::Double(const double &data): ArithmeticObject<double>(){}

Double::~Double() {}

const char *Double::getType() const
{
    return "Double";
}