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
                int Flag1 = 1;
                PrintCase(1);
                while (Flag1 != 0)
                {
                    std::cin >> Status;
                    switch (Status)
                    {
                        case 0:
                        {
                            Flag1 = 0;
                            break;
                        }
                        case 1:
                        {
                            VectorTests();
                            PrintVector(1);
                            break;
                        }
                        case 2:
                        {
                            int Status1 = 0;
                            int Flag2 = 1;
                            PrintVector(2);
                            while (Flag2 != 0)
                            {
                                std::cin >> Status1;
                                switch (Status1)
                                {
                                    case 0:
                                    {
                                        Flag2 = 0;
                                        break;
                                    }
                                    case 1:
                                    {
                                        int len1, len2;
                                        int a, b;
                                        std::cout << "Write the length of the first vector:\n";
                                        std::cin >> len1;
                                        std::cout << "Write the length of the second vector:\n";
                                        std::cin >> len2;
                                        if (len1 != len2)
                                        {
                                            std::cout << "Different sizes, error" << std::endl;
                                            break;
                                        }
                                        auto arr1 = new int[len1];
                                        auto arr2 = new int[len2];
                                        for (int i = 0; i < len1; i++)
                                        {
                                            std::cout << "Enter " << i + 1 << " element of the first vector:\n";
                                            std::cin >> a;
                                            arr1[i] = a;
                                        }
                                        for (int i = 0; i < len2; i++)
                                        {
                                            std::cout << "Enter " << i + 1 << " element of the second vector:\n";
                                            std::cin >> b;
                                            arr2[i] = b;
                                        }
                                        Vector<int> test1(arr1, len1);
                                        Vector<int> test2(arr2, len2);
                                        Vector<int> *test3 = test1 + test2;
                                        std::cout << "Result vector: ";
                                        VectorShow(test3);
                                        std::cout << std::endl;
                                        break;
                                    }
                                    case 2:
                                    {
                                        int len;
                                        int a;
                                        std::cout << "Write the length of vector:\n";
                                        std::cin >> len;
                                        auto arr = new int[len];
                                        for (int i = 0; i < len; i++)
                                        {
                                            std::cout << "Enter " << i + 1 << " element of the vector:\n";
                                            std::cin >> a;
                                            arr[i] = a;
                                        }
                                        Vector<int> test1(arr, len);
                                        int scalar;
                                        std::cout << "Enter scalar in int form:\n";
                                        std::cin >> scalar;
                                        Vector<int> *test2 = test1 * scalar;
                                        std::cout << "Vector Result: ";
                                        VectorShow(test2);
                                        std::cout << std::endl;
                                        break;
                                    }
                                    case 3:
                                    {
                                        int len;
                                        int a;
                                        std::cout << "Write the length of vector:\n";
                                        std::cin >> len;
                                        auto arr = new int[len];
                                        for (int i = 0; i < len; i++)
                                        {
                                            std::cout << "Enter " << i + 1 << " element of the vector:\n";
                                            std::cin >> a;
                                            arr[i] = a;
                                        }
                                        Vector<int> test1(arr, len);
                                        double Norm = test1.vectorNorm();
                                        std::cout << "VectorNorm Result: " << Norm << std::endl;
                                        break;
                                    }
                                    case 4:
                                    {
                                        int len1, len2;
                                        int a, b;
                                        std::cout << "Write the length of the first vector:\n";
                                        std::cin >> len1;
                                        std::cout << "Write the length of the second vector:\n";
                                        std::cin >> len2;
                                        if (len1 != len2)
                                        {
                                            std::cout << "Different sizes, error" << std::endl;
                                            break;
                                        }
                                        int *arr1 = new int[len1];
                                        int *arr2 = new int[len2];
                                        for (int i = 0; i < len1; i++)
                                        {
                                            std::cout << "Enter " << i + 1 << " element of the first vector:\n";
                                            std::cin >> a;
                                            arr1[i] = a;
                                        }
                                        for (int i = 0; i < len2; i++)
                                        {
                                            std::cout << "Enter " << i + 1 << " element of the second vector:\n";
                                            std::cin >> b;
                                            arr2[i] = b;
                                        }
                                        Vector<int> test1(arr1, len1);
                                        Vector<int> test2(arr2, len2);
                                        Vector<int> *test3 = test1 * test2;
                                        std::cout << "Vector Result: ";
                                        VectorShow(test3);
                                        std::cout << std::endl;
                                        break;
                                    }
                                    default:
                                    {
                                        std::cout << "Unknown programm" << std::endl;
                                        break;
                                    }
                                }
                                if (Status1 != 0) {
                                    PrintVector(2);
                                }
                            }
                            break;
                        }
                        case 3:
                        {
                            int Status2 = 0;
                            int Flag3 = 1;
                            PrintVector(3);
                            while (Flag3 != 0)
                            {
                                std::cin >> Status2;
                                switch (Status2)
                                {
                                    case 0:
                                    {
                                        Flag3 = 0;
                                        break;
                                    }
                                    case 1:
                                    {
                                        int len1, len2;
                                        complex a, b;
                                        std::cout << "Write the length of the first vector:\n";
                                        std::cin >> len1;
                                        std::cout << "Write the length of the second vector:\n";
                                        std::cin >> len2;
                                        if (len1 != len2)
                                        {
                                            std::cout << "Different sizes, error" << std::endl;
                                            break;
                                        }
                                        auto arr1 = new complex[len1];
                                        auto arr2 = new complex[len2];
                                        for (int i = 0; i < len1; i++)
                                        {
                                            std::cout << "Enter " << i + 1 << " element of the first vector in complex form (Re + Im):\n";
                                            std::cin >> a;
                                            arr1[i] = a;
                                        }
                                        for (int i = 0; i < len2; i++)
                                        {
                                            std::cout << "Enter " << i + 1 << " element of the second vector in complex forn (Re + Im):\n";
                                            std::cin >> b;
                                            arr2[i] = b;
                                        }
                                        Vector<complex> test1(arr1, len1);
                                        Vector<complex> test2(arr2, len2);
                                        Vector<complex> *test3 = test1 + test2;
                                        std::cout << "Vector Result:";
                                        VectorShow(test3);
                                        std::cout << std::endl;
                                        break;
                                    }
                                    case 2:
                                    {
                                        int len;
                                        complex a;
                                        std::cout << "Write length of vector:\n";
                                        std::cin >> len;
                                        auto arr = new complex[len];
                                        for (int i = 0; i < len; i++)
                                        {
                                            std::cout << "Enter " << i + 1 << " element of the vector in complex form (Re + Im):\n";
                                            std::cin >> a;
                                            arr[i] = a;
                                        }
                                        Vector<complex> test1(arr, len);
                                        complex scalar;
                                        std::cout << "Enter scalar in complex form:\n";
                                        std::cin >> scalar;
                                        Vector<complex> *test2 = test1 * scalar;
                                        std::cout << "Vector Result: ";
                                        VectorShow(test2);
                                        std::cout << std::endl;
                                        break;
                                    }
                                    case 3:
                                    {
                                        int len;
                                        complex a;
                                        std::cout << "Write the length of vector:\n";
                                        std::cin >> len;
                                        auto arr = new complex[len];
                                        for (int i = 0; i < len; i++)
                                        {
                                            std::cout << "Enter " << i + 1 << " element of the vector in complex form (Re + Im):\n";
                                            std::cin >> a;
                                            arr[i] = a;
                                        }
                                        Vector<complex> test1(arr, len);
                                        double Norm = test1.vectorNorm();
                                        std::cout << "VectorNorm Result: " << Norm << std::endl;
                                        break;
                                    }
                                    case 4:
                                    {
                                        int len1, len2;
                                        complex a, b;
                                        std::cout << "Write the length of the first vector:\n";
                                        std::cin >> len1;
                                        std::cout << "Write the length of the second vector:\n";
                                        std::cin >> len2;
                                        if (len1 != len2)
                                        {
                                            std::cout << "Different sizes, error" << std::endl;
                                            break;
                                        }
                                        auto arr1 = new complex[len1];
                                        auto arr2 = new complex[len2];
                                        for (int i = 0; i < len1; i++)
                                        {
                                            std::cout << "Enter " << i + 1 << " element of the first vector:\n";
                                            std::cin >> a;
                                            arr1[i] = a;
                                        }
                                        for (int i = 0; i < len2; i++)
                                        {
                                            std::cout << "Enter " << i + 1 << " element of the second vector:\n";
                                            std::cin >> b;
                                            arr2[i] = b;
                                        }
                                        Vector<complex> test1(arr1, len1);
                                        Vector<complex> test2(arr2, len2);
                                        Vector<complex> *test3 = test1 * test2;
                                        std::cout << "Vector Result:";
                                        VectorShow(test3);
                                        std::cout << std::endl;
                                        break;
                                    }
                                    default:
                                    {
                                        std::cout << "Unknown programm" << std::endl;
                                        break;
                                    }
                                }
                                if (Status2 != 0) {
                                    PrintVector(2);
                                }
                            }
                            break;
                        }
                        default:
                        {
                            PrintVector(Status);
                            break;
                        }
                    }
                    if (Status != 0) {
                        PrintCase(1);
                    }
                }
                break;
            }
            case 2:
            {
                int Status = 0;
                PrintCase(2);
                std::cin >> Status;
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




