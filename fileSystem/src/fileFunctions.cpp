#include <fileSystem.hpp>

using namespace dataObject;
using namespace FileSystem;

String FileSystem::getAbsolutePath(String &path)
{
    // 絶対パスか判定
    if (path[0] == "/")
    {
        // 絶対パスなので返り値に直接設定
        return path;
    }

    // 相対パスから変換
    char *current_dir_path = NULL;
    String current_path;
    current_dir_path = getcwd(NULL, 360);

    if (current_dir_path == NULL)
    {
        printf("カレントディレクトリの取得に失敗しました!\n");
        String ret = "";
        return ret;
    }
    else
    {
        current_path = current_dir_path;
    }

    // カレントパスのリスト
    List<String> ret_path_list;
    // 絶対パスを生成するためのリスト
    List<String> input_path_list;

    // リスト化
    if (OSTYPE == "LINUX")
    {
        ret_path_list = current_path.split("/");
        ret_path_list.del(0);
        input_path_list = path.split("/");
    }
    else if (OSTYPE == "WINDOWS")
    {
        ret_path_list = current_path.split("\\");
        input_path_list = path.split("\\");
    }
    else
    {
        printf("未対応OSです!\n");
        exit(1);
    }

    // パスのリスト生成
    for (int i = 0; i < input_path_list.getSize(); i++)
    {
        if (input_path_list[i] == ".")
        {
            continue;
        }
        else if (input_path_list[i] == "..")
        {
            ret_path_list.del(-1);
        }
        else
        {
            ret_path_list.append(input_path_list[i]);
        }
    }

    // パス生成
    String ret = "";
    String path_separator;
    if (OSTYPE == "LINUX")
    {
        path_separator = "/";
    }
    else
    {
        path_separator = "\\";
    }

    for (int i = 0; i < len(ret_path_list); i++)
    {
        if (OSTYPE == "LINUX")
        {
            ret += path_separator + ret_path_list[i];
        }
        else
        {
            ret += path_separator + ret_path_list[i];
        }
    }

    return ret;
}

List<String> FileSystem::getPathList(String &path)
{
    List<String> ret;
    String path_separator;

    // パス区切り文字
    if (OSTYPE == "LINUX")
    {
        path_separator = "/";
    }
    else if (OSTYPE == "WINDOWS")
    {
        path_separator = "\\";
    }else{
        path_separator = "/";
    }

    // パス分割
    ret = path.split(path_separator);

    return ret;
}