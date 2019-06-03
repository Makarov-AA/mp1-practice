#include "ToDoList.h"
#include <stdlib.h>
#include <iostream>

int main()
{
    int n, c = -1;
    Date now;
    List list;
    while (c != 0)
    {
        c = -1;
        std::cout << "Input date: " << std::endl;
        try
        {
            std::cin >> now;
            while (c != 3)
            {
                c = -1;
                list.print(now);
                std::cout << "1) Add daily task" << std::endl;
                std::cout << "2) Add shortly task" << std::endl;
                std::cout << "3) Data change" << std::endl;
                std::cout << "4) Delete task" << std::endl;
                std::cout << "5) Print all list" << std::endl;
                std::cout << "0) Exit" << std::endl;
                while ((c < 0) || (c > 5))
                    std::cin >> c;
                if (c == 1) list.add_task(now);
                if (c == 2) list.add_s_task(now);
                if (c == 4)
                {
                    std::cout << "Task's number to delete: ";
                    std::cin >> n;
                    list.del_task(now, n);
                }
                if (c == 5)
                {
                    list.print_all();
                    c = 3;
                }
                if (c == 0) return 0;
            }
        }
        catch (char* c)
        {
            std::cout << c;
        }
    }
    return 0;
}