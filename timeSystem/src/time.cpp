#include <timeSystem/timeSystem.hpp>

using namespace dataObject;
using namespace timeSystem;

Int Time::day() const { return Int(_day); }
Int Time::hour() const { return Int(_hour); }
Int Time::minute() const { return Int(_minute); }
Int Time::second() const { return Int(_second); }
Int Time::millisec() const { return Int(_millisec); }

const char *Time::getType() const { return "Time"; }
int Time::getSize() const { return 1; }
const char *Time::getLog() const
{
    String ret = "";
    ret += toString(_day);
    ret += "d ";
    ret += toString(_hour);
    ret += ":";
    ret += toString(_minute);
    ret += ":";
    ret += toString(_second);
    ret += " ";
    ret += toString(_millisec);
    return ret.getChar();
}

Time &Time::operator+=(const Time &time)
{
    _converter(_day + time.day(), _hour + time.hour(), _minute + time.hour(), _second + time.hour(), _millisec + time.millisec());
    return *this;
}

void Time::now()
{
    std::chrono::system_clock::time_point tp = std::chrono::system_clock::now();
    time_t tt = std::chrono::system_clock::to_time_t(tp);
    std::chrono::milliseconds p_mill = std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch());
    _converter(0, 0, 0, tt, p_mill.count() % 1000);
}

Time::Time()
{
    _day = 0;
    _hour = 0;
    _minute = 0;
    _second = 0;
    _millisec = 0;
}

Time::Time(int day, int hour, int minute, int second, int millisec)
{
    _converter(day, hour, minute, second, millisec);
}

Time::~Time()
{
}

void Time::_converter(int day, int hour, int minute, int second, int millisec)
{
    int buffer;

    _millisec = millisec % 1000;
    buffer = int(millisec / 1000);
    _second = (second + buffer) % 60;
    buffer = int(float(second + buffer) / 60);
    _minute = (minute + buffer) % 60;
    buffer = int(float(minute + buffer) / 60);
    _hour = (hour + buffer) % 24;
    buffer = int(float(hour + buffer) / 24);
    _day = day + buffer;
}

void timeSystem::getTimeZone(int &hour, int &minutes)
{
    auto result = command("date +\"%z\"");

    String hour_str = result.slice(1, 2);
    hour = atoi(hour_str.getChar());
    String min_str = result.slice(3, 2);
    minutes = atoi(min_str.getChar());
    if (result[0] == "-")
    {
        hour = -hour;
    }
}

Time timeSystem::getTimeZone()
{
    int hour = 0;
    int minute = 0;
    getTimeZone(hour, minute);

    return Time(0, hour, minute, 0, 0);
}
