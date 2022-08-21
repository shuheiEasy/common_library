#ifndef INT_H
#define INT_H

#include "./core.hpp"

namespace dataObject
{
    class Int:public DataObject{
        private:
        int _data;

        void _init();

        public:
        Int();
        Int(const int &data);
        ~Int();
        const char *getType() const;
        const char *getLog() const;
        int getSize() const;
    };
}

#endif