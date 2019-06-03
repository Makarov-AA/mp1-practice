#pragma once

#include <stdlib.h>
#include <iostream>
#include <time.h>

///////////////////////���������� ����������////////////////////
 
template <class T>
class Container 
{
protected:
    T* x; //������ ������ ��� ��������
    int size; //������� ���������� ���������
public:
    Container();//������� ������ ���������
    Container(int);//������� ��������� ��������� �������
    Container(const Container&);//������� ��������� ����� ��� ������������� ����������
    ~Container();//����������
    T& operator [] (int);//������ � ��������� ����������
    void resize(int);
    void clear();
    void del(int);//�������� �� ������
    void add(const T&);//���������� �������� � ������� ����
    void add(const T&, int);//���������� �������� ����� �������� �������
    int search(const T&);//����� ��������, ���� �� ������������, ���������� -1
    virtual void print();
    friend std::ostream& operator << (std::ostream&, const Container&);//������ ���������� ����� �������� <<
    void input();
    //friend std::istream& operator >> (std::istream&, Container&);//���� ����� ������� ����� >>
    int get_size();//��������� ���������� ������� ���������
};

/////////////////////////�������������///////////////////////////

template <>
void Container<char>::print()
{
    for (int i = 0; i < size; i++)
        std::cout << x[i];
}

void int_rand_input(Container<int>& C)//������� ���������� ���������� ������ ������� ��� ������������
{
    int s = C.get_size();
    srand((unsigned)time(0));
    for (int i = 0; i < s; i++)
    {
        C[i] = std::rand();
    }
}

////////////////////////���������� �������////////////////////////

template <class T>
Container<T>::Container() : x(nullprt), size(0) {}

template <class T>
Container<T>::Container(int n) : size(n)
{
    if (n < 0) throw "�������� ������ ����������";
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
    if ((i < 0) || (i >= size)) throw "����� �� ������� ����������";
    return x[i];
}

int min(int a, int b)
{
    return a < b ? a : b;
}

template <class T>
void Container<T>::resize(int n)
{
    if (n < 1) throw "�������� ������ ����������";
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
    if ((k < 0) || (k >= size)) throw "����� �� ������� ����������";
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
    if ((k < 0) || (k >= size)) throw "����� �� ������� ����������";
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