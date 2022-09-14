#include <timeSystem/timeSystem.hpp>

using namespace dataObject;
using namespace timeSystem;

Int Time::day(const Int &day)
{
    _converter(day, _hour, _minute, _second, _millisec);
    return Int(_day);
}
Int Time::day() const { return Int(_day); }
Int Time::hour(const Int &hour)
{
    _converter(_day, hour, _minute, _second, _millisec);
    return Int(_hour);
}
Int Time::hour() const { return Int(_hour); }
Int Time::minute(const Int &min)
{
    _converter(_day, _hour, min, _second, _millisec);
    return Int(_minute);
}
Int Time::minute() const { return Int(_minute); }
Int Time::second(const Int &sec)
{
    _converter(_day, _hour, _minute, sec, _millisec);
    return Int(_second);
}
Int Time::second() const { return Int(_second); }
Int Time::millisec(const Int &msec)
{
    _converter(_day, _hour, _minute, _second, msec);
    return Int(_millisec);
}
Int Time::millisec() const { return Int(_millisec); }

const char *Time::getType() const { return "Time"; }
int Time::getSize() const { return 1; }
const char *Time::getLog() const
{
    return _print_text.getChar();
}
Time &Time::operator=(const Time &time)
{
    _converter(time.day(), time.hour(), time.minute(), time.second(), time.millisec());
    return *this;
}
Time Time::operator+(Time &time)
{
    Time ret(*this);
    ret += time;
    return ret;
}
Time Time::operator-(Time &time)
{
    Time ret(*this);
    ret -= time;
    return ret;
}

Time &Time::operator+=(const Time &time)
{
    _converter(_day + time.day(), _hour + time.hour(), _minute + time.minute(), _second + time.second(), _millisec + time.millisec());
    return *this;
}
Time &Time::operator-=(const Time &time)
{
    _converter(_day - time.day(), _hour - time.hour(), _minute - time.minute(), _second - time.second(), _millisec - time.millisec());
    return *this;
}

Bool Time::operator==(const Time &time) const
{
    long long this_time = _convert2msec(_day, _hour, _minute, _second, _millisec);
    long long compare_time = _convert2msec(time.day(), time.hour(), time.minute(), time.second(), time.millisec());
    if (this_time == compare_time)
    {
        return true;
    }
    else
    {
        return false;
    }
}
Bool Time::operator!=(const Time &time) const { return !(*this == time); }
Bool Time::operator<(const Time &time) const
{
    long long this_time = _convert2msec(_day, _hour, _minute, _second, _millisec);
    long long compare_time = _convert2msec(time.day(), time.hour(), time.minute(), time.second(), time.millisec());
    if (this_time < compare_time)
    {
        return true;
    }
    else
    {
        return false;
    }
}
Bool Time::operator<=(const Time &time) const
{
    long long this_time = _convert2msec(_day, _hour, _minute, _second, _millisec);
    long long compare_time = _convert2msec(time.day(), time.hour(), time.minute(), time.second(), time.millisec());
    if (this_time <= compare_time)
    {
        return true;
    }
    else
    {
        return false;
    }
}
Bool Time::operator>(const Time &time) const
{
    long long this_time = _convert2msec(_day, _hour, _minute, _second, _millisec);
    long long compare_time = _convert2msec(time.day(), time.hour(), time.minute(), time.second(), time.millisec());
    if (this_time > compare_time)
    {
        return true;
    }
    else
    {
        return false;
    }
}
Bool Time::operator>=(const Time &time) const
{
    long long this_time = _convert2msec(_day, _hour, _minute, _second, _millisec);
    long long compare_time = _convert2msec(time.day(), time.hour(), time.minute(), time.second(), time.millisec());
    if (this_time >= compare_time)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Time::now()
{
    std::chrono::system_clock::time_point tp = std::chrono::system_clock::now();
    time_t tt = std::chrono::system_clock::to_time_t(tp);
    std::chrono::milliseconds p_mill = std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch());
    _converter(0, 0, 0, tt, p_mill.count() % 1000);
}

void Time::setFormat(const char *format)
{
    _formatter.setFormat(format);
    _generateText();
}
void Time::setFormat(const dataObject::String &format)
{
    _formatter.setFormat(format);
    _generateText();
}

Time::Time()
{
    _init();
}
Time::Time(const Time &time)
{
    _converter(time.day(), time.hour(), time.minute(), time.second(), time.millisec());
}

Time::Time(int day, int hour, int minute, int second, int millisec)
{
    _init();
    _converter(day, hour, minute, second, millisec);
}

Time::~Time()
{
}

void Time::_converter(int day, int hour, int minute, long long second, long long millisec)
{
    long long time = _convert2msec(day, hour, minute, second, millisec);
    long long buffer;

    _millisec = time % 1000;
    buffer = time / 1000;
    _second = buffer % 60;
    buffer = buffer / 60;
    _minute = buffer % 60;
    buffer = buffer / 60;
    _hour = buffer % 24;
    buffer = buffer / 24;
    _day = buffer;

    _generateText();
}

long long Time::_convert2msec(int day, int hour, int minute, long long second, long long millisec)
{
    long long time = day * 24 + hour;
    time = time * 60 + minute;
    time = time * 60 + second;
    time = time * 1000 + millisec;
    return time;
}

long long Time::_convert2msec(int day, int hour, int minute, long long second, long long millisec) const
{
    long long time = day * 24 + hour;
    time = time * 60 + minute;
    time = time * 60 + second;
    time = time * 1000 + millisec;
    return time;
}

void Time::_generateText()
{
    _formatter.setData("day", toString(_day));
    _formatter.setData("hour", toString(_hour));
    _formatter.setData("min", toString(_minute));
    _formatter.setData("sec", toString(_second));
    _formatter.setData("msec", toString(_millisec));

    _print_text = _formatter.generateText();
}

void Time::_init()
{
    _formatter.setFormat("${day}d ${hour}:${min}:${sec} ${msec}");
    _converter(0, 0, 0, 0, 0);
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
