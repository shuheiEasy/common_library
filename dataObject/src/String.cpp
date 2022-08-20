#include <dataObject.hpp>

using namespace dataObject;

String::String()
{
    _init();
}

String::String(const int &data)
{
    _init();
    _fromInt(data, -1);
}

String::String(const double &data)
{
    _init();
    _fromDouble(data, -1);
}

String::String(const char *text)
{
    _init();
    _setData(text, -1);
}

String::String(const String &text)
{
    _init();
    _setData(text.getChar(), -1);
}

String::~String()
{
    _free_ptr();
}

void String::append(const int &data)
{
    _fromInt(data, -1);
}

void String::append(const double &data)
{
    _fromDouble(data, -1);
}

void String::append(const char *text)
{
    _setData(text, -1);
}

void String::append(const String text)
{
    _setData(text.getChar(), -1);
}

void String::clear()
{
    _free_ptr();
    _init();
}

void String::del(int start)
{
    _del(start, 1);
}

void String::del(int start, int length)
{
    _del(start, length);
}

char *String::getChar() const
{
    // 初期化
    int char_size = 0;
    int ptr = 0;
    char *ret;

    // 容量計算
    for (int i = 0; i < _length; i++)
    {
        char_size += _data[i].size;
    }
    char_size++;

    // 容量確保
    ret = (char *)malloc(sizeof(char) * char_size);

    // 初期化
    for (int i = 0; i < char_size; i++)
    {
        ret[i] = '\0';
    }

    // コピー
    for (int i = 0; i < _length; i++)
    {
        for (int j = 0; j < _data[i].size; j++)
        {
            ret[ptr + j] = _data[i].data[j];
        }
        ptr += _data[i].size;
    }

    return ret;
}

const char *String::getType() const
{
    return "String";
}

const char *String::getLog() const
{
    return getChar();
}

int String::getSize() const
{
    return _length;
}

Moji *String::getStr() const
{
    return _data;
}

void String::insert(const char *text, int start)
{
    int start_pos = _getPos(start);

    _setData(text, start_pos);
}

void String::insert(const String text, int start)
{
    int start_pos = _getPos(start);

    _setData(text.getChar(), start_pos);
}

bool String::isdigit() const
{
    for (int i = 0; i < _length; i++)
    {
        if (_data[i].size > 2)
        {
            return false;
        }
        else
        {
            switch (_data[i].data[0])
            {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                break;

            default:
                return false;
                break;
            }
        }
    }
    return true;
}

bool String::isnumeric() const
{
    for (int i = 0; i < _length; i++)
    {
        if (_data[i].size > 2)
        {
            return false;
        }
        else
        {
            switch (_data[i].data[0])
            {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                break;

            // 追加部分
            case '.':
                break;

            default:
                return false;
                break;
            }
        }
    }
    return true;
}

bool String::operator==(const int &data) const
{
    String tmp(data);
    if (tmp == *this)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool String::operator==(const double &data) const
{
    String tmp(data);
    if (tmp == *this)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool String::operator==(const char *text) const
{
    if (strcmp(getChar(), text) == 0)
    {
        return true;
    }
    return false;
}

bool String::operator==(const String &text) const
{
    if (text.getSize() == _length)
    {
        Moji *str = text.getStr();

        for (int i = 0; i < _length; i++)
        {
            if (strcmp(_data[i].data, str[i].data) != 0)
            {
                return false;
            }
        }

        return true;
    }
    return false;
}

bool String::operator!=(const int &data) const
{
    return !operator==(data);
}

bool String::operator!=(const double &data) const
{
    return !operator==(data);
}

bool String::operator!=(const char *text) const
{
    return !operator==(text);
}

bool String::operator!=(const String &text) const
{
    return !operator==(text);
}

String String::operator[](const int id) const
{
    return slice(id, 1);
}

String String::operator=(const int &data)
{
    clear();
    _fromInt(data, -1);
    return *this;
}

String String::operator=(const double &data)
{
    clear();
    _fromDouble(data, -1);
    return *this;
}

String String::operator=(const char *str)
{
    clear();
    _setData(str, -1);

    return *this;
}

String String::operator=(const String &str)
{
    clear();
    _setData(str.getChar(), -1);

    return *this;
}

String String::operator+(const int &data) const
{
    String ret = *this;
    ret.append(data);
    return ret;
}

String String::operator+(const double &data) const
{
    String ret = *this;
    ret.append(data);
    return ret;
}

String String::operator+(const char *str) const
{
    String ret = *this;
    ret.append(str);
    return ret;
}

String String::operator+(const String &str) const
{
    String ret = *this;
    ret.append(str);
    return ret;
}

String &String::operator+=(const int &data)
{
    _fromInt(data, -1);
    return *this;
}

String &String::operator+=(const double &data){
    _fromDouble(data, -1);
    return *this;
}

String &String::operator+=(const char *str)
{
    _setData(str, -1);
    return *this;
}

String &String::operator+=(const String &str)
{
    _setData(str.getChar(), -1);
    return *this;
}

String String::slice(int start, int length) const
{
    // 位置取得
    int start_pos;
    int end_pos;

    if (length < 0)
    {
        end_pos = _getPos(start);
        start_pos = _getPos(end_pos + length);
    }
    else
    {
        start_pos = _getPos(start);
        end_pos = _getPos(start_pos + length);
    }

    // 不正検知
    if (start_pos > end_pos)
    {
        return String("");
    }

    // データ取得
    String ret = "";
    for (int i = start_pos; i < end_pos; i++)
    {
        // 領域外判定
        if (i >= _memory_unit * _MEMORY_SIZE)
        {
            break;
        }
        ret += _data[i].data;
    }

    return ret;
}

List<String> String::split(const char *sep)
{
    return split(String(sep));
}

List<String> String::split(const String sep)
{
    List<String> ret;
    int sep_length = sep.getSize();

    String buffer = "";
    String check_text = "";
    for (int i = 0; i < _length; i++)
    {
        check_text += _data[i].data;
        if (check_text.getSize() == sep_length)
        {
            if (check_text == sep)
            {
                check_text = "";
                ret.append(buffer);
                buffer = "";
            }
            else
            {
                buffer += check_text.pop(0, 1);
            }
        }
    }
    ret.append(buffer);
    return ret;
}

String String::pop(int start, int length)
{
    String ret = slice(start, length);
    _del(start, length);
    return ret;
}

Moji *String::_converter(const char *text, int &size)
{
    // 初期化
    setlocale(LC_CTYPE, "ja_JP.UTF-8");
    int pos = 0;
    size = 0;
    Moji *ret = _malloc(strlen(text));

    // 計測
    while (text[pos] != '\0')
    {
        // サイズ計測
        int len = mblen(&text[pos], MB_CUR_MAX);

        // 文字情報取得
        for (int i = 0; i < len; i++)
        {
            ret[size].data[i] = text[pos + i];
        }
        //　容量
        ret[size].size = len;

        //後始末
        pos += len;
        size++;
    }

    return ret;
}

int String::_del(int start, int length)
{
    // 位置取得
    int start_pos;
    int end_pos;

    if (length < 0)
    {
        end_pos = _getPos(start);
        start_pos = _getPos(end_pos + length);
    }
    else
    {
        start_pos = _getPos(start);
        end_pos = _getPos(start_pos + length);
    }

    // 不正検知
    if (start_pos > end_pos)
    {
        return -1;
    }

    //データ移動
    int pos = 0;
    for (int i = end_pos; i < _memory_unit * _MEMORY_SIZE; i++)
    {
        _data[start_pos + pos].size = _data[i].size;
        _data[i].size = 0;
        for (int j = 0; j < _MOJI_SIZE; j++)
        {
            _data[start_pos + pos].data[j] = _data[i].data[j];
            _data[i].data[j] = '\0';
        }
        pos++;
    }

    //文字数削除
    _length -= end_pos - start_pos;

    return 0;
}

void String::_init()
{
    // 定数
    _MOJI_SIZE = 4;
    _MEMORY_SIZE = 4;

    // 長さ
    _length = 0;

    // 記憶容量
    _memory_unit = 1;

    // 記憶領域確保
    _data = _malloc(_memory_unit * _MEMORY_SIZE);
}

void String::_free_ptr()
{
    if (_memory_unit > 0)
    {
        for (int i = 0; i < _memory_unit * _MEMORY_SIZE; i++)
        {
            if (_data[i].data != NULL)
            {
                free(_data[i].data);
                _data[i].data = NULL;
            }
        }

        if (_data != NULL)
        {
            free(_data);
            _data = NULL;
        }
        _memory_unit = 0;
    }
}

void String::_fromInt(const int data, const int start)
{
    const int TMP_SIZE = 12;
    char tmp[TMP_SIZE];
    for (int i = 0; i < TMP_SIZE; i++)
    {
        tmp[i] = '\0';
    }
    snprintf(tmp, TMP_SIZE, "%d", data);
    _setData(tmp, start);
}

void String::_fromDouble(const double data, const int start)
{
    const int TMP_SIZE = 16;
    char tmp[TMP_SIZE];
    for (int i = 0; i < TMP_SIZE; i++)
    {
        tmp[i] = '\0';
    }
    snprintf(tmp, TMP_SIZE, "%f", data);
    int non_zero_digit = TMP_SIZE - 1;
    for (int i = TMP_SIZE - 1; i >= 0; i--)
    {
        if (non_zero_digit == i)
        {
            if ((tmp[i] == '0') || (tmp[i] == '\0'))
            {
                non_zero_digit--;
            }
        }
    }

    for (int i = non_zero_digit + 1; i < TMP_SIZE; i++)
    {
        tmp[i] = '\0';
    }

    _setData(tmp, start);
}

void String::_getMemory(const int memory_size)
{
    // 記憶容量不足時
    if (memory_size >= _memory_unit * _MEMORY_SIZE)
    {
        // 記憶容量拡張
        _memory_unit++;

        // 記憶領域確保
        Moji *tmp = (Moji *)realloc(_data, sizeof(Moji) * _memory_unit * _MEMORY_SIZE);

        if (tmp == NULL)
        {
            printf("メモリーの再確保に失敗しました!(size=%d)\n", memory_size);
            // _free_ptr();
            exit(1);
        }
        else
        {
            // 追加確保分初期化
            for (int i = (_memory_unit - 1) * _MEMORY_SIZE; i < _memory_unit * _MEMORY_SIZE; i++)
            {
                tmp[i].data = (char *)malloc(sizeof(char) * _MOJI_SIZE);
                for (int j = 0; j < _MOJI_SIZE; j++)
                {
                    tmp[i].data[j] = '\0';
                }
                tmp[i].size = 0;
            }

            // 代入
            _data = tmp;

            // もっと足りないこともありそうなので再帰的にする
            _getMemory(memory_size);
        }
    }
}

int String::_getPos(int pos) const
{
    int ret;

    if (pos < 0)
    {
        ret = _length + pos + 1;
        if (ret < 0)
        {
            ret = 0;
        }
    }
    else
    {
        ret = pos;
        if (ret > _length)
        {
            ret = _length;
        }
    }

    return ret;
}

Moji *String::_malloc(int size)
{
    Moji *ret = (Moji *)malloc(sizeof(Moji) * size);
    for (int i = 0; i < size; i++)
    {
        ret[i].size = 0;
        ret[i].data = (char *)malloc(sizeof(char) * _MOJI_SIZE);
        for (int j = 0; j < _MOJI_SIZE; j++)
        {
            ret[i].data[j] = '\0';
        }
    }

    return ret;
}

void String::_setData(const char *text, int start)
{
    // 変数
    int moji_counter = 0;
    int start_pos;
    Moji *tmp;

    // 入力情報分析
    tmp = _converter(text, moji_counter);

    // 入力位置分析
    if (start < 0)
    {
        start_pos = _length;
    }
    else
    {
        start_pos = start;
    }

    // 記憶領域確保
    _getMemory(_length + moji_counter);

    // データの移動
    for (int i = _length; i > start_pos; i--)
    {
        int ptr = i + moji_counter - 1;
        _data[ptr].size = _data[i - 1].size;

        for (int j = 0; j < _MOJI_SIZE; j++)
        {
            _data[ptr].data[j] = _data[i - 1].data[j];
        }
    }

    // データのコピー
    for (int i = 0; i < moji_counter; i++)
    {
        _data[i + start_pos].size = tmp[i].size;
        for (int j = 0; j < _MOJI_SIZE; j++)
        {
            _data[i + start_pos].data[j] = tmp[i].data[j];
        }
    }

    // バッファの解放
    free(tmp);

    // 文字の長さ更新
    _length += moji_counter;
}

void String::_test()
{
    printf("test start\n");

    int char_size = 0;
    for (int i = 0; i < _length; i++)
    {
        printf("%d: data= %s, size=%d\n", i, _data[i].data, _data[i].size);
        char_size += _data[i].size;
    }
    printf("%d\n", char_size);

    printf("test fin\n");
}
