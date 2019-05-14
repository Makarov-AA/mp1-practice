#pragma once
class Matrix
{
	int n_m;//строки
	int m_m;//столбцы
	double* x_m;
	void Matrix::dif(int k, double a, int m, double b);
public:
	Matrix(int n, int m);//конструктор 
	Matrix(int n = 3);//конструктор по умолчанию
	Matrix(const Matrix &x);//конструктор копирования
	~Matrix();//деструктор
	friend std::ostream& operator<<(std::ostream &out, const Matrix &x);//вывод
	friend std::istream& operator>>(std::istream &in, const Matrix &x);//ввод
	Matrix operator+(const Matrix &x) const;//сложение матриц
	Matrix operator-(const Matrix &x) const;//вычитание матриц
	Matrix operator*(const Matrix &x) const;//произведение матриц
	Matrix operator+(const double x) const;//прибавление константы
	Matrix operator-(const double x) const;//вычитание константы
	Matrix operator*(const double x) const;//умножение на константу
	Matrix operator/(const double x) const;//деление на константу
	Matrix& operator=(const Matrix &x);//присваивание
	Matrix operator+=(const Matrix &x);//+= для матриц
	Matrix operator-=(const Matrix &x);//-= для матриц
	Matrix operator*=(const Matrix &x);//*= для матриц
	Matrix operator+=(const double x);//+= для константы
	Matrix operator-=(const double x);//-= для константы
	Matrix operator*=(const double x);//*= для константы
	Matrix operator/=(const double x);// /= для константы
	double* operator[](int i) const;//получение ссылки на i-ую строку
};