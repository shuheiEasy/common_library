#ifndef COMMON_FORMATTER_H
#define COMMON_FORMATTER_H


#include <dataObject/dataObject.hpp>
namespace formatter
{
    class Formatter : public dataObject::None
    {
        public:
        Formatter();
        ~Formatter();
    };
}
#endif