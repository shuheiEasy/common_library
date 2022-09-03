#include <fileSystem/fileSystem.hpp>

using namespace dataObject;
using namespace fileSystem;

TextFile::TextFile() : File() {}

TextFile::TextFile(const char *path) : File(path) {}

TextFile::~TextFile() {}

Int TextFile::read(String &output)
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
            line.push_back(moji);
        }
        close();

        output = line.c_str();
    }
    else
    {
        return -2;
    }

    return 0;
}

String TextFile::read()
{
    String ret = "";
    String buffer;
    if (read(buffer) != 0)
    {
        return ret;
    }
    return buffer;
}

Int TextFile::readlines(List<String> &text_lines)
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
                text_lines.append(String(line.c_str()));
                line.clear();
                line = "";
            }
            else
            {
                line.push_back(moji);
            }
        }
        text_lines.append(String(line.c_str()));
        close();
    }
    else
    {
        return -2;
    }

    return 0;
}

List<String> TextFile::readlines()
{
    List<String> ret;
    List<String> buffer;
    if (readlines(buffer) != 0)
    {
        return ret;
    }
    return buffer;
}

// 末尾に追加
Int TextFile::write(const char *text, FileMode mode)
{
    String buffer = text;
    return this->write(buffer, mode);
}

// 末尾に追加
Int TextFile::write(String text, FileMode mode)
{
    if (_filetype != FT_File)
    {
        return -1;
    }

    // ファイル開く
    Bool status = false;
    switch (mode)
    {
    case WRITEMODE:
    case APPENDMODE:
        if (_filemode != mode)
        {
            status = open(mode);
        }
        break;
    }

    // ファイル開けない
    if (!status)
    {
        return -2;
    }

    // 書き込み
    fputs(text.getChar(), _file_ptr);

    return 0;
}

// 末尾に追加して改行
Int TextFile::writeline(const char *text, FileMode mode)
{
    String buffer = text;
    return this->writeline(buffer, mode);
}

// 末尾に追加して改行
Int TextFile::writeline(String text, FileMode mode)
{
    if (_filetype != FT_File)
    {
        return -1;
    }

    // ファイル開く
    Bool status = false;
    switch (mode)
    {
    case WRITEMODE:
    case APPENDMODE:
        if (_filemode != mode)
        {
            status = open(mode);
        }
        break;
    }

    // ファイル開けない
    if (!status)
    {
        return -2;
    }

    // 改行
    text += "\n";

    // 書き込み
    fputs(text.getChar(), _file_ptr);

    return 0;
}

// 行のリストを書き込み
Int TextFile::writelines(List<Bool> &text_lines, FileMode mode)
{
    if (_filetype != FT_File)
    {
        return -1;
    }

    // ファイル開く
    Bool status = false;
    switch (mode)
    {
    case WRITEMODE:
    case APPENDMODE:
        if (_filemode != mode)
        {
            status = open(mode);
        }
        else
        {
            status = true;
        }
        break;
    }

    // ファイル開けない
    if (!status)
    {
        return -2;
    }

    // 書き込み
    for (int i = 0; i < len(text_lines); i++)
    {
        String buffer = text_lines[i].getLog();
        buffer += "\n";
        fputs(buffer.getChar(), _file_ptr);
    }

    return 0;
}

// 行のリストを書き込み
Int TextFile::writelines(List<Int> &text_lines, FileMode mode)
{
    if (_filetype != FT_File)
    {
        return -1;
    }

    // ファイル開く
    Bool status = false;
    switch (mode)
    {
    case WRITEMODE:
    case APPENDMODE:
        if (_filemode != mode)
        {
            status = open(mode);
        }
        else
        {
            status = true;
        }
        break;
    }

    // ファイル開けない
    if (!status)
    {
        return -2;
    }

    // 書き込み
    for (int i = 0; i < len(text_lines); i++)
    {
        String buffer = text_lines[i].getLog();
        buffer += "\n";
        fputs(buffer.getChar(), _file_ptr);
    }

    return 0;
}

// 行のリストを書き込み
Int TextFile::writelines(List<Float> &text_lines, FileMode mode)
{
    if (_filetype != FT_File)
    {
        return -1;
    }

    // ファイル開く
    Bool status = false;
    switch (mode)
    {
    case WRITEMODE:
    case APPENDMODE:
        if (_filemode != mode)
        {
            status = open(mode);
        }
        else
        {
            status = true;
        }
        break;
    }

    // ファイル開けない
    if (!status)
    {
        return -2;
    }

    // 書き込み
    for (int i = 0; i < len(text_lines); i++)
    {
        String buffer = text_lines[i].getLog();
        buffer += "\n";
        fputs(buffer.getChar(), _file_ptr);
    }

    return 0;
}

// 行のリストを書き込み
Int TextFile::writelines(List<Double> &text_lines, FileMode mode)
{
    if (_filetype != FT_File)
    {
        return -1;
    }

    // ファイル開く
    Bool status = false;
    switch (mode)
    {
    case WRITEMODE:
    case APPENDMODE:
        if (_filemode != mode)
        {
            status = open(mode);
        }
        else
        {
            status = true;
        }
        break;
    }

    // ファイル開けない
    if (!status)
    {
        return -2;
    }

    // 書き込み
    for (int i = 0; i < len(text_lines); i++)
    {
        String buffer = text_lines[i].getLog();
        buffer += "\n";
        fputs(buffer.getChar(), _file_ptr);
    }

    return 0;
}

// 行のリストを書き込み
Int TextFile::writelines(List<String> &text_lines, FileMode mode)
{
    if (_filetype != FT_File)
    {
        return -1;
    }

    // ファイル開く
    Bool status = false;
    switch (mode)
    {
    case WRITEMODE:
    case APPENDMODE:
        if (_filemode != mode)
        {
            status = open(mode);
        }
        else
        {
            status = true;
        }
        break;
    }

    // ファイル開けない
    if (!status)
    {
        return -2;
    }

    // 書き込み
    for (int i = 0; i < len(text_lines); i++)
    {
        String buffer = text_lines[i];
        buffer += "\n";
        fputs(buffer.getChar(), _file_ptr);
    }

    return 0;
}
