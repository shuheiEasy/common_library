#include <fileSystem.hpp>
#include <split.hpp>

using namespace FileSystem;

File::File(std::string path)
{
    _init(path);
}

File::File(const char *path)
{
    _init(std::string(path));
}

File::~File() {}

void File::append(std::string str, int tab)
{
    std::vector<std::string> lines = string_tool::text_spliter(str, '\n');
    for (int i = 0; i < lines.size(); i++)
    {
        text.push_back(getTab(tab) + lines[i]);
    }
}

bool File::isDir(void)
{
    bool ret = false;

    if (_filetype == FT_Dir)
    {
        ret = true;
    }

    return ret;
}

std::string File::getExtension(void)
{
    return _extension;
}

std::string File::getName(void)
{
    return _name;
}

std::string File::getPath(void)
{
    return _path;
}

std::string File::getTab(int tab)
{
    std::string ret = "";
    for (int i = 0; i < _tab_counter * tab; i++)
    {
        ret.push_back(' ');
    }

    return ret;
}

void File::getTab(std::string &str, int tab)
{
    std::string tab_blank = getTab(tab);

    str = tab_blank + str;
}

std::string File::getText(void)
{
    std::string ret = "";
    for (int i = 0; i < text.size(); i++)
    {
        auto line = text[i] + "\n";
        ret += line;
    }

    return ret;
}

int File::read(void)
{
    FILE *fp = NULL;

    // ファイル以外を排除
    if (_filetype != FT_File)
    {
        return -1;
    }

    // ファイル読み込み
    if ((fp = fopen(_name.c_str(), "r")) != NULL)
    {
        char moji;
        std::string line = "";
        while ((moji = fgetc(fp)) != EOF)
        {
            if (moji == '\n')
            {
                text.push_back(line);
                line.clear();
                line = "";
            }
            else
            {
                line.push_back(moji);
            }
        }
        fclose(fp);
    }
    else
    {
        return -2;
    }

    return 0;
}

int File::write(void)
{
    FILE *fp = NULL;

    if (_filetype != FT_File)
    {
        return -1;
    }

    if ((fp = fopen(_name.c_str(), "w")) != NULL)
    {
        for (int i = 0; i < text.size(); i++)
        {
            auto line = text[i] + "\n";
            fputs(line.c_str(), fp);
        }
        fclose(fp);
    }
    else
    {
        return -2;
    }

    return 0;
}

void File::_init(std::string path)
{
    // 絶対パスへ変換
    path = getAbsolutePath(path.c_str());

    // PATH確認
    struct stat stat_buffer;
    if (stat(path.c_str(), &stat_buffer) == 0)
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

        // ファイル名取得
        std::vector<std::string> path_list = string_tool::text_spliter(path, '/');
        _name = path_list[path_list.size() - 1];

        // パス取得
        if (S_ISDIR(stat_buffer.st_mode))
        {
            _path = "/" + path_list[0] + "/";
            for (int i = 1; i < path_list.size(); i++)
            {
                _path += path_list[i] + "/";
            }
        }
        else
        {
            _path = path;
        }

        //拡張子取得
        if (_filetype == FT_File)
        {
            path_list.clear();
            path_list = string_tool::text_spliter(_name, '.');
            _extension = path_list[path_list.size() - 1];
        }
        else
        {
            _extension = "";
        }
    }
    else
    {
        // ファイル名取得
        std::vector<std::string> path_list = string_tool::text_spliter(path, '/');
        _name = path_list[path_list.size() - 1];
        std::vector<std::string> name_list = string_tool::text_spliter(_name, '.');

        //拡張子の有無判定
        if (name_list.size() > 0)
        {
            _filetype = FT_File;
            _extension = name_list[name_list.size() - 1];
            _path = path;

            // ファイル作成
            FILE *fp = NULL;
            if ((fp = fopen(_name.c_str(), "w")) != NULL)
            {
                fclose(fp);
            }
            else
            {
                printf("[ERROR] ファイル作成に失敗しました\n");
            }
        }
        else
        {
            _filetype = FT_Dir;
            _path = "/" + path_list[0] + "/";

            // ディレクトリ作成
            for (int i = 1; i < path_list.size(); i++)
            {
                _path += path_list[i] + "/";
            }

            if (mkdir(_path.c_str(), 0777) == 0)
            {
                printf("[ERROR] ディレクトリ作成に失敗しました\n");
            }
        }
    }

    //初期変数
    _tab_counter = 4;
}
