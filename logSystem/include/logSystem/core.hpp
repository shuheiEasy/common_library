#ifndef LOG_CORE_H
#define LOG_CORE_H

#include <stdarg.h>
#include <dataObject/dataObject.hpp>
#include <formatter/formatter.hpp>
#include <timeSystem/timeSystem.hpp>
#include <fileSystem/fileSystem.hpp>
/// @brief ログライブラリ
namespace logSystem
{
    /// @brief ログ出力レベルの列挙体
    enum LogLevel
    {
        NOTSET = 0,
        DEBUG = 10,
        INFO = 20,
        WARNING = 30,
        ERROR = 40,
        CRITICAL = 50
    };

    // 関数群

    /// @brief ログ出力
    /// @tparam 可変長型
    /// @param args, 入力する可変長データ 
    template <class... Args>
    void print(const Args &...args);
    /// @brief 書式設定可能ログ出力
    /// @param format 書式
    /// @param args 入力する可変長データ
    void fprint(const dataObject::String &format, ...);
    /// @brief 書式設定可能ログ出力
    /// @param format 書式
    /// @param args 入力する可変長データ
    void fprint(const char *format, ...);
    /// @cond
    // 書式を使って可変長データを文章へ変換
    dataObject::String _vprint(const dataObject::String &format, va_list args);
    /// @endcond

    /// @brief ログレベルをString型へ変換
    /// @param level ログレベル
    /// @return [String] ログレベルをString型へ変換したもの
    dataObject::String logLevel_str(LogLevel level);

    /// @brief ログ出力クラス
    class LogSystem
    {
    private:
        fileSystem::File *_file;
        LogLevel _log_level;
        formatter::Formatter _formatter;
        timeSystem::Datetime _datetime;

        // メゾット
        dataObject::String _generatePrintText(dataObject::String &&msg);
        void _init();
        void _setLoglevelText(LogLevel log_level);

    public:
        /// @brief コンストラクタ
        LogSystem();
        /// @brief コンストラクタ
        /// @param file_name ログを出力するファイル
        LogSystem(const char *file_name);
        /// @brief デコンストラクタ
        ~LogSystem();
        /// @brief ログを出力するファイルを設定する
        /// @param file_name ログを出力するファイル
        void setFile(const char *file_name);
        /// @brief ログの書式を設定する
        /// @param format 書式
        /// @details
        /// 書式の種類
        /// | 書式名 | 入力されるデータ |
        /// |--:|:--:|
        /// | levelname | ログレベル |
        /// | message | 出力するメッセージ |
        /// | year | ログを出力した年 |
        /// | month | ログを出力した月 |
        /// | day | ログを出力した日 |
        /// | hour | ログを出力した時間の時 |
        /// | min | ログを出力した時間の分 |
        /// | sec | ログを出力した時間の秒 |
        /// | msec | ログを出力した時間のミリ秒 |
        void setFormat(const char *format);
        /// @brief ログの書式を設定する
        /// @param format 書式
        /// @details
        /// 書式の種類
        /// | 書式名 | 入力されるデータ |
        /// |--:|:--:|
        /// | levelname | ログレベル |
        /// | message | 出力するメッセージ |
        /// | year | ログを出力した年 |
        /// | month | ログを出力した月 |
        /// | day | ログを出力した日 |
        /// | hour | ログを出力した時間の時 |
        /// | min | ログを出力した時間の分 |
        /// | sec | ログを出力した時間の秒 |
        /// | msec | ログを出力した時間のミリ秒 |
        void setFormat(const dataObject::String &format);
        /// @brief 出力するログレベルを設定する
        /// @param log_level ログレベル
        void setLevel(LogLevel log_level);
        /// @brief 書式付きログ出力
        /// @param log_level ログレベル
        /// @param format 書式
        /// @param  可変長データ 出力するデータ
        /// @return 出力する結果
        int fprint(LogLevel log_level, const dataObject::String &format, ...);
        /// @brief ログ出力
        /// @tparam ...Args 可変長型
        /// @param log_level ログレベル
        /// @param ...args 出力するデータ
        /// @return 出力する結果
        template <class... Args>
        int print(LogLevel log_level, Args &&...args);
    };

    /// @brief 出力ログ生成クラス
    class PrintSystem
    {
    private:
        dataObject::List<dataObject::String> *_text_list;
        void _extractStr() {}
        template <class HeadClass, class... TailClass>
        void _extractStr(const HeadClass &head, TailClass &...tail);

    public:
        /// @brief コンストラクタ
        /// @param 可変長データ 出力したいデータ 
        template <class... Args>
        PrintSystem(const Args &...args);
        /// @brief デコンストラクタ
        ~PrintSystem() { delete _text_list; }
        /// @brief ログ生成
        /// @return [String] ログの文字列
        dataObject::String getPrintStr();
        /// @brief ログ出力
        void print(void);
    };

}

#endif