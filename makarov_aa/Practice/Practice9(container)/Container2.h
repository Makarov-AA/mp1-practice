#pragma once

#pragma once

#include <stdlib.h>
#include <iostream>
#include <time.h>

///////////////////////ОбЪЯВЛЕНИЕ КОНТЕЙНЕРА////////////////////

template <class T>
class Container2
{
protected:
    T** x; //массив данных для хранения
    int* l_s; //текущее количество элементов в строке
    int l;//текущее количество строк
    int s;//текущее количество элементов во всем контейнере
public:
    Container2();//создает пустой контейнер
    Container2(int n = 0);//создает квадратный контейнер заданного размера
    Container2(int m = 0, int n = 0);//создает контейнер с m строками по n элементов в каждой 
    Container2(const Container2&);//создает отдельную копию уже существующего контейнера
    ~Container2();//деструктор
    T* operator [] (int);//доступ к строке контейнера
    void resize(int); //меняет контейнер на квадратный заданного размера
    void resize(int, int); //меняет контейнер на прямоугольный заданного размера
    void clear();//очищает контейнер, размер 0, указатель нулевой
    void del(int, int);//удаление по номеру: первый номер строк, второй - номер элемента в строке
	void del_l(int);//удаляет указанную строку
    void add(const T&, int);//добавление элемента с правого края заданной строки
    void add(const T&, int, int);//добавление элемента перед заданным номером, первый номер строка, второй - номер элемента в строке
	void add_l(int, T*);//добавляет строку
	void add_l(int, T*, int);//добавляет строку перед указанной
    int search(const T&, int&);//поиск элемента, в параметр помещает строку, возвращает столбец, если не обнаруживает, возвращает -1
    void print();//печать контейнера
	void print(int);//печать заданной строки контейнера
    void input();//ввод всего контейнера
	void input(int);//ввод 
    int get_size();//получение количества текущих элементов
	int get_l();//получение количества строк
	int get_l_s(int);//получение количества элементов в указанной строке
};

/////////////////////////СПЕЦИАЛИЗАЦИИ///////////////////////////

/*template <>
void Container<char>::print()
{
    for (int i = 0; i < size; i++)
        std::cout << x[i];
}*/

void int_rand_input(Container2<int>& C)//функция заполнения случайными целыми числами для демонстрации
{
    int s = C.get_size();
    srand((unsigned)time(0));
    for (int i = 0; i < s; i++)
		for (int j = 0; j < C.get_l_s(C.get_l()); j++)
			C[i][j] = std::rand();
}

////////////////////////РЕАЛИЗАЦИИ МЕТОДОВ////////////////////////

template <class T>
Container2<T>::Container2() : x(nullprt), s(0), l(0), l_s(nullptr) {}

template <class T>
Container2<T>::Container2(int n = 0) : s(n * m), l(n)
{
	if (n < 0) throw "Неверный размер контейнера";
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
    if ((n < 0) || (m < 0)) throw "Неверный размер контейнера";
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
    if ((i < 0) || (i >= l)) throw "Выход за пределы контейнера";
    return x[i];
}

template <class T>
void Container2<T>::resize(int n)
{
    if (n < 0) throw "Неверный размер контейнера";
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
	if ((n < 0) || (m < 0)) throw "Неверный размер контейнера";
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
    if ((n < 0) || (n >= l)) throw "Выход за пределы контейнера";
	if ((m < 0) || (m >= l_s[n])) throw "Выход за пределы контейнера";
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
	if ((n < 0) || (n >= l)) throw "Выход за пределы контейнера";
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
	if ((n < 0) || (n >= l)) throw "Выход за пределы контейнера";
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
	if ((n < 0) || (n >= l)) throw "Выход за пределы контейнера";
	if ((m < 0) || (m >= l_s[n])) throw "Выход за пределы контейнера";
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
	if (size < 0) throw "Неверный размер строки";
	if ((n < 0) || (n >= l)) throw "Выход за пределы контейнера";
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
