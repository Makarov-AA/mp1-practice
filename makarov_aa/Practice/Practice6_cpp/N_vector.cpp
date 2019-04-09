#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "N_vector.h"

N_vector::N_vector(int a) : n_m(a)//конструктор по умолчанию
{
	x_m = new double(a);
}
N_vector::N_vector(const N_vector &x)//конструктор копирования
{
	x_m = x.x_m;
	n_m = x.n_m;
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
	in >> x.n_m;
	for (int i = 0; i < x.n_m; i++)
		in >> x.x_m[i];
	return in;
}
N_vector N_vector::operator+(const N_vector x) const
{
	N_vector sum(n_m);
	for (int i = 0; i < n_m; i++)
		sum.x_m[i] = x_m [i] + x.x_m[i];
	return sum;
}
N_vector N_vector::operator-(const N_vector x) const
{
	N_vector dif(n_m);
	for (int i = 0; i < n_m; i++)
		dif.x_m[i] = x_m[i] - x.x_m[i];
	return dif;
}
N_vector N_vector::operator*(const N_vector x) const
{
	N_vector mlp(n_m);
	for (int i = 0; i < n_m; i++)
		mlp.x_m[i] = x_m[i] * x.x_m[i];
	return mlp;
}
N_vector N_vector::operator+(const double x) const
{
	N_vector sum(n_m);
	for (int i = 0; i < n_m; i++)
		sum.x_m[i] = x_m[i] + x;
	return sum;
}
N_vector N_vector::operator-(const double x) const
{
	N_vector dif(n_m);
	for (int i = 0; i < n_m; i++)
		dif.x_m[i] = x_m[i] - x;
	return dif;
}
N_vector N_vector::operator*(const double x) const
{
	N_vector mlp(n_m);
	for (int i = 0; i < n_m; i++)
		mlp.x_m[i] = x_m[i] * x;
	return mlp;
}
N_vector N_vector::operator/(const double x) const
{
	N_vector div(n_m);
	for (int i = 0; i < n_m; i++)
		div.x_m[i] = x_m[i] / x;
	return div;
}
N_vector& N_vector::operator=(const N_vector &x)
{
	n_m = x.n_m;
	for (int i = 0; i < n_m; i++)
		x_m[i] = x.x_m[i];
	return (*this);
}
N_vector N_vector::operator+=(const N_vector x)
{
	for (int i = 0; i < n_m; i++)
		x_m[i] += x.x_m[i];
	return (*this);
}
N_vector N_vector::operator-=(const N_vector x)
{
	for (int i = 0; i < n_m; i++)
		x_m[i] -= x.x_m[i];
	return (*this);
}
N_vector N_vector::operator*=(const N_vector x)
{
	for (int i = 0; i < n_m; i++)
		x_m[i] *= x.x_m[i];
	return (*this);
}
N_vector N_vector::operator+=(const double x)
{
	for (int i = 0; i < n_m; i++)
		x_m[i] += x;
	return (*this);
}
N_vector N_vector::operator-=(const double x)
{
	for (int i = 0; i < n_m; i++)
		x_m[i] -= x;
	return (*this);
}
N_vector N_vector::operator*=(const double x)
{
	for (int i = 0; i < n_m; i++)
		x_m[i] *= x;
	return (*this);
}
N_vector N_vector::operator/=(const double x)
{
	for (int i = 0; i < n_m; i++)
		x_m[i] /= x;
	return (*this);
}
int N_vector::get_s() const { return n_m; }
double& N_vector::operator[](int i) const
{
	return x_m[i];
}
double N_vector::length() const
{
	double l(0);
	for (int i = 0; i < n_m; i++)
		l += x_m[i] * x_m[i];
	return sqrt(l);
}
double angle(N_vector x) const
{
	double a;
	a 
}