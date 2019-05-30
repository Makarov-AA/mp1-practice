#include "Task.h"

Task::~Task()
{

}

Task::Task()
{

}

Task::Task(Date d)
{
	date = d;
}

int Task::get_n()
{
	return n;
}

Task::Task(const Task &t)
{
	date = t.date;
	s = t.s;
	n = t.n;
}
std::string Task::get_string()
{
	return s;
}

void Task::set_n(int num)
{
	n = num;
}

Date Task::get_date()
{
	return date;
}

void Task::set_date(Date d)
{
	date = d;
}

void Task::input()
{
	std::cout << "Text input: ";
	std::cin.ignore(255, '\n');
	std::getline(std::cin, s);
}

void Task::output()
{
	std::cout << n << ". " << s << std::endl;
}

void ShortTask::output()
{
	std::cout << n << ". " << time << " " << s << std::endl;
}

bool Task::is_time()
{
	return false;
}

Task& Task::operator = (const Task &t)
{
	s = t.s;
	date = t.date;
	n = t.n;
	return *this;
}

ShortTask::ShortTask(Date d)
{
	date = d;
}

ShortTask::ShortTask(const ShortTask &t)
{
	s = t.s;
	date = t.date;
	n = t.n;
	time = t.time;
}

ShortTask::ShortTask(Task &t)
{
	date = t.get_date();
	s = t.get_string();
	n = t.get_n();
	time = t.get_time();
}

ShortTask& ShortTask::operator = (const ShortTask &t)
{
	s = t.s;
	date = t.date;
	n = t.n;
	time = t.time;
	return *this;
}

Time ShortTask::get_time()
{
	return time;
}

Time Task::get_time()
{
	Time t;
	return t;
}

void ShortTask::set_time(Time t)
{
	time = t;
}

void ShortTask::input()
{
	std::cout << "Time input: ";
	std::cin >> time;
	std::cout << "Text input: ";
	std::cin.ignore(255, '\n');
	std::getline(std::cin, s);
}

bool ShortTask::is_time()
{
	return true;
}