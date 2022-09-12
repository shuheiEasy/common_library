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
        };
        dataObject::List<Format> _formatter;
        void _initFormatStruct(Format &f);
        
    public:
        Formatter();
        ~Formatter();
        dataObject::String generateText();
        void setData(const char* fornat_type, const char *data);
        void setData(const dataObject::String &fornat_type, const dataObject::String &data);
        void setFormat(const char *fornat_text);
        void setFormat(const dataObject::String &fornat_text);
    };
}
#endif