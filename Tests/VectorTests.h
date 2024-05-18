#ifndef VECTORTESTS_H
#define VECTORTESTS_H

#include "../Complex.h"
#include "../Vector.h"
#include <assert.h>

void TestVectorSum()
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {1, 2, 3, 4, 5};
    int c[] = {2, 4, 6, 8, 10};
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
    complex a(1, 3);
    complex b(2, 4);
    complex c(3, 5);
    complex d(4, 8);
    complex e(4, 8);
    complex f(6, 12);
    complex arr1[] = {a, b};
    complex arr2[] = {c, d};
    complex arrRes[] = {e, f};
    Vector<complex> test1(arr1, 2);
    Vector<complex> test2(arr2, 2);
    Vector<complex> *res = test1.vectorSum(test2);
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
    for (int i = 0; i < res->GetLength(); i++)
    {
        assert(res->Get(i) == b[i]);
    }
}

void TestVectorMulti()
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {2, 4, 6, 8, 10};
    int c[] = {2, 8, 18, 32, 50};
    Vector<int> vec1(a, 5);
    Vector<int> vec2(b, 5);
    Vector<int> *res = vec1.vectorMulti(vec2);
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
    TestVectorMulti();
    TestVectorMultiComplex();
}
#endif //VECTORTESTS_H
