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
	std::cout << a;
	std::cout << "Ввод\n";
	std::cin >> a;
	/*a[0] = 5;
	a[1] = 0;
	a[2] = -7;*/
	std::cout << "Операции с константой 5\n";
	try { std::cout << a + 5 << a - 5 << a * 5 << a / 5; }
	catch (char* er) { std::cout << er; }
	std::cout << "Попытка деления на 0\n";
	try { std::cout << a / 0; }
	catch (char* er) { std::cout << er; }
	std::cout << "Создание вектора b 2ой размерности с координатами (3, 4) через[]\n";
	Matrix b(2);
	b[0] = 3;
	b[1] = 4;
	std::cout << "Попытка присвоить третью координату\n";
	try { b[3] = 7; }
	catch (char* er) { std::cout << er; }
	std::cout << "Попытка выполнения операций с векторами разных размеров \n";
	std::cout << "a + b = ";
	try { std::cout << a + b; }
	catch (char* er) { std::cout << er; }
	std::cout << "a - b = ";
	try { std::cout << a - b; }
	catch (char* er) { std::cout << er; }
	std::cout << "a * b = ";
	try { std::cout << a * b; }
	catch (char* er) { std::cout << er; }
	std::cout << "Угол между а и b \n";
	try { std::cout << a.angle(b); }
	catch (char* er) { std::cout << er; }
	std::cout << "Создание вектора с = а (проверка конструктора копирования) \n";
	Matrix c(a);
	std::cout << "Ввод других координат для вектора с\n";
	std::cin >> c;
	std::cout << "Выполнение всех операций с векторами а и с \n";
	std::cout << "a + c = ";
	try { std::cout << a + c << std::endl; }
	catch (char* er) { std::cout << er; }
	std::cout << "a - c = ";
	try { std::cout << a - c << std::endl; }
	catch (char* er) { std::cout << er; }
	std::cout << "a * c = ";
	try { std::cout << a * c << std::endl; }
	catch (char* er) { std::cout << er; }
	catch (char* er) { std::cout << er; }
	return 0;
}