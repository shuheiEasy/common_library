#ifndef CORE_H
#define CORE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#include <type_traits>

#define LANGUAGECODE "ja_JP.UTF-8"

#ifdef __linux__
#define OSTYPE "LINUX"
#elif _WIN32
#define OSTYPE "WINDOWS"
#elif _WIN64
#define OSTYPE "WINDOWS"
#else
#define OSTYPE "OTHER"
#endif

namespace dataObject
{
    class DataObject
    {
    public:
        virtual const char *getType() const { return "DataObject"; }
        virtual int getSize() const { return 0; }
        virtual const char *getLog() const { return "None"; }
    };

    class None : public DataObject
    {
    public:
        const char *getType() const { return "None"; }
        int getSize() const { return 0; }
        const char *getLog() const { return "None"; }
    };

    enum ClassType
    {
        ANYTYPE_CLASS = -1,
        NONETYPE_CLASS = 0,
        DATATYPE_CLASS = 100,
        LISTTYPE_CLASS
    };

    template <class TYPE>
    class Type
    {
    public:
        ClassType class_id;
        Type() { class_id = ANYTYPE_CLASS; }
    };

    template <class TYPE>
    class ClassCheck
    {
        template <class tInnerClass, int dummy = (&tInnerClass::getLog, 0)>
        static const char *check(tInnerClass arg) { return arg.getLog(); }
        static const char *check(...) { return "arg.getLog()"; }
        static TYPE *mClass;

    public:
        static constexpr const char *value = decltype(check(mClass))::value;
    };
}

#endif