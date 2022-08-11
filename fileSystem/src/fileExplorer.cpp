#include <fileSystem.hpp>
#include <split.hpp>

using namespace FileSystem;

// FileExplorer
FileExplorer::FileExplorer(std::string path)
{
    // ディレクトリ取得
    _dir = new File(path);
    if (!_dir->isDir())
    {
        printf("ERROR! this path is NOT directory.\n");
        exit(1);
    }

    // ファイルリスト作成
    _file_list = new std::vector<File>();

    // ディレクトリの中身取得
    _searchDir();
}

FileExplorer::~FileExplorer()
{
    delete _dir;
    delete _file_list;
}

/////////////////////////////////////////////////////
//
// private
//
/////////////////////////////////////////////////////

void FileExplorer::_searchDir(void)
{
    DIR *dp;
    dirent *searcher;

    // ディレクトリ展開
    dp = opendir(_dir->getPath().c_str());
    if (dp == NULL)
    {
        printf("[ERROR] opendirでエラーが発生しました\n");
        exit(1);
    }

    // ディレクトリ探索
    searcher = readdir(dp);

    while (searcher != NULL)
    {
        if (searcher != NULL)
        {
            struct stat stat_buffer;
            std::string file_path = _dir->getPath() + std::string(searcher->d_name);
            if (stat(file_path.c_str(), &stat_buffer) == 0)
            {
                // フォルダ判定
                if (S_ISDIR(stat_buffer.st_mode))
                {
                    std::string dir_name = std::string(searcher->d_name);
                    // カレントディレクトリ排除
                    if (!(dir_name == "." || dir_name == ".."))
                    {
                        _file_list->push_back(File(file_path));
                    }
                }
                else
                {
                    _file_list->push_back(File(file_path));
                }
            }
        }

        searcher = readdir(dp);
    }

    free(dp);
}

std::vector<File> *FileSystem::FileExplorer::getFileList(void)
{
    return _file_list;
}
