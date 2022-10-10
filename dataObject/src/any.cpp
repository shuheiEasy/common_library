#include <dataObject/dataObject.hpp>

using namespace dataObject;

Any::Any()
{
    _data_ptr = new Data<NoneType>(None);
}