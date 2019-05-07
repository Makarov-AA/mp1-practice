#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Matrix.h"

int min(int a, int b)
{
	return a < b ? a : b;
}
Matrix::Matrix(int n, int m) : n_m(n), m_m(m)//конструктор по умолчанию
{
	if ((n <= 0) && (m <= 0)) throw "Error: incorrect matrix size\n";
	x_m = new double[n * m];
}
Matrix::Matrix(int n) : n_m(n), m_m(n)
{
	if (n <= 0) throw "Error: incorrect matrix size\n";
	x_m = new double[n * n];
}
Matrix::Matrix(const Matrix &x)//конструктор копирования
{
	n_m = x.n_m;
	m_m = x.m_m;
	x_m = new double[n_m * m_m];
	for (int i = 0; i < n_m; i++)
		for (int j = 0; j < m_m; j++)
			x_m[i*j + j] = x.x_m[i * j + j];
}
Matrix::~Matrix()//деструктор
{
	delete[] x_m;
}
std::ostream& operator<<(std::ostream &out, const Matrix &x)//вывод
{
	out << std::endl;
	for (int i = 0; i < x.n_m; i++)
	{
		for (int j = 0; j < x.m_m; j++)
			out << x.x_m[i * j + j] << " ";
		out << std::endl;
	}
	return out;
}
std::istream& operator >> (std::istream &in, const Matrix &x)//ввод
{
	for (int i = 0; i < x.n_m; i++)
		for (int j = 0; j < x.m_m; j++)
			in >> x.x_m[i * j + j];
	return in;
}
Matrix Matrix::operator+(const Matrix &x) const //сложение матриц
{
	if ((n_m != x.n_m) && (m_m != x.m_m)) throw "Error: different sizes of vectors\n";
	Matrix sum(n_m, m_m);
	for (int i = 0; i < n_m; i++)
		for (int j = 0; j < m_m; j++)
			sum.x_m[i * j + j] = x_m[i * j + j] + x.x_m[i * j + j];
	return sum;
}
Matrix Matrix::operator-(const Matrix &x) const //вычитание матриц
{
	if ((n_m != x.n_m) && (m_m != x.m_m)) throw "Error: different sizes of vectors\n";
	Matrix dif(n_m, m_m);
	for (int i = 0; i < n_m; i++)
		for (int j = 0; j < m_m; j++)
			dif.x_m[i * j + j] = x_m[i * j + j] - x.x_m[i * j + j];
	return dif;
}
 Matrix Matrix::operator*(const Matrix &x) const//скалярное произведение матриц
{
	if (n_m != x.m_m) throw "Error: different sizes of vectors\n";
	Matrix mlp(0);
	for (int i = 0; i < n_m; i++)
		for (int j = 0; j < x.m_m; j++)
			for (int k = 0; k < min(m_m, x.n_m); k++)

	return mlp;
}
Matrix Matrix::operator+(const double x) const // прибавление константы
{
	Matrix sum(n_m);
	for (int i = 0; i < n_m; i++)
		sum.x_m[i] = x_m[i] + x;
	return sum;
}
Matrix Matrix::operator-(const double x) const // вычитание константы
{
	Matrix dif(n_m);
	for (int i = 0; i < n_m; i++)
		dif.x_m[i] = x_m[i] - x;
	return dif;
}
Matrix Matrix::operator*(const double x) const // умножение на константу
{
	Matrix mlp(n_m);
	for (int i = 0; i < n_m; i++)
		mlp.x_m[i] = x_m[i] * x;
	return mlp;
}
Matrix Matrix::operator/(const double x) const // деление на константу
{
	if (x == 0) throw "Error: 0 division is impossible\n";
	Matrix div(n_m);
	for (int i = 0; i < n_m; i++)
		div.x_m[i] = x_m[i] / x;
	return div;
}
Matrix& Matrix::operator=(const Matrix &x) // присваивание
{
	if (n_m != x.n_m)
	{
		delete[] x_m;
		x_m = new double[x.n_m];
	}
	n_m = x.n_m;
	for (int i = 0; i < n_m; i++)
		x_m[i] = x.x_m[i];
	return (*this);
}
Matrix Matrix::operator+=(const Matrix x) // += для векторов
{
	if (n_m != x.n_m) throw "Error: different sizes of vectors\n";
	for (int i = 0; i < n_m; i++)
		x_m[i] += x.x_m[i];
	return (*this);
}
Matrix Matrix::operator-=(const Matrix x) // -= для векторов
{
	if (n_m != x.n_m) throw "Error: different sizes of vectors\n";
	for (int i = 0; i < n_m; i++)
		x_m[i] -= x.x_m[i];
	return (*this);
}
Matrix Matrix::operator+=(const double x)//+= для констант
{
	for (int i = 0; i < n_m; i++)
		x_m[i] += x;
	return (*this);
}
Matrix Matrix::operator-=(const double x)// -= для констант
{
	for (int i = 0; i < n_m; i++)
		x_m[i] -= x;
	return (*this);
}
Matrix Matrix::operator*=(const double x)// *= для констант
{
	for (int i = 0; i < n_m; i++)
		x_m[i] *= x;
	return (*this);
}
Matrix Matrix::operator/=(const double x)// /= для констант
{
	if (x == 0) throw "Error: 0 division is impossible\n";
	for (int i = 0; i < n_m; i++)
		x_m[i] /= x;
	return (*this);
}
int Matrix::get_size() const { return n_m; }// геттер для для размерности
double& Matrix::operator[](int i) const //получение ссылки на i-ую координату
{
	if (i > n_m - 1) throw "Error: out of dimension\n";
	return x_m[i];
}
double Matrix::length() const//длина
{
	double l(0);
	for (int i = 0; i < n_m; i++)
		l += x_m[i] * x_m[i];
	return sqrt(l);
}
double Matrix::angle(Matrix x) const//угол между двумя векторами
{
	double a;
	a = x * (*this) / length() / x.length();
	return a;
}