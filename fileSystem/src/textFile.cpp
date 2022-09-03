#include <fileSystem/fileSystem.hpp>

using namespace dataObject;
using namespace FileSystem;

TextFile::TextFile() : File() {}

TextFile::TextFile(const char *path) : File(path) {}

TextFile::~TextFile() {}

// 末尾に追加
Int TextFile::append(const char *text)
{
    String buffer = text;
    return this->append(buffer);
}

// 末尾に追加
Int TextFile::append(String text)
{
    if (_filetype != FT_File)
    {
        return -1;
    }

    if (open("a"))
    {
        // 書き込み
        fputs(text.getChar(), _file_ptr);
        close();

        // テキスト情報更新
        List<String> lines = text.split("\n");
        for (int i = 0; i < len(lines); i++)
        {
            _text_lines.append(lines[i]);
        }
    }
    else
    {
        return -2;
    }

    return 0;
}

// 文章取得
List<String> *TextFile::getText()
{
    return &_text_lines;
}

Int TextFile::read()
{
    // ファイル以外を排除
    if (_filetype != FT_File)
    {
        return -1;
    }

    // ファイル読み込み
    if (open("r"))
    {
        char moji;
        std::string line = "";

        while ((moji = fgetc(_file_ptr)) != EOF)
        {
            if (moji == '\n')
            {
                _text_lines.append(String(line.c_str()));
                line.clear();
                line = "";
            }
            else
            {
                line.push_back(moji);
            }
        }
        _text_lines.append(String(line.c_str()));
        close();
    }
    else
    {
        return -2;
    }

    return 0;
}

// ファイル書き込み
Int TextFile::write(void)
{
    if (_filetype != FT_File)
    {
        return -1;
    }

    if (open("w"))
    {
        for (int i = 0; i < len(_text_lines) - 1; i++)
        {
            auto line = _text_lines[i] + "\n";
            fputs(line.getChar(), _file_ptr);
        }
        auto line = _text_lines[-1];
        fputs(line.getChar(), _file_ptr);
        close();
    }
    else
    {
        return -2;
    }

    return 0;
}
