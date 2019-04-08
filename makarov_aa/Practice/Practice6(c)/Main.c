#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include "N_vector.h"

#define _CRT_SECURE_NO_WARNINGS

int main()
{
	setlocale(LC_ALL, "Russian");
	//printf("Попытка создать нулевой вектор\n");
	N_vector v;// = create(0);
	N_vector v1, result;
	double d;
	printf("Создание вектора размерности 3 со значениями (4, 5, 3)\n");
	v = create(3);
	v.m_x[0] = 4;
	v.m_x[1] = 5;
	v.m_x[2] = 3;
	printf("Создание вектора размерности 2 со значениями (1, 7)\n");
	v1 = create(2);
	v1.m_x[0] = 1;
	v1.m_x[1] = 7;
	printf("Попытка выполнения всех операций между первым и вторым вектором\n");
	result = sum(&v, &v1);
	result = diff(&v, &v1);
	d = mlp(&v, &v1);
	d = angle(&v, &v1);
	printf("Создание вектора размерности 3 со значениями (1, 7, 9)\n");
	v1 = create(3);
	v1.m_x[0] = 1;
	v1.m_x[1] = 7;
	v1.m_x[2] = 9;
	printf("Выполнение операции сложения\n");
	result = sum(&v, &v1);
	printf("Результат:\n");
	print(&result);
	printf("Выполнение операции вычитания\n");
	result = diff(&v, &v1);
	printf("Результат:\n");
	print(&result);
	printf("Выполнение операции скалярного произведения\n");
	d = mlp(&v, &v1);
	printf("Результат: %lf\n", d);
	printf("Угол между двумя векторами %lf\n", angle(&v, &v1));
	printf("Попытка деления на ноль\n");
	c_div(&v, 0);
	printf("Выполнение всех операций с константой 3.7\n");
	printf("Сложение\n");
	c_sum(&v, 3.7);
	printf("Результат:\n");
	print(&v);
	printf("Вычитание\n");
	c_diff(&v, 3.7);
	printf("Результат:\n");
	print(&v);
	printf("Умножение\n");
	c_mlp (&v, 3.7);
	printf("Результат:\n");
	print(&v);
	printf("Деление\n");
	c_div(&v, 3.7);
	printf("Результат:\n");
	print(&v);
	printf("Очистка памяти");
	delete(&v);
	return 0;
}

