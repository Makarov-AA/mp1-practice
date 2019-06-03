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
    for (int i = 0; i < (n_m * m_m); i++)
        x_m[i] = x.x_m[i];
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
            out << x.x_m[i * x.m_m + j] << " ";
        out << std::endl;
    }
    return out;
}
std::istream& operator>>(std::istream &in, const Matrix &x)//ввод
{
    for (int i = 0; i < (x.n_m * x.m_m); i++)
            in >> x.x_m[i];
    return in;
}
Matrix Matrix::operator+(const Matrix &x) const //сложение матриц
{
    if ((n_m != x.n_m) && (m_m != x.m_m)) throw "Error: different sizes of matrix\n";
    Matrix sum(n_m, m_m);
    for (int i = 0; i < (n_m * m_m); i++)
            sum.x_m[i] = x_m[i] + x.x_m[i];
    return sum;
}
Matrix Matrix::operator-(const Matrix &x) const //вычитание матриц
{
    if ((n_m != x.n_m) && (m_m != x.m_m)) throw "Error: different sizes of matrix\n";
    Matrix dif(n_m, m_m);
    for (int i = 0; i < (n_m * m_m); i++)
        dif.x_m[i] = x_m[i] - x.x_m[i];
    return dif;
}
 Matrix Matrix::operator*(const Matrix &x) const//произведение матриц
{
    if (n_m != x.m_m) throw "Error: different sizes of lines and columns\n";
    Matrix mlp(n_m, x.m_m);
    for (int i = 0; i < n_m; i++)
        for (int j = 0; j < x.m_m; j++)
        {
            mlp.x_m[i * mlp.m_m + j] = 0;
            for (int k = 0; k < min(m_m, x.n_m); k++)
                mlp.x_m[i * mlp.m_m + j] += x_m[i * m_m + k] * x.x_m[k * x.m_m + j];
        }
    return mlp;
}
Matrix Matrix::operator+(const double x) const // прибавление константы
{
    if (n_m != m_m) throw "Error: matrix should be square\n";
    Matrix sum(*this);
    for (int i = 0; i < n_m; i++)
        sum.x_m[i * m_m + i] += x;
    return sum;
}
Matrix Matrix::operator-(const double x) const // вычитание константы
{
    if (n_m != m_m) throw "Error: matrix should be square\n";
    Matrix dif(*this);
    for (int i = 0; i < n_m; i++)
        dif.x_m[i * m_m + i] -= x;
    return dif;
}
Matrix Matrix::operator*(const double x) const // умножение на константу
{
    Matrix mlp(*this);
    for (int i = 0; i < (n_m * m_m); i++)
        mlp.x_m[i] *= x;
    return mlp;
}
Matrix Matrix::operator/(const double x) const // деление на константу
{
    if (x == 0) throw "Error: 0 division is impossible\n";
    Matrix div(*this);
    for (int i = 0; i < (n_m * m_m); i++)
        div.x_m[i] /= x;
    return div;
}
Matrix& Matrix::operator=(const Matrix &x) // присваивание
{
    if ((n_m != x.n_m) && (m_m != x.m_m))
    {
        n_m = x.n_m;
        m_m = x.m_m;
        delete[] x_m;
        x_m = new double[n_m * m_m];
    }
    for (int i = 0; i < (n_m * m_m); i++)
        x_m[i] = x.x_m[i];
    return *this;
}
Matrix Matrix::operator+=(const Matrix &x) // += для матриц
{
    if ((n_m != x.n_m) && (m_m != x.m_m)) throw "Error: different sizes of matrix\n";
    for (int i = 0; i < (n_m * m_m); i++)
        x_m[i]+= x.x_m[i];
    return *this;
}
Matrix Matrix::operator-=(const Matrix &x) // -= для матриц
{
    if ((n_m != x.n_m) && (m_m != x.m_m)) throw "Error: different sizes of matrix\n";
    for (int i = 0; i < (n_m * m_m); i++)
        x_m[i] -= x.x_m[i];
    return *this;
}
Matrix Matrix::operator*=(const Matrix &x)//*= для матриц
{
    if (n_m != x.m_m) throw "Error: different sizes of lines and columns\n";
    Matrix mlp(n_m, x.m_m);
    for (int i = 0; i < n_m; i++)
        for (int j = 0; j < x.m_m; j++)
        {
            mlp.x_m[i * mlp.m_m + j] = 0;
            for (int k = 0; k < min(m_m, x.n_m); k++)
                mlp.x_m[i * mlp.m_m + j] += x_m[i * m_m + k] * x.x_m[k * x.m_m + j];
        }
    *this = mlp;
    return *this;
}
Matrix Matrix::operator+=(const double x)//+= для констант
{
    if (n_m != m_m) throw "Error: matrix should be square\n";
    for (int i = 0; i < n_m; i++)
        x_m[i * m_m + i] += x;
    return *this;
}
Matrix Matrix::operator-=(const double x)//-= для констант
{
    if (n_m != m_m) throw "Error: matrix should be square\n";
    for (int i = 0; i < n_m; i++)
        x_m[i * m_m + i] -= x;
    return *this;
}
Matrix Matrix::operator*=(const double x)// *= для констант
{
    for (int i = 0; i < (n_m * m_m); i++)
        x_m[i] *= x;
    return (*this);
}
Matrix Matrix::operator/=(const double x)// /= для констант
{
    if (x == 0) throw "Error: 0 division is impossible\n";
    for (int i = 0; i < (n_m * m_m); i++)
        x_m[i] /= x;
    return (*this);
}
double* Matrix::operator[](int i) const //получение ссылки на i-ую строку
{
    if (i >= n_m) throw "Error: out of dimension\n";
    return x_m + (i * m_m);
}
void Matrix::dif(int k, double a, int m, double b)
{
    for (int i = 0; i < m_m; i++)
    {
        x_m[k * m_m + i] *= a;
        x_m[k * m_m + i] -= x_m[m * m_m + i] * b;
    }
}
Matrix Matrix::invert() const
{
    if (n_m != m_m) throw "Error: matrix should be square\n";
    Matrix inv(n_m, m_m), tmp(*this);
    for (int i = 0; i < n_m; i++)
        for (int j = 0; j < n_m; j++)
            inv[i][j] = 0;
    for (int i = 0; i < n_m; i++)
        inv[i][i] = 1;
    for (int j = 0; j < m_m; j++)
        for (int i = j + 1; i < n_m; i++)
        {
            inv.dif(i, tmp[j][j], j, tmp[i][j]);
            tmp.dif(i, tmp[j][j], j, tmp[i][j]);
        }
    for (int j = n_m - 1; j > -1; j--)
    {
        for (int i = 0; i > m_m; i++)
            inv[j][i] /= tmp[j][j];
        for (int k = j - 1; k > -1; k--)
            inv.dif(k, 1, j, tmp[j - 1][j]);
    }
    return inv;
}
Matrix Matrix::transp() const
{
    Matrix tr(m_m, n_m);
    for (int j = 0; j < m_m; j++)
        for (int i = 0; i < n_m; i++)
            tr[j][i] = (*this)[i][j];
    return tr;
}
