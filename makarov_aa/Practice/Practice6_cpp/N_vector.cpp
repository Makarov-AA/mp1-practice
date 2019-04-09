#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "N_vector.h"

N_vector::N_vector(int a = 0) : n_m(a)//конструктор по умолчанию
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
std::ostream& operator<<(std::ostream &out, const N_vector &x)
{
	out << x.x_m[0];
	for (int i = 1; i < x.n_m; i++)
		out << "  " << x.x_m[i];
	return out;
}