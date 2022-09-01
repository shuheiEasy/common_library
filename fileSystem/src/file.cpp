#include <fileSystem.hpp>

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

// ディレクトリ作成
Int File::mkdir()
{

    // パス設定
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
            printf("ディレクトリが存在しています\n");
        }
        else
        {
            printf("ディレクトリの作成はできません\n");
        }
    }

    // 戻り値
    Int ret = -1;
    if (_filetype == FT_Dir)
    {
        ret = 0;
    }
    return ret;
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