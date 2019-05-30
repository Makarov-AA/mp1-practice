#pragma once
#include <iostream>
#include <stdlib.h>

class Date
{
	unsigned int day, month, year;
public:
	Date();
	friend std::ostream& operator << (std::ostream& out, Date date);
	friend std::istream& operator >> (std::istream& out, Date &date);
	unsigned int get_day();
	unsigned int get_month();
	unsigned int get_year();
	Date& operator = (const Date &d);
	bool operator == (Date d);
	bool operator > (Date d);
	bool operator < (Date d);
	bool operator >= (Date d);
	bool operator <= (Date d);
	bool operator != (Date d);
};
