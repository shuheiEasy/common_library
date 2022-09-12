#include <formatter/formatter.hpp>

using namespace dataObject;
using namespace formatter;

Formatter::Formatter() {}

Formatter::~Formatter() {}

String Formatter::generateText(){
    // 文章作成
    String ret;
    for(int i=0;i<_formatter.getSize();i++){
        ret+=_formatter.get(i).data;
    }

    // データ削除
    for(int i=0;i<_formatter.getSize();i++){
        if(_formatter.get(i).type_flag){
            _formatter[i].data="";
        }
    }

    return ret;
}

void Formatter::setData(const char* fornat_type, const char *data){
    setData(String(fornat_type),String(data));
}

void Formatter::setData(const String &fornat_type, const String &data)
{
    for (int i = 0; i < _formatter.getSize(); i++)
    {
        if (_formatter.get(i).type_flag)
        {
            if (_formatter.get(i).type == fornat_type)
            {
                _formatter[i].data = data;
            }
        }
    }
}

void Formatter::setFormat(const char *fornat_text)
{
    setFormat(String(fornat_text));
}
void Formatter::setFormat(const dataObject::String &fornat_text)
{
    enum _State
    {
        _TEXT,
        _TYPE
    };
    String buffer_str = "";
    Format buffer_format;
    int positon = 0;
    _State state = _TEXT;

    // 初期化
    _initFormatStruct(buffer_format);
    _formatter.clear();

    // 書式取得
    while (positon < fornat_text.getSize())
    {
        switch (state)
        {
        case _TEXT:
            if (fornat_text[positon] == "$")
            {
                if (positon + 1 < fornat_text.getSize())
                {
                    if (fornat_text[positon + 1] == "{")
                    {
                        // 追加
                        buffer_format.data = buffer_str;
                        _formatter.append(buffer_format);

                        // 初期化
                        state = _TYPE;
                        buffer_str = "";
                        _initFormatStruct(buffer_format);
                        positon++;
                    }
                    else
                    {
                        buffer_str += fornat_text[positon];
                    }
                }
                else
                {
                    buffer_str += fornat_text[positon];
                }
            }
            else
            {
                buffer_str += fornat_text[positon];
            }
            break;
        case _TYPE:
            if (fornat_text[positon] == "}")
            {
                // 追加
                buffer_format.type = buffer_str;
                buffer_format.type_flag = true;
                _formatter.append(buffer_format);
                state = _TEXT;
                buffer_str = "";
                _initFormatStruct(buffer_format);
            }
            else
            {
                buffer_str += fornat_text[positon];
            }
            break;
        }
        positon++;
    }

    // 追加
    buffer_format.data = buffer_str;
    _formatter.append(buffer_format);
}

void Formatter::_initFormatStruct(Format &f)
{
    f.type_flag = false;
    f.type.clear();
    f.data.clear();
}
