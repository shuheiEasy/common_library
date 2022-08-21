#ifndef BOOL_H
#define BOOL_H

#include "./core.hpp"
#include "./string.hpp"

namespace dataObject
{
    class Bool : public DataObject
    {
    private:
        bool _data;

        void _init();
        void _fromInt(const int &data);
        void _fromString(const String &data);

    public:
        Bool();
        Bool(const bool &data);
        Bool(const Bool &data);
        Bool(const int &data);
        Bool(const String &data);
        ~Bool();
        bool getBool() const;
        const char *getType() const;
        const char *getLog() const;
        int getSize() const;
        operator bool() { return _data; };
        Bool operator=(const bool &data);
        Bool operator=(const Bool &data);
        Bool operator=(const int &data);
        Bool operator=(const String &data);

    };
}

#endif