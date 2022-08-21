#ifndef BOOL_H
#define BOOL_H

#include "./core.hpp"

namespace dataObject
{
    class Bool:public DataObject{
        private:
        bool _data;

        void _init();

        public:
        Bool();
        Bool(const bool &data);
        ~Bool();
        const char *getType() const;
        const char *getLog() const;
        int getSize() const;
    };
}

#endif