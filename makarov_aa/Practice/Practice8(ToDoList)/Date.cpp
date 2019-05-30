#include "Date.h"

Date::Date()
{

}
std::ostream& operator << (std::ostream& out, Date date)
{
	out << date.day << "." << date.month << "." << date.year;
	return out;
}

std::istream& operator >> (std::istream& in, Date &date)
{
	std::cout << "Day: ";
	in >> date.day;
	std::cout << "Month: ";
	in >> date.month;
	std::cout << "Year: ";
	in >> date.year;
	if ((date.day > 31) || (date.day < 1) || (date.month > 12) || (date.month < 1))
		throw "Incorrect data input";
	return in;
}

unsigned int Date::get_day()
{
	return day;
}

unsigned int Date::get_month()
{
	return month;
}

unsigned int Date::get_year()
{
	return year;
}

Date& Date::operator = (const Date &d)
{
	day = d.day;
	month = d.month;
	year = d.year;
	return *this;
}

bool Date::operator == (Date d)
{
	return ((year == d.year) && (month == d.month) && (day == d.day));
}

bool Date::operator > (Date d)
{
	if (year > d.year) return true;
	if (year == d.year)
	{
		if (month > d.month) return true;
		if (month == d.month)
			if (day > d.day) return true;
	}
	return false;
}

bool Date::operator < (Date d)
{
	return !((*this > d) || (*this == d));
}

bool Date::operator >= (Date d)
{
	return !(*this < d);
}

bool Date::operator <= (Date d)
{
	return !(*this > d);
}

bool Date::operator != (Date d)
{
	return !(*this == d);
}