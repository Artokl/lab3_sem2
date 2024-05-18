#include <iostream>
#include "Ui.h"
#include "Tests/StandartTests.h"
#include "Tests/ComplexTests.h"

int main()
{
    StandartTests();
    ComplexTests();
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
                PrintCase(0);
                break;
            }
            case 1:
            {
                int Status = 0;
                PrintCase(1);
                std::cin >> Status;
            }
            case 2:
            {
                int Status = 0;
                PrintCase(2);
                std::cin >> Status;
            }
            default:
            {
                PrintCase(Choise);
            }
        }
        if (Choise != 0)
        {
            StartMenu();
        }
    }
    return 0;
}
