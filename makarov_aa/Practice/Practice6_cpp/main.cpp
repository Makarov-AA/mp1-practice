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
	catch (char* er) { std::cout << er; }
	std::cout << "�������� ������� � �� ��������� (3�� �����������)\n";
	N_vector a;
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
	N_vector b(2);
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
	N_vector c(a);
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
	std::cout << "���� ����� � � c \n";
	try { std::cout << a.angle(c) << std::endl; }
	catch (char* er) { std::cout << er; }
	return 0;
}