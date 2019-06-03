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
    std::cout << "Ввод а\n";
    std::cin >> a;
    std::cout << "Ввод b\n";
    std::cin >> b;
    std::cout << "Матрица а:\n";
    std::cout << a;
    std::cout << "Матрица b:\n";
    std::cout << b;
    std::cout << "Операции с константой 5\n";
    try { std::cout << a + 5 << a - 5 << a * 5 << a / 5; }
    catch (char* er) { std::cout << er; }
    std::cout << "Попытка деления на 0\n";
    try { std::cout << a / 0; }
    catch (char* er) { std::cout << er; }
    std::cout << "Выполнение всех операций между а и b  \n";
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