#ifndef TIMESYS_H
#define TIMESYS_H

#include <time.h>
#include <chrono>

#include <dataObject/dataObject.hpp>
namespace timeSystem
{
    const static short int MINYEAR = 0;
    const static short int MAXYEAR = 9999;

    class Time : public dataObject::None
    {
    private:
        short int _day;
        short int _hour;
        short int _minute;
        short int _second;
        short int _millisec;

        void _converter(int day, int hour, int minute, int second, int millisec);

    public:
        dataObject::Int day() const;
        dataObject::Int hour() const;
        dataObject::Int minute() const;
        dataObject::Int second() const;
        dataObject::Int millisec() const;
        const char *getType() const;
        int getSize() const;
        const char *getLog() const;
        Time &operator+=(const Time &time);
        void now();
        Time();
        Time(int day, int hour, int minute, int second, int millisec = 0);
        ~Time();
    };

    class Datetime : public dataObject::None
    {
    private:
        Time _time;

        short int _year;
        short int _month;
        short int _day;

        short int _hour;
        short int _minute;
        short int _second;
        short int _millisec;

        void _converter(int duration);

    public:
        Datetime();
        ~Datetime();
        const char *getType() const;
        int getSize() const;
        const char *getLog() const;
        void now();
    };

    void getTimeZone(int &hour,int &minutes);
    Time getTimeZone();

}
#endif
