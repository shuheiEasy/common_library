#include <dataObject.hpp>

using namespace dataObject;

String::String()
{
    _init();
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

void String::append(const char *text)
{
    _setData(text, -1);
}

void String::clear()
{
    _free_ptr();
    _init();
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

bool String::operator!=(const String &text) const
{
    return !operator==(text);
}

String &String::operator=(const char *str){
    clear();
    _setData(str, -1);

    return *this;
}

String &String::operator=(const String &str)
{
    clear();
    _setData(str.getChar(), -1);

    return *this;
}

String &String::operator+=(const String &str)
{
    _setData(str.getChar(), -1);
    return *this;
}

void String::remove(int start, int end)
{
    // 位置取得
    int start_pos = _getPos(start);
    int end_pos = _getPos(end);

    // 位置指定が不正なので修正
    if (start_pos > end_pos)
    {
        start_pos = _getPos(end);
        end_pos = _getPos(start);
    }

    // データ移動
    int pos = 0;
    for (int i = end_pos + 1; i < _memory_unit * _MEMORY_SIZE; i++)
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
    _length -= end_pos - start_pos + 1;
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

void String::_init()
{
    // 長さ
    _length = 0;

    // 記憶容量
    _memory_unit = 1;

    // 記憶領域確保
    _data = _malloc(_memory_unit * _MEMORY_SIZE);
}

void String::_free_ptr()
{
    free(_data);
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
            _free_ptr();
            printf("メモリーの再確保に失敗しました!\n");
            exit(1);
        }

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

int String::_getPos(int pos)
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
