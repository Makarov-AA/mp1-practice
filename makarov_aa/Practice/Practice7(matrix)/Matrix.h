#pragma once
class Matrix
{
	int n_m;//������
	int m_m;//�������
	double* x_m;
public:
	Matrix(int n, int m);//����������� 
	Matrix(int n = 3);//����������� �� ���������
	Matrix(const Matrix &x);//����������� �����������
	~Matrix();//����������
	friend std::ostream& operator<<(std::ostream &out, const Matrix &x);//�����
	friend std::istream& operator >> (std::istream &in, const Matrix &x);//����
	Matrix operator+(const Matrix &x) const;//�������� ������
	Matrix operator-(const Matrix &x) const;//��������� ������
	Matrix operator*(const Matrix &x) const;//������������ ������
	Matrix operator+(const double x) const;//����������� ���������
	Matrix operator-(const double x) const;//��������� ���������
	Matrix operator*(const double x) const;//��������� �� ���������
	Matrix operator/(const double x) const;//������� �� ���������
	Matrix& operator=(const Matrix &x);//������������
	Matrix operator+=(const Matrix &x);//+= ��� ������
	Matrix operator-=(const Matrix &x);//-= ��� ������
	Matrix operator*=(const Matrix &x);//-= ��� ������
	Matrix operator+=(const double x);//+= ��� ���������
	Matrix operator-=(const double x);//-= ��� ���������
	Matrix operator*=(const double x);//*= ��� ���������
	Matrix operator/=(const double x);// /= ��� ���������
	int get_size() const;//������ �������
	double* operator[](int i) const;//��������� ������ �� i-�� ������
	Matrix invert(const Matrix &x) const;
	Matrix transp(const Matrix &x) const;
	double det(const Matrix &x) const;
};