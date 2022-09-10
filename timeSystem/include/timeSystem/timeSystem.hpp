#ifndef TIMESYS_H
#define TIMESYS_H

#include <time.h>

#include <dataObject/dataObject.hpp>
namespace timeSystem
{
    const static short int MINYEAR=0;
    const static short int MAXYEAR=9999;

    class Time : public dataObject::None
    {
    private:
        short int _hour;
        short int _minute;
        short int _second;

    public:
        const char *getType() const ;
        int getSize() const ;
        const char *getLog() const;
        Time();
        ~Time();
    };

}
#endif
