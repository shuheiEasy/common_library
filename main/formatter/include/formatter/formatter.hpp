#ifndef COMMON_FORMATTER_H
#define COMMON_FORMATTER_H

#include <dataObject/dataObject.hpp>

/// @brief 書式ライブラリ
namespace formatter
{   
    /// @brief 書式クラス
    class Formatter : public dataObject::DataObject
    {
    private:
        struct Format
        {
            bool type_flag;
            dataObject::String type;
            dataObject::String data;
            dataObject::String left_fill;
            dataObject::Int left_zero;
        };
        dataObject::List<Format> _formatter;
        dataObject::String _format_text;
        void _initFormatStruct(Format &f);

    public:
        /// @brief コンストラクタ
        Formatter();
        /// @brief デコンストラクタ
        ~Formatter();
        /// @brief 文章を生成する関数
        /// @return 生成した文章
        dataObject::String generateText();
        const char *getType() const { return "Formatter"; }
        int getSize() const { return 1; }
        const char *getLog() const { return _format_text.getLog(); }
        /// @brief 生成する文章のデータを入力
        /// @param fornat_type 書式形式
        /// @param data データ
        void setData(const char *fornat_type, const char *data);
        /// @brief 生成する文章のデータを入力
        /// @param fornat_type 書式形式
        /// @param data データ
        void setData(const char *fornat_type, const dataObject::String &data);
        /// @brief 生成する文章のデータを入力
        /// @param fornat_type 書式形式
        /// @param data データ
        void setData(const dataObject::String &fornat_type, const dataObject::String &data);
        /// @brief 生成する文章のデータを入力
        /// @param fornat_type 書式形式
        /// @param data データ
        void setData(const dataObject::String &fornat_type, const char *data);
        /// @brief 書式を設定する
        /// @param format_text 書式を示す文章
        void setFormat(const char *format_text);
        /// @brief 書式を設定する
        /// @param format_text 書式を示す文章
        void setFormat(const dataObject::String &format_text);
    };
}
#endif