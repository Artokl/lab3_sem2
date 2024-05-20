#ifndef ABS_H
#define ABS_H

#include "Complex.h"

template <typename T>
double Abs(const T& Value) {
    if (Value >= 0) return Value;
    else return -Value;
}

template <>
double Abs <complex>(const complex& Value) {
    return Value.abs();
}

#endif //ABS_H
