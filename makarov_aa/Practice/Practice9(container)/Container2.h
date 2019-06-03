#pragma once

#pragma once

#include <stdlib.h>
#include <iostream>
#include <time.h>

///////////////////////���������� ����������////////////////////

template <class T>
class Container2
{
protected:
    T** x; //������ ������ ��� ��������
    int* l_s; //������� ���������� ��������� � ������
    int l;//������� ���������� �����
    int s;//������� ���������� ��������� �� ���� ����������
public:
    Container2();//������� ������ ���������
    Container2(int n = 0);//������� ���������� ��������� ��������� �������
    Container2(int m = 0, int n = 0);//������� ��������� � m �������� �� n ��������� � ������ 
    Container2(const Container2&);//������� ��������� ����� ��� ������������� ����������
    ~Container2();//����������
    T* operator [] (int);//������ � ������ ����������
    void resize(int); //������ ��������� �� ���������� ��������� �������
    void resize(int, int); //������ ��������� �� ������������� ��������� �������
    void clear();//������� ���������, ������ 0, ��������� �������
    void del(int, int);//�������� �� ������: ������ ����� �����, ������ - ����� �������� � ������
	void del_l(int);//������� ��������� ������
    void add(const T&, int);//���������� �������� � ������� ���� �������� ������
    void add(const T&, int, int);//���������� �������� ����� �������� �������, ������ ����� ������, ������ - ����� �������� � ������
	void add_l(int, T*);//��������� ������
	void add_l(int, T*, int);//��������� ������ ����� ���������
    int search(const T&, int&);//����� ��������, � �������� �������� ������, ���������� �������, ���� �� ������������, ���������� -1
    void print();//������ ����������
	void print(int);//������ �������� ������ ����������
    void input();//���� ����� ����������
	void input(int);//���� 
    int get_size();//��������� ���������� ������� ���������
	int get_l();//��������� ���������� �����
	int get_l_s(int);//��������� ���������� ��������� � ��������� ������
};

/////////////////////////�������������///////////////////////////

/*template <>
void Container<char>::print()
{
    for (int i = 0; i < size; i++)
        std::cout << x[i];
}*/

void int_rand_input(Container2<int>& C)//������� ���������� ���������� ������ ������� ��� ������������
{
    int s = C.get_size();
    srand((unsigned)time(0));
    for (int i = 0; i < s; i++)
		for (int j = 0; j < C.get_l_s(C.get_l()); j++)
			C[i][j] = std::rand();
}

////////////////////////���������� �������////////////////////////

template <class T>
Container2<T>::Container2() : x(nullprt), s(0), l(0), l_s(nullptr) {}

template <class T>
Container2<T>::Container2(int n = 0) : s(n * m), l(n)
{
	if (n < 0) throw "�������� ������ ����������";
	if (n == 0)
	{
		x = nullptr;
		l_s = nullptr;
	}
	else
	{
		x = new T*[n];
		for (int i = 0; i < n; i++)
			x[i] = new t[n];
		l_s = new int[n];
		for (int i = 0; i < n; i++)
			l_s[i] = n;
	}
}

template <class T>
Container2<T>::Container2(int n = 0, int m = 0) : s(n * m), l(n)
{
    if ((n < 0) || (m < 0)) throw "�������� ������ ����������";
	if ((n == 0) && (m == 0))
	{
		x = nullptr;
		l_s = nullptr;
	}
	else
	{
		x = new T*[n];
		for (int i = 0; i < n; i++)
			x[i] = new T[m];
		l_s = new int[n];
		for (int i = 0; i < n; i++)
			l_s[i] = m;
	}
}

template <class T>
Container2<T>::Container2(const Container2& C) : s(C.s), l(C.l)
{
	l_s = new int[l];
	for (int i = 0; i < l; i++)
		l_s[i] = C.l_s[i];
    for (int i = 0; i < l; i++)
		for (int j = 0; j < l_s[i]; j++)
			x[i][j] = C.x[i][j];
}

template <class T>
Container2<T>::~Container2()
{
	for (int i = 0; i < l; i++)
		delete[] x[i];
    delete[] x;
}

template <class T>
T* Container2<T>::operator [] (int i)
{
    if ((i < 0) || (i >= l)) throw "����� �� ������� ����������";
    return x[i];
}

template <class T>
void Container2<T>::resize(int n)
{
    if (n < 0) throw "�������� ������ ����������";
	if (n == 0) clear();
	else
	{
		T** tmp = new T*[n];
		int k = n < l ? n : l;
		for (int i = 0; i < k; i++)
		{
			int c = n < l_s[i] ? n : l_s[i];
			for (int i = 0; i < c; i)
				tmp[i][j] = x[i][j]; 
		}
		for (int i = 0; i < l; i++)
			delete[] x[i];
		delete[] x;
		x = tmp;
		l = n;
		for (int i = 0; i < l; i++)
			l_s[i] = n;
		s = n * n;
	}
}

template <class T>
void Container2<T>::resize(int n, int m)
{
	if ((n < 0) || (m < 0)) throw "�������� ������ ����������";
	if ((n == 0) || (m == 0)) clear();
	else
	{
		T** tmp = new T*[n];
		int k = n < l ? n : l;
		for (int i = 0; i < k; i++)
		{
			int c = m < l_s[i] ? m : l_s[i];
			for (int i = 0; i < c; i)
				tmp[i][j] = x[i][j];
		}
		for (int i = 0; i < l; i++)
			delete[] x[i];
		delete[] x;
		x = tmp;
		l = n;
		for (int i = 0; i < l; i++)
			l_s[i] = m;
		s = n * m;
	}
}

template <class T>
void Container2<T>::clear()
{
	for (int i = 0; i < l; i++)
		delete[] x[i];
    delete[] x;
    x = nullptr;
	delete[] l_s;
	l_s = nullptr;
	l = 0;
	s = 0;
}

template <class T>
void Container2<T>::del(int n, int m)
{
    if ((n < 0) || (n >= l)) throw "����� �� ������� ����������";
	if ((m < 0) || (m >= l_s[n])) throw "����� �� ������� ����������";
	if (l_s[n] == 1) del_l(n);
	else
	{
		T* tmp = new T[l_s[n] - 1];
		for (int i = 0; i < m; i++)
			tmp[i] = x[n][i];
		for (int i = m + 1; i < l_s[n]; i++)
			tmp[i] = x[n][i];
		delete[] x[n];
		x[n] = tmp;
		s--;
		l_s[n]--;
	}
}

template <class T>
void Container2<T>::del_l(int n)
{
	if ((n < 0) || (n >= l)) throw "����� �� ������� ����������";
	if (l == 1) clear();
	else
	{
		T** tmp = new T*[l - 1];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < l_s[i]; j++)
				tmp[i][j] == x[i][j];
		for (int i = n + 1; i < l; i++)
			for (int j = 0; j < l_s[i]; j++)
				tmp[i][j] == x[i][j];
		for (int i = 0; i < l; i++)
			delete[] x[i];
		delete[] x;
		x = tmp;
		int* tmp_l = new int[l - 1];
		s -= s_l[n];
		for (int i = 0; i < n; i++)
			tmp_l[i] = s_l[i];
		for (int i = n + 1; i < l; i++)
			tmp_l[i] = s_l[i];
		delete[] s_l;
		s_l = tmp_l;
		l--;
	}
}

template <class T>
void Container2<T>::add(const T& item, int n)
{
	if ((n < 0) || (n >= l)) throw "����� �� ������� ����������";
    T* tmp = new T[l_s[n] + 1];
    for (int i = 0; i < l_s[n]; i++)
        tmp[i] = x[n][i];
    tmp[l_s[n]++] = item;
    delete[] x[n];
    x[n] = tmp;
	s++;
}

template <class T>
void Container2<T>::add(const T& item, int n, int m)
{
	if ((n < 0) || (n >= l)) throw "����� �� ������� ����������";
	if ((m < 0) || (m >= l_s[n])) throw "����� �� ������� ����������";
    T* tmp = new T[size + 1];
    for (int i = 0; i < m; i++)
        tmp[i] = x[n][i];
    tmp[m] = item;
    for (int i = m + 1; i < l_s[n] + 1; i++)
        tmp[i] = x[n][i - 1];
    delete[] x[n];
    x[n] = tmp;
    s++;
	l_s[n]++;
}

template <class T>
void Container2<T>::add_l(int size, T* line)
{
	if (size < 0) throw "Wrong line size";
	T** tmp = new T*[l + 1];
	for (int i = 0; i < l; i++)
		for (int j = 0; j < l_s[i]; j++)
			tmp[i][j] = x[i][j];
	for (int i = 0; i < size; i++)
		tmp[l][i] = line[i];
	for (int i = 0; i < l; i++)
		delete[] x[i];
	delete[] x;
	x = tmp;
	l_s[l] = size;
	l++;
	s += size;
}

template <class T>
void Container2<T>::add_l(int size, T* line, int n)
{
	if (size < 0) throw "�������� ������ ������";
	if ((n < 0) || (n >= l)) throw "����� �� ������� ����������";
	T** tmp = new T*[l + 1];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tmp[i][j] = x[i][j];
	for (int i = 0; i < size; i++)
		tmp[n][i] = line[i];
	for (int i = n + 1; i < l + 1; i++)
		for (int j = 0; j < l_s[i - 1]; j++)
			tmp[i][j] = x[i - 1][j];
	for (int i = 0; i < l; i++)
		delete[] x[i];
	delete x;
	x = tmp;
	int* tmp_l = new int[l + 1];
	for (int i = 0; i < n; i++)
		tmp_l[i] = l_s[i];
	tmp_l[n] = size;
	for (int i = n + 1; i < l + 1; i++)
		tmp_l[i] = l_s[i - 1];
	delete l_s;
	l_s = tmp_l;
	s += size;
	l++;
}

template <class T>
int Container2<T>::search(const T& item, int& n)
{
    for (int i = 0; i < l; i++)
		for (int j = 0; j < l_s[i]; j++)
			if (x[i] == item)
			{
				n = i;
				return j;
			}
    return -1;
}

template <class T>
void Container2<T>::print()
{
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < l_s[i] - 1; j++)
			std::cout << x[i] << ' ';
		std::cout << x[l_s[i] - 1] << endl;
	}
}

template <class T>
void Container2<T>::print(int n)
{
	for (int i = 0; i < l_s[n] - 1; i++)
		std::cout << x[n][i] << ' ';
	std::cout << x[n][l_s[n] - 1];
}

template <class T>
void Container2<T>::input()
{
	for (int i = 0; i < l; i++)
		for (int j = 0; j < l_s[i]; j++)
			std::cin >> x[i][j];
}

template <class T>
void Container2<T>::input(int n)
{
    for (int i = 0; i < l_s[n]; i++)
        std::cin >> x[n][i];
}

template <class T>
int Container2<T>::get_size()
{
    return s;
}

template <class T>
int Container2<T>::get_l()
{
	return l;
}

template <class T>
int Container2<T>::get_l_s(int i)
{
	return l_s[i];
}
