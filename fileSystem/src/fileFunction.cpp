#include <fileSystem.hpp>
#include <split.hpp>

std::string FileSystem::getAbsolutePath(const char *path)
{
    // 絶対パスのとき
    if (path[0] == '/')
    {
        return std::string(path);
    }

    // カレントディレクトリ取得
    std::string ret = "";
    char *current_dir_path;
    current_dir_path = getcwd(NULL, 360);
    if (current_dir_path == NULL)
    {
        printf("カレントディレクトリの取得に失敗しました!\n");
        exit(1);
    }

    // 絶対パスへ変換
    std::vector<std::string> ret_list = string_tool::text_spliter(std::string(current_dir_path), '/');
    std::vector<std::string> path_list = string_tool::text_spliter(std::string(path), '/');

    for (int i = 0; i < path_list.size(); i++)
    {
        if (path_list[i] == ".")
        {
            continue;
        }
        else if (path_list[i] == "..")
        {
            ret_list.pop_back();
        }
        else
        {
            ret_list.push_back(path_list[i]);
        }
    }

    for (int i = 0; i < ret_list.size(); i++)
    {
        ret += "/" + ret_list[i];
    }

    return ret;
}
