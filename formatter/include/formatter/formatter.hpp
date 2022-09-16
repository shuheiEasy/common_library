#ifndef COMMON_FORMATTER_H
#define COMMON_FORMATTER_H

#include <dataObject/dataObject.hpp>
namespace formatter
{
    class Formatter : public dataObject::None
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
        Formatter();
        ~Formatter();
        dataObject::String generateText();
        const char *getType() const { return "Formatter"; }
        int getSize() const { return 1; }
        const char *getLog() const { return "None"; }
        void setData(const char *fornat_type, const char *data);
        void setData(const char *fornat_type, const dataObject::String &data);
        void setData(const dataObject::String &fornat_type, const dataObject::String &data);
        void setData(const dataObject::String &fornat_type, const char *data);
        void setFormat(const char *format_text);
        void setFormat(const dataObject::String &format_text);
    };
}
#endif