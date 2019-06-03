#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include "Time.h"
#include "Date.h"

class Task
{
protected:
    std::string s;
    Date date;
    int n;
public:
    ~Task();
    Task();
    Task(Date d);
    Task(const Task &t);
    std::string get_string();
    int get_n();
    void set_n(int num);
    Date get_date();
    void set_date(Date d);
    virtual void input();
    virtual void output();
    virtual bool is_time();
    virtual Time get_time();
    virtual Task& operator = (const Task &t);
};

class ShortTask: public Task
{
    Time time;
public:
    ShortTask(Date d);
    ShortTask(const ShortTask &t);
    ShortTask(Task &t);
    Time get_time();
    void set_time(Time t);
    void input();
    void output();
    bool is_time();
    ShortTask& operator = (const ShortTask &t);
};