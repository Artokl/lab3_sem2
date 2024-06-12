#ifndef MATRIXTESTS_H
#define MATRIXTESTS_H

#include <cassert>
#include <complex>
#include <cmath>
#include "../RectangularMatrix.h"

void TestMatrixSum() {
    int a[] = {1, 2, 3, 4, 5, 6};
    int b[] = {6, 5, 4, 3, 2, 1};
    int c[] = {7, 7, 7, 7, 7, 7};
    Matrix<int, 2, 3> test1(a);
    Matrix<int, 2, 3> test2(b);
    Matrix<int, 2, 3> *test3 = test1.Sum(test2);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            assert((*test3)(i, j) == c[i * 3 + j]);
        }
    }
    delete test3;
}

void TestMatrixSumComplex() {
    complex a(1, 2);
    complex b(3, 4);
    complex c(5, 6);
    complex d(7, 8);
    complex e(9, 10);
    complex f(11, 12);
    complex g(13, 14);
    complex h(15, 16);
    complex a1(10, 12);
    complex b1(14, 16);
    complex c1(18, 20);
    complex d1(22, 24);
    complex arr1[] = {a, b, c, d};
    complex arr2[] = {e, f, g, h};
    complex arrRes[] = {a1, b1, c1, d1};
    Matrix<complex, 2, 2> test1(arr1);
    Matrix<complex, 2, 2> test2(arr2);
    Matrix<complex, 2, 2> *test3 = test1.Sum(test2);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            assert((*test3)(i, j) == arrRes[i * 2 + j]);
        }
    }
    delete test3;
}

void TestMatrixMultiOnScalar() {
    int a[] = {1, 2, 3, 4, 5, 6};
    int c[] = {2, 4, 6, 8, 10, 12};
    Matrix<int, 2, 3> test1(a);
    Matrix<int, 2, 3> *test2 = test1.ScalarMultiplication(2);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            assert((*test2)(i, j) == c[i * 3 + j]);
        }
    }
    delete test2;
}

void TestMatrixMultiOnScalarComplex() {
    complex a(1, 2);
    complex b(3, 4);
    complex c(5, 6);
    complex d(7, 8);
    complex e(2, 4);
    complex f(6, 8);
    complex g(10, 12);
    complex h(14, 16);
    complex arr1[] = {a, b, c, d};
    complex arr2[] = {e, f, g, h};
    Matrix<complex, 2, 2> test1(arr1);
    Matrix<complex, 2, 2> *test2 = test1.ScalarMultiplication(complex(2, 0));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            assert((*test2)(i, j) == arr2[i * 2 + j]);
        }
    }
    delete test2;
}

void TestMatrixNorm() {
    int a[] = {1, 2, 3, 4, 5, 6};
    Matrix<int, 2, 3> test(a);
    double Res1 = sqrt(1*1 + 2*2 + 3*3 + 4*4 + 5*5 + 6*6);
    double Res = test.GetNorm();
    assert(Abs(Res - Res1) < 0.0001);
}

void TestMatrixNormComplex() {
    complex a(1, 2);
    complex b(3, 4);
    complex c(5, 6);
    complex d(7, 8);
    complex arr1[] = {a, b, c, d};
    double Res = sqrt(Abs(a)*Abs(a) + Abs(b)*Abs(b) + Abs(c)*Abs(c) + Abs(d)*Abs(d));
    Matrix<complex, 2, 2> test1(arr1);
    double Res1 = test1.GetNorm();
    assert(Abs(Res - Res1) < 0.0001);
}

void TestMatrixSwapRows() {
    int a[] = {1, 2, 3, 4, 5, 6};
    int c[] = {4, 5, 6, 1, 2, 3};
    Matrix<int, 2, 3> test(a);
    test.swapRows(0,1);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            assert(test(i, j) == c[i * 3 + j]);
        }
    }
}

void TestMatrixSwapRowsComplex() {
    complex a(1, 2);
    complex b(3, 4);
    complex c(5, 6);
    complex d(7, 8);
    complex e(5, 6);
    complex f(7, 8);
    complex g(1, 2);
    complex h(3,4);
    complex arr1[] = {a, b, c, d};
    complex arr2[] = {e, f, g, h};
    Matrix<complex, 2, 2> test1(arr1);
    test1.swapRows(0,1);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            assert(test1(i, j) == arr2[i * 2 + j]);
        }
    }
}

void TestMatrixMultiplyRow() {
    int a[] = {1, 2, 3, 4, 5, 6};
    int c[] = {2, 4, 6, 4, 5, 6};
    Matrix<int, 2, 3> test(a);
    test.multiplyRow(0, 2);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            assert(test(i, j) == c[i * 3 + j]);
        }
    }
}

void TestMatrixMultiplyRowComplex() {
    complex a(1, 2);
    complex b(3, 4);
    complex c(5, 6);
    complex d(7, 8);
    complex e(2, 4);
    complex f(6, 8);
    complex g(5, 6);
    complex h(7,8);
    complex arr1[] = {a, b, c, d};
    complex arr2[] = {e, f, g, h};
    Matrix<complex, 2, 2> test1(arr1);
    test1.multiplyRow(0,complex(2,0));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            assert(test1(i, j) == arr2[i * 2 + j]);
        }
    }
}

void TestMatrixAddRows() {
    int a[] = {1, 2, 3, 4, 5, 6};
    int c[] = {9, 12, 15, 4, 5, 6};
    Matrix<int, 2, 3> test(a);
    test.addRows(0,1,2);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            assert(test(i, j) == c[i * 3 + j]);
        }
    }
}
void TestMatrixAddRowsComplex() {
    complex a(1, 2);
    complex b(3, 4);
    complex c(5, 6);
    complex d(7, 8);
    complex e(11, 14);
    complex f(17, 20);
    complex g(5, 6);
    complex h(7,8);
    complex arr1[] = {a, b, c, d};
    complex arr2[] = {e, f, g, h};
    Matrix<complex, 2, 2> test1(arr1);
    test1.addRows(0,1,complex(2,0));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            assert(test1(i, j).GetRe() == arr2[i * 2 + j].GetRe());
            assert(test1(i, j).GetIm() == arr2[i * 2 + j].GetIm());
        }
    }
}
void TestMatrixSwapCols() {
    int a[] = {1, 2, 3, 4, 5, 6};
    int c[] = {2, 1, 3, 5, 4, 6};
    Matrix<int, 2, 3> test(a);
    test.swapCols(0,1);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            assert(test(i, j) == c[i * 3 + j]);
        }
    }
}
void TestMatrixSwapColsComplex() {
    complex a(1, 2);
    complex b(3, 4);
    complex c(5, 6);
    complex d(7, 8);
    complex e(3, 4);
    complex f(1, 2);
    complex g(7, 8);
    complex h(5,6);
    complex arr1[] = {a, b,c, d};
    complex arr2[] = {e, f, g, h};
    Matrix<complex, 2, 2> test1(arr1);
    test1.swapCols(0,1);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            assert(test1(i, j).GetRe() == arr2[i * 2 + j].GetRe());
            assert(test1(i, j).GetIm() == arr2[i * 2 + j].GetIm());
        }
    }
}
void TestMatrixMultiplyCol() {
    int a[] = {1, 2, 3, 4, 5, 6};
    int c[] = {2, 2, 3, 8, 5, 6};
    Matrix<int, 2, 3> test(a);
    test.multiplyCol(0, 2);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            assert(test(i, j) == c[i * 3 + j]);
        }
    }
}
void TestMatrixMultiplyColComplex() {
    complex a(1, 2);
    complex b(3, 4);
    complex c(5, 6);
    complex d(7, 8);
    complex e(2, 4);
    complex f(3, 4);
    complex g(10, 12);
    complex h(7,8);
    complex arr1[] = {a, b, c, d};
    complex arr2[] = {e, f, g, h};
    Matrix<complex, 2, 2> test1(arr1);
    test1.multiplyCol(0,complex(2,0));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            assert(test1(i, j).GetRe() == arr2[i * 2 + j].GetRe());
            assert(test1(i, j).GetIm() == arr2[i * 2 + j].GetIm());
        }
    }
}
void TestMatrixAddCols() {
    int a[] = {1, 2, 3, 4, 5, 6};
    int c[] = {5, 2, 3, 14, 5, 6};
    Matrix<int, 2, 3> test(a);
    test.addCols(0,1,2);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            assert(test(i, j) == c[i * 3 + j]);
        }
    }
}
void TestMatrixAddColsComplex() {
    complex a(1, 2);
    complex b(3, 4);
    complex c(5, 6);
    complex d(7, 8);
    complex e(7, 10);
    complex f(3, 4);
    complex g(19, 22);
    complex h(7,8);
    complex arr1[] = {a, b, c, d};
    complex arr2[] = {e, f, g, h};
    Matrix<complex, 2, 2> test1(arr1);
    test1.addCols(0,1,complex(2,0));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            assert(test1(i, j).GetRe() == arr2[i * 2 + j].GetRe());
            assert(test1(i, j).GetIm() == arr2[i * 2 + j].GetIm());
        }
    }
}
void MatrixTests() {
    TestMatrixSum();
    TestMatrixSumComplex();
    TestMatrixMultiOnScalar();
    TestMatrixMultiOnScalarComplex();
    TestMatrixNorm();
    TestMatrixNormComplex();
    TestMatrixSwapRows();
    TestMatrixSwapRowsComplex();
    TestMatrixMultiplyRow();
    TestMatrixMultiplyRowComplex();
    TestMatrixAddRows();
    TestMatrixSwapCols();
    TestMatrixSwapColsComplex();
    TestMatrixMultiplyCol();
    TestMatrixMultiplyColComplex();
    TestMatrixAddCols();
    TestMatrixAddColsComplex();
}

#endif //MATRIXTESTS_H
