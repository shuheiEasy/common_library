#include "./core.hpp"
#include "./string.hpp"

namespace dataObject
{
    int len(DataObject &data);
    String type(DataObject &data);
    String getEnv(const String &data);
}