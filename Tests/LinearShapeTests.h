#ifndef LINEARSHAPETESTS_H
#define LINEARSHAPETESTS_H

#include "../LinearShape.h"
#include <assert.h>
#include "Complex.h"

void TestLinearShapeSum() {
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {3, 4, 5, 6, 7};
    int c[] = {4, 6, 8, 10, 12};
    LinearShape<int> Test1(a, 5);
    LinearShape<int> Test2(b, 5);
    LinearShape<int> *Test3 = Test1.linear_shapeSum(Test2);
    assert(Test3->GetLength() == 5);
    for (int i = 0; i < Test3->GetLength(); i++) {
        assert(Test3->Get(i) == c[i]);
    }
}
void TestLinearShapeSumComplex() {
    complex a (1 ,2);
    complex b (1 ,2);
    complex c (3 ,4);
    complex d (3 ,4);
    complex e (4 ,6);
    complex f (4 ,6);
    complex arr1[] = {a, b};
    complex arr2[] = {c, d};
    complex res[] = {e,f};
    LinearShape<complex> Test1(arr1, 2);
    LinearShape<complex> Test2(arr2, 2);
    LinearShape<complex> *Test3 = Test1.linear_shapeSum(Test2);
    assert(Test3->GetLength() == 2);
    for (int i = 0; i < Test3->GetLength(); i++) {
        assert(Test3->Get(i).GetRe() == res[i].GetRe());
        assert(Test3->Get(i).GetIm() == res[i].GetIm());
    }
}
void TestLinearShapeDif() {
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {3, 4, 5, 6, 7};
    int c[] = {-2, -2, -2, -2, -2};
    LinearShape<int> Test1(a, 5);
    LinearShape<int> Test2(b, 5);
    LinearShape<int> *Test3 = Test1.linear_shapeDif(Test2);
    assert(Test3->GetLength() == 5);
    for (int i = 0; i < Test3->GetLength(); i++) {
        assert(Test3->Get(i) == c[i]);
    }
}
void TestLinearShapeDifComplex() {
    complex a (1 ,2);
    complex b (1 ,2);
    complex c (3 ,4);
    complex d (3 ,4);
    complex e (-2 ,-2);
    complex f (-2 ,-2);
    complex arr1[] = {a, b};
    complex arr2[] = {c, d};
    complex res[] = {e,f};
    LinearShape<complex> Test1(arr1, 2);
    LinearShape<complex> Test2(arr2, 2);
    LinearShape<complex> *Test3 = Test1.linear_shapeDif(Test2);
    assert(Test3->GetLength() == 2);
    for (int i = 0; i < Test3->GetLength(); i++) {
        assert(Test3->Get(i).GetRe() == res[i].GetRe());
        assert(Test3->Get(i).GetIm() == res[i].GetIm());
    }
}
void TestLinearShapeMultiOnScalar() {
    int a[] = {1, 2, 3, 4, 5};
    int c[] = {2, 4, 6, 8, 10};
    LinearShape<int> Test1(a, 5);
    LinearShape<int> *Test2 = Test1.linear_shapeMultiOnScalar(2);
    assert(Test2->GetLength() == 5);
    for (int i = 0; i < Test2->GetLength(); i++) {
        assert(Test2->Get(i) == c[i]);
    }
}
void TestLinearShapeMultiOnScalarComplex() {
    complex a (1 ,2);
    complex b (3 ,4);
    complex c (2 ,4);
    complex d (6 ,8);
    complex arr1[] = {a, b};
    complex res[] = {c, d};
    LinearShape<complex> Test1(arr1, 2);
    LinearShape<complex> *Test3 = Test1.linear_shapeMultiOnScalar(complex(2,0));
    assert(Test3->GetLength() == 2);
    for (int i = 0; i < Test3->GetLength(); i++) {
        assert(Test3->Get(i).GetRe() == res[i].GetRe());
        assert(Test3->Get(i).GetIm() == res[i].GetIm());
    }
}
void TestLinearShapeCalculating() {
    int a[] = {1, 2, 3, 4, 5};
    int c[] = {-3, 7, 1, 0, 4};
    LinearShape<int> Test1(a, 5);
    int Res = -3*1 + 2*7 + 3*1 + 4*0 + 5*4;
    int Res1 = Test1.linear_shapeCalculating(c,5);
    assert(Res == Res1);
}
void TestLinearShapeCalculatingComplex() {
    complex a (1 ,2);
    complex b (3 ,4);
    complex c (2 ,4);
    complex d (6 ,8);
    complex arr1[] = {a, b};
    complex arr2[] = {c, d};
    LinearShape<complex> Test1(arr1, 2);
    complex Res = a*c + b*d;
    complex Res1 = Test1.linear_shapeCalculating(arr2,2);
    assert(Res == Res1);
}

void LinearShapeTests() {
    TestLinearShapeSum();
    TestLinearShapeSumComplex();
    TestLinearShapeDif();
    TestLinearShapeDifComplex();
    TestLinearShapeMultiOnScalar();
    TestLinearShapeMultiOnScalarComplex();
    TestLinearShapeCalculating();
    TestLinearShapeCalculatingComplex();
}
#endif //LINEARSHAPETESTS_H
