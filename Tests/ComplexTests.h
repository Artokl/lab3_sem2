#ifndef COMPLEXTESTS_H
#define COMPLEXTESTS_H

#include "../Complex.h"
#include <assert.h>

void ComplexSum()
{
    complex test1(3, 2);
    complex test2(2,3);
    complex test3 = test1 + test2;
    assert(test3.GetRe() == 5);
    assert(test3.GetIm() == 5);
    assert(test1.GetRe() == 3);
}
void ComplexSubtract()
{
    complex test1(3, 2);
    complex test2(2, 3);
    complex test3 = test1 - test2;
    assert(test3.GetRe() == 1);
    assert(test3.GetIm() == -1);
    assert(test1.GetRe() == 3);
}
void ComplexMulti()
{
    complex test1(3, 2);
    complex test2(2, 3);
    complex test3 = test1 * test2;
    assert(test3.GetRe() == 0);
    assert(test3.GetIm() == 13);
    assert(test1.GetRe() == 3);
}
void ComplexDiv()
{
    complex test1(1, 1);
    complex test2(1, 1);
    complex test3 = test1 / test2;
    assert(test3.GetRe() == 1);
    assert(test3.GetIm() == 0);
}
void ComplexAbs()
{
    complex test(-2,-5);
    double abs = sqrt((-2)*(-2) + (-5)*(-5));
    assert(test.abs() == abs);
}
void ComplexTests()
{
    ComplexDiv();
    ComplexMulti();
    ComplexSubtract();
    ComplexSum();
    ComplexAbs();
}
#endif //COMPLEXTESTS_H
