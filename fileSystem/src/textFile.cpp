#include <fileSystem/fileSystem.hpp>

using namespace dataObject;
using namespace FileSystem;

TextFile::TextFile():File(){}

TextFile::TextFile(const char *path):File(path){}

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

    FILE *fp = NULL;

    // ファイル読み込み
    if ((fp = fopen(_path.getChar(), "r")) != NULL)
    {
        char moji;
        std::string line = "";

        while ((moji = fgetc(fp)) != EOF)
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
    FILE *fp = NULL;

    if (_filetype != FT_File)
    {
        return -1;
    }

    if ((fp = fopen(_path.getChar(), "w")) != NULL)
    {
        for (int i = 0; i < len(_text_lines) - 1; i++)
        {
            auto line = _text_lines[i] + "\n";
            fputs(line.getChar(), fp);
        }
        auto line = _text_lines[-1];
        fputs(line.getChar(), fp);
        fclose(fp);
    }
    else
    {
        return -2;
    }

    return 0;
}
