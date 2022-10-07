#include <dataObject/dataObject.hpp>

dataObject::Int dataObject::len(DataObject &data)
{
    Int ret = data.getSize();
    return ret;
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

dataObject::String dataObject::command(const char *cmd)
{
    FILE *fp;
    if ((fp = popen(cmd, "r")) == NULL)
    {
        printf("popen ERROR\n");
        exit(1);
    }
    char buf[256];
    dataObject::List<dataObject::String> command_list;
    while (!feof(fp))
    {
        fgets(buf, sizeof(buf), fp);
        command_list.append(dataObject::String(buf));
    }
    pclose(fp);

    dataObject::String ret = "";

    for (int i = 0; i < command_list.getSize() - 1; i++)
    {
        ret += command_list[i];
    }

    return ret;
}
