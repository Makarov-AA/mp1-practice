#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Matrix.h"
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "�������� � � b 3�3\n";
	Matrix a, b;
	std::cout << "������� �:\n";
	std::cout << a;
	std::cout << "����\n";
	std::cin >> a;
	/*a[0] = 5;
	a[1] = 0;
	a[2] = -7;*/
	std::cout << "�������� � ���������� 5\n";
	try { std::cout << a + 5 << a - 5 << a * 5 << a / 5; }
	catch (char* er) { std::cout << er; }
	std::cout << "������� ������� �� 0\n";
	try { std::cout << a / 0; }
	catch (char* er) { std::cout << er; }
	std::cout << "�������� ������� b 2�� ����������� � ������������ (3, 4) �����[]\n";
	Matrix b(2);
	b[0] = 3;
	b[1] = 4;
	std::cout << "������� ��������� ������ ����������\n";
	try { b[3] = 7; }
	catch (char* er) { std::cout << er; }
	std::cout << "������� ���������� �������� � ��������� ������ �������� \n";
	std::cout << "a + b = ";
	try { std::cout << a + b; }
	catch (char* er) { std::cout << er; }
	std::cout << "a - b = ";
	try { std::cout << a - b; }
	catch (char* er) { std::cout << er; }
	std::cout << "a * b = ";
	try { std::cout << a * b; }
	catch (char* er) { std::cout << er; }
	std::cout << "���� ����� � � b \n";
	try { std::cout << a.angle(b); }
	catch (char* er) { std::cout << er; }
	std::cout << "�������� ������� � = � (�������� ������������ �����������) \n";
	Matrix c(a);
	std::cout << "���� ������ ��������� ��� ������� �\n";
	std::cin >> c;
	std::cout << "���������� ���� �������� � ��������� � � � \n";
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