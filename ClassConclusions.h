#ifndef CLASSCONCLUSIONS_H
#define CLASSCONCLUSIONS_H

#include "Abs.h"
#include "Vector.h"
#include "RectangularMatrix.h"
#include "LinearForm.h"

template <typename T> void VectorShow(Vector<T> &vec)
{
    std::cout << "{";
    for (int i = 0; i < vec.GetLength() - 1; i++)
    {
        std::cout << vec.Get(i) << ", ";
    }
    std::cout << vec.Get(vec.GetLength() - 1) << "}";
}
template <typename T> void VectorShow(Vector<T> *vec)
{
    std::cout << "{";
    for (int i = 0; i < vec->GetLength() - 1; i++)
    {
        std::cout << vec->Get(i) << ", ";
    }
    std::cout << vec->Get(vec->GetLength() - 1) << "}";
}

template <typename T, size_t Rows, size_t Cols> void MatrixShow(Matrix<T, Rows, Cols>  &matrix) {
    for (int i = 0; i < Rows; ++i) {
        for (int j = 0; j < Cols; ++j) {
            std::cout << (matrix)(i, j) << " ";
        }
        std::cout << std::endl;
    }
}
template <typename T, size_t Rows, size_t Cols> void MatrixShow(Matrix<T, Rows, Cols> *matrix) {
    for (int i = 0; i < Rows; ++i) {
        for (int j = 0; j < Cols; ++j) {
            std::cout << (*matrix)(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

void LinearFormShow(const LinearForm<int> &LinForm) {
    int flag = 0;
    std::cout << "L(";
    for (int i = 0; i < LinForm.GetLength()-1; i++) {
        std::cout << "x" << i+1 << ",";
    }
    std::cout << "x" << LinForm.GetLength() << ") =";
    if (LinForm.Get(0) > 0 || LinForm.Get(0) < 0) {
        std::cout << " " << LinForm.Get(0) << "x1";
        flag = 1;
    }
    for (int i = 1; i < LinForm.GetLength()-1; i++) {
        if (LinForm.Get(i) > 0) std::cout << " + " << LinForm.Get(i) << "x" << i+1; flag = 1;
        if (LinForm.Get(i) < 0) std::cout << " - " << Abs(LinForm.Get(i)) << "x" << i+1; flag = 1;
    }
    if (LinForm.Get(LinForm.GetLength()-1) > 0) {
        flag = 1;
        std::cout << " + " << LinForm.Get(LinForm.GetLength()-1)
        << "x" << LinForm.GetLength();
    }
    else if (LinForm.Get(LinForm.GetLength()-1) < 0) {
        flag = 1;
        std::cout << " - " << Abs(LinForm.Get(LinForm.GetLength()-1))
        << "x" << LinForm.GetLength();
    }
    if (flag == 0) {
        std::cout << " 0";
    }
    std::cout << std::endl;
}
void LinearFormShow(const LinearForm<int> *LinForm) {
    int flag = 0;
    std::cout << "L(";
    for (int i = 0; i < LinForm->GetLength()-1; i++) {
        std::cout << "x" << i+1 << ",";
    }
    std::cout << "x" << LinForm->GetLength() << ") =";
    if (LinForm->Get(0) > 0 || LinForm->Get(0) < 0) {
        flag = 1;
        std::cout << " " << LinForm->Get(0) << "x1";
    }
    for (int i = 1; i < LinForm->GetLength()-1; i++) {
        if (LinForm->Get(i) > 0) std::cout << " + " << LinForm->Get(i) << "x" << i+1; flag = 1;
        if (LinForm->Get(i) < 0) std::cout << " - " << Abs(LinForm->Get(i)) << "x" << i+1; flag = 1;
    }
    if (LinForm->Get(LinForm->GetLength()-1) > 0) {
        flag = 1;
        std::cout << " + " << LinForm->Get(LinForm->GetLength()-1)
        << "x" << LinForm->GetLength();
    }
    else if (LinForm->Get(LinForm->GetLength()-1) < 0) {
        flag = 1;
        std::cout << " - " << Abs(LinForm->Get(LinForm->GetLength()-1))
        << "x" << LinForm->GetLength();
    }
    if (flag == 0) {
        std::cout << " 0";
    }
    std::cout << std::endl;
}
void LinearFormShow(const LinearForm<complex> &LinForm) {
    std::cout << "L(";
    for (int i = 0; i < LinForm.GetLength(); i++) {
        std::cout << "x" << i+1 << ",";
    }
    std::cout << "x" << LinForm.GetLength() << ") = ";
    for (int i = 0; i < LinForm.GetLength()-1; i++) {
        std::cout << "(" << LinForm.Get(i) << ")x" << i+1;
    }
    std::cout << "(" << LinForm.Get(LinForm.GetLength()-1) << ")x" << LinForm.GetLength()-1 << std::endl;
}
void LinearFormShow(const LinearForm<complex> *LinForm) {
    std::cout << "L(";
    for (int i = 0; i < LinForm->GetLength()-1; i++) {
        std::cout << "x" << i+1 << ",";
    }
    std::cout << "x" << LinForm->GetLength() << ") =";
    for (int i = 0; i < LinForm->GetLength()-1; i++) {
        std::cout << "(" << LinForm->Get(i) << ")x" << i+1 << " + ";
    }
    std::cout << "(" << LinForm->Get(LinForm->GetLength()-1) << ")x" << LinForm->GetLength()-1 << std::endl;
}
#endif //CLASSCONCLUSIONS_H
