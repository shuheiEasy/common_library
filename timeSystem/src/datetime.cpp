#include <timeSystem/timeSystem.hpp>

using namespace dataObject;
using namespace timeSystem;

Datetime::Datetime()
{
    _formatter.setFormat("${year}年${month}月${day}日 ${hour}時${min}分${sec}秒 ${msec}");
    now();
}

Datetime::~Datetime() {}

const char *Datetime::getType() const { return "Datetime"; }

int Datetime::getSize() const { return 1; }

const char *Datetime::getLog() const { return _print_text.getChar(); }

void Datetime::now()
{
    _time.now();

    _year = 1970;
    _month = 1;
    _day = 1;

    auto timezone = getTimeZone();
    _time += timezone;
    _converter(_time.day());
    _hour = _time.hour();
    _minute = _time.minute();
    _second = _time.second();
    _millisec = _time.millisec();

    _generateText();
}

void Datetime::setFormat(const char *format)
{
    _formatter.setFormat(format);
    _generateText();
}
void Datetime::setFormat(const String &format)
{
    _formatter.setFormat(format);
    _generateText();
}

Int Datetime::year() const { return Int(_year); }
Int Datetime::month() const { return Int(_month); }
Int Datetime::day() const { return Int(_day); }
Int Datetime::hour() const { return Int(_hour); }
Int Datetime::minute() const { return Int(_minute); }
Int Datetime::second() const { return Int(_second); }
Int Datetime::millisec() const { return Int(_millisec); }

//////////////////////////////////
//
// private
//
//////////////////////////////////
void Datetime::_converter(int duration)
{
    _day++;
    int remain_days = duration - 1;
    bool next_month_flag = false;

    switch (_month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
        if (_day > 31)
        {
            next_month_flag = true;
        }
        break;
    case 2:
        if (_year % 4 == 0)
        {
            if (_day > 29)
            {
                next_month_flag = true;
            }
        }
        else
        {
            if (_day > 28)
            {
                next_month_flag = true;
            }
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (_day > 30)
        {
            next_month_flag = true;
        }
        break;
    case 12:
        if (_day > 31)
        {
            _month = 1;
            _day = 1;
            _year++;
        }
        break;
    }

    // 次の月へ
    if (next_month_flag)
    {
        _day = 1;
        _month++;
    }

    // 経過日数が残っているならば
    if (remain_days > 0)
    {
        _converter(remain_days);
    }
}

void Datetime::_generateText()
{
    _formatter.setData("year", toString(_year));
    _formatter.setData("month", toString(_month));
    _formatter.setData("day", toString(_day));
    _formatter.setData("hour", toString(_hour));
    _formatter.setData("min", toString(_minute));
    _formatter.setData("sec", toString(_second));
    _formatter.setData("msec", toString(_millisec));

    _print_text = _formatter.generateText();
}
