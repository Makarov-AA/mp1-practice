#pragma once
#include <iostream>
#include <stdlib.h>

class Time
{
    int hour;
    int minute;
public:
    Time(int h = 0, int m = 0);
    friend std::ostream& operator << (std::ostream& out, Time time);
    friend std::istream& operator >> (std::istream& in, Time &time);
    int get_hour();
    int get_minute();
    Time& operator = (const Time &t);
    bool operator > (Time t);
    bool operator < (Time t);
    bool operator >= (Time t);
    bool operator <= (Time t);
    bool operator == (Time t);
    bool operator != (Time t);
};
