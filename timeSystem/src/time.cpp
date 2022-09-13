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
    return _print_text.getChar();
}

Time &Time::operator+=(const Time &time)
{
    _converter(_day + time.day(), _hour + time.hour(), _minute + time.minute(), _second + time.second(), _millisec + time.millisec());
    return *this;
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

Time::Time(int day, int hour, int minute, int second, int millisec)
{
    _init();
    _converter(day, hour, minute, second, millisec);
}

Time::~Time()
{
}

void Time::_converter(int day, int hour, int minute, int second, int millisec)
{
    long long time = day * 24 + hour;
    time = time * 60 + minute;
    time = time * 60 + second;
    time = time * 1000 + millisec;

    long long buffer;

    _millisec = time % 1000;
    buffer = int(float(time) / 1000.f);
    _second = buffer % 60;
    buffer = int(float(buffer) / 60.f);
    _minute = buffer % 60;
    buffer = int(float(buffer) / 60.f);
    _hour = buffer % 24;
    buffer = int(float(buffer) / 24.f);
    _day = buffer;

    _generateText();
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
