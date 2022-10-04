#ifndef TIMESYS_H
#define TIMESYS_H

#include <time.h>
#include <chrono>

#include <dataObject/dataObject.hpp>
#include <formatter/formatter.hpp>

/// @brief 時刻ライブラリ
namespace timeSystem
{
    /// @brief 最小の年
    const static short int MINYEAR = 0;
    /// @brief 最大の年
    const static short int MAXYEAR = 9999;

    /// @brief 時間クラス
    /// @details 日・時・分・秒・ミリ秒を格納する
    class Time : public dataObject::DataObject
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
        /// @brief 日数を設定する
        /// @param day 設定する日数
        /// @return 設定した日数
        dataObject::Int day(const dataObject::Int &day);
        /// @brief 日数を取得
        /// @return 設定した日数
        dataObject::Int day() const;
        /// @brief 時間を設定する
        /// @param hour 時間
        /// @return 設定した時間
        dataObject::Int hour(const dataObject::Int &hour);
        /// @brief 時間を取得
        /// @return 設定した時間
        dataObject::Int hour() const;
        /// @brief 時間の分を設定する
        /// @param min 時間の分
        /// @return 設定した時間の分
        dataObject::Int minute(const dataObject::Int &min);
        /// @brief 時間の分を取得
        /// @return 設定した時間の分
        dataObject::Int minute() const;
        /// @brief 時間の秒を設定する
        /// @param sec 時間の秒
        /// @return 設定した時間の秒
        dataObject::Int second(const dataObject::Int &sec);
        /// @brief 時間の秒を取得
        /// @return 設定した時間の秒
        dataObject::Int second() const;
        /// @brief 時間のミリ秒を設定する
        /// @param msec 時間のミリ秒
        /// @return 設定した時間のミリ秒
        dataObject::Int millisec(const dataObject::Int &msec);
        /// @brief 時間のミリ秒を取得
        /// @return 設定した時間のミリ秒
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
        /// @brief 現在のUNIX時間を取得する
        void now();
        /// @brief 時間の書式を設定する
        /// @param format 書式
        void setFormat(const char *format);
        /// @brief 時間の書式を設定する
        /// @param format 書式
        void setFormat(const dataObject::String &format);
        /// @brief コンストラクタ
        Time();
        /// @brief コンストラクタ
        /// @param time 時間
        Time(const Time &time);
        /// @brief コンストラクタ
        /// @param day 時間の日数
        /// @param hour 時間の時
        /// @param minute 時間の分
        /// @param second 時間の秒
        /// @param millisec 時間のミリ秒
        Time(int day, int hour, int minute, int second, int millisec = 0);
        ~Time();
    };

    /// @brief 日付クラス
    class Datetime : public dataObject::DataObject
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
        /// @brief 時刻の年を取得
        /// @return 設定した時刻の年
        dataObject::Int year() const;
        /// @brief 時刻の年を設定する
        /// @param year 時刻の年
        /// @return 設定した時刻の年
        dataObject::Int year(const dataObject::Int &year);
        /// @brief 時刻の時を取得
        /// @return 設定した時刻の時
        dataObject::Int month() const;
        /// @brief 時刻の時を設定する
        /// @param month 時刻の時
        /// @return 設定した時刻の時
        dataObject::Int month(const dataObject::Int &month);
        /// @brief 時刻の日を設定する
        /// @param day 設定する日
        /// @return 設定した日
        dataObject::Int day(const dataObject::Int &day);
        /// @brief 日数を取得
        /// @return 設定した日数
        dataObject::Int day() const;
        /// @brief 時刻の時を設定する
        /// @param hour 時
        /// @return 設定した時刻の時
        dataObject::Int hour(const dataObject::Int &hour);
        /// @brief 時刻の時を取得
        /// @return 設定した時刻の時
        dataObject::Int hour() const;
        /// @brief 時刻の分を設定する
        /// @param min 時刻の分
        /// @return 設定した時刻の分
        dataObject::Int minute(const dataObject::Int &min);
        /// @brief 時刻の分を取得
        /// @return 設定した時刻の分
        dataObject::Int minute() const;
        /// @brief 時刻の秒を設定する
        /// @param sec 時刻の秒
        /// @return 設定した時刻の秒
        dataObject::Int second(const dataObject::Int &sec);
        /// @brief 時刻の秒を取得
        /// @return 設定した時刻の秒
        dataObject::Int second() const;
        /// @brief 時刻のミリ秒を設定する
        /// @param msec 時刻のミリ秒
        /// @return 設定した時刻のミリ秒
        dataObject::Int millisec(const dataObject::Int &msec);
        /// @brief 時刻のミリ秒を取得
        /// @return 設定した時刻のミリ秒
        dataObject::Int millisec() const;
        /// @brief コンストラクタ
        Datetime();
        /// @brief コンストラクタ
        /// @param year 日付の年
        /// @param month 日付の月
        /// @param day 日付の日
        /// @param hour 時刻の時
        /// @param min 時刻の分
        /// @param sec 時刻の秒
        /// @param msec 時刻のミリ秒
        Datetime(int year, int month, int day, int hour, int min, int sec, int msec);
        ~Datetime();
        const char *getType() const;
        int getSize() const;
        const char *getLog() const;
        /// @brief 現在時刻取得する
        void now();
        /// @brief 時刻の書式を設定する
        /// @param format 時刻の書式
        void setFormat(const char *format);
        /// @brief 時刻の書式を設定する
        /// @param format 時刻の書式
        void setFormat(const dataObject::String &format);
    };

    /////////////////////////////////////////////////////////////////
    // 関数群
    /////////////////////////////////////////////////////////////////

    /// @brief タイムゾーンを取得する
    /// @param hour タイムゾーンの時差の時
    /// @param minutes タイムゾーンの時差の分
    void getTimeZone(int &hour, int &minutes);
    /// @brief タイムゾーンを取得する
    /// @return タイムゾーンの時差
    Time getTimeZone();

}
#endif
