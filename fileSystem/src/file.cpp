#include <fileSystem/fileSystem.hpp>

using namespace dataObject;
using namespace FileSystem;

File::File()
{
    String buf = "";
    _init(buf);
}
File::File(const char *path)
{
    _init(String(path));
}
File::File(String &path)
{
    _init(path);
}
File::~File() {}

/////////////////////////////////////////////////
//
// public 独自メンバ関数
//
/////////////////////////////////////////////////

// ファイルの存在確認
Bool File::exists()
{
    Bool ret = false;
    switch (_filetype)
    {
    case FT_File:
    case FT_Dir:
        ret = true;
        break;
    }
    return ret;
}

// 名前取得
String File::getName()
{
    return _name;
}

// 名前取得
String File::getPath()
{
    return _path;
}

// 文章取得
List<String> *File::getText()
{
    return &_text_lines;
}

// ディレクトリ判定
Bool File::isdir()
{
    Bool ret = false;
    if (_filetype == FT_Dir)
    {
        ret = true;
    }
    return ret;
}

// ファイル判定
Bool File::isfile()
{
    Bool ret = false;
    if (_filetype == FT_File)
    {
        ret = true;
    }
    return ret;
}

// ディレクトリ作成
Bool File::mkdir()
{

    // パス設定
    _setDirPath();

    // ディレクトリ作成
    if ((_filetype == FT_NoExist) || (_filetype == FT_File))
    {
        if (::mkdir(_path.getChar(), 0777) == 0)
        {
            _filetype = FT_Dir;
        }
        else
        {
            printf("ディレクトリの作成に失敗しました\n");
            _filetype = FT_Unknown;
        }
    }
    else
    {
        if (_filetype == FT_Dir)
        {
            printf("ディレクトリが存在していたので作成しません\n");
        }
        else
        {
            printf("ディレクトリの作成はできません\n");
        }
    }

    // 戻り値
    Bool ret = false;
    if (_filetype == FT_Dir)
    {
        ret = true;
    }
    return ret;
}

Bool File::mkfile()
{
    // 拡張子設定
    _setExtension();

    // ファイル作成
    FILE *fp = NULL;

    switch (_filetype)
    {
    case FT_NoExist:
    case FT_Dir:
        if (((fp = fopen(_name.getChar(), "w")) != NULL))
        {
            fclose(fp);
            _filetype = FT_File;
        }
        else
        {
            printf("ファイルの作成に失敗しました\n");
            _filetype = FT_Unknown;
        }
        break;
    case FT_File:
        printf("ファイルが存在していたので作成しません\n");
        break;
    default:
        printf("ファイルが作成できません\n");
        break;
    }

    // 戻り値
    Bool ret = false;
    if (_filetype == FT_File)
    {
        ret = true;
    }
    return ret;
}

Bool File::touch()
{
    return mkfile();
}

Int File::read()
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
Int File::write(void)
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

/////////////////////////////////////////////////
//
// private
//
/////////////////////////////////////////////////

void File::_init(String path)
{
    // 絶対パス取得
    _path = getAbsolutePath(path);

    // 名前取得
    _setName();

    // 拡張子設定
    _extension = "";

    // フォルダ・ファイルの存在判定
    struct stat stat_buffer;
    if (stat(_path.getChar(), &stat_buffer) == 0)
    {
        //フォルダ・ファイル判定
        if (S_ISREG(stat_buffer.st_mode))
        {
            _filetype = FT_File;
        }
        else if (S_ISDIR(stat_buffer.st_mode))
        {
            _filetype = FT_Dir;
        }
        else
        {
            _filetype = FT_Unknown;
        }

        // フォルダ
        if (_filetype == FT_Dir)
        {
            _setDirPath();
        }
        // ファイル
        else if (_filetype == FT_File)
        {
            _setExtension();
        }
    }
    else
    {
        _filetype = FT_NoExist;
    }
}

void File::_setDirPath()
{
    if (OSTYPE == "LINUX")
    {
        if (_path[-1] != "/")
        {
            _path += "/";
        }
    }
    else
    {
        if (_path[-1] != "\\")
        {
            _path += "\\";
        }
    }
}

void File::_setExtension()
{
    List<String> name_list = _name.split(".");
    if (len(name_list) > 1)
    {
        _extension = name_list[-1];
    }
}

void File::_setName()
{
    List<String> path_list = getPathList(_path);

    if (path_list[-1] == "")
    {
        if (path_list.getSize() > 1)
        {
            _name = path_list[-2];
        }
        else
        {
            _name = path_list[-1];
        }
    }
    else
    {
        _name = path_list[-1];
    }
}