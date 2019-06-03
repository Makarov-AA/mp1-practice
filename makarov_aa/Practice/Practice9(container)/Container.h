#pragma once

#include <stdlib.h>
#include <iostream>
#include <time.h>

///////////////////////ОбЪЯВЛЕНИЕ КОНТЕЙНЕРА////////////////////
 
template <class T>
class Container 
{
protected:
    T* x; //массив данных для хранения
    int size; //текущее количество элементов
public:
    Container();//создает пустой контейнер
    Container(int);//создает контейнер заданного размера
    Container(const Container&);//создает отдельную копию уже существующего контейнера
    ~Container();//деструктор
    T& operator [] (int);//доступ к элементам контейнера
    void resize(int);
    void clear();
    void del(int);//удаление по номеру
    void add(const T&);//добавление элемента с правого края
    void add(const T&, int);//добавление элемента перед заданным номером
    int search(const T&);//поиск элемента, если не обнаруживает, возвращает -1
    virtual void print();
    friend std::ostream& operator << (std::ostream&, const Container&);//печать контейнера через оператор <<
    void input();
    //friend std::istream& operator >> (std::istream&, Container&);//ввод всего массива через >>
    int get_size();//получение количества текущих элементов
};

/////////////////////////СПЕЦИАЛИЗАЦИИ///////////////////////////

template <>
void Container<char>::print()
{
    for (int i = 0; i < size; i++)
        std::cout << x[i];
}

void int_rand_input(Container<int>& C)//функция заполнения случайными целыми числами для демонстрации
{
    int s = C.get_size();
    srand((unsigned)time(0));
    for (int i = 0; i < s; i++)
    {
        C[i] = std::rand();
    }
}

////////////////////////РЕАЛИЗАЦИИ МЕТОДОВ////////////////////////

template <class T>
Container<T>::Container() : x(nullprt), size(0) {}

template <class T>
Container<T>::Container(int n) : size(n)
{
    if (n < 0) throw "Неверный размер контейнера";
    if (n == 0) 
        x = nullptr;
    else 
        x = new T[size];
}

template <class T>
Container<T>::Container(const Container& C) : size(C.size)
{
    x = new T[size];
    for (int i = 0; i < size; i++)
        x[i] = C.x[i];
}

template <class T>
Container<T>::~Container()
{
    delete[] x;
}

template <class T>
T& Container<T>::operator [] (int i)
{
    if ((i < 0) || (i >= size)) throw "Выход за пределы контейнера";
    return x[i];
}

int min(int a, int b)
{
    return a < b ? a : b;
}

template <class T>
void Container<T>::resize(int n)
{
    if (n < 1) throw "Неверный размер контейнера";
    T* tmp = new T[n];
    int k = min(size, n);
    for (int i = 0; i < k; i++)
        tmp[i] = x[i];
    delete x;
    x = tmp;
    size = n;
}

template <class T>
void Container<T>::clear()
{
    delete[] x;
    x = nullptr;
    size = 0;
}

template <class T>
void Container<T>::del(int k)
{
    if ((k < 0) || (k >= size)) throw "Выход за пределы контейнера";
    T* tmp = new T[size - 1];
    for (int i = 0; i < k; i++)
        tmp[i] = x[i];
    for (int i = k + 1; i < size; i++)
        tmp[i - 1] = x[i];
    delete[] x;
    x = tmp;
    size--;
}

template <class T>
void Container<T>::add(const T& item)
{
    T* tmp = new T[size + 1];
    for (int i = 0; i < size; i++)
        tmp[i] = x[i];
    tmp[size++] = item;
    delete[] x;
    x = tmp;
}

template <class T>
void Container<T>::add(const T& item, int k)
{
    if ((k < 0) || (k >= size)) throw "Выход за пределы контейнера";
    T* tmp = new T[size + 1];
    for (int i = 0; i < k; i++)
        tmp[i] = x[i];
    tmp[k] = item;
    for (int i = k + 1; i < size + 1; i++)
        tmp[i] = x[i - 1];
    delete[] x;
    x = tmp;
    size++;
}

template <class T>
int Container<T>::search(const T& item)
{
    for (int i = 0; i < size; i++)
        if (x[i] == item) return i;
    return -1;
}

template <class T>
void Container<T>::print()
{
    for (int i = 0; i < size - 1; i++)
        std::cout << x[i] << ' ';
    std::cout << x[size - 1];
}

template <class T>
std::ostream& operator << (std::ostream& out, const Container<T>& C)
{
    for (int i = 0; i < size - 1; i++)
        out << x[i] << ' ';
    out << x[size - 1];
    return out;
}

template <class T>
void Container<T>::input()
{
    for (int i = 0; i < size; i++)
        std::cin >> x[i];
}

/*template <class T>
std::istream& operator >> (std::istream& in, Container<T>& C)
{
    for (int i = 0; i < size; i++)
        in >> x[i];
    return in;
}*/

template <class T>
int Container<T>::get_size()
{
    return size;
}