#include <timeSystem/timeSystem.hpp>

using namespace dataObject;
using namespace timeSystem;

Datetime::Datetime() { now(); }

Datetime::~Datetime() {}

const char *Datetime::getType() const { return "Datetime"; }

int Datetime::getSize() const { return 1; }

const char *Datetime::getLog() const
{
    String ret = "";
    ret += toString(_year);
    ret += "年";
    ret += toString(_month);
    ret += "月";
    ret += toString(_day);
    ret += "日 ";
    ret += toString(_hour);
    ret += ":";
    ret += toString(_minute);
    ret += ":";
    ret += toString(_second);
    ret += " ";
    ret += toString(_millisec);
    return ret.getChar();
}

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
}

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
