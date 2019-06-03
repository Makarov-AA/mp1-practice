#include <iostream>
#include <stdlib.h>
#include "Container.h"

int main()
{
    int mode(-1);
    setlocale(LC_ALL, "Russian");
    while (mode != 0)
    {
        std::cout << "�������� ����� ���������:" << std::endl;
        std::cout << "1. ���������� ���������" << std::endl;
        std::cout << "2. ��������� ���������" << std::endl;
        std::cout << "0. �����" << std::endl;
        std::cin >> mode;
        if ((mode < 0) || (mode > 2)) std::cout << "�������� ����" << std::endl;
        if (mode == 1)
        {
            int size;
            std::cout << "������� ������" << std::endl;
            std::cin >> size;
            try
            {
                mode = -1;
                Container<int> C(size);
                while ((mode < 0) || (mode > 2))
                {
                    std::cout << "1.������ �������" << std::endl;
                    std::cout << "2.��������� ���������� �������" << std::endl;
                    std::cout << "0.���������" << std::endl;
                    std::cin >> mode;
                    if ((mode < 0) || (mode > 2))
                        std::cout << "�������� ����";
                }
                if (mode == 1)
                    C.input();
                if (mode == 2)
                    int_rand_input(C);
                while (mode != 0)
                {
                    std::cout << "�������� ��������" << std::endl;
                    std::cout << "1.�������� ������� � ����� ������" << std::endl;
                    std::cout << "2.�������� ������� ����� ��������� �������" << std::endl;
                    std::cout << "3.������� ������� �� ������" << std::endl;
                    std::cout << "4.����� �������" << std::endl;
                    std::cout << "5. ������" << std::endl;
                    std::cout << "0.���������" << std::endl;
                    std::cin >> mode;
                    try
                    {
                        int a, n;
                        switch (mode)
                        {
                        case 1:
                            std::cout << "������� �������" << std::endl;
                            std::cin >> a;
                            C.add(a);
                            break;
                        case 2:
                            std::cout << "������� �������" << std::endl;
                            
                            std::cin >> a;
                            std::cout << "������� ����� (��������� ���������� � 0)" << std::endl;
                            std::cin >> n;
                            C.add(a, n);
                            break;
                        case 3:
                            std::cout << "������� ����� (��������� ���������� � 0)" << std::endl;
                            std::cin >> n;
                            C.del(n);
                            break;
                        case 4:
                            std::cout << "������� ������� (��������� ���������� � 0)" << std::endl;
                            std::cin >> a;
                            if (C.search(a) == -1) std::cout << "��� ������ ��������" << std::endl;
                            else std::cout << "������ ����� ������� ��� ������� " << C.search(a) << std::endl;
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