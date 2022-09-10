#include <timeSystem/timeSystem.hpp>

using namespace timeSystem;

const char *Time::getType() const { return "Time"; }
int Time::getSize() const { return 0; }
const char *Time::getLog() const { return "Time"; }

Time::Time()
{
    _hour = 0;
    _minute = 0;
    _second = 0;
    printf("Hello world\n");
}

Time::~Time()
{
}
