#include <fileSystem/fileSystem.hpp>

using namespace dataObject;
using namespace fileSystem;

FileExplorer::FileExplorer(const String &path)
{
    _dir = new File(path.getChar());
    _file_list = NULL;
    _searchDir();
}

FileExplorer::~FileExplorer()
{
    delete _dir;
}

const char *FileExplorer::getLog() const
{
    if (_file_list != NULL)
    {
        return _file_list->getLog();
    }
    else
    {
        return "None";
    }
}

int FileExplorer::getSize() const
{
    if (_file_list != NULL)
    {
        return _file_list->getSize();
    }
    else
    {
        return 0;
    }
}

/////////////////////////////////////////////////
//
// private
//
/////////////////////////////////////////////////

int FileExplorer::_searchDir()
{
    // ディレクトリ判定
    if (!_dir->isdir())
    {
        printf("[ERROR] ディレクトリではありません!\n");
        return -1;
    }

    // ファイルのリストを初期化
    if (_file_list == NULL)
    {
        _file_list = new List<File>();
    }
    else
    {
        _file_list->clear();
    }

    DIR *dir;
    dirent *dp;

    if ((dir = opendir(_dir->getPath().getChar())) != NULL)
    {
        while ((dp = readdir(dir)) != NULL)
        {
            String file_path = dp->d_name;
            if (!((file_path == ".") || (file_path == "..")))
            {
                file_path = _dir->getPath() + file_path;
                _file_list->append(File(file_path));
            }
        }

        closedir(dir);
    }

    return 0;
}