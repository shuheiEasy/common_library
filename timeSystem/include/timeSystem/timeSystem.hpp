#ifndef TIMESYS_H
#define TIMESYS_H

#include <time.h>
#include <chrono>

#include <dataObject/dataObject.hpp>
#include <formatter/formatter.hpp>

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

        formatter::Formatter _formatter;
        dataObject::String _print_text;

        void _converter(int day, int hour, int minute, long long second, long long millisec);
        long long _convert2msec(int day, int hour, int minute, long long second, long long millisec);
        long long _convert2msec(int day, int hour, int minute, long long second, long long millisec) const;
        void _init();
        void _generateText();

    public:
        dataObject::Int day(const dataObject::Int &day);
        dataObject::Int day() const;
        dataObject::Int hour(const dataObject::Int &hour);
        dataObject::Int hour() const;
        dataObject::Int minute(const dataObject::Int &min);
        dataObject::Int minute() const;
        dataObject::Int second(const dataObject::Int &sec);
        dataObject::Int second() const;
        dataObject::Int millisec(const dataObject::Int &msec);
        dataObject::Int millisec() const;
        const char *getType() const;
        int getSize() const;
        const char *getLog() const;
        Time &operator=(const Time &time);
        Time operator+(Time &time);
        Time operator-(Time &time);
        Time &operator+=(const Time &time);
        Time &operator-=(const Time &time);
        dataObject::Bool operator==(const Time &time) const;
        dataObject::Bool operator!=(const Time &time) const;
        dataObject::Bool operator<(const Time &time) const;
        dataObject::Bool operator<=(const Time &time) const;
        dataObject::Bool operator>(const Time &time) const;
        dataObject::Bool operator>=(const Time &time) const;
        void now();
        void setFormat(const char *format);
        void setFormat(const dataObject::String &format);
        Time();
        Time(const Time &time);
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

        formatter::Formatter _formatter;
        dataObject::String _print_text;

        void _converter(int year, int month, int day, int hour, int min, int sec, int msec);
        void _day2Calendar(int duration);
        void _generateText();

    public:
        dataObject::Int year() const;
        dataObject::Int year(const dataObject::Int &year);
        dataObject::Int month() const;
        dataObject::Int month(const dataObject::Int &month);
        dataObject::Int day() const;
        dataObject::Int day(const dataObject::Int &day);
        dataObject::Int hour() const;
        dataObject::Int hour(const dataObject::Int &hour);
        dataObject::Int minute() const;
        dataObject::Int minute(const dataObject::Int &minute);
        dataObject::Int second() const;
        dataObject::Int second(const dataObject::Int &second);
        dataObject::Int millisec() const;
        dataObject::Int millisec(const dataObject::Int &millisec);
        Datetime();
        Datetime(int year, int month, int day, int hour, int min, int sec, int msec);
        ~Datetime();
        const char *getType() const;
        int getSize() const;
        const char *getLog() const;
        void now();
        void setFormat(const char *format);
        void setFormat(const dataObject::String &format);
    };

    void getTimeZone(int &hour, int &minutes);
    Time getTimeZone();

}
#endif
