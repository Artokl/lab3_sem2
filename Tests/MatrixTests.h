#ifndef MATRIXTESTS_H
#define MATRIXTESTS_H

#include <assert.h>
#include "../Complex.h"
#include "../RectangularMatrix.h"

void TestMatrixSum() {
    int a[] = {1, 2, 3, 4, 5, 6};
    int b[] = {6, 5, 4 ,3, 2, 1};
    int c[] = {7, 7, 7, 7, 7, 7};
    Matrix<int, 2, 3> test1(a);
    Matrix<int, 2, 3> test2(b);
    std::cout << test1(0,0);
    Matrix<int, 2, 3> test3 = test1.MatrixSum(test2);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            assert(test3(i, j) == c[i * 3 + j]);
        }
    }
}
void TestMatrixSumComplex() {
    complex a(1, 2);
    complex b(3, 4);
    complex c(5, 6);
    complex d(7, 8);
    complex e(9, 10);
    complex f(11, 12);
    complex g(13, 14);
    complex h(15,16);
    complex a1(10,12);
    complex b1(14,16);
    complex c1(18, 20);
    complex d1(21,24);
    complex arr1[] = {a, b, c, d};
    complex arr2[] = {e, f, g, h};
    complex arrRes[] = {a1, b1, c1, d1};
    Matrix<complex, 2, 2> test1(arr1);
    Matrix<complex, 2, 2> test2(arr2);
    Matrix<complex, 2, 2> test3 = test1.MatrixSum(test2);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            assert(test3(i, j).GetRe() == arrRes[i * 2 + j].GetRe());
            assert(test3(i, j).GetIm() == arrRes[i * 2 + j].GetIm());
        }
    }
}
void TestMatrixMultiOnScalar() {
    int a[] = {1, 2, 3, 4, 5, 6};
    int c[] = {2, 4, 6, 8, 10, 12};
    Matrix<int, 2, 3> test1(a);
    Matrix<int, 2, 3> test2 = test1.MatrixMultiOnScalar(2);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            assert(test2(i, j) == c[i * 3 + j]);
        }
    }
}
void TestMatrixMultiOnScalarComplex() {
    complex a(1, 2);
    complex b(3, 4);
    complex c(5, 6);
    complex d(7, 8);
    complex e(2, 4);
    complex f(6, 8);
    complex g(10, 12);
    complex h(14,16);
    complex arr1[] = {a, b, c, d};
    complex arr2[] = {e, f, g, h};
    Matrix<complex, 2, 2> test1(arr1);
    Matrix<complex, 2, 2> test2 = test1.MatrixMultiOnScalar(complex (2, 0));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            assert(test2(i, j).GetRe() == arr2[i * 2 + j].GetRe());
            assert(test2(i, j).GetIm() == arr2[i * 2 + j].GetIm());
        }
    }
}
void TestMatrixNorm () {
    int a[] = {1, 2, 3, 4, 5, 6};
    Matrix<int, 2, 3> test(a);
    double Res1 = sqrt(1*1 + 2*2 + 3*3 + 4*4 + 5*5 + 6*6);
    double Res = test.MatrixNorm();
    assert(Res == Res1);
}
void TestMatrixNormComplex() {
    complex a(1, 2);
    complex b(3, 4);
    complex c(5, 6);
    complex d(7, 8);
    complex arr1[] = {a, b, c, d};
    double Res = sqrt(sqrt(1*1+2*2)*sqrt(2*2+1*1) + sqrt(3*3+4*4) + sqrt(5*5+6*6) + sqrt(7*7+8*8));
    Matrix<complex, 2, 2> test1(arr1);
    double Res1 = test1.MatrixNorm();
    assert(Res == Res1);
}
void MatrixTests() {
    TestMatrixSum();
//    TestMatrixSumComplex();
//    TestMatrixMultiOnScalar();
//    TestMatrixMultiOnScalarComplex();
//    TestMatrixNorm ();
//    TestMatrixNormComplex();
}

#endif //MATRIXTESTS_H
