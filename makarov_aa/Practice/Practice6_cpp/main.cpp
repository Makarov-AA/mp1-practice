#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "N_vector.h"
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Попытка создать нулевой вектор\n";
	try { N_vector a(0); }
	catch (char* b) { std::cout << b; }
	std::cout << "Создание вектора по умолчанию (3ей размерности)\n";
	N_vector a;
	std::cout << "Ввод\n";
	std::cin >> a;
	std::cout << "Операции с константой 5";
	try { std::cout << a + 5 << a - 5 << a * 5 << a / 5; }
	catch (char* b) { std::cout << b; }
	std::cout << "Попытка деления на 0";
	try { std::cout << a / 0; }
	catch (char* b) { std::cout << b; }
	std::cout << "Создание вектора 2ой размерности с координатами (3, 4) через[]\n";
	N_vector b(2);
	b[0] = 3;
	b[1] = 4;
	std::cout << "Попытка присвоить третью координату\n";
	try { b[3] = 7; }
	catch (char* b) { std::cout << b; }
	std::cout << "Попытка выполнения операций с векторами разных размеров \n";
	try { std::cout << a + b << a - b << a * b; }
	catch (char* b) { std::cout << b; }
	std::cout << "Присваивание вектору b вектора a\n";
	return 0;
}