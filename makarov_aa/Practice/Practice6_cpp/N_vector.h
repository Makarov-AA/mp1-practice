#pragma once
class N_vector
{
	int n_m;
	double* x_m;
public:
	N_vector(int a = 0);//конструктор по умолчанию
	N_vector(const N_vector &x);//конструктор копирования
	~N_vector();//деструктор
	friend std::ostream& operator<<(std::ostream &out, const N_vector &x);//вывод
	friend std::istream& operator >> (std::istream &in, const N_vector &x);//ввод
	N_vector operator+(const N_vector x) const;//сложение векторов
	N_vector operator-(const N_vector x) const;//вычитание векторов
	N_vector operator*(const N_vector x) const;//скалярное произведение векторов
	N_vector operator+(const double x) const;//прибавление константы
	N_vector operator-(const double x) const;//вычитание константы
	N_vector operator*(const double x) const;//умножение на константу
	N_vector operator/(const double x) const;//деление на константу
	N_vector& operator=(const N_vector &x);//присваивание
	N_vector operator+=(const N_vector x);//+= для векторов
	N_vector operator-=(const N_vector x);//-= для векторов
	N_vector operator*=(const N_vector x);//*= для векторов
	N_vector operator+=(const double x);//+= для константы
	N_vector operator-=(const double x);//-= для константы
	N_vector operator*=(const double x);//*= для константы
	N_vector operator/=(const double x);// /= для константы
	int get_s() const;//геттер размера
	double& operator[](int i) const;//получение i-ой координаты
	double length() const;//длина
	double angle(N_vector x) const;//угол между двумя векторами
	double angle() const;//угол между вектором и осью координат
};


