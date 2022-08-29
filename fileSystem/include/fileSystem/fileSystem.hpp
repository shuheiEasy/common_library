#ifndef FILESYS_H
#define FILESYS_H

#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <string>

#include "dataObject/dataObject.hpp"

namespace FileSystem
{
    enum FileType
    {
        FT_Unknown = -1,
        FT_File = 0,
        FT_Dir,
    };

    class FileClass : public dataObject::None
    {
    private:
        FileType _filetype;
        dataObject::String _path;

    public:
        FileClass();
        FileClass(dataObject::String path);
        ~FileClass();
        const char *getType() const { return "File"; }
        int getSize() const { return 1; }
        const char *getLog() const { return _path.getChar(); }
    };

    class File
    {
    private:
        FileType _filetype;
        std::string _path;
        std::string _name;
        std::string _extension;
        int _tab_counter;

        void _init(std::string path);

    public:
        std::vector<std::string> text;

        File(std::string path);
        File(const char *path);
        ~File();
        void append(std::string str, int tab = 0);
        bool isDir(void);
        std::string getName(void);
        std::string getExtension(void);
        std::string getPath(void);
        std::string getTab(int tab = 1);
        void getTab(std::string &str, int tab = 1);
        std::string getText(void);
        int read(void);
        int write(void);
    };

    class FileExplorer
    {
    private:
        File *_dir;
        std::vector<File> *_file_list;
        void _searchDir(void);

    public:
        FileExplorer(std::string path);
        ~FileExplorer();
        std::vector<File> *getFileList(void);
    };

    // 関数
    std::string getAbsolutePath(const char *path);
    dataObject::String getAbsolutePath(dataObject::String path);

}
#endif