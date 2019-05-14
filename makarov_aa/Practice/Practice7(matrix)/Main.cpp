#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Matrix.h"
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Создание а и b 3х3\n";
	Matrix a, b;
	std::cout << "Матрица а:\n";
	a[0][0] = 5; a[0][1] = -3; a[0][2] = 3;
	a[1][0] = 7; a[1][1] = 4; a[1][2] = 7;
	a[2][0] = 13; a[2][1] = -1; a[2][2] = 8;
	std::cout << a;
	std::cout << "Матрица b\n";
	b[0][0] = 5; b[0][1] = 1; b[0][2] = -9;
	b[1][0] = 3; b[1][1] = -15; b[1][2] = 4;
	b[2][0] = 8; b[2][1] = 2; b[2][2] = 14;
	std::cout << b;
	std::cout << "a + b" << a + b;
	std::cout << "a - b" << a - b;
	std::cout << "a * b" << a * b;
	return 0;
}