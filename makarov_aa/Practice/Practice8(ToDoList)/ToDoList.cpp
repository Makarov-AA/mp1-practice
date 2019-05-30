#include "ToDoList.h"

int List::get_size()
{
	return size;
}

List::List()
{
	task = new Task*;
	size = 0;
}

List::~List()
{
	delete task;
}

void List::sort()
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size - i - 1; j++)
			if (task[j]->get_date() > task[j + 1]->get_date())
			{
				Task* tmp = task[j];
				task[j] = task[j + 1];
				task[j + 1] = tmp;
			}
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size - i - 1; j++)
			if (task[j]->get_date() == task[j + 1]->get_date())
			{
				if ((task[j]->is_time()) && !(task[j + 1]->is_time()))
				{
					Task* tmp = task[j];
					task[j] = task[j + 1];
					task[j + 1] = tmp;
				}
				if ((task[j]->is_time()) && (task[j + 1]->is_time()))
					if (task[j]->get_time() > task[j + 1]->get_time())
					{
						Task* tmp = task[j];
						task[j] = task[j + 1];
						task[j + 1] = tmp;
					}
			}
	int num = 1;
	task[0]->set_n(num);
	for (int i = 1; i < size; i++)
		if (task[i]->get_date() == task[i - 1]->get_date())
			task[i]->set_n(++num);
		else
		{
			num = 1;
			task[i]->set_n(num);
		}
}

void List::print_all()
{
	std::cout << task[0]->get_date() << std::endl;
	task[0]->output();
	for (int i = 1; i < size; i++)
	{
		if (task[i]->get_date() != task[i - 1]->get_date())
			std::cout << task[i]->get_date() << std::endl;
		task[i]->output();
	}
}

void List::print(Date date)
{
	std::cout << date << std::endl;
	for (int i = 0; i < size; i++)
		if (task[i]->get_date() == date)
			task[i]->output();
}

void List::add_task(Date date)
{
	Task** tmp = new Task*[size + 1];
	for (int i = 0; i < size; i++)
		if (task[i]->is_time())
			tmp[i] = new ShortTask(*task[i]);
		else tmp[i] = new Task(*task[i]);
	tmp[size] = new Task(date);
	tmp[size]->input();
	for (int i = 0; i < size; i++)
		delete task[i];
	size++;
	task = tmp;
	sort();
}

void List::add_s_task(Date date)
{
	Task** tmp = new Task*[size + 1];
	for (int i = 0; i < size; i++)
		if (task[i]->is_time())
			tmp[i] = new ShortTask(*task[i]);
		else tmp[i] = new Task(*task[i]);
	tmp[size] = new ShortTask(date);
	tmp[size]->input();
	for (int i = 0; i < size; i++)
		delete task[i];
	size++;
	task = tmp;
	sort();
}

void List::del_task(Date date, int n)
{
	int k = 0;
	while ((task[k]->get_date() != date) || (task[k]->get_n() != n)) k++;
	Task** tmp = new Task*[size - 1];
	for (int i = 0; i < k; i++)
		if (task[i]->is_time())
			tmp[i] = new ShortTask(*task[i]);
		else tmp[i] = new Task(*task[i]);
	for (int i = k + 1; i < size; i++)
		if (task[i]->is_time())
			tmp[i - 1] = new ShortTask(*task[i]);
		else tmp[i - 1] = new Task(*task[i]);
	for (int i = 0; i < size; i++)
		delete task[i];
	size--;
	task = tmp;
	sort();
}
