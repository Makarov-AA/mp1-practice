#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "N_vector.h"

N_vector::N_vector(int a) : n_m(a)//конструктор по умолчанию
{
	if (a <= 0) throw "Error: incorrect vector size\n";
	x_m = new double(a);
}
N_vector::N_vector(const N_vector &x)//конструктор копирования
{
	n_m = x.n_m;
	x_m = new double(n_m);
	for (int i = 0; i < n_m; i++)
		x_m[i] = x.x_m[i];
}
N_vector::~N_vector()//деструктор
{
	delete x_m;
}
std::ostream& operator<<(std::ostream &out, const N_vector &x)//вывод
{
	out << x.x_m[0];
	for (int i = 1; i < x.n_m; i++)
		out << "  " << x.x_m[i];
	out << "\n" << "Size " << x.n_m << "\n";
	return out;
}
std::istream& operator >> (std::istream &in, const N_vector &x)//ввод
{
	for (int i = 0; i < x.n_m; i++)
		in >> x.x_m[i];
	return in;
}
N_vector N_vector::operator+(const N_vector x) const //сложение векторов
{
	if (n_m != x.n_m) throw "Error: different sizes of vectors\n";
	N_vector sum(n_m);
	for (int i = 0; i < n_m; i++)
		sum.x_m[i] = x_m [i] + x.x_m[i];
	return sum;
}
N_vector N_vector::operator-(const N_vector x) const //вычитание векторов
{
	if (n_m != x.n_m) throw "Error: different sizes of vectors\n";
	N_vector dif(n_m);
	for (int i = 0; i < n_m; i++)
		dif.x_m[i] = x_m[i] - x.x_m[i];
	return dif;
}
double N_vector::operator*(const N_vector x) const//скалярное произведение векторов
{
	if (n_m != x.n_m) throw "Error: different sizes of vectors\n";
	double mlp(n_m);
	for (int i = 0; i < n_m; i++)
		mlp.x_m[i] = x_m[i] * x.x_m[i];
	return mlp;
}
N_vector N_vector::operator+(const double x) const // прибавление константы
{
	N_vector sum(n_m);
	for (int i = 0; i < n_m; i++)
		sum.x_m[i] = x_m[i] + x;
	return sum;
}
N_vector N_vector::operator-(const double x) const // вычитание константы
{
	N_vector dif(n_m);
	for (int i = 0; i < n_m; i++)
		dif.x_m[i] = x_m[i] - x;
	return dif;
}
N_vector N_vector::operator*(const double x) const // умножение на константу
{
	N_vector mlp(n_m);
	for (int i = 0; i < n_m; i++)
		mlp.x_m[i] = x_m[i] * x;
	return mlp;
}
N_vector N_vector::operator/(const double x) const // деление на константу
{
	if (x == 0) throw "Error: 0 division is impossible\n";
	N_vector div(n_m);
	for (int i = 0; i < n_m; i++)
		div.x_m[i] = x_m[i] / x;
	return div;
}
N_vector& N_vector::operator=(const N_vector &x) // присваивание
{
	if (n_m != x.n_m)
	{
		delete x_m;
		x_m = new double(x.n_m);
	}
	n_m = x.n_m;
	for (int i = 0; i < n_m; i++)
		x_m[i] = x.x_m[i];
	return (*this);
}
N_vector N_vector::operator+=(const N_vector x) // += для векторов
{
	if (n_m != x.n_m) throw "Error: different sizes of vectors\n";
	for (int i = 0; i < n_m; i++)
		x_m[i] += x.x_m[i];
	return (*this);
}
N_vector N_vector::operator-=(const N_vector x) // -= для векторов
{
	if (n_m != x.n_m) throw "Error: different sizes of vectors\n";
	for (int i = 0; i < n_m; i++)
		x_m[i] -= x.x_m[i];
	return (*this);
}
//N_vector N_vector::operator*=(const N_vector x)
{
	if (n_m != x.n_m) throw "Error: different sizes of vectors\n";
	for (int i = 0; i < n_m; i++)
		x_m[i] *= x.x_m[i];
	return (*this);
}
N_vector N_vector::operator+=(const double x)//+= для констант
{
	for (int i = 0; i < n_m; i++)
		x_m[i] += x;
	return (*this);
}
N_vector N_vector::operator-=(const double x)// -= для констант
{
	for (int i = 0; i < n_m; i++)
		x_m[i] -= x;
	return (*this);
}
N_vector N_vector::operator*=(const double x)// *= для констант
{
	for (int i = 0; i < n_m; i++)
		x_m[i] *= x;
	return (*this);
}
N_vector N_vector::operator/=(const double x)// /= для констант
{
	if (x == 0) throw "Error: 0 division is impossible\n";
	for (int i = 0; i < n_m; i++)
		x_m[i] /= x;
	return (*this);
}
int N_vector::get_s() const { return n_m; }// геттер для для размерности
double& N_vector::operator[](int i) const //получение ссылки на i-ую координату
{
	if (i > n_m - 1) throw "Error: out of dimension\n";
	return x_m[i];
}
double N_vector::length() const//длина
{
	double l(0);
	for (int i = 0; i < n_m; i++)
		l += x_m[i] * x_m[i];
	return sqrt(l);
}
double N_vector::angle(N_vector x) const//угол между двумя векторами
{
	double a;
	a = x * (*this) / length() / x.length();
	return a;
}