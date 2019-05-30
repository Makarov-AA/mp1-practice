#pragma once
#include <iostream>
#include <stdlib.h>
#include "Task.h"
class List
{
	Task** task;
	int size;
public:
	int get_size();
	List();
	~List();
	void sort();
	void print_all();
	void print(Date date);
	void add_task(Date date);
	void add_s_task(Date date);
	void del_task(Date date, int n);
};

