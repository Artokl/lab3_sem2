#include <iostream>
#include "Ui.h"

int main()
{
    int Choise = 0;
    int Flag = 1;
    StartMenu();
    while (Flag)
    {
        std::cin >> Choise;
        switch (Choise)
        {
            case 0:
            {
                Flag = 0;
                std::cout << "Programm ended";
                break;
            }
            case 1:
            {
                int Status = 0;
                PrintMenuVector();
                std::cin >> Status;
            }
            case 2:
            {
                int Status = 0;
                PrintMenuMatrix();
                std::cin >> Status;
            }
        }

    }
}
