#include <iostream>
#include <stdlib.h>
#include "Container.h"

int main()
{
    int mode(-1);
    setlocale(LC_ALL, "Russian");
    while (mode != 0)
    {
        std::cout << "Выберите режим программы:" << std::endl;
        std::cout << "1. Одномерный контейнер" << std::endl;
        std::cout << "2. Двумерный контейнер" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cin >> mode;
        if ((mode < 0) || (mode > 2)) std::cout << "Неверный ввод" << std::endl;
        if (mode == 1)
        {
            int size;
            std::cout << "Введите размер" << std::endl;
            std::cin >> size;
            try
            {
                mode = -1;
                Container<int> C(size);
                while ((mode < 0) || (mode > 2))
                {
                    std::cout << "1.Ввести вручную" << std::endl;
                    std::cout << "2.Заполнить случайными числами" << std::endl;
                    std::cout << "0.Вернуться" << std::endl;
                    std::cin >> mode;
                    if ((mode < 0) || (mode > 2))
                        std::cout << "Неверный ввод";
                }
                if (mode == 1)
                    C.input();
                if (mode == 2)
                    int_rand_input(C);
                while (mode != 0)
                {
                    std::cout << "Выберите действие" << std::endl;
                    std::cout << "1.Добавить элемент в конец строки" << std::endl;
                    std::cout << "2.Добавить элемент перед указанным номером" << std::endl;
                    std::cout << "3.Удалить элемент по номеру" << std::endl;
                    std::cout << "4.Найти элемент" << std::endl;
                    std::cout << "5. Печать" << std::endl;
                    std::cout << "0.Вернуться" << std::endl;
                    std::cin >> mode;
                    try
                    {
                        int a, n;
                        switch (mode)
                        {
                        case 1:
                            std::cout << "Введите элемент" << std::endl;
                            std::cin >> a;
                            C.add(a);
                            break;
                        case 2:
                            std::cout << "Введите элемент" << std::endl;
                            
                            std::cin >> a;
                            std::cout << "Введите номер (нумерация начинается с 0)" << std::endl;
                            std::cin >> n;
                            C.add(a, n);
                            break;
                        case 3:
                            std::cout << "Введите номер (нумерация начинается с 0)" << std::endl;
                            std::cin >> n;
                            C.del(n);
                            break;
                        case 4:
                            std::cout << "Введите элемент (нумерация начинается с 0)" << std::endl;
                            std::cin >> a;
                            if (C.search(a) == -1) std::cout << "Нет такого элемента" << std::endl;
                            else std::cout << "Первый такой элемент под номером " << C.search(a) << std::endl;
                            break;
                        case 5:
                            C.print();
                            std::cout << std::endl;
                            break;
                        }
                    }
                    catch (char* c)
                    {
                        std::cout << c << std::endl;
                    }
                }
            }
            catch (char* c)
            {
                std::cout << c << std::endl;
            }
            mode = -1;
        }
        if (mode == 2)
        {

        }
    }
    return 0;
}