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
    std::cout << "1) VectorSum" << std::endl;
    std::cout << "2) VectorMultiOnScalar" << std::endl;
    std::cout << "3) VectorNorm" << std::endl;
    std::cout << "4) VectorMulti" << std::endl;
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
        std::cout << "Unknown Programm" << std::endl;
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
    std::cout << "1) MatrixSum" << std::endl;
    std::cout << "2) MatrixMultiOnScalar" << std::endl;
    std::cout << "3) MatrixNorm" << std::endl;
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
        std::cout << "Unknown Programm" << std::endl;
    }
}

void PrintMenuLinearShape() {
    std::cout << "0) Return to StartMenu" << std::endl;
    std::cout << "1) Run tests" << std::endl;
    std::cout << "2) Use functions with int linearshapes" << std::endl;
    std::cout << "3) Use functions with complex linearshapes" << std::endl;
}
void PrintFunctionsForLinerShape() {
    std::cout << "0) Return back" << std::endl;
    std::cout << "1) LinearShapeSum" << std::endl;
    std::cout << "2) LinearShapeDif" << std::endl;
    std::cout << "3) LinearShapeMultiOnScalar" << std::endl;
    std::cout << "4) LinearShapeCalculating" << std::endl;
}
void PrintLinearShape(int Status) {
    if (Status == 1) {
        std::cout << "Tests for linearshape passed" << std::endl;
    }
    else if (Status == 2) {
        std::cout << "Int linearshapes:" << std::endl;
        PrintFunctionsForLinerShape();
    }
    else if (Status == 3) {
        std::cout << "Complex linearshapes:" << std::endl;
        PrintFunctionsForLinerShape();
    }
    else {
        std::cout << "Unknown Programm" << std::endl;
    }
}

void StartMenu()
{
    std::cout << "Choose what you want to work with: " << std::endl;
    std::cout << "0) Exit" << std::endl;
    std::cout << "1) Vector" << std::endl;
    std::cout << "2) RectangularMatrix" << std::endl;
    std::cout << "3) LinearShape" << std::endl;
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
        PrintMenuLinearShape();
    }
    else {
        std::cout << "Unknown command" << std::endl;
    }
}


#endif //UI_H
