#include <fileSystem/fileSystem.hpp>

using namespace dataObject;
using namespace FileSystem;

TextFile::TextFile() : File() {}

TextFile::TextFile(const char *path) : File(path) {}

TextFile::~TextFile() {}

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
