#ifndef FILESYS_H
#define FILESYS_H

#include <unistd.h>
#include <sys/stat.h>

#include <string>

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

namespace fileSystem
{
    enum FileType
    {
        FT_Unknown = -100,
        FT_NoExist = 0,
        FT_File = 1,
        FT_Dir,
    };

    enum FileMode
    {
        UNKNOWNMODE = -100,
        CLOSEMODE = -1,
        READMODE = 0,
        WRITEMODE,
        APPENDMODE
    };

    class File : public dataObject::None
    {
    protected:
        FileType _filetype;
        FileMode _filemode;
        dataObject::String _path;
        dataObject::String _name;
        dataObject::String _extension;
        FILE *_file_ptr;

        // メンバ関数
        void _init(dataObject::String path);
        void _setDirPath();
        void _setExtension();
        void _setName();

    public:
        File();
        File(const char *path);
        File(dataObject::String &path);
        ~File();
        const char *getType() const { return "File"; }
        int getSize() const;
        const char *getLog() const { return _path.getChar(); }

        // 独自メンバ関数
        void close();                            // ファイル閉じる
        dataObject::Bool exists();               // ディレクトリ判定
        FILE *getFilePtr();                      // ファイルポインター
        dataObject::String getName();            // 名前取得
        dataObject::String getPath();            // Path取得
        dataObject::Bool isdir();                // ディレクトリ判定
        dataObject::Bool isfile();               // ファイル判定
        dataObject::Bool mkdir();                // ディレクトリ作成
        dataObject::Bool mkfile();               // ファイル作成
        dataObject::Bool open(const char *mode); // ファイル開く
        dataObject::Bool open(FileMode mode);    // ファイル開く
        dataObject::Bool touch();                // ファイル作成
    };

    class TextFile : public File
    {
    public:
        // メンバ関数
        TextFile();
        TextFile(const char *path);
        ~TextFile();
        const char *getType() const { return "TextFile"; }

        // 独自メンバ関数

        // ファイル全体を読み込み
        dataObject::Int read(dataObject::String &output);
        // ファイル全体を読み込み
        dataObject::String read();
        // 行ごとに読み取り
        dataObject::Int readlines(dataObject::List<dataObject::String> &text_lines);
        // 行ごとに読み取り
        dataObject::List<dataObject::String> readlines();
        // 書き込み
        dataObject::Int write(const char *text, FileMode mode = APPENDMODE);
        // 書き込み
        dataObject::Int write(dataObject::String text, FileMode mode = APPENDMODE);
        // 改行したものを書き込み
        dataObject::Int writeline(const char *text, FileMode mode = APPENDMODE);
        // 改行したものを書き込み
        dataObject::Int writeline(dataObject::String text, FileMode mode = APPENDMODE);
        // 行のリストを書き込み
        dataObject::Int writelines(dataObject::List<dataObject::Bool> &text_lines, FileMode mode = APPENDMODE);
        // 行のリストを書き込み
        dataObject::Int writelines(dataObject::List<dataObject::Int> &text_lines, FileMode mode = APPENDMODE);
        // 行のリストを書き込み
        dataObject::Int writelines(dataObject::List<dataObject::Float> &text_lines, FileMode mode = APPENDMODE);
        // 行のリストを書き込み
        dataObject::Int writelines(dataObject::List<dataObject::Double> &text_lines, FileMode mode = APPENDMODE);
        // 行のリストを書き込み
        dataObject::Int writelines(dataObject::List<dataObject::String> &text_lines, FileMode mode = APPENDMODE);
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