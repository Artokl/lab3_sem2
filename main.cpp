#include <iostream>

#include "LinearShape.h"
#include "RectangularMatrix.h"
#include "Ui.h"
#include "Tests/StandartTests.h"
#include "Tests/ComplexTests.h"
#include "Tests/LinearShapeTests.h"
#include "Tests/VectorTests.h"
#include "Tests/MatrixTests.h"

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
                                int len1, len2;
                                int a, b;
                                int len;
                                switch (Status1)
                                {
                                    case 0:
                                    {
                                        Flag2 = 0;
                                        break;
                                    }
                                    case 1:
                                    {
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
                                int len1, len2;
                                int len;
                                complex a, b;
                                switch (Status2)
                                {
                                    case 0:
                                    {
                                        Flag3 = 0;
                                        break;
                                    }
                                    case 1:
                                    {
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
                int Flag3 = 1;
                PrintCase(2);
                while (Flag3 != 0)
                {
                    std::cin >> Status;
                    switch (Status) {
                        case 0:
                        {
                            Flag3 = 0;
                            break;
                        }
                        case 1:
                        {
                            MatrixTests();
                            PrintMatrix(1);
                            break;
                        }
                        case 2:
                        {
                            int Status1 = 0;
                            int Flag4 = 1;
                            PrintMatrix(2);
                            while (Flag4 != 0) {
                                std::cin >> Status1;
                                unsigned int row1, col1;
                                int a;
                                switch (Status1) {
                                    case 0:
                                    {
                                        Flag4 = 0;
                                        break;
                                    }
                                    case 1:
                                    {
                                        int  b;
                                        unsigned int row2, col2;
                                        std::cout << "Write the number of rows of the first matrix:\n";
                                        std::cin >> row1;
                                        std::cout << "Write the number of columns of the first matrix:\n";
                                        std::cin >> col1;
                                        std::cout << "Write the number of rows of the second matrix:\n";
                                        std::cin >> row2;
                                        std::cout << "Write the number of columns of the second matrix:\n";
                                        std::cin >> col2;
                                        if (row1 != row2 || col1 != col2)
                                        {
                                            std::cout << "Different sizes, error" << std::endl;
                                            break;
                                        }
                                        auto arr1 = new int[row1 * col1];
                                        auto arr2 = new int[row2 * col2];
                                        for (int i = 0; i < row1; i++) {
                                            for (int j = 0; j < col1; j++) {
                                                std::cout << "Enter (" << i + 1 << ", " << j + 1 << ") element of the first matrix:\n";
                                                std::cin >> a;
                                                arr1[i*col1 + j] = a;
                                            }
                                        }
                                        for (int i = 0; i < row2; i++) {
                                            for (int j = 0; j < col2; j++) {
                                                std::cout << "Enter (" << i + 1 << ", " << j + 1 << ") element of the second matrix:\n";
                                                std::cin >> b;
                                                arr2[i*col2 + j] = b;
                                            }
                                        }
                                        Matrix<int> test1(arr1, row1, col1);
                                        Matrix<int> test2(arr2, row2, col2);
                                        Matrix<int> *test3 = test1 + test2;
                                        std::cout << "Result matrix:\n";
                                        MatrixShow(test3);
                                        break;
                                    }
                                    case 2:
                                    {
                                        std::cout << "Write the number of rows of the matrix:\n";
                                        std::cin >> row1;
                                        std::cout << "Write the number of columns of the matrix:\n";
                                        std::cin >> col1;
                                        auto arr1 = new int[row1 * col1];
                                        for (int i = 0; i < row1; i++) {
                                            for (int j = 0; j < col1; j++) {
                                                std::cout << "Enter (" << i + 1 << ", " << j + 1 << ") element of the matrix:\n";
                                                std::cin >> a;
                                                arr1[i*col1 + j] = a;
                                            }
                                        }
                                        Matrix<int> test1(arr1, row1, col1);
                                        int scalar;
                                        std::cout << "Enter scalar in int form:\n";
                                        std::cin >> scalar;
                                        Matrix<int> *test3 = test1 * scalar;
                                        std::cout << "Result matrix:\n";
                                        MatrixShow(test3);
                                        break;
                                    }
                                    case 3:
                                    {
                                        std::cout << "Write the number of rows of the matrix:\n";
                                        std::cin >> row1;
                                        std::cout << "Write the number of columns of the matrix:\n";
                                        std::cin >> col1;
                                        auto arr1 = new int[row1 * col1];
                                        for (int i = 0; i < row1; i++) {
                                            for (int j = 0; j < col1; j++) {
                                                std::cout << "Enter (" << i + 1 << ", " << j + 1 << ") element of the matrix:\n";
                                                std::cin >> a;
                                                arr1[i*col1 + j] = a;
                                            }
                                        }
                                        Matrix<int> test1(arr1, row1, col1);
                                        double Norm;
                                        Norm = test1.MatrixNorm();
                                        std::cout << "Result matrix: " << Norm << std::endl;
                                        break;
                                    }
                                    case 4:
                                    {
                                        PrintStringConversions();
                                        int Status2 = 0;
                                        int Flag5 = 1;
                                        while (Flag5 != 0) {
                                            std::cin >> Status2;
                                            switch (Status2) {
                                                case 0:
                                                {
                                                    Flag5 = 0;
                                                    break;
                                                }
                                                case 1:
                                                {
                                                    std::cout << "Write the number of rows of the matrix:\n";
                                                    std::cin >> row1;
                                                    std::cout << "Write the number of columns of the matrix:\n";
                                                    std::cin >> col1;
                                                    auto arr1 = new int[row1 * col1];
                                                    for (int i = 0; i < row1; i++) {
                                                        for (int j = 0; j < col1; j++) {
                                                            std::cout << "Enter (" << i + 1 << ", " << j + 1 << ") element of the matrix:\n";
                                                            std::cin >> a;
                                                            arr1[i*col1 + j] = a;
                                                        }
                                                    }
                                                    Matrix<int> test1(arr1, row1, col1);
                                                    unsigned int row_1, row_2;
                                                    std::cout << "Enter row1 and row2 you want to swap in the form of: row1 " " row2:\n";
                                                    std::cin >> row_1 >> row_2;
                                                    test1.swapRows(row_1 - 1, row_2 - 1);
                                                    std::cout << "Result matrix:\n";
                                                    MatrixShow(test1);
                                                    break;
                                                }
                                                case 2:
                                                {
                                                    std::cout << "Write the number of rows of the matrix:\n";
                                                    std::cin >> row1;
                                                    std::cout << "Write the number of columns of the matrix:\n";
                                                    std::cin >> col1;
                                                    auto arr1 = new int[row1 * col1];
                                                    for (int i = 0; i < row1; i++) {
                                                        for (int j = 0; j < col1; j++) {
                                                            std::cout << "Enter (" << i + 1 << ", " << j + 1 << ") element of the matrix:\n";
                                                            std::cin >> a;
                                                            arr1[i*col1 + j] = a;
                                                        }
                                                    }
                                                    Matrix<int> test1(arr1, row1, col1);
                                                    int scalar;
                                                    unsigned int row_1;
                                                    std::cout << "Enter scalar in int form:\n";
                                                    std::cin >> scalar;
                                                    std::cout << "Enter the row you want to multiply:\n";
                                                    std::cin >> row_1;
                                                    test1.multiplyRow(row_1 - 1, scalar);
                                                    std::cout << "Result matrix:\n";
                                                    MatrixShow(test1);
                                                    break;
                                                }
                                                case 3:
                                                {
                                                    std::cout << "Write the number of rows of the matrix:\n";
                                                    std::cin >> row1;
                                                    std::cout << "Write the number of columns of the matrix:\n";
                                                    std::cin >> col1;
                                                    auto arr1 = new int[row1 * col1];
                                                    for (int i = 0; i < row1; i++) {
                                                        for (int j = 0; j < col1; j++) {
                                                            std::cout << "Enter (" << i + 1 << ", " << j + 1 << ") element of the matrix:\n";
                                                            std::cin >> a;
                                                            arr1[i*col1 + j] = a;
                                                        }
                                                    }
                                                    Matrix<int> test1(arr1, row1, col1);
                                                    int scalar;
                                                    unsigned int row_1, row_2;
                                                    std::cout << "Enter scalar in int form:\n";
                                                    std::cin >> scalar;
                                                    std::cout << "Enter row1, you want to add with row2*scalar, and row2 in the form of: row1 " " row2:\n";
                                                    std::cin >> row_1 >> row_2;
                                                    test1.addRows(row_1 - 1, row_2 -1, scalar);
                                                    std::cout << "Result matrix:\n";
                                                    MatrixShow(test1);
                                                    break;
                                                }
                                                default:
                                                {
                                                    std::cout << "Unknown programm" << std::endl;
                                                }
                                            }
                                            if (Status2 != 0)
                                            {
                                                PrintStringConversions();
                                            }
                                        }
                                        break;
                                    }
                                    case 5:
                                    {
                                        PrintColumnConversions();
                                        int Status2 = 0;
                                        int Flag5 = 1;
                                        while (Flag5 != 0) {
                                            std::cin >> Status2;
                                            switch (Status2) {
                                                case 0:
                                                {
                                                    Flag5 = 0;
                                                    break;
                                                }
                                                case 1:
                                                {
                                                    std::cout << "Write the number of rows of the matrix:\n";
                                                    std::cin >> row1;
                                                    std::cout << "Write the number of columns of the matrix:\n";
                                                    std::cin >> col1;
                                                    auto arr1 = new int[row1 * col1];
                                                    for (int i = 0; i < row1; i++) {
                                                        for (int j = 0; j < col1; j++) {
                                                            std::cout << "Enter (" << i + 1 << ", " << j + 1 << ") element of the matrix:\n";
                                                            std::cin >> a;
                                                            arr1[i*col1 + j] = a;
                                                        }
                                                    }
                                                    Matrix<int> test1(arr1, row1, col1);
                                                    unsigned int col_1, col_2;
                                                    std::cout << "Enter col1 and col2 you want to swap in the form of: col1 " " col2:\n";
                                                    std::cin >> col_1 >> col_2;
                                                    test1.swapCols(col_1 - 1, col_2 - 1);
                                                    std::cout << "Result matrix:\n";
                                                    MatrixShow(test1);
                                                    break;
                                                }
                                                case 2:
                                                {
                                                    std::cout << "Write the number of rows of the matrix:\n";
                                                    std::cin >> row1;
                                                    std::cout << "Write the number of columns of the matrix:\n";
                                                    std::cin >> col1;
                                                    auto arr1 = new int[row1 * col1];
                                                    for (int i = 0; i < row1; i++) {
                                                        for (int j = 0; j < col1; j++) {
                                                            std::cout << "Enter (" << i + 1 << ", " << j + 1 << ") element of the matrix:\n";
                                                            std::cin >> a;
                                                            arr1[i*col1 + j] = a;
                                                        }
                                                    }
                                                    Matrix<int> test1(arr1, row1, col1);
                                                    int scalar;
                                                    unsigned int col_1;
                                                    std::cout << "Enter scalar in int form:\n";
                                                    std::cin >> scalar;
                                                    std::cout << "Enter the col you want to multiply:\n";
                                                    std::cin >> col_1;
                                                    test1.multiplyCol(col_1 - 1, scalar);
                                                    std::cout << "Result matrix:\n";
                                                    MatrixShow(test1);
                                                    break;
                                                }
                                                case 3:
                                                {
                                                    std::cout << "Write the number of rows of the matrix:\n";
                                                    std::cin >> row1;
                                                    std::cout << "Write the number of columns of the matrix:\n";
                                                    std::cin >> col1;
                                                    auto arr1 = new int[row1 * col1];
                                                    for (int i = 0; i < row1; i++) {
                                                        for (int j = 0; j < col1; j++) {
                                                            std::cout << "Enter (" << i + 1 << ", " << j + 1 << ") element of the matrix:\n";
                                                            std::cin >> a;
                                                            arr1[i*col1 + j] = a;
                                                        }
                                                    }
                                                    Matrix<int> test1(arr1, row1, col1);
                                                    int scalar;
                                                    unsigned int col_1, col_2;
                                                    std::cout << "Enter scalar in int form:\n";
                                                    std::cin >> scalar;
                                                    std::cout << "Enter col1, you want to add with col2*scalar, and col2 in the form of: col1 " " col2:\n";
                                                    std::cin >> col_1 >> col_2;
                                                    test1.addCols(col_1 - 1, col_2 -1, scalar);
                                                    std::cout << "Result matrix:\n";
                                                    MatrixShow(test1);
                                                    break;
                                                }
                                                default:
                                                {
                                                    std::cout << "Unknown programm" << std::endl;
                                                }
                                            }
                                            if (Status2 != 0)
                                            {
                                                PrintColumnConversions();
                                            }
                                        }
                                        break;
                                    }
                                    default:
                                    {
                                        std::cout << "Unknown programm" << std::endl;
                                        break;
                                    }
                                }
                                if (Status1 != 0)
                                {
                                    PrintMatrix(2);
                                }
                            }
                            break;
                        }
                        case 3:
                        {
                            int Status1 = 0;
                            int Flag4 = 1;
                            PrintMatrix(3);
                            while (Flag4 != 0) {
                                std::cin >> Status1;
                                unsigned int row1, col1;
                                complex a;
                                switch (Status1) {
                                    case 0:
                                    {
                                        Flag4 = 0;
                                        break;
                                    }
                                    case 1:
                                    {
                                        complex b;
                                        unsigned int row2, col2;
                                        std::cout << "Write the number of rows of the first matrix:\n";
                                        std::cin >> row1;
                                        std::cout << "Write the number of columns of the first matrix:\n";
                                        std::cin >> col1;
                                        std::cout << "Write the number of rows of the second matrix:\n";
                                        std::cin >> row2;
                                        std::cout << "Write the number of columns of the second matrix:\n";
                                        std::cin >> col2;
                                        if (row1 != row2 || col1 != col2)
                                        {
                                            std::cout << "Different sizes, error" << std::endl;
                                            break;
                                        }
                                        auto arr1 = new complex[row1 * col1];
                                        auto arr2 = new complex[row2 * col2];
                                        for (int i = 0; i < row1; i++) {
                                            for (int j = 0; j < col1; j++) {
                                                std::cout << "Enter (" << i + 1 << ", " << j + 1 << ") element of the first matrix:\n";
                                                std::cin >> a;
                                                arr1[i*col1 + j] = a;
                                            }
                                        }
                                        for (int i = 0; i < row2; i++) {
                                            for (int j = 0; j < col2; j++) {
                                                std::cout << "Enter (" << i + 1 << ", " << j + 1 << ") element of the second matrix:\n";
                                                std::cin >> b;
                                                arr2[i*col2 + j] = b;
                                            }
                                        }
                                        Matrix<complex> test1(arr1, row1, col1);
                                        Matrix<complex> test2(arr2, row2, col2);
                                        Matrix<complex> *test3 = test1 + test2;
                                        std::cout << "Result matrix:\n";
                                        MatrixShow(test3);
                                        break;
                                    }
                                    case 2:
                                    {
                                        std::cout << "Write the number of rows of the matrix:\n";
                                        std::cin >> row1;
                                        std::cout << "Write the number of columns of the matrix:\n";
                                        std::cin >> col1;
                                        auto arr1 = new complex[row1 * col1];
                                        for (int i = 0; i < row1; i++) {
                                            for (int j = 0; j < col1; j++) {
                                                std::cout << "Enter (" << i + 1 << ", " << j + 1 << ") element of the matrix:\n";
                                                std::cin >> a;
                                                arr1[i*col1 + j] = a;
                                            }
                                        }
                                        Matrix<complex> test1(arr1, row1, col1);
                                        complex scalar;
                                        std::cout << "Enter scalar in complex form:\n";
                                        std::cin >> scalar;
                                        Matrix<complex> *test3 = test1 * scalar;
                                        std::cout << "Result matrix:\n";
                                        MatrixShow(test3);
                                        break;
                                    }
                                    case 3:
                                    {
                                        std::cout << "Write the number of rows of the matrix:\n";
                                        std::cin >> row1;
                                        std::cout << "Write the number of columns of the matrix:\n";
                                        std::cin >> col1;
                                        auto arr1 = new complex[row1 * col1];
                                        for (int i = 0; i < row1; i++) {
                                            for (int j = 0; j < col1; j++) {
                                                std::cout << "Enter (" << i + 1 << ", " << j + 1 << ") element of the matrix:\n";
                                                std::cin >> a;
                                                arr1[i*col1 + j] = a;
                                            }
                                        }
                                        Matrix<complex> test1(arr1, row1, col1);
                                        double Norm;
                                        Norm = test1.MatrixNorm();
                                        std::cout << "Result norm: " << Norm << std::endl;
                                        break;
                                    }
                                    case 4:
                                    {
                                        PrintStringConversions();
                                        int Status2 = 0;
                                        int Flag5 = 1;
                                        while (Flag5 != 0) {
                                            std::cin >> Status2;
                                            switch (Status2) {
                                                case 0:
                                                {
                                                    Flag5 = 0;
                                                    break;
                                                }
                                                case 1:
                                                {
                                                    std::cout << "Write the number of rows of the matrix:\n";
                                                    std::cin >> row1;
                                                    std::cout << "Write the number of columns of the matrix:\n";
                                                    std::cin >> col1;
                                                    auto arr1 = new complex[row1 * col1];
                                                    for (int i = 0; i < row1; i++) {
                                                        for (int j = 0; j < col1; j++) {
                                                            std::cout << "Enter (" << i + 1 << ", " << j + 1 << ") element of the matrix:\n";
                                                            std::cin >> a;
                                                            arr1[i*col1 + j] = a;
                                                        }
                                                    }
                                                    Matrix<complex> test1(arr1, row1, col1);
                                                    unsigned int row_1, row_2;
                                                    std::cout << "Enter row1 and row2 you want to swap in the form of: row1 " " row2:\n";
                                                    std::cin >> row_1 >> row_2;
                                                    test1.swapRows(row_1 - 1, row_2 - 1);
                                                    std::cout << "Result matrix:\n";
                                                    MatrixShow(test1);
                                                    break;
                                                }
                                                case 2:
                                                {
                                                    std::cout << "Write the number of rows of the matrix:\n";
                                                    std::cin >> row1;
                                                    std::cout << "Write the number of columns of the matrix:\n";
                                                    std::cin >> col1;
                                                    auto arr1 = new complex[row1 * col1];
                                                    for (int i = 0; i < row1; i++) {
                                                        for (int j = 0; j < col1; j++) {
                                                            std::cout << "Enter (" << i + 1 << ", " << j + 1 << ") element of the matrix:\n";
                                                            std::cin >> a;
                                                            arr1[i*col1 + j] = a;
                                                        }
                                                    }
                                                    Matrix<complex> test1(arr1, row1, col1);
                                                    complex scalar;
                                                    unsigned int row_1;
                                                    std::cout << "Enter scalar in complex form:\n";
                                                    std::cin >> scalar;
                                                    std::cout << "Enter the row you want to multiply:\n";
                                                    std::cin >> row_1;
                                                    test1.multiplyRow(row_1 - 1, scalar);
                                                    std::cout << "Result matrix:\n";
                                                    MatrixShow(test1);
                                                    break;
                                                }
                                                case 3:
                                                {
                                                    std::cout << "Write the number of rows of the matrix:\n";
                                                    std::cin >> row1;
                                                    std::cout << "Write the number of columns of the matrix:\n";
                                                    std::cin >> col1;
                                                    auto arr1 = new complex[row1 * col1];
                                                    for (int i = 0; i < row1; i++) {
                                                        for (int j = 0; j < col1; j++) {
                                                            std::cout << "Enter (" << i + 1 << ", " << j + 1 << ") element of the matrix:\n";
                                                            std::cin >> a;
                                                            arr1[i*col1 + j] = a;
                                                        }
                                                    }
                                                    Matrix<complex> test1(arr1, row1, col1);
                                                    complex scalar;
                                                    unsigned int row_1, row_2;
                                                    std::cout << "Enter scalar in complex form:\n";
                                                    std::cin >> scalar;
                                                    std::cout << "Enter row1, you want to add with row2*scalar, and row2 in the form of: row1 " " row2:\n";
                                                    std::cin >> row_1 >> row_2;
                                                    test1.addRows(row_1 - 1, row_2 -1, scalar);
                                                    std::cout << "Result matrix:\n";
                                                    MatrixShow(test1);
                                                    break;
                                                }
                                                default:
                                                {
                                                    std::cout << "Unknown programm" << std::endl;
                                                }
                                            }
                                            if (Status2 != 0)
                                            {
                                                PrintStringConversions();
                                            }
                                        }
                                        break;
                                    }
                                    case 5:
                                    {
                                        PrintColumnConversions();
                                        int Status2 = 0;
                                        int Flag5 = 1;
                                        while (Flag5 != 0) {
                                            std::cin >> Status2;
                                            switch (Status2) {
                                                case 0:
                                                {
                                                    Flag5 = 0;
                                                    break;
                                                }
                                                case 1:
                                                {
                                                    std::cout << "Write the number of rows of the matrix:\n";
                                                    std::cin >> row1;
                                                    std::cout << "Write the number of columns of the matrix:\n";
                                                    std::cin >> col1;
                                                    auto arr1 = new complex[row1 * col1];
                                                    for (int i = 0; i < row1; i++) {
                                                        for (int j = 0; j < col1; j++) {
                                                            std::cout << "Enter (" << i + 1 << ", " << j + 1 << ") element of the matrix:\n";
                                                            std::cin >> a;
                                                            arr1[i*col1 + j] = a;
                                                        }
                                                    }
                                                    Matrix<complex> test1(arr1, row1, col1);
                                                    unsigned int col_1, col_2;
                                                    std::cout << "Enter col1 and col2 you want to swap in the form of: col1 " " col2:\n";
                                                    std::cin >> col_1 >> col_2;
                                                    test1.swapCols(col_1 - 1, col_2 - 1);
                                                    std::cout << "Result matrix:\n";
                                                    MatrixShow(test1);
                                                    break;
                                                }
                                                case 2:
                                                {
                                                    std::cout << "Write the number of rows of the matrix:\n";
                                                    std::cin >> row1;
                                                    std::cout << "Write the number of columns of the matrix:\n";
                                                    std::cin >> col1;
                                                    auto arr1 = new complex[row1 * col1];
                                                    for (int i = 0; i < row1; i++) {
                                                        for (int j = 0; j < col1; j++) {
                                                            std::cout << "Enter (" << i + 1 << ", " << j + 1 << ") element of the matrix:\n";
                                                            std::cin >> a;
                                                            arr1[i*col1 + j] = a;
                                                        }
                                                    }
                                                    Matrix<complex> test1(arr1, row1, col1);
                                                    complex scalar;
                                                    unsigned int col_1;
                                                    std::cout << "Enter scalar in complex form:\n";
                                                    std::cin >> scalar;
                                                    std::cout << "Enter the col you want to multiply:\n";
                                                    std::cin >> col_1;
                                                    test1.multiplyCol(col_1 - 1, scalar);
                                                    std::cout << "Result matrix:\n";
                                                    MatrixShow(test1);
                                                    break;
                                                }
                                                case 3:
                                                {
                                                    std::cout << "Write the number of rows of the matrix:\n";
                                                    std::cin >> row1;
                                                    std::cout << "Write the number of columns of the matrix:\n";
                                                    std::cin >> col1;
                                                    auto arr1 = new complex[row1 * col1];
                                                    for (int i = 0; i < row1; i++) {
                                                        for (int j = 0; j < col1; j++) {
                                                            std::cout << "Enter (" << i + 1 << ", " << j + 1 << ") element of the matrix:\n";
                                                            std::cin >> a;
                                                            arr1[i*col1 + j] = a;
                                                        }
                                                    }
                                                    Matrix<complex> test1(arr1, row1, col1);
                                                    complex scalar;
                                                    unsigned int col_1, col_2;
                                                    std::cout << "Enter scalar in complex form:\n";
                                                    std::cin >> scalar;
                                                    std::cout << "Enter col1, you want to add with col2*scalar, and col2 in the form of: col1 " " col2:\n";
                                                    std::cin >> col_1 >> col_2;
                                                    test1.addCols(col_1 - 1, col_2 -1, scalar);
                                                    std::cout << "Result matrix:\n";
                                                    MatrixShow(test1);
                                                    break;
                                                }
                                                default:
                                                {
                                                    std::cout << "Unknown programm" << std::endl;
                                                }
                                            }
                                            if (Status2 != 0)
                                            {
                                                PrintColumnConversions();
                                            }
                                        }
                                        break;
                                    }
                                    default:
                                    {
                                        std::cout << "Unknown command" << std::endl;
                                        break;
                                    }
                                }
                                if (Status1 != 0)
                                {
                                    PrintMatrix(3);
                                }
                            }
                            break;
                        }
                        default:
                        {
                            PrintMatrix(Status);
                            break;
                        }
                    }
                    if (Status != 0)
                    {
                        PrintCase(2);
                    }
                }
                break;
            }
            case 3:
            {
                int Status = 0;
                int Flag3 = 1;
                PrintCase(3);
                while (Flag3 != 0) {
                    std::cin >> Status;
                    switch (Status) {
                        case 0:
                        {
                            Flag3 = 0;
                            break;
                        }
                        case 1:
                        {
                            LinearShapeTests();
                            PrintLinearShape(1);
                            break;
                        }
                        case 2:
                        {
                            int Status5 = 0;
                            int Flag5 = 1;
                            PrintLinearShape(2);
                            while (Flag5 != 0) {
                                std::cin >> Status5;
                                int a, b, length1, length2;
                                switch (Status5) {
                                    case 0:
                                    {
                                        Flag5 = 0;
                                        break;
                                    }
                                    case 1:
                                    {
                                        std::cout << "Enter the length of the first LinearShape:\n";
                                        std::cin >> length1;
                                        std::cout << "Enter the length of the second LinearShape:\n";
                                        std::cin >> length2;
                                        int arr1[length1], arr2[length2];
                                        if (length1 != length2) {
                                            throw std::invalid_argument("different sizes");
                                        }
                                        for (int i = 0; i < length1; i++) {
                                            std::cout << "Enter the " << i+1 << " ratio of first LinearShape:\n";
                                            std::cin >> a;
                                            arr1[i] = a;
                                        }
                                        for (int i = 0; i < length2; i++) {
                                            std::cout << "Enter the " << i+1 << " ratio of second LinearShape:\n";
                                            std::cin >> b;
                                            arr2[i] = b;
                                        }
                                        LinearShape<int> linear_shape1(arr1,length1);
                                        LinearShape<int> linear_shape2(arr2,length2);
                                        LinearShape<int> *Res = linear_shape1 + linear_shape2;
                                        std::cout << "Result LinearShape:\n";
                                        LinearShapeShow(Res);
                                        break;
                                    }
                                    case 2:
                                    {
                                        std::cout << "Enter the length of the first LinearShape:\n";
                                        std::cin >> length1;
                                        std::cout << "Enter the length of the second LinearShape:\n";
                                        std::cin >> length2;
                                        int arr1[length1], arr2[length2];
                                        if (length1 != length2) {
                                            throw std::invalid_argument("different sizes");
                                        }
                                        for (int i = 0; i < length1; i++) {
                                            std::cout << "Enter the " << i+1 << " ratio of first LinearShape:\n";
                                            std::cin >> a;
                                            arr1[i] = a;
                                        }
                                        for (int i = 0; i < length2; i++) {
                                            std::cout << "Enter the " << i+1 << " ratio of second LinearShape:\n";
                                            std::cin >> b;
                                            arr2[i] = b;
                                        }
                                        LinearShape<int> linear_shape1(arr1,length1);
                                        LinearShape<int> linear_shape2(arr2,length2);
                                        LinearShape<int> *Res = linear_shape1 - linear_shape2;
                                        std::cout << "Result LinearShape:\n";
                                        LinearShapeShow(Res);
                                        break;
                                    }
                                    case 3:
                                    {
                                        std::cout << "Enter the length of the LinearShape:\n";
                                        std::cin >> length1;
                                        int arr1[length1];
                                        for (int i = 0; i < length1; i++) {
                                            std::cout << "Enter the " << i+1 << " ratio of first LinearShape:\n";
                                            std::cin >> a;
                                            arr1[i] = a;
                                        }
                                        LinearShape<int> linear_shape1(arr1,length1);
                                        int scalar;
                                        std::cout << "Enter the scalar in int form:\n";
                                        std::cin >> scalar;
                                        LinearShape<int> *Res = linear_shape1 * scalar;
                                        std::cout << "Result LinearShape:\n";
                                        LinearShapeShow(Res);
                                        break;
                                    }
                                    default:
                                    {
                                        PrintLinearShape(Status5);
                                        break;
                                    }
                                }
                                if (Status5 != 0)
                                {
                                    PrintLinearShape(2);
                                }
                            }
                            break;
                        }
                        default:
                        {
                            PrintLinearShape(Status);
                            break;
                        }
                    }
                    if (Status != 0)
                    {
                        PrintCase(3);
                    }
                }
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




