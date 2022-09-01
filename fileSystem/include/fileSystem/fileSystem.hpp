#ifndef FILESYS_H
#define FILESYS_H

#include <unistd.h>
#include <sys/stat.h>

#include <dataObject/dataObject.hpp>

#ifdef __linux__
#define OSTYPE "LINUX"
#elif _WIN32
#define OSTYPE "WINDOWS"
#elif _WIN64
#define OSTYPE "WINDOWS"
#else
#define OSTYPE "OTHER"
#endif

namespace FileSystem
{
    enum FileType
    {
        FT_Unknown = -100,
        FT_NoExist = 0,
        FT_File = 1,
        FT_Dir,
    };

    class File : public dataObject::None
    {
    private:
        FileType _filetype;
        dataObject::String _path;
        dataObject::String _name;
        dataObject::String _extension;

        void _init(dataObject::String path);
        void _setExtension();
        void _setName();

    public:
        File();
        File(const char *path);
        File(dataObject::String &path);
        ~File();
        const char *getType() const { return "File"; }
        int getSize() const { return 1; }
        const char *getLog() const { return _path.getChar(); }

        // 独自メンバ関数
        dataObject::Bool isdir(); // ディレクトリ判定
        dataObject::Int mkdir();  // ディレクトリ作成
    };

    // class FileExplorer
    // {
    // private:
    //     File *_dir;
    //     std::vector<File> *_file_list;
    //     void _searchDir(void);

    // public:
    //     FileExplorer(std::string path);
    //     ~FileExplorer();
    //     std::vector<File> *getFileList(void);
    // };

    // 関数
    dataObject::String getAbsolutePath(dataObject::String &path);
    dataObject::List<dataObject::String> getPathList(dataObject::String &path);
}
#endif