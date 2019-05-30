#include "Time.h"

Time::Time(int h, int m)
{
	if ((h > 23) || (h < 0) || (m > 59) || (m < 0))
		throw "Incorrect time input";
	hour = h;
	minute = m;
}
std::ostream& operator << (std::ostream& out, Time time)
{
	out << time.hour << ":" << time.minute;
	return out;
}

std::istream& operator >> (std::istream& in, Time &time)
{
	std::cout << "Hours: ";
	in >> time.hour;
	std::cout << "Minutes: ";
	in >> time.minute;
	if ((time.hour > 23) || (time.hour < 0) || (time.minute > 59) || (time.minute < 0))
		throw "Incorrect time input";
	return in;
}

int Time::get_hour()
{
	return hour;
}

int Time::get_minute()
{
	return minute;
}

Time& Time::operator = (const Time &t)
{
	hour = t.hour;
	minute = t.minute;
	return *this;
}

bool Time::operator == (Time t)
{
	return ((hour == t.hour) && (minute == t.minute));
}

bool Time::operator > (Time t)
{
	if (hour > t.hour) return true;
	if (hour == t.hour)
		if (minute > t.minute) return true;
	return false;
}

bool Time::operator < (Time t)
{
	return !((*this > t) || (*this == t));
}

bool Time::operator >= (Time t)
{
	return !(*this < t);
}

bool Time::operator <= (Time t)
{
	return !(*this > t);
}

bool Time::operator != (Time t)
{
	return !(*this == t);
}