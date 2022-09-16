#include <formatter/formatter.hpp>

using namespace dataObject;
using namespace formatter;

Formatter::Formatter() {}

Formatter::~Formatter() {}

String Formatter::generateText()
{
    // 文章作成
    String ret;
    for (int i = 0; i < _formatter.getSize(); i++)
    {
        if (_formatter.get(i).left_zero >= 0)
        {
            for (int j = _formatter.get(i).data.getSize(); j < _formatter.get(i).left_zero; j++)
            {
                ret += _formatter.get(i).left_fill;
            }
        }
        ret += _formatter.get(i).data;
    }

    // データ削除
    for (int i = 0; i < _formatter.getSize(); i++)
    {
        if (_formatter.get(i).type_flag)
        {
            _formatter[i].data = "";
        }
    }

    return ret;
}

void Formatter::setData(const char *fornat_type, const char *data)
{
    setData(String(fornat_type), String(data));
}

void Formatter::setData(const char *fornat_type, const dataObject::String &data)
{
    setData(String(fornat_type), data);
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

void Formatter::setData(const dataObject::String &fornat_type, const char *data)
{
    setData(fornat_type, String(data));
}

void Formatter::setFormat(const char *format_text)
{
    setFormat(String(format_text));
}
void Formatter::setFormat(const dataObject::String &format_text)
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
    _format_text=format_text;

    // 書式取得
    while (positon < format_text.getSize())
    {
        switch (state)
        {
        case _TEXT:
            if (format_text[positon] == "$")
            {
                if (positon + 1 < format_text.getSize())
                {
                    if (format_text[positon + 1] == "{")
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
                        buffer_str += format_text[positon];
                    }
                }
                else
                {
                    buffer_str += format_text[positon];
                }
            }
            else
            {
                buffer_str += format_text[positon];
            }
            break;
        case _TYPE:
            if (format_text[positon] == "}")
            {
                List<String> type_infos = buffer_str.split(":");
                // 追加
                buffer_format.type = type_infos[0];
                buffer_format.type_flag = true;
                if (len(type_infos) > 1)
                {
                    if (len(type_infos[1]) > 1)
                    {
                        buffer_format.left_fill=type_infos[1][0];
                        buffer_format.left_zero = atoi(type_infos[1][1].getChar());
                    }else{
                        buffer_format.left_fill=" ";
                        buffer_format.left_zero = atoi(type_infos[1][0].getChar());
                    }
                }
                _formatter.append(buffer_format);
                state = _TEXT;
                buffer_str = "";
                _initFormatStruct(buffer_format);
            }
            else
            {
                buffer_str += format_text[positon];
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
    f.left_fill.clear();
    f.left_zero = -1;
}
