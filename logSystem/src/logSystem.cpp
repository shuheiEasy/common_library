#include <logSystem.hpp>

using namespace logSystem;

LogSystem::LogSystem()
{
}

LogSystem::~LogSystem()
{
}

void LogSystem::print(const dataObject::DataObject &obj){
    printf("型は %s です。\n",obj.getType());
}