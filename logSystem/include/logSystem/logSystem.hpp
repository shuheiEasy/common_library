#ifndef LOGSYS_H
#define LOGSYS_H

#include <stdio.h>
#include <fileSystem/fileSystem.hpp>

namespace logSystem
{
    class LogSystem
    {
    private:
        FileSystem::File *file;

    public:
        LogSystem();
        ~LogSystem();
        void print(const dataObject::DataObject &obj);
    };

    

}

#endif