#ifndef FILESYS_H
#define FILESYS_H

#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

#include <string>

#include <dataObject/dataObject.hpp>

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
        File(const File &file);
        ~File();
        const char *getType() const { return "File"; }
        int getSize() const;
        const char *getLog() const { return _path.getChar(); }

        // 独自メンバ関数

        // ファイル閉じる
        void close();
        // ディレクトリ判定
        dataObject::Bool exists();
        // 拡張子取得
        dataObject::String getExtension() const;
        // ファイルポインター
        FILE *getFilePtr();
        // ファイル形式取得
        FileType getFileType() const;
        // 名前取得
        dataObject::String getName() const;
        // Path取得
        dataObject::String getPath() const;
        // ディレクトリ判定
        dataObject::Bool isdir();
        // ファイル判定
        dataObject::Bool isfile();
        // ディレクトリ作成
        dataObject::Bool mkdir();
        // ファイル作成
        dataObject::Bool mkfile();
        // ファイル開く
        dataObject::Bool open(const char *mode);
        // ファイル開く
        dataObject::Bool open(FileMode mode);
        // ファイル作成
        dataObject::Bool touch();
    };

    class TextFile : public File
    {
    public:
        // メンバ関数
        TextFile();
        TextFile(const char *path);
        TextFile(const File &file);
        // TextFile(TextFile &file);
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
        dataObject::Int write(const char *text, FileMode mode = APPENDMODE, dataObject::Bool close_flag = true);
        // 書き込み
        dataObject::Int write(dataObject::String text, FileMode mode = APPENDMODE, dataObject::Bool close_flag = true);
        // 改行したものを書き込み
        dataObject::Int writeline(const char *text, FileMode mode = APPENDMODE, dataObject::Bool close_flag = true);
        // 改行したものを書き込み
        dataObject::Int writeline(dataObject::String text, FileMode mode = APPENDMODE, dataObject::Bool close_flag = true);
        // 行のリストを書き込み
        dataObject::Int writelines(dataObject::List<dataObject::Bool> &text_lines, FileMode mode = APPENDMODE, dataObject::Bool close_flag = true);
        // 行のリストを書き込み
        dataObject::Int writelines(dataObject::List<dataObject::Int> &text_lines, FileMode mode = APPENDMODE, dataObject::Bool close_flag = true);
        // 行のリストを書き込み
        dataObject::Int writelines(dataObject::List<dataObject::Float> &text_lines, FileMode mode = APPENDMODE, dataObject::Bool close_flag = true);
        // 行のリストを書き込み
        dataObject::Int writelines(dataObject::List<dataObject::Double> &text_lines, FileMode mode = APPENDMODE, dataObject::Bool close_flag = true);
        // 行のリストを書き込み
        dataObject::Int writelines(dataObject::List<dataObject::String> &text_lines, FileMode mode = APPENDMODE, dataObject::Bool close_flag = true);
    };

    class FileExplorer: public dataObject::None
    {
    private:
        File *_dir;
        dataObject::List<File> *_file_list;
        int _searchDir(void);

    public:
        FileExplorer(const dataObject::String &path);
        ~FileExplorer();
        // dataObject::List *getFileList(void);
        const char *getLog() const;
        int getSize() const;
        const char *getType() const { return "FileExplorer"; }
    };

    // 関数
    dataObject::String getAbsolutePath(dataObject::String &path);
    dataObject::List<dataObject::String> getPathList(dataObject::String &path);
}
#endif