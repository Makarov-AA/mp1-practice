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
    std::cout << "���� �\n";
    std::cin >> a;
    std::cout << "���� b\n";
    std::cin >> b;
    std::cout << "������� �:\n";
    std::cout << a;
    std::cout << "������� b:\n";
    std::cout << b;
    std::cout << "�������� � ���������� 5\n";
    try { std::cout << a + 5 << a - 5 << a * 5 << a / 5; }
    catch (char* er) { std::cout << er; }
    std::cout << "������� ������� �� 0\n";
    try { std::cout << a / 0; }
    catch (char* er) { std::cout << er; }
    std::cout << "���������� ���� �������� ����� � � b  \n";
    std::cout << "a + b = ";
    try { std::cout << a + b; }
    catch (char* er) { std::cout << er; }
    std::cout << "a - b = ";
    try { std::cout << a - b; }
    catch (char* er) { std::cout << er; }
    std::cout << "a * b = ";
    try { std::cout << a * b; }
    catch (char* er) { std::cout << er; }
    return 0;
}