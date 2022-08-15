#include <dataObject.hpp>

int dataObject::len(DataObject &data)
{
    return data.getSize();
}

dataObject::String dataObject::type(DataObject &data)
{
    return String(data.getType());
}