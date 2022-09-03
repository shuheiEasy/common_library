#include <dataObject/dataObject.hpp>

int dataObject::len(DataObject &data)
{
    return data.getSize();
}

dataObject::String dataObject::type(DataObject &data)
{
    return String(data.getType());
}

dataObject::String dataObject::getEnv(const String &data)
{
    char *strenv;
    /* 環境変数HOMEの値を取得 */
    if ((strenv = getenv(data.getChar())) == NULL)
    {
        return String("");
    }
    return String(strenv);
}