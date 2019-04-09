#pragma once
class N_vector
{
	int n_m;
	double* x_m;
public:
	N_vector(int a = 0);//����������� �� ���������
	N_vector(const N_vector &x);//����������� �����������
	~N_vector();//����������
	friend std::ostream& operator<<(std::ostream &out, const N_vector &x);//�����
	friend std::istream& operator >> (std::istream &in, const N_vector &x);//����
	N_vector operator+(const N_vector x) const;//�������� ��������
	N_vector operator-(const N_vector x) const;//��������� ��������
	N_vector operator*(const N_vector x) const;//��������� ������������ ��������
	N_vector operator+(const double x) const;//����������� ���������
	N_vector operator-(const double x) const;//��������� ���������
	N_vector operator*(const double x) const;//��������� �� ���������
	N_vector operator/(const double x) const;//������� �� ���������
	N_vector& operator=(const N_vector &x);//������������
	void operator+=(const N_vector x);//+= ��� ��������
	void operator-=(const N_vector x);//-= ��� ��������
	void operator*=(const N_vector x);//*= ��� ��������
	void operator+=(const double x);//+= ��� ���������
	void operator-=(const double x);//-= ��� ���������
	void operator*=(const double x);//*= ��� ���������
	void operator/=(const double x);// /= ��� ���������
	int get_s();//������ �������
	double& operator[](int i) const;//��������� i-�� ����������
	double length();//�����
	double angle(N_vector x);//���� ����� ����� ���������
	double angle();//���� ����� �������� � ���� ���������
};


