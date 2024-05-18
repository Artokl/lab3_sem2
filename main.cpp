/*#include <iostream>
#include "Ui.h"
#include "Tests/StandartTests.h"
#include "Tests/ComplexTests.h"
#include "Tests/VectorTests.h"

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
                switch (Status)
                {
                    case 0:
                    {
                        break;
                    }
                    case 1:
                    {
                        VectorTests();
                        PrintVector(1);
                        break;
                    }
                    default:
                    {
                        PrintVector(Status);
                        break;
                    }
                }
                if (Status != 0)
                {
                    PrintCase(1);
                }
                else
                {
                    break;
                }
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
                break;
            }
        }
        if (Choise != 0)
        {
            StartMenu();
        }
    }
    return 0;
}*/
#include <iostream>
#include "Ui.h"
#include "Tests/StandartTests.h"
#include "Tests/ComplexTests.h"
#include "Tests/VectorTests.h"

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
                while (Status != 0)
                {
                    switch (Status)
                    {
                        case 1:
                        {
                            VectorTests();
                            PrintVector(1);
                            break;
                        }
                        default:
                        {
                            PrintVector(Status);
                            break;
                        }
                    }
                    PrintCase(1);
                    std::cin >> Status;
                }
                // If Status is 0, break out of the inner loop and continue to the main loop
                break;
            }
            case 2:
            {
                int Status = 0;
                PrintCase(2);
                std::cin >> Status;
                // Process Status if needed for case 2
                break;
            }
            default:
            {
                PrintCase(Choise);
                break;
            }
        }
        if (Choise != 0)
        {
            StartMenu();
        }
    }
    return 0;
}

