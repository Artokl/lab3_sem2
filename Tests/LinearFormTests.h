#ifndef LinearFormTESTS_H
#define LinearFormTESTS_H

#include "../LinearForm.h"
#include <assert.h>
#include "Complex.h"

void TestLinearFormSum() {
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {3, 4, 5, 6, 7};
    int c[] = {4, 6, 8, 10, 12};
    LinearForm<int> Test1(a, 5);
    LinearForm<int> Test2(b, 5);
    LinearForm<int> *Test3 = Test1.Sum(Test2);
    assert(Test3->GetLength() == 5);
    for (int i = 0; i < Test3->GetLength(); i++) {
        assert(Test3->Get(i) == c[i]);
    }
}
void TestLinearFormSumComplex() {
    complex a (1 ,2);
    complex b (1 ,2);
    complex c (3 ,4);
    complex d (3 ,4);
    complex e (4 ,6);
    complex f (4 ,6);
    complex arr1[] = {a, b};
    complex arr2[] = {c, d};
    complex res[] = {e,f};
    LinearForm<complex> Test1(arr1, 2);
    LinearForm<complex> Test2(arr2, 2);
    LinearForm<complex> *Test3 = Test1.Sum(Test2);
    assert(Test3->GetLength() == 2);
    for (int i = 0; i < Test3->GetLength(); i++) {
        assert(Test3->Get(i).GetRe() == res[i].GetRe());
        assert(Test3->Get(i).GetIm() == res[i].GetIm());
    }
}
void TestLinearFormDif() {
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {3, 4, 5, 6, 7};
    int c[] = {-2, -2, -2, -2, -2};
    LinearForm<int> Test1(a, 5);
    LinearForm<int> Test2(b, 5);
    LinearForm<int> *Test3 = Test1.Dif(Test2);
    assert(Test3->GetLength() == 5);
    for (int i = 0; i < Test3->GetLength(); i++) {
        assert(Test3->Get(i) == c[i]);
    }
}
void TestLinearFormDifComplex() {
    complex a (1 ,2);
    complex b (1 ,2);
    complex c (3 ,4);
    complex d (3 ,4);
    complex e (-2 ,-2);
    complex f (-2 ,-2);
    complex arr1[] = {a, b};
    complex arr2[] = {c, d};
    complex res[] = {e,f};
    LinearForm<complex> Test1(arr1, 2);
    LinearForm<complex> Test2(arr2, 2);
    LinearForm<complex> *Test3 = Test1.Dif(Test2);
    assert(Test3->GetLength() == 2);
    for (int i = 0; i < Test3->GetLength(); i++) {
        assert(Test3->Get(i).GetRe() == res[i].GetRe());
        assert(Test3->Get(i).GetIm() == res[i].GetIm());
    }
}
void TestLinearFormMultiOnScalar() {
    int a[] = {1, 2, 3, 4, 5};
    int c[] = {2, 4, 6, 8, 10};
    LinearForm<int> Test1(a, 5);
    LinearForm<int> *Test2 = Test1.ScalarMultiplication(2);
    assert(Test2->GetLength() == 5);
    for (int i = 0; i < Test2->GetLength(); i++) {
        assert(Test2->Get(i) == c[i]);
    }
}
void TestLinearFormMultiOnScalarComplex() {
    complex a (1 ,2);
    complex b (3 ,4);
    complex c (2 ,4);
    complex d (6 ,8);
    complex arr1[] = {a, b};
    complex res[] = {c, d};
    LinearForm<complex> Test1(arr1, 2);
    LinearForm<complex> *Test3 = Test1.ScalarMultiplication(complex(2,0));
    assert(Test3->GetLength() == 2);
    for (int i = 0; i < Test3->GetLength(); i++) {
        assert(Test3->Get(i).GetRe() == res[i].GetRe());
        assert(Test3->Get(i).GetIm() == res[i].GetIm());
    }
}
void TestLinearFormCalculating() {
    int a[] = {1, 2, 3, 4, 5};
    int c[] = {-3, 7, 1, 0, 4};
    LinearForm<int> Test1(a, 5);
    int Res = -3*1 + 2*7 + 3*1 + 4*0 + 5*4;
    int Res1 = Test1.Eval(c,5);
    assert(Res == Res1);
}
void TestLinearFormCalculatingComplex() {
    complex a (1 ,2);
    complex b (3 ,4);
    complex c (2 ,4);
    complex d (6 ,8);
    complex arr1[] = {a, b};
    complex arr2[] = {c, d};
    LinearForm<complex> Test1(arr1, 2);
    complex Res = a*c + b*d;
    complex Res1 = Test1.Eval(arr2,2);
    assert(Res == Res1);
}

void LinearFormTests() {
    TestLinearFormSum();
    TestLinearFormSumComplex();
    TestLinearFormDif();
    TestLinearFormDifComplex();
    TestLinearFormMultiOnScalar();
    TestLinearFormMultiOnScalarComplex();
    TestLinearFormCalculating();
    TestLinearFormCalculatingComplex();
}
#endif //LinearFormTESTS_H
