#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "N_vector.h"
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "������� ������� ������� ������\n";
	try { N_vector a(0); }
	catch (char* b) { std::cout << b; }
	std::cout << "�������� ������� �� ��������� (3�� �����������)\n";
	N_vector a;
	std::cout << "����\n";
	std::cin >> a;
	std::cout << "�������� � ���������� 5";
	try { std::cout << a + 5 << a - 5 << a * 5 << a / 5; }
	catch (char* b) { std::cout << b; }
	std::cout << "������� ������� �� 0";
	try { std::cout << a / 0; }
	catch (char* b) { std::cout << b; }
	std::cout << "�������� ������� 2�� ����������� � ������������ (3, 4) �����[]\n";
	N_vector b(2);
	b[0] = 3;
	b[1] = 4;
	std::cout << "������� ��������� ������ ����������\n";
	try { b[3] = 7; }
	catch (char* b) { std::cout << b; }
	std::cout << "������� ���������� �������� � ��������� ������ �������� \n";
	try { std::cout << a + b << a - b << a * b; }
	catch (char* b) { std::cout << b; }
	std::cout << "������������ ������� b ������� a\n";
	return 0;
}