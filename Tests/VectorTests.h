#ifndef VECTORTESTS_H
#define VECTORTESTS_H

#include "../Complex.h"
#include "../Vector.h"
#include <assert.h>

void TestVectorSum()
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {5, 4, 3, 2, 1};
    int c[] = {6, 6, 6, 6, 6};
    Vector<int> test1(a, 5);
    Vector<int> test2(b, 5);
    Vector<int> *res = test1.vectorSum(test2);
    for (int i = 0; i < res->GetLength(); i++)
    {
        assert(res->Get(i) == c[i]);
    }
}

void TestVectorSumComplex()
{
    complex a(1, 2);
    complex b(3, 4);
    complex c(5, 6);
    complex d(7, 8);
    complex e(6, 8);
    complex f(10, 12);
    complex arr1[] = {a, b};
    complex arr2[] = {c, d};
    complex arrRes[] = {e, f};
    Vector<complex> test1(arr1, 2);
    Vector<complex> test2(arr2, 2);
    Vector<complex> *res = test1.vectorSum(test2);
    assert(res->GetLength() == 2);
    for (int i = 0; i < res->GetLength(); i++)
    {
        assert(res->Get(i).GetRe() == arrRes[i].GetRe());
        assert(res->Get(i).GetIm() == arrRes[i].GetIm());
    }
}

void TestVectorMultiOnScalar()
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {2, 4, 6, 8, 10};
    Vector<int> vec(a, 5);
    Vector<int> *res = vec.vectorMultiOnScalar(2);
    assert(vec.GetLength() == 5);
    for (int i = 0; i < res->GetLength(); i++)
    {
        assert(res->Get(i) == b[i]);
    }
}

void TestVectorMultiOnScalarComplex()
{
    complex a(1, 3);
    complex b(2, 4);
    complex c(2, 6);
    complex d(4, 8);
    complex arr[] = {a, b};
    complex res[] = {c, d};
    Vector<complex> test (arr,2);
    Vector<complex> *test1 = test.vectorMultiOnScalar(complex(2,0));
    assert(test1->GetLength() == 2);
    for (int i = 0; i < test1->GetLength(); i++)
    {
        assert(test1->Get(i).GetRe() == res[i].GetRe());
        assert(test1->Get(i).GetIm() == res[i].GetIm());
    }
}

void TestVectorNorm()
{
    int a[] = {1, 2, 3, 4, 5};
    Vector<int> vec(a, 5);
    double Res1 = sqrt(1*1 + 2*2 + 3*3 + 4*4 + 5*5);
    double Res = vec.vectorNorm();
    assert(Res == Res1);
}

void TestVectorNormComplex()
{
    complex a(1, 3);
    complex b(2, 4);
    complex arr[] = {a, b};
    double Res1 = sqrt(sqrt(1*1+3*3)*sqrt(1*1+3*3) + sqrt(2*2+4*4)*sqrt(2*2+4*4));
    Vector<complex> test(arr, 2);
    double Res = test.vectorNorm();
    assert(Res - Res1 < 0.00001);
}

void TestVectorMulti()
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {6, 7, 8, 9, 10};
    int c[] = {6, 14, 24, 36, 50};
    Vector<int> vec1(a, 5);
    Vector<int> vec2(b, 5);
    Vector<int> *res = vec1.vectorMulti(vec2);
    assert(res->GetLength() == 5);
    for (int i = 0; i < res->GetLength(); i++)
    {
        assert(res->Get(i) == c[i]);
    }
}

void TestVectorMultiComplex()
{
    complex a(1, 3);
    complex b(2, 4);
    complex c(3, 5);
    complex d(4, 8);
    complex e(-12, 14);
    complex f(-24, 32);
    complex arr1[] = {a, b};
    complex arr2[] = {c, d};
    complex arrRes[] = {e, f};
    Vector<complex> test1(arr1, 2);
    Vector<complex> test2(arr2, 2);
    Vector<complex> *res = test1.vectorMulti(test2);
    for (int i = 0; i < res->GetLength(); i++)
    {
        assert(res->Get(i).GetRe() == arrRes[i].GetRe());
        assert(res->Get(i).GetIm() == arrRes[i].GetIm());
    }
}
void VectorTests()
{
    TestVectorSum();
    TestVectorSumComplex();
    TestVectorMultiOnScalar();
    TestVectorMultiOnScalarComplex();
    TestVectorNorm();
    TestVectorNormComplex();
    TestVectorMulti();
    TestVectorMultiComplex();
}
#endif //VECTORTESTS_H
