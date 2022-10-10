#include <dataObject/dataObject.hpp>

using namespace dataObject;

Any::Any()
{
    _data_ptr.reset(new Data<NoneType>(None));
}