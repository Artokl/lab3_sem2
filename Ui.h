#ifndef UI_H
#define UI_H

#include <iostream>

void PrintMenuVector() {
    std::cout << "0) Return to StartMenu" << std::endl;
    std::cout << "1) Run tests" << std::endl;
    std::cout << "2) Use functions with int vectors" << std::endl;
    std::cout << "3) Use functions with complex vectors" << std::endl;
}
void PrintFunctionsForVector() {
    std::cout << "0) Return back" << std::endl;
    std::cout << "1) Sum" << std::endl;
    std::cout << "2) ScalarMultiplication" << std::endl;
    std::cout << "3) GetNorm" << std::endl;
    std::cout << "4) Multiplication" << std::endl;
}
void PrintVector(int Status)
{
    if (Status == 1) {
        std::cout << "Tests for vector passed" << std::endl;
    }
    else if (Status == 2) {
        std::cout << "Int vectors:" << std::endl;
        PrintFunctionsForVector();
    }
    else if (Status == 3) {
        std::cout << "Complex vectors:" << std::endl;
        PrintFunctionsForVector();
    }
    else {
        std::cout << "Unknown Command" << std::endl;
    }
}

void PrintMenuMatrix() {
    std::cout << "0) Return to StartMenu" << std::endl;
    std::cout << "1) Run tests" << std::endl;
    std::cout << "2) Use functions with int matrixes" << std::endl;
    std::cout << "3) Use functions with complex matrixes" << std::endl;
}
void PrintFunctionsForMatrix() {
    std::cout << "0) Return back" << std::endl;
    std::cout << "1) Sum" << std::endl;
    std::cout << "2) ScalarMultiplication" << std::endl;
    std::cout << "3) GetNorm" << std::endl;
    std::cout << "4) Elementary string conversions" << std::endl;
    std::cout << "5) elementary column conversions" << std::endl;
}
void PrintStringConversions() {
    std::cout << "0) Return back" << std::endl;
    std::cout << "1) SwapRows" << std::endl;
    std::cout << "2) MultiplyRow" << std::endl;
    std::cout << "3) AddRows" << std::endl;
}
void PrintColumnConversions() {
    std::cout << "0) Return back" << std::endl;
    std::cout << "1) SwapCols" << std::endl;
    std::cout << "2) MultiplyCol" << std::endl;
    std::cout << "3) AddCols" << std::endl;
}
void PrintMatrix(int Status) {
    if (Status == 1) {
        std::cout << "Tests for matrix passed" << std::endl;
    }
    else if (Status == 2) {
        std::cout << "Int Matrices:" << std::endl;
        PrintFunctionsForMatrix();
    }
    else if (Status == 3) {
        std::cout << "Complex Matrices:" << std::endl;
        PrintFunctionsForMatrix();
    }
    else {
        std::cout << "Unknown Command" << std::endl;
    }
}

void PrintMenuLinearForm() {
    std::cout << "0) Return to StartMenu" << std::endl;
    std::cout << "1) Run tests" << std::endl;
    std::cout << "2) Use functions with int linearforms" << std::endl;
    std::cout << "3) Use functions with complex linearforms" << std::endl;
}
void PrintFunctionsForLinearForm() {
    std::cout << "0) Return back" << std::endl;
    std::cout << "1) Sum" << std::endl;
    std::cout << "2) Dif" << std::endl;
    std::cout << "3) ScalarMultiplication" << std::endl;
    std::cout << "4) Eval" << std::endl;
}
void PrintLinearForm(int Status) {
    if (Status == 1) {
        std::cout << "Tests for linearform passed" << std::endl;
    }
    else if (Status == 2) {
        std::cout << "Int linearforms:" << std::endl;
        PrintFunctionsForLinearForm();
    }
    else if (Status == 3) {
        std::cout << "Complex linearforms:" << std::endl;
        PrintFunctionsForLinearForm();
    }
    else {
        std::cout << "Unknown Command" << std::endl;
    }
}

void StartMenu()
{
    std::cout << "Choose what you want to work with: " << std::endl;
    std::cout << "0) Exit" << std::endl;
    std::cout << "1) Vector" << std::endl;
    std::cout << "2) RectangularMatrix" << std::endl;
    std::cout << "3) LinearForm" << std::endl;
}
void PrintCase(int Status)
{
    if (Status == 0) {
        std::cout << "Programm ended";
    }
    else if (Status == 1) {
        PrintMenuVector();
    }
    else if (Status == 2) {
        PrintMenuMatrix();
    }
    else if(Status == 3) {
        PrintMenuLinearForm();
    }
    else {
        std::cout << "Unknown command" << std::endl;
    }
}


#endif //UI_H
